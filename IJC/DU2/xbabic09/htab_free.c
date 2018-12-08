/**
*	@file	htab_free.c
*	@author	Radovan Babic, xbabic09
*	@date	24.4.2018
*	@brief Clear table and free alocated space
*/

void htab_free(htab_t *t) {
	htab_clear(t);
    free(t);
}
