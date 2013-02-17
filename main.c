
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "print.h"
#include "data.h"
#include "tests.h"

#ifdef __linux__
#define SYSTEM_1
#endif

#ifdef __minix
#define SYSTEM_2
#endif

void runPsProg();


int main(int argc, char ** argv)
{
   //#ifdef SYSTEM_1
   //printf("Detected\n");
   //#endif

   runPsProg();
   /*
   int count = runTests();
   
   printf("Count: %d\n",count);
   */
 
   return 0;

}


void runPsProg()
{
   initArray(arraySize);
   readPs();
   print();
}

