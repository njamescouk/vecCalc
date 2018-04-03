// Definition.h
#ifndef have_Definition
#define have_Definition

#include "LineDefinition.h"
#include "PointDefinition.h"
#include "vecCalcGlobals.h"

enum DEFINITION_TYPE
{
    DEFINITION_TYPE_NONE = 0,
    DEFINITION_TYPE_LINEDEFINITION,
    DEFINITION_TYPE_POINTDEFINITION,
    DEFINITION_TYPE_SVGFLAG,
};

class Definition
{
    DEFINITION_TYPE m_type;
    PointDefinition m_pointDefinition;
    LineDefinition m_lineDefinition;
    SVG_FLAGS m_flag;

public:
    Definition();
    Definition(Name n);
    Definition(PointDefinition pd);
    Definition(LineDefinition pd);
    virtual ~Definition();
    
    DEFINITION_TYPE getType()
    {
        return m_type;
    }

    std::string getName()
    {
        if (m_type == DEFINITION_TYPE_POINTDEFINITION)
            return m_pointDefinition.getName();
        else if (m_type == DEFINITION_TYPE_LINEDEFINITION)
            return m_lineDefinition.getName();

        return std::string();
    }

    PointDefinition getPointDefinition()
    {
        return m_pointDefinition;
    }

    LineDefinition getLineDefinition()
    {
        return m_lineDefinition;
    }

    SVG_FLAGS getFlag()
    {
        return m_flag;
    }

    std::string getFlagName()
    {
        switch (m_flag)
        {
        case SVG_FLAG_DASHED:
            return "dashed";
        case SVG_FLAG_DRAW:
            return "draw";
        case SVG_FLAG_NODRAW:
            return "nodraw";
        case SVG_FLAG_SOLID:
            return "solid";
        case SVG_COLOUR_R:
            return "colR";
        case SVG_COLOUR_G:
            return "colG";
        case SVG_COLOUR_B:
            return "colB";
        case SVG_COLOUR_C:
            return "colC";
        case SVG_COLOUR_M:
            return "colM";
        case SVG_COLOUR_Y:
            return "colY";
        case SVG_COLOUR_K:
            return "colK";
        case SVG_COLOUR_W:
            return "colW";
        }

        return "none";
    }
};



#endif // have_Definition
