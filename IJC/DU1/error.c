/*                            error.c
 * =====================================================================
 *          IJC, DU_1 - priklad B
 *          Modul pre chybove hlasenia
 *          Datum:  20.3.2018
 *          Autor:  Radovan Babic
 *          Login:  xbabic09
 * =====================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "error.h"

void warning_msg(const char *fmt, ...){
  va_list(ap);
  va_start(ap, fmt);
  fprintf(stderr, "CHYBA: \n");
  vfprintf(stderr, fmt, ap);
  va_end(ap);
}

void error_exit(const char *fmt, ...){
  va_list(ap);
  va_start(ap, fmt);
  fprintf(stderr, "CHYBA: \n");
  vfprintf(stderr, fmt, ap);
  va_end(ap);
  exit(1);
}
