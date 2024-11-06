#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>
#include<strtab.h>

struct strEntry strTable[MAXIDS];
param *working_list_head = NULL;
param *working_list_end = NULL;
table_node* current_scope = NULL;

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

int ST_insert(char *id, int data_type, int symbol_type, int* scope){
    // Creates key and sets it to the concatenation of scope and id.
    char key[MAXIDS];
    snprintf(key, sizeof(key), "%s%s", scope, id);
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

symEntry *ST_lookup(char *id) {
    // Create key equal to concatenation of scope and id like in ST_insert
    char key[MAXIDS];
    snprintf(key, sizeof(key), "%s%s", id);
    // Generate has value, same as in ST_insert
    unsigned long index = hash((unsigned char *)key) % MAXIDS;

    // Search for symbol in table. Empty spot means id is not present
    while (strTable[index].id != NULL) {
	/* Checks if symbol with equal scope and id exists already.
	// If so, symbol is found and index is returned. */
	if (strcmp(strTable[index].id, id) == 0) { //&& strcmp(strTable[index].scope, scope) == 0) {
	    return index;
	}
	index = (index + 1) % MAXIDS;
    }
    
    // If while loop doesn't find the symbol then it is not present.
    return -1;
}


void add_param(int data_type, int symbol_type){

}


void connect_params(int index, int num_params){

}


void new_scope(){

}


void up_scope(){

}

void print_sym_tab(){

}


