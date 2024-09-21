
/*Description: This is a 'rough draft' of the scanner.l file.
//Here we can update / share progress that isn't complete.
*/

/* definitions */

%{
#include<stdio.h>
#include "tokendef.h"

int scancol = 1;
int yycol = 1;
int scanlineno = 1;

char* yyerror;

void updateCol(); 
void countLines(); 
int processString(); 
%}

newline         \n
whitespace      [\s|\t]+
integer         [1-9][0-9]*
integerlead0    0[0-9]*
character       \'[A-Za-z]\'

/* String can contain any characters between the double quotes other than a newline or
// unescaped doublequotes.
*/
string		\"[^/n"]\"

/* multiline string has \n somewhere in the middle */
multlnstring 	\"[^"]*\n[^"]*\"

/* If the end quote is found, one of the two regexes above will be matched. Otherwise,
// the string is unterminated.
*/
untermstring 	\"[\n\s\S]*

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
\@		    {updateCol(); return AT;}
\+\+		{updateCol(); return OPER_INC;}
\-\-		{updateCol(); return OPER_DEC;}
\&\&		{updateCol(); return OPER_AND;}
\|\|		{updateCol(); return STR_ESCAPE;}
\!		    {updateCol(); return OPER_NOT;}

 /* Identifiers */;
{identifier}    {updateCol(); return ID;}
{illidentifier} {updateCol(); yyerror = "Illegal identifier detected. Identifiers must begin with an uppercase or lowercase letter." }

 /* Constants */;
{integer}       {updateCol(); return INTCONST;}
{integerlead0}  {updateCol(); yyerror = "Integers may not have leading zeros"; return ERROR;} // Catching an integer that begins with 0 and generating an error. 
{character}     {updateCOL(); return CHARCONST;}
{string}        {updateCol(); return processString();}
{untermstring}  {updateCol(); yyerror = "Unterminated string"; return ERROR;}
{multlnstring}  {updateCol(); countLines(); yyerror = "String spans multiple lines"; return ERROR;} // Catching a multi-line string and generating an error.

 /* Comments */;
{comment}       {updateCol();}
{untermcomment} {updateCol();, countLines();}
{multlncomment} {updateCol();, yyerror = "Unterminated comment"; return ERROR;}

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
    line_number = scanlineno;
    scanlineno += line_number;
}


int processString(){
	// TODO: Process a string literal and return the appropriate microsyntax.
}
