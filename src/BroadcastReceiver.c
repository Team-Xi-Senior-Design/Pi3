#include <errno.h>
#include <stdio.h>      /* for printf() and fprintf() */
#include <sys/socket.h> /* for socket(), connect(), sendto(), and recvfrom() */
#include <arpa/inet.h>  /* for sockaddr_in and inet_addr() */
#include <stdlib.h>     /* for atoi() and exit() */
#include <string.h>     /* for memset() */
#include <unistd.h>     /* for close() */
#include <netinet/in.h>
#include <sys/ioctl.h>

#include "BroadcastReceiver.h"

#define BROADCAST_PORT 25565
#define MAX_PACKET_SIZE 500

static int sock;
static struct sockaddr_in broadcastAddr; /* Broadcast Address */
static unsigned short broadcastPort = BROADCAST_PORT;     /* Port */


void receiveNetData(packet_t * data) {
/*	data->size = 0;
	int numBytes = 0;
	do
	{
		if (numBytes != 0) {
			fprintf(stderr,"IAMANGRY\n");
		}
		int bytes = read(sock, data, sizeof(packet_t));
		if (bytes>0) {
			numBytes += bytes;
			//fprintf(stderr,"recieved: %d bytes\n",numBytes);
		} else {
			perror("error receiving");
		}
		usleep(100);
	} while (numBytes < sizeof(packet_t)); */
	int bytesRead = 0;
	while(bytesRead < sizeof(packet_t))
	{
		bytesRead += recvfrom(sock, &data[bytesRead], sizeof(packet_t)-bytesRead, 0, NULL, 0);
		fprintf(stderr, "received: %d\n", bytesRead);
	}
}

void initReceiver() {
	if ((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) <0)
		perror("failed to make socket");
	memset(&broadcastAddr, 0, sizeof(broadcastAddr));
	broadcastAddr.sin_family = AF_INET;
	broadcastAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	broadcastAddr.sin_port = htons(broadcastPort);
	if (bind(sock, (struct sockaddr*) &broadcastAddr,sizeof(broadcastAddr)) < 0)
		perror("failed to bind");
	ioctl(sock,FIONBIO,1);
}

void cleanupReceiver() {
	close(sock);
}
