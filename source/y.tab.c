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
#include "DefinitionList.h"
#include "Definition.h"
#include "PointDefinition.h"
#include "LineDefinition.h"
#include "Name.h"
#include "PointRef.h"
#include "LineRef.h"
#pragma warning( disable : 4786 )
#pragma warning( disable : 4996 )


#include <stdio.h>
#include <stdlib.h>
#include "yaccFns.h"
#include "vecCalcGlobals.h"

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
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    0,    1,    1,    1,    2,    2,    2,    2,    3,
    3,    3,    3,    3,    3,    4,    5,    6,    7,    8,
};
short yylen[] = {                                         2,
    1,    2,    1,    1,    2,    4,    5,    5,    4,    4,
    5,    5,    5,    5,    1,    1,    1,    1,    1,    1,
};
short yydefred[] = {                                      0,
   15,    0,    0,    0,    0,    1,    3,    4,   18,    0,
    0,    5,    2,   19,    0,    0,    0,    0,    0,   16,
    0,    0,    0,   20,    0,    0,    0,    0,   10,    0,
    0,    9,   17,    6,   13,   14,   12,   11,    7,    8,
};
short yydgoto[] = {                                       5,
    6,    7,    8,   23,   34,   10,   19,   25,
};
short yysindex[] = {                                   -252,
    0, -254, -254, -262, -252,    0,    0,    0,    0, -236,
 -242,    0,    0,    0, -251, -251, -251, -251, -240,    0,
 -251, -249, -235,    0, -234, -227, -240, -240,    0, -251,
 -240,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
   27,    0,    0,    0,    0,   30,   -9,  -16,
};
#define YYTABLESIZE 33
short yytable[] = {                                      26,
   27,   28,    9,    1,   30,   32,    2,   12,   24,   29,
   24,   14,   31,   39,    3,   20,    4,   37,   38,   21,
   14,   40,   33,   35,   14,   22,   15,   16,   17,   18,
   36,   13,   11,
};
short yycheck[] = {                                      16,
   17,   18,  257,  256,   21,   22,  259,  270,  260,   19,
  260,  261,   22,   30,  267,  258,  269,   27,   28,  262,
  261,   31,  258,  258,  261,  268,  263,  264,  265,  266,
  258,    5,    3,
};
#define YYFINAL 5
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 271
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"ID","INTEGER","LINE","LINE_REF",
"POINT_REF","INTERSECT","EXTEND","SLIDE","PARALLEL","PERPENDICULAR","POINT",
"BISECT","SVG_DIRECTIVE","SVG_FLAG","LEXERR",
};
char *yyrule[] = {
"$accept : definitionList",
"definitionList : definition",
"definitionList : definitionList definition",
"definition : pointDefinition",
"definition : lineDefinition",
"definition : SVG_DIRECTIVE SVG_FLAG",
"pointDefinition : POINT name xcoord ycoord",
"pointDefinition : POINT name INTERSECT lineRef lineRef",
"pointDefinition : POINT name BISECT pointRef pointRef",
"pointDefinition : POINT name BISECT lineRef",
"lineDefinition : LINE name pointRef pointRef",
"lineDefinition : LINE name PERPENDICULAR lineRef pointRef",
"lineDefinition : LINE name PARALLEL lineRef pointRef",
"lineDefinition : LINE name EXTEND lineRef INTEGER",
"lineDefinition : LINE name SLIDE lineRef INTEGER",
"lineDefinition : error",
"xcoord : INTEGER",
"ycoord : INTEGER",
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
            gResult.push_back(*yyvsp[0].DefinitionPtr);
            delete yyvsp[0].DefinitionPtr;
        }
    }
