/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/parser.y"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<../src/tree.h>
#include<../src/strtab.h>

extern int yylineno;
extern table_node* current_scope;

enum opType {ADD, SUB, MUL, DIV, LT, LTE, EQ, GTE, GT, NEQ};

int functionIndex;
int parameterCount;
char* scope = "";

#line 88 "obj/y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "y.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_INTCONST = 4,                   /* INTCONST  */
  YYSYMBOL_CHARCONST = 5,                  /* CHARCONST  */
  YYSYMBOL_STRCONST = 6,                   /* STRCONST  */
  YYSYMBOL_ERROR = 7,                      /* ERROR  */
  YYSYMBOL_ILLEGAL_TOK = 8,                /* ILLEGAL_TOK  */
  YYSYMBOL_KWD_IF = 9,                     /* KWD_IF  */
  YYSYMBOL_KWD_ELSE = 10,                  /* KWD_ELSE  */
  YYSYMBOL_KWD_WHILE = 11,                 /* KWD_WHILE  */
  YYSYMBOL_KWD_INT = 12,                   /* KWD_INT  */
  YYSYMBOL_KWD_STRING = 13,                /* KWD_STRING  */
  YYSYMBOL_KWD_CHAR = 14,                  /* KWD_CHAR  */
  YYSYMBOL_KWD_RETURN = 15,                /* KWD_RETURN  */
  YYSYMBOL_KWD_VOID = 16,                  /* KWD_VOID  */
  YYSYMBOL_OPER_ADD = 17,                  /* OPER_ADD  */
  YYSYMBOL_OPER_SUB = 18,                  /* OPER_SUB  */
  YYSYMBOL_OPER_MUL = 19,                  /* OPER_MUL  */
  YYSYMBOL_OPER_DIV = 20,                  /* OPER_DIV  */
  YYSYMBOL_OPER_LT = 21,                   /* OPER_LT  */
  YYSYMBOL_OPER_GT = 22,                   /* OPER_GT  */
  YYSYMBOL_OPER_GTE = 23,                  /* OPER_GTE  */
  YYSYMBOL_OPER_LTE = 24,                  /* OPER_LTE  */
  YYSYMBOL_OPER_EQ = 25,                   /* OPER_EQ  */
  YYSYMBOL_OPER_NEQ = 26,                  /* OPER_NEQ  */
  YYSYMBOL_OPER_ASGN = 27,                 /* OPER_ASGN  */
  YYSYMBOL_OPER_MOD = 28,                  /* OPER_MOD  */
  YYSYMBOL_OPER_INC = 29,                  /* OPER_INC  */
  YYSYMBOL_OPER_DEC = 30,                  /* OPER_DEC  */
  YYSYMBOL_OPER_AND = 31,                  /* OPER_AND  */
  YYSYMBOL_OPER_NOT = 32,                  /* OPER_NOT  */
  YYSYMBOL_OPER_AT = 33,                   /* OPER_AT  */
  YYSYMBOL_OPER_OR = 34,                   /* OPER_OR  */
  YYSYMBOL_LSQ_BRKT = 35,                  /* LSQ_BRKT  */
  YYSYMBOL_RSQ_BRKT = 36,                  /* RSQ_BRKT  */
  YYSYMBOL_LCRLY_BRKT = 37,                /* LCRLY_BRKT  */
  YYSYMBOL_RCRLY_BRKT = 38,                /* RCRLY_BRKT  */
  YYSYMBOL_LPAREN = 39,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 40,                    /* RPAREN  */
  YYSYMBOL_COMMA = 41,                     /* COMMA  */
  YYSYMBOL_SEMICLN = 42,                   /* SEMICLN  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_program = 44,                   /* program  */
  YYSYMBOL_declList = 45,                  /* declList  */
  YYSYMBOL_decl = 46,                      /* decl  */
  YYSYMBOL_varDecl = 47,                   /* varDecl  */
  YYSYMBOL_typeSpecifier = 48,             /* typeSpecifier  */
  YYSYMBOL_funDecl = 49,                   /* funDecl  */
  YYSYMBOL_funHeader = 50,                 /* funHeader  */
  YYSYMBOL_formalDeclList = 51,            /* formalDeclList  */
  YYSYMBOL_formalDecl = 52,                /* formalDecl  */
  YYSYMBOL_funBody = 53,                   /* funBody  */
  YYSYMBOL_localDeclList = 54,             /* localDeclList  */
  YYSYMBOL_statementList = 55,             /* statementList  */
  YYSYMBOL_statement = 56,                 /* statement  */
  YYSYMBOL_compoundStmt = 57,              /* compoundStmt  */
  YYSYMBOL_assignStmt = 58,                /* assignStmt  */
  YYSYMBOL_condStmt = 59,                  /* condStmt  */
  YYSYMBOL_loopStmt = 60,                  /* loopStmt  */
  YYSYMBOL_returnStmt = 61,                /* returnStmt  */
  YYSYMBOL_expression = 62,                /* expression  */
  YYSYMBOL_var = 63,                       /* var  */
  YYSYMBOL_relop = 64,                     /* relop  */
  YYSYMBOL_addExpr = 65,                   /* addExpr  */
  YYSYMBOL_addop = 66,                     /* addop  */
  YYSYMBOL_term = 67,                      /* term  */
  YYSYMBOL_mulop = 68,                     /* mulop  */
  YYSYMBOL_factor = 69,                    /* factor  */
  YYSYMBOL_funcCallExpr = 70,              /* funcCallExpr  */
  YYSYMBOL_argList = 71                    /* argList  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   140

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  111

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    87,    87,    98,   107,   120,   129,   140,   166,   188,
     194,   200,   208,   221,   232,   251,   263,   281,   301,   324,
     344,   347,   363,   366,   381,   387,   393,   399,   405,   413,
     422,   432,   440,   451,   466,   479,   486,   496,   502,   517,
     535,   557,   561,   565,   569,   573,   577,   583,   589,   602,
     610,   614,   620,   626,   639,   648,   652,   658,   664,   670,
     676,   682,   688,   697,   722,   741,   747
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "INTCONST",
  "CHARCONST", "STRCONST", "ERROR", "ILLEGAL_TOK", "KWD_IF", "KWD_ELSE",
  "KWD_WHILE", "KWD_INT", "KWD_STRING", "KWD_CHAR", "KWD_RETURN",
  "KWD_VOID", "OPER_ADD", "OPER_SUB", "OPER_MUL", "OPER_DIV", "OPER_LT",
  "OPER_GT", "OPER_GTE", "OPER_LTE", "OPER_EQ", "OPER_NEQ", "OPER_ASGN",
  "OPER_MOD", "OPER_INC", "OPER_DEC", "OPER_AND", "OPER_NOT", "OPER_AT",
  "OPER_OR", "LSQ_BRKT", "RSQ_BRKT", "LCRLY_BRKT", "RCRLY_BRKT", "LPAREN",
  "RPAREN", "COMMA", "SEMICLN", "$accept", "program", "declList", "decl",
  "varDecl", "typeSpecifier", "funDecl", "funHeader", "formalDeclList",
  "formalDecl", "funBody", "localDeclList", "statementList", "statement",
  "compoundStmt", "assignStmt", "condStmt", "loopStmt", "returnStmt",
  "expression", "var", "relop", "addExpr", "addop", "term", "mulop",
  "factor", "funcCallExpr", "argList", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-51)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      64,   -51,   -51,   -51,     2,    64,   -51,   -51,    13,   -51,
     -21,   -51,   -51,    -9,    15,    31,   -51,    24,    59,    12,
      42,    48,    64,   -51,    70,    24,    64,    65,    64,   106,
      19,    74,   -51,   -51,   -51,   -51,    -9,    46,   -51,   -51,
     -51,    67,    75,     1,    19,    43,    73,    19,   -51,   -51,
     -51,   -51,   -51,   111,    86,    -5,    22,   -51,   -51,   -51,
      43,     5,    43,    43,   -51,    44,   -51,    77,    72,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,   -51,    43,    43,   -51,
     -51,   -51,    43,   -51,   -51,   -51,    43,    21,   -51,   111,
      10,    78,    98,   -51,   -51,   -51,    -5,    66,    22,   -51,
     -51,   -51,    43,    19,    19,   -51,   111,   116,   -51,    19,
     -51
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,    10,    11,     0,     2,     3,     5,     0,     6,
       0,     1,     4,    14,     0,     0,     8,     0,     0,     0,
      15,     0,    20,    13,    17,     0,     0,     0,    20,     0,
      22,     0,    12,    16,     7,    21,     0,    39,    60,    61,
      62,     0,     0,     0,    22,     0,     0,    22,    24,    25,
      26,    27,    28,    31,    58,    37,    47,    52,    59,    18,
       0,     0,     0,     0,    35,     0,    58,     0,     0,    19,
      23,    42,    43,    44,    41,    45,    46,     0,     0,    50,
      51,    49,     0,    55,    56,    54,     0,     0,    64,    65,
       0,     0,     0,    36,    29,    57,    38,     0,    48,    53,
      40,    63,     0,     0,     0,    30,    66,    32,    34,     0,
      33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -51,   -51,   -51,   122,    49,   103,   -51,   -51,    90,   -51,
     105,   100,    28,   -50,   -51,   -51,   -51,   -51,   -51,   -42,
     -30,   -51,   -45,   -51,    57,   -51,    54,   -51,   -51
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,     9,    10,    19,    20,
      23,    30,    46,    47,    48,    49,    50,    51,    52,    53,
      66,    77,    55,    82,    56,    86,    57,    58,    90
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      54,    65,    11,    68,    37,    38,    39,    40,    37,    38,
      39,    40,    79,    80,    54,    87,    13,    54,    14,    89,
      91,    92,    37,    38,    39,    40,    15,     1,    41,     2,
      42,     3,    96,    16,    43,    21,    97,    81,    79,    80,
      45,    83,    84,    64,    45,    88,    37,    38,    39,    40,
     101,   102,    25,   107,   108,    17,    44,   100,    45,   110,
     106,    22,    24,    81,    85,    71,    72,    73,    74,    75,
      76,    28,    67,    54,    54,    70,     1,    28,     2,    54,
       3,    60,    45,    26,    27,    61,    93,    71,    72,    73,
      74,    75,    76,    71,    72,    73,    74,    75,    76,    71,
      72,    73,    74,    75,    76,    31,    62,    34,   105,    36,
      59,    69,    95,    78,    63,    94,    33,    18,   103,    71,
      72,    73,    74,    75,    76,    29,   109,    12,    35,    18,
      32,    29,    71,    72,    73,    74,    75,    76,   104,    98,
      99
};

static const yytype_int8 yycheck[] =
{
      30,    43,     0,    45,     3,     4,     5,     6,     3,     4,
       5,     6,    17,    18,    44,    60,     3,    47,    39,    61,
      62,    63,     3,     4,     5,     6,    35,    12,     9,    14,
      11,    16,    77,    42,    15,     4,    78,    42,    17,    18,
      39,    19,    20,    42,    39,    40,     3,     4,     5,     6,
      40,    41,    40,   103,   104,    40,    37,    36,    39,   109,
     102,    37,     3,    42,    42,    21,    22,    23,    24,    25,
      26,    22,    44,   103,   104,    47,    12,    28,    14,   109,
      16,    35,    39,    41,    36,    39,    42,    21,    22,    23,
      24,    25,    26,    21,    22,    23,    24,    25,    26,    21,
      22,    23,    24,    25,    26,    35,    39,    42,    42,     3,
      36,    38,    40,    27,    39,    38,    26,    14,    40,    21,
      22,    23,    24,    25,    26,    22,    10,     5,    28,    26,
      25,    28,    21,    22,    23,    24,    25,    26,    40,    82,
      86
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    12,    14,    16,    44,    45,    46,    47,    48,    49,
      50,     0,    46,     3,    39,    35,    42,    40,    48,    51,
      52,     4,    37,    53,     3,    40,    41,    36,    47,    48,
      54,    35,    53,    51,    42,    54,     3,     3,     4,     5,
       6,     9,    11,    15,    37,    39,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    65,    67,    69,    70,    36,
      35,    39,    39,    39,    42,    62,    63,    55,    62,    38,
      55,    21,    22,    23,    24,    25,    26,    64,    27,    17,
      18,    42,    66,    19,    20,    42,    68,    65,    40,    62,
      71,    62,    62,    42,    38,    40,    65,    62,    67,    69,
      36,    40,    41,    40,    40,    42,    62,    56,    56,    10,
      56
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    47,    47,    48,
      48,    48,    49,    49,    50,    51,    51,    52,    52,    53,
      54,    54,    55,    55,    56,    56,    56,    56,    56,    57,
      58,    58,    59,    59,    60,    61,    61,    62,    62,    63,
      63,    64,    64,    64,    64,    64,    64,    65,    65,    65,
      66,    66,    67,    67,    67,    68,    68,    69,    69,    69,
      69,    69,    69,    70,    70,    71,    71
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     6,     3,     1,
       1,     1,     5,     4,     2,     1,     3,     2,     4,     4,
       0,     2,     0,     2,     1,     1,     1,     1,     1,     3,
       4,     1,     5,     7,     5,     2,     3,     1,     3,     1,
       4,     1,     1,     1,     1,     1,     1,     1,     3,     2,
       1,     1,     1,     3,     2,     1,     1,     3,     1,     1,
       1,     1,     1,     4,     3,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: declList  */
