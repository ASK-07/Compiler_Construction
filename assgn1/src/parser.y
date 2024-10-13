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
             assignStmt condStmt loopStmt returnStmt relop addExpr addop term mulop factor funcCallExpr argList expression var char void

%start program

%%
/* Grammars */
program         : declList
                {
                    /* create tree */
                    tree* progNode = maketree(PROGRAM);
                    /* add child for node: declList */
                    addChild(progNode, $1);
                    /* assign tree to output variable: ast (root) */
                    ast = progNode;
                }
        ;

declList        : decl
                {
                    /* create tree */
                    tree* declListNode = maketree(DECLLIST);
                    /* add child for node: decl */
                    addChild(declListNode, $1);
                    /* assign as new child in output tree created in root: ast */
                    $$ = declListNode;
                }
                | declList decl
                {
                    /* create tree */
                    tree* declListNode = maketree(DECLLIST);
                    /* add child for node: declList */
                    addChild(declListNode, $1);
                    /* add child for node: decl */
                    addChild(declListNode, $2);
                    /* assign as new child in output tree created in root: ast */
                    $$ = declListNode;
                }
                ;

decl            : varDecl
                {
                    /* create tree */
                    tree* varDeclNode = maketree(DECL);
                    /* add child for node: varDecl */
                    addChild(varDeclNode, $1);
                    /* assign as new child in output tree created in root: ast */
                    $$ = varDeclNode;
                }
		        | funDecl
                {
                    /* create tree */
                    tree* funDeclNode = maketree(DECL);
                    /* add child for node: funDecl */
                    addChild(funDeclNode, $1);
                    /* assign as new child in output tree created in root: ast */
                    $$ = funDeclNode;
                }
                ;

varDecl         : typeSpecifier ID LPAREN INTCONST RPAREN
                {
                    /* create tree */
                    tree *declNode = maketree(VARDECL);
                    /* add child for node: typeSpecifier */
                    addChild(declNode, $1);
                    /* Lookup index */
                    int index = ST_lookup($2, scope);
                    /* add child for node as a tree with value: ID */
                    addChild(declNode, maketreeWithVal(IDENTIFIER, index));
                    /* add child for node as a tree with value: INTCONST */
                    addChild(declNode, maketreeWithVal(INTCONST, $4));
                    /* assign as new child in output tree created in root: ast */
                    $$ = declNode;
                }
		        | typeSpecifier ID SEMICLN
                {
                    /* create tree */
                    tree *declNode = maketree(VARDECL);
                    /* add child for node: typeSpecifier */
                    addChild(declNode, $1);
                    /* Lookup index */
                    int index = ST_lookup($2, scope);
                    /* add child for node as a tree with value: ID */
                    addChild(declNode, maketreeWithVal(IDENTIFIER, index));
                    /* assign as new child in output tree created in root: ast */
                    $$ = declNode;
                }
                ;

typeSpecifier	: KWD_INT
                {
                    /* create tree with value: Integer */
                    /* assign as new child in output tree created in root: ast */
		            $$ = maketreeWithVal(TYPESPEC, INTEGER);
		        }
                | KWD_CHAR
                {
                    /* create tree with value: Character */
                    /* assign as new child in output tree created in root: ast */
		            $$ = maketreeWithVal(TYPESPEC, CHAR);
		        }
                | KWD_VOID
                {
                    /*nothing*/
		        }
                ;

funDecl         : typeSpecifier ID LPAREN formalDeclList RPAREN funBody
                {
                    /* create tree */
                    tree *funDeclNode = maketree(FUNDECL);
                    /* add child for node: typeSpecifier */
                    addChild(funDeclNode, $1);
                    /* Lookup index */
                    int index = ST_lookup($2, scope);
                    /* add child for node as a tree with value: ID */
                    addChild(funDeclNode, maketreeWithVal(IDENTIFIER, index));
                    /* add child for node: formalDeclList */
                    addChild(funDeclNode, $4);
                    /* add child for node: funBody */
                    addChild(funDeclNode, $6);
                    /* assign as new child in output tree created in root: ast */
                    $$ = funDeclNode;
                }
		        | typeSpecifier ID LPAREN RPAREN funBody
                {
                    /* create tree */
                    tree *funDeclNode = maketree(FUNDECL);
                    /* add child for node: typeSpecifier */
                    addChild(funDeclNode, $1);
                    /* Lookup index */
                    int index = ST_lookup($2, scope);
                    addChild(funDeclNode, maketreeWithVal(IDENTIFIER, index));
                    /* add child for node: funBody */
                    addChild(funDeclNode, $5);
                    /* assign as new child in output tree created in root: ast */
                    $$ = funDeclNode;
                }
                ;

