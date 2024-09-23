
/* definitions */

%{
#include<stdio.h>
#include "tokendef.h"

int scancol = 1;
int yycol = 1;
int startIndex;
int startCol;

char* yyerror;

void updateCol(); 
void countLines(); 
int processString(); 
%}

newline         \n
integerlead0    0[0-9]+
integer         0|[1-9][0-9]*
character       \'[A-Za-z]\'
whitespace      [ \t]+

/* multiline string has \n somewhere in the middle */
multlnstring \"([^\"]*[\n][^\"]*)\"

/* String can contain any characters between the double quotes other than a newline or
// unescaped doublequotes.
*/

string		    \"([^\"\n\\]*(\\.[^\"\n\\]*)*)*\"

/* multiline string has \n somewhere in the middle */
multlnstring 	\"([^\"]*[\n][^\"]*)\"


/* If the end quote is found, one of the two regexes above will be matched. Otherwise,
// the string is unterminated.
*/
untermstring 	\"([^\"\n]*)$

comment         \/\*[^\n]*\*\/
multlncomment   \/\*[^*]*\*\/
/* Same as with unterminated strings, this will catch any comment that has a start but
// no end after multlncomment has already scanned valid comments
*/
untermcomment   \/\*[^*]*

/* identifiers can begin with any uppercase or lowercase letter followed by
// any number of letters or digits. They may not begin with a digit.
*/
identifier      [a-zA-Z][a-zA-Z0-9]*
illidentifier   [0-9][a-zA-Z0-9]*

yylineno = 1;

%%

 /* rules */

 /* Keywords */;
"if" 		    {updateCol(); return KWD_IF;}
"else" 		    {updateCol(); return KWD_ELSE;}
"while" 	    {updateCol(); return KWD_WHILE;}
"int" 		    {updateCol(); return KWD_INT;}
"string" 	    {updateCol(); return KWD_STRING;}
"char" 		    {updateCol(); return KWD_CHAR;}
"return" 	    {updateCol(); return KWD_RETURN;}
"void" 		    {updateCol(); return KWD_VOID;}

 /* Operators */;
\+		        {updateCol(); return OPER_ADD;}
\-		        {updateCol(); return OPER_SUB;}
\*		        {updateCol(); return OPER_MUL;}
\/		        {updateCol(); return OPER_DIV;}
\%		        {updateCol(); return OPER_MOD;}
\<		        {updateCol(); return OPER_LT;}
\>		        {updateCol(); return OPER_GT;}
\<\=	        {updateCol(); return OPER_GTE;}
\>\=	        {updateCol(); return OPER_LTE;}
\=\=	        {updateCol(); return OPER_EQ;}
\!\=	        {updateCol(); return OPER_NEQ;}
\=		        {updateCol(); return OPER_ASGN;}
\[		        {updateCol(); return LSQ_BRKT;}
\]		        {updateCol(); return RSQ_BRKT;}
\{		        {updateCol(); return LCRLY_BRKT;}
\}		        {updateCol(); return RCRLY_BRKT;}
\(		        {updateCol(); return LPAREN;}
\)		        {updateCol(); return RPAREN;}
\,		        {updateCol(); return COMMA;}
\;		        {updateCol(); return SEMICLN;}
\@		        {updateCol(); return OPER_AT;}
\+\+		    {updateCol(); return OPER_INC;}
\-\-		    {updateCol(); return OPER_DEC;}
\&\&		    {updateCol(); return OPER_AND;}
\|\|		    {updateCol(); return OPER_OR;}
\!		        {updateCol(); return OPER_NOT;}

 /* Constants */;
{integer}       {updateCol(); return INTCONST;}
{integerlead0}  {updateCol(); yyerror = "Integers may not have leading zeros"; return ERROR;}
{character}     {updateCol(); return CHARCONST;}

{string}        {updateCol();  return processString();}
{untermstring}  {updateCol(); yyerror = "Unterminated string"; return ERROR;}
{multlnstring}  {updateCol(); countLines(yytext); yyerror = "String spans multiple lines"; return ERROR;}




 /* Identifiers */;
{identifier}    {updateCol(); return ID;}
{illidentifier} {updateCol(); yyerror = "Illegal identifier detected. Identifiers must begin with an uppercase or lowercase letter."; return ERROR;}

 /* Comments */;
{comment}       {updateCol();}
{multlncomment} {updateCol(); countLines(yytext);}
{untermcomment} {updateCol(); yyerror = "Unterminated comment"; return ERROR;}


 /* Other */;
{newline}       {countLines(yytext);}
{whitespace}    {updateCol();}
.               {return ILLEGAL_TOK;}

%%

/* user routines */

void updateCol(){
    yycol = scancol;
    scancol += yyleng;
}

void countLines(const char *string) {

    int line_column_tracker = 1;

    const char *ptr = string;
    while (*ptr) {
        if (*ptr == '\n') {
            yylineno++;

            line_column_tracker = 1;
        }
        else{
            line_column_tracker++;
        }
        ptr++;
    }
    scancol = line_column_tracker;
    yycol = line_column_tracker;
}


int processString() {
    for (int i = 0; i < (yyleng-1); i++){
        char ch1 = yytext[i];
        char ch2;
        if (ch1 == '\\'){
            ch2 = yytext[i+1];
            if ((ch2 != 'n') && (ch2 != 't') && (ch2 !='\\') && (ch2 != '\"')){
                yyerror = "Unrecognized escape character in String";
                yycol = i+1;
                return ERROR;
            }
        }
    }
}
