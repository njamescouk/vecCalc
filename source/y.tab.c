#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define yyclearin (yychar=(-1))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING (yyerrflag!=0)
#define YYPREFIX "yy"
#include <stdio.h>
#include <stdlib.h>
#include "DefinitionList.h"
#include "Definition.h"
#include "PointDefinition.h"
#include "LineDefinition.h"
#include "CircleDefinition.h"
#include "AngleDefinition.h"
#include "VarDefinition.h"
#include "Name.h"
#include "PointRef.h"
#include "LineRef.h"
#include "CircleRef.h"
#include "VarRef.h"
#include "yaccFns.h"
#include "vecCalcGlobals.h"
#include "VecCalcSchedule.h"

#pragma warning( disable : 4786 )
#pragma warning( disable : 4996 )

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
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    0,    1,    1,    1,    1,    1,    1,    1,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    3,    3,
    3,    3,    3,    4,    4,    4,    4,    4,    5,    8,
    6,    6,    7,    7,    9,   10,   11,
};
short yylen[] = {                                         2,
    1,    2,    1,    1,    1,    1,    1,    2,    2,    4,
    5,    5,    4,    5,    5,    5,    5,    5,    4,    5,
    5,    5,    5,    5,    4,    4,    6,    6,    5,    3,
    1,    1,    1,    1,    1,    1,    1,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,
    3,    4,    6,    5,    7,   35,    0,    0,    0,    0,
    0,    0,    8,    9,    2,   36,    0,    0,    0,    0,
    0,   31,   32,    0,    0,    0,    0,    0,    0,    0,
   30,   37,    0,    0,    0,    0,   19,    0,    0,   13,
   33,   34,   10,    0,    0,    0,    0,    0,   25,    0,
    0,    0,   22,   23,   21,   20,   11,   12,   17,   16,
   14,   15,   18,   24,    0,    0,   29,   28,   27,
};
short yydgoto[] = {                                       9,
   10,   11,   12,   13,   14,   36,   53,   15,   17,   31,
   43,
};
short yysindex[] = {                                   -222,
 -257, -257, -257, -257, -257, -257, -274, -271, -222,    0,
    0,    0,    0,    0,    0,    0, -202, -206, -253, -248,
 -253, -242,    0,    0,    0,    0, -240, -240, -240, -240,
 -253,    0,    0, -240, -199, -249, -254, -226, -253, -253,
    0,    0, -224, -220, -253, -253,    0, -240, -253,    0,
    0,    0,    0, -219, -215, -253, -253, -253,    0, -253,
 -184, -253,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -191, -253,    0,    0,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
   27,    0,    0,    0,    0,    0,    0,    0,   67,  -16,
  -17,
};
#define YYTABLESIZE 277
short yytable[] = {                                      16,
   26,   37,   38,   23,   40,   24,   26,   26,   51,   39,
   44,   45,   46,   52,   47,   41,   48,   50,   49,   42,
   58,   60,   61,   62,   54,   55,   56,   57,   65,   66,
   67,   59,   68,   63,   26,   25,    1,   64,   69,   71,
   72,   73,   70,   74,   76,   77,    2,    3,    4,    5,
    6,   32,    7,    8,   26,    0,   33,   34,   26,   79,
   42,   26,   27,   28,   29,   30,   78,   35,   18,   19,
   20,   21,   22,   75,    0,    0,   26,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   26,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   26,
   26,   26,   26,   26,    0,   26,   26,
};
short yycheck[] = {                                     257,
    0,   18,   19,  278,   21,  277,  261,  261,  258,  258,
   28,   29,   30,  263,   31,  258,   34,   35,   35,  260,
   37,   38,   39,   40,  279,  280,  281,  282,   45,   46,
   48,  258,   49,  258,  261,    9,  259,  258,  258,   56,
   57,   58,  258,   60,   61,   62,  269,  270,  271,  272,
  273,  258,  275,  276,  261,   -1,  263,  264,  261,   76,
  260,  261,  265,  266,  267,  268,  258,  274,    2,    3,
    4,    5,    6,  258,   -1,   -1,  261,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  259,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  269,
  270,  271,  272,  273,   -1,  275,  276,
};
#define YYFINAL 9
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 283
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"ID","INTEGER","LINE","LINE_REF",
"POINT_REF","CIRCLE_REF","VAR_REF","INTERSECT","EXTEND","SLIDE","PARALLEL",
"PERPENDICULAR","POINT","CIRCLE","ARC","ANGLE","VAR","BISECT","SVG_DIRECTIVE",
"INC_DIRECTIVE","FILENAME","SVG_FLAG","DIVIDE","MULTIPLY","ADD","SUBTRACT",
"LEXERR",
};
char *yyrule[] = {
"$accept : definitionList",
"definitionList : definition",
"definitionList : definitionList definition",
"definition : pointDefinition",
"definition : lineDefinition",
"definition : angleDefinition",
"definition : circleDefinition",
"definition : varDefinition",
"definition : SVG_DIRECTIVE SVG_FLAG",
"definition : INC_DIRECTIVE FILENAME",
"pointDefinition : POINT name xcoord ycoord",
"pointDefinition : POINT name INTERSECT lineRef lineRef",
"pointDefinition : POINT name BISECT pointRef pointRef",
"pointDefinition : POINT name BISECT lineRef",
"pointDefinition : POINT name pointRef ADD pointRef",
"pointDefinition : POINT name pointRef SUBTRACT pointRef",
"pointDefinition : POINT name pointRef MULTIPLY INTEGER",
"pointDefinition : POINT name pointRef DIVIDE INTEGER",
"pointDefinition : POINT name pointRef pointRef pointRef",
"lineDefinition : LINE name pointRef pointRef",
"lineDefinition : LINE name PERPENDICULAR lineRef pointRef",
"lineDefinition : LINE name PARALLEL lineRef pointRef",
"lineDefinition : LINE name EXTEND lineRef INTEGER",
"lineDefinition : LINE name SLIDE lineRef INTEGER",
"circleDefinition : CIRCLE name pointRef pointRef pointRef",
"circleDefinition : CIRCLE name pointRef INTEGER",
"circleDefinition : CIRCLE name pointRef pointRef",
"circleDefinition : ARC name INTEGER pointRef pointRef pointRef",
"circleDefinition : ARC name INTEGER pointRef INTEGER INTEGER",
"angleDefinition : ANGLE name pointRef pointRef pointRef",
"varDefinition : VAR name INTEGER",
"xcoord : INTEGER",
"xcoord : VAR_REF",
"ycoord : INTEGER",
"ycoord : VAR_REF",
"name : ID",
"pointRef : POINT_REF",
"lineRef : LINE_REF",
};
#endif
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH 500
#endif
#endif
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short yyss[YYSTACKSIZE];
YYSTYPE yyvs[YYSTACKSIZE];
#define yystacksize YYSTACKSIZE
/* user code */

