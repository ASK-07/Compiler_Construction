#ifndef CODEGEN_H
#define CODEGEN_H

#include "tree.h"
#include <stdio.h>

char* nextRegister();
void freeRegister();
char* newLabel();
void generate_conditional(tree *node, FILE *outputFile);
void generate_assignment(tree *node, FILE *outputFile);
void generate_expression(tree *node, FILE *outputFile);
void generate_function_call(tree *node, FILE *outputFile);
void generate_code(tree *node, FILE *outputFile);

#endif
