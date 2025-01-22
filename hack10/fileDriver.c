#include "file_utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
    const char *filePath = "./examples/dnaSample002.txt";
    printf("Tesing getFileLines\n");
    int numLines;
    char **fileLines = getFileLines(filePath, &numLines);
    for(int i = 0; i < numLines; i++){
        printf("%s\n", fileLines[i]);
        free(fileLines[i]);
    }
    free(fileLines);
    printf("Lines: %d\n", numLines);
    return 0;
}
