%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<../src/tree.h>
#include<../src/strtab.h>

extern int yylineno;
enum nodeTypes {PROGRAM, DECLLIST, DECL, VARDECL, TYPESPEC, FUNDECL,
                FORMALDECLLIST, FORMALDECL, FUNBODY, LOCALDECLLIST,
                STATEMENTLIST, STATEMENT, COMPOUNDSTMT, ASSIGNSTMT,
                CONDSTMT, LOOPSTMT, RETURNSTMT, EXPRESSION, RELOP,
                ADDEXPR, ADDOP, TERM, MULOP, FACTOR, FUNCCALLEXPR,
                ARGLIST, INTEGER, IDENTIFIER, VAR, ARRAYDECL, CHAR,
                FUNCTYPENAME};

enum opType {ADD, SUB, MUL, DIV, LT, LTE, EQ, GTE, GT, NEQ};

/* NOTE: mC has two kinds of scopes for variables : local and global. Variables declared outside any
function are considered globals, whereas variables (and parameters) declared inside a function foo are local to foo. You should update the scope variable whenever you are inside a production
 that matches function definition (funDecl production). The rationale is that you are entering that function, so all variables, arrays, and other functions should be within this scope. You should pass this variable
  whenever you are calling the ST_insert or ST_lookup functions. This variable should be updated to scope = "" to indicate global scope whenever funDecl finishes. Treat these hints as helpful directions only. You may
   implement all of the functions as you like and not adhere to my instructions. As long as the directory structure is correct and the file names are correct, we are okay with it. */
char* scope = "";
%}

/* the union describes the fields available in the yylval variable */
%union
{
    int value;
    struct treenode *node;
    char *strval;
}

/* Token declarations */

/*Major Stuff*/
%token <strval> ID
%token <value> INTCONST
%token <strval> CHARCONST
%token <strval> STRCONST
%token ERROR
%token ILLEGAL_TOK

/* Keywords */
%token KWD_IF     
%token KWD_ELSE   
%token KWD_WHILE  
%token KWD_INT    
%token KWD_STRING 
%token KWD_CHAR   
%token KWD_RETURN 
%token KWD_VOID

/* Operators */
%token OPER_ADD
%token OPER_SUB
%token OPER_MUL
%token OPER_DIV
%token OPER_LT
%token OPER_GT
%token OPER_GTE
%token OPER_LTE
%token OPER_EQ
%token OPER_NEQ
%token OPER_ASGN
%token OPER_MOD
%token OPER_INC
%token OPER_DEC
%token OPER_AND
%token OPER_NOT
%token OPER_AT
%token OPER_OR

/* Brackets and Parenthesis*/
%token LSQ_BRKT
%token RSQ_BRKT
%token LCRLY_BRKT
%token RCRLY_BRKT
%token LPAREN
%token RPAREN

/* Punctuation */
%token COMMA
%token SEMICLN

/* Declare none terminals as nodes */

%type <node> program declList decl varDecl typeSpecifier funDecl formalDeclList formalDecl funBody localDeclList statementList statement compoundStmt assignStmt condStmt loopStmt returnStmt expression var char void

*/
%start program

%%
/* Grammars */


program         : declList
                {
                    tree* progNode = maketree(PROGRAM);
                    addChild(progNode, $1);
                    ast = progNode;
                }
        ;

declList        : decl
                {
                    tree* declListNode = maketree(DECLLIST);
                    addChild(declListNode, $1);
                    $$ = declListNode;
                }
                | declList decl
                {
                    tree* declListNode = maketree(DECLLIST);
                    addChild(declListNode, $1);
                    addChild(declListNode, $2);
                    $$ = declListNode;
                }
                ;

decl            : varDecl
		        | funDecl

varDecl         : typeSpecifier ID LPAREN INTCONST RPAREN
		        | typeSpecifier ID SEMICLN

typeSpecifier	: INT
                | CHAR
                | VOID

funDecl         : typeSpecifier ID LPAREN formalDeclList RPAREN funBody
		        | typeSpecifier ID LPAREN RPAREN funBody

formalDeclList  : formalDecl
		        | formalDecl COMMA formalDeclList

formalDecl      : typeSpecifier ID
		        | typeSpecifier ID LSQ_BRKT RSQ_BRKT

funBody         : LCRLY_BRKT localDeclList statementList RCRLY_BRKT

localDeclList   : 
		        | varDecl localDeclList

statementList   : 
		        | statement statementList

statement       : compoundStmt
                | assignStmt
                | condStmt
                | loopStmt
                | returnStmt

compoundStmt    : LCRLY_BRKT statementList RCRLY_BRKT

assignStmt      : var OPER_ASGN expression
		    | expression

condStmt        : KWD_IF LPAREN expression RPAREN statement
		    | KWD_IF LPAREN expression RPAREN statement KWD_ELSE statement

loopStmt        : KWD_WHILE LPAREN expression RPAREN statement

returnStmt      : KWD_RETURN
		    | KWD_RETURN expression


%%

int yywarning(char * msg){
    printf("warning: line %d: %s\n", yylineno, msg);
    return 0;
}

int yyerror(char * msg){
    printf("error: line %d: %s\n", yylineno, msg);
    return 0;
}