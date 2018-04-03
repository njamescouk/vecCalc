#include "Definition.h" 

Definition::Definition() 
    : m_type(DEFINITION_TYPE_NONE)
{
}

Definition::Definition(Name n)
    : m_type(DEFINITION_TYPE_SVGFLAG)
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
        m_flag = SVG_COLOUR_R;
    }
    else if (n == "colG")
    {
        m_flag = SVG_COLOUR_G;
    }
    else if (n == "colB")
    {
        m_flag = SVG_COLOUR_B;
    }
    else if (n == "colC")
    {
        m_flag = SVG_COLOUR_C;
    }
    else if (n == "colM")
    {
        m_flag = SVG_COLOUR_M;
    }
    else if (n == "colY")
    {
        m_flag = SVG_COLOUR_Y;
    }
    else if (n == "colK")
    {
        m_flag = SVG_COLOUR_K;
    }
    else if (n == "colW")
    {
        m_flag = SVG_COLOUR_W;
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

Definition::~Definition() 
{
}
