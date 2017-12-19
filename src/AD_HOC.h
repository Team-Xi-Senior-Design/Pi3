/*
 * Author: MSOE Team Xi Senior Design 2017
 * Date: 12/2017
 * Description: This file contains the functions that will control all AD-HOC network communications
 */

#ifndef AD_HOC_H_
#define AD_HOC_H_

#ifdef AD_HOC_C
#define EXTERN_PFX
#else
#define EXTERN_PFX extern
#endif
/*****************************
 * External Includes         *
 *****************************/
#include "Bluetooth_Pi0W.h"

/*****************************
 * Function Prototypes       *
 *****************************/

void broadcast(char*,int);
void initAD_HOC();
void cleanupAD_HOC();
int receive(char*);
void test();

#endif /* AD_HOC_H_ */
