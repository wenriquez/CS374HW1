#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "print.h"
#include "tests.h"



int testArrayInit(void) {
	
    int expectedStartingArraySize = 100;
    int i;
    int countSize = 0;
    initArray(arraySize); // initalize array
     
    for(i = 0; i < arraySize; i++)
	{
        array[i];
        countSize++;     
    }
    
    if(countSize == arraySize) // check if space was properly allocated for 100 structs
    {return 0;} //true
    else
    {return 1;} //false   
    

}

int testReadPs(void) {
 
    int countSize = 0; // will test if the array was expanded past the starting size of 100
    int numRead = 0;
    
    
    readPs(); // assumes array has already been initalized previously

    numRead = elements; // number of items in the array, should be more than zero
    
    if(numRead > 0)
    {
      if( numRead > 100) // expand array had to work
      {return 0;}
      else if( numRead <= 100) // didn't need to expand
      {return 0;}
    }
    else
    {return 1;} // failed nothing was read 
    
    
    

}

int teststripSyms()
{
   char * expected = "9";
   char * input = "(9)";
   
   char * actual = stripSyms(input,"()");

   if(expected == input)
   {return 0;}
   else
   {return 1;} // failed to strip the () characters

}


int runTests() {
	
    int passCount = 0;
	
    passCount += testArrayInit();
    passCount += testReadPs();
    passCount += teststripSyms();
    free(array);
 
    return passCount;
}
