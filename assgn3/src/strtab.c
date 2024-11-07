#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>
#include<strtab.h>


param *working_list_head = NULL;
param *working_list_end = NULL;
table_node* current_scope = NULL;
struct strEntry strTable[MAXIDS];

// This can be called at the start of the program to clear the table if necessary.
void ST_init() {
    for (int i = 0; i < MAXIDS; i++) {
        strTable[i].id = NULL;
        strTable[i].scope = NULL;
        strTable[i].data_type = -1;
        strTable[i].symbol_type = -1;
    }
}

/* Provided is a hash function that you may call to get an integer back. */
unsigned long hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

int ST_insert(char *id, int data_type, int symbol_type, int* scope) {
    // Create a key based on concatenating the scope and id
    char key[MAXIDS];
    snprintf(key, sizeof(key), "%d%s", *scope, id);// convert pointer to string

    // Generates a hash value
    unsigned long index = hash((unsigned char *)key) % MAXIDS;

    // Loops though the symbol table to check for empty locations
    while (strTable[index].id != NULL) {
	/* Checks if index already exists in table
	// If current index has values equal to symbol to be inserted,
	// it is considered to already exist. */
	if (strcmp(strTable[index].id, id) == 0 && strcmp(strTable[index].scope, scope) == 0) {
	    return index;
	}
	// If index is already occupied, then perform linear probe
	index = (index + 1) % MAXIDS;
    }

    // Insert new symbol entry
    strTable[index].id = id;
    strTable[index].scope = scope;
    strTable[index].data_type = data_type;
    strTable[index].symbol_type = symbol_type;
    return index;
}

symEntry* ST_lookup(char *id) {
    // Create a key based on concatenating the scope and id
    char key[MAXIDS];
    snprintf(key, sizeof(key), "%d%s", current_scope, id);

    // Generate has value, same as in ST_insert
    unsigned long index = hash((unsigned char *)key) % MAXIDS;

    // Search for symbol in table. Empty spot means id is not present
    while (strTable[index].id != NULL) {
	/* Checks if symbol with equal scope and id exists already.
	// If so, symbol is found and index is returned. */
	if (strcmp(strTable[index].id, id) == 0) { //&& strcmp(strTable[index].scope, scope) == 0) {
	    return &strTable[index];
	}
	index = (index + 1) % MAXIDS;
    }
    
    // If while loop doesn't find the symbol then it is not present.
    return NULL;
}



void add_param(int data_type, int symbol_type) {
    //Allocate memory and set data_type/symbol_type
    param* new_param = (param*)malloc(sizeof(param));
    new_param->data_type = data_type;
    new_param->symbol_type = symbol_type;
    //Link new parameter to current working_list_head and then update working_list_head to point to new parameter
    new_param->next = working_list_head;
    working_list_head = new_param;
}



void connect_params(int index, int num_params){
    //Check if current scope has a parent (if we are in a function)
    if (current_scope->parent) {
        //Access parent (function) entry
        symEntry* func_entry = current_scope->parent->strTable[index];
        if (func_entry && func_entry->symbol_type == FUNCTION) {
            //Set Parameter variables
            func_entry->params = working_list_head;
            func_entry->size = num_params;
            //Reset head
            working_list_head = NULL; 
        }
    }
}


void new_scope(){
    //Allocate memory and set variables for a new scope (type:table_node)
    table_node* new_scope = (table_node*)malloc(sizeof(table_node));
    new_scope->parent = current_scope;
    new_scope->numChildren = 0;
    new_scope->first_child = NULL;
    new_scope->last_child = NULL;
    new_scope->next = NULL;
    
    //Check if current node has a child
    if (current_scope) {
        if (current_scope->first_child == NULL) {
            //Create new child
            current_scope->first_child = new_scope;
        } else {
            //Create new child (sibling)
            current_scope->last_child->next = new_scope;
        }
        //Update last_child pointer to new scope and update numChildren
        current_scope->last_child = new_scope;
        current_scope->numChildren++;
    }
    //Update current scope to the new_scope
    current_scope = new_scope;
}


void up_scope(){
    //Check if there is a parent
    if (current_scope && current_scope->parent) {
        //Go up to parent's scope
        current_scope = current_scope->parent;
    }
}

void print_sym_tab_recursive(table_node* node, int depth){
    //Base Case: if node is not found / is null
    if (!node) return;

    //Print Scope Depth
    printf("Scope Depth %d:\n", depth);
    //For each index of strTable, check if it exists and if so, print the data and parameter lists.
    for (int i = 0; i < MAXIDS; i++) {
        if (node->strTable[i]) {
            //Access and print data
            symEntry* entry = node->strTable[i];
            printf("ID: %s, Type: %d, Scope: %s, Symbol Type: %d, Size: %d\n",
                   entry->id, entry->data_type, entry->scope, entry->symbol_type, entry->size);
            //Access and print parameter list
            param* p = entry->params;
            while (p) {
                printf("  Param Type: %d, Param Symbol: %d\n", p->data_type, p->symbol_type);
                p = p->next;
            }
        }
    }
    //Recursion: Call self for child or sibling
    print_sym_tab_recursive(node->first_child, depth + 1);
    print_sym_tab_recursive(node->next, depth);
}

void print_sym_tab() {
    //Calls recursive function
    print_sym_tab_recursive(current_scope, 0);
}


