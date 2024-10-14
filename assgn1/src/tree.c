#include<tree.h>
#include<strtab.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<tokendef.h>

tree *ast;

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


// This is a recursive function to print out the syntax tree
void printAst(tree *root, int nestLevel) {
    // Stops recursion once it hits the root node
    if (!root) return;

    // Prints out tabs based on nesting level of current node
    for (int i = 0; i < nestLevel; i++) printf("  ");

    // Prints out node kind
    printf("<%d", root->nodeKind);

    // Prints out value of node if applicable
    if (root->nodeKind == IDENTIFIER || root->nodeKind == INTEGER) {
        printf(", %d", root->val);
    }
    printf(">\n");

    // Recursively calls itself for each child, increasing nesting level
    for (int i = 0; i < root->numChildren; i++) {
        printAst(root->children[i], nestLevel + 1);
    }
}
