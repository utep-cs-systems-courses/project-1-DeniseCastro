####Project 1: Tokenizer
====================
  
This program is a string tokenizer. That include tokenizer.c and history.c  
  
Tokenizer.c takes a string of words and allocates each word as tokens.  
Includes methods:   
	 *space_char(char)	Returns true if passed a whitespace character.
	 *non_space_char(char)	 Returns true if passsed a non-whitespace
	 character.
	 *word_start(char*)	Returns a pointer to the first charcter of the
	 next word.
	 *word_terminator(char*)  Returns pointer to following word.
	 *cont_words(char*)	  Returns number of words in a string.
	 *copy_str(char*, short)  Returns new string, that is newly allocated.
	 *tokenize(char*) 	  Returns newly allocated vector of tokens
	 from a string.
	 *print_tokens(char**)	  Prints tokens of passed vector.
	 *free_tokens(char**)	  Frees tokens and vector containg them.

History.c uses a linkedlist refered to as list with nodes referred to as
item. It defines the basic methods of this list that keeps a history of
items.  
Includes methods:  
	 *init_history()	Initializes the linked list.
	 *add_history(List*, char*)	    Adds Item to the end of the list.
	 *get_history(List*, int)	    Gets the string stored in the node.
	 where Item id matches passed int
	 *print_history(List*) 	      Prints entire content of list.
	 *free_history(List*)	      Free the history list.
