#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "print.h"

#ifdef __linux__
#define SYSTEM_1
#endif

#ifdef __minix
#define SYSTEM_2
#endif

FILE * psAux;
int curPID;

void readPs(void);
void parsePsLine(char * bufLine);
void printTabs(int numTabs);
void printTree(int depth, int curID);
void print(void);
char *stripThree(char *string);

void readPs(void)
{
      char buf[1024];
      #ifdef SYSTEM_1
      psAux = popen("/bin/ps -aefc", "r");
      #endif
      #ifdef SYSTEM_2
      psAux = popen("ps -aef", "r");
      #endif

      if (psAux)
      {
          fgets(buf, sizeof(buf), psAux);
          while(fgets(buf, sizeof(buf), psAux))
          {
             if(checkFull() == 1)
             {expandArray(arraySize,expandSize);}
             parsePsLine(buf);
          }

     }
     pclose(psAux);
}

void parsePsLine(char * bufLine)
{
    	  char * processID; char * parentID; char * command; char * current;
    	  int c = 1; char * nextWordPtr; char * buf = bufLine; char * currentTemp;
          int PID; int PPID; char tempCMD[1024];

          #ifdef SYSTEM_1
          PID = 2; PPID = 3;
          #endif
          #ifdef SYSTEM_2
          PID = 3; PPID = 4; strcpy(tempCMD, bufLine);
          #endif

	      nextWordPtr = strtok(buf," ");

          while (nextWordPtr != NULL) {
          current = nextWordPtr;
          if(c == PID)
          {processID = nextWordPtr;}
          else if ( c == PPID)
          {parentID = nextWordPtr;}
           nextWordPtr = strtok(NULL," ");
           c++;
          }
          command = current;
          #ifdef SYSTEM_2
          nextWordPtr = strtok(tempCMD,":");
            
         while(nextWordPtr != NULL){
 
         currentTemp = nextWordPtr;
         nextWordPtr = strtok(NULL,":");
         }
           
          if(currentTemp != NULL)
          {command = stripThree(currentTemp);}
          #endif

          saveData(processID,parentID,command,array);
}

char *stripThree(char *string)
{
    return string+3;
}

void printTabs(int numTabs)
{
    int j;

    for(j = 0; j < numTabs; j++)
    {
        printf("\t");

    }

}

void printTree(int depth, int curID)
{
     int j;
     int r;

     for(j = 0; j < elements; j ++)
     {
        if(array[j].PPID == curID)
        {
           printTabs(depth);
           printf("%s [PID: %d] [PPID: %d]\n",array[j].CMD, array[j].PID, array[j].PPID);
           r = array[j].PID;
           printTree(depth+1,r);

        }
     }
     return;

}

void print(void)
{
   int j;
   int r;
   int p = 0;

   for(j = 0; j < elements; j ++)
   {

       if(array[j].PPID == p)
       {
          printf("%s [PID %d] [PPID %d]\n",array[j].CMD, array[j].PID, array[j].PPID);
          r = array[j].PID;
          printTree(2,r);
       }


   }
   free(array);

}
