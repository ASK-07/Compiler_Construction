#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<../src/tree.h>
#include<../src/strtab.h>
#include<../src/codegen.h>

FILE *outputFile;

int main(int argc, char* argv[]) {
    if (argc != 2) {
	fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
	return 1;
    }
    FILE* inputFile = fopen(argv[1], "r");
    if (!inputFile) {
	perror("Error opening input file");
	return 1;
    }

    extern FILE* yyin;
    yyin = inputFile;

    outputFile = stdout;


    if (!yyparse()){
        /*printAst(ast, 1);*/
	generate_code(ast, outputFile);
/*
        printf("\n\nSYMBOL TABLE:\n");
        for(int i = 0; i < MAXIDS; i++){
            if(strTable[i].id != NULL){
                output_entry(i);
            }
        }
*/
    } else {
	fprintf(stderr, "Parsing failed.\n");
    }
    fclose(inputFile);
    return 0;
}
