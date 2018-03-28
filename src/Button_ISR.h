/**
 *  @author: Team XI
 *  @file:   Button_ISR.h
 *
 *  @date 3/2018
 */
#ifndef BUTTON_ISR_H
#define BUTTON_ISR_H
/*****************************************
 *GPIO Port definishion                  *
 *****************************************/
#define GPIO_I
/*****************************************
 *  External Includes                    *
 *****************************************/
#include "AD_HOC.h"
#include "VoiceCommands.h"
#include <stdbool.h>

/****************************************
 *Function Prototypes                   *
 ****************************************/
void setupIO();
int  getIOPin(int);
void lobbySel(int );
bool voiceCMD();
void volModButton(int);

#endif /* end  BUTTON_ISR_H */

