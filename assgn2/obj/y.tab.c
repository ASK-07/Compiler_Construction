/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 2
#define YYMINOR 0
#define YYPATCH 20210109

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "src/parser.y"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<../src/tree.h>
#include<../src/strtab.h>
#include<../src/codegen.h>

extern FILE *outputFile;
extern int yylineno;

enum opType {ADD, SUB, MUL, DIV, LT, LTE, EQ, GTE, GT, NEQ};


char* scope = "";
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 19 "src/parser.y"
typedef union
{
    int value;
    struct treenode *node;
    char *strval;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 50 "obj/y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

#if !(defined(yylex) || defined(YYSTATE))
int YYLEX_DECL();
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define ID 257
#define INTCONST 258
#define CHARCONST 259
#define STRCONST 260
#define ERROR 261
#define ILLEGAL_TOK 262
#define KWD_IF 263
#define KWD_ELSE 264
#define KWD_WHILE 265
#define KWD_INT 266
#define KWD_STRING 267
#define KWD_CHAR 268
#define KWD_RETURN 269
#define KWD_VOID 270
#define OPER_ADD 271
#define OPER_SUB 272
#define OPER_MUL 273
#define OPER_DIV 274
#define OPER_LT 275
#define OPER_GT 276
#define OPER_GTE 277
#define OPER_LTE 278
#define OPER_EQ 279
#define OPER_NEQ 280
#define OPER_ASGN 281
#define OPER_MOD 282
#define OPER_INC 283
#define OPER_DEC 284
#define OPER_AND 285
#define OPER_NOT 286
#define OPER_AT 287
#define OPER_OR 288
#define LSQ_BRKT 289
#define RSQ_BRKT 290
#define LCRLY_BRKT 291
#define RCRLY_BRKT 292
#define LPAREN 293
#define RPAREN 294
#define COMMA 295
#define SEMICLN 296
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    2,    2,    3,    3,    4,    4,    4,
    5,    5,   27,    6,    6,    7,    7,    8,    9,    9,
   10,   10,   11,   11,   11,   11,   11,   12,   13,   13,
   14,   14,   15,   16,   16,   25,   25,   26,   26,   17,
   17,   17,   17,   17,   17,   18,   18,   18,   19,   19,
   20,   20,   20,   21,   21,   22,   22,   22,   22,   22,
   22,   23,   23,   24,   24,
};
static const YYINT yylen[] = {                            2,
    1,    1,    2,    1,    1,    6,    3,    1,    1,    1,
    5,    4,    2,    1,    3,    2,    4,    4,    0,    2,
    0,    2,    1,    1,    1,    1,    1,    3,    4,    1,
    5,    7,    5,    2,    3,    1,    3,    1,    4,    1,
    1,    1,    1,    1,    1,    1,    3,    2,    1,    1,
    1,    3,    2,    1,    1,    3,    1,    1,    1,    1,
    1,    4,    3,    1,    3,
};
static const YYINT yydefred[] = {                         0,
    8,    9,   10,    0,    0,    2,    4,    0,    5,    0,
    3,    0,    0,    0,    7,    0,    0,    0,    0,    0,
    0,   12,    0,    0,    0,    0,    0,    0,    0,    0,
   11,   15,    6,   20,    0,    0,   59,   60,   61,    0,
    0,    0,    0,    0,    0,    0,   23,   24,   25,   26,
   27,    0,    0,   51,   58,    0,    0,   17,    0,    0,
    0,    0,   34,    0,   57,    0,    0,   18,   22,   49,
   50,   48,    0,   54,   55,   53,    0,   41,   42,   43,
   40,   44,   45,    0,    0,    0,   63,    0,    0,    0,
    0,   35,   28,   56,    0,   52,    0,    0,   39,   62,
    0,    0,    0,   29,    0,    0,   33,    0,   32,
};
static const YYINT yydgoto[] = {                          4,
    5,    6,    7,    8,    9,   18,   19,   22,   29,   45,
   46,   47,   48,   49,   50,   51,   84,   52,   73,   53,
   77,   54,   55,   88,   56,   65,   10,
};
static const YYINT yysindex[] = {                      -255,
    0,    0,    0,    0, -255,    0,    0, -241,    0, -275,
    0, -287, -258, -228,    0, -256, -177, -208, -207, -191,
 -255,    0, -184, -256, -255, -188, -255, -144,   65, -149,
    0,    0,    0,    0, -287, -187,    0,    0,    0, -128,
 -126, -235,   65, -231, -114,   65,    0,    0,    0,    0,
    0, -168, -189,    0,    0,   60, -102,    0, -231, -253,
 -231, -231,    0, -133,    0, -112,  -58,    0,    0,    0,
    0,    0, -231,    0,    0,    0, -231,    0,    0,    0,
    0,    0,    0, -231, -231, -171,    0, -223,   60,  -19,
   22,    0,    0,    0, -189,    0, -168,  -94,    0,    0,
 -231,   65,   65,    0,   60,  -67,    0,   65,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,  198,    0,    0,    0,    0,    0,
    0, -275,    0,    0,    0,    0,    0,    0,  -91,    0,
   27,    0, -163,    0,    0,    0,   27,    0,  -88,    0,
    0,    0,    0,    0,    0, -226,    0,    0,    0,    0,
    0,    0,  -88,    0,    0,  -88,    0,    0,    0,    0,
    0,  -64, -142,    0,    0,   14, -182,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -155,    0,
    0,    0,    0,    0, -103,    0,  -25,    0,    0,    0,
    0,    0,    0,    0, -124,   52,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,  201,   36,   99,    0,  182,    0,  184,  183,   13,
   56,    0,    0,    0,    0,    0,    0,  -17,    0,  136,
    0,  146,    0,    0,  -41,  -29,    0,
};
#define YYTABLESIZE 358
static const YYINT yytable[] = {                         57,
   64,   14,   67,   36,   37,   38,   39,    1,   15,    2,
    1,    3,    2,   57,    3,   12,   57,   13,   89,   90,
   91,   36,   37,   38,   39,   36,   37,   38,   39,   20,
   38,   38,   38,   38,   21,   16,   38,   38,   38,   44,
   87,   86,   38,   98,   38,   38,   38,   38,   38,   38,
   38,   38,   38,   38,   38,   66,   27,   44,   69,  105,
   63,   44,   27,   38,   38,   38,   97,   38,   38,   38,
  100,  101,   57,   57,   57,   57,   57,   57,   57,   23,
   57,   57,   57,   74,   75,   24,   57,   25,   57,   57,
   57,   57,   57,   57,   57,   57,   57,   57,   26,   70,
   71,   59,   70,   71,   30,   60,   76,   33,   57,   57,
   57,   17,   35,   57,   46,   46,   46,   46,   99,   28,
   46,   46,   46,   17,   72,   28,   46,   72,   46,   46,
   16,   16,   46,   46,   46,   46,   46,   46,   64,   64,
   58,   78,   79,   80,   81,   82,   83,   46,   46,   46,
   46,   46,   46,   47,   47,   47,   47,  106,  107,   47,
   47,   47,   92,  109,   61,   47,   62,   47,   47,   65,
   65,   47,   47,   47,   47,   47,   47,   68,   85,   93,
   78,   79,   80,   81,   82,   83,   47,   47,   47,   47,
   47,   47,   36,   36,   36,   36,  108,    1,   36,   36,
   36,  104,   14,   21,   36,   11,   32,   31,   95,   34,
   36,   36,   36,   36,   36,   36,   78,   79,   80,   81,
   82,   83,   96,    0,    0,    0,   36,   36,   36,   36,
   36,   37,   37,   37,   37,   94,    0,   37,   37,   37,
    0,    0,    0,   37,    0,    0,    0,    0,    0,   37,
   37,   37,   37,   37,   37,   78,   79,   80,   81,   82,
   83,    0,    0,    0,    0,   37,   37,   37,   37,   37,
   30,   30,   30,   30,  102,    0,   30,   30,   30,    0,
    0,    0,   30,   19,   19,   19,   19,    0,    0,   19,
    0,   19,    0,    0,    0,   19,   78,   79,   80,   81,
   82,   83,    0,    0,   30,   30,   30,    0,   31,   31,
   31,   31,    0,    0,   31,  103,   31,   19,   19,   19,
   31,   36,   37,   38,   39,    0,    0,   40,    0,   41,
    0,    0,    0,   42,   78,   79,   80,   81,   82,   83,
    0,    0,   31,   31,   31,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   43,    0,   44,
};
static const YYINT yycheck[] = {                         29,
   42,  289,   44,  257,  258,  259,  260,  266,  296,  268,
  266,  270,  268,   43,  270,  257,   46,  293,   60,   61,
   62,  257,  258,  259,  260,  257,  258,  259,  260,  258,
  257,  258,  259,  260,  291,  294,  263,  264,  265,  293,
  294,   59,  269,   85,  271,  272,  273,  274,  275,  276,
  277,  278,  279,  280,  281,   43,   21,  293,   46,  101,
  296,  293,   27,  290,  291,  292,   84,  294,  295,  296,
  294,  295,  102,  103,  257,  258,  259,  260,  108,  257,
  263,  264,  265,  273,  274,  294,  269,  295,  271,  272,
  273,  274,  275,  276,  277,  278,  279,  280,  290,  271,
  272,  289,  271,  272,  289,  293,  296,  296,  291,  292,
  293,   13,  257,  296,  257,  258,  259,  260,  290,   21,
  263,  264,  265,   25,  296,   27,  269,  296,  271,  272,
  294,  295,  275,  276,  277,  278,  279,  280,  294,  295,
  290,  275,  276,  277,  278,  279,  280,  290,  291,  292,
  293,  294,  295,  257,  258,  259,  260,  102,  103,  263,
  264,  265,  296,  108,  293,  269,  293,  271,  272,  294,
  295,  275,  276,  277,  278,  279,  280,  292,  281,  292,
  275,  276,  277,  278,  279,  280,  290,  291,  292,  293,
  294,  295,  257,  258,  259,  260,  264,    0,  263,  264,
  265,  296,  294,  292,  269,    5,   25,   24,   73,   27,
  275,  276,  277,  278,  279,  280,  275,  276,  277,  278,
  279,  280,   77,   -1,   -1,   -1,  291,  292,  293,  294,
  295,  257,  258,  259,  260,  294,   -1,  263,  264,  265,
   -1,   -1,   -1,  269,   -1,   -1,   -1,   -1,   -1,  275,
  276,  277,  278,  279,  280,  275,  276,  277,  278,  279,
  280,   -1,   -1,   -1,   -1,  291,  292,  293,  294,  295,
  257,  258,  259,  260,  294,   -1,  263,  264,  265,   -1,
   -1,   -1,  269,  257,  258,  259,  260,   -1,   -1,  263,
   -1,  265,   -1,   -1,   -1,  269,  275,  276,  277,  278,
  279,  280,   -1,   -1,  291,  292,  293,   -1,  257,  258,
  259,  260,   -1,   -1,  263,  294,  265,  291,  292,  293,
  269,  257,  258,  259,  260,   -1,   -1,  263,   -1,  265,
   -1,   -1,   -1,  269,  275,  276,  277,  278,  279,  280,
   -1,   -1,  291,  292,  293,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  291,   -1,  293,
};
#define YYFINAL 4
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 296
#define YYUNDFTOKEN 326
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"ID","INTCONST","CHARCONST",
"STRCONST","ERROR","ILLEGAL_TOK","KWD_IF","KWD_ELSE","KWD_WHILE","KWD_INT",
"KWD_STRING","KWD_CHAR","KWD_RETURN","KWD_VOID","OPER_ADD","OPER_SUB",
"OPER_MUL","OPER_DIV","OPER_LT","OPER_GT","OPER_GTE","OPER_LTE","OPER_EQ",
"OPER_NEQ","OPER_ASGN","OPER_MOD","OPER_INC","OPER_DEC","OPER_AND","OPER_NOT",
"OPER_AT","OPER_OR","LSQ_BRKT","RSQ_BRKT","LCRLY_BRKT","RCRLY_BRKT","LPAREN",
"RPAREN","COMMA","SEMICLN",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : declList",
"declList : decl",
"declList : declList decl",
"decl : varDecl",
"decl : funDecl",
"varDecl : typeSpecifier ID LSQ_BRKT INTCONST RSQ_BRKT SEMICLN",
"varDecl : typeSpecifier ID SEMICLN",
"typeSpecifier : KWD_INT",
"typeSpecifier : KWD_CHAR",
"typeSpecifier : KWD_VOID",
"funDecl : funHeader LPAREN formalDeclList RPAREN funBody",
"funDecl : funHeader LPAREN RPAREN funBody",
"funHeader : typeSpecifier ID",
"formalDeclList : formalDecl",
"formalDeclList : formalDecl COMMA formalDeclList",
"formalDecl : typeSpecifier ID",
"formalDecl : typeSpecifier ID LSQ_BRKT RSQ_BRKT",
"funBody : LCRLY_BRKT localDeclList statementList RCRLY_BRKT",
"localDeclList :",
"localDeclList : varDecl localDeclList",
"statementList :",
"statementList : statement statementList",
"statement : compoundStmt",
"statement : assignStmt",
"statement : condStmt",
"statement : loopStmt",
"statement : returnStmt",
"compoundStmt : LCRLY_BRKT statementList RCRLY_BRKT",
"assignStmt : var OPER_ASGN expression SEMICLN",
"assignStmt : expression",
"condStmt : KWD_IF LPAREN expression RPAREN statement",
"condStmt : KWD_IF LPAREN expression RPAREN statement KWD_ELSE statement",
"loopStmt : KWD_WHILE LPAREN expression RPAREN statement",
"returnStmt : KWD_RETURN SEMICLN",
"returnStmt : KWD_RETURN expression SEMICLN",
"expression : addExpr",
"expression : expression relop addExpr",
"var : ID",
"var : ID LSQ_BRKT addExpr RSQ_BRKT",
"relop : OPER_LTE",
"relop : OPER_LT",
"relop : OPER_GT",
"relop : OPER_GTE",
"relop : OPER_EQ",
"relop : OPER_NEQ",
"addExpr : term",
"addExpr : addExpr addop term",
"addExpr : addExpr SEMICLN",
"addop : OPER_ADD",
"addop : OPER_SUB",
"term : factor",
"term : term mulop factor",
"term : term SEMICLN",
"mulop : OPER_MUL",
"mulop : OPER_DIV",
"factor : LPAREN expression RPAREN",
"factor : var",
"factor : funcCallExpr",
"factor : INTCONST",
"factor : CHARCONST",
"factor : STRCONST",
"funcCallExpr : ID LPAREN argList RPAREN",
"funcCallExpr : ID LPAREN RPAREN",
"argList : expression",
"argList : argList COMMA expression",

};
#endif

