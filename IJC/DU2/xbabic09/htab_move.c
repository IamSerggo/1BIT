/**
 *	@file	htab_move.c
 *	@author	Radovan Babic, xbabic09
 *	@date	24.4.2018
 *	@brief Move t2 table to new table
 */

#include "htab.h"

htab_t *htab_move(unsigned long newsize, htab_t *t2) {

  htab_t *newtab = htab_init(newsize);
  if (newtab == NULL) errorExit("Error while creating table!\n");

  unsigned long i, index;
  unsigned long t2_size = htab_bucket_count(t2);
  struct htab_listitem *temp = t2->ptr[i];
  struct htab_listitem *first, *next;

  for (i = 0; i < t2_size; i++) {
    if (t2->ptr[i] == NULL) continue; //skip iteration if list is empty

    for (temp; temp != NULL; ) { //cycle to go thru whole list
      index = hash_function(temp->key) % htab_bucket_count(newtab); //calculate index
      next = temp->next;

      // swap data from t2 table to newtab
      // t2 will stay empty
      if (newtab->ptr[index] == NULL) {
        newtab->ptr[index] = temp;
        newtab->ptr[index]->next = NULL;
      }
      else {
        first = newtab->ptr[index];
        newtab->ptr[index] = temp;
        temp->next = first;
      }

      temp = first;
      newtab->n++; // add one item to table
      t2->n--; // sub one item from table
    }

    t2->ptr[i] = NULL // delete pointer after every iteration
  }

  return newtab;
}
