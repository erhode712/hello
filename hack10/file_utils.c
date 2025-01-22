#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "file_utils.h"

char *getFileContents(const char *filePath){
    if(filePath == NULL){
        return NULL;
    }

    FILE *file = fopen(filePath, "r");
    if(file == NULL){
        return NULL;
    }
    int bufferSize = 2000;
    char *content = malloc(bufferSize);
    char buffer[2000];
    int contentLength = 0;

    while(fgets(buffer, sizeof(buffer), file) != NULL){
        int bufferLength = strlen(buffer);
        content = realloc(content, contentLength + bufferLength + 1);
        strcpy(content + contentLength, buffer);
        contentLength += bufferLength;
    }
    fclose(file);
    return content;
}

char **getFileLines(const char *filePath, int *numLines){
    if(filePath == NULL || numLines == NULL){
        return NULL;
    }

    FILE *file = fopen(filePath, "r");
    if(file == NULL){
        return NULL;
    }
    int numberOfLines = 0 ;
    char buffer[2000];
    int i;
    while(fgets(buffer, 2000, file) != NULL){
        numberOfLines++;
    }
    *numLines = numberOfLines;
    fclose(file);

    file = fopen(filePath, "r");

    char **fileLines = (char**)malloc(sizeof(char*) * numberOfLines);

    for(int i = 0; i < numberOfLines; i++){
        fileLines[i] = (char*)malloc(sizeof(char) * 2000);
    }

    i = 0;
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        char *string = strtok(buffer, "\0");
        strcpy(fileLines[i], string);
        rtrim(fileLines[i]);
        i++;
    }
    fclose(file);
    return fileLines;
}

void rtrim(char *str) {
    if(str == NULL){
        return;
    }
    int n = strlen(str);
    while(n >= 0 && isspace(str[n-1])){
        str[n-1] = '\0';
        n--;
    }
}

char * replaceCharCopy(const char *s, char oldChar, char newChar){
    if(s == NULL){
        return NULL;
    }

    char *copy = malloc(sizeof(char) * (strlen(s) + 1));
    int length = strlen(s);

    for(int i = 0; i < length; i++){
        if(s[i] == oldChar){
            copy[i] = newChar;
        }
        else{
            copy[i] = s[i];
        }
    }
    copy[length] = '\0';
    return copy;
}

char **lengthSplit(const char *s, int n){
    if(s == NULL || n <= 0){
        return NULL;
    }

    int length = strlen(s);
    int newSize = (length + n - 1)/n;
    char **copy = malloc(sizeof(char *) * newSize+1);

    int i;
    for (i = 0; i < newSize; i++) {
        copy[i] = malloc(sizeof(char) * (n + 1));
        int charLength;
        if(i == newSize - 1){
            if(length % n == 0){
                charLength = n;
            }
            else{
                charLength = length % n;
            }
        }
        else{
            charLength = n;
        }
        strncpy(copy[i], s + i * n, charLength);
        copy[i][charLength] = '\0';
    }
    copy[i] = NULL;
    return copy;
}

void removeChar(char *s, char c){
    if(s == NULL){
        return;
    }

    int length = strlen(s);
    int newIndex = 0;

    for(int i = 0; i < length; i++){
        if(s[i] != c){
            s[newIndex++] = s[i];
        }
    }
    s[newIndex] = '\0';
}



