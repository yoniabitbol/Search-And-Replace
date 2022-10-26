#ifndef text_H_
#define text_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *upperCase(char oldStr[]);
void replaceWord(char path[], char argument[]);
void replaceAll(char *str, const char *oldW, const char *newW, char currentDir[]);
void printSorted();
int compare(const void *a, const void *b);

#endif