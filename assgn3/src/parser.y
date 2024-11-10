%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<../src/tree.h>
#include<../src/strtab.h>
#include <stdbool.h>

extern int yylineno;
extern table_node* current_scope;

enum opType {ADD, SUB, MUL, DIV, LT, LTE, EQ, GTE, GT, NEQ};

int functionIndex;
int parameterCount;
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
%token <value> ERROR
%token <value> ILLEGAL_TOK

/* Keywords */
%token <value> KWD_IF     
%token <value> KWD_ELSE   
%token <value> KWD_WHILE  
%token <value> KWD_INT    
%token <value> KWD_STRING 
%token <value> KWD_CHAR   
%token <value> KWD_RETURN 
%token <value> KWD_VOID

/* Operators */
%token <value> OPER_ADD
%token <value> OPER_SUB
%token <value> OPER_MUL
%token <value> OPER_DIV
%token <value> OPER_LT
%token <value> OPER_GT
%token <value> OPER_GTE
%token <value> OPER_LTE
%token <value> OPER_EQ
%token <value> OPER_NEQ
%token <value> OPER_ASGN
%token <value> OPER_MOD
%token <value> OPER_INC
%token <value> OPER_DEC
%token <value> OPER_AND
%token <value> OPER_NOT
%token <value> OPER_AT
%token <value> OPER_OR

/* Brackets and Parenthesis */
%token <value> LSQ_BRKT
%token <value> RSQ_BRKT
%token <value> LCRLY_BRKT
%token <value> RCRLY_BRKT
%token <value> LPAREN
%token <value> RPAREN

/* Punctuation */
%token <value> COMMA
%token <value> SEMICLN

/* Declare none terminals as nodes */

%type <node> program declList decl varDecl typeSpecifier funDecl formalDeclList formalDecl funBody localDeclList statementList statement compoundStmt
             assignStmt condStmt loopStmt returnStmt relop addExpr addop term mulop factor funcCallExpr argList expression var funHeader

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

varDecl         : typeSpecifier ID LSQ_BRKT INTCONST RSQ_BRKT SEMICLN
                {
                    /* Create tree */
                    tree *declNode = maketree(VARDECL);
                    /* Add child for node: typeSpecifier */
                    addChild(declNode, $1);
                    int index;
                    /* Check for out-of-bounds array size (non-positive integer) */
                    if ($4 <= 0) {
                        printf("Error: Array %s declared with non-positive size %d at line %d.\n", $2, $4, yylineno);
                    }

                    /* Lookup index and check for a multiple declaration */
                    if (ST_lookup($2) != NULL) {
                        printf("Error: Multiple declarations of variable %s at line %d.\n", $2, yylineno);
                    } else {
                        /* If no multiple is found, insert new array into symbol table */
                        index = ST_insert($2, $1->val, ARRAY, (int *)(&current_scope));
                    }

                    /* Add child for node as a tree with value: ID */
                    addChild(declNode, maketreeWithVal(IDENTIFIER, index));
                    /* Add child for node as a tree with value: INTCONST */
                    addChild(declNode, maketreeWithVal(INTEGER, $4));
                    $$ = declNode;
                }
		        | typeSpecifier ID SEMICLN
                {
                    /* create tree */
                    tree *declNode = maketree(VARDECL);
                    /* add child for node: typeSpecifier */
                    addChild(declNode, $1);
                    int index;
                    /* Lookup index and check for a multiple declaration */
                    if (ST_lookup($2) != NULL) {
                        printf("Error: Multiple declarations of variable %s at line %d.\n", $2, yylineno);
                    } else {
                        /* If no multiple is found, insert new array into symbol table */
                        index = ST_insert($2, $1, SCALAR, (int *)(&current_scope));
                    }

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
		            $$ = maketreeWithVal(TYPESPEC, INT_TYPE);
		        }
                | KWD_CHAR
                {
                    /* create tree with value: Character */
                    /* assign as new child in output tree created in root: ast */
		            $$ = maketreeWithVal(TYPESPEC, CHAR_TYPE);
		        }
                | KWD_VOID
                {
                    /* create tree with value: Character */
                    /* assign as new child in output tree created in root: ast */
                    $$ = maketreeWithVal(TYPESPEC, VOID_TYPE);
		        }
                ;

funDecl         : funHeader LPAREN formalDeclList RPAREN funBody
                {
		            tree* funDeclNode = maketree (FUNDECL);
                    if ($3 != NULL) {
                        addChild(funDeclNode, $3);
                    }
                    if ($5 != NULL)  {
                        addChild(funDeclNode, $5);
                    }
                    connect_params(functionIndex, parameterCount);
		            /* assign as new child in output tree created in root: ast */
                    $$ = funDeclNode;
                }
		        | funHeader LPAREN RPAREN funBody
                {
                    tree* funDeclNode = maketree (FUNDECL);
                    /* add child for node: funBody */
                    if ($4 != NULL) {
                    addChild(funDeclNode, $4);
                }
                    /* assign as new child in output tree created in root: ast */
                    $$ = funDeclNode;
                }
                ;