void yyerror (char *s)
{
    fprintf (stderr, "line %d %s\n", yylineno, s);
    if (!gSchedule.getLastToken().empty())
        fprintf (stderr, "last token was >%s<\n", gSchedule.getLastToken().c_str());
}

#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse()
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register char *yys;

    if (yys = getenv("YYDEBUG"))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if (yyn = yydefred[yystate]) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yyss + yystacksize - 1)
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#ifdef lint
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#ifdef lint
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yyss + yystacksize - 1)
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 1:
{
        /* definitionList : definition */
        if (yyvsp[0].DefinitionPtr != 0)
        {
            VecCalcScheduleLine vl(*yyvsp[0].DefinitionPtr);
            gSchedule.push_back(vl);
            delete yyvsp[0].DefinitionPtr;
        }
    }
break;
case 2:
{
        /* definitionList : definition */
        if (yyvsp[0].DefinitionPtr != 0)
        {
            VecCalcScheduleLine vl(*yyvsp[0].DefinitionPtr);
            gSchedule.push_back(vl);
            delete yyvsp[0].DefinitionPtr;
        }
    }
break;
case 3:
{
        /* definition : pointDefinition */
        if (yyvsp[0].PointDefinitionPtr != 0)
        {
            yyval.DefinitionPtr = new Definition(*yyvsp[0].PointDefinitionPtr);
            delete yyvsp[0].PointDefinitionPtr;
        }
    }
break;
case 4:
{
        /* definition : lineDefinition */
        if (yyvsp[0].LineDefinitionPtr != 0)
        {
            yyval.DefinitionPtr = new Definition(*yyvsp[0].LineDefinitionPtr);
            delete yyvsp[0].LineDefinitionPtr;
        }
    }
break;
case 5:
{
        /* definition : angleDefinition */
        if (yyvsp[0].AngleDefinitionPtr != 0)
        {
            yyval.DefinitionPtr = new Definition(*yyvsp[0].AngleDefinitionPtr);
            delete yyvsp[0].AngleDefinitionPtr;
        }
    }
break;
case 6:
{
        /* definition : circleDefinition */
        if (yyvsp[0].CircleDefinitionPtr != 0)
        {
            yyval.DefinitionPtr = new Definition(*yyvsp[0].CircleDefinitionPtr);
            delete yyvsp[0].CircleDefinitionPtr;
        }
    }
break;
case 7:
{
        /* definition : varDefinition */
        if (yyvsp[0].VarDefinitionPtr != 0)
        {
            yyval.DefinitionPtr = new Definition(*yyvsp[0].VarDefinitionPtr);
            delete yyvsp[0].VarDefinitionPtr;
        }
    }
