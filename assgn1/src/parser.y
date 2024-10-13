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

%type <node> program declList decl varDecl typeSpecifier funDecl formalDeclList formalDecl funBody localDeclList statementList statement compoundStmt
             assignStmt condStmt loopStmt returnStmt relop addExpr addop term mulop factor funcCallExpr argList  expression var char void

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
                {
                    tree* varDeclNode = maketree(DECL);
                    addChild(varDeclNode, $1);
                    $$ = varDeclNode;
                }
		        | funDecl
                {
                    tree* funDeclNode = maketree(DECL);
                    addChild(funDeclNode, $1);
                    $$ = funDeclNode;
                }
                ;

varDecl         : typeSpecifier ID LPAREN INTCONST RPAREN
                {
                    tree *declNode = maketree(VARDECL);
                    addChild(declNode, $1);
                    int index = ST_insert($2);
                    addChild(declNode, maketreeWithVal(IDENTIFIER, index));
                    addChild(declNode, maketreeWithVal(INTCONST, $4));
                    $$ = declNode;
                }
		        | typeSpecifier ID SEMICLN
                {
                    tree *declNode = maketree(VARDECL);
                    addChild(declNode, $1);
                    int index = ST_insert($2);
                    addChild(declNode, maketreeWithVal(IDENTIFIER, index));
                    $$ = declNode;
                }
                ;

typeSpecifier	: KWD_INT
                {
		            $$ = maketreeWithVal(TYPESPEC, INT);
		        }
                | KWD_CHAR
                {
		            $$ = maketreeWithVal(TYPESPEC, CHAR);
		        }
                | KWD_VOID
                {
		            $$ = maketreeWithVal(TYPESPEC, VOID);
		        }
                ;

funDecl         : typeSpecifier ID LPAREN formalDeclList RPAREN funBody
                {
                    tree *declNode = maketree(FUNDECL);
                    addChild(funDeclNode, $1);
                    int index = ST_insert($2);
                    addChild(declNode, maketreeWithVal(IDENTIFIER, index));
                    addChild(funDeclNode, $4);
                    addChild(funDeclNode, $6);
                    $$ = declNode;
                }
		        | typeSpecifier ID LPAREN RPAREN funBody
                {
                    tree *declNode = maketree(FUNDECL);
                    addChild(funDeclNode, $1);
                    int index = ST_insert($2);
                    addChild(declNode, maketreeWithVal(IDENTIFIER, index));
                    addChild(funDeclNode, $5);
                    $$ = declNode;
                }
                ;

formalDeclList  : formalDecl
                {
                    tree* varDeclNode = maketree(FORMALDECLLIST);
                    addChild(formalDeclListNode, $1);
                    $$ = formalDeclListNode;
                }
		        | formalDecl COMMA formalDeclList
                {
                    tree* varDeclNode = maketree(FORMALDECLLIST);
                    addChild(formalDeclListNode, $1);
                    addChild(formalDeclListNode, $3);
                    $$ = formalDeclListNode;
                }
                ;

formalDecl      : typeSpecifier ID
                {
                    tree *formalDeclNode = maketree(FORMALDECL);
                    addChild(formalDeclNode, $1); 
                    int index = ST_insert($2); 
                    addChild(formalDeclNode, maketreeWithVal(IDENTIFIER, index)); 
                    $$ = formalDeclNode;
                }
		        | typeSpecifier ID LSQ_BRKT RSQ_BRKT
                {
                    tree *formalDeclNode = maketree(FORMALDECL);
                    addChild(formalDeclNode, $1); 
                    int index = ST_insert($2); 
                    addChild(formalDeclNode, maketreeWithVal(IDENTIFIER, index)); 
                    addChild(formalDeclNode, maketree(ARRAYDECL));
                    $$ = formalDeclNode;
                }
                ;

funBody         : LCRLY_BRKT localDeclList statementList RCRLY_BRKT
                {
                    tree *funBodyNode = maketree(FUNBODY);
                    addChild(funBodyNode, $2); 
                    addChild(funBodyNode, $3); 
                    $$ = funBodyNode;
                }
                ;

localDeclList   : 
		        | varDecl localDeclList
                {
                    $$ = maketree(LOCALDECLLIST);
                    addChild(localDeclListNode, $1); 
                    addChild(localDeclListNode, $2);
                }
                ;

statementList   : 
		        | statement statementList
                {
                    $$ = maketree(STATEMENTLIST);
                    addChild(statementListNode, $1);
                    addChild(statementListNode, $2);
                }
                ;

