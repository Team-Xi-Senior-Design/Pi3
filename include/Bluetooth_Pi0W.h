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
#include "NetworkPacket.h"

/*******************************************
 * Function Prototypes                     *
 *******************************************/
void getBluetoothData(packet_t*);
void sendBluetoothData(packet_t*);
int getBluetoothAudio(char*,int);
void sendBluetoothAudio(const char*,int);
void initBluetooth_Pi0W(void);
void closeBluetooth_Pi0W(void);
void* handleBluetoothRecv(void*);

#endif /* BLUETOOTH_PI0W_H */