break;
case 8:
{
        /* definition : SVG_DIRECTIVE SVG_FLAG */
        if (yyvsp[0].NamePtr != 0)
        {
            yyval.DefinitionPtr = new Definition(DEFINITION_TYPE_SVGFLAG, *yyvsp[0].NamePtr);
            delete yyvsp[0].NamePtr;
        }
    }
break;
case 9:
{
        /* definition: INC_DIRECTIVE FILENAME */
        if (yyvsp[0].NamePtr != 0)
        {
            yyval.DefinitionPtr = new Definition(DEFINITION_TYPE_INCDIR, *yyvsp[0].NamePtr);
            delete yyvsp[0].NamePtr;
        }
    }
break;
case 10:
{
        /* pointDefinition : POINT name xcoord ycoord */
        if (yyvsp[-2].NamePtr != 0)
        {
            yyval.PointDefinitionPtr = new PointDefinition(*yyvsp[-2].NamePtr, yyvsp[-1].realNum, yyvsp[0].realNum);
            PosVector pv(yyvsp[-1].realNum, yyvsp[0].realNum);
            gSchedule.installPoint(*yyvsp[-2].NamePtr, pv);
            delete yyvsp[-2].NamePtr;
        }
    }
break;
case 11:
{
        /* pointDefinition : POINT name INTERSECT lineRef lineRef */
        if (yyvsp[-3].NamePtr != 0 && yyvsp[-1].LineRefPtr != 0 && yyvsp[0].LineRefPtr != 0)
        {
            if (!(gSchedule.isLineInTable(*yyvsp[-1].LineRefPtr) && gSchedule.isLineInTable(*yyvsp[0].LineRefPtr)))
            {
                fprintf(stderr, "line %d invalid lineRef\n", yylineno);
                fprintf(stderr, "either %s or %s or both\n", yyvsp[-1].LineRefPtr->c_str(), yyvsp[0].LineRefPtr->c_str());
                yynerrs++;
                return 1;
            }

            yyval.PointDefinitionPtr = new PointDefinition(*yyvsp[-3].NamePtr, *yyvsp[-1].LineRefPtr, *yyvsp[0].LineRefPtr);

            Line line1 = gSchedule.getLine(*yyvsp[-1].LineRefPtr);
            Line line2 = gSchedule.getLine(*yyvsp[0].LineRefPtr);
            PosVector pv = line1.intersect(line2);
            gSchedule.installPoint(*yyvsp[-3].NamePtr, pv);
            delete yyvsp[-3].NamePtr;
            delete yyvsp[-1].LineRefPtr;
            delete yyvsp[0].LineRefPtr;
        }
    }
break;
case 12:
{
        /* pointDefinition : POINT name BISECT pointRef pointRef */
        if (yyvsp[-3].NamePtr != 0 && yyvsp[-1].PointRefPtr != 0 && yyvsp[0].PointRefPtr != 0)
        {
            if (!(gSchedule.isPointInTable(*yyvsp[-1].PointRefPtr) && gSchedule.isPointInTable(*yyvsp[0].PointRefPtr)))
            {
                fprintf(stderr, "line %d invalid pointRef\n", yylineno);
                fprintf(stderr, "either %s or %s or both\n", yyvsp[-1].PointRefPtr->c_str(), yyvsp[0].PointRefPtr->c_str());
                yynerrs++;
                return 1;
            }

            yyval.PointDefinitionPtr = new PointDefinition(*yyvsp[-3].NamePtr, *yyvsp[-1].PointRefPtr, *yyvsp[0].PointRefPtr);

            PosVector pvFrom = gSchedule.getPoint(*yyvsp[-1].PointRefPtr);
            PosVector pvTo = gSchedule.getPoint(*yyvsp[0].PointRefPtr);
            PosVector pvBis = pvFrom.bisect(pvTo);
            gSchedule.installPoint(*yyvsp[-3].NamePtr, pvBis);

            delete yyvsp[-3].NamePtr;
            delete yyvsp[-1].PointRefPtr;
            delete yyvsp[0].PointRefPtr;
        }
    }
break;
case 13:
{
        /* pointDefinition : POINT lineRef */
        if (yyvsp[-2].NamePtr != 0 && yyvsp[0].LineRefPtr != 0)
        {
            if (!(gSchedule.isLineInTable(*yyvsp[0].LineRefPtr)))
            {
                fprintf(stderr, "line %d invalid lineRef ", yylineno);
                fprintf(stderr, "%s\n", yyvsp[0].LineRefPtr->c_str());
                yynerrs++;
                return 1;
            }

            yyval.PointDefinitionPtr = new PointDefinition(*yyvsp[-2].NamePtr, *yyvsp[0].LineRefPtr);

            Line li = gSchedule.getLine(*yyvsp[0].LineRefPtr);
            PosVector pv = li.bisect();
            gSchedule.installPoint(*yyvsp[-2].NamePtr, pv);

            delete yyvsp[-2].NamePtr;
            delete yyvsp[0].LineRefPtr;
        }
    }
