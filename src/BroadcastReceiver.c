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
	int bytesRead = recvfrom(sock, data, sizeof(packet_t), MSG_WAITALL, NULL, 0);
	if(bytesRead < 0)
	{
		perror("error receiving");
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
