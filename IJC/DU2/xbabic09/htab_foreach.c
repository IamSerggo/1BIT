/**
*	@file	htab_foreach.c
*	@author	Radovan Babic, xbabic09
*	@date	24.4.2018
*	@brief Call function for all items in table without changing the table
*/

#include "htab.h"

void htab_foreach(htab_t *t, void (*func)(char *, unsigned long)) {

  if (t == NULL) return NULL;

  unsigned long size = t->arr_size;
  struct htab_listitem *temp;

  for (unsigned long i = 0; i < size; i++) {
    for (temp = t->ptr[i]; temp != NULL; temp = temp->next) {
      func(temp->key, temp->data);
    }
  }
}