formalDeclList  : formalDecl
                {
                    /* create tree */
                    tree* formalDeclListNode = maketree(FORMALDECLLIST);
                    /* add child for node: formalDecl */
                    addChild(formalDeclListNode, $1);
                    /* assign as new child in output tree created in root: ast */
                    $$ = formalDeclListNode;
                }
		        | formalDecl COMMA formalDeclList
                {
                    /* create tree */
                    tree* formalDeclListNode = maketree(FORMALDECLLIST);
                    /* add child for node: formalDecl */
                    addChild(formalDeclListNode, $1);
                    /* add child for node: formalDeclList */
                    addChild(formalDeclListNode, $3);
                    /* assign as new child in output tree created in root: ast */
                    $$ = formalDeclListNode;
                }
                ;

formalDecl      : typeSpecifier ID
                {
                    /* create tree */
                    tree *formalDeclNode = maketree(FORMALDECL);
                    /* add child for node: typeSpecifier */
                    addChild(formalDeclNode, $1); 
                    /* Lookup index */
                    int index = ST_lookup($2, scope); 
                    /* add child for node as a tree with value: ID */
                    addChild(formalDeclNode, maketreeWithVal(IDENTIFIER, index)); 
                    /* assign as new child in output tree created in root: ast */
                    $$ = formalDeclNode;
                }
		        | typeSpecifier ID LSQ_BRKT RSQ_BRKT
                {
                    /* create tree */
                    tree *formalDeclNode = maketree(FORMALDECL);
                    /* add child for node: typeSpecifier */
                    addChild(formalDeclNode, $1); 
                    /* Lookup index */
                    int index = ST_lookup($2, scope); 
                    /* add child for node as a tree with value: ID */
                    addChild(formalDeclNode, maketreeWithVal(IDENTIFIER, index)); 
                    /* add child for node: Array (Wasn't sure if i do this.. Otherwise these were the same though.)  */
                    addChild(formalDeclNode,ARRAYDECL);
                    /* assign as new child in output tree created in root: ast */
                    $$ = formalDeclNode;
                }
                ;

funBody         : LCRLY_BRKT localDeclList statementList RCRLY_BRKT
                {
                    /* create tree */
                    tree *funBodyNode = maketree(FUNBODY);
                    /* add child for node: localDeclList */
                    addChild(funBodyNode, $2); 
                    /* add child for node: statementList */
                    addChild(funBodyNode, $3); 
                    /* assign as new child in output tree created in root: ast */
                    $$ = funBodyNode;
                }
                ;

localDeclList   : 
		        | varDecl localDeclList
                {
                    /* create tree */
                    tree *localDeclListNode = maketree(LOCALDECLLIST);
                    /* add child for node: varDecl */
                    addChild(localDeclListNode, $1);
                    /* add child for node: localDeclList */ 
                    addChild(localDeclListNode, $2);
                    /* assign as new child in output tree created in root: ast */
                    $$ = localDeclListNode;
                }
                ;

statementList   : 
		        | statement statementList
                {
                    /* create tree */
                    tree *statementListNode = maketree(STATEMENTLIST);
                    /* add child for node: statement */
                    addChild(statementListNode, $1);
                    /* add child for node: statementList */
                    addChild(statementListNode, $2);
                    /* assign as new child in output tree created in root: ast */
                    $$ = statementListNode;
                }
                ;

statement       : compoundStmt
                | assignStmt
                | condStmt
                | loopStmt
                | returnStmt

compoundStmt    : LCRLY_BRKT statementList RCRLY_BRKT
                {
                    /* assign statementList as new child in output tree created in root: ast */
                    $$ = $2;
                }
                ;
assignStmt      : var OPER_ASGN expression
                {
                    /* create tree */
                    tree *assignNode = maketree(ASSIGNSTMT);
                    /* add child for node: var */
                    addChild(assignNode, $1);
                    /* add child for node: expression */
                    addChild(assignNode, $3);
                    $$ = assignNode;
	            }
		        | expression
                {
                    /* assign expression as new child in output tree created in root: ast */
                    $$ = $1;
                }
                ;

condStmt        : KWD_IF LPAREN expression RPAREN statement
                {
                    /* create tree */
                    tree *condNode = maketree(CONDSTMT);
                    /* add child for node: expression */
                    addChild(condNode, $3); 
                    /* add child for node: statement */
                    addChild(condNode, $5); 
                    /* assign as new child in output tree created in root: ast */
                    $$ = condNode;
                }
		        | KWD_IF LPAREN expression RPAREN statement KWD_ELSE statement
                {
                    /* create tree */
                    tree *condNode = maketree(CONDSTMT);
                    /* add child for node: expression */
                    addChild(condNode, $3); 
                    /* add child for node: statement */
                    addChild(condNode, $5); 
                    /* add child for node: statement */
                    addChild(condNode, $7); 
                    /* assign as new child in output tree created in root: ast */
                    $$ = condNode; 
                }
                ;

