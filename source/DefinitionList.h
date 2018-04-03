// DefinitionList.h
#ifndef have_DefinitionList
#define have_DefinitionList

#include <vector>
#include <cstdlib>
#include "Definition.h"
#include "PosVector.h"
#include "Line.h"
#include "vecCalcGlobals.h"

class DefinitionList : public std::vector<Definition>
{

    PointDefinition findPoint(PointRef p)
    {
        PointDefinition res;

        size_t i;
        for (i = 0; i < size(); i++)
        {
            Definition curDef = at(i);
            if (curDef.getType() == DEFINITION_TYPE_POINTDEFINITION)
            {
                if (curDef.getName() == p)
                {
                    res = curDef.getPointDefinition();
                    break;
                }
            }
        }

        return res;
    }

    LineDefinition findLine(LineRef l)
    {
        LineDefinition res;

        size_t i;
        for (i = 0; i < size(); i++)
        {
            Definition curDef = at(i);
            if (curDef.getType() == DEFINITION_TYPE_LINEDEFINITION)
            {
                if (curDef.getName() == l)
                {
                    res = curDef.getLineDefinition();
                    break;
                }
            }
        }

        return res;
    }

    void getMaxMin(double &minX, double &minY, double &maxX, double &maxY)
    {
        minX = DBL_MAX;
        minY = DBL_MAX;
        maxX = -DBL_MAX;
        maxY = -DBL_MAX;

        size_t i;
        for (i = 0; i < size(); i++)
        {
            Definition curDef = at(i);
            if (curDef.getType() == DEFINITION_TYPE_POINTDEFINITION)
            {
                PointRef sillyButThereYougo(curDef.getName().c_str());
                PosVector pvRes = resolve(sillyButThereYougo);
                pvRes.getMaxMin(minX, minY, maxX, maxY);
            }
            if (curDef.getType() == DEFINITION_TYPE_LINEDEFINITION)
            {
                LineRef sillyButThereYougo(curDef.getName().c_str());
                Line lineRes = resolve(sillyButThereYougo);
                lineRes.getMaxMin(minX, minY, maxX, maxY);
            }
        }

        if (fabs(minX) > 1e9)
        {
            minX = _copysign(1e9, minX);
        }
        if (fabs(minY) > 1e9)
        {
            minY = _copysign(1e9, minY);
        }
        if (fabs(maxX) > 1e9)
        {
            maxX = _copysign(1e9, maxX);
        }
        if (fabs(maxY) > 1e9)
        {
            maxY = _copysign(1e9, maxY);
        }

    }

    void write(FILE *fp, PointDefinition p)
    {
        std::string dashes = "";
        if (gSvgFlag == SVG_FLAG_DASHED)
            dashes = gSvgDashes;

        switch (p.getType())
        {
        case POINTDEFINITION_TYPE_NONE:
        {
            fprintf(stderr, "invalid point definition\n");
        }
        break;
        case POINTDEFINITION_TYPE_POINT:
        {
            PosVector pv(p.x(), p.y());
            if (gWriteSvg)
                p.print(fp);
            else
                fprintf (fp, "%s,%s\n", p.getName().c_str(), pv.toString().c_str());
        }
        break;
        case POINTDEFINITION_TYPE_INTERSECT:
        {
            Line l = resolve (p.getLineRef());
            Line l1 = resolve (p.getLineRef1());

            PosVector pv = l.intersect(l1);
            PointDefinition pInter(p.getName(), (long)(pv.x()), (long)(pv.y()));

            if (gWriteSvg)
                pInter.print (fp);
            else
                fprintf (fp, "%s,%s\n", p.getName().c_str(), pv.toString().c_str());
        }
        break;
        case POINTDEFINITION_TYPE_BISECT:
        {
            PosVector pvFrom = resolve (p.getPointRef());
            PosVector pvTo = resolve (p.getPointRef1());

            PosVector pvBis = pvFrom.bisect(pvTo);
            PointDefinition pBis(p.getName(), (long)(pvBis.x()), (long)(pvBis.y()));
            if (gWriteSvg)
                pBis.print(fp);
            else
                fprintf (fp, "%s,%s\n", p.getName().c_str(), pvBis.toString().c_str());
        }
        break;
        case POINTDEFINITION_TYPE_BISECT_LINE:
        {
            Line l = resolve (p.getLineRef());

            PosVector pvBisLine = l.bisect();
            PointDefinition pBisLine(p.getName(), (long)(pvBisLine.x()), (long)(pvBisLine.y()));
            if (gWriteSvg)
                pBisLine.print(fp);
            else
                fprintf (fp, "%s,%s\n", p.getName().c_str(), pvBisLine.toString().c_str());
        }
        break;
        }
    }

