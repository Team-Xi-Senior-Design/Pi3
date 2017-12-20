/*
 * Author: MSOE Team Xi Senior Design 2017
 * Date 12/2017
 * Description:
 */

#ifndef BLUETOOTH_PI0W_H
#define BLUETOOTH_PI0W_H

/*******************************************
 * External Includes                       *
 *******************************************/
#include "VoiceCommands.h"


/*******************************************
 * Function Prototypes                     *
 *******************************************/
char* getAudio(void);
void sendAudio(char*);
void sendData(char*);
void initBluetooth_Pi0W(void);
void closeVoiceCommands(void);


#endif /* BLUETOOTH_PI0W_H */
