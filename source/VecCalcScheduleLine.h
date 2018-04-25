// VecCalcScheduleLine.h
#ifndef have_VecCalcScheduleLine
#define have_VecCalcScheduleLine

#include <cassert>
#include "PosVector.h"
#include "Line.h"
#include "Circle.h"
#include "PointTable.h"
#include "LineTable.h"
#include "CircleTable.h"
#include "AngleTable.h"
#include "VarTable.h"
#include "split_string.h"

enum SCHEDULE_TYPE
{
    SCHEDULE_TYPE_NONE,
    SCHEDULE_TYPE_POINT,
    SCHEDULE_TYPE_LINE,
    SCHEDULE_TYPE_CIRCLE,
    SCHEDULE_TYPE_ANGLE,
    SCHEDULE_TYPE_VAR,
    SCHEDULE_TYPE_FLAG,
    SCHEDULE_TYPE_INC,
};

class VecCalcScheduleLine
{

    void writeArcSvg(FILE *fp, 
                     std::string name, 
                     int arcRadius,
                     PointTriple ppp,
                     PosVector &start,
                     PosVector &end)
    {
        /* lines from centre of arc to points */
        Line line1(ppp.point2, ppp.point1);
        Line line2(ppp.point2, ppp.point3);

        /* start (theta) and end (thetaPlusDeltaTheta) angles */
        double theta = line1.angle(); 
        double thetaPlusDeltaTheta = line2.angle(); 
        double deltaTheta = thetaPlusDeltaTheta - theta;
        double interiorAngle = deltaTheta;
        if (deltaTheta > PI)
        {
            interiorAngle = deltaTheta - 2*PI;  
        }
        else if (deltaTheta < -PI)
        {
            interiorAngle = 2*PI + deltaTheta;
        }
        deltaTheta = interiorAngle;

        int largeArcFlag; // fA
        int increasingAngleFlag; //fS
        setArcFlags(deltaTheta, largeArcFlag, increasingAngleFlag);

        /* points m_angleRadius from centre along lines 1 & 2 */
        PosVector point1 = line1.pvHat() * arcRadius;
        PosVector point2 = line2.pvHat() * arcRadius;

        /* start and end wrt to origin */
        start = point1 + ppp.point2;
        end = point2 + ppp.point2;

        std::string title = "angle " + name;
        writeArcSvg(fp, title, arcRadius, start, end, largeArcFlag, increasingAngleFlag, "black");
    }

    void writeArcSvg(FILE *fp, 
                     std::string name, 
                     double arcRadius, 
                     PosVector start, 
                     PosVector end, 
                     int largeArcFlag, 
                     int increasingAngleFlag,
                     std::string colour="")
    {
        std::string titleStr;
        if (!name.empty())
        {
            titleStr = "title=\"" + escape(name) + "\"";
        }

        if (colour.empty())
            colour = gSvgFlagState.getLineColour();

        fprintf (fp, 
                    "<path %s fill=\"none\" stroke=\"%s\" %s "
                    "d=\"M%s A %.2f %.2f 0 %d,%d  %s\"/>\n",
                    titleStr.c_str(),
                    colour.c_str(),
                    gSvgFlagState.getDashes().c_str(),
                    start.toPath().c_str(),
                    arcRadius,
                    arcRadius,
                    largeArcFlag,
                    increasingAngleFlag,
                    end.toPath().c_str());
    }

    void setArcFlags(double deltaTheta, int &largeArcFlag, int &increasingAngleFlag)
    {
        largeArcFlag = 1; // fA
        increasingAngleFlag = 1; //fS

        if (deltaTheta > 0.0)
        {
            if (deltaTheta <= PI)
                largeArcFlag = 0;
        }
        else
        {
            if (-deltaTheta <= PI)
                largeArcFlag = 0;
        }

        if (deltaTheta < 0)
            increasingAngleFlag = 0;

        bool invertFsLogic = true;
        if (invertFsLogic)
            increasingAngleFlag == 1?increasingAngleFlag = 0:increasingAngleFlag=1;
    }

public:
    SCHEDULE_TYPE m_type;
    std::string m_pointRef;
    std::string m_lineRef;
    std::string m_circleRef;
    std::string m_angleRef;
    std::string m_varRef;
    SVG_FLAGS m_flag;
    std::string m_include;