    void write(FILE *fp, LineDefinition l)
    {
        std::string dashes = "";
        if (gSvgFlag == SVG_FLAG_DASHED)
            dashes = " stroke-dasharray=\"8, 8\" ";

        switch (l.getType())
        {
        case LINEDEFINITION_TYPE_NONE:
        {
            fprintf(stderr, "invalid line definition\n");
            exit(300);
        }
        break;
        case LINEDEFINITION_TYPE_LINE:
        {
            PosVector pvFrom = resolve (l.getPointRef());
            PosVector pvTo = resolve (l.getPointRef1());

            if (gWriteSvg)
                fprintf (fp, 
                         "<path stroke=\"%s\" %s d=\"M%s %s\"/>\n",
                         gSvgColour.c_str(),
                         dashes.c_str(),
                         pvFrom.toPath().c_str(), 
                         pvTo.toPath().c_str());
            else
                fprintf (fp, "%s,%s,%s\n", l.getName().c_str(), pvFrom.toString().c_str(), pvTo.toString().c_str());
        }
        break;
        case LINEDEFINITION_TYPE_PERPENDICULAR:
        {
            PosVector pv = resolve (l.getPointRef());
            Line lSrc = resolve (l.getLineRef());

            Line lPerp = lSrc.perpendicular(pv);

            if (gWriteSvg)
                fprintf (fp, 
                         "<path stroke=\"%s\" %s d=\"M%s\"/>\n",
                         gSvgColour.c_str(),
                         dashes.c_str(), 
                         lPerp.toPath().c_str());
            else
                fprintf (fp, "%s,%s\n", l.getName().c_str(), lPerp.toString().c_str());
        }
        break;
        case LINEDEFINITION_TYPE_PARALLEL:
        {
            PosVector pv = resolve (l.getPointRef());
            Line lSrc = resolve (l.getLineRef());

            Line lPara = lSrc.parallel(pv);

            if (gWriteSvg)
                fprintf (fp, 
                         "<path stroke=\"%s\" %s d=\"M%s\"/>\n",
                         gSvgColour.c_str(),
                         dashes.c_str(), 
                         lPara.toPath().c_str());
            else
                fprintf (fp, "%s,%s\n", l.getName().c_str(), lPara.toString().c_str());
        }
        break;
        case LINEDEFINITION_TYPE_EXTEND:
        {
            Line lSrc = resolve (l.getLineRef());
            long n = l.getNumber();

            Line lExt = lSrc.extend(n);

            if (gWriteSvg)
                fprintf (fp, 
                         "<path stroke=\"%s\" %s d=\"M%s\"/>\n",
                         gSvgColour.c_str(),
                         dashes.c_str(), 
                         lExt.toPath().c_str());
            else
                fprintf (fp, "%s,%s\n", l.getName().c_str(), lExt.toString().c_str());
        }
        break;
        case LINEDEFINITION_TYPE_SLIDE:
        {
            Line lSrc = resolve (l.getLineRef());
            long n = l.getNumber();

            Line lSli = lSrc.slide(n);

            if (gWriteSvg)
                fprintf (fp, 
                         "<path stroke=\"%s\" %s d=\"M%s\"/>\n",
                         gSvgColour.c_str(),
                         dashes.c_str(), 
                         lSli.toPath().c_str());
            else
                fprintf (fp, "%s,%s\n", l.getName().c_str(), lSli.toString().c_str());
        }
        break;
        }
    }

