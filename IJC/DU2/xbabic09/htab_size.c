/**
 *	@file	htab_size.c
 *	@author	Radovan Babic, xbabic09
 *	@date	24.4.2018
 *	@brief Size of htab
 */

 #include "htab.h"

 size_t htab_size(htab_t *t) {
   return t->n;
 }
