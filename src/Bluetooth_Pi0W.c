/*
 * Author: MSOE Team Xi Senior Design 2017
 * Date: 12/2017
 * Description: This file contains all the function prototypes for the Bluetooth Connection on the Pi3 side
 */

#include "Bluetooth_Pi0W.h"
#include "NetworkPacket.h"
#include "VoiceCommands.h"
#include "Button_ISR.h"

#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>

static char* BluetoothAddr = "B8:27:EB:66:3C:01";
#define CHANNEL_NUMBER 1
static int sock;
static int client;


void* handleBluetoothRecv(void* params)
{
	packet_t receivedData;

	while (1)
	{
		getBluetoothData(&receivedData);
		fprintf(stderr,"recieved a packet\n");
		switch(receivedData.datatype)
		{
			case OBDII_DATA:
				break;
			case VOICE_DATA:
				write(1,receivedData.data,receivedData.size);
				if (voiceCMD())
				{
					broadcast(&receivedData);
					processVoiceCommands(&receivedData);
<<<<<<< HEAD
					//broadcast(&receivedData);
=======
					write(1,receivedData.data,receivedData.size);
>>>>>>> 1081ba7360be508be10bb0c20e3348d4357d4d07
				}
				else
				{
					//broadcast(&receivedData);
<<<<<<< HEAD
=======
					write(1,receivedData.data,receivedData.size);
>>>>>>> 1081ba7360be508be10bb0c20e3348d4357d4d07
				}
				break;
		}
	}

}

/*
 * Description:
 * @param: data
 * @return:
 */
void getBluetoothData(packet_t* data){
	int bytesRead = 0;
	memset(data, 0, sizeof(packet_t));
	while (bytesRead < sizeof(packet_t)) {
		bytesRead += read(client, &((char*)data)[bytesRead], sizeof(packet_t)-bytesRead);
	}
}

/*
 * Description: Sends data across the Bluetooth connection to the Pi0W
 * @param: data
 * @return:NULL
 */
void sendBluetoothData(packet_t* data){
	int dataWritten = 0;
	while (dataWritten < sizeof(packet_t)) {
		dataWritten += write(client,&((char*)data)[dataWritten],sizeof(packet_t)-dataWritten);
	}
}

/*
 * Description: Initializes the connection from the Pi3 to the Pi0 W
 * @param: NULL
 * @return: NULL
 */
void initBluetooth_Pi0W(){
	int d;
	struct sockaddr_rc laddr={0}, raddr={0};
	struct hci_dev_info di;
	int opt = sizeof(raddr);

	if(hci_devinfo(0, &di) < 0) {
		perror("HCI device info failed");
		exit(1);
	}

	//printf("Local device %s\n", batostr(&di.bdaddr));

	laddr.rc_family = AF_BLUETOOTH;
	laddr.rc_bdaddr = *BDADDR_ANY;
	laddr.rc_channel = 1;

 	raddr.rc_family = AF_BLUETOOTH;
 	str2ba(BluetoothAddr,&raddr.rc_bdaddr);
 	raddr.rc_channel = CHANNEL_NUMBER;

 	// Create a Socket to Bind with RFCOMM
 	if( (sock = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM)) < 0) {
 		perror("socket");
 	}

 	// Bind socket to Bluetooth Address using RFCOMM
 	if(bind(sock, (struct sockaddr *)&laddr, sizeof(laddr)) < 0) {
 		perror("bind");
		exit(1);
	}

	listen(sock, 1);

	//printf("Remote device %s\n", argv[1]);

	client = accept(sock, (struct sockaddr *)&raddr, &opt);

/*	// Connect to the Bluetooth Address using RFCOMM
	if(connect(sock, (struct sockaddr *)&raddr, sizeof(raddr)) < 0) {
		perror("connect");
		exit(1);
	}*/
}

/*
 * Description: Disconnects Bluetooth, closes socket, and frees receivedAudio
 * @param: NULL
 * @return: NULL
 */
void closeBluetooth_Pi0W(){
	close(sock);
}
