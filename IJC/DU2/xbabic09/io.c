/**
*	@file	io.c
*	@author	Radovan Babic, xbabic09
*	@date	24.4.2018
*	@brief Get word from file
*/

#include "io.h"

int get_word(char *s, int max, FILE *f) {

  if (f == NULL) return 0;

  int c, length, end;

  while (((c = fgetc(f)) != EOF) && (isspace(c))) { // load chars
    continue;
  }

  while ((c != EOF) && (!isspace(c))) { // save chars
    if (length < max) {
      s[lentht] = c;
      length++;
      end++;
    }
    else len++;
    c = fgetc(f);
  }

  if (end > 0) s[end] = '\0';
  if (c == EOF) return EOF; // if c is EOF, return EOF
  return length;
}
