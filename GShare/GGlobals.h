/* 
 * File:   GGlobals.h
 * Author: karsten
 *
 * Created on 23. april 2011, 11:04
 */

#ifndef GGLOBALS_H
#define	GGLOBALS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <stdint.h>
#define PI 3.14159265

extern bool printbufferbool;
extern bool printposbufferbool;
extern uint32_t Gtime;
extern double MySin[360];
extern double MyCos[360];


#define TPIDMASK 0xFF000000
typedef uint32_t OBJID;
typedef uint32_t OBJTPID;
typedef uint32_t TIME;
#endif	/* GGLOBALS_H */

