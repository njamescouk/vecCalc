// PointDefinition.h
#ifndef have_PointDefinition
#define have_PointDefinition

#include "LineRef.h"
#include "Name.h"
#include "PointRef.h"
#include <string>
#include <cstdio>
#include "vecCalcGlobals.h" 

enum POINTDEFINITION_TYPE
{
    POINTDEFINITION_TYPE_NONE = 0,
    POINTDEFINITION_TYPE_POINT,
    POINTDEFINITION_TYPE_INTERSECT,
    POINTDEFINITION_TYPE_BISECT,
    POINTDEFINITION_TYPE_BISECT_LINE,
};

class PointDefinition
{
    POINTDEFINITION_TYPE m_type;
    Name m_name;
    long m_xcoord;
    long m_ycoord;
    LineRef m_lineRef;
    LineRef m_lineRef1;
    long m_number;
    PointRef m_pointRef;
    PointRef m_pointRef1;

    void writePoint(FILE *fp)
    {
        fprintf(fp, "%ld,%ld\n", m_xcoord, m_ycoord);
    }

public:
    PointDefinition();
    PointDefinition(Name n, long x, long y);
    PointDefinition(Name n, LineRef l1, LineRef l2);
    PointDefinition(Name n, PointRef p, PointRef p2);
    PointDefinition(Name n, LineRef l);

    virtual ~PointDefinition();
        
    POINTDEFINITION_TYPE getType()
    {
        return m_type;
    }

    std::string getName()
    {
        return m_name;
    }

    long x()
    {
        return m_xcoord;
    }

    long y()
    {
        return m_ycoord;
    }

    LineRef getLineRef()
    {
        return m_lineRef;
    }

    LineRef getLineRef1()
    {
        return m_lineRef1;
    }

    PointRef getPointRef()
    {
        return m_pointRef;
    }
    
    PointRef getPointRef1()
    {
        return m_pointRef1;
    }

    void print(FILE *fp)
    {
        fprintf (fp, 
                    "<circle fill=\"%s\" cx=\"%ld\" cy=\"%ld\" r=\"%d\"/>"
                    "<text x=\"%ld\" y=\"%ld\" font-size=\"%dpx\">%s</text>\n",
                    gSvgPointColour.c_str(),
                    m_xcoord,
                    -m_ycoord,
                    gSvgPointRadius,
                    m_xcoord + 2*gSvgPointRadius, 
                    -m_ycoord - 2*gSvgPointRadius,
                    gSvgFontSize,
                    m_name.c_str());
    }
};



#endif // have_PointDefinition
