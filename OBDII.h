/*
 * Author: MSOE Team Xi Senior Design 2017
 * Date: 12/2017
 * Description:
 */

#ifndef OBDII_H
#define OBDII_H

#ifdef OBDII_C
#define EXTERN_PFX
#else
#define EXTERN_PFX extern
#endif

/******************************
 * External Includes          *
 ******************************/
#include "Bluetooth_Pi0W.h"

/******************************
 * Function Prototypes        *
 ******************************/
int getFuelLevel(void);
int getRPM(void);
int getSpeed(void);
void initOBDII(void);

#endif
