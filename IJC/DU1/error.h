/*                            error.h
 * =====================================================================
 *          IJC, DU_1 - priklad B
 *          Hlavickovy subor pre chybove hlasnia - rozhranie pre error.c
 *          Datum:  20.3.2018
 *          Autor:  Radovan Babic
 *          Login:  xbabic09
 * =====================================================================
 */

#ifndef ERROR
#define ERROR

#include <stdarg.h>

/*
 * Funkcia pre vypisanie varovania
 * Neurcity pocet argumentov
 * Po skonceni funkcie program neskonci
 */
void warning_msg(const char *fmt, ...);

/*
 * Funkcia na vypisanie chybovej hlasky
 * Neurcity pocet argumentov
 * Po skonceni program ukonci prikazom exit(1)
 */
void error_exit(const char *fmt, ...);

#endif
