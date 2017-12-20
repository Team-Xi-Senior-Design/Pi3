/* Author: MSOE Team Xi Senior Design 2017
 * Date: 12/2017
 * Description: This is the main c file for the bike side controller
 */

#include "main.h"

int main(int argc, char* argv[]){
	initOBDII();

	initBluetooth_Pi0W();
	//printf(getAudio());

	char buff[2048];

	while(1) {
		sprintf(buff,"Fuel Level: %d\n\r",getFuelLevel());
		printf(buff);
		sendData(buff);
		sprintf(buff,"RPM: %d\n\r", getRPM());
		printf(buff);
		sendData(buff);
		sprintf(buff,"Ground Speed [km/h]: %d\n\r", getSpeed());
		printf(buff);
		sendData(buff);
	}
	freeOBDII();
	return (0);
}
