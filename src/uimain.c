#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define MAX 1000

int main(int argc, char *argv[])
{
  char input[MAX];
  char *toToken;
  char **tokens;

  while(input != "!quit")
    {
      printf(">Type a string \n");
  
      printf("> ");
      scanf("%[^\n]", input);
      printf("\n");
      toToken = input;
      //add to history here
      tokens = tokenize(toToken);
      printf("tokenized\n");
      
      print_tokens(tokens);
      free_tokens(tokens);
      //printf(" %s\n", input);
      
    }
  return 0;
}
