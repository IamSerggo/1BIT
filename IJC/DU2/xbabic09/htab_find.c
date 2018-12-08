/**
*	@file	htab_find.c
*	@author	Radovan Babic, xbabic09
*	@date	24.4.2018
*	@brief Look for match in table according to key without list allocation
*/

#include "htab.h"

struct htab_listitem *htab_find(htab_t *t, char *key) {

  if (t == NULL || key == NULL) return NULL;

  unsigned long index = htab_hash_function(key) % t->arr_size;
  struct htab_t *temp;
  temp = t->ptr[index];

  while (temp != NULL) {
    if (strcmp(key, temp->key) == 0) {
      temp->data++;
      return temp;
    }
    temp = temp->next;
  }
  return NULL;
}
