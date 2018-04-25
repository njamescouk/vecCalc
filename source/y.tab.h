#define ID 257
#define INTEGER 258
#define LINE 259
#define LINE_REF 260
#define POINT_REF 261
#define CIRCLE_REF 262
#define VAR_REF 263
#define INTERSECT 264
#define EXTEND 265
#define SLIDE 266
#define PARALLEL 267
#define PERPENDICULAR 268
#define POINT 269
#define CIRCLE 270
#define ARC 271
#define ANGLE 272
#define VAR 273
#define BISECT 274
#define SVG_DIRECTIVE 275
#define INC_DIRECTIVE 276
#define FILENAME 277
#define SVG_FLAG 278
#define DIVIDE 279
#define MULTIPLY 280
#define ADD 281
#define SUBTRACT 282
#define LEXERR 283
typedef union
{
    DefinitionList *DefinitionListPtr;
    Definition *DefinitionPtr;
    PointDefinition *PointDefinitionPtr;
    LineDefinition *LineDefinitionPtr;
    CircleDefinition *CircleDefinitionPtr;
    AngleDefinition *AngleDefinitionPtr;
    VarDefinition *VarDefinitionPtr;
    Name *NamePtr;
    PointRef *PointRefPtr;
    LineRef *LineRefPtr;
    CircleRef *CircleRefPtr;
    VarRef *VarRefPtr;
    long longInt;
    double realNum;
} YYSTYPE;
extern YYSTYPE yylval;
