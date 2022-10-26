#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include "text.h"

#define MAX_PATH 1024
 
 
void fileTraversal(char *dir, char argument[])
{
   char path[MAX_PATH];
   struct dirent *dp;
   DIR *dfd;
 
   if ((dfd = opendir(dir)) == NULL) {
      fprintf(stderr, "fileTraversal: can't open %s\n", dir);
      return;
   }
 
   while ((dp = readdir(dfd)) != NULL) {
   
      if (dp->d_type == DT_DIR){
         path[0] = '\0';
         if (strcmp(dp->d_name, ".") == 0 || 
             strcmp(dp->d_name, "..") == 0)
            continue;
         sprintf(path, "%s/%s", dir, dp->d_name);
         fileTraversal(path, argument);
      }
      else{
         char newPath[100] = {0};
         strcat(newPath,dir);
         strcat(newPath,"/");
         strcat(newPath, dp->d_name);

         if(strncmp(dp->d_name + strlen(dp->d_name) - 4, ".txt", 4) == 0){
            replaceWord(newPath, argument);
         }
         
      }
      }
   closedir(dfd);
}

