/*
 * Author: MSOE Team Xi Senior Deisgn 2017
 * Date: 12/2017
 * Description:
 */

#ifndef BUTTON_ISR_H
#define BUTTON_ISR_H

/*******************************************
 * External Includes                       *
 *******************************************/
#include "AD_HOC.h"
#include "VoiceCommands.h"
#include <stdbool.h>

/*******************************************
 * Funtion Prototypes                      *
 *******************************************/
void setupIO();
void lobbySel(int);
bool voiceCMD();
void volModButton(int);

#endif /* BUTTON_ISR_H */
