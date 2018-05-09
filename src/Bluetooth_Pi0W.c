/*
 * Author: MSOE Team Xi Senior Design 2017
 * Date: 12/2017
 * Description: This file contains all the function prototypes for the Bluetooth Connection on the Pi3 side
 */

#include "Bluetooth_Pi0W.h"
#include "NetworkPacket.h"
#include "Button_ISR.h"

#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>
#include <bluetooth/sco.h>
#include <bluetooth/l2cap.h>

static char BluetoothAddr[] = "B8:27:EB:66:3C:01";
//static char* BluetoothAddr = "B8:27:EB:6E:73:23";
#define CHANNEL_NUMBER 1
static int rfcomm_sock;
static int rfcomm_client;
static int sco_sock;
static int sco_client;

struct timeval timer = {5,0};

void* handleBluetoothRecv(void* params)
{
	packet_t receivedData;
	clock_t start = clock();
	clock_t delta = 0;
	while ((((float)delta)/CLOCKS_PER_SEC) < 6)
	{
		printf("%f\n",((float)delta)/CLOCKS_PER_SEC);
		getBluetoothData(&receivedData);
		switch(receivedData.datatype)
		{
			case OBDII_DATA:
				break;
			case VOICE_DATA:
//				write(1,receivedData.data,receivedData.size);
				if (voiceCMD())
				{
				//	broadcast(&receivedData);
					//processVoiceCommands(&receivedData);
				}
				else
				{
					broadcast(&receivedData);
				}
				break;
		}
		delta = clock()-start;
	}
}

/*
 * Description:
 * @param: data
 * @return:
 */
void getBluetoothData(packet_t* data){
	int bytesRead = 0;
	bytesRead = recv(rfcomm_client, data, sizeof(packet_t),MSG_WAITALL);
}

int getBluetoothAudio(char* audio, int buffsize){
	fd_set socketReadSet;
	FD_ZERO(&socketReadSet);
	FD_SET(sco_client,&socketReadSet);
	if (select(sco_client,&socketReadSet,0,0,&timer))
	{
		perror("failed to recieve data");
		exit(EXIT_FAILURE);
	}
	int bytesRead = 0;
	printf("Sco client %d\n",sco_client);
	printf("Sco socket %d\n",sco_sock);
	printf("rfcomm client %d\n",rfcomm_client);
	printf("rfcomm socket %d\n",rfcomm_sock);
	bytesRead = recv(sco_client, audio, buffsize, 0);
	if (bytesRead < 0)
	{
		perror("read");
	}
	return bytesRead;
}

/*
 * Description: Sends data across the Bluetooth connection to the Pi0W
 * @param: data
 * @return:NULL
 */
void sendBluetoothData(packet_t* data){
	int dataWritten = 0;
	dataWritten = send(rfcomm_client, data, sizeof(packet_t),0);
}

void sendBluetoothAudio(const char* data, int buffsize){
	int dataWritten = 0;
	dataWritten = write(sco_client, data, buffsize);
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
	socklen_t opt = sizeof(raddr);

	if(hci_devinfo(0, &di) < 0) {
		perror("HCI device info failed");
		exit(EXIT_FAILURE);
	}

	//printf("Local device %s\n", batostr(&di.bdaddr));

	laddr.rc_family = AF_BLUETOOTH;
	bdaddr_t temp = {0,0,0,0,0,0};
	laddr.rc_bdaddr = temp;
	laddr.rc_channel = 1;

 	raddr.rc_family = AF_BLUETOOTH;
 	str2ba(BluetoothAddr,&raddr.rc_bdaddr);
 	raddr.rc_channel = CHANNEL_NUMBER;

 	// Create a rfcomm_socket to Bind with RFCOMM
 	if( (rfcomm_sock = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM)) < 0) {
 		perror("rfcomm_socket");
		exit(EXIT_FAILURE);
 	}

 	// Bind rfcomm_socket to Bluetooth Address using RFCOMM
 	if(bind(rfcomm_sock, (struct sockaddr *)&laddr, sizeof(laddr)) < 0) {
 		perror("bind");
		exit(EXIT_FAILURE);
	}

	listen(rfcomm_sock, 1);

	//printf("Remote device %s\n", argv[1]);

	rfcomm_client = accept(rfcomm_sock, (struct sockaddr *)&raddr,(socklen_t*) &opt);

	//BELOW HERE
	struct sockaddr_sco local,remote;
	// Create a rfcomm_socket to Bind with RFCOMM
 	if( (sco_sock = socket(AF_BLUETOOTH, SOCK_SEQPACKET, BTPROTO_SCO)) < 0) {
 		perror("sco_socket");
		exit(EXIT_FAILURE);
 	}
	memset(&local,0,sizeof(struct sockaddr_sco));
	local.sco_family = AF_BLUETOOTH;
	local.sco_bdaddr = {0,0,0,0,0,0};

 	// Bind rfcomm_socket to Bluetooth Address using RFCOMM
 	if(bind(sco_sock, (struct sockaddr *)&local, sizeof(laddr)) < 0) {
 		perror("bind");
		exit(EXIT_FAILURE);
	}
	listen(sco_sock, 5);
	opt = sizeof(struct sockaddr_sco);
	sco_client = accept(sco_sock, (struct sockaddr *)&remote, (socklen_t*)&opt);
	if (sco_client < 0)
	{
		perror("failed to accept connection");
		exit(EXIT_FAILURE);
	}
}

/*
 * Description: Disconnects Bluetooth, closes rfcomm_socket, and frees receivedAudio
 * @param: NULL
 * @return: NULL
 */
void closeBluetooth_Pi0W(){
	close(rfcomm_sock);
}
