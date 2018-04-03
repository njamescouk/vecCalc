#include "vecCalcGlobals.h" 
#include "DefinitionList.h"

char *progname = 0;
char *szVersion = "1.0";
DefinitionList gResult;
bool gWriteSvg = true;
SVG_FLAGS gSvgFlag = SVG_FLAG_NONE;

const std::string gSvgDashes = " stroke-dasharray=\"8, 8\" ";
std::string gSvgColour = "black";
const std::string gSvgPointColour = "red";
int gSvgPointRadius = 10;
int gSvgFontSize = 40;
