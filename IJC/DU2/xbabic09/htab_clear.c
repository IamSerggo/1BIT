/**
*	@file	htab_clear.c
*	@author	Radovan Babic, xbabic09
*	@date	24.4.2018
*	@brief Clear table
*/

#include "htab.h"

 void htab_clear(htab_t *t) {

   if (t==NULL) errorExit("NULL pointer error!\n");

   unsigned long size = t->arr_size;
   struct htab_listitem *temp;


   for (unsigned long i = 0; i < size; i++) { //cycle thru array
     if (t->ptr[i] == NULL) continue; //skip iteration if item is empty

     temp = t->ptr[i];
     while (temp != NULL) { // cycle thru list, free memory and go to next item
       t->n--
       free(temp);
       free(temp->key);
       temp = temp->next;
     }
   }
 }
