/*                            ppm.c
 * =====================================================================
 *          IJC, DU_1 - priklad B
 *          Datum:  20.3.2018
 *          Autor:  Radovan Babic
 *          Login:  xbabic09
 * =====================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ppm.h"
#include "error.h"


struct ppm *ppm_read(const char *filename){

  FILE *file;
  unsigned xsize, ysize, maxcolor;
  char type[10] = {'\0'};

  file = fopen(filename, "r");
  if (file == NULL) {
    warning_msg("Subor %s sa nepodarilo otvorit\n", filename);
    return NULL;
  }

  int image_scan = fscanf(file, "%s\n%u %u\n%u\n ",type, &xsize, &ysize, &maxcolor);
  if (strcmp(type, "P6") == 1 || image_scan != 4) {
    warning_msg("Subor %s nie je v spravnom formate\n", filename);
    fclose(file);
    return NULL;
  }

  unsigned long picture_size = xsize * ysize * 3;

  struct ppm *image = malloc(picture_size + sizeof(struct ppm));

  if (image == NULL) {
    warning_msg("Nepodarilo sa alokovat pamat\n");
    free(image);
    fclose(file);
    return NULL;
  }
  else if (maxcolor != 255) {
    warning_msg("Nespravna najvyssia mozna farebna hlbka\n");
    free(image);
    fclose(file);
    return NULL;
  }

  image->xsize = xsize;
  image->ysize = ysize;

  int c;
  for (unsigned long i = 0; i < picture_size; i++) {
    c = getc(file);
    image->data[i] = c;
  }
  fclose(file);
  return image;

}

int ppm_write(struct ppm *p, const char *filename){

  FILE *file;

  file = fopen(filename, "w");
  if (file == NULL) {
    warning_msg("Subor %s sa nepodarilo otvorit\n", filename);
    return -420;
  }

  fprintf(file, "P6\n%u %u\n%u\n", p->xsize, p->ysize, 255U);

  fclose(file);
  return EXIT_SUCCESS;
}
