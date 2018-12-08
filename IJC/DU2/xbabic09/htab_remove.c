/**
*	@file	htab.h
*	@author	Radovan Babic, xbabic09
*	@date	24.4.2018
*	@brief Remove item from table
*/

#include "htab.h"

bool htab_remove(htab_t *t, char *key) {

  if (t == NULL || key == NULL) return NULL;

  unsigned long index = htab_hash_function(key) % t->arr_size;
  struct htab_listitem *temp_prev = NULL;
  struct htab_listitem *temp;
  temp = t->ptr[index];

  while (temp != NULL) {
    if (strcmp(key, temp->key) == 0) {
      t->n--;
      free(temp->key)
    }
    temp = temp->next;
  }


}