break;
case 14:
{
        /* pointDefinition : POINT name pointRef ADD pointRef */
        if (yyvsp[-3].NamePtr != 0 && yyvsp[-2].PointRefPtr != 0 && yyvsp[0].PointRefPtr != 0)
        {
            if (!(gSchedule.isPointInTable(*yyvsp[-2].PointRefPtr) && gSchedule.isPointInTable(*yyvsp[0].PointRefPtr)))
            {
                fprintf(stderr, "line %d invalid pointRef ", yylineno);
                fprintf(stderr, "%s or %s or both\n", yyvsp[-2].PointRefPtr->c_str(), yyvsp[0].PointRefPtr->c_str());
                yynerrs++;
                return 1;
            }

            PosVector pv1 = gSchedule.getPoint(*yyvsp[-2].PointRefPtr);
            PosVector pv2 = gSchedule.getPoint(*yyvsp[0].PointRefPtr);
            PosVector pvSum = pv1 + pv2;
            gSchedule.installPoint(*yyvsp[-3].NamePtr, pvSum);

            yyval.PointDefinitionPtr = new PointDefinition(*yyvsp[-3].NamePtr, pvSum.x(), pvSum.y());

            delete yyvsp[-3].NamePtr;
            delete yyvsp[-2].PointRefPtr;
            delete yyvsp[0].PointRefPtr;
        }
    }
break;
case 15:
{
        /* pointDefinition : POINT name pointRef SUBTRACT pointRef */
        if (yyvsp[-3].NamePtr != 0 && yyvsp[-2].PointRefPtr != 0 && yyvsp[0].PointRefPtr != 0)
        {
            if (!(gSchedule.isPointInTable(*yyvsp[-2].PointRefPtr) && gSchedule.isPointInTable(*yyvsp[0].PointRefPtr)))
            {
                fprintf(stderr, "line %d invalid pointRef ", yylineno);
                fprintf(stderr, "%s or %s or both\n", yyvsp[-2].PointRefPtr->c_str(), yyvsp[0].PointRefPtr->c_str());
                yynerrs++;
                return 1;
            }

            PosVector pv1 = gSchedule.getPoint(*yyvsp[-2].PointRefPtr);
            PosVector pv2 = gSchedule.getPoint(*yyvsp[0].PointRefPtr);
            PosVector pvDiff = pv1 - pv2;
            gSchedule.installPoint(*yyvsp[-3].NamePtr, pvDiff);

            yyval.PointDefinitionPtr = new PointDefinition(*yyvsp[-3].NamePtr, pvDiff.x(), pvDiff.y());

            delete yyvsp[-3].NamePtr;
            delete yyvsp[-2].PointRefPtr;
            delete yyvsp[0].PointRefPtr;
        }
    }
break;
case 16:
{
        /* pointDefinition : POINT name pointRef MULTIPLY INTEGER */
        if (yyvsp[-3].NamePtr != 0 && yyvsp[-2].PointRefPtr != 0)
        {
            if (!(gSchedule.isPointInTable(*yyvsp[-2].PointRefPtr)))
            {
                fprintf(stderr, "line %d invalid pointRef ", yylineno);
                fprintf(stderr, "%s\n", yyvsp[-2].PointRefPtr->c_str());
                yynerrs++;
                return 1;
            }

            PosVector pv1 = gSchedule.getPoint(*yyvsp[-2].PointRefPtr);
            PosVector pvProd = pv1 * yyvsp[0].longInt;
            gSchedule.installPoint(*yyvsp[-3].NamePtr, pvProd);

            yyval.PointDefinitionPtr = new PointDefinition(*yyvsp[-3].NamePtr, pvProd.x(), pvProd.y());

            delete yyvsp[-3].NamePtr;
            delete yyvsp[-2].PointRefPtr;
        }
    }
