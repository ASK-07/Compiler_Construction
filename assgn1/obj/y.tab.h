/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_OBJ_Y_TAB_H_INCLUDED
# define YY_YY_OBJ_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ID = 258,                      /* ID  */
    INTCONST = 259,                /* INTCONST  */
    CHARCONST = 260,               /* CHARCONST  */
    STRCONST = 261,                /* STRCONST  */
    ERROR = 262,                   /* ERROR  */
    ILLEGAL_TOK = 263,             /* ILLEGAL_TOK  */
    KWD_IF = 264,                  /* KWD_IF  */
    KWD_ELSE = 265,                /* KWD_ELSE  */
    KWD_WHILE = 266,               /* KWD_WHILE  */
    KWD_INT = 267,                 /* KWD_INT  */
    KWD_STRING = 268,              /* KWD_STRING  */
    KWD_CHAR = 269,                /* KWD_CHAR  */
    KWD_RETURN = 270,              /* KWD_RETURN  */
    KWD_VOID = 271,                /* KWD_VOID  */
    OPER_ADD = 272,                /* OPER_ADD  */
    OPER_SUB = 273,                /* OPER_SUB  */
    OPER_MUL = 274,                /* OPER_MUL  */
    OPER_DIV = 275,                /* OPER_DIV  */
    OPER_LT = 276,                 /* OPER_LT  */
    OPER_GT = 277,                 /* OPER_GT  */
    OPER_GTE = 278,                /* OPER_GTE  */
    OPER_LTE = 279,                /* OPER_LTE  */
    OPER_EQ = 280,                 /* OPER_EQ  */
    OPER_NEQ = 281,                /* OPER_NEQ  */
    OPER_ASGN = 282,               /* OPER_ASGN  */
    OPER_MOD = 283,                /* OPER_MOD  */
    OPER_INC = 284,                /* OPER_INC  */
    OPER_DEC = 285,                /* OPER_DEC  */
    OPER_AND = 286,                /* OPER_AND  */
    OPER_NOT = 287,                /* OPER_NOT  */
    OPER_AT = 288,                 /* OPER_AT  */
    OPER_OR = 289,                 /* OPER_OR  */
    LSQ_BRKT = 290,                /* LSQ_BRKT  */
    RSQ_BRKT = 291,                /* RSQ_BRKT  */
    LCRLY_BRKT = 292,              /* LCRLY_BRKT  */
    RCRLY_BRKT = 293,              /* RCRLY_BRKT  */
    LPAREN = 294,                  /* LPAREN  */
    RPAREN = 295,                  /* RPAREN  */
    COMMA = 296,                   /* COMMA  */
    SEMICLN = 297                  /* SEMICLN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 25 "src/parser.y"

    int value;
    struct treenode *node;
    char *strval;

#line 112 "obj/y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_OBJ_Y_TAB_H_INCLUDED  */