    // these should be cached
    Line resolve (LineRef lr)
    {
        Line res;
        
        LineDefinition ld = findLine(lr);

        switch (ld.getType())
        {
        case LINEDEFINITION_TYPE_NONE:
        {
            fprintf(stderr, "invalid line definition\n");
            exit(300);
        }
        break;
        case LINEDEFINITION_TYPE_LINE:
        {
            PosVector pvFrom = resolve (ld.getPointRef());
            PosVector pvTo = resolve (ld.getPointRef1());
            
            Line l(pvFrom, pvTo);

            return l;
        }
        break;
        case LINEDEFINITION_TYPE_PERPENDICULAR:
        {
            PosVector pv = resolve (ld.getPointRef());
            Line lSrc = resolve (ld.getLineRef());

            Line lPerp = lSrc.perpendicular(pv);
            return lPerp;
        }
        break;
        case LINEDEFINITION_TYPE_PARALLEL:
        {
            PosVector pv = resolve (ld.getPointRef());
            Line lSrc = resolve (ld.getLineRef());

            Line lPara = lSrc.parallel(pv);
            return lPara;
        }
        break;
        case LINEDEFINITION_TYPE_EXTEND:
        {
            Line lSrc = resolve (ld.getLineRef());
            long n = ld.getNumber();

            Line lExt = lSrc.extend(n);
            return lExt;
        }
        break;
        case LINEDEFINITION_TYPE_SLIDE:
        {
            Line lSrc = resolve (ld.getLineRef());
            long n = ld.getNumber();

            Line lSli = lSrc.slide(n);
            return lSli;
        }
        break;
        }

        return res;
    }

    // these should be cached
    PosVector resolve (PointRef pr)
    {
        PosVector res;
        PointDefinition pd = findPoint(pr);

        switch (pd.getType())
        {
        case POINTDEFINITION_TYPE_NONE:
        {
            fprintf(stderr, "invalid point definition\n");
        }
        break;
        case POINTDEFINITION_TYPE_POINT:
        {
            PosVector pv(pd.x(), pd.y());
            return pv;
        }
        break;
        case POINTDEFINITION_TYPE_INTERSECT:
        {
            Line l = resolve (pd.getLineRef());
            Line l1 = resolve (pd.getLineRef1());

            return l.intersect(l1);
        }
        break;
        case POINTDEFINITION_TYPE_BISECT:
        {
            PosVector pv = resolve (pd.getPointRef());
            PosVector pv1 = resolve (pd.getPointRef1());

            return pv.bisect(pv1);
        }
        break;
        case POINTDEFINITION_TYPE_BISECT_LINE:
        {
            Line l = resolve (pd.getLineRef());

            return l.bisect();
        }
        break;
        }

        return res;
    }

    bool setColour(SVG_FLAGS f)
    {
        bool res = true;

        switch (f)
        {
        case SVG_COLOUR_R:
            gSvgColour = "red";
            break;
        case SVG_COLOUR_G:
            gSvgColour = "green";
            break;
        case SVG_COLOUR_B:
            gSvgColour = "blue";
            break;
        case SVG_COLOUR_C:
            gSvgColour = "cyan";
            break;
        case SVG_COLOUR_M:
            gSvgColour = "magenta";
            break;
        case SVG_COLOUR_Y:
            gSvgColour = "yellow";
            break;
        case SVG_COLOUR_K:
            gSvgColour = "black";
            break;
        case SVG_COLOUR_W:
            gSvgColour = "white";
            break;
        default:
            res = false;
        }

        return res;
    }

public:
    DefinitionList();
    virtual ~DefinitionList();