funHeader       : typeSpecifier ID 
                {
                    new_scope();
                    /* create tree */
                    tree *funHeadNode = maketree(FUNHEAD);
                    /* add child for node: typeSpecifier */
                    addChild(funHeadNode, $1);

                    /* Check for duplicate function definition */
                    if (ST_lookup($2) != NULL) {
                        printf("Error: Multiply defined function %s at line %d.\n", $2, yylineno);
                    } else {
                        /* Insert function into symbol table if no duplicate */
                        functionIndex = ST_insert($2, $1->val, FUNCTION, (int *)(&current_scope));
                    }

                    addChild(funHeadNode, maketreeWithVal(IDENTIFIER, functionIndex));
                    $$ = funHeadNode;
                    up_scope();
                }

formalDeclList  : formalDecl
                {
		            parameterCount = 0;
                    /* create tree */
                    tree* formalDeclListNode = maketree(FORMALDECLLIST);
                    /* add child for node: formalDecl */
                    if ($1 != NULL) {
			            addChild(formalDeclListNode, $1);
		            }
                    /* assign as new child in output tree created in root: ast */
                    $$ = formalDeclListNode;
                }
		        | formalDecl COMMA formalDeclList
                {
                    /* create tree */
                    tree* formalDeclListNode = maketree(FORMALDECLLIST);
                    /* add child for node: formalDecl */
                    if ($1 != NULL) {
                        addChild(formalDeclListNode, $1);
                    }
                    /* add child for node: formalDeclList */
                    if ($3 != NULL) {
                    addChild(formalDeclListNode, $3);
                    }
		            parameterCount++;
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
                    /* Check for duplicate parameter */
                    int index;
                    if (ST_lookup($2) != NULL) {
                        printf("Error: Parameter %s already defined in the scope at line %d.\n", $2, yylineno);
                    } else {
                        /* Insert scalar parameter into the symbol table */
                        index = ST_insert($2, $1->val, SCALAR, (int *)(&current_scope));
			            add_param($1, SCALAR);
                    } 

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
                    int index; 
                    /* Check for duplicate parameter */
                    if (ST_lookup($2) != NULL) {
                        printf("Error: Parameter %s already defined in the scope at line %d.\n", $2, yylineno);
                    } else {
                        /* Insert array parameter into the symbol table */
                        index = ST_insert($2, $1->val, ARRAY, (int *)(&current_scope));
			            add_param($1, ARRAY);
                    }
                    /* add child for node as a tree with value: ID */
                    addChild(formalDeclNode, maketreeWithVal(IDENTIFIER, index)); 
                    /* add child for node: Array (Wasn't sure if i do this.. Otherwise these were the same though.)  */
                    addChild(formalDeclNode, maketreeWithVal(ARRAYDECL, VOID_TYPE));
                    /* assign as new child in output tree created in root: ast */
                    $$ = formalDeclNode;
                }
                ;

funBody         : LCRLY_BRKT localDeclList statementList RCRLY_BRKT
                {
                    /* create tree */
                    tree *funBodyNode = maketree(FUNBODY);
                    /* add child for node: localDeclList */
                    if ($2 != NULL) {
                        addChild(funBodyNode, $2);
                    } 
                    /* add child for node: statementList */
                    if ($3 != NULL) {
                        addChild(funBodyNode, $3);
                    } 
                    /* assign as new child in output tree created in root: ast */
                    $$ = funBodyNode;
                }
                ;

localDeclList   :
                {
                    $$ = NULL;
                }
		        | varDecl localDeclList
                {
                    /* create tree */
                    tree *localDeclListNode = maketree(LOCALDECLLIST);
                    /* add child for node: varDecl */
                    addChild(localDeclListNode, $1);
                    /* add child for node: localDeclList */ 
                    if ($2 != NULL) {
                        addChild(localDeclListNode, $2);
                    }
                    /* assign as new child in output tree created in root: ast */
                    $$ = localDeclListNode;
                }
                ;

statementList   :
                {
                    $$ = NULL;
                }
		        | statement statementList
                {
                    /* create tree */
                    tree *statementListNode = maketree(STATEMENTLIST);
                    /* add child for node: statement */
                    addChild(statementListNode, $1);
                    /* add child for node: statementList */
                    if ($2 != NULL) {  
                        addChild(statementListNode, $2);
                        }
                    /* assign as new child in output tree created in root: ast */
                    $$ = statementListNode;
                }
                ;

