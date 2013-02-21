#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

typedef struct

        {
                int PID;

                int PPID;

                char CMD [1024];

        } PrintOut;


extern PrintOut *array;
extern int arraySize;
extern int expandSize;
extern int elements;

void saveData(char * processID, char * parentID, char * command, PrintOut *emptyArr);
void initArray(int size);
void expandArray(int curSize, int expSize);
int checkFull();
char *stripSyms(const char *string, const char *chars);



#endif // DATA_H_INCLUDED