    /* use unicode escapes for double quotes */
    std::string escape(std::string s)
    {
        std::string res = s;
        splitstring::subst(res, "\"", "&#x0022;");  

        return res;
    }

    void writePointSvg(FILE *fp, std::string name, PosVector pv)
    {
        if (!gSvgFlagState.draw())
            return;

        int pointRadius = gSvgFlagState.getPointRadius();
        std::string title = escape(name) + " " + pv.toString();
        fprintf (fp, 
                    "<circle title=\"%s\" fill=\"%s\" cx=\"%.0f\" cy=\"%.0f\" r=\"%d\"/>"
                    "<text x=\"%.0f\" y=\"%.0f\" font-size=\"%dpx\">%s</text>\n",
                    title.c_str(),
                    gSvgFlagState.getPointColour().c_str(),
                    pv.x(),
                    -pv.y(),
                    pointRadius,
                    pv.x() + 2*pointRadius, 
                    -pv.y() - 2*pointRadius,
                    gSvgFlagState.getFontSize(),
                    name.c_str());
    }

    void writeLineSvg(FILE *fp, std::string name, Line li)
    {
        if (!gSvgFlagState.draw())
            return;

        PosVector pvFrom = li.getFrom();
        PosVector pvTo = li.getTo();

        fprintf (fp, 
                    "<path title=\"%s\" stroke=\"%s\" %s d=\"M%s %s\"/>\n",
                    escape(name).c_str(),
                    gSvgFlagState.getLineColour().c_str(),
                    gSvgFlagState.getDashes().c_str(),
                    pvFrom.toPath().c_str(), 
                    pvTo.toPath().c_str());
    }

    void writeCircleSvg(FILE *fp, std::string name, Circle ci)
    {
        if (!gSvgFlagState.draw())
            return;

        if (ci.isArc())
        {
            double deltaTheta = ci.positiveDelta();
            int increasingFlag;
            int largeFlag;
            setArcFlags(deltaTheta, largeFlag, increasingFlag);
            PosVector start = ci.arcStart();
            PosVector end = ci.arcEnd();
            writeArcSvg(fp, 
                        name, 
                        ci.getRadius(), 
                        start, 
                        end, 
                        largeFlag, 
                        increasingFlag);
        }
        else
        {
            fprintf (fp, 
                     "<circle title=\"%s\" cx=\"%.2f\" cy=\"%.2f\" r=\"%.2f\" "
                      "fill=\"none\" stroke=\"%s\" %s />\n",
                     escape(name).c_str(),
                     ci.getCentre().x(),
                     -ci.getCentre().y(), /* in svg land */
                     ci.getRadius(),
                     gSvgFlagState.getLineColour().c_str(),
                     gSvgFlagState.getDashes().c_str());
        }
    }

    /* 
        draw arc centred on ppp.point2, radius 
        gSvgFlagState.m_angleRadius from 
        line1 = ppp.point2->ppp.point1
        to line2 = ppp.point2->ppp.point3 or vice versa
    */
    void writeAngleSvg(FILE *fp, std::string name, PointTriple ppp)
    {
        if (!gSvgFlagState.draw())
            return;

        int arcRadius = gSvgFlagState.getAngleRadius();

        PosVector startPoint;
        PosVector endPoint;
        writeArcSvg(fp, name, arcRadius, ppp, startPoint, endPoint);

        bool printEllipEnds=false;
        if (printEllipEnds)
        {
            writePointSvg(fp, "1", startPoint);
            writePointSvg(fp, "2", endPoint);
        }
        
        PosVector pvBisector = startPoint.bisect(endPoint);
        Line lBisector(ppp.point2, pvBisector);
        PosVector pvText = lBisector.pvHat() * (1.5 * arcRadius);
        pvText = pvText + ppp.point2;
        fprintf(fp, 
                "    <text x=\"%.0f\" y=\"%.0f\" font-size=\"%dpx\">%s</text>\n", 
                pvText.x(),
                -pvText.y(),
                gSvgFlagState.getFontSize(), 
                name.c_str());
    }

