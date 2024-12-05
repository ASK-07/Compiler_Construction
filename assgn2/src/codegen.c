#include <stdio.h>
#include "codegen.h"
#include "strtab.h"

#define MAX_TEMP_REGISTERS 10

static int labelCounter = 0;

static int regIndex = 0;

char* nextRegister() {
    static char registerName[4]; // Enough to hold "$tX\0"
    if (regIndex >= MAX_TEMP_REGISTERS) {
        fprintf(stderr, "Error: Out of temporary registers\n");
        exit(1);
    }
    snprintf(registerName, sizeof(registerName), "$t%d", regIndex++);
    return registerName;
}

// Frees the most recently allocated temporary register
void freeRegister() {
    if (regIndex > 0) {
        regIndex--;
    } else {
        fprintf(stderr, "Error: No registers to free\n");
        exit(1);
    }
}

// Helper to generate unique labels
char *newLabel() {
    static char label[16];
    snprintf(label, sizeof(label), "L%d", labelCounter++);
    return label;
}

// Generate code for conditional statements
void generate_conditional(tree *node, FILE *outputFile) {
    if (!node || node->nodeKind != CONDSTMT || node->numChildren < 3) return;

    // Generate labels
    char *elseLabel = newLabel();
    char *endLabel = newLabel();

    // Generate code for the condition (child 0)
    generate_expression(node->children[0], outputFile);
    char *condReg = nextRegister();
    fprintf(outputFile, "beqz %s, %s\n", condReg, elseLabel);

    // Generate code for the 'if' branch (child 1)
    generate_code(node->children[1], outputFile);
    fprintf(outputFile, "j %s\n", endLabel);

    // Generate code for the 'else' branch (child 2), if present
    fprintf(outputFile, "%s:\n", elseLabel);
    if (node->numChildren > 2 && node->children[2]) {
        generate_code(node->children[2], outputFile);
    }

    // End label
    fprintf(outputFile, "%s:\n", endLabel);
}

// Generate code for assignments
void generate_assignment(tree *node, FILE *outputFile) {
    if (!node || node->nodeKind != ASSIGNSTMT || node->numChildren != 2) return;

    // Generate code for the RHS (child 1)
    generate_expression(node->children[1], outputFile);
    char *rhsReg = nextRegister();

    // Generate code to store the result into the variable (child 0)
    if (node->children[0]->nodeKind == VAR) {
        fprintf(outputFile, "sw %s, %d($gp)\n", rhsReg, node->children[0]->val);
    } else {
        fprintf(stderr, "Error: Left-hand side of assignment is not a variable.\n");
    }
}

