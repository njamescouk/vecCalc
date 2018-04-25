// Definition.h
#ifndef have_Definition
#define have_Definition

#include "LineDefinition.h"
#include "PointDefinition.h"
#include "CircleDefinition.h"
#include "AngleDefinition.h"
#include "VarDefinition.h"
#include "SvgFlagState.h"

#pragma warning( disable : 4996 )

enum DEFINITION_TYPE
{
    DEFINITION_TYPE_NONE = 0,
    DEFINITION_TYPE_LINEDEFINITION,
    DEFINITION_TYPE_POINTDEFINITION,
    DEFINITION_TYPE_CIRCLEDEFINITION,
    DEFINITION_TYPE_ANGLEDEFINITION,
    DEFINITION_TYPE_VARDEFINITION,
    DEFINITION_TYPE_SVGFLAG,
    DEFINITION_TYPE_INCDIR,
};

class Definition
{
    DEFINITION_TYPE m_type;
    PointDefinition m_pointDefinition;
    LineDefinition m_lineDefinition;
    AngleDefinition m_angleDefintion;
    VarDefinition m_varDefinition;
    CircleDefinition m_circleDefinition;
    SVG_FLAGS m_flag;
    std::string m_include;

public:
    Definition();
    Definition(DEFINITION_TYPE type, Name n);
    Definition(PointDefinition pd);
    Definition(LineDefinition pd);
    Definition(CircleDefinition cd);
    Definition(AngleDefinition ad);
    Definition(VarDefinition vd);
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
        else if (m_type == DEFINITION_TYPE_CIRCLEDEFINITION)
            return m_circleDefinition.getName();
        else if (m_type == DEFINITION_TYPE_ANGLEDEFINITION)
            return m_angleDefintion.getName();
        else if (m_type == DEFINITION_TYPE_VARDEFINITION)
            return m_varDefinition.getName();

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

    std::string getInclude()
    {
        return m_include;
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
        case SVG_FLAG_COLOUR_R:
            return "colR";
        case SVG_FLAG_COLOUR_G:
            return "colG";
        case SVG_FLAG_COLOUR_B:
            return "colB";
        case SVG_FLAG_COLOUR_C:
            return "colC";
        case SVG_FLAG_COLOUR_M:
            return "colM";
        case SVG_FLAG_COLOUR_Y:
            return "colY";
        case SVG_FLAG_COLOUR_K:
            return "colK";
        case SVG_FLAG_COLOUR_W:
            return "colW";
        }

        return "none";
    }

    void writeInclude(FILE *ofp)
    {
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

};



#endif // have_Definition
