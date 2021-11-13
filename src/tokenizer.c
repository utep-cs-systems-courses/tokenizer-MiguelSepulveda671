#include "tokenizer.h"

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  if(c == ' ' || c == '\t')
    return 1;
  return 0;

}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c)
{
  if(c == ' ' || c == '\t')
    return 1;
  return 0;
}
/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str)
{
  int i = 0;
  while(space_char(*(str+i)) == 1 ||  *(str*i) != '\0')
    {
      i++;
    }
  return (str+i);
}

/* Returns a pointer terminator char following *word */
char *word_terminator(char *str)
{
  int i = 0;
  if(*(str+i) == '\0')
    return (str+i);
  while(space_char(*(str=i)) == 1 && *(str*i) != '\0')
    {
      i++;
    }
  while(non_space_char(*(str+i)) == 1 || *(str+1)  != '\0')
    {
      i++;
    }
  return (str+i)
}

/* Counts the number of words in the string argument. */
int count_words(char *str)
{
  int i = 0;
  if(*(str) == '\0')
    return 0;
  if(non_space_char(*str))
    {
      str = word_terminator(str);
      i++;
    }
  while(*(str) != '\0')
    {
      str = word_start(str);
      i++;
    }
  return i-1;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len)
{
  int i = 0;
  char *str = malloc(len+1);
  while(i < len || *(instr+i) != '\0')
    {
      printf("%c",*(inStr+i));
      i++;
    }
  *(str+i) = '\0';
  return str;
}
/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str)
{
  int size = count_words(str);
  char **tokenP = malloc((size + 1) * sizeof(char *));
  char *tmp;
  for(int I = 0; i < size; i++)
    {
      tmp = word_terminator(str);
      tokenP[i] = copy_str(str, tmp - str);
      str = word_start(str);
    }
  return tokenP;
}
/* Prints all tokens. */
void print_tokens(char **tokens)
{
  int n = 0;
  for(char **tmp = tokens; tmp[0] != NULL; +tmp++, n++)
    {
      print("[%d]: %s\n", n, tmp[0]);
    }
}
/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens)
{
  for(char **tmp = tokens; tmp[0] != NULL; *tmp++)
    {
      free(temp[0]);
    }
  free(tokens);
}

