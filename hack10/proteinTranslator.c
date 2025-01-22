#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "protein_utils.h"
#include "file_utils.h"

int main(int argc, char **argv) {
    if (argc != 3) {
        return 1;
    }

    char *inputFile = argv[1];
    char *outputFile = argv[2];

    FILE *fileIn = fopen(inputFile, "r");
    char *fileContents = getFileContents(inputFile);
    char *rna = replaceCharCopy(fileContents, 'T', 'U');
    removeChar(rna, '\n');
    int n = 3;
    char **result = lengthSplit(rna, n);
    char protein;
    fclose(fileIn);

    FILE *fileOut = fopen(outputFile, "w");
    int length = 0;

    while(result[length] != NULL){
        length++;
    }

    for(int i = 0; i < length; i++){
        protein = rnaToProtein(result[i]);
        if(protein != 'x'){
            fprintf(fileOut, "%c", protein);
        }
        free(result[i]);
    }
    free(result);
    free(rna);
    free(fileContents);
    fclose(fileOut);
    return 0;
}



