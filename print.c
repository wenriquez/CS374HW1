#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "print.h"

FILE * psAux;
int curPID;

void readPs(void);
void parsePsLine(char * bufLine);
void printTabs(int numTabs);
void printTree(int depth, int curID);
void print(void);

void readPs(void)
{
      char buf[1024];

	 psAux = popen("/bin/ps -aefc", "r");
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
    	  char * processID;
    	  char * parentID;
    	  char * command;
    	  int c = 1;
          char * nextWordPtr;
    	  char * buf = bufLine;

	      nextWordPtr = strtok(buf," ");

          while (nextWordPtr != NULL) {

          if(c == 2)
          {processID = nextWordPtr;}
	      else if ( c == 3)
	      {parentID = nextWordPtr;}
	       else if ( c == 9)
	      {command = nextWordPtr;}
           nextWordPtr = strtok(NULL," ");
           c++;
          }
           saveData(processID,parentID,command,array);
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
