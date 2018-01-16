/*
 * Author: MSOE Team Xi Senior Design 2017
 * Date: 12/2017
 * Description:
 */

#ifndef VOICECOMMANDS_H
#define VOICECOMMANDS_H

#ifdef VOICECOMMANDS_C
#define EXTERN_PFX
#else
#define EXTERN_PRX extern
#endif /* VOICECOMMANDS_C */

/******************************************
 * External Includes                      *
 ******************************************/
#include "Bluetooth_Pi0W.h"
#include "Bluetooth_Phone.h"
#include "AD_HOC.h"
#include "NetworkPacket.h"

/******************************************
 * Function Prototypes                    *
 ******************************************/
void processVoiceCommands(packet_t*);
void gps(char*);
void join(char*);
void kick(char*);
void leave(void);
void make(char*, char*);
void volMod(int);

#endif /* VOICECOMMANDS_H */
