#include "PointDefinition.h" 

PointDefinition::PointDefinition() 
    : m_type(POINTDEFINITION_TYPE_NONE)
{
}

PointDefinition::PointDefinition(Name n, long x, long y)
    : m_type(POINTDEFINITION_TYPE_POINT)
    , m_name(n)
    , m_xcoord(x)
    , m_ycoord(y)
{
}

PointDefinition::PointDefinition(Name n, LineRef l1, LineRef l2)
    : m_type(POINTDEFINITION_TYPE_INTERSECT)
    , m_name(n)
    , m_lineRef(l1)
    , m_lineRef1(l2)
{
}

PointDefinition::PointDefinition(Name n, PointRef p, PointRef p2)
    : m_type(POINTDEFINITION_TYPE_BISECT)
    , m_name(n)
    , m_pointRef(p)
    , m_pointRef1(p2)
{
}

PointDefinition::PointDefinition(Name n, LineRef l)
    : m_type(POINTDEFINITION_TYPE_BISECT_LINE)
    , m_name(n)
    , m_lineRef(l)
{
}

PointDefinition::~PointDefinition() 
{
}
