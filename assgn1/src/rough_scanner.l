
/* definitions */

%{
#include <stdio.h>
#include "tokendef.h"

int scancol = 1;
int yycol = 1;
int scanlineno = 1;

char* yyerror;

void updateCol() {
    yycol += yyleng; // Update column based on length of matched text
}

void countLines() {
    scanlineno++; // Increment line number
    yycol = 1; // Reset column number
}

int processString() {
    // Check for illegal escape sequences
    for (int i = 0; i < yyleng; i++) {
        if (yytext[i] == '\\') {
            // Check if there is a next character
            if (i + 1 >= yyleng || (yytext[i + 1] != 'n' && yytext[i + 1] != 't' && 
                                    yytext[i + 1] != '"' && yytext[i + 1] != '\\')) {
                // Found an illegal escape sequence
                printf("<ERROR, Unrecognized escape character in String> : (%d:%d)\n", scanlineno, yycol);
                return ERROR;
            }
            // Increment i to skip the next character since it's part of the escape sequence
            i++;
        }
    }
    return STRCONST; // Adjust this based on your needs
}
%}

%%


[ \t]+         { /* Ignore whitespace */ }
\n             { countLines(); updateCol(); }


if             { updateCol(); return KWD_IF; }
else           { updateCol(); return KWD_ELSE; }
while          { updateCol(); return KWD_WHILE; }
int            { updateCol(); return KWD_INT; } 
string         { updateCol(); return KWD_STRING; }
char           { updateCol(); return KWD_CHAR; }
return         { updateCol(); return KWD_RETURN; }
void           { updateCol(); return KWD_VOID; }


[a-zA-Z][a-zA-Z0-9]*  { return ID; }


0[0-9]+       { yyerror = "Integers cannot have leading zeros"; return ERROR; } // handle just zero separately
0|[1-9][0-9]* { return INTCONST; }


'[^\\'\n]'     { return CHARCONST; }


\"([^\"\n\\]*(\\.[^\"\n\\]*)*)*\"  { return processString(); }


"+"            { return OPER_ADD; }
"-"            { return OPER_SUB; }
"*"            { return OPER_MUL; }
"/"            { return OPER_DIV; }
"%"            { return OPER_MOD; }
"<"            { return OPER_LT; }
">"            { return OPER_GT; }
"<="           { return OPER_LTE; }
">="           { return OPER_GTE; }
"=="           { return OPER_EQ; }
"!="           { return OPER_NEQ; }
"="            { return OPER_ASGN; }
"["            { return LSQ_BRKT; }
"]"            { return RSQ_BRKT; }
"{"            { return LCRLY_BRKT; }
"}"            { return RCRLY_BRKT; }
"("            { return LPAREN; }
")"            { return RPAREN; }
","            { return COMMA; }
";"            { return SEMICLN; }
"@"            { return OPER_AT; }
"++"           { return OPER_INC; }
"--"           { return OPER_DEC; }
"&&"           { return OPER_AND; }
"||"           { return OPER_OR; }
"!"            { return OPER_NOT; }


"/*"([^*]|\*+[^*/])*\*+"/"  { /* Ignore comments */ }
"/*"          { yyerror = "Unterminated comment"; while (input() != '\n'); countLines(); updateCol(); return ERROR; }
"\""          { yyerror = "Unterminated string"; while (input() != '\n'); countLines(); updateCol(); return ERROR; }


.              { return ILLEGAL_TOK; }

%%
