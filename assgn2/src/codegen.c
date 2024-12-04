#include "codegen.h"
#include "tree.h"

int reg_counter = 0;

char *get_next_register() {
	static char reg[4];
	snprintf(reg, sizeof(reg), "$t%d", reg_counter++);
	return reg;
}

int process(tree *node) {
	if (!node) return -1;

	switch (node->nodeKind) {
		case EXPRESSION: generate_expression(node); break;
		case ASSIGNSTMT: generate_assignment(node); break;
		case CONDSTMT: generate_conditional(node); break;
		case LOOPSTMT: generate_loop(node); break;
		case FUNDECL: generate_function(node); break;
		default:
			fprintf(stderr, "Unknown node kind.\n");
			break;
	}
	return 0;
}

void generate_expression(tree *node) {
}

void generate_assignment(tree *node) {
}

void generate_conditional(tree *node) {
}

void generate_loop(tree *node) {
}

void generate_function(tree *node) {
}