    void writeVarSvg(FILE *ofp, std::string name, double val)
    {
        fprintf(ofp, "    <!-- var %s: %.2f -->\n", name.c_str(), val);  
    }

    void writeSvgInclude(FILE *ofp)
    {
        assert(m_type == SCHEDULE_TYPE_INC);
        FILE *ifp = fopen(m_include.c_str(), "rt");
        {
            if (ifp == 0)
            {
                std::string msg = "Cannot include " + m_include;
                perror(msg.c_str());
                return;
            }
        }

        int c = 0;
        while (!feof(ifp) && !ferror(ifp))
        {
            c = fgetc(ifp);
            if (c != EOF)
                fputc(c, ofp);
        }

        fclose(ifp);
    }

public:
    VecCalcScheduleLine()
        : m_type(SCHEDULE_TYPE_NONE)
    {}

    VecCalcScheduleLine(Definition d)
    {
        switch (d.getType())
        {
            case DEFINITION_TYPE_LINEDEFINITION:
                m_type = SCHEDULE_TYPE_LINE;
                m_lineRef = d.getName();
                break;
            case DEFINITION_TYPE_POINTDEFINITION:
                m_type = SCHEDULE_TYPE_POINT;
                m_pointRef = d.getName();
                break;
            case DEFINITION_TYPE_CIRCLEDEFINITION:
                m_type = SCHEDULE_TYPE_CIRCLE;
                m_circleRef = d.getName();
                break;
            case DEFINITION_TYPE_ANGLEDEFINITION:
                m_type = SCHEDULE_TYPE_ANGLE;
                m_angleRef = d.getName();
                break;
            case DEFINITION_TYPE_VARDEFINITION:
                m_type = SCHEDULE_TYPE_VAR;
                m_varRef = d.getName();
                break;
            case DEFINITION_TYPE_SVGFLAG:
                m_type = SCHEDULE_TYPE_FLAG;
                m_flag = d.getFlag();
                break;
            case DEFINITION_TYPE_INCDIR:
                m_type = SCHEDULE_TYPE_INC;
                m_include = d.getInclude();
                break;
        }
    }

    virtual ~VecCalcScheduleLine(){}

    
    SCHEDULE_TYPE getType()
    {
        return m_type;
    }

    void writeSvg(FILE *ofp, PointTable pt, LineTable lt, AngleTable at, CircleTable ct, VarTable vt)
    {
        switch(m_type)
        {
            case SCHEDULE_TYPE_NONE:
            {
            }
            break;
            case SCHEDULE_TYPE_POINT:
            {
                PosVector pv = pt[m_pointRef];
                writePointSvg(ofp, m_pointRef, pv);
            }
            break;
            case SCHEDULE_TYPE_LINE:
            {
                Line li = lt[m_lineRef];
                writeLineSvg(ofp, m_lineRef, li);
            }
            break;
            case SCHEDULE_TYPE_ANGLE:
            {
                PointTriple ppp = at[m_angleRef];
                writeAngleSvg(ofp, m_angleRef, ppp);
            }
            break;
            case SCHEDULE_TYPE_CIRCLE:
            {
                Circle c = ct[m_circleRef];
                writeCircleSvg(ofp, m_circleRef, c);
            }
            break;
            case SCHEDULE_TYPE_VAR:
            {
                double val = vt[m_varRef];
                writeVarSvg(ofp, m_varRef, val);
            }
            break;
            case SCHEDULE_TYPE_FLAG:
            {
                gSvgFlagState.setState(m_flag);
            }
            break;
            case SCHEDULE_TYPE_INC:
            {
                writeSvgInclude(ofp);
            }
            break;
        }
    }
};



#endif // have_VecCalcScheduleLine

