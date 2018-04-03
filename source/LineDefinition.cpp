#include "LineDefinition.h" 

LineDefinition::LineDefinition() 
    :m_type(LINEDEFINITION_TYPE_NONE)
{
}

LineDefinition::LineDefinition(Name n, PointRef from, PointRef to)
    : m_type(LINEDEFINITION_TYPE_LINE)
    , m_name(n)
    , m_pointRef(from)
    , m_pointRef1(to)
{
}

LineDefinition::LineDefinition(LINEDEFINITION_TYPE t, Name n, LineRef l, PointRef p)
    : m_type(t)
    , m_name(n)
    , m_lineRef(l)
    , m_pointRef(p)
{
}

LineDefinition::LineDefinition(Name n, LineRef l, long i, LINEDEFINITION_TYPE type)
    : m_type(type)
    , m_name(n)
    , m_lineRef(l)
    , m_number(i)
{
}

LineDefinition::~LineDefinition() 
{
}
