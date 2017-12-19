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

/*
 * Description:
 * @param:
 * @return: NULL
 */
void broadcast(char* voice, int size){
	sendNetData(voice,size);
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
char* receive(int*size){
 	return receiveNetData(size);
}
