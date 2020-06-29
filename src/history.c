#include "history.h"
#include "malloc.h"

/* Initialize the linked list to keep the history. */
List* listHistory = 0;

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str){
  Item* newItem = malloc(sizeof(List));
  Item* lastItem = list;

  if(list == 0){
    list = newItem;
    return;
  }
  
  newItem -> root = str;
  lastItem -> next = 0;
  
  while(lastItem -> next != 0)
    lastItem -> next = newItem;
  
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){
  //Item* thisItem 
}

/*Print the entire contents of the list. */
void print_history(List *list){
  if(list == 0) return;
  print_history(list -> root);
  puts(root);
  print_history(root -> next);
  }

/*Free the history list and the strings it references. */
void free_history(List *list){
  if(list == 0) return;
  Item nextItem = list;

  while(nextItem != 0){
    free-history(nextItem -> next);
    free(list-> root);
    free(list);
    list = 0;
  }
  }

