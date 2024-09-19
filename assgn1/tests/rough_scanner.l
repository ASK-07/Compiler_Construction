
/*Description: This is a 'rough draft' of the scanner.l file.
//Here we can update / share progress that isn't complete.
//I'll also put the questions my progress sparked and you can offer
//some thinkies if you want before i decide if I need to email questions.
//
//1: The .h file seems to be missing many entries. Assuming we 
//   add those, do we want to just put them in the correct 'group'
//   then continue the count into the 200's? 
//2: The specifications about int confused me a bit. Looking at the
//   'Constants' section, do we need to create a different
//   definition (and regular expression), for an integer with a leading
//    0?
//3: I am unclear on how comments will need to be. Specifically i'm having
//   trouble reconciling the write up section on comments with the skeleton
//   code
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
integer         0|[1-9][0-9]*
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
untermstring 	//TODO

comment         //TODO
multlncomment   \/\*[\s\S]*?\*\/
untermcomment   //TODO

identifier      //TODO
illidentifier   //TODO: regular expression for an illegal identifier

yylineno = 1;

%%

 /* rules */

 /* Keywords */;
"if" 		{ updateCol(); return KWD_IF }
"else" 		{ updateCol(); return KWD_ELSE }
"while" 	{ updateCol(); return KWD_WHILE }
"int" 		{ updateCol(); return KWD_INT }
"string" 	{ updateCol(); return KWD_STRING }
"char" 		{ updateCol(); return KWD_CHAR }
"return" 	{ updateCol(); return KWD_RETURN }
"void" 		{ updateCol(); return KWD_VOID }

 /* Operators */;
\+		    { updateCol(); return OPER_ADD }
\-		    { updateCol(); return OPER_SUB }
\*		    { updateCol(); return OPER_MUL }
\/		    { updateCol(); return OPER_DIV }
\%		    { updateCol(); return  }
\<		    { updateCol(); return OPER_LT }
\>		    { updateCol(); return OPER_GT }
\<\=	    { updateCol(); return OPER_GTE }
\>\=	    { updateCol(); return OPER_LTE }
\=\=	    { updateCol(); return OPER_EQ }
\!\=	    { updateCol(); return OPER_NEQ }
\=		    { updateCol(); return OPER_ASGN }
\[		    { updateCol(); return LSQ_BRKT }
\]		    { updateCol(); return RSQ_BRKT }
\{		    { updateCol(); return LCRLY_BRKT }
\}		    { updateCol(); return RCRLY_BRKT }
\(		    { updateCol(); return LPAREN }
\)		    { updateCol(); return RPAREN }
\,		    { updateCol(); return  }
\;		    { updateCol(); return  }
\@		    { updateCol(); return  }
\+\+		{ updateCol(); return  }
\-\-		{ updateCol(); return  }
\&\&		{ updateCol(); return  }
\|\|		{ updateCol(); return  }
\!		    { updateCol(); return  }

 /* Identifiers */;
{identifier}    //TODO
{illidentifier} //TODO

 /* Constants */;
{integer}       //TODO
{integerlead0}  {updateCol(); yyerror = "Integers may not have leading zeros"; return ERROR} // Catching an integer that begins with 0 and generating an error. 
{character}     //TODO
{string}        {updateCol(); return processString();}
{untermstring}  {updateCol(); yyerror = "Unterminated string"; return ERROR;}
{multlnstring}  {updateCol(); countLines(); yyerror = "String spans multiple lines"; return ERROR;} // Catching a multi-line string and generating an error.

 /* Comments */;
{comment}       //TODO
{untermcomment} //TODO
{multlncomment} //TODO

 /* Other */;
{newline}       //TODO
{whitespace}    //TODO
.               {return ILLEGAL_TOK;}

%%

/* user routines */

void updateCol(){
    yycol = scancol;
    scancol += yyleng;
}

void countLines(){
    line_number = scanlineno
    scanlineno += line_number
}


int processString(){
	// TODO: Process a string literal and return the appropriate microsyntax.
}
