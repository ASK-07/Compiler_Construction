
/*Description: This is a 'rough draft' of the scanner.l file.
//Here we can update / share progress that isn't complete.
*/

/* definitions */

%{
#include<stdio.h>
#include "tokendef.h"

int scancol = 1;
int yycol = 1;

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
string		\"([^\"\n\\]*(\\.[^\"\n\\]*)*)*\"

/* If the end quote is found, one of the two regexes above will be matched. Otherwise,
// the string is unterminated.
*/
untermstring 	\"([^\"\n]*)$

comment         \/\/.*
multlncomment   \/\*[\s\S]*?\*\/
/* Same as with unterminated strings, this will catch any comment that has a start but
// no end after multlncomment has already scanned valid comments
*/
untermcomment   \/\*[\s\S]*

/* identifiers can begin with any uppercase or lowercase letter followed by
// any number of letters or digits. They may not begin with a digit.
*/
identifier      [a-zA-Z][a-zA-Z0-9]*
illidentifier   [0-9][a-zA-Z0-9]*

yylineno = 1;

%%

 /* rules */

 /* Keywords */;
"if" 		{updateCol(); return KWD_IF;}
"else" 		{updateCol(); return KWD_ELSE;}
"while" 	{updateCol(); return KWD_WHILE;}
"int" 		{updateCol(); return KWD_INT;}
"string" 	{updateCol(); return KWD_STRING;}
"char" 		{updateCol(); return KWD_CHAR;}
"return" 	{updateCol(); return KWD_RETURN;}
"void" 		{updateCol(); return KWD_VOID;}

 /* Operators */;
\+		    {updateCol(); return OPER_ADD;}
\-		    {updateCol(); return OPER_SUB;}
\*		    {updateCol(); return OPER_MUL;}
\/		    {updateCol(); return OPER_DIV;}
\%		    {updateCol(); return OPER_MOD;}
\<		    {updateCol(); return OPER_LT;}
\>		    {updateCol(); return OPER_GT;}
\<\=	    {updateCol(); return OPER_GTE;}
\>\=	    {updateCol(); return OPER_LTE;}
\=\=	    {updateCol(); return OPER_EQ;}
\!\=	    {updateCol(); return OPER_NEQ;}
\=		    {updateCol(); return OPER_ASGN;}
\[		    {updateCol(); return LSQ_BRKT;}
\]		    {updateCol(); return RSQ_BRKT;}
\{		    {updateCol(); return LCRLY_BRKT;}
\}		    {updateCol(); return RCRLY_BRKT;}
\(		    {updateCol(); return LPAREN;}
\)		    {updateCol(); return RPAREN;}
\,		    {updateCol(); return COMMA;}
\;		    {updateCol(); return SEMICLN;}
\@		    {updateCol(); return OPER_AT;}
\+\+		{updateCol(); return OPER_INC;}
\-\-		{updateCol(); return OPER_DEC;}
\&\&		{updateCol(); return OPER_AND;}
\|\|		{updateCol(); return OPER_OR;}
\!		    {updateCol(); return OPER_NOT;}



 /* Constants */;
{integer}       {updateCol(); return INTCONST;}
{integerlead0}  {updateCol(); yyerror = "Integers may not have leading zeros"; return ERROR;} // Catching an integer that begins with 0 and generating an error. 
{character}     {updateCol(); return CHARCONST;}

{multlnstring}  {updateCol(); countLines(); yyerror = "String spans multiple lines"; return ERROR;} // Catching a multi-line string and generating an error.
{untermstring}  {updateCol(); yyerror = "Unterminated string"; return ERROR;}
{string}	{updateCol(); return processString();}

 /* Identifiers */;
{identifier}    {updateCol(); return ID;}
{illidentifier} {updateCol(); yyerror = "Illegal identifier detected. Identifiers must begin with an uppercase or lowercase letter."; return ERROR;}

 /* Comments */;
{comment}       {updateCol();}
{untermcomment} {updateCol(); yyerror = "Unterminated comment"; return ERROR;}
{multlncomment} {updateCol(); countLines();}

 /* Other */;
{newline}       {countLines();}
{whitespace}    {updateCol();}
.               {return ILLEGAL_TOK;}

%%

/* user routines */

void updateCol(){
    yycol = scancol;
    scancol += yyleng;
}

void countLines(){
    yylineno++;
    scancol = 1;
    yycol = 1;
}


int processString() {
    // Check for illegal escape sequences
    for (int i = 0; i < yyleng; i++) {
        if (yytext[i] == '\\') {
            // Check if there is a next character
            if (i + 1 >= yyleng || (yytext[i + 1] != 'n' && yytext[i + 1] != 't' && 
                                    yytext[i + 1] != '"' && yytext[i + 1] != '\\')) {
                // Found an illegal escape sequence
                printf("<ERROR, Unrecognized escape character in String> : (%d:%d)\n", yylineno, yycol);
                return ERROR;
            }
            // Increment i to skip the next character since it's part of the escape sequence
            i++;
        }
    }
    return STRCONST; // Adjust this based on your needs
}