#line 88 "src/parser.y"
                {
                    /* create tree */
                    tree* progNode = maketree(PROGRAM);
                    /* add child for node: declList */
                    addChild(progNode, (yyvsp[0].node));
                    /* assign tree to output variable: ast (root) */
                    ast = progNode;
                }
#line 1237 "obj/y.tab.c"
    break;

  case 3: /* declList: decl  */
#line 99 "src/parser.y"
                {
                    /* create tree */
                    tree* declListNode = maketree(DECLLIST);
                    /* add child for node: decl */
                    addChild(declListNode, (yyvsp[0].node));
                    /* assign as new child in output tree created in root: ast */
                    (yyval.node) = declListNode;
                }
#line 1250 "obj/y.tab.c"
    break;

  case 4: /* declList: declList decl  */
#line 108 "src/parser.y"
                {
                    /* create tree */
                    tree* declListNode = maketree(DECLLIST);
                    /* add child for node: declList */
                    addChild(declListNode, (yyvsp[-1].node));
                    /* add child for node: decl */
                    addChild(declListNode, (yyvsp[0].node));
                    /* assign as new child in output tree created in root: ast */
                    (yyval.node) = declListNode;
                }
#line 1265 "obj/y.tab.c"
    break;

  case 5: /* decl: varDecl  */