#if YYDEBUG
int      yydebug;
#endif

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;
int      yynerrs;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 691 "src/parser.y"

int yywarning(char * msg){
    printf("warning: line %d: %s\n", yylineno, msg);
    return 0;
}

int yyerror(char * msg){
    printf("error: line %d: %s\n", yylineno, msg);
    return 0;
}
#line 415 "obj/y.tab.c"

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yym = 0;
    yyn = 0;
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        yychar = YYLEX;
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);

    switch (yyn)
    {
case 1:
#line 88 "src/parser.y"
	{
                    /* create tree */
                    tree* progNode = maketree(PROGRAM);
                    /* add child for node: declList */
                    addChild(progNode, yystack.l_mark[0].node);
                    /* assign tree to output variable: ast (root) */
                    ast = progNode;
		    generate_code(progNode, outputFile);
                }
break;
case 2:
#line 100 "src/parser.y"
	{
                    /* create tree */
                    tree* declListNode = maketree(DECLLIST);
                    /* add child for node: decl */
                    addChild(declListNode, yystack.l_mark[0].node);
                    /* assign as new child in output tree created in root: ast */
                    yyval.node = declListNode;
                }
break;
case 3:
#line 109 "src/parser.y"
	{
                    /* create tree */
                    tree* declListNode = maketree(DECLLIST);
                    /* add child for node: declList */
                    addChild(declListNode, yystack.l_mark[-1].node);
                    /* add child for node: decl */
                    addChild(declListNode, yystack.l_mark[0].node);
                    /* assign as new child in output tree created in root: ast */
                    yyval.node = declListNode;
                }
break;
case 4:
#line 122 "src/parser.y"
	{
                    /* create tree */
                    tree* varDeclNode = maketree(DECL);
                    /* add child for node: varDecl */
                    addChild(varDeclNode, yystack.l_mark[0].node);
                    /* assign as new child in output tree created in root: ast */
                    yyval.node = varDeclNode;
                }
break;
case 5:
#line 131 "src/parser.y"
	{
                    /* create tree */
                    tree* funDeclNode = maketree(DECL);
                    /* add child for node: funDecl */
                    addChild(funDeclNode, yystack.l_mark[0].node);
                    /* assign as new child in output tree created in root: ast */
                    yyval.node = funDeclNode;
                }
break;
case 6:
#line 142 "src/parser.y"
	{
                    /* create tree */
                    tree *declNode = maketree(VARDECL);
                    /* add child for node: typeSpecifier */
                    addChild(declNode, maketreeWithVal(TYPESPEC, yystack.l_mark[-5].node));
                    /* Lookup index */
                    /*int index = ST_insert($2, scope, $1->val, VAR);*/
                    /* add child for node as a tree with value: ID */
                    addChild(declNode, maketreeWithVal(IDENTIFIER, yystack.l_mark[-4].strval));
                    /* add child for node as a tree with value: INTCONST */
                    addChild(declNode, maketreeWithVal(INTEGER, yystack.l_mark[-2].value));
                    /* assign as new child in output tree created in root: ast */
                    yyval.node = declNode;
                }
break;
case 7:
#line 157 "src/parser.y"
	{
                    /* create tree */
                    tree *declNode = maketree(VARDECL);
                    /* add child for node: typeSpecifier */
                    addChild(declNode, maketreeWithVal(TYPESPEC, yystack.l_mark[-2].node));
                    /* Lookup index */
                    /*int index = ST_insert($2, scope, $1->val, IDENTIFIER);*/
                    /* add child for node as a tree with value: ID */
                    addChild(declNode, maketreeWithVal(IDENTIFIER, yystack.l_mark[-1].strval));
                    /* assign as new child in output tree created in root: ast */
                    yyval.node = declNode;
                }
break;
case 8:
#line 172 "src/parser.y"
	{
                    /* create tree with value: Integer */
                    /* assign as new child in output tree created in root: ast */
		            yyval.node = maketreeWithVal(TYPESPEC, INT_TYPE);
		        }
break;
case 9:
#line 178 "src/parser.y"
	{
                    /* create tree with value: Character */
                    /* assign as new child in output tree created in root: ast */
		            yyval.node = maketreeWithVal(TYPESPEC, CHAR_TYPE);
		        }
break;
case 10:
#line 184 "src/parser.y"
	{
                    /* create tree with value: Character */
                    /* assign as new child in output tree created in root: ast */
                    yyval.node = maketreeWithVal(TYPESPEC, VOID_TYPE);
		        }
break;
case 11:
#line 192 "src/parser.y"
	{
		            tree* funDeclNode = maketree (FUNDECL);
                    if (yystack.l_mark[-2].node != NULL) {
                        addChild(funDeclNode, yystack.l_mark[-2].node);
                    }
                    if (yystack.l_mark[0].node != NULL)  {
                        addChild(funDeclNode, yystack.l_mark[0].node);
                    }
                    /* assign as new child in output tree created in root: ast */
                    yyval.node = funDeclNode;
                }
break;
case 12:
#line 204 "src/parser.y"
	{
                    tree* funDeclNode = maketree (FUNDECL);
                    /* add child for node: funBody */
                    if (yystack.l_mark[0].node != NULL) {
                    addChild(funDeclNode, yystack.l_mark[0].node);
                }
                    /* assign as new child in output tree created in root: ast */
                    yyval.node = funDeclNode;
                }
break;
case 13:
#line 215 "src/parser.y"
	{
                    /* create tree */
                    tree *funHeadNode = maketree(FUNHEAD);
                    /* add child for node: typeSpecifier */
                    addChild(funHeadNode, yystack.l_mark[-1].node);
                    int index = ST_insert(yystack.l_mark[0].strval, scope, yystack.l_mark[-1].node->val, FUNCTION);
                    addChild(funHeadNode, maketreeWithVal(IDENTIFIER, index));
                    yyval.node = funHeadNode;
                }
break;
case 14:
#line 226 "src/parser.y"
	{
                    /* create tree */
                    tree* formalDeclListNode = maketree(FORMALDECLLIST);
                    /* add child for node: formalDecl */
                    if (yystack.l_mark[0].node != NULL) {
			            addChild(formalDeclListNode, yystack.l_mark[0].node);
		            }
                    /* assign as new child in output tree created in root: ast */
                    yyval.node = formalDeclListNode;
                }
break;
case 15:
#line 237 "src/parser.y"
	{
                    /* create tree */
                    tree* formalDeclListNode = maketree(FORMALDECLLIST);
                    /* add child for node: formalDecl */
                    if (yystack.l_mark[-2].node != NULL) {
                        addChild(formalDeclListNode, yystack.l_mark[-2].node);
                    }
                    /* add child for node: formalDeclList */
                    if (yystack.l_mark[0].node != NULL) {
                    addChild(formalDeclListNode, yystack.l_mark[0].node);
                    }
		            /* assign as new child in output tree created in root: ast */
                    yyval.node = formalDeclListNode;
                }
break;
case 16:
#line 254 "src/parser.y"
	{
                    /* create tree */
                    tree *formalDeclNode = maketree(FORMALDECL);
                    /* add child for node: typeSpecifier */
                    addChild(formalDeclNode, yystack.l_mark[-1].node); 
                    /* Lookup index */
                    ST_insert(yystack.l_mark[0].strval, scope, yystack.l_mark[-1].node->val, SCALAR); 
                    /* add child for node as a tree with value: ID */
                    addChild(formalDeclNode, maketreeWithVal(IDENTIFIER, index)); 
                    /* assign as new child in output tree created in root: ast */
                    yyval.node = formalDeclNode;
                }
break;
case 17:
#line 267 "src/parser.y"
	{
                    /* create tree */
                    tree *formalDeclNode = maketree(FORMALDECL);
                    /* add child for node: typeSpecifier */
                    addChild(formalDeclNode, yystack.l_mark[-3].node); 
                    /* Lookup index */
                    ST_insert(yystack.l_mark[-2].strval, scope, yystack.l_mark[-3].node->val, ARRAY);
                    /* add child for node as a tree with value: ID */
                    addChild(formalDeclNode, maketreeWithVal(IDENTIFIER, index)); 
                    /* add child for node: Array (Wasn't sure if i do this.. Otherwise these were the same though.)  */
                    addChild(formalDeclNode, maketreeWithVal(ARRAYDECL, VOID_TYPE));
                    /* assign as new child in output tree created in root: ast */
                    yyval.node = formalDeclNode;
                }
break;
case 18:
#line 284 "src/parser.y"
	{
                    /* create tree */
                    tree *funBodyNode = maketree(FUNBODY);
                    /* add child for node: localDeclList */
                    if (yystack.l_mark[-2].node != NULL) {
                        addChild(funBodyNode, yystack.l_mark[-2].node);
                    } 
                    /* add child for node: statementList */
                    if (yystack.l_mark[-1].node != NULL) {
                        addChild(funBodyNode, yystack.l_mark[-1].node);
                    } 
                    /* assign as new child in output tree created in root: ast */
                    yyval.node = funBodyNode;
                }
break;
case 19:
#line 301 "src/parser.y"
	{
                    yyval.node = NULL;
                }
break;
case 20:
#line 305 "src/parser.y"
	{
                    /* create tree */
                    tree *localDeclListNode = maketree(LOCALDECLLIST);
                    /* add child for node: varDecl */
                    addChild(localDeclListNode, yystack.l_mark[-1].node);
                    /* add child for node: localDeclList */ 
                    if (yystack.l_mark[0].node != NULL) {
                        addChild(localDeclListNode, yystack.l_mark[0].node);
                    }
                    /* assign as new child in output tree created in root: ast */
                    yyval.node = localDeclListNode;
                }
break;
case 21:
#line 320 "src/parser.y"
	{
                    yyval.node = NULL;
                }
break;
case 22:
#line 324 "src/parser.y"
	{
                    /* create tree */
                    tree *statementListNode = maketree(STATEMENTLIST);
                    /* add child for node: statement */
                    addChild(statementListNode, yystack.l_mark[-1].node);
                    /* add child for node: statementList */
                    if (yystack.l_mark[0].node != NULL) {  
                        addChild(statementListNode, yystack.l_mark[0].node);
                        }
                    /* assign as new child in output tree created in root: ast */
                    yyval.node = statementListNode;
                }
break;
case 23:
#line 339 "src/parser.y"
	{
                tree* statementNode = maketree(STATEMENT);
                addChild(statementNode, yystack.l_mark[0].node);
                yyval.node = statementNode;
                }
break;
case 24:
#line 345 "src/parser.y"
	{
                tree* statementNode = maketree(STATEMENT);
                addChild(statementNode, yystack.l_mark[0].node);
                yyval.node = statementNode;
                }
break;
case 25:
#line 351 "src/parser.y"
	{
                tree* statementNode = maketree(STATEMENT);
                addChild(statementNode, yystack.l_mark[0].node);
                yyval.node = statementNode;
                }
break;
case 26:
#line 357 "src/parser.y"
	{
                tree* statementNode = maketree(STATEMENT);
                addChild(statementNode, yystack.l_mark[0].node);
                yyval.node = statementNode;
                }
break;
case 27:
#line 363 "src/parser.y"
	{
                tree* statementNode = maketree(STATEMENT);
                addChild(statementNode, yystack.l_mark[0].node);
                yyval.node = statementNode;
                }
break;
case 28:
#line 371 "src/parser.y"
	{
                    tree* compoundStmtNode = maketree(COMPOUNDSTMT);
                    addChild(compoundStmtNode, maketreeWithVal(STATEMENTLIST, yystack.l_mark[-2].value));
                    yyval.node = compoundStmtNode;
                }
break;
case 29:
#line 378 "src/parser.y"
	{
                    /* create tree */
                    tree *assignNode = maketree(ASSIGNSTMT);
                    /* add child for node: var */
                    addChild(assignNode, yystack.l_mark[-3].node);
                    /* add child for node: expression */
                    addChild(assignNode, yystack.l_mark[-1].node);
                    yyval.node = assignNode;
		    generate_assignment(assignNode, outputFile);
	            }
break;
case 30:
#line 389 "src/parser.y"
	{
                    tree* assignNode = maketree(ASSIGNSTMT);
                    addChild(assignNode, yystack.l_mark[0].node);
                    yyval.node = assignNode;
		    generate_assignment(assignNode, outputFile);
                }
break;
case 31:
#line 398 "src/parser.y"
	{
                    /* create tree */
                    tree *condNode = maketree(CONDSTMT);
                    /* add child for node: expression */
                    addChild(condNode, yystack.l_mark[-2].node); 
                    /* add child for node: statement */
                    addChild(condNode, yystack.l_mark[0].node); 
                    /* assign as new child in output tree created in root: ast */
                    yyval.node = condNode;
		    generate_conditional(condNode, outputFile);
                }
break;
case 32:
#line 410 "src/parser.y"
	{
                    /* create tree */
                    tree *condNode = maketree(CONDSTMT);
                    /* add child for node: expression */
                    addChild(condNode, yystack.l_mark[-4].node); 
                    /* add child for node: statement */
                    addChild(condNode, yystack.l_mark[-2].node); 
                    /* add child for node: statement */
                    addChild(condNode, yystack.l_mark[0].node); 
                    /* assign as new child in output tree created in root: ast */
                    yyval.node = condNode; 
		    generate_conditional(condNode, outputFile);
                }
break;
case 33:
#line 426 "src/parser.y"
	{ 
                    /* create tree */
                    tree *loopNode = maketree(LOOPSTMT);
                    /* add child for node: expression */
                    addChild(loopNode, yystack.l_mark[-2].node); 
                    /* add child for node: statement */
                    addChild(loopNode, yystack.l_mark[0].node);
                    /* assign as new child in output tree created in root: ast */
                    yyval.node = loopNode; 
                }
break;
case 34:
#line 439 "src/parser.y"
	{
                    /* create tree */
                    tree *returnNode = maketree(RETURNSTMT);
                    /* assign as new child in output tree created in root: ast */
                    yyval.node = returnNode; 
                }
break;
case 35:
#line 446 "src/parser.y"
	{
                    /* create tree */
                    tree *returnNode = maketree(RETURNSTMT);
                    /* add child for node: expression */
                    addChild(returnNode, yystack.l_mark[-1].node);
                    /* assign as new child in output tree created in root: ast */
                    yyval.node = returnNode;
                }
break;
case 36:
#line 456 "src/parser.y"
	{
                    tree* expressionNode = maketree(EXPRESSION);
                    addChild(expressionNode, yystack.l_mark[0].node);
                    yyval.node = expressionNode;
		    generate_expression(expressionNode, outputFile);
                }
break;
case 37:
#line 463 "src/parser.y"
	{
                    /* create tree */
                    tree *exprNode = maketree(EXPRESSION);
                    /* add child for node: expression */
                    addChild(exprNode, yystack.l_mark[-2].node);  
                    /* add child for node: relop */
                    addChild(exprNode, yystack.l_mark[-1].node);  
                    /* add child for node: addExpr */
                    addChild(exprNode, yystack.l_mark[0].node);  
                    /* assign as new child in output tree created in root: ast */
                    yyval.node = exprNode;
		    generate_expression(exprNode, outputFile);
                }
break;
case 38:
#line 479 "src/parser.y"
	{
                    /* create tree */
                    tree *varNode = maketree(VAR);
                    /* Lookup index */
                    int index = ST_lookup(yystack.l_mark[0].strval, scope); 
                    /* add child for node as a tree with value: ID */
                    addChild(varNode, maketreeWithVal(IDENTIFIER, index));
                    /* assign as new child in output tree created in root: ast */
                    yyval.node = varNode;
                }
break;
case 39:
#line 490 "src/parser.y"
	{
                    /* create tree */
                    tree *varNode = maketree(VAR);
                    /* Lookup index */
                    int index = ST_lookup(yystack.l_mark[-3].strval, scope); 
                    /* add child for node as a tree with value: ID */
                    addChild(varNode, maketreeWithVal(IDENTIFIER, index));
                    addChild(varNode, yystack.l_mark[-1].node);
                    /* assign as new child in output tree created in root: ast */
		            yyval.node = varNode;
                }
break;
case 40:
#line 504 "src/parser.y"
	{
                    yyval.node = maketreeWithVal(RELOP, OPER_LTE);
                }
break;
case 41:
#line 508 "src/parser.y"
	{
                    yyval.node = maketreeWithVal(RELOP, OPER_LT);
                }
break;
case 42:
#line 512 "src/parser.y"
	{
                    yyval.node = maketreeWithVal(RELOP, OPER_GT);
                }
break;
case 43:
#line 516 "src/parser.y"
	{
                    yyval.node = maketreeWithVal(RELOP, OPER_GTE);
                }
break;
case 44:
#line 520 "src/parser.y"
	{
                    yyval.node = maketreeWithVal(RELOP, OPER_EQ);
                }
break;
case 45:
#line 524 "src/parser.y"
	{
                    yyval.node = maketreeWithVal(RELOP, OPER_NEQ);
                }
break;
case 46:
#line 530 "src/parser.y"
	{
                    tree* addExprNode = maketree(ADDEXPR);
                    addChild(addExprNode, yystack.l_mark[0].node);
                    yyval.node = addExprNode;
                }
break;
case 47:
#line 536 "src/parser.y"
	{
                    /* create tree */
                    tree *addExprNode = maketree(ADDEXPR);
                    /* add child for node: addExpr */
                    addChild(addExprNode, yystack.l_mark[-2].node); 
                    /* add child for node: addop */
                    addChild(addExprNode, yystack.l_mark[-1].node); 
                    /* add child for node: term */
                    addChild(addExprNode, yystack.l_mark[0].node); 
                    /* assign as new child in output tree created in root: ast */
                    yyval.node = addExprNode;
                }
break;
case 48:
#line 549 "src/parser.y"
	{
                    tree* addExprNode = maketree(ADDEXPR);
                    addChild(addExprNode, yystack.l_mark[-1].node);
                    yyval.node = addExprNode;
                }
break;
case 49:
#line 557 "src/parser.y"
	{
                    yyval.node = maketreeWithVal(ADDOP, OPER_ADD);
                }
break;
case 50:
#line 561 "src/parser.y"
	{
                    yyval.node = maketreeWithVal(ADDOP, OPER_SUB);
                }
break;
case 51:
#line 567 "src/parser.y"
	{
                    tree* termNode = maketree(TERM);
                    addChild(termNode, yystack.l_mark[0].node);
                    yyval.node = termNode;
                }
break;
case 52:
#line 573 "src/parser.y"
	{
                    /* create tree */
                    tree* termNode = maketree(TERM);
                    /* add child for node: term */
                    addChild(termNode, yystack.l_mark[-2].node); 
                    /* add child for node: mulop */
                    addChild(termNode, yystack.l_mark[-1].node); 
                    /* add child for node: factor */
                    addChild(termNode, yystack.l_mark[0].node); 
                    /* assign as new child in output tree created in root: ast */
                    yyval.node = termNode;
                }
break;
case 53:
#line 586 "src/parser.y"
	{
                    tree* termNode = maketree(TERM);
                    addChild(termNode, yystack.l_mark[-1].node);
                    yyval.node = termNode;
                }
break;
case 54:
#line 595 "src/parser.y"
	{
                    yyval.node = maketreeWithVal(MULOP, OPER_MUL);
                }
break;
case 55:
#line 599 "src/parser.y"
	{
                    yyval.node = maketreeWithVal(MULOP, OPER_DIV);
                }
break;
case 56:
#line 605 "src/parser.y"
	{
                    tree* factorNode = maketree(FACTOR);
                    addChild(factorNode, maketreeWithVal(EXPRESSION, yystack.l_mark[-2].value));
                    yyval.node = factorNode;
                }
break;
case 57:
#line 611 "src/parser.y"
	{
                    tree* factorNode = maketree(FACTOR);
                    addChild(factorNode, maketreeWithVal(VAR, yystack.l_mark[0].node));
                    yyval.node = factorNode;
                }
break;
case 58:
#line 617 "src/parser.y"
	{
                    tree* factorNode = maketree(FACTOR);
                    addChild(factorNode, maketreeWithVal(FUNCCALLEXPR, yystack.l_mark[0].node));
                    yyval.node = factorNode;
                }
break;
case 59:
#line 623 "src/parser.y"
	{
                    tree* factorNode = maketree(FACTOR);
                    addChild(factorNode, maketreeWithVal(INTEGER, yystack.l_mark[0].value));
                    yyval.node = factorNode;
                }
break;
case 60:
#line 629 "src/parser.y"
	{
                    tree* factorNode = maketree(FACTOR);
                    addChild(factorNode, maketreeWithVal(CHAR, yystack.l_mark[0].strval));
                    yyval.node = factorNode;
                }
break;
case 61:
#line 635 "src/parser.y"
	{
                    /*tree* strConstNode = maketree(FACTOR);*/
                    /*addChild(varNode, maketreeWithVal(CHAR, $1));*/
                    /*$$ = varNode;*/
                    tree* factorNode = maketree(FACTOR);
                }
break;
case 62:
#line 644 "src/parser.y"
	{
                    /* create tree */
                    tree *funcCallNode = maketree(FUNCCALLEXPR);
                    /* Lookup index */
                    int index = ST_lookup(yystack.l_mark[-3].strval, scope); 
                    /* add child for node as a tree with value: ID */
                    addChild(funcCallNode, maketreeWithVal(IDENTIFIER, index)); 
                    /* add child for node: argList */
                    addChild(funcCallNode, yystack.l_mark[-1].node); 
                    /* assign as new child in output tree created in root: ast */
                    yyval.node = funcCallNode;
		    generate_function_call(funcCallNode, outputFile);
                }
break;
case 63:
#line 658 "src/parser.y"
	{
                    /* create tree */
                    tree *funcCallNode = maketree(FUNCCALLEXPR);
                    /* Lookup index */
                    int index = ST_lookup(yystack.l_mark[-2].strval, scope); 
                    /* add child for node as a tree with value: ID */
                    addChild(funcCallNode, maketreeWithVal(IDENTIFIER, index)); 
                    /* assign as new child in output tree created in root: ast */
                    yyval.node = funcCallNode; 
		    generate_function_call(funcCallNode, outputFile);
                }
break;
case 64:
#line 672 "src/parser.y"
	{
                    tree* expressionNode = maketree(ARGLIST);
                    addChild(expressionNode, maketreeWithVal(EXPRESSION, yystack.l_mark[0].node));
                    yyval.node = expressionNode;
                }
break;
case 65:
#line 678 "src/parser.y"
	{
                    /* create tree */
                    tree *argListNode = maketree(ARGLIST);
                    /* add child for node: argList */
                    addChild(argListNode, yystack.l_mark[-2].node); 
                    /* add child for node: expression */
                    addChild(argListNode, yystack.l_mark[0].node); 
                    /* assign as new child in output tree created in root: ast */
                    yyval.node = argListNode;
                }
break;
#line 1294 "obj/y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            yychar = YYLEX;
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
