/* Author: MSOE Team Xi Senior Design 2017
 * Date: 12/2017
 * Description: This is the main c file for the bike side controller
 */

#include "main.h"

int main(int argc, char* argv[]){

//	initOBDII();
//	printf("Fuel Level: %d\n",getFuelLevel());
//	printf("RPM: %d\n", getRPM());
//	printf("Ground Speed [km/h]: %d\n", getSpeed());
//	freeOBDII();
	initAD_HOC();
	//broadcast("test",5);
	char buff[5];
	int size;
	//buff = receive(&size);
	return (0);
}
