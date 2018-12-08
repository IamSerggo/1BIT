/*                            eratosthenes.c
 * =====================================================================
 *          IJC, DU_1 - priklad A
 *          Modul pre vypocet prvocisiel pouzitim Eratostenova sita
 *          Datum:  20.3.2018
 *          Autor:  Radovan Babic
 *          Login:  xbabic09
 * =====================================================================
 */

 #include <math.h>
 #include "eratosthenes.h"

 void Eratosthenes(bit_array_t array){
   if (bit_array_size(array) < 2) {
     error_exit("V tomto rozsahu 0..%d nie je ziadne prvocislo\n", (unsigned long)bit_array_size(array));
   }

   unsigned long mySqrt = sqrt(bit_array_size(array) + 1);

   for (unsigned long i = 2; i <= mySqrt; i++) {
     if (bit_array_getbit(array, i) == 0) {
       for (unsigned long n = i*i; n < bit_array_size(array); n += i) {
         bit_array_setbit(array, n, 1);
       }
     }
   }
 }