#line 121 "src/parser.y"
                {
                    /* create tree */
                    tree* varDeclNode = maketree(DECL);
                    /* add child for node: varDecl */
                    addChild(varDeclNode, (yyvsp[0].node));
                    /* assign as new child in output tree created in root: ast */
                    (yyval.node) = varDeclNode;
                }
#line 1278 "obj/y.tab.c"
    break;

  case 6: /* decl: funDecl  */
#line 130 "src/parser.y"
                {
                    /* create tree */
                    tree* funDeclNode = maketree(DECL);
                    /* add child for node: funDecl */
                    addChild(funDeclNode, (yyvsp[0].node));
                    /* assign as new child in output tree created in root: ast */
                    (yyval.node) = funDeclNode;
                }
#line 1291 "obj/y.tab.c"
    break;

  case 7: /* varDecl: typeSpecifier ID LSQ_BRKT INTCONST RSQ_BRKT SEMICLN  */
#line 141 "src/parser.y"
                {
                    /* Create tree */
                    tree *declNode = maketree(VARDECL);
                    /* Add child for node: typeSpecifier */
                    addChild(declNode, maketreeWithVal(TYPESPEC, (yyvsp[-5].node)));
                    
                    /* Check for out-of-bounds array size (non-positive integer) */
                    if ((yyvsp[-2].value) <= 0) {
                        printf("Error: Array %s declared with non-positive size %d at line %d.\n", (yyvsp[-4].strval), (yyvsp[-2].value), yylineno);
                    }

                    /* Lookup index and check for a multiple declaration */
                    if (ST_lookup((yyvsp[-4].strval)) != NULL) {
                        printf("Error: Multiple declarations of variable %s at line %d.\n", (yyvsp[-4].strval), yylineno);
                    } else {
                        /* If no multiple is found, insert new array into symbol table */
                        ST_insert((yyvsp[-4].strval), (yyvsp[-5].node), ARRAY, &(current_scope));
                    }

                    /* Add child for node as a tree with value: ID */
                    addChild(declNode, maketreeWithVal(IDENTIFIER, (yyvsp[-4].strval)));
                    /* Add child for node as a tree with value: INTCONST */
                    addChild(declNode, maketreeWithVal(INTEGER, (yyvsp[-2].value)));
                    (yyval.node) = declNode;
                }
