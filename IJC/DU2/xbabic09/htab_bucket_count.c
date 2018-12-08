/**
 *	@file	htab_move.c
 *	@author	Radovan Babic, xbabic09
 *	@date	24.4.2018
 *	@brief Size of array
 */

 #include "htab.h"

 size_t htab_bucket_count(htab *t) {
   return t->arr_size;
 }
