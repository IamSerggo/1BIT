/**
 *	@file	htab_hash_function.c
 *	@author	Radovan Babic, xbabic09
 *	@date	24.4.2018
 *	@brief Dispersing function for strings
 */

#include "htab.h"

unsigned int htab_hash_function(const char *str) {
  unsigned int h = 0;
  const unsigned char *p;
  for (p=(const unsigned char*)str; *p!='\0'; p++) h = 65599*h + *p;
  return h;
}
