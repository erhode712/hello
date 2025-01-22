#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "string_utils.h"

int main(){
int numTestsPassed = 0;
int numTestsFailed = 0;

char str1[] = "hello world";
const char *result1 = "hell0 w0rld";
char c = 'o';
char h = '0';
printf("Original string: %s\n", str1);
printf("Test replaceChar:\n");
replaceChar(str1, c, h);
printf("Modified string: %s\n", str1);
if(strcmp(str1, result1) == 0){
    printf("PASSED\n");
    numTestsPassed++;
}
else{
    printf("FAILED\n");
    numTestsFailed++;
}

char string1[] = "hello world";
const char *resultString1 = "he11o wor1d";
char a = 'l';
char b = '1';
printf("Original string: %s\n", string1);
printf("Test replaceChar:\n");
replaceChar(string1, a, b);
printf("Modified string: %s\n", string1);
if(strcmp(string1, resultString1) == 0){
    printf("PASSED\n");
    numTestsPassed++;
}
else{
    printf("FAILED\n");
    numTestsFailed++;

}

char s1[] = "hello world";
const char *resultS1 = "qello world";
char e = 'h';
char f = 'q';
printf("Original string: %s\n", s1);
printf("Test replaceChar:\n");
replaceChar(s1, e, f);
printf("Modified string: %s\n", s1);
if(strcmp(s1, resultS1) == 0){
    printf("PASSED\n");
    numTestsPassed++;
}
else{
    printf("FAILED\n");
    numTestsFailed++;
}

char str2[] = "hello world";
const char *result2 = "hell0 w0rld";
printf("Original string: %s\n", str2);
printf("Test replaceCharCopy:\n");
char *strCopy = replaceCharCopy(str2, c, h);
if(strcmp(strCopy, result2) == 0){
    printf("PASSED\n");
    numTestsPassed++;
}
else{
    printf("FAILED\n");
    numTestsFailed++;
}
free(strCopy);

char string2[] = "goodbye world";
const char *resultString2 = "g00dbye w0rld";
printf("Original string: %s\n", string2);
printf("Test replaceCharCopy:\n");
char *string2Copy = replaceCharCopy(string2, c, h);
if(strcmp(string2Copy, resultString2) == 0){
    printf("PASSED\n");
    numTestsPassed++;
}
else{
    printf("FAILED\n");
    numTestsFailed++;
}
free(string2Copy);

char s2[] = "i love football";
const char *resultS2 = "i l0ve f00tball";
printf("Original string: %s\n", s2);
printf("Test replaceCharCopy:\n");
char *s2Copy = replaceCharCopy(s2, c, h);
if(strcmp(s2Copy, resultS2) == 0){
    printf("PASSED\n");
    numTestsPassed++;
}
else{
    printf("FAILED\n");
    numTestsFailed++;
}
free(s2Copy);

char str3[] = "hello world";
const char *result3 = "hell wrld";
printf("Original string: %s\n", str3);
printf("Test removeChar:\n");
removeChar(str3, c);
printf("Modified string: %s\n", str3);
if(strcmp(str3, result3) == 0){
    printf("PASSED\n");
    numTestsPassed++;
}
else{
    printf("FAILED\n");
    numTestsFailed++;
}

char string3[] = "i love books";
const char *resultString3 = "i lve bks";
printf("Original string: %s\n", string3);
printf("Test removeChar:\n");
removeChar(string3, c);
printf("Modified string: %s\n", string3);
if(strcmp(string3, resultString3) == 0){
    printf("PASSED\n");
    numTestsPassed++;
}
else{
    printf("FAILED\n");
    numTestsFailed++;
}

char s3[] = "how are you";
const char *resultS3 = "hw are yu";
printf("Original string: %s\n", s3);
printf("Test removeChar:\n");
removeChar(s3, c);
printf("Modified string: %s\n", s3);
if(strcmp(s3, resultS3) == 0){
    printf("PASSED\n");
    numTestsPassed++;
}
else{
    printf("FAILED\n");
    numTestsFailed++;
}

char str4[] = "hello world";
const char *result4 = "hell wrld";
printf("Original string: %s\n", str4);
printf("Test removeCharCopy:\n");
char *strCopy2 = removeCharCopy(str4, c);
if(strcmp(strCopy2, result4) == 0){
    printf("PASSED\n");
    numTestsPassed++;
}
else{
    printf("FAILED\n");
    numTestsFailed++;
}
free(strCopy2);

char string4[] = "i love tacos";
const char *resultString4 = "i lve tacs";
printf("Original string: %s\n", string4);
printf("Test removeCharCopy:\n");
char *strCopyString4 = removeCharCopy(string4, c);
if(strcmp(strCopyString4, resultString4) == 0){
    printf("PASSED\n");
    numTestsPassed++;
}
else{
    printf("FAILED\n");
    numTestsFailed++;
}
free(strCopyString4);

char s4[] = "school is cool";
const char *resultS4 = "schl is cl";
printf("Original string: %s\n", s4);
printf("Test removeCharCopy:\n");
char *strCopyS4 = removeCharCopy(s4, c);
if(strcmp(strCopyS4, resultS4) == 0){
    printf("PASSED\n");
    numTestsPassed++;
}
else{
    printf("FAILED\n");
    numTestsFailed++;
}
free(strCopyS4);

const char *str5 = "Hello World, how are you?";
const char *expectedResults[] = {
    "Hel", "lo ", "Wor", "ld,", " ho", "w a", "re ", "you", "?"    };
int n = 3;
printf("Test lengthSplit:\n");
char **splitStrings = lengthSplit(str5, n);
for(int i = 0; i < (strlen(str5) + n - 1)/n; i++){
    if(strcmp(splitStrings[i], expectedResults[i]) == 0){
    printf("PASSED\n");
    numTestsPassed++;
    }
    else{
    printf("FAILED\n");
    numTestsFailed++;
    }
    free(splitStrings[i]);
}
free(splitStrings);

const char *string5 = "Programming is fun!";
const char *expectedResultsString5[] = {
    "Prog", "ramm", "ing ", "is ", "fun", "!" };
int num = 4;
printf("Test lengthSplit:\n");
char **splitString5 = lengthSplit(string5, num);
for(int i = 0; i < (strlen(string5) + num - 1)/num; i++){
    if(strcmp(splitString5[i], expectedResultsString5[i]) == 0){
    printf("PASSED\n");
    numTestsPassed++;
    }
    else{
    printf("FAILED\n");
    numTestsFailed++;
    }
    free(splitString5[i]);
}
free(splitString5);

const char *s5 = "I love computer science";
const char *expectedResultS5[] = {
    "I lo", "ve c", "ompu", "ter ", "sci", "enc", "e" };
int number = 4;
printf("Test lengthSplit:\n");
char **splitS5 = lengthSplit(s5, number);
for(int i = 0; i < (strlen(s5) + number - 1)/number; i++){
    if(strcmp(splitS5[i], expectedResultS5[i]) == 0){
    printf("PASSED\n");
    numTestsPassed++;
    }
    else{
    printf("FAILED\n");
    numTestsFailed++;
    }
    free(splitS5[i]);
}
free(splitS5);

printf("Number of Tests passed: %d\n", numTestsPassed);
printf("Number of Tests failed: %d\n", numTestsFailed);

return 0;
}
