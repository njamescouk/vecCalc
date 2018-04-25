#include "Definition.h" 
#include <cassert>

Definition::Definition() 
    : m_type(DEFINITION_TYPE_NONE)
{
}

Definition::Definition(DEFINITION_TYPE type, Name n)
    : m_type(type)
{
    assert(type == DEFINITION_TYPE_SVGFLAG || type == DEFINITION_TYPE_INCDIR);

    if (type == DEFINITION_TYPE_SVGFLAG)
    {
        if (n == "dashed")
        {
            m_flag = SVG_FLAG_DASHED;
        }
        else if (n == "draw")
        {
            m_flag = SVG_FLAG_DRAW;
        }
        else if (n == "nodraw")
        {
            m_flag = SVG_FLAG_NODRAW;
        }
        else if (n == "solid")
        {
            m_flag = SVG_FLAG_SOLID;
        }
        else if (n == "colR")
        {
            m_flag = SVG_FLAG_COLOUR_R;
        }
        else if (n == "colG")
        {
            m_flag = SVG_FLAG_COLOUR_G;
        }
        else if (n == "colB")
        {
            m_flag = SVG_FLAG_COLOUR_B;
        }
        else if (n == "colC")
        {
            m_flag = SVG_FLAG_COLOUR_C;
        }
        else if (n == "colM")
        {
            m_flag = SVG_FLAG_COLOUR_M;
        }
        else if (n == "colY")
        {
            m_flag = SVG_FLAG_COLOUR_Y;
        }
        else if (n == "colK")
        {
            m_flag = SVG_FLAG_COLOUR_K;
        }
        else if (n == "colW")
        {
            m_flag = SVG_FLAG_COLOUR_W;
        }
    }
    else if (type == DEFINITION_TYPE_INCDIR)
    {
        m_include = n;
    }
}

Definition::Definition(PointDefinition pd)
    : m_type(DEFINITION_TYPE_POINTDEFINITION)
    , m_pointDefinition(pd)
{
}

Definition::Definition(LineDefinition ld)
    : m_type(DEFINITION_TYPE_LINEDEFINITION)
    , m_lineDefinition(ld)
{
}

Definition::Definition(CircleDefinition cd)
    : m_type(DEFINITION_TYPE_CIRCLEDEFINITION)
    , m_circleDefinition(cd)
{
}

Definition::Definition(AngleDefinition ad)
    : m_type(DEFINITION_TYPE_ANGLEDEFINITION)
    , m_angleDefintion(ad)
{
}

Definition::Definition(VarDefinition vd)
    : m_type(DEFINITION_TYPE_VARDEFINITION)
    , m_varDefinition(vd)
{
}

Definition::~Definition() 
{
}
