// VecCalcSchedule.h
#ifndef have_VecCalcSchedule
#define have_VecCalcSchedule

#include "vecCalcGlobals.h"
#include "Definition.h"
#include "VecCalcScheduleLine.h"
#include <vector>
#include <cassert>

struct DrawingParameters
{
    std::string m_inputFile;
    double m_minX;
    double m_minY;
    double m_maxX;
    double m_maxY;
    double m_xExtent;
    double m_yExtent;
    double m_margin;
    double m_svgWidth;
    double m_svgHeight;
    double m_deltaX;
    double m_deltaY;
    int m_pointRadius;
    int m_fontSize;
    
    void compute(std::string inputFile, double minX, double minY, double maxX, double maxY)
    {
        m_inputFile = inputFile;
        m_minX = minX;
        m_minY = minY;
        m_maxX = maxX;
        m_maxY = maxY;

        m_xExtent = fabs(maxX - minX);
        m_yExtent = fabs(maxY - minY);

        m_margin = 100 + m_xExtent/50;
        m_svgWidth = m_xExtent + m_margin;
        m_svgHeight = m_yExtent + m_margin;

        m_deltaX = -m_minX+m_margin/2;
        m_deltaY = m_maxY+m_margin/2;

        m_pointRadius = (int)((m_xExtent + m_yExtent)/300.0);
        if (m_pointRadius < 5)
            m_pointRadius = 3;

        m_fontSize = (int)((m_xExtent + m_yExtent)/75);
        if (m_fontSize < 20.0)
            m_fontSize = 15;
    }

    void dump(FILE *fp)
    {
        fprintf (fp,
                 "drawing parameters:\n"
                 "  minX %.2f\n"
                 "  minY %.2f\n"
                 "  maxX %.2f\n"
                 "  maxY %.2f\n"
                 "  xExtent %.2f\n"
                 "  yExtent %.2f\n"
                 "  margin %.2f\n"
                 "  svgWidth %.2f\n"
                 "  svgHeight %.2f\n"
                 "  deltaX %.2f\n"
                 "  deltaY %.2f\n"
                 "  pointRadius %d\n"
                 "  fontSize %d\n",
                 m_minX,
                 m_minY,
                 m_maxX,
                 m_maxY,
                 m_xExtent,
                 m_yExtent,
                 m_margin,
                 m_svgWidth,
                 m_svgHeight,
                 m_deltaX,
                 m_deltaY,
                 m_pointRadius,
                 m_fontSize);
    }
};

class VecCalcSchedule : public std::vector<VecCalcScheduleLine>
{
    PointTable m_pointTable;
    LineTable m_lineTable;
    AngleTable m_angleTable;
    CircleTable m_circleTable;
    VarTable m_varTable;
    std::string m_lastTok;

    void writeSvgPreamble(FILE *fp, DrawingParameters dp)
    {
        std::string title = dp.m_inputFile.substr(1+dp.m_inputFile.find_last_of("\\/"));
        fprintf(fp, 
                "<svg xmlns=\"http://www.w3.org/2000/svg\"\n"
                "    width=\"%.0f\"\n"
                "    height=\"%.0f\"\n"
                "    >\n"
                "<title>%s</title>\n",
                dp.m_svgWidth,
                dp.m_svgHeight,
                title.c_str()
                );

        /* banner */
        fprintf(fp, "\n<!--\n      **  %s **\n\n      input file: %s\n\n", progname, dp.m_inputFile.c_str());
        fprintf(fp, 
                "      margin %.2f\n      minX %.2f - maxX %.2f : %.2f\n      minY %.2f - MaxY %.2f : %.2f\n\n\n", 
                dp.m_margin,
                dp.m_minX, 
                dp.m_maxX, 
                dp.m_xExtent,
                dp.m_minY, 
                dp.m_maxY,
                dp.m_yExtent);
        fprintf(fp, "-->\n\n");

        fprintf(fp, 
                "<g\n"
                "   transform=\"translate(%.0f,%.0f)\">\n",
                dp.m_deltaX,
                dp.m_deltaY);
    }

