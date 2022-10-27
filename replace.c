#include <stdio.h>
#include "traversal.h"
#include "text.h"
#include "report.h"

int main(int argc, char *argv[])  {
   if(argc < 2){ 
      fprintf(stderr, "No argument passed through command line.\n"); 
      return 1;
   }  
   else{  
      fileTraversal(".", argv[1]);
   }  
   printSorted();
   report(argv[1]);
   return 0;
}