loopStmt        : KWD_WHILE LPAREN expression RPAREN statement
                { 
                    /* create tree */
                    tree *loopNode = maketree(LOOPSTMT);
                    /* add child for node: expression */
                    addChild(loopNode, $3); 
                    /* add child for node: statement */
                    addChild(loopNode, $5);
                    /* assign as new child in output tree created in root: ast */
                    $$ = loopNode; 
                }
                ;

returnStmt      : KWD_RETURN
                {
                    /* create tree */
                    tree *returnNode = maketree(RETURNSTMT);
                    /* assign as new child in output tree created in root: ast */
                    $$ = returnNode; 
                }
		        | KWD_RETURN expression
                {
                    /* create tree */
                    tree *returnNode = maketree(RETURNSTMT);
                    /* add child for node: expression */
                    addChild(returnNode, $2);
                    /* assign as new child in output tree created in root: ast */
                    $$ = returnNode;
                }

expression      : addExpr
                | expression relop addExpr
                {
                    /* create tree */
                    tree *exprNode = maketree(EXPRESSION);
                    /* add child for node: expression */
                    addChild(exprNode, $1);  
                    /* add child for node: relop */
                    addChild(exprNode, $2);  
                    /* add child for node: addExpr */
                    addChild(exprNode, $3);  
                    /* assign as new child in output tree created in root: ast */
                    $$ = exprNode;
                }
                ;

var             : ID
                | ID LSQ_BRKT addExpr RSQ_BRKT
                {
                    /* create tree */
                    tree *varNode = maketree(VAR);
                    /* Lookup index */
                    int index = ST_lookup($1, scope); 
                    /* add child for node as a tree with value: ID */
                    addChild(varNode, maketreeWithVal(IDENTIFIER, index)); 
                    /* assign as new child in output tree created in root: ast */
                    $$ = varNode;
                }
                ;

char            : CHARCONST
                {
                    /* create tree with value: Character */
                    /* assign as new child in output tree created in root: ast */
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

addExpr          : term
                | addExpr addop term
                {
                    /* create tree */
                    tree *addExprNode = maketree(ADDEXPR);
                    /* add child for node: addExpr */
                    addChild(addExprNode, $1); 
                    /* add child for node: addop */
                    addChild(addExprNode, $2); 
                    /* add child for node: term */
                    addChild(addExprNode, $3); 
                    /* assign as new child in output tree created in root: ast */
                    $$ = addExprNode;
                }
                ;

addop           : OPER_ADD
                | OPER_SUB
                ;

term            : factor
                | term mulop factor
                {
                    /* create tree */
                    tree *termNode = maketree(TERM);
                    /* add child for node: term */
                    addChild(termNode, $1); 
                    /* add child for node: mulop */
                    addChild(termNode, $2); 
                    /* add child for node: factor */
                    addChild(termNode, $3); 
                    /* assign as new child in output tree created in root: ast */
                    $$ = termNode;
                }
                ;

mulop           : OPER_MUL
                | OPER_DIV
                ;

factor          : LPAREN expression RPAREN
                {
                    /* assign expression as new child in output tree created in root: ast */
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
                    /* create tree */
                    tree *funcCallNode = maketree(FUNCCALLEXPR);
                    /* Lookup index */
                    int index = ST_lookup($1, scope); 
                    /* add child for node as a tree with value: ID */
                    addChild(funcCallNode, maketreeWithVal(IDENTIFIER, index)); 
                    /* add child for node: argList */
                    addChild(funcCallNode, $3); 
                    /* assign as new child in output tree created in root: ast */
                    $$ = funcCallNode;
                }
                | ID LPAREN RPAREN
                {
                    /* create tree */
                    tree *funcCallNode = maketree(FUNCCALLEXPR);
                    /* Lookup index */
                    int index = ST_lookup($1, scope); 
                    /* add child for node as a tree with value: ID */
                    addChild(funcCallNode, maketreeWithVal(IDENTIFIER, index)); 
                    /* assign as new child in output tree created in root: ast */
                    $$ = funcCallNode; 
                }
                ;

argList         : expression
                | argList COMMA expression
                {
                    /* create tree */
                    tree *argListNode = maketree(ARGLIST);
                    /* add child for node: argList */
                    addChild(argListNode, $1); 
                    /* add child for node: expression */
                    addChild(argListNode, $3); 
                    /* assign as new child in output tree created in root: ast */
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