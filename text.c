#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "traversal.h"

#define TEMPTXT 1000

void replaceAll(char *str, const char *oldWord, const char *newWord, char currentDir[]);
int compare(const void *a, const void *b);
int i = 0;
int count;
char * updateArr[100];

char *upperCase(char oldStr[])
{
    char *upperString = oldStr;
    for (int x = 0; x < strlen(oldStr); x++)
    {
        upperString[x] = toupper(oldStr[x]);
    }
    return upperString;
}

void replaceWord(char path[], char word[]){

    FILE * fptr;
    FILE * ftmpo;
    char *updateFile;
    count = 0;
    char buffer[TEMPTXT];

    fptr  = fopen(path, "r");
    ftmpo = fopen("tempfile.tmp", "w"); 

    if (fptr == NULL || ftmpo == NULL)
    {
        fprintf(stderr,"\nUnable to open file.\n");
        return;
    }

    while ((fgets(buffer, TEMPTXT, fptr)) != NULL)
    {
        char newWord[strlen(word)];
        strcpy(newWord, word);
        upperCase(newWord);
        replaceAll(buffer, word, newWord, path);
        fputs(buffer, ftmpo);
    }

    updateFile = (char *)malloc(sizeof(char) * 100);
    sprintf(updateFile, "%d", count);
    strcat(updateFile, "\t");
    strcat(updateFile, path);
    strcat(updateFile, "\n");
    updateArr[i] = updateFile;
    if(updateArr == NULL){
        fprintf(stderr, "Ran out of memory, terminating!");
        exit(1);
    }

    i++;

    fclose(fptr);
    fclose(ftmpo);
    remove(path);
    rename("tempfile.tmp", path);

}

void replaceAll(char *str, const char *oldW, const char *newW, char currentDir[])
{
    char *pos, temp[TEMPTXT];
    int index = 0;
    int owlen;

    owlen = strlen(oldW);

    if (!strcmp(oldW, newW)) {
        exit(EXIT_SUCCESS);
    }

    while ((pos = strstr(str, oldW)) != NULL)
    {

        strcpy(temp, str);
        index = pos - str;
        str[index] = '\0';
        strcat(str, newW);
        strcat(str, temp + index + owlen);
        count++;
    }
}
int compare(const void *a, const void *b)
{
    return atoi(*(const char **)b) - atoi(*(const char **)a);
}
void printSorted()
{
    qsort(updateArr, i, sizeof(char *), compare);
    for (int j = 0; j < i; j++)
    {
        printf("%s", updateArr[j]);
    }
}