statement       : compoundStmt
                {
                    tree* statementNode = maketree(STATEMENT);
                    addChild(statementNode, $1);
                    $$ = statementNode;
                }
                | assignStmt
                {
                    tree* statementNode = maketree(STATEMENT);
                    addChild(statementNode, $1);
                    $$ = statementNode;
                }
                | condStmt
                {
                    tree* statementNode = maketree(STATEMENT);
                    addChild(statementNode, $1);
                    $$ = statementNode;
                }
                | loopStmt
                {
                    tree* statementNode = maketree(STATEMENT);
                    addChild(statementNode, $1);
                    $$ = statementNode;
                }
                | returnStmt
                {
                    tree* statementNode = maketree(STATEMENT);
                    addChild(statementNode, $1);
                    $$ = statementNode;
                }
                ;

compoundStmt    : LCRLY_BRKT statementList RCRLY_BRKT
                {
		            new_scope();
                    tree* compoundStmtNode = maketree(COMPOUNDSTMT);
                    addChild(compoundStmtNode, maketreeWithVal(STATEMENTLIST, $1));
                    $$ = compoundStmtNode;
		            up_scope();
                }
                ;
assignStmt      : var OPER_ASGN expression SEMICLN
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
                    tree* assignNode = maketree(ASSIGNSTMT);
                    addChild(assignNode, $1);
                    $$ = assignNode;
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

returnStmt      : KWD_RETURN SEMICLN
                {
                    /* create tree */
                    tree *returnNode = maketree(RETURNSTMT);
                    /* assign as new child in output tree created in root: ast */
                    $$ = returnNode; 
                }
		        | KWD_RETURN expression SEMICLN
                {
                    /* create tree */
                    tree *returnNode = maketree(RETURNSTMT);
                    /* add child for node: expression */
                    addChild(returnNode, $2);
                    /* assign as new child in output tree created in root: ast */
                    $$ = returnNode;
                }

expression      : addExpr
                {
                    tree* expressionNode = maketree(EXPRESSION);
                    addChild(expressionNode, $1);
                    $$ = expressionNode;
                }
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
                {
                    /* create tree */
                    tree *varNode = maketree(VAR);

                    /* Lookup index */
                    symEntry* entry = ST_lookup($1); 
                    if (entry != NULL) {
                        /* add child for node as a tree with value: ID */
                        addChild(varNode, maketreeWithVal(IDENTIFIER, entry->id));
                    } else {
                        /* Error: Undefined Variable */
                        printf("Error: %s is not defined.\n", $1);
                    }

                    /* assign as new child in output tree created in root: ast */
                    $$ = varNode;
                }
                | ID LSQ_BRKT addExpr RSQ_BRKT
                {
                    /* create tree */
                    tree *varNode = maketree(VAR);

                    /* Lookup index */
                    symEntry* entry = ST_lookup($1); 
                    if (entry != NULL) {
                        /* add child for node as a tree with value: ID */
                        addChild(varNode, maketreeWithVal(IDENTIFIER, entry->id));
                        /* add child for the array index expression */
                        addChild(varNode, $3); 
                    } else {
                        /* Error: Undefined Variable */
                        printf("Error: %s is not defined.\n", $1);
                    }

                    /* assign as new child in output tree created in root: ast */
                    $$ = varNode;
                }
                ;

relop           : OPER_LTE
                {
                    $$ = maketreeWithVal(RELOP, OPER_LTE);
                }
                | OPER_LT
                {
                    $$ = maketreeWithVal(RELOP, OPER_LT);
                }
                | OPER_GT
                {
                    $$ = maketreeWithVal(RELOP, OPER_GT);
                }
                | OPER_GTE
                {
                    $$ = maketreeWithVal(RELOP, OPER_GTE);
                }
                | OPER_EQ
                {
                    $$ = maketreeWithVal(RELOP, OPER_EQ);
                }
                | OPER_NEQ
                {
                    $$ = maketreeWithVal(RELOP, OPER_NEQ);
                }
                ;

addExpr         : term
                {
                    tree* addExprNode = maketree(ADDEXPR);
                    addChild(addExprNode, $1);
                    $$ = addExprNode;
                }
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
                | addExpr SEMICLN
                {
                    tree* addExprNode = maketree(ADDEXPR);
                    addChild(addExprNode, $1);
                    $$ = addExprNode;
                }
                ;

addop           : OPER_ADD
                {
                    $$ = maketreeWithVal(ADDOP, OPER_ADD);
                }
                | OPER_SUB
                {
                    $$ = maketreeWithVal(ADDOP, OPER_SUB);
                }
                ;

