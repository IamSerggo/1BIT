/*                            steg_decode.c
 * =====================================================================
 *          IJC, DU_1 - priklad B
 *          Datum:  20.3.2018
 *          Autor:  Radovan Babic
 *          Login:  xbabic09
 * =====================================================================
 */

#ifndef STEG_DECODE
#define STEG_DECODE

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "bit_array.h"
#include "ppm.c"
#include "error.c"
#include "eratosthenes.c"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    warning_msg("Nespravny pocet parametrov\n");
    return EXIT_FAILURE;
  }

  struct ppm *image = ppm_read(argv[1]);
	if(!image) {
		warning_msg("Nepodarilo sa precitat subor\n");
  }

  unsigned long picture_size = image->xsize * image->ysize * 3;
	bit_array_create(array, picture_size);
  Eratosthenes(array);

  int bit[8];
  int cislo = 0;
  int j = 0, string_index = 0;
  char string[4269];
  unsigned long i = 11;

  for (; i < picture_size; i++) {
    if (!bit_array_getbit(array, i)) {
      bit[j] = image->data[i] & 1;
      j++;
    }
    if (j == 8) {
      cislo = 0;
      int exponent = 1;
      for (int c = 0; c < 8; c++) {
        cislo += bit[c] * exponent;
        exponent *= 2;
      }
      if (cislo == 0) {
        break;
      }
      string[string_index] = cislo;
      string_index++;
      j = 0;
    }
  }
  if (i == picture_size) {
    error_exit("Retazec nespravne ukonceny\n");
  }

  printf("%s\n", string);
	free(image);
  return EXIT_SUCCESS;
}

#endif
