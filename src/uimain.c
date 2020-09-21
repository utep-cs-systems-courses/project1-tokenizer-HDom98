#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define MAX 1000
int main()
{
  char input[MAX];
  while(1)
    {
      printf("Type a string \n");
  
      printf("> ");
      scanf(" %s", input);
      if(input == '0')
	{
	  printf("Goodbye :)");
	  break;
	}
      //add to history here
      //tokenize here
      
      printf("\n");
      //print tokens here
      //free tokens here
      //printf(" %s\n", input);
      
    }
  return 0;
}
