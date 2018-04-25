// SvgFlagState.h
#ifndef have_SvgFlagState
#define have_SvgFlagState

#include <string>
#pragma warning( disable : 4996 )

enum SVG_FLAGS
{
    SVG_FLAG_NONE,
    SVG_FLAG_DRAW,
    SVG_FLAG_NODRAW,
    SVG_FLAG_SOLID,
    SVG_FLAG_DASHED,
    SVG_FLAG_COLOUR_R,
    SVG_FLAG_COLOUR_G,
    SVG_FLAG_COLOUR_B,
    SVG_FLAG_COLOUR_C,
    SVG_FLAG_COLOUR_M,
    SVG_FLAG_COLOUR_Y,
    SVG_FLAG_COLOUR_K,
    SVG_FLAG_COLOUR_W,
};

class SvgFlagState
{
    std::string m_dashes;
    std::string m_lineColour;
    std::string m_textColour;
    std::string m_pointColour;
    int m_pointRadius;
    int m_angleRadius;
    int m_fontSize;
    int m_dashSize;
    bool m_draw; // if false no svg written

public:
    SvgFlagState()
        :m_textColour("black")
        ,m_lineColour("black")
        ,m_pointColour("red")
        ,m_pointRadius(10)
        ,m_angleRadius(80)
        ,m_fontSize(40)
        ,m_dashSize(8)
        ,m_draw(true)
    {}

    virtual ~SvgFlagState(){}

    void setFontSize(int i)
    {
        m_fontSize = i;
    }

    void setPointRadius(int i)
    {
        m_pointRadius = i;
    }

    void setAngleRadius(int i)
    {
        m_angleRadius = i;
    }

    void setDashSize(int i)
    {
        m_dashSize = i;
    }

    void setState(SVG_FLAGS f)
    {
        switch (f)
        {
        case SVG_FLAG_DRAW:
            m_draw = true;
            break;
        case SVG_FLAG_NODRAW:
            m_draw = false;
            break;
        case SVG_FLAG_SOLID:
            m_draw = true;
            m_dashes = "";
            break;
        case SVG_FLAG_DASHED:
            m_draw = true;
            char szDashes[BUFSIZ];
            sprintf(szDashes, "stroke-dasharray=\"%d, %d\"", m_dashSize, m_dashSize);
            m_dashes = szDashes;
            break;
        case SVG_FLAG_COLOUR_R:
        case SVG_FLAG_COLOUR_G:
        case SVG_FLAG_COLOUR_B:
        case SVG_FLAG_COLOUR_C:
        case SVG_FLAG_COLOUR_M:
        case SVG_FLAG_COLOUR_Y:
        case SVG_FLAG_COLOUR_K:
        case SVG_FLAG_COLOUR_W:
            setColour(f);
            break;
        }
    }

    bool setColour(SVG_FLAGS f)
    {
        bool res = true;

        switch (f)
        {
        case SVG_FLAG_COLOUR_R:
            m_lineColour = "red";
            break;
        case SVG_FLAG_COLOUR_G:
            m_lineColour = "green";
            break;
        case SVG_FLAG_COLOUR_B:
            m_lineColour = "blue";
            break;
        case SVG_FLAG_COLOUR_C:
            m_lineColour = "cyan";
            break;
        case SVG_FLAG_COLOUR_M:
            m_lineColour = "magenta";
            break;
        case SVG_FLAG_COLOUR_Y:
            m_lineColour = "yellow";
            break;
        case SVG_FLAG_COLOUR_K:
            m_lineColour = "black";
            break;
        case SVG_FLAG_COLOUR_W:
            m_lineColour = "white";
            break;
        default:
            res = false;
        }

        return res;
    }

    int getPointRadius()
    {
        return m_pointRadius;
    }

    int getAngleRadius()
    {
        return m_angleRadius;
    }

    int getFontSize()
    {
        return m_fontSize;
    }

    std::string getPointColour()
    {
        return m_pointColour;
    }

    std::string getLineColour()
    {
        return m_lineColour;
    }

    std::string getDashes()
    {
        return m_dashes;
    }

    bool draw()
    {
        return m_draw;
    }

    void dump(FILE *fp)
    {
        fprintf(fp, 
                "flags:\n"
                "  angleRadius %d\n"
                "  fontSize %d\n"
                "  pointRadius %d\n",
                m_angleRadius,
                m_fontSize,
                m_pointRadius
                );
    }
};



#endif // have_SvgFlagState