#line 1321 "obj/y.tab.c"
    break;

  case 8: /* varDecl: typeSpecifier ID SEMICLN  */
#line 167 "src/parser.y"
                {
                    /* create tree */
                    tree *declNode = maketree(VARDECL);
                    /* add child for node: typeSpecifier */
                    addChild(declNode, maketreeWithVal(TYPESPEC, (yyvsp[-2].node)));

                    /* Lookup index and check for a multiple declaration */
                    if (ST_lookup((yyvsp[-1].strval)) != NULL) {
                        printf("Error: Multiple declarations of variable %s at line %d.\n", (yyvsp[-1].strval), yylineno);
                    } else {
                        /* If no multiple is found, insert new array into symbol table */
                        ST_insert((yyvsp[-1].strval), (yyvsp[-2].node), SCALAR, &(current_scope));
                    }

                    /* add child for node as a tree with value: ID */
                    addChild(declNode, maketreeWithVal(IDENTIFIER, (yyvsp[-1].strval)));
                    /* assign as new child in output tree created in root: ast */
                    (yyval.node) = declNode;
                }
#line 1345 "obj/y.tab.c"
    break;

  case 9: /* typeSpecifier: KWD_INT  */
#line 189 "src/parser.y"
                {
                    /* create tree with value: Integer */
                    /* assign as new child in output tree created in root: ast */
		            (yyval.node) = maketreeWithVal(TYPESPEC, INT_TYPE);
		        }
#line 1355 "obj/y.tab.c"
    break;

  case 10: /* typeSpecifier: KWD_CHAR  */
#line 195 "src/parser.y"
                {
                    /* create tree with value: Character */
                    /* assign as new child in output tree created in root: ast */
		            (yyval.node) = maketreeWithVal(TYPESPEC, CHAR_TYPE);
		        }
#line 1365 "obj/y.tab.c"
    break;

  case 11: /* typeSpecifier: KWD_VOID  */
#line 201 "src/parser.y"
                {
                    /* create tree with value: Character */
                    /* assign as new child in output tree created in root: ast */
                    (yyval.node) = maketreeWithVal(TYPESPEC, VOID_TYPE);
		        }
#line 1375 "obj/y.tab.c"
    break;

  case 12: /* funDecl: funHeader LPAREN formalDeclList RPAREN funBody  */
#line 209 "src/parser.y"
                {
		            tree* funDeclNode = maketree (FUNDECL);
                    if ((yyvsp[-2].node) != NULL) {
                        addChild(funDeclNode, (yyvsp[-2].node));
                    }
                    if ((yyvsp[0].node) != NULL)  {
                        addChild(funDeclNode, (yyvsp[0].node));
                    }
                    connect_params(functionIndex, parameterCount);
		    /* assign as new child in output tree created in root: ast */
                    (yyval.node) = funDeclNode;
                }
#line 1392 "obj/y.tab.c"
    break;

  case 13: /* funDecl: funHeader LPAREN RPAREN funBody  */
#line 222 "src/parser.y"
                {
                    tree* funDeclNode = maketree (FUNDECL);
                    /* add child for node: funBody */
                    if ((yyvsp[0].node) != NULL) {
                    addChild(funDeclNode, (yyvsp[0].node));
                }
                    /* assign as new child in output tree created in root: ast */
                    (yyval.node) = funDeclNode;
                }
#line 1406 "obj/y.tab.c"
    break;

  case 14: /* funHeader: typeSpecifier ID  */
#line 233 "src/parser.y"
                {
                    /* create tree */
                    tree *funHeadNode = maketree(FUNHEAD);
                    /* add child for node: typeSpecifier */
                    addChild(funHeadNode, (yyvsp[-1].node));

                    /* Check for duplicate function definition */
                    if (ST_lookup((yyvsp[0].strval)) != NULL) {
                        printf("Error: Multiply defined function %s at line %d.\n", (yyvsp[0].strval), yylineno);
                    } else {
                        /* Insert function into symbol table if no duplicate */
                        functionIndex = ST_insert((yyvsp[0].strval), (yyvsp[-1].node)->val, FUNCTION, &(current_scope));
                    }

                    addChild(funHeadNode, maketreeWithVal(IDENTIFIER, (yyvsp[0].strval)));
                    (yyval.node) = funHeadNode;
                }
#line 1428 "obj/y.tab.c"
    break;

  case 15: /* formalDeclList: formalDecl  */
#line 252 "src/parser.y"
                {
		    parameterCount = 0;
                    /* create tree */
                    tree* formalDeclListNode = maketree(FORMALDECLLIST);
                    /* add child for node: formalDecl */
                    if ((yyvsp[0].node) != NULL) {
			            addChild(formalDeclListNode, (yyvsp[0].node));
		            }
                    /* assign as new child in output tree created in root: ast */
                    (yyval.node) = formalDeclListNode;
                }
#line 1444 "obj/y.tab.c"
    break;

  case 16: /* formalDeclList: formalDecl COMMA formalDeclList  */
#line 264 "src/parser.y"
                {
                    /* create tree */
                    tree* formalDeclListNode = maketree(FORMALDECLLIST);
                    /* add child for node: formalDecl */
                    if ((yyvsp[-2].node) != NULL) {
                        addChild(formalDeclListNode, (yyvsp[-2].node));
                    }
                    /* add child for node: formalDeclList */
                    if ((yyvsp[0].node) != NULL) {
                    addChild(formalDeclListNode, (yyvsp[0].node));
                    }
		    parameterCount++;
		            /* assign as new child in output tree created in root: ast */
                    (yyval.node) = formalDeclListNode;
                }
#line 1464 "obj/y.tab.c"
    break;

  case 17: /* formalDecl: typeSpecifier ID  */