// Generate code for expressions
void generate_expression(tree *node, FILE *outputFile) {
    if (!node || node->nodeKind != EXPRESSION) return;

    if (node->numChildren == 1) {
        // Single child expression (e.g., a term or factor)
        generate_code(node->children[0], outputFile);
    } else if (node->numChildren == 3) {
        // Binary expression (e.g., addExpr + term)
        generate_expression(node->children[0], outputFile);
        char *leftReg = nextRegister();

        generate_expression(node->children[2], outputFile);
        char *rightReg = nextRegister();

        char *resultReg = nextRegister();
        switch (node->children[1]->val) {
            case OPER_ADD:
                fprintf(outputFile, "add %s, %s, %s\n", resultReg, leftReg, rightReg);
                break;

            case OPER_SUB:
                fprintf(outputFile, "sub %s, %s, %s\n", resultReg, leftReg, rightReg);
                break;
            case OPER_MULT:
                fprintf(outputFile, "mul %s, %s, %s\n", resultReg, leftReg, rightReg);
                break;

            case OPER_DIV:
                fprintf(outputFile, "div %s, %s, %s\n", resultReg, leftReg, rightReg);
                break;

            case OPER_MOD:
                fprintf(outputFile, "mod %s, %s, %s\n", resultReg, leftReg, rightReg);
                break;

            case OPER_LT:
                fprintf(outputFile, "cmp %s, %s\n", leftReg, rightReg);
                fprintf(outputFile, "setlt %s\n", resultReg);
                break;

            case OPER_GT:
                fprintf(outputFile, "cmp %s, %s\n", leftReg, rightReg);
                fprintf(outputFile, "setgt %s\n", resultReg);
                break;

            case OPER_LTE:
                fprintf(outputFile, "cmp %s, %s\n", leftReg, rightReg);
                fprintf(outputFile, "setlt %s\n", resultReg);
                break;

            case OPER_GTE:
                fprintf(outputFile, "cmp %s, %s\n", leftReg, rightReg);
                fprintf(outputFile, "setgt %s\n", resultReg);
                break;

            case OPER_EQ:
                fprintf(outputFile, "cmp %s, %s\n", leftReg, rightReg);
                fprintf(outputFile, "sete %s\n", resultReg);
                break;

            case OPER_NEQ:
                fprintf(outputFile, "cmp %s, %s\n", leftReg, rightReg);
                fprintf(outputFile, "setne %s\n", resultReg);
                break;

            case OPER_ASGN:
                fprintf(outputFile, "move %s, %s\n", leftReg, rightReg);
                break;

            case OPER_INC:
                fprintf(outputFile, "addi %s, %s, 1\n", leftReg, leftReg);
                break;

            case OPER_DEC:
                fprintf(outputFile, "addi %s, %s, -1\n", leftReg, leftReg);
                break;

            case OPER_AND:
                fprintf(outputFile, "and %s, %s, %s\n", resultReg, leftReg, rightReg);
                break;

            case OPER_NOT:
                fprintf(outputFile, "seq %s, %s, $zero\n", resultReg, leftReg);
                break;

            case OPER_AT:
                fprintf(outputFile, "lw %s, 0(%s)\n", resultReg, leftReg);
                break;

            case OPER_OR:
                fprintf(outputFile, "or %s, %s, %s\n", resultReg, leftReg, rightReg);
                break;
            default:
                fprintf(stderr, "Unhandled operator in generate_expression: %d\n", node->children[1]->val);
        }
    }
}

// Generate code for function calls
void generate_function_call(tree *node, FILE *outputFile) {
    if (!node || node->nodeKind != FUNCCALLEXPR) return;

    // Generate code for each argument (children)
    for (int i = 0; i < node->numChildren; i++) {
        generate_expression(node->children[i], outputFile);
        char *argReg = nextRegister();
        fprintf(outputFile, "addi $sp, $sp, -4\n");
        fprintf(outputFile, "sw %s, 0($sp)\n", argReg);
    }

    // Call the function
    fprintf(outputFile, "jal %s\n", node->val);

    // Clean up the stack after the call
    fprintf(outputFile, "addi $sp, $sp, %d\n", node->numChildren * 4);

    // Store the return value (if any) in a register
    char *resultReg = nextRegister();
    fprintf(outputFile, "move %s, $v0\n", resultReg);
}

// Generic function to dispatch based on node type
void generate_code(tree *node, FILE *outputFile) {
    if (!node) return;

    switch (node->nodeKind) {
	
	case PROGRAM:
		fprintf(outputFile, ".data\n");
		fprintf(outputFile, ".text\n");
		fprintf(outputFile, ".globl main\n");
		
		for (int i = 0; i < node->numChildren; i++) {
		    generate_code(node->children[i], outputFile);
		}
		break;
	case DECLLIST:
		for (int i = 0; i < node->numChildren; i++) {
		    generate_code(node->children[i], outputFile);

		}
		break;
	/*case DECL:
		if(node->numChildren > 0 && node->children[0] != NULL) {
			tree *child = node->children[0];
			switch (child->nodeKind) {
				case VARDECL:
					generate_var_declaration(child, outputFile);
					break;
				case FUNDECL:
					generate_function(child, outputFile);
					break;
				default:
					fprintf(stderr, "Unhandled declaration type: %d\n", child->nodeKind);
					break;
			}
		}
		break;*/
        case CONDSTMT:
            generate_conditional(node, outputFile);
            break;

        case ASSIGNSTMT:
            generate_assignment(node, outputFile);
            break;

        case EXPRESSION:
            generate_expression(node, outputFile);
            break;
	case ADDEXPR:
	case TERM:
	    break;
        case FUNCCALLEXPR:
            generate_function_call(node, outputFile);
            break;

        default:
            fprintf(stderr, "Unhandled nodeKind in generate_code: %d\n", node->nodeKind);
            break;
    }
}
