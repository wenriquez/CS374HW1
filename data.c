#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "print.h"
#include "data.h"


int arraySize = 100;
int expandSize = 50;
int elements = 0;

PrintOut *array;

void saveData(char * processID, char * parentID, char * command, PrintOut *emptyArr);
void initArray(int size);
void expandArray(int curSize, int expSize);
int checkFull();


void initArray(int size)
{
   array = calloc(size, sizeof(PrintOut));
}


void expandArray(int curSize, int expSize)
{

    int totalSize = expSize + curSize;
	array = realloc(array, totalSize*sizeof(PrintOut));
	if (array == NULL)
    {
        printf("Cannot allocate more memory.\n");
        arraySize  = 0;
    }
    else
    {
        arraySize = totalSize;
    }
}

void saveData(char * processID, char * parentID, char * command, PrintOut *emptyArr)
{
    char temp [1024];

	strcpy(emptyArr[elements].CMD, command);
    strcpy(temp,emptyArr[elements].CMD);
    temp[strlen(temp)-1] = '\0'; //remove the \n character
    strcpy(emptyArr[elements].CMD,temp);
	emptyArr[elements].PID = atoi(processID);
	emptyArr[elements].PPID = atoi(parentID);
    elements++;
}

int checkFull()
{
  if(elements == (arraySize-2))
  {return 1;}
  else
  {return 0;}
}