#line 282 "src/parser.y"
                {
                    /* create tree */
                    tree *formalDeclNode = maketree(FORMALDECL);
                    /* add child for node: typeSpecifier */
                    addChild(formalDeclNode, (yyvsp[-1].node)); 
                    /* Check for duplicate parameter */
                    if (ST_lookup((yyvsp[0].strval)) != NULL) {
                        printf("Error: Parameter %s already defined in the scope at line %d.\n", (yyvsp[0].strval), yylineno);
                    } else {
                        /* Insert scalar parameter into the symbol table */
                        ST_insert((yyvsp[0].strval), (yyvsp[-1].node)->val, SCALAR, &(current_scope));
			add_param((yyvsp[-1].node), SCALAR);
                    } 

                    /* add child for node as a tree with value: ID */
                     addChild(formalDeclNode, maketreeWithVal(IDENTIFIER, (yyvsp[0].strval)));
                    /* assign as new child in output tree created in root: ast */
                    (yyval.node) = formalDeclNode;
                }
#line 1488 "obj/y.tab.c"
    break;

  case 18: /* formalDecl: typeSpecifier ID LSQ_BRKT RSQ_BRKT  */
#line 302 "src/parser.y"
                {
                    /* create tree */
                    tree *formalDeclNode = maketree(FORMALDECL);
                    /* add child for node: typeSpecifier */
                    addChild(formalDeclNode, (yyvsp[-3].node)); 
                    /* Check for duplicate parameter */
                    if (ST_lookup((yyvsp[-2].strval)) != NULL) {
                        printf("Error: Parameter %s already defined in the scope at line %d.\n", (yyvsp[-2].strval), yylineno);
                    } else {
                        /* Insert array parameter into the symbol table */
                        ST_insert((yyvsp[-2].strval), (yyvsp[-3].node)->val, ARRAY, &(current_scope));
			add_param((yyvsp[-3].node), ARRAY);
                    }
                    /* add child for node as a tree with value: ID */
                    addChild(formalDeclNode, maketreeWithVal(IDENTIFIER, (yyvsp[-2].strval))); 
                    /* add child for node: Array (Wasn't sure if i do this.. Otherwise these were the same though.)  */
                    addChild(formalDeclNode, maketreeWithVal(ARRAYDECL, VOID_TYPE));
                    /* assign as new child in output tree created in root: ast */
                    (yyval.node) = formalDeclNode;
                }
#line 1513 "obj/y.tab.c"
    break;

  case 19: /* funBody: LCRLY_BRKT localDeclList statementList RCRLY_BRKT  */
#line 325 "src/parser.y"
                {
		            new_scope();
                    /* create tree */
                    tree *funBodyNode = maketree(FUNBODY);
                    /* add child for node: localDeclList */
                    if ((yyvsp[-2].node) != NULL) {
                        addChild(funBodyNode, (yyvsp[-2].node));
                    } 
                    /* add child for node: statementList */
                    if ((yyvsp[-1].node) != NULL) {
                        addChild(funBodyNode, (yyvsp[-1].node));
                    } 
                    /* assign as new child in output tree created in root: ast */
                    (yyval.node) = funBodyNode;
		            up_scope();
                }
#line 1534 "obj/y.tab.c"
    break;

  case 20: /* localDeclList: %empty  */
#line 344 "src/parser.y"
                {
                    (yyval.node) = NULL;
                }
#line 1542 "obj/y.tab.c"
    break;

  case 21: /* localDeclList: varDecl localDeclList  */
#line 348 "src/parser.y"
                {
                    /* create tree */
                    tree *localDeclListNode = maketree(LOCALDECLLIST);
                    /* add child for node: varDecl */
                    addChild(localDeclListNode, (yyvsp[-1].node));
                    /* add child for node: localDeclList */ 
                    if ((yyvsp[0].node) != NULL) {
                        addChild(localDeclListNode, (yyvsp[0].node));
                    }
                    /* assign as new child in output tree created in root: ast */
                    (yyval.node) = localDeclListNode;
                }
#line 1559 "obj/y.tab.c"
    break;

  case 22: /* statementList: %empty  */
#line 363 "src/parser.y"
                {
                    (yyval.node) = NULL;
                }
#line 1567 "obj/y.tab.c"
    break;

  case 23: /* statementList: statement statementList  */
#line 367 "src/parser.y"
                {
                    /* create tree */
                    tree *statementListNode = maketree(STATEMENTLIST);
                    /* add child for node: statement */
                    addChild(statementListNode, (yyvsp[-1].node));
                    /* add child for node: statementList */
                    if ((yyvsp[0].node) != NULL) {  
                        addChild(statementListNode, (yyvsp[0].node));
                        }
                    /* assign as new child in output tree created in root: ast */
                    (yyval.node) = statementListNode;
                }
#line 1584 "obj/y.tab.c"
    break;

  case 24: /* statement: compoundStmt  */
#line 382 "src/parser.y"
                {
                    tree* statementNode = maketree(STATEMENT);
                    addChild(statementNode, (yyvsp[0].node));
                    (yyval.node) = statementNode;
                }
#line 1594 "obj/y.tab.c"
    break;

  case 25: /* statement: assignStmt  */
#line 388 "src/parser.y"
                {
                    tree* statementNode = maketree(STATEMENT);
                    addChild(statementNode, (yyvsp[0].node));
                    (yyval.node) = statementNode;
                }
#line 1604 "obj/y.tab.c"
    break;

  case 26: /* statement: condStmt  */
#line 394 "src/parser.y"
                {
                    tree* statementNode = maketree(STATEMENT);
                    addChild(statementNode, (yyvsp[0].node));
                    (yyval.node) = statementNode;
                }
