#include <stdio.h>
#include "traversal.h"
#include "text.h"
#include "report.h"

int main(int argc, char *argv[])  {  
   report(argv[1]);
   if(argc < 2){ 
      printf("No argument passed through command line.\n");  
   }  
   else{  
      fileTraversal(".", argv[1]);
   }  
   printSorted();
   return 0;
}