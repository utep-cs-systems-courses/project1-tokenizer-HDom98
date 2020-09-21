#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#define MAX 1000 // the max amount of chars

int main()
{
  char input[MAX];
  printf("> Type a string \n");
  
  printf("> ");
  scanf("%[^\n]", &input);

  printf("\n");
  printf("> %s\n", input);
  
  char *word = input;
  printf(" %d\n", count_words(word));
  printf(" %p",word_terminator(word));
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
  if(str[1] = '\0')
    {
      /*if there are no words return 0 pointer*/
      start = &str[1];
      return start;
    }
  for(int i = 1; i <= MAX; i++)
  {
    if((non_space_char(str[i]) == 1) && (space_char(str[i-1]) == 1))
    {
      start[currentStart] = &str[i];
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
  int currentTerm;
  for(int i = 1; i <= MAX; i++)
    {
      if((space_char(word[i]) == 1) && (non_space_char(word[i-1]))
	{/*if the current char is a space and the previous is a char that is the terminator*/
	  terminator = &word[i];
	  return terminator;
	}
    }
}

int count_words(char *str)
{
  int count = 1;/*Assuming there's at least 1 word*/
  
  for(int i = 1; i <= MAX; i++)
    {
      if(str[i] == '\0')
	{
	  count++;
	  return count;
	}else if((space_char(str[i-1])) == 1 && (non_space_char(str[i]) == 1))
	{
	  count++;
	}
    }
}

char *copy_string(char *inStr, short len)
{
  char *copiedStr;
  for(int i = 0; i <= len+1; i++)
    {
    if(inStr[i] == '\0')
      {
      copiedStr[i] = &inStr[i];
      return copiedStr;
      }else
      {
	copiedStr[i] = &inStr[i];
      }
    }
}

char **tokenize(char *str)
{
  short wordCount = count_words(str);
  char **token = malloc(wordCount*sizeof(char*);
  char *starts = word_start(str);
  
  for(int i = 0; i<= wordCount; i++)
    {
      
    }
}

void print_tokens(char **tokens){
  for(int i = 0; i < MAX; i++)
    {
      if((*tokens)[i] == '\0')
      {
	printf(" %s \n",(*tokens)[i]);
	break;
      }else
      {
	printf(" %s \n",(*tokens)[i]);
      }
  }
}

void free_tokens(char **tokens){
  for(int i = 0; i < MAX; i++)
    {//free the contents of tokens first
      if((*tokens)[i] == '\0')
	{
	  free(tokens[i]);
	  break;
	}else
	{
	  free(tokens[i]);
	}
    }
  free(*tokens);//free the pointer
}