    void dump(FILE *fp, DrawingParameters dp)
    {
        fprintf(fp, "input file %s\n", dp.m_inputFile.c_str());
        fprintf(fp, 
                "width %.2f - %.2f : %.2f\nheight %.2f - %.2f : %.2f\n", 
                dp.m_minX, 
                dp.m_maxX, 
                fabs(dp.m_maxX - dp.m_minX),
                dp.m_minY, 
                dp.m_maxY,
                fabs(dp.m_maxY - dp.m_minY));

        dp.dump(fp);
        gSvgFlagState.dump(fp);
        m_pointTable.dump(fp);
        m_lineTable.dump(fp);
        m_angleTable.dump(fp);
   }

public:

    void installPoint(std::string name, PosVector pv)
    {
        m_pointTable[name] = pv;
    }

    void installLine(std::string name, Line li)
    {
        m_lineTable[name] = li;
    }

    void installCircle(std::string name, Circle ci)
    {
        m_circleTable[name] = ci;
    }

    void installAngle(std::string name, PointTriple ppp)
    {
        m_angleTable[name] = ppp;
    }

    void installVar(std::string name, double d)
    {
        m_varTable[name] = d;
    }

    bool isPointInTable(std::string s)
    {
        return (m_pointTable.find(s) != m_pointTable.end());
    }

    bool isLineInTable(std::string s)
    {
        return (m_lineTable.find(s) != m_lineTable.end());
    }

    bool isCircleInTable(std::string s)
    {
        return (m_circleTable.find(s) != m_circleTable.end());
    }

    bool isVarInTable(std::string s)
    {
        return (m_varTable.find(s) != m_varTable.end());
    }

    PosVector getPoint(std::string s)
    {
        if (m_pointTable.find(s) != m_pointTable.end())
            return m_pointTable.at(s);

        fprintf(stderr, "no point %s\n", s.c_str()); 
        assert(false);
        return PosVector();
    }

    Line getLine(std::string s)
    {
        if (m_lineTable.find(s) != m_lineTable.end())
            return m_lineTable.at(s);

        fprintf(stderr, "no line %s\n", s.c_str()); 
        assert(false);
        return Line();
    }

    double getVar(std::string s)
    {
        if (m_varTable.find(s) != m_varTable.end())
            return m_varTable.at(s);

        fprintf(stderr, "no var %s\n", s.c_str()); 
        assert(false);
        return 0.0;
    }

    void getMaxMin(double &minX, double &minY, double &maxX, double &maxY)
    {
        minX = DBL_MAX;
        minY = DBL_MAX;
        maxX = -DBL_MAX;
        maxY = -DBL_MAX;

        m_pointTable.getMaxMin(minX, minY, maxX, maxY);
        m_lineTable.getMaxMin(minX, minY, maxX, maxY);
        m_circleTable.getMaxMin(minX, minY, maxX, maxY);

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

    void write(FILE *ofp, std::string inputFile, bool writeSvg)
    {
        double minX, 
               minY, 
               maxX,
               maxY;

        getMaxMin(minX, minY, maxX, maxY);
        DrawingParameters dp;
        dp.compute(inputFile, minX, minY, maxX, maxY);
        gSvgFlagState.setFontSize(dp.m_fontSize);
        gSvgFlagState.setPointRadius(dp.m_pointRadius);
        gSvgFlagState.setAngleRadius(2*dp.m_fontSize);
        gSvgFlagState.setDashSize(dp.m_pointRadius);

        if (writeSvg)
        {
            writeSvgPreamble(ofp, dp);
            size_t i;
            for (i = 0; i < size(); i++)
            {
                VecCalcScheduleLine cur = at(i);
                cur.writeSvg(ofp, m_pointTable, m_lineTable, m_angleTable, m_circleTable, m_varTable);
            }

            fprintf(ofp, "</g>\n</svg>\n");
        }
        else
        {
            dump(ofp, dp);
        }
    }

    void setLastToken(std::string s)
    {
        m_lastTok = s;
    }

    std::string getLastToken()
    {
        return m_lastTok;
    }
};

#endif // have_VecCalcSchedule