#line 1614 "obj/y.tab.c"
    break;

  case 27: /* statement: loopStmt  */
#line 400 "src/parser.y"
                {
                    tree* statementNode = maketree(STATEMENT);
                    addChild(statementNode, (yyvsp[0].node));
                    (yyval.node) = statementNode;
                }
#line 1624 "obj/y.tab.c"
    break;

  case 28: /* statement: returnStmt  */
#line 406 "src/parser.y"
                {
                    tree* statementNode = maketree(STATEMENT);
                    addChild(statementNode, (yyvsp[0].node));
                    (yyval.node) = statementNode;
                }
#line 1634 "obj/y.tab.c"
    break;

  case 29: /* compoundStmt: LCRLY_BRKT statementList RCRLY_BRKT  */
#line 414 "src/parser.y"
                {
		            new_scope();
                    tree* compoundStmtNode = maketree(COMPOUNDSTMT);
                    addChild(compoundStmtNode, maketreeWithVal(STATEMENTLIST, (yyvsp[-2].value)));
                    (yyval.node) = compoundStmtNode;
		            up_scope();
                }
#line 1646 "obj/y.tab.c"
    break;

  case 30: /* assignStmt: var OPER_ASGN expression SEMICLN  */
#line 423 "src/parser.y"
                {
                    /* create tree */
                    tree *assignNode = maketree(ASSIGNSTMT);
                    /* add child for node: var */
                    addChild(assignNode, (yyvsp[-3].node));
                    /* add child for node: expression */
                    addChild(assignNode, (yyvsp[-1].node));
                    (yyval.node) = assignNode;
	            }
#line 1660 "obj/y.tab.c"
    break;

  case 31: /* assignStmt: expression  */
#line 433 "src/parser.y"
                {
                    tree* assignNode = maketree(ASSIGNSTMT);
                    addChild(assignNode, (yyvsp[0].node));
                    (yyval.node) = assignNode;
                }
#line 1670 "obj/y.tab.c"
    break;

  case 32: /* condStmt: KWD_IF LPAREN expression RPAREN statement  */
#line 441 "src/parser.y"
                {
                    /* create tree */
                    tree *condNode = maketree(CONDSTMT);
                    /* add child for node: expression */
                    addChild(condNode, (yyvsp[-2].node)); 
                    /* add child for node: statement */
                    addChild(condNode, (yyvsp[0].node)); 
                    /* assign as new child in output tree created in root: ast */
                    (yyval.node) = condNode;
                }
#line 1685 "obj/y.tab.c"
    break;

  case 33: /* condStmt: KWD_IF LPAREN expression RPAREN statement KWD_ELSE statement  */
#line 452 "src/parser.y"
                {
                    /* create tree */
                    tree *condNode = maketree(CONDSTMT);
                    /* add child for node: expression */
                    addChild(condNode, (yyvsp[-4].node)); 
                    /* add child for node: statement */
                    addChild(condNode, (yyvsp[-2].node)); 
                    /* add child for node: statement */
                    addChild(condNode, (yyvsp[0].node)); 
                    /* assign as new child in output tree created in root: ast */
                    (yyval.node) = condNode; 
                }
#line 1702 "obj/y.tab.c"
    break;

  case 34: /* loopStmt: KWD_WHILE LPAREN expression RPAREN statement  */
#line 467 "src/parser.y"
                { 
                    /* create tree */
                    tree *loopNode = maketree(LOOPSTMT);
                    /* add child for node: expression */
                    addChild(loopNode, (yyvsp[-2].node)); 
                    /* add child for node: statement */
                    addChild(loopNode, (yyvsp[0].node));
                    /* assign as new child in output tree created in root: ast */
                    (yyval.node) = loopNode; 
                }
#line 1717 "obj/y.tab.c"
    break;

  case 35: /* returnStmt: KWD_RETURN SEMICLN  */
#line 480 "src/parser.y"
                {
                    /* create tree */
                    tree *returnNode = maketree(RETURNSTMT);
                    /* assign as new child in output tree created in root: ast */
                    (yyval.node) = returnNode; 
                }
#line 1728 "obj/y.tab.c"
    break;

  case 36: /* returnStmt: KWD_RETURN expression SEMICLN  */
#line 487 "src/parser.y"
                {
                    /* create tree */
                    tree *returnNode = maketree(RETURNSTMT);
                    /* add child for node: expression */
                    addChild(returnNode, (yyvsp[-1].node));
                    /* assign as new child in output tree created in root: ast */
                    (yyval.node) = returnNode;
                }
#line 1741 "obj/y.tab.c"
    break;

  case 37: /* expression: addExpr  */
#line 497 "src/parser.y"
                {
                    tree* expressionNode = maketree(EXPRESSION);
                    addChild(expressionNode, (yyvsp[0].node));
                    (yyval.node) = expressionNode;
                }
#line 1751 "obj/y.tab.c"
    break;

  case 38: /* expression: expression relop addExpr  */
#line 503 "src/parser.y"
                {
                    /* create tree */
                    tree *exprNode = maketree(EXPRESSION);
                    /* add child for node: expression */
                    addChild(exprNode, (yyvsp[-2].node));  
                    /* add child for node: relop */
                    addChild(exprNode, (yyvsp[-1].node));  
                    /* add child for node: addExpr */
                    addChild(exprNode, (yyvsp[0].node));  
                    /* assign as new child in output tree created in root: ast */
                    (yyval.node) = exprNode;
                }
#line 1768 "obj/y.tab.c"
    break;

  case 39: /* var: ID  */
