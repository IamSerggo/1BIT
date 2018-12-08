/*                            primes.c
 * =====================================================================
 *          IJC, DU_1 - priklad A
 *          Datum:  20.3.2018
 *          Autor:  Radovan Babic
 *          Login:  xbabic09
 * =====================================================================
 */

 #include <stdio.h>
 #include <limits.h>
 #include <math.h>
 #include "eratosthenes.c"
 #include "bit_array.h"
 #include "error.c"

 int main(void) {
   bit_array_create(array, 222000000);
   Eratosthenes(array);

   unsigned int i, j = 0;
   for (i = (unsigned)bit_array_size(array)-1; j < 10; i--) {
     if (!bit_array_getbit(array, i)) {
       j++;
     }
   }

   for (i = i; i < (unsigned)bit_array_size(array)-1; i++){
     if (!bit_array_getbit(array, i)) {
       printf("%d\n", i);
     }
   }
   return EXIT_SUCCESS;
 }