    bool isLine(const char* s)
    {
        size_t i;
        for (i = 0; i < size(); i++)
        {
            Definition curDef = at(i);
            if (curDef.getType() == DEFINITION_TYPE_LINEDEFINITION)
            {
                if (curDef.getName() == std::string(s))
                    return true;
            }
        }

        return false;
    }

    bool isPoint(const char* s)
    {
        size_t i;
        for (i = 0; i < size(); i++)
        {
            Definition curDef = at(i);
            if (curDef.getType() == DEFINITION_TYPE_POINTDEFINITION)
            {
                if (curDef.getName() == std::string(s))
                    return true;
            }
        }

        return false;
    }

    void write(FILE *ofp, std::string inputFile)
    {
        double minX = 0;
        double minY = 0;
        double maxX = 0;
        double maxY = 0;

        getMaxMin(minX, minY, maxX, maxY);

        double xExtent = fabs(maxX - minX);
        double yExtent = fabs(maxY - minY);

        double margin = 100 + xExtent/50;
        double svgWidth = xExtent + margin;
        double svgHeight = yExtent + margin;

        double deltaX = -minX+margin/2;
        double deltaY = maxY+margin/2;

        gSvgPointRadius =  (int)((xExtent + yExtent)/300);
        gSvgFontSize = (int)((xExtent + yExtent)/75);

        if (gWriteSvg)
        {
            fprintf(ofp, 
                    "<svg xmlns=\"http://www.w3.org/2000/svg\"\n"
                    "    width=\"%.0f\"\n"
                    "    height=\"%.0f\"\n"
                    "    >\n",
                    svgWidth,
                    svgHeight
                    );

            /* banner */
            fprintf(ofp, "\n<!--\n      **  %s **\n\n      input file: %s\n\n", progname, inputFile.c_str());
            fprintf(ofp, 
                    "      margin %.2f\n      minX %.2f - maxX %.2f : %.2f\n      minY %.2f - MaxY %.2f : %.2f\n\n\n", 
                    margin,
                    minX, 
                    maxX, 
                    xExtent,
                    minY, 
                    maxY,
                    yExtent);
            fprintf(ofp, "-->\n\n");
        }
        else
        {
            fprintf(ofp, "input file %s\n", inputFile.c_str());
            fprintf(ofp, 
                    "width %.2f - %.2f : %.2f\nheight %.2f - %.2f : %.2f\n", 
                    minX, 
                    maxX, 
                    fabs(maxX - minX),
                    minY, 
                    maxY,
                    fabs(maxY - minY));
        }

        fprintf(ofp, 
                "<g\n"
                "   transform=\"translate(%.0f,%.0f)\">\n",
                deltaX,
                deltaY);

        size_t i;
        for (i = 0; i < size(); i++)
        {
            Definition cur = at(i);

            if (cur.getType() == DEFINITION_TYPE_POINTDEFINITION)
            {
                if (gSvgFlag != SVG_FLAG_NODRAW)
                    write(ofp, cur.getPointDefinition());
            }
            else if (cur.getType() == DEFINITION_TYPE_LINEDEFINITION)
            {
                if (gSvgFlag != SVG_FLAG_NODRAW)
                    write(ofp, cur.getLineDefinition());
            }
            else if (cur.getType() == DEFINITION_TYPE_SVGFLAG)
            {
                if (gWriteSvg)
                {
                    SVG_FLAGS fCur = cur.getFlag();
                    if (!setColour(fCur))
                        gSvgFlag = fCur;
                }
                else
                {
                    fprintf(ofp, "#svg %s\n", cur.getFlagName().c_str());
                }
            }
        }

        if (gWriteSvg)
        {
            fprintf(ofp, "</g>\n</svg>\n");
        }

    }
};



#endif // have_DefinitionList
