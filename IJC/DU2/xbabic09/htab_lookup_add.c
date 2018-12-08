/**
*	@file	htab_lookup_add.c
*	@author	Radovan Babic, xbabic09
*	@date	24.4.2018
*	@brief Look for match in table with memory allocation
*/

#include "htab.h"

struct htab_listitem *htab_lookup_add(htab_t *t, char *key) {

  if (t == NULL || key == NULL) return NULL;

  unsigned long index = htab_hash_function(key) % t->arr_size; //calculate index
  struct htab_listitem *temp_prev = NULL;
  struct htab_listitem *temp;
  temp = t->ptr[index];

  for (temp; temp != NULL; temp = temp->next) { //cycle thru whole list
    if (strcmp(key, temp->key) == 0) {
      temp->data++;
      return temp; //if match, return found item
    }
    temp_prev = temp; //list linking
  }

  //if there was no match, function will continue here

  //memory allocation for new item
  struct htab_listitem *newitem = (struct htab_listitem *) malloc(sizeof(struct htab_listitem));
  if (newitem == NULL) return NULL;

  //memory allocation for key in list
  newitem->key = (char *) malloc((strlen(key) + 1) * sizeof(char));
  if (newitem->key == NULL) {
    free(newitem);
    return NULL;
  }

  //set data to new item
  strcpy(newitem->key, key);
  newitem->data = 1;
  newitem->next = NULL;

  if (temp_prev == NULL) t->ptr[index] = newitem; //if list is empty, newitem is first
  else temp_prev->next = newitem; //if there is some record, newitem is last

  //increment records in list and return adress of new item
  t->n++;
  return newitem;
}
