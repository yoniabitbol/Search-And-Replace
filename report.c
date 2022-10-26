#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include "text.h"

char *getcwd(char *buf, size_t size);

void report(char arg[]){
    char cwd[500];
    printf("Target string: %s\n", arg);
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
       printf("Search begins in the current working directory: %s\n", cwd);
    } else {
    perror("getcwd() error");
}
printf("** Search Report ** \n\nUpdates \t File Name\n");
}