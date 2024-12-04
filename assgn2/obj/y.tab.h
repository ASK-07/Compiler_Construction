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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union
{
    int value;
    struct treenode *node;
    char *strval;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