break;
case 17:
{
        /* pointDefinition : POINT name pointRef DIVIDE INTEGER */
        if (yyvsp[-3].NamePtr != 0 && yyvsp[-2].PointRefPtr != 0)
        {
            if (!(gSchedule.isPointInTable(*yyvsp[-2].PointRefPtr)))
            {
                fprintf(stderr, "line %d invalid pointRef ", yylineno);
                fprintf(stderr, "%s\n", yyvsp[-2].PointRefPtr->c_str());
                yynerrs++;
                return 1;
            }

            PosVector pv1 = gSchedule.getPoint(*yyvsp[-2].PointRefPtr);
            PosVector pvDiv = pv1 / yyvsp[0].longInt;
            gSchedule.installPoint(*yyvsp[-3].NamePtr, pvDiv);

            yyval.PointDefinitionPtr = new PointDefinition(*yyvsp[-3].NamePtr, pvDiv.x(), pvDiv.y());

            delete yyvsp[-3].NamePtr;
            delete yyvsp[-2].PointRefPtr;
        }
    }
break;
case 18:
{
        /* pointDefinition : POINT name pointRef pointRef pointRef */
        if (yyvsp[-3].NamePtr != 0 && yyvsp[-2].PointRefPtr != 0 && yyvsp[-1].PointRefPtr != 0 && yyvsp[0].PointRefPtr != 0)
        {
            if (!(gSchedule.isPointInTable(*yyvsp[-2].PointRefPtr)
                  && gSchedule.isPointInTable(*yyvsp[-1].PointRefPtr)
                  && gSchedule.isPointInTable(*yyvsp[0].PointRefPtr)))
            {
                fprintf(stderr, "line %d invalid pointRef ", yylineno);
                fprintf(stderr, "either %s, %s or %s or any combination\n", yyvsp[-2].PointRefPtr->c_str(), yyvsp[-1].PointRefPtr->c_str(), yyvsp[0].PointRefPtr->c_str());
                yynerrs++;
                return 1;
            }

            /* compute circumcentre*/
            Circle c(gSchedule.getPoint(*yyvsp[-2].PointRefPtr), gSchedule.getPoint(*yyvsp[-1].PointRefPtr), gSchedule.getPoint(*yyvsp[0].PointRefPtr));

            PosVector pvCC = c.getCentre();

            gSchedule.installPoint(*yyvsp[-3].NamePtr, pvCC);

            yyval.PointDefinitionPtr = new PointDefinition(*yyvsp[-3].NamePtr, pvCC.x(), pvCC.y());

            delete yyvsp[-3].NamePtr;
            delete yyvsp[-2].PointRefPtr;
            delete yyvsp[-1].PointRefPtr;
            delete yyvsp[0].PointRefPtr;
        }
    }
break;
case 19:
{
        /* lineDefinition : LINE name pointRef pointRef */
        if (yyvsp[-2].NamePtr != 0 && yyvsp[-1].PointRefPtr != 0 && yyvsp[0].PointRefPtr != 0)
        {
            if (!(gSchedule.isPointInTable(*yyvsp[-1].PointRefPtr) && gSchedule.isPointInTable(*yyvsp[0].PointRefPtr)))
            {
                fprintf(stderr, "line %d invalid pointRef\n", yylineno);
                fprintf(stderr, "either %s or %s or both\n", yyvsp[-1].PointRefPtr->c_str(), yyvsp[0].PointRefPtr->c_str());
                yynerrs++;
                return 1;
            }

            yyval.LineDefinitionPtr = new LineDefinition(*yyvsp[-2].NamePtr, *yyvsp[-1].PointRefPtr, *yyvsp[0].PointRefPtr);

            PosVector pvFrom = gSchedule.getPoint(*yyvsp[-1].PointRefPtr);
            PosVector pvTo = gSchedule.getPoint(*yyvsp[0].PointRefPtr);
            Line li(pvFrom, pvTo);
            gSchedule.installLine(*yyvsp[-2].NamePtr, li);
            delete yyvsp[-2].NamePtr;
            delete yyvsp[-1].PointRefPtr;
            delete yyvsp[0].PointRefPtr;
        }
    }
break;
case 20:
{
        /* lineDefinition : LINE name PERPENDICULAR lineRef pointRef */
        if (yyvsp[-3].NamePtr != 0 && yyvsp[-1].LineRefPtr != 0 && yyvsp[0].PointRefPtr != 0)
        {
            if (!(gSchedule.isLineInTable(yyvsp[-1].LineRefPtr->c_str()) && gSchedule.isPointInTable(yyvsp[0].PointRefPtr->c_str())))
            {
                fprintf(stderr, "line %d invalid point/line ref\n", yylineno);
                fprintf(stderr, "either %s or %s or both\n", yyvsp[-1].LineRefPtr->c_str(), yyvsp[0].PointRefPtr->c_str());
                yynerrs++;
                return 1;
            }

            yyval.LineDefinitionPtr = new LineDefinition(LINEDEFINITION_TYPE_PERPENDICULAR, *yyvsp[-3].NamePtr, *yyvsp[-1].LineRefPtr, *yyvsp[0].PointRefPtr);

            Line li = gSchedule.getLine(*yyvsp[-1].LineRefPtr);
            PosVector pv = gSchedule.getPoint(*yyvsp[0].PointRefPtr);
            Line linePerp = li.perpendicular(pv);
            gSchedule.installLine(*yyvsp[-3].NamePtr, linePerp);

            delete yyvsp[-3].NamePtr;
            delete yyvsp[-1].LineRefPtr;
            delete yyvsp[0].PointRefPtr;
        }
    }
