
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


/* Updates the current column number so that token locations
// can be printed to the console. */
void updateCol(){
    yycol = scancol;
    scancol += yyleng;
    /* If the error is on a different line than the beginning of the token,
    // such as in a multiline string, update the line number to the current
    // scanner position */
    if (yylineno < scanlineno){
        yylineno = scanlineno;
    }
    else {scanlineno = yylineno;}
}

/* Updates the current line number so that token locations
// can be printed to the console. Takes the token as input. */
void countLines(const char *string) {
    int newline_found_flag = 0;

    const char *ptr = string;
    /* If a newline is detected, line number is incremented and
    // column number is set back to 1. Also flags that the
    // current token spans multiple lines. */
    while (*ptr) {
        if ((*ptr == '\n') && (newline_found_flag == 0)) {
            scanlineno++;
            scancol = 1;
            newline_found_flag = 1;
        }
        else if ((*ptr == '\n') && (newline_found_flag == 1)){
            scanlineno++;
            scancol = 1;
        }
	/* The reason this increments yycol but the next condition
	// doesn't is so that the location of a newline in a
	// multiline string can be printed in the error message. */
        else if ((*ptr != '\n') && (newline_found_flag == 0)){
            yycol++;
            scancol++;
        }
        else if ((*ptr != '\n') && (newline_found_flag == 1)){
            scancol++;
        }
        ptr++;
    }
    

}

/* Checks out every character in a string to look for escape characters */
int processString() {

    /* Iterates through each character */
    for (int i = 0; i < (yyleng-1); i++){
        char ch1 = yytext[i];
        char ch2;

	/* If backslash is detected, check next character to see if it is
	// a valid escape sequence */
        if (ch1 == '\\'){
            ch2 = yytext[i+1];
            if ((ch2 != 'n') && (ch2 != 't') && (ch2 !='\\') && (ch2 != '\"')){
                yyerror = "Unrecognized escape character in String";
                yycol = i+1;
                return ERROR;
            }
	    /* Skips a character since next character has already been checked */
	    i++;
        }
    }
    return STRCONST;
}
