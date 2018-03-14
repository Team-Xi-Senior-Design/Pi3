/* Author: MSOE Team Xi Senior Design 2017
 * Date: 12/2017
 * Description: This file contains the functions that will control all AD-HOC network communications
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <netdb.h>
#include <sys/types.h>

#include "AD_HOC.h"

#include "BroadcastSender.h"
#include "BroadcastReceiver.h"
#include "Bluetooth_Pi0W.h"
/*
 * Description:
 * @param:
 * @return: NULL
 */
void broadcast(packet_t* packet){
	sendNetData(packet);
}

/*
 * Description:
 * @param:
 * @retrun: NULL
 */
void initAD_HOC(){
	initReceiver();
	initSender();
}

void cleanupAD_HOC() {
	cleanupReceiver();
}

/*
 * Description:
 * @param:
 * @return:
 */
void receiveAdhoc(packet_t* packet){
 	receiveNetData(packet);
}

void* adhocThread(void* params)
{
	packet_t data;
	while (1)
	{
		data.datatype=VOICE_DATA;
		memset(data.data,'a',10);
		data.data[10] = 0;
		data.size = 10;
//		receiveAdhoc(&data);
//		printf("%d\n", data.size);
//		printf("%s\n",data.data);
		switch(data.datatype)
		{
			case VOICE_DATA:
				sendBluetoothData(&data);
				//write(1,data.data,data.size);
				break;

			default://write(1,data.data,data.size);
				break;
		}
	}
}
