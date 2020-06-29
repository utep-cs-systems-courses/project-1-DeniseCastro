#include <stdio.h>
#include "tokenizer.c"


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').     Zero terminators are not printable (therefore false) */
int space_char(char c){
  int bool;
  if(c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == '\v' || c == '\f')
    bool = 1;
  else
    bool = 0;
    
    return bool;
}
/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){
  int bool;

  if(c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == '\v' || c == '\f')
    bool = 0;
  else
    bool = 1;

  return bool;
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char word_start(char *str){
  if(*str != '\0'){
    while(non_space_char(*str)){
      str++;
    }
    while(space_char(*str)){
      str++;
    }
    return *str;
  }
  str = 0;
  return *str;
p}

/* Returns a pointer to the first space character in
   zero-terminated str.  Return a zero pointer if 
   str does not contain any space characters. */
char *word_terminator(char *str){
   if(*str != '\0'){
    while(non_space_char(*str)){
      str++;
    }
    if(space_char(*str)){  
      return str;
    }
   }
   str = 0;
   return str;
}



/* Counts the number of words in the string argument. */
   int count_words(char *str){
     int counter;
     counter = 0;
     while(word_start(str) != '\0'){
       counter++;
     }
     return counter;
   }
/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
  int i;
  char *copy = malloc(len * sizeof(char)), temp;
  for(i=0; i < len-1; ++i)
    temp = *(copy+i) = *(inStr+i);
 
  return copy;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char** tokenize(char* str){
  char** token;
  char* temp, start, end;
  int words = count_words(str), length =0;

  token = malloc(words * sizeof(char*)), temp;

  temp = str;
  
  for(int i =0; i < words; i++){
    end = word_terminator(temp);
    do{
      start = temp;
      if(non_space_char(start)){
	start++;
	length++;
      }else
	  length = 0;
      
    }while(start != end);
    copy_str(temp, length);
    temp = word_start(end);
  }
  
  return token;
}

/* Prints all tokens. */
void print_tokens(char **tokens){
  do{
    puts(*tokens);
    *tokens++;
  }while(*tokens != 0);
  
}

/* Frees all tokens and the vector containing them. */
void free_tokens(char **tokens){
  while(*tokens != 0){
    free(*tokens);
    *tokens++;
  }
}


