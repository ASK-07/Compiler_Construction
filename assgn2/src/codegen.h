#ifndef CODEGEN_H
#define CODEGEN_H

#include "tree.h"
#include <stdio.h>

int process(tree *node);

void generate_expression(tree *node);
void generate_assignment(tree *node);
void generate_conditional(tree *node);
void generate_loop(tree *node);
void generate_function(tree *node);

#endif
