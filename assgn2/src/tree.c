#include<tree.h>
#include<strtab.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<tokendef.h>

tree *ast;

const char *nodeTypeNames[] = {
    "PROGRAM", "DECLLIST", "DECL", "VARDECL", "TYPESPEC", "FUNDECL",
    "FORMALDECLLIST", "FORMALDECL", "FUNBODY", "LOCALDECLLIST",
    "STATEMENTLIST", "STATEMENT", "COMPOUNDSTMT", "ASSIGNSTMT",
    "CONDSTMT", "LOOPSTMT", "RETURNSTMT", "EXPRESSION", "RELOP",
    "ADDEXPR", "ADDOP", "TERM", "MULOP", "FACTOR", "FUNCCALLEXPR",
    "ARGLIST", "INTEGER", "IDENTIFIER", "VAR", "ARRAYDECL", "CHAR",
    "FUNCTYPENAME", "FUNHEAD"
};
#define MAX_NODEKIND (sizeof(nodeTypeNames) / sizeof(nodeTypeNames[0]))
// Creates the first node of the syntax tree
tree *maketree(int kind) {
    tree *newNode = (tree *)malloc(sizeof(struct treenode));
    newNode->nodeKind = kind;
    // numChildren updates as nodes are added.
    newNode->numChildren = 0;
    newNode->parent = NULL;
    return newNode;
}

// Creates a tree with leaf node of value val
tree *maketreeWithVal(int kind, int val) {
    // Calls maketree to create root
    tree *newNode = maketree(kind);
    // Adds leaf node
    newNode->val = val;
    return newNode;
}

// Adds new node to the tree.
void addChild(tree *parent, tree *child) {
    if (parent->numChildren < MAXCHILDREN) {
	// Increases child count and sets parent and child
        parent->children[parent->numChildren++] = child;
        child->parent = parent;
    }
    else {printf("Cannot add child to parent node\n"); exit(1);}
}


// Recursive function to print out the syntax tree
void printAst(tree *root, int nestLevel) {
    // Stops recursion once it hits the root node
    if (!root) return;

    // Ensure nodeKind is within bounds
    if (root->nodeKind < 0 || root->nodeKind >= MAX_NODEKIND) {
        printf("Unknown node kind\n");
        return;
    }

    // Prints out tabs based on nesting level of current node
    for (int i = 0; i < nestLevel; i++) printf("  ");

    // Prints out node kind
    printf("<%s", nodeTypeNames[root->nodeKind]);

    // Prints out value of node if applicable
    if (root->nodeKind == INTEGER || root->nodeKind == IDENTIFIER || root->nodeKind == TYPESPEC) {
        printf(", %d", root->val);
    }
    /*else if (root->nodeKind == IDENTIFIER) {
        if (root->val == -1) {
            printf(", -1");
        } else if (root->val < 0 || root->val >= MAXIDS) {
            printf(", Invalid val: %d", root->val);
        } else {
            printf(", %s", strTable[root->val]);
        }
    }
    */
    printf(">\n");

    // Recursively calls itself for each child, increasing nesting level
    for (int i = 0; i < root->numChildren; i++) {
        if (root->children[i] != NULL) {
            printAst(root->children[i], nestLevel + 1);
        }
    }
}
