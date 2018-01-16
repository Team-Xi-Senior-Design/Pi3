/* Author: MSOE Team Xi Senior Design 2017
 * Date: 12/2017
 * Description: This is the main c file for the bike side controller
 */

#include <stdlib.h>
#include <string.h>

#include "main.h"
#include "AD_HOC.h"
#include "Bluetooth_Pi0W.h"
#include <pthread.h>

int main(int argc, char* argv[]){
	initAD_HOC();
	initBluetooth_Pi0W();
	//initOBDII();
	pthread_t adhoc,bluepi;

	pthread_create(&adhoc, NULL, adhocThread, NULL);
	pthread_create(&bluepi, NULL, handleBluetoothRecv, NULL);

	pthread_exit(NULL);
	/**
	initOBDII();

	initBluetooth_Pi0W();
	initAD_HOC();

	packet_t *boi = malloc(sizeof(packet_t));
	while(1) {

		boi->datatype = OBDII_DATA;
		//boi->name = "From Bike w/ <3";
		char buff[2048];
		fgets(buff,32,stdin);
		memcpy(boi->name, buff, strlen(buff));
		boi->name[strlen(buff)-1] = 0;
		//printf("%s",boi->name);

		obd2data_t *boiz = malloc(sizeof(obd2data_t));
		boiz->fuelLevel = getFuelLevel();
		boiz->speed = getSpeed();
		boiz->rpm = getRPM();

		memcpy(boi->data, boiz, sizeof(obd2data_t));
		boi->size = sizeof(obd2data_t);

		sendBluetoothData(boi);
		free(boiz);

		receive(boi);
		printf("data from other bike: datatype: %d, name: %s, size: %d, data: %s\r\n",boi->datatype,boi->name,boi->size,boi->data);
	}
	freeOBDII();
	free(boi);
	//initAD_HOC();
	//broadcast("test",5);
	//int size;
	//size = receive(buff,5);
	//printf("%4s\n", buff);
	return (0);
	*/

	return (0);
}