break;
case 21:
{
        /* lineDefinition : name PARALLEL lineRef pointRef */
        if (yyvsp[-3].NamePtr != 0 && yyvsp[-1].LineRefPtr != 0 && yyvsp[0].PointRefPtr != 0)
        {
            if (!(gSchedule.isLineInTable(yyvsp[-1].LineRefPtr->c_str()) && gSchedule.isPointInTable(yyvsp[0].PointRefPtr->c_str())))
            {
                fprintf(stderr, "line %d invalid point/line ref\n", yylineno);
                fprintf(stderr, "either %s or %s or both\n", yyvsp[-1].LineRefPtr->c_str(), yyvsp[0].PointRefPtr->c_str());
                yynerrs++;
                return 1;
            }

            yyval.LineDefinitionPtr = new LineDefinition(LINEDEFINITION_TYPE_PARALLEL, *yyvsp[-3].NamePtr, *yyvsp[-1].LineRefPtr, *yyvsp[0].PointRefPtr);

            Line li = gSchedule.getLine(*yyvsp[-1].LineRefPtr);
            PosVector pv = gSchedule.getPoint(*yyvsp[0].PointRefPtr);
            Line linePara = li.parallel(pv);
            gSchedule.installLine(*yyvsp[-3].NamePtr, linePara);

            delete yyvsp[-3].NamePtr;
            delete yyvsp[-1].LineRefPtr;
            delete yyvsp[0].PointRefPtr;
        }
    }
break;
case 22:
{
        /* LINE name EXTEND lineRef INTEGER */
        if (yyvsp[-3].NamePtr != 0 && yyvsp[-1].LineRefPtr != 0)
        {
            if (!(gSchedule.isLineInTable(*yyvsp[-1].LineRefPtr)))
            {
                fprintf(stderr, "line %d invalid lineRef ", yylineno);
                fprintf(stderr, "%s\n", yyvsp[-1].LineRefPtr->c_str());
                yynerrs++;
                return 1;
            }

            yyval.LineDefinitionPtr = new LineDefinition(*yyvsp[-3].NamePtr, *yyvsp[-1].LineRefPtr, yyvsp[0].longInt, LINEDEFINITION_TYPE_EXTEND);

            Line li = gSchedule.getLine(*yyvsp[-1].LineRefPtr);
            Line liExt = li.extend(yyvsp[0].longInt);
            gSchedule.installLine(*yyvsp[-3].NamePtr, liExt);

            delete yyvsp[-3].NamePtr;
            delete yyvsp[-1].LineRefPtr;
        }
    }
break;
case 23:
{
        /* LINE name SLIDE lineRef INTEGER */
        if (yyvsp[-3].NamePtr != 0 && yyvsp[-1].LineRefPtr != 0)
        {
            if (!(gSchedule.isLineInTable(*yyvsp[-1].LineRefPtr)))
            {
                fprintf(stderr, "line %d invalid lineRef ", yylineno);
                fprintf(stderr, "%s\n", yyvsp[-1].LineRefPtr->c_str());
                yynerrs++;
                return 1;
            }

            yyval.LineDefinitionPtr = new LineDefinition(*yyvsp[-3].NamePtr, *yyvsp[-1].LineRefPtr, yyvsp[0].longInt, LINEDEFINITION_TYPE_SLIDE);

            Line li = gSchedule.getLine(*yyvsp[-1].LineRefPtr);
            Line liSl = li.slide(yyvsp[0].longInt);
            gSchedule.installLine(*yyvsp[-3].NamePtr, liSl);

            delete yyvsp[-3].NamePtr;
            delete yyvsp[-1].LineRefPtr;
        }
    }
