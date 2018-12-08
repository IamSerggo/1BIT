/*                            eratosthebes.h
 * =====================================================================
 *          IJC, DU_1 - priklad A
 *          Hlavickovy subor pre vypocet Eratostenovo sito
 *          Rozhranie pre eratosthenes.c
 *          Datum:  20.3.2018
 *          Autor:  Radovan Babic
 *          Login:  xbabic09
 * =====================================================================
 */

 #ifndef ERATOSTHENES
 #define ERATOSTHENES

 #include <math.h>
 #include "bit_array.h"
 #include "error.h"

/*
 * Funkcia pre vypocet Eratostenovho sita
 * Pomocou algoritmu najdeme v poli prvocisla
 * Prvocisla maju hodnotu 0, ostatne bity budu na hodnote 1
 * Vyberieme najmensi index pre ktory plati, ze jeho hondota je 0
 * Nasledne kontrolujeme nasobky i a nastavime bity na hodnotu 1
 */
 void Eratosthenes(bit_array_t array);

 #endif
