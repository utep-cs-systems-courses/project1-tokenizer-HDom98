#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#define MAX 1000 /* the max amount of chars*/

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
  if(str[1] == '\0')
    {
      /* if there are no words return 0 pointer */
      start = &str[0];
      return start;
    }
  for(int i = 0; i <= MAX; i++)
  {
    if((non_space_char(str[i]) == 1))
      {
      start = &str[i];
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
	{/* if the current char is a space and the previous is a char that is the terminator */
	  terminator = &word[i];
	  return terminator;
	}
    }
}

int count_words(char *str)
{
  int count = 1;/* Assuming there's at least 1 word */
  
  for(int i = 1; i <= MAX; i++)
    {
      if(str[i] == '\0')
	{
	 return count;
	}else if((space_char(str[i-1])) == 1 && (non_space_char(str[i]) == 1))
	{/* if the char before is a space and the current char isnt a space */
	  count++;
	}
    }
}

char *copy_string(char *inStr, short len)
{
  char *outStr = malloc(len * sizeof(char));
  for(int i = 0; i <= len; i++)
    {
    if(i == len)
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
  printf("tokenizing\n");
  short wordCount = count_words(str);
  char *tokenWords[wordCount];
  short wordLength;
  char **tokens;
  char *starts;

  for(int i = 0; i< wordCount && str[i] != '\0'; i++)
    {
      starts = word_start(str);
      wordLength = 0;
      
      for(int j = 0; j < MAX; j++)
	{/* measuring the length of the current word */
	  if(non_space_char(starts[j]) == 0)
	    {
	      wordLength++;
	      break;
	    }else
	    {
	      wordLength++;
	    }
	}
      
      tokenWords[i] = copy_string(starts, wordLength);
      printf("%s\n",tokenWords[i]);
      str = word_terminator(starts);
    }
  tokens = tokenWords;
  return tokens;
}

void print_tokens(char **tokens){
  while(tokens != NULL)/* print the tokens until it reaches NULL */
    {
      printf("%s\n",*tokens);
      tokens++;
    } 
}

void free_tokens(char **tokens){
  while(tokens != NULL)
    {
      free(*tokens);/* free the contents of tokens */
      tokens++;
    }
  free (tokens);/* free the pointer */
}