break;
case 24:
{
        /* circleDefinition : CIRCLE name pointRef pointRef pointRef */
        if (yyvsp[-3].NamePtr != 0 && yyvsp[-2].PointRefPtr != 0 && yyvsp[-1].PointRefPtr != 0 && yyvsp[0].PointRefPtr != 0)
        {
            if (!(gSchedule.isPointInTable(*yyvsp[-2].PointRefPtr) && gSchedule.isPointInTable(*yyvsp[-1].PointRefPtr) && gSchedule.isPointInTable(*yyvsp[0].PointRefPtr)))
            {
                fprintf(stderr, "line %d invalid pointRef\n", yylineno);
                fprintf(stderr, "either %s, %s or %s or any combination\n", yyvsp[-2].PointRefPtr->c_str(), yyvsp[-1].PointRefPtr->c_str(), yyvsp[0].PointRefPtr->c_str());
                yynerrs++;
                return 1;
            }

            yyval.CircleDefinitionPtr = new CircleDefinition(*yyvsp[-3].NamePtr, *yyvsp[-2].PointRefPtr, *yyvsp[-1].PointRefPtr, *yyvsp[0].PointRefPtr);

            Circle c(gSchedule.getPoint(*yyvsp[-2].PointRefPtr), gSchedule.getPoint(*yyvsp[-1].PointRefPtr), gSchedule.getPoint(*yyvsp[0].PointRefPtr));
            gSchedule.installCircle(*yyvsp[-3].NamePtr, c);
            delete yyvsp[-3].NamePtr;
            delete yyvsp[-2].PointRefPtr;
            delete yyvsp[-1].PointRefPtr;
            delete yyvsp[0].PointRefPtr;
        }
    }
break;
case 25:
{
        /* circleDefinition : CIRCLE name pointRef INTEGER */
        if (yyvsp[-2].NamePtr != 0 && yyvsp[-1].PointRefPtr != 0)
        {
            if (!(gSchedule.isPointInTable(*yyvsp[-1].PointRefPtr)))
            {
                fprintf(stderr, "line %d invalid pointRef ", yylineno);
                fprintf(stderr, "%s\n", yyvsp[-1].PointRefPtr->c_str());
                yynerrs++;
                return 1;
            }

            yyval.CircleDefinitionPtr = new CircleDefinition(*yyvsp[-2].NamePtr, *yyvsp[-1].PointRefPtr, yyvsp[0].longInt);

            Circle c(gSchedule.getPoint(*yyvsp[-1].PointRefPtr), yyvsp[0].longInt);
            gSchedule.installCircle(*yyvsp[-2].NamePtr, c);
            delete yyvsp[-2].NamePtr;
            delete yyvsp[-1].PointRefPtr;
        }
    }
break;
case 26:
{
        /* circleDefinition : CIRCLE name pointRef pointRef */
        if (yyvsp[-2].NamePtr != 0 && yyvsp[-1].PointRefPtr != 0 && yyvsp[-1].PointRefPtr != 0)
        {
            if (!(gSchedule.isPointInTable(*yyvsp[-1].PointRefPtr) && gSchedule.isPointInTable(*yyvsp[0].PointRefPtr)))
            {
                fprintf(stderr, "line %d invalid pointRef ", yylineno);
                fprintf(stderr, "%s or %s or both\n", yyvsp[-1].PointRefPtr->c_str(), yyvsp[0].PointRefPtr->c_str());
                yynerrs++;
                return 1;
            }

            yyval.CircleDefinitionPtr = new CircleDefinition(*yyvsp[-2].NamePtr, *yyvsp[-1].PointRefPtr, *yyvsp[0].PointRefPtr);

            Circle c(gSchedule.getPoint(*yyvsp[-1].PointRefPtr), gSchedule.getPoint(*yyvsp[0].PointRefPtr));
            gSchedule.installCircle(*yyvsp[-2].NamePtr, c);
            delete yyvsp[-2].NamePtr;
            delete yyvsp[-1].PointRefPtr;
        }
    }
break;
case 27:
{
        /* circleDefinition : ARC name INTEGER pointRef pointRef pointRef */
        if (yyvsp[-4].NamePtr != 0 && yyvsp[-2].PointRefPtr != 0 && yyvsp[-1].PointRefPtr != 0 && yyvsp[0].PointRefPtr != 0)
        {
            if (!(gSchedule.isPointInTable(*yyvsp[-2].PointRefPtr) && gSchedule.isPointInTable(*yyvsp[-1].PointRefPtr) && gSchedule.isPointInTable(*yyvsp[0].PointRefPtr)))
            {
                fprintf(stderr, "line %d invalid pointRef\n", yylineno);
                fprintf(stderr, "either %s, %s or %s or any combination\n", yyvsp[-2].PointRefPtr->c_str(), yyvsp[-1].PointRefPtr->c_str(), yyvsp[0].PointRefPtr->c_str());
                yynerrs++;
                return 1;
            }

            yyval.CircleDefinitionPtr = new CircleDefinition(*yyvsp[-4].NamePtr, yyvsp[-3].longInt, *yyvsp[-2].PointRefPtr, *yyvsp[-1].PointRefPtr, *yyvsp[0].PointRefPtr);

            Circle c(yyvsp[-3].longInt, gSchedule.getPoint(*yyvsp[-2].PointRefPtr), gSchedule.getPoint(*yyvsp[-1].PointRefPtr), gSchedule.getPoint(*yyvsp[0].PointRefPtr));
            gSchedule.installCircle(*yyvsp[-4].NamePtr, c);
            delete yyvsp[-4].NamePtr;
            delete yyvsp[-2].PointRefPtr;
            delete yyvsp[-1].PointRefPtr;
            delete yyvsp[0].PointRefPtr;
        }
    }
