/* Author: MSOE Team Xi Senior Design 2017
 * Date: 12/2017
 * Description: This is the main c file for the bike side controller
 */

#include "main.h"
#include "string.h"

int main(int argc, char* argv[]){
	initOBDII();

	initBluetooth_Pi0W();
	//printf(getAudio());

	//char buff[2048];

	while(1) {
		packet_t *boi;
		boi->datatype = OBDII_DATA;
		//boi->name = "From Bike w/ <3";
		memcpy(boi->name, "From Bike w/ <3", 15);

		obd2data_t *boiz;
		boiz->fuelLevel = getFuelLevel();
		boiz->speed = getSpeed();
		boiz->rpm = getRPM();

		memcpy(boi->data, boiz, sizeof(obd2data_t));
		boi->size = sizeof(obd2data_t);

		sendBluetoothData(boi);
	}
	freeOBDII();
	//initAD_HOC();
	//broadcast("test",5);
	//int size;
	//size = receive(buff,5);
	//printf("%4s\n", buff);
	return (0);
}
