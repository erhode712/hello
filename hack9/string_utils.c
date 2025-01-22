#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

#include "string_utils.h"

void replaceChar(char *s, char oldChar, char newChar){
    if(s == NULL){
        return;
    }
      int length = strlen(s);

    for(int i = 0; i < length; i++){
        if(s[i] == oldChar){
            s[i] = newChar;
        }
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

char * removeCharCopy(const char *s, char c){
    if(s == NULL){
        return NULL;
    }

    int length = strlen(s);
    int newSize = 0;
    for(int i = 0; i < length; i++){
        if(s[i] != c){
            newSize++;
        }
    }

    char *copy = malloc(sizeof(char) * (newSize + 1));
    int j = 0;
    for(int i = 0; i < length; i++){
        if(s[i] != c){
            copy[j] = s[i];
            j++;
        }
    }
    copy[j] = '\0';
    return copy;
}

char **lengthSplit(const char *s, int n){
    if(s == NULL || n <= 0){
        return NULL;
    }

    int length = strlen(s);
    int newSize = (length + n - 1)/n;
    char **copy = malloc(sizeof(char *) * newSize);

    for (int i = 0; i < newSize; i++) {
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
    return copy;
}











