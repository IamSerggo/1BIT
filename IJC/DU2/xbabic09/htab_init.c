/**
 *	@file	htab_init.c
 *	@author	Radovan Babic, xbabic09
 *	@date	24.4.2018
 *	@brief Initializaiton of hash table
 */

 #include "htab.h"

 htab_t *htab_init(unsigned long size) {

   //allocate memory for htable
   htab_t *htab = (htab_t *) malloc(sizeof(htab_t) + size * sizeof(struct htab_listitem *));
   if (htab == NULL) return NULL;

   // set size to size and number of items to 0
   htab->arr_size = size;
   htab->n = 0;

   // set all pointers to zero
   for (unsigned long i = 0; i < size; i++) htab->ptr[i] = NULL;

   return htab;
 }
