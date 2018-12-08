/*                            bit_array.h
 * =====================================================================
 *          IJC, DU_1 - priklad A
 *          Definicia makier a inline funkcii pre pracu s bit_array
 *          Datum:  20.3.2018
 *          Autor:  Radovan Babic
 *          Login:  xbabic09
 * =====================================================================
 */


 #ifndef BIT_ARRAY
 #define BIT_ARRAY

 #include <stdio.h>
 #include <stdlib.h>
 #include <limits.h>
 #include "error.h"

 #define LONGSIZE (sizeof(unsigned long) * CHAR_BIT)


 typedef unsigned long * bit_array_t;


/*
 * Definicia makier a inline funkcie pre bit_array
 *
 * bit_array_create(nazov_pola, velkost)
 *    -vytori bitove pole longov 'nazov_pola' o velkosti 'velkost'
 *    -jeden prvok navyse pre ulozenie velkosti
 *
 * bit_array_size(nazov_pola)
 *    -vrati velkost bitoveho pola 'nazov_pola'
 *
 * bit_array_setbit(nazov_pola, index, vyraz)
 *    -nastavi v poli bitov bit na indexe 'index' na pozadovanu hodnotu
 *    -kontroluje velkost pola
 *
 * bit_array_getbit(nazov_pola, index)
 *    -ziska hodnotu pozadovaneho bitu na indexe 'index'
 */


  #define bit_array_create(array_name, size) \
  unsigned long array_name[((size % LONGSIZE == 0) ?  \
                          ((size / LONGSIZE)+1): \
                          ((size / LONGSIZE)+2))]; \
                          array_name[0] = size; \
                          for (unsigned long i = 1; i < size/LONGSIZE + 1; i++) { \
                            array_name[i] = 0; \
                          }

  #define bit_array_size(array_name) array_name[0]


  /* MACROS */
  #ifndef USE_INLINE
  #define bit_array_setbit(array_name, index, statement) \
    if ((index) >= (bit_array_size(array_name))) { \
      (error_exit("Index %lu mimo rozsah 0..%lu\n", (unsigned long)index, (bit_array_size(array_name))));\
    } \
    if (statement) { \
      ((array_name)[1 + ((index) / LONGSIZE)] |= 1ul << ((index) % LONGSIZE)); \
    } \
    else{ \
      ((array_name)[1 + ((index) / LONGSIZE)] &= ~(1ul << ((index) % LONGSIZE))); \
    }

  #define bit_array_getbit(array_name, index)  (((index) >= bit_array_size(array_name)) ? \
      (error_exit("Index %ld mimo rozsah 0..%ld\n", (index), (bit_array_size(array_name))), 0) : \
      ((array_name)[1 + ((index)/LONGSIZE)] & 1ul << ((index) % LONGSIZE)))
  #endif


  /* INLINE FUNCTIONS */
  #ifdef USE_INLINE
  inline void bit_array_setbit(bit_array_t array, unsigned long index, int statement){
    if (index >= bit_array_size(array)) {
      error_exit("Index %lu mimo rozsah 0..%lu\n", (unsigned long)index, (bit_array_size(array)));
    }

    if (statement) {
      array[1 + (index / LONGSIZE)] |= 1ul << (index % LONGSIZE);
    }
    else {
      array[1 + (index / LONGSIZE)] &= ~(1ul << (index % LONGSIZE));
    }
  }

  inline int bit_array_getbit(bit_array_t array, unsigned long index){
    if (index >= bit_array_size(array)) {
      error_exit("Index %lu mimo rozsah 0..%lu\n", (unsigned long)index, (bit_array_size(array)));
    }
    return array[1 + index / LONGSIZE] & 1ul << (index % LONGSIZE);
  }
  #endif
  #endif
