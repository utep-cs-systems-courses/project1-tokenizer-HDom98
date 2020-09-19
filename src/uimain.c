#include <stdio.h>
#include <stdlib.h>

int main()
{
  char input[1000];
  printf("Type a string \n");
  
  printf("> ");
  scanf(" %s", input);

  printf("\n");
  printf(" %s\n", input);
  
  return 0;
}