#line 518 "src/parser.y"
                {
                    /* create tree */
                    tree *varNode = maketree(VAR);

                    /* Lookup index */
                    symEntry* entry = ST_lookup((yyvsp[0].strval)); 
                    if (entry != NULL) {
                        /* add child for node as a tree with value: ID */
                        addChild(varNode, maketreeWithVal(IDENTIFIER, entry->id));
                    } else {
                        /* Error: Undefined Variable */
                        printf("Error: %s is not defined.\n", (yyvsp[0].strval));
                    }

                    /* assign as new child in output tree created in root: ast */
                    (yyval.node) = varNode;
                }
#line 1790 "obj/y.tab.c"
    break;

  case 40: /* var: ID LSQ_BRKT addExpr RSQ_BRKT  */
#line 536 "src/parser.y"
                {
                    /* create tree */
                    tree *varNode = maketree(VAR);

                    /* Lookup index */
                    symEntry* entry = ST_lookup((yyvsp[-3].strval)); 
                    if (entry != NULL) {
                        /* add child for node as a tree with value: ID */
                        addChild(varNode, maketreeWithVal(IDENTIFIER, entry->id));
                        /* add child for the array index expression */
                        addChild(varNode, (yyvsp[-1].node)); 
                    } else {
                        /* Error: Undefined Variable */
                        printf("Error: %s is not defined.\n", (yyvsp[-3].strval));
                    }

                    /* assign as new child in output tree created in root: ast */
                    (yyval.node) = varNode;
                }
#line 1814 "obj/y.tab.c"
    break;

  case 41: /* relop: OPER_LTE  */
#line 558 "src/parser.y"
                {
                    (yyval.node) = maketreeWithVal(RELOP, OPER_LTE);
                }
#line 1822 "obj/y.tab.c"
    break;

  case 42: /* relop: OPER_LT  */
#line 562 "src/parser.y"
                {
                    (yyval.node) = maketreeWithVal(RELOP, OPER_LT);
                }
#line 1830 "obj/y.tab.c"
    break;

  case 43: /* relop: OPER_GT  */
#line 566 "src/parser.y"
                {
                    (yyval.node) = maketreeWithVal(RELOP, OPER_GT);
                }
#line 1838 "obj/y.tab.c"
    break;

  case 44: /* relop: OPER_GTE  */
#line 570 "src/parser.y"
                {
                    (yyval.node) = maketreeWithVal(RELOP, OPER_GTE);
                }
#line 1846 "obj/y.tab.c"
    break;

  case 45: /* relop: OPER_EQ  */
#line 574 "src/parser.y"
                {
                    (yyval.node) = maketreeWithVal(RELOP, OPER_EQ);
                }
#line 1854 "obj/y.tab.c"
    break;

  case 46: /* relop: OPER_NEQ  */
#line 578 "src/parser.y"
                {
                    (yyval.node) = maketreeWithVal(RELOP, OPER_NEQ);
                }
#line 1862 "obj/y.tab.c"
    break;

  case 47: /* addExpr: term  */
#line 584 "src/parser.y"
                {
                    tree* addExprNode = maketree(ADDEXPR);
                    addChild(addExprNode, (yyvsp[0].node));
                    (yyval.node) = addExprNode;
                }
#line 1872 "obj/y.tab.c"
    break;

  case 48: /* addExpr: addExpr addop term  */
#line 590 "src/parser.y"
                {
                    /* create tree */
                    tree *addExprNode = maketree(ADDEXPR);
                    /* add child for node: addExpr */
                    addChild(addExprNode, (yyvsp[-2].node)); 
                    /* add child for node: addop */
                    addChild(addExprNode, (yyvsp[-1].node)); 
                    /* add child for node: term */
                    addChild(addExprNode, (yyvsp[0].node)); 
                    /* assign as new child in output tree created in root: ast */
                    (yyval.node) = addExprNode;
                }
#line 1889 "obj/y.tab.c"
    break;

  case 49: /* addExpr: addExpr SEMICLN  */
#line 603 "src/parser.y"
                {
                    tree* addExprNode = maketree(ADDEXPR);
                    addChild(addExprNode, (yyvsp[-1].node));
                    (yyval.node) = addExprNode;
                }
#line 1899 "obj/y.tab.c"
    break;

  case 50: /* addop: OPER_ADD  */
#line 611 "src/parser.y"
                {
                    (yyval.node) = maketreeWithVal(ADDOP, OPER_ADD);
                }
#line 1907 "obj/y.tab.c"
    break;

  case 51: /* addop: OPER_SUB  */
#line 615 "src/parser.y"
                {
                    (yyval.node) = maketreeWithVal(ADDOP, OPER_SUB);
                }
#line 1915 "obj/y.tab.c"
    break;

  case 52: /* term: factor  */
#line 621 "src/parser.y"
                {
                    tree* termNode = maketree(TERM);
                    addChild(termNode, (yyvsp[0].node));
                    (yyval.node) = termNode;
                }
#line 1925 "obj/y.tab.c"
    break;

  case 53: /* term: term mulop factor  */
#line 627 "src/parser.y"
                {
                    /* create tree */
                    tree* termNode = maketree(TERM);
                    /* add child for node: term */
                    addChild(termNode, (yyvsp[-2].node)); 
                    /* add child for node: mulop */
                    addChild(termNode, (yyvsp[-1].node)); 
                    /* add child for node: factor */
                    addChild(termNode, (yyvsp[0].node)); 
                    /* assign as new child in output tree created in root: ast */
                    (yyval.node) = termNode;
                }
#line 1942 "obj/y.tab.c"
    break;

  case 54: /* term: term SEMICLN  */
#line 640 "src/parser.y"
                {
                    tree* termNode = maketree(TERM);
                    addChild(termNode, (yyvsp[-1].node));
                    (yyval.node) = termNode;
                }
#line 1952 "obj/y.tab.c"
    break;

  case 55: /* mulop: OPER_MUL  */
