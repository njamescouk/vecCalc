// vecCalcGlobals.h
#ifndef have_vecCalcGlobals
#define have_vecCalcGlobals

class DefinitionList;

extern char *progname;
extern char *szVersion;
extern DefinitionList gResult;
extern bool gWriteSvg;

#include <string>

enum SVG_FLAGS
{
    SVG_FLAG_NONE,
    SVG_FLAG_DRAW,
    SVG_FLAG_NODRAW,
    SVG_FLAG_SOLID,
    SVG_FLAG_DASHED,
    SVG_COLOUR_R,
    SVG_COLOUR_G,
    SVG_COLOUR_B,
    SVG_COLOUR_C,
    SVG_COLOUR_M,
    SVG_COLOUR_Y,
    SVG_COLOUR_K,
    SVG_COLOUR_W,
};

extern SVG_FLAGS gSvgFlag;

extern const std::string gSvgDashes;
extern std::string gSvgColour;
extern const std::string gSvgPointColour;
extern int gSvgFontSize;
extern int gSvgPointRadius;


#endif // have_vecCalcGlobals