break;
case 2:
{
        /* definitionList : definition */
        if (yyvsp[0].DefinitionPtr != 0)
        {
            gResult.push_back(*yyvsp[0].DefinitionPtr);
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
        /* definition : SVG_DIRECTIVE SVG_FLAG */
        if (yyvsp[0].NamePtr != 0)
        {
            yyval.DefinitionPtr = new Definition(*yyvsp[0].NamePtr);
            delete yyvsp[0].NamePtr;
        }
    }
break;
case 6:
{
        /* pointDefinition : POINT name xcoord ycoord */
        if (yyvsp[-2].NamePtr != 0)
        {
            yyval.PointDefinitionPtr = new PointDefinition(*yyvsp[-2].NamePtr, yyvsp[-1].longInt, yyvsp[0].longInt);
            delete yyvsp[-2].NamePtr;
        }
    }
break;
case 7:
{
        /* pointDefinition : POINT name INTERSECT lineRef lineRef */
        if (yyvsp[-3].NamePtr != 0 && yyvsp[-1].LineRefPtr != 0 && yyvsp[0].LineRefPtr != 0)
        {
            if (!(gResult.isLine(yyvsp[-1].LineRefPtr->c_str()) && gResult.isLine(yyvsp[0].LineRefPtr->c_str())))
            {
                fprintf(stderr, "line %d invalid lineRef\n", yylineno);
                fprintf(stderr, "either %s or %s or both\n", yyvsp[-1].LineRefPtr->c_str(), yyvsp[0].LineRefPtr->c_str());
                yynerrs++;
                return 1;
            }

            yyval.PointDefinitionPtr = new PointDefinition(*yyvsp[-3].NamePtr, *yyvsp[-1].LineRefPtr, *yyvsp[0].LineRefPtr);
            delete yyvsp[-3].NamePtr;
            delete yyvsp[-1].LineRefPtr;
            delete yyvsp[0].LineRefPtr;
        }
    }
break;
case 8:
{
        /* pointDefinition : POINT name BISECT pointRef pointRef */
        if (yyvsp[-3].NamePtr != 0 && yyvsp[-1].PointRefPtr != 0 && yyvsp[0].PointRefPtr != 0)
        {
            if (!(gResult.isPoint(yyvsp[-1].PointRefPtr->c_str())) && gResult.isPoint(yyvsp[0].PointRefPtr->c_str()))
            {
                fprintf(stderr, "line %d invalid pointRef\n", yylineno);
                fprintf(stderr, "either %s or %s or both\n", yyvsp[-1].PointRefPtr->c_str(), yyvsp[0].PointRefPtr->c_str());
                yynerrs++;
                return 1;
            }

            yyval.PointDefinitionPtr = new PointDefinition(*yyvsp[-3].NamePtr, *yyvsp[-1].PointRefPtr, *yyvsp[0].PointRefPtr);
            delete yyvsp[-3].NamePtr;
            delete yyvsp[-1].PointRefPtr;
            delete yyvsp[0].PointRefPtr;
        }
    }
break;
case 9:
{
        /* pointDefinition : POINT lineRef */
        if (yyvsp[-2].NamePtr != 0 && yyvsp[0].LineRefPtr != 0)
        {
            if (!(gResult.isLine(yyvsp[0].LineRefPtr->c_str())))
            {
                fprintf(stderr, "line %d invalid lineRef ", yylineno);
                fprintf(stderr, "%s\n", yyvsp[0].LineRefPtr->c_str());
                yynerrs++;
                return 1;
            }

            yyval.PointDefinitionPtr = new PointDefinition(*yyvsp[-2].NamePtr, *yyvsp[0].LineRefPtr);
            delete yyvsp[-2].NamePtr;
            delete yyvsp[0].LineRefPtr;
        }
    }
break;
case 10:
{
        /* lineDefinition : LINE name pointRef pointRef */
        if (yyvsp[-2].NamePtr != 0 && yyvsp[-1].PointRefPtr != 0 && yyvsp[0].PointRefPtr != 0)
        {
            if (!(gResult.isPoint(yyvsp[-1].PointRefPtr->c_str()) && gResult.isPoint(yyvsp[0].PointRefPtr->c_str())))
            {
                fprintf(stderr, "line %d invalid pointRef\n", yylineno);
                fprintf(stderr, "either %s or %s or both\n", yyvsp[-1].PointRefPtr->c_str(), yyvsp[0].PointRefPtr->c_str());
                yynerrs++;
                return 1;
            }

            yyval.LineDefinitionPtr = new LineDefinition(*yyvsp[-2].NamePtr, *yyvsp[-1].PointRefPtr, *yyvsp[0].PointRefPtr);
            delete yyvsp[-2].NamePtr;
            delete yyvsp[-1].PointRefPtr;
            delete yyvsp[0].PointRefPtr;
        }
    }
break;
case 11:
{
        /* lineDefinition : LINE name PERPENDICULAR lineRef pointRef */
        if (yyvsp[-3].NamePtr != 0 && yyvsp[-1].LineRefPtr != 0 && yyvsp[0].PointRefPtr != 0)
        {
            if (!(gResult.isLine(yyvsp[-1].LineRefPtr->c_str()) && gResult.isPoint(yyvsp[0].PointRefPtr->c_str())))
            {
                fprintf(stderr, "line %d invalid point/line ref\n", yylineno);
                fprintf(stderr, "either %s or %s or both\n", yyvsp[-1].LineRefPtr->c_str(), yyvsp[0].PointRefPtr->c_str());
                yynerrs++;
                return 1;
            }

            yyval.LineDefinitionPtr = new LineDefinition(LINEDEFINITION_TYPE_PERPENDICULAR, *yyvsp[-3].NamePtr, *yyvsp[-1].LineRefPtr, *yyvsp[0].PointRefPtr);
            delete yyvsp[-3].NamePtr;
            delete yyvsp[-1].LineRefPtr;
            delete yyvsp[0].PointRefPtr;
        }
    }
break;
case 12:
{
        /* lineDefinition : name PARALLEL lineRef pointRef */
        if (yyvsp[-3].NamePtr != 0 && yyvsp[-1].LineRefPtr != 0 && yyvsp[0].PointRefPtr != 0)
        {
            if (!(gResult.isLine(yyvsp[-1].LineRefPtr->c_str()) && gResult.isPoint(yyvsp[0].PointRefPtr->c_str())))
            {
                fprintf(stderr, "line %d invalid point/line ref\n", yylineno);
                fprintf(stderr, "either %s or %s or both\n", yyvsp[-1].LineRefPtr->c_str(), yyvsp[0].PointRefPtr->c_str());
                yynerrs++;
                return 1;
            }

            yyval.LineDefinitionPtr = new LineDefinition(LINEDEFINITION_TYPE_PARALLEL, *yyvsp[-3].NamePtr, *yyvsp[-1].LineRefPtr, *yyvsp[0].PointRefPtr);
            delete yyvsp[-3].NamePtr;
            delete yyvsp[-1].LineRefPtr;
            delete yyvsp[0].PointRefPtr;
        }
    }
break;
case 13:
{
        /* LINE name EXTEND lineRef INTEGER */
        if (yyvsp[-3].NamePtr != 0 && yyvsp[-1].LineRefPtr != 0)
        {
            if (!(gResult.isLine(yyvsp[-1].LineRefPtr->c_str())))
            {
                fprintf(stderr, "line %d invalid lineRef ", yylineno);
                fprintf(stderr, "%s\n", yyvsp[-1].LineRefPtr->c_str());
                yynerrs++;
                return 1;
            }

            yyval.LineDefinitionPtr = new LineDefinition(*yyvsp[-3].NamePtr, *yyvsp[-1].LineRefPtr, yyvsp[0].longInt, LINEDEFINITION_TYPE_EXTEND);
            delete yyvsp[-3].NamePtr;
            delete yyvsp[-1].LineRefPtr;
        }
    }
break;
case 14:
{
        /* LINE name SLIDE lineRef INTEGER */
        if (yyvsp[-3].NamePtr != 0 && yyvsp[-1].LineRefPtr != 0)
        {
            if (!(gResult.isLine(yyvsp[-1].LineRefPtr->c_str())))
            {
                fprintf(stderr, "line %d invalid lineRef ", yylineno);
                fprintf(stderr, "%s\n", yyvsp[-1].LineRefPtr->c_str());
                yynerrs++;
                return 1;
            }

            yyval.LineDefinitionPtr = new LineDefinition(*yyvsp[-3].NamePtr, *yyvsp[-1].LineRefPtr, yyvsp[0].longInt, LINEDEFINITION_TYPE_SLIDE);
            delete yyvsp[-3].NamePtr;
            delete yyvsp[-1].LineRefPtr;
        }
    }
break;
case 15:
{
        fprintf(stderr,
                "incomplete line definition?\nbad #svg directive?\n"  
                "possibly given LINE name lineRef EXTEND/SLIDE INTEGER a pointRef?\n");
        yynerrs++;
        return 1;
    }
break;
case 16:
{
        /* xcoord : INTEGER */
        yyval.longInt = yylval.longInt;
    }
break;
case 17:
{
        /* ycoord : INTEGER */
        yyval.longInt = yylval.longInt;
    }
break;
case 18:
{
        /* name : ID */
        yyval.NamePtr = yylval.NamePtr;
    }
break;
case 19:
{
        /* pointRef : ID */
        yyval.PointRefPtr = yylval.PointRefPtr;
    }
break;
case 20:
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