break;
case 28:
{
        /* circleDefinition : ARC name INTEGER pointRef INTEGER INTEGER */
        if (yyvsp[-4].NamePtr != 0 && yyvsp[-2].PointRefPtr != 0)
        {
            if (!(gSchedule.isPointInTable(*yyvsp[-2].PointRefPtr)))
            {
                fprintf(stderr, "line %d invalid pointRef ", yylineno);
                fprintf(stderr, "%s\n", yyvsp[-2].PointRefPtr->c_str());
                yynerrs++;
                return 1;
            }

            double startAngDeg = yyvsp[-1].longInt;
            double endAngDeg = yyvsp[0].longInt;
            double startAng = startAngDeg*(2*PI)/360;
            double endAng = endAngDeg*(2*PI)/360;
            yyval.CircleDefinitionPtr = new CircleDefinition(*yyvsp[-4].NamePtr, yyvsp[-3].longInt, *yyvsp[-2].PointRefPtr, startAng, endAng);

            Circle c(yyvsp[-3].longInt, gSchedule.getPoint(*yyvsp[-2].PointRefPtr), startAng, endAng);
            gSchedule.installCircle(*yyvsp[-4].NamePtr, c);
            delete yyvsp[-4].NamePtr;
            delete yyvsp[-2].PointRefPtr;
        }
    }
break;
case 29:
{
        /* angleDefinition : ANG name pointRef pointRef pointRef */
        if (yyvsp[-3].NamePtr != 0 && yyvsp[-2].PointRefPtr != 0 && yyvsp[-1].PointRefPtr != 0 && yyvsp[0].PointRefPtr != 0)
        {
            if (!(gSchedule.isPointInTable(*yyvsp[-2].PointRefPtr) && gSchedule.isPointInTable(*yyvsp[-1].PointRefPtr) && gSchedule.isPointInTable(*yyvsp[0].PointRefPtr)))
            {
                fprintf(stderr, "line %d invalid pointRef\n", yylineno);
                fprintf(stderr, "either %s, %s or %s or any combination\n", yyvsp[-2].PointRefPtr->c_str(), yyvsp[-1].PointRefPtr->c_str(), yyvsp[0].PointRefPtr->c_str());
                yynerrs++;
                return 1;
            }

            yyval.AngleDefinitionPtr = new AngleDefinition(*yyvsp[-3].NamePtr, *yyvsp[-2].PointRefPtr, *yyvsp[-1].PointRefPtr, *yyvsp[0].PointRefPtr);

            PointTriple ppp(gSchedule.getPoint(*yyvsp[-2].PointRefPtr), gSchedule.getPoint(*yyvsp[-1].PointRefPtr), gSchedule.getPoint(*yyvsp[0].PointRefPtr));
            gSchedule.installAngle(*yyvsp[-3].NamePtr, ppp);
            delete yyvsp[-3].NamePtr;
            delete yyvsp[-2].PointRefPtr;
            delete yyvsp[-1].PointRefPtr;
            delete yyvsp[0].PointRefPtr;
        }
    }
break;
case 30:
{
        /* varDefinition : VAR name INTEGER */
        if (yyvsp[-1].NamePtr != 0)
        {
            gSchedule.installVar(*yyvsp[-1].NamePtr, yyvsp[0].longInt);
            yyval.VarDefinitionPtr = new VarDefinition(*yyvsp[-1].NamePtr, yyvsp[0].longInt);

            delete yyvsp[-1].NamePtr;
        }
    }
break;
case 31:
{
        /* xcoord : INTEGER */
        yyval.realNum = yylval.longInt;
    }
break;
case 32:
{
        yyval.realNum = gSchedule.getVar(*yylval.VarRefPtr);
    }
break;
case 33:
{
        /* ycoord : INTEGER */
        yyval.realNum = yylval.longInt;
    }
break;
case 34:
{
        yyval.realNum = gSchedule.getVar(*yylval.VarRefPtr);
    }
break;
case 35:
{
        /* name : ID */
        yyval.NamePtr = yylval.NamePtr;
    }
break;
case 36:
{
        /* pointRef : ID */
        yyval.PointRefPtr = yylval.PointRefPtr;
    }
break;
case 37:
{
        /*lineRef :  ID */
        yyval.LineRefPtr = yylval.LineRefPtr;
    }
break;
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yyss + yystacksize - 1)
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
