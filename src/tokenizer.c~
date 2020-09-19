#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"

int main()
{
  char input[1000];
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
  for(int i = 1; i < 1000; i++)
  {
    /* checks if the current char is a non space char and 
       if there is a space before the current char*/
    if((non_space_char(str[i])==1) && (space_char(str[i-1])==1))
    {
      start = &str[i];
      return start;
    }else if(str[i] == '\0')
    {
      //if theres only 1 word return original
      start = &str[0];
      return start;
    }
  }
}

char *word_terminator(char *word)
{
  char *terminator;
  for(int i = 1; i <= 1000; i++)
    {
      if(word[i] == '\0')
	{
	  terminator = &word[i];
	  return terminator;
	}
    }
}

int count_words(char *str)
{
  int count = 1;
  char *nextWord = word_start(str);
  
  if(&nextWord == &str)
    {//if there's only 1 word
      return count;
    }
  
  for(int i = 1; i < 1000; i++)
    {
      if(str[i] == '\0')
	{
	  return count;
	}else if((space_char(str[i-1])) == 1 && (non_space_char(str[i])))
	{
	  count++;
	}
    }
}

char *copy_string(char *inStr, short len)
{//allocate memory for strings
  char *copiedStr = malloc(len*sizeof(char));
  return copiedStr;
}

char **tokenize(char *str)
{
  char **token;
  int wordCount = count_words(str);
  for(int i = 0; i <= 1000; i++)
    {
      if(str[i] == '\0'){
	return token;
      }else
      {
	
      }
    }
}
