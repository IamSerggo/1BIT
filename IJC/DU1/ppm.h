/*                            ppm.h
 * =====================================================================
 *          IJC, DU_1 - priklad B
 *          Rozhranie pre modul ppm.c
 *          Datum:  20.3.2018
 *          Autor:  Radovan Babic
 *          Login:  xbabic09
 * =====================================================================
 */
#ifndef PPM
#define PPM

#include "error.h"
#include "eratosthenes.h"

#define MAX_RESOLUTION (1000 * 1000 * 3)

struct ppm {
  unsigned xsize;
  unsigned ysize;
  char data[MAX_RESOLUTION]; // RGB bytes, max 3*xsize*ysize
};

struct ppm *ppm_read(const char *filename);

int ppm_write(struct ppm *p, const char *filename);

#endif
