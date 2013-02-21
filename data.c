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
char *stripSyms(const char *string, const char *chars);


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
    char temp2 [1024];

    strcpy(temp2, processID);

    char * strippedPID = stripSyms(temp2,"()");

	strcpy(emptyArr[elements].CMD, command);
    strcpy(temp,emptyArr[elements].CMD);
    temp[strlen(temp)-1] = '\0'; //remove the \n character
    strcpy(emptyArr[elements].CMD,temp);
	emptyArr[elements].PID = atoi(strippedPID);
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

char *stripSyms(const char *string, const char *chars)
{
  char * newstr = malloc(strlen(string) + 1);
  int counter = 0;
 
  for ( ; *string; string++) {
    if (!strchr(chars, *string)) {
      newstr[ counter ] = *string;
      ++ counter;
    }
  }
 
  newstr[counter] = 0;
  return newstr;
}

