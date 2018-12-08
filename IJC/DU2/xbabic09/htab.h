/**
*	@file	htab.h
*	@author	Radovan Babic, xbabic09
*	@date	24.4.2018
*	@brief Head file for work with hash table
*/

#ifndef htab
#define htab

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

struct htab_listitem {
 char *key;
 unsigned long data;
 struct htab_listitem *next;
};

typedef struct htab_t {
 unsigned long arr_size;
 unsigned long n;
 struct htab_listitem *ptr[];
} htab_t;

/**
*  @brief Initializaiton of htable
*
*  @param size of htab_t
*  @return htab_t*
*/
htab_t *htab_init(size);

/**
*  @brief Initializaiton and creation of new table from t2 data
*
*  @param new size of htab_t
*  @param second htab_t
*  @return htab_t*
*/
htab_t *htab_move(unsigned long newsize, htab_t *t2);

/**
*  @brief Number of items in table
*
*  @param htab_t
*  @return size_t
*/
size_t htab_size(htab_t *t);

/**
 *  @brief Number of items in array
 *
 *  @param htab_t
 *  @return size_t
 */
 size_t htab_bucket_count(htab_t *t);

 /**
  *  @brief Look for match in table according to key with list allocation
  *
  *  @param htab_t
  *  @param pointer to dynamically allocated string
  *  @return htab_listitem struct
  */
 struct htab_listitem *htab_lookup_add(htab_t *t, char *key);

 /**
  *  @brief Look for match in table according to key without list allocation
  *
  *  @param htab_t
  *  @param pointer to dynamically allocated string
  *  @return htab_listitem struct
  */
 struct htab_listitem *htab_find(htab_t *t, char *key);

 /**
  *  @brief Call function for all items in table without changing the table
  *
  *  @param htab_t
  *  @param void function
  */
 void htab_foreach(htab_t *t, void (*function)(char *, unsigned long));

 /**
  *  @brief Remove item from table
  *
  *  @param htab_t
  *  @param pointer to dynamically allocated string
  *  @return bool (if b == false then item was not found in table)
  */
 bool htab_remove(htab_t *t, char *key);

 /**
  *  @brief Delete all reocrds from table
  *
  *  @param htab_t
  */
 void htab_clear(htab_t *t);

 /**
  *  @brief Destructor of table (calling htab_clear() function)
  *
  *  @param htab_t
  */
 void htab_free(htab_t *t);

 /**
  *  @brief @brief Dispersing function for strings
  *
  *  @param String to disperse
  */
 unsigned int htab_hash_function(const char *str);

 /**
  * @brief Function for error message and error exit from program
  *
  * @param String with error message
  */
 void errorExit(const char *fmt, ...){
   va_list(ap);
   va_start(ap, fmt);
   vfprintf(stderr, fmt, ap);
   va_end(ap);
   exit(1);
 }
