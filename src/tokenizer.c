#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#define MAX 1000 /* the max amount of chars*/

int main()
{
  char input[MAX];
  printf("> Type a string \n");
  
  printf("> ");
  scanf("%[^\n]", &input);
  printf("\n");
  
  char *toToken;
  toToken = input;
  printf("stored to pointer\n");
  
  char **tokens;
  tokens = tokenize(input);
  printf("tokenized\n");
  
  print_tokens(tokens);
  printf("finished printing\n");
  
  free_tokens(tokens);
  printf("freed tokens\n");
  
  return 0;
}

int space_char(char c)
{
  if( c == ' ' || c == '\t')
  {
    return 1;
  }else
  {
    return 0;
  }
}

int non_space_char(char c)
{
  if( c != ' ' && c != '\t' && c!= '\0')
  {
    return 1;
  }else
  {
    return 0;
  }
}

char *word_start(char *str)
{
  char *start;
  int currentStart = 0;
  if(str[1] == '\0')
    {
      /*if there are no words return 0 pointer*/
      start = &str[1];
      return start;
    }
  for(int i = 1; i <= MAX; i++)
  {
    if((non_space_char(str[i]) == 1) && (space_char(str[i-1]) == 1))
    {
      start[currentStart] = str[i];
      currentStart++;
    }else if(str[i] == '\0')
      {//returns pointer of all word starts
      return start;
    }
  }
}

char *word_terminator(char *word)
{
  char *terminator;
  for(int i = 1; i <= MAX; i++)
    {
      if((space_char(word[i]) == 1) && (non_space_char(word[i-1]) == 1))
	{/*if the current char is a space and the previous is a char that is the terminator*/
	  terminator = &word[i];
	  return terminator;
	}
    }
}

int count_words(char *str)
{
  printf("inside count\n");
  int count = 1;/*Assuming there's at least 1 word*/
  
  for(int i = 1; i <= MAX; i++)
    {
      if(str[i] == '\0')
	{
	 return count;
	}else if((space_char(str[i-1])) == 1 && (non_space_char(str[i]) == 1))
	{
	  count++;
	}
    }
}

char *copy_string(char *inStr, short len)
{
  printf("inside copy\n");
  char *outStr = malloc(len*sizeof(char));
  for(int i = 0; i <= len; i++)
    {
    if(inStr[i] == '\0')
      {
      outStr[i] = '\0';
      return outStr;
      }else
      {
	outStr[i] = inStr[i];
      }
    }
}

char **tokenize(char *str)
{
  printf("inside tokenize\n");
  short wordCount = count_words(str);
  printf("counted words\n");
  char *tokenWords[wordCount];
  short wordLength;
  printf("made *\n");
  char **tokens = &tokenWords[0];
  printf("made **\n");
  char *starts;

  printf("called values\n");
  starts = word_start(str);/* pointer to all the starts */
  for(int i = 0; i< wordCount; i++)
    {
      wordLength = 0;
      for(int j = 0; j < MAX; j++)
	{/* measuring the length of the current word */
	  if(non_space_char(str[j]) == 0)
	    {
	      break;
	    }else
	    {
	      wordLength++;
	    }
	}
      
      printf("word length is %d \n",wordLength);
      
      str = word_terminator((starts+i));/* stuck here */ 
      tokenWords[i] = (copy_string(str, wordLength));/* and here */
    }
  printf("finished tokenize\n");
  return tokens;
}

void print_tokens(char **tokens){
  printf("inside print\n");
  for(int i = 0; i < MAX; i++)
    {
      if(tokens[i] == NULL)
      {
	break;
      }else
      {
	printf(" %s \n",(*tokens)[i]);
      }
  }
  printf("finished string\n");
}

void free_tokens(char **tokens){
  printf("inside free\n");
  for(int i = 0; i <= MAX; i++)
    {/*free the contents of tokens first*/
      if(tokens[i] == NULL)
	{
	  free(tokens[i]);
	  break;
	}else
	{
	  free(tokens[i]);
	  *tokens++;
	}
    }
  free (*tokens);/*free the pointer*/
}
