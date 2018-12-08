/**
*	@file	io.h
*	@author	Radovan Babic, xbabic09
*	@date	24.4.2018
*	@brief Header file for  get_word function
*/

#include <stdio.h>
#include <ctype.h>

/**
*  @brief Get word from file f
*
*  @param array where word will be stored
*  @param max length of get_word
*  @param file to read from
*  @return length of loaded word
*/
int get_word(char *s, int max, FILE *f);
