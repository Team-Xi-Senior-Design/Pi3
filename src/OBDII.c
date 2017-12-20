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

const char OBD2_INIT[] = "Z\rAT SP 0\rE0\rR0\r";

static int SerialPortID;
static char * Buffer;

/*
 * Description: Returns the fuel level of the vehicle from OBDII as a percent out of 100
 * @param: NULL
 * @return: Fuel level of the vehicle (0-100)
 */
int getFuelLevel(){
	// send the command to the ELM 327 to get fuel level
	write(SerialPortID, "012F\r",5);

	// setup some variables for making sure reids are good
	int bytesRead = 0;
	int responseRecieved = 0;
	int returnValue;

	// if the response hasn't finished
	while (!responseRecieved) {
		// wait a second for the hardware to get some data
		usleep(20000);
		// increase the bytes read, and read the serial data into the buffer
		bytesRead += read(SerialPortID, &Buffer[bytesRead], BUFFER_SIZE);
		// if we read something
		if (bytesRead > 0) {
			// check to see if the end of the transmission was recieved, and if it was, exit
			responseRecieved = Buffer[bytesRead-1]!='\r';
		}
	}

	// A*100/255
	returnValue = (strtol(&Buffer[11],NULL,16) * 100)/255;

	// clear the buffer
	memset(Buffer,0,bytesRead);

	// wait a bit
	usleep(2000);
	// clear the serial data
	while(read(SerialPortID, &Buffer[bytesRead], BUFFER_SIZE)!=0);
	// clear the buffer
	memset(Buffer,0,bytesRead);

	return returnValue;
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
	int returnValue;

	while (!responseRecieved) {
		usleep(20000);
		bytesRead += read(SerialPortID, &Buffer[bytesRead], BUFFER_SIZE);
		if (bytesRead > 0) {
			responseRecieved = Buffer[bytesRead-1]!='\r';
		}
	}

	// (256A + B) / 4
	returnValue = ((256*strtol(&Buffer[11],NULL,16))+strtol(&Buffer[14],NULL,16))/4;

	memset(Buffer,0,bytesRead);

	usleep(2000);
	while(read(SerialPortID, &Buffer[bytesRead], BUFFER_SIZE)!=0);
	memset(Buffer,0,bytesRead);

	return returnValue;
}

/*
 * Description: Returns the ground speed of the vehicle from OBDII
 * @param: NULL
 * @return: Ground Speed in MPH
 */
int getSpeed(){
	write(SerialPortID, "010D\r",5);
	int bytesRead = 0;
	int responseRecieved = 0;
	int returnValue;

	while (!responseRecieved) {
		usleep(20000);
		bytesRead += read(SerialPortID, &Buffer[bytesRead], BUFFER_SIZE);
		if (bytesRead > 0) {
			responseRecieved = Buffer[bytesRead-1]!='\r';
		}
	}
	// A
	returnValue = strtol(&Buffer[11],NULL,16);

	memset(Buffer,0,bytesRead);

	usleep(2000);
	while(read(SerialPortID, &Buffer[bytesRead], BUFFER_SIZE)!=0);
	memset(Buffer,0,bytesRead);

	return returnValue;

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
		printf("Failed to open the ELM327 device\n");
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
