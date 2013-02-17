#ifndef PRINT_H_INCLUDED
#define PRINT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE * psAux;
extern int curPID;

void readPs(void);
void parsePsLine(char * bufLine);
void printTabs(int numTabs);
void printTree(int depth, int curID);
void print(void);

#endif // PRINT_H_INCLUDED