statement       : compoundStmt
                | assignStmt
                | condStmt
                | loopStmt
                | returnStmt

compoundStmt    : LCRLY_BRKT statementList RCRLY_BRKT
                {
                    $$ = $2;
                }
                ;
assignStmt      : var OPER_ASGN expression
                {
                    tree *assignNode = maketree(ASSIGNSTMT);
                    addChild(assignNode, $1);
                    addChild(assignNode, $3);
                    $$ = assignNode;
	            }
		        | expression
                {
                    $$ = $1;
                }
                ;

condStmt        : KWD_IF LPAREN expression RPAREN statement
                {
                    tree *condNode = maketree(CONDSTMT);
                    addChild(condNode, $3); 
                    addChild(condNode, $5); 
                    $$ = condNode;
                }
		        | KWD_IF LPAREN expression RPAREN statement KWD_ELSE statement
                {
                    tree *condNode = maketree(CONDSTMT);
                    addChild(condNode, $3); 
                    addChild(condNode, $5); 
                    addChild(condNode, $7); 
                    $$ = condNode; 
                }
                ;

loopStmt        : KWD_WHILE LPAREN expression RPAREN statement
                { 
                    tree *loopNode = maketree(LOOPSTMT);
                    addChild(loopNode, $3); 
                    addChild(loopNode, $5);
                    $$ = loopNode; 
                }
                ;

returnStmt      : KWD_RETURN
                {
                    tree *returnNode = maketree(RETURNSTMT);
                    $$ = returnNode; 
                }
		        | KWD_RETURN expression
                {
                    tree *returnNode = maketree(RETURNSTMT);
                    addChild(returnNode, $2);
                    $$ = returnNode;
                }

expression      : addExp
                | expression relop addExp
                {
                    tree *exprNode = maketree(EXPRESSION);
                    addChild(exprNode, $1);  
                    addChild(exprNode, $2);  
                    addChild(exprNode, $3);  
                    $$ = exprNode;
                }
                ;

var             : ID
                | ID LSQ_BRKT addExp RSQ_BRKT
                {
                    tree *varNode = maketree(VAR);
                    int index = ST_insert($1); 
                    addChild(varNode, maketreeWithVal(IDENTIFIER, index)); 
                    $$ = varNode;
                }
                ;

char            : CHARCONST
                {
                    $$ = maketreeWithVal(CHAR, $1);
                }
                ;

relop           : OPER_LTE
                | OPER_LT
                | OPER_GT
                | OPER_GTE
                | OPER_EQ
                | OPER_NEQ
                ;

addExp          : term
                | addExp addop term
                {
                    tree *addExpNode = maketree(ADDEXP);
                    addChild(addExpNode, $1); 
                    addChild(addExpNode, $2); 
                    addChild(addExpNode, $3); 
                    $$ = addExpNode;
                }
                ;

addop           : OPER_ADD
                | OPER_SUB
                ;

term            : factor
                | term mulop factor
                {
                    tree *termNode = maketree(TERM);
                    addChild(termNode, $1); 
                    addChild(termNode, $2); 
                    addChild(termNode, $3); 
                    $$ = termNode;
                }
                ;

mulop           : OPER_MUL
                | OPER_DIV
                ;

factor          : LPAREN expression RPAREN
                {
                    $$ = $2; 
                }
                | var
                | funcCallExpr
                | INTCONST
                | CHARCONST
                | STRCONST
                ;

funcCallExpr    : ID LPAREN argList RPAREN
                {
                    tree *funcCallNode = maketree(FUNCTIONCALL);
                    int index = ST_insert($1); 
                    addChild(funcCallNode, maketreeWithVal(IDENTIFIER, index)); 
                    addChild(funcCallNode, $3); 
                    $$ = funcCallNode;
                }
                | ID LPAREN RPAREN
                {
                    tree *funcCallNode = maketree(FUNCTIONCALL);
                    int index = ST_insert($1); 
                    addChild(funcCallNode, maketreeWithVal(IDENTIFIER, index)); 
                    $$ = funcCallNode; 
                }
                ;

argList         : expression
                | argList COMMA expression
                {
                    tree *argListNode = maketree(ARGUMENTS);
                    addChild(argListNode, $1); 
                    addChild(argListNode, $3); 
                    $$ = argListNode;
                }
                ;

%%

int yywarning(char * msg){
    printf("warning: line %d: %s\n", yylineno, msg);
    return 0;
}

int yyerror(char * msg){
    printf("error: line %d: %s\n", yylineno, msg);
    return 0;
}