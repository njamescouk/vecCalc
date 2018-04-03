// LineDefinition.h
#ifndef have_LineDefinition
#define have_LineDefinition

#include "LineRef.h"
#include "Name.h"
#include "PointRef.h"
#include <cstdio>

enum LINEDEFINITION_TYPE
{
    LINEDEFINITION_TYPE_NONE = 0,
    LINEDEFINITION_TYPE_LINE,
    LINEDEFINITION_TYPE_PERPENDICULAR,
    LINEDEFINITION_TYPE_PARALLEL,
    LINEDEFINITION_TYPE_EXTEND,
    LINEDEFINITION_TYPE_SLIDE,
};

class LineDefinition
{
    LINEDEFINITION_TYPE m_type;
    Name m_name;
    PointRef m_pointRef;
    PointRef m_pointRef1;
    LineRef m_lineRef;
    long m_number;

public:
    LineDefinition();
    LineDefinition(Name n, PointRef from, PointRef to);
    LineDefinition(LINEDEFINITION_TYPE t, Name n, LineRef l, PointRef p);
    LineDefinition(Name n, LineRef l, long i, LINEDEFINITION_TYPE type);

    virtual ~LineDefinition();
    
    LINEDEFINITION_TYPE getType()
    {
        return m_type;
    }

    std::string getName()
    {
        return m_name;
    }

    PointRef getPointRef()
    {
        return m_pointRef;
    }

    PointRef getPointRef1()
    {
        return m_pointRef1;
    }

    LineRef getLineRef()
    {
        return m_lineRef;
    }

    long getNumber()
    {
        return m_number;
    }
};



#endif // have_LineDefinition