#line 649 "src/parser.y"
                {
                    (yyval.node) = maketreeWithVal(MULOP, OPER_MUL);
                }
#line 1960 "obj/y.tab.c"
    break;

  case 56: /* mulop: OPER_DIV  */
#line 653 "src/parser.y"
                {
                    (yyval.node) = maketreeWithVal(MULOP, OPER_DIV);
                }
#line 1968 "obj/y.tab.c"
    break;

  case 57: /* factor: LPAREN expression RPAREN  */
#line 659 "src/parser.y"
                {
                    tree* factorNode = maketree(FACTOR);
                    addChild(factorNode, maketreeWithVal(EXPRESSION, (yyvsp[-2].value)));
                    (yyval.node) = factorNode;
                }
#line 1978 "obj/y.tab.c"
    break;

  case 58: /* factor: var  */
#line 665 "src/parser.y"
                {
                    tree* factorNode = maketree(FACTOR);
                    addChild(factorNode, maketreeWithVal(VAR, (yyvsp[0].node)));
                    (yyval.node) = factorNode;
                }
#line 1988 "obj/y.tab.c"
    break;

  case 59: /* factor: funcCallExpr  */
#line 671 "src/parser.y"
                {
                    tree* factorNode = maketree(FACTOR);
                    addChild(factorNode, maketreeWithVal(FUNCCALLEXPR, (yyvsp[0].node)));
                    (yyval.node) = factorNode;
                }
#line 1998 "obj/y.tab.c"
    break;

  case 60: /* factor: INTCONST  */
#line 677 "src/parser.y"
                {
                    tree* factorNode = maketree(FACTOR);
                    addChild(factorNode, maketreeWithVal(INTEGER, (yyvsp[0].value)));
                    (yyval.node) = factorNode;
                }
#line 2008 "obj/y.tab.c"
    break;

  case 61: /* factor: CHARCONST  */
#line 683 "src/parser.y"
                {
                    tree* factorNode = maketree(FACTOR);
                    addChild(factorNode, maketreeWithVal(CHAR, (yyvsp[0].strval)));
                    (yyval.node) = factorNode;
                }
#line 2018 "obj/y.tab.c"
    break;

  case 62: /* factor: STRCONST  */
#line 689 "src/parser.y"
                {
                    //tree* strConstNode = maketree(FACTOR);
                    //addChild(varNode, maketreeWithVal(CHAR, $1));
                    //$$ = varNode;
                    tree* factorNode = maketree(FACTOR);
                }
#line 2029 "obj/y.tab.c"
    break;

  case 63: /* funcCallExpr: ID LPAREN argList RPAREN  */
#line 698 "src/parser.y"
                {
                    /* create tree */
                    tree *funcCallNode = maketree(FUNCCALLEXPR);

                    /* Lookup the index to see if the function is in the symbol table */
                    symEntry* index = ST_lookup((yyvsp[-3].strval));
                    if (index != NULL &&  index->symbol_type == FUNCTION) {
                        /* Add the function identifier to the AST if num arguments is correct */
                        int num_args = ((yyvsp[-1].node)->numChildren);
                        if (num_args != index->size) {
                        printf("Error: Incorrect number of arguments for function %s at line %d.\n", (yyvsp[-3].strval), yylineno);
                        } else {
                            addChild(funcCallNode, maketreeWithVal(IDENTIFIER, index));
                        }
                    } else {
                        /* Error: Undefined Function */
                        printf("Error: function %s is not defined.\n", (yyvsp[-3].strval));
                    } 

                    /* add child for node: argList */
                    addChild(funcCallNode, (yyvsp[-1].node)); 
                    /* assign as new child in output tree created in root: ast */
                    (yyval.node) = funcCallNode;
                }
#line 2058 "obj/y.tab.c"
    break;

  case 64: /* funcCallExpr: ID LPAREN RPAREN  */
#line 723 "src/parser.y"
                {
                    /* create tree */
                    tree *funcCallNode = maketree(FUNCCALLEXPR);

                    /* Lookup the index to see if the function is in the symbol table */
                    symEntry* index = ST_lookup((yyvsp[-2].strval)); 
                    if (index >= 0) {
                        /* Add the function identifier to the AST */
                        addChild(funcCallNode, maketreeWithVal(IDENTIFIER, index));
                    } else {
                        /* Error: Undefined Function */
                        printf("Error: function %s is not defined.\n", (yyvsp[-2].strval));
                    }
                    /* assign as new child in output tree created in root: ast */
                    (yyval.node) = funcCallNode; 
                }
#line 2079 "obj/y.tab.c"
    break;

  case 65: /* argList: expression  */
#line 742 "src/parser.y"
                {
                    tree* expressionNode = maketree(ARGLIST);
                    addChild(expressionNode, maketreeWithVal(EXPRESSION, (yyvsp[0].node)));
                    (yyval.node) = expressionNode;
                }
#line 2089 "obj/y.tab.c"
    break;

  case 66: /* argList: argList COMMA expression  */
#line 748 "src/parser.y"
                {
                    /* create tree */
                    tree *argListNode = maketree(ARGLIST);
                    /* add child for node: argList */
                    addChild(argListNode, (yyvsp[-2].node)); 
                    /* add child for node: expression */
                    addChild(argListNode, (yyvsp[0].node)); 
                    /* assign as new child in output tree created in root: ast */
                    (yyval.node) = argListNode;
                }
#line 2104 "obj/y.tab.c"
    break;


#line 2108 "obj/y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 760 "src/parser.y"


int yywarning(char * msg){
    printf("warning: line %d: %s\n", yylineno, msg);
    return 0;
}

int yyerror(char * msg){
    printf("error: line %d: %s\n", yylineno, msg);
    return 0;
}
            