term            : factor
                {
                    tree* termNode = maketree(TERM);
                    addChild(termNode, $1);
                    $$ = termNode;
                }
                | term mulop factor
                {
                    /* create tree */
                    tree* termNode = maketree(TERM);
                    /* add child for node: term */
                    addChild(termNode, $1); 
                    /* add child for node: mulop */
                    addChild(termNode, $2); 
                    /* add child for node: factor */
                    addChild(termNode, $3); 
                    /* assign as new child in output tree created in root: ast */
                    $$ = termNode;
                }
                | term SEMICLN
                {
                    tree* termNode = maketree(TERM);
                    addChild(termNode, $1);
                    $$ = termNode;
                }

                ;

mulop           : OPER_MUL
                {
                    $$ = maketreeWithVal(MULOP, OPER_MUL);
                }
                | OPER_DIV
                {
                    $$ = maketreeWithVal(MULOP, OPER_DIV);
                }
                ;

factor          : LPAREN expression RPAREN
                {
                    tree* factorNode = maketree(FACTOR);
                    addChild(factorNode, maketreeWithVal(EXPRESSION, $1));
                    $$ = factorNode;
                }
                | var
                {
                    tree* factorNode = maketree(FACTOR);
                    addChild(factorNode, maketreeWithVal(VAR, $1));
                    $$ = factorNode;
                }
                | funcCallExpr
                {
                    tree* factorNode = maketree(FACTOR);
                    addChild(factorNode, maketreeWithVal(FUNCCALLEXPR, $1));
                    $$ = factorNode;
                }
                | INTCONST
                {
                    tree* factorNode = maketree(FACTOR);
                    addChild(factorNode, maketreeWithVal(INTEGER, $1));
                    $$ = factorNode;
                }
                | CHARCONST
                {
                    tree* factorNode = maketree(FACTOR);
                    addChild(factorNode, maketreeWithVal(CHAR, $1));
                    $$ = factorNode;
                }
                | STRCONST
                {
                    //tree* strConstNode = maketree(FACTOR);
                    //addChild(varNode, maketreeWithVal(CHAR, $1));
                    //$$ = varNode;
                    tree* factorNode = maketree(FACTOR);
                }
                ;

funcCallExpr    : ID LPAREN argList RPAREN
                {
                    /* create tree */
                    tree *funcCallNode = maketree(FUNCCALLEXPR);

                    /* Lookup the index to see if the function is in the symbol table */
                    symEntry* index = ST_lookup($1);
                    if (index != NULL &&  index->symbol_type == FUNCTION) {
                        int num_args = ($3->numChildren);
                        bool count_check = num_args == index->size;
                        bool type_check = true;
                        param* expected = index->params;
                        int index_index = 0;
                        while (expected){
                            if ($3->children[index_index]->nodeKind != index->data_type) {
                                type_check = false;
                            }
                            expected = expected->next;
                            index_index++;
                        }
                        if (!count_check) {
                            printf("Error: Incorrect number of arguments for function %s at line %d.\n", $1, yylineno);
                        }
                        if (!type_check){
                            printf("Error: Type mismatch for function $s call at line %d. \n", $1, yylineno);
                        }
                        if (count_check && type_check){
                            addChild(funcCallNode, maketreeWithVal(IDENTIFIER, index));
                        }
                    } else {
                        /* Error: Undefined Function */
                        printf("Error: function %s is not defined.\n", $1);
                    }
                    addChild(funcCallNode, $3); 
                    /* assign as new child in output tree created in root: ast */
                    $$ = funcCallNode;
                }
                | ID LPAREN RPAREN
                {
                    /* create tree */
                    tree *funcCallNode = maketree(FUNCCALLEXPR);

                    /* Lookup the index to see if the function is in the symbol table */
                    symEntry* index = ST_lookup($1); 
                    if (index != NULL) {
                        if (index->size != 0){
                            printf("Error: Incorrect number of arguments for function %s at line %d.\n", $1, yylineno);
                        } else {
                            /* Add the function identifier to the AST */
                            addChild(funcCallNode, maketreeWithVal(IDENTIFIER, index));
                        }
                    } else {
                        /* Error: Undefined Function */
                        printf("Error: function %s is not defined.\n", $1);
                    }
                    /* assign as new child in output tree created in root: ast */
                    $$ = funcCallNode; 
                }
                ;

argList         : expression
                {
                    tree* expressionNode = maketree(ARGLIST);
                    addChild(expressionNode, maketreeWithVal(EXPRESSION, $1));
                    $$ = expressionNode;
                }
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
void check_params(symEntry* func_entry, treenode* argList){
    int num_params = func_entry->params_count;
    param* formal_params = func_entry->params;
    int num_args = countArgs(argList);

    if (num_args != num_params) {
        printf("Error: Function %s expects %d arguments, but %d were provided.\n", func_entry->id, num_params, num_args);
    }

    
}
