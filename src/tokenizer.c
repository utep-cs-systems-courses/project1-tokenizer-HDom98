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
  if(str[1] == '\0')
    {
      /*if there are no words return 0 pointer*/
      start = &str[0];
      return start;
    }
  for(int i = 0; i <= MAX; i++)
  {
    if((non_space_char(str[i]) == 1))
      {
      start = &str[i];
      return start;
      }/*else if((non_space_char(str[0]) == 1))
      {
	start = &str[0];
	return start;
      }*/
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
  char *outStr = malloc(len * sizeof(char));
  for(int i = 0; i <= len+1; i++)
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
  printf("inside tokenize\n");
  short wordCount = count_words(str);
  char *tokenWords[wordCount];
  short wordLength;
  char **tokens;
  char *starts;

  tokenWords[wordCount] = '\0';
  for(int i = 0; i< wordCount && str[i] != '\0'; i++)
    {
      starts = word_start(str);
      printf(" %s\n", starts);
      wordLength = 0;
      for(int j = 0; j < MAX; j++)
	{/* measuring the length of the current word */
	  if(non_space_char(starts[j]) == 0)
	    {
	      break;
	    }else
	    {
	      wordLength++;
	    }
	}
      
      printf("word length is %d \n",wordLength);
      
      tokenWords[i] = (copy_string(starts, wordLength));
      str = word_terminator(starts);
      *tokens[i] = &tokenWords[i];
    }
  printf("finished tokenize\n");
  
  return tokens;
}

void print_tokens(char **tokens){
  //printf(" %s\n",tokens[0]);
  for(int i = 0; i < MAX; i++)
    {
      if((*tokens)[i] == '\0')
      {
	break;
      }else
      {
	printf(" %s \n",tokens[i]);
      }
  }
  
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
	  (*tokens)++;
	}
    }
  free (tokens);/*free the pointer*/
}
