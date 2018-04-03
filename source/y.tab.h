#define ID 257
#define INTEGER 258
#define LINE 259
#define LINE_REF 260
#define POINT_REF 261
#define INTERSECT 262
#define EXTEND 263
#define SLIDE 264
#define PARALLEL 265
#define PERPENDICULAR 266
#define POINT 267
#define BISECT 268
#define SVG_DIRECTIVE 269
#define SVG_FLAG 270
#define LEXERR 271
typedef union
{
    DefinitionList *DefinitionListPtr;
    Definition *DefinitionPtr;
    PointDefinition *PointDefinitionPtr;
    LineDefinition *LineDefinitionPtr;
    Name *NamePtr;
    PointRef *PointRefPtr;
    LineRef *LineRefPtr;
    long longInt;

} YYSTYPE;
extern YYSTYPE yylval;
