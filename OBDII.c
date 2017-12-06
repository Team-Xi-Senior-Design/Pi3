/*
 * Author: MSOE Team Xi Senior Design 2017
 * Date: 12/2017
 * Description:
 */

#include "OBDII.h"

#include "SerialDriver.h"

#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 255

const char PORTNAME[] = "/dev/ttyUSB0";

const char OBD2_INIT[] = "AT SP 0\rE0\rR0\r";

static int SerialPortID;
static char * Buffer;

/*
 * Description: Returns the fuel level of the vehicle from OBDII as a percent out of 100
 * @param: NULL
 * @return: Fuel level of the vehicle (0-100)
 */
int getFuelLevel(){
/*	write(SerialPortID, "012F\r",6);
	while (read(SerialPortID,Buffer,BUFFER_SIZE) == 0);
	// (100A) / 255
	Buffer[8] = 0;
	return atoi(&Buffer[4]);
*/return 100;
}

/*
 * Description: Returns the RPM of the vehicle from OBDII
 * @param: NULL
 * @return: Rotations per minute of the pistons in the engine
 */
int getRPM(){

	write(SerialPortID, "010C\r",5);
	int bytesRead = 0;
	int responseRecieved = 0;
	while (!responseRecieved) {
		usleep(20000);
		bytesRead += read(SerialPortID, &Buffer[bytesRead], BUFFER_SIZE);
		if (bytesRead > 0) {
			responseRecieved = Buffer[bytesRead-1]!='\r';
		}
	}
	printf("Bytes Read: %d\n",bytesRead);
	printf("%s\n",Buffer);

	memset(Buffer,0,bytesRead);

	responseRecieved = 0;
	bytesRead = 0;
	while (!responseRecieved) {
		usleep(2000);
		bytesRead += read(SerialPortID, &Buffer[bytesRead], BUFFER_SIZE);
		if (bytesRead > 0) {
			responseRecieved = Buffer[bytesRead-1] != '\r';
		}
	}
	printf("Bytes Read: %d\n",bytesRead);
	printf("%s\n",Buffer);
	memset(Buffer,0,bytesRead);

	// (256A + B) / 4
	Buffer[7] = 0;
	return atoi(&Buffer[4]);
}

/*
 * Description: Returns the ground speed of the vehicle from OBDII
 * @param: NULL
 * @return: Ground Speed in MPH
 */
int getSpeed(){
/**
	write(SerialPortID, "010D",5);
	usleep((4*8)*200);
	read(SerialPortID, Buffer, BUFFER_SIZE);
	Buffer[7] = 0;
	// A
	int speed = atoi(&Buffer[4]) >> 24;
	return speed;
*/ return 54;
}

/*
 * Description: Initializes the OBDII interface
 * @param: NULL
 * @return: NULL
 */
void initOBDII(){
	SerialPortID = open(PORTNAME, O_RDWR | O_NOCTTY | O_SYNC);
	if (SerialPortID < 0)
	{
		printf("Something very bad happened, you should probably cry\n");
		return;
	}
	set_interface_attribs(SerialPortID, B38400, 0); // baud of 38400, no parity
	set_blocking(SerialPortID, 0); // no blocking

	Buffer = (char*)malloc(BUFFER_SIZE);

	write(SerialPortID,OBD2_INIT,strlen(OBD2_INIT)+1);

	usleep((50)*200);

	while(read(SerialPortID,Buffer,BUFFER_SIZE)==0);
	while(read(SerialPortID,Buffer,BUFFER_SIZE)!=0);
}

void freeOBDII() {
	close(SerialPortID);
	free(Buffer);
}
