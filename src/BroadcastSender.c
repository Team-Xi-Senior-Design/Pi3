#include <errno.h>
#include <stdio.h>      /* for printf() and fprintf() */
#include <sys/socket.h> /* for socket() and bind() */
#include <arpa/inet.h>  /* for sockaddr_in */
#include <stdlib.h>     /* for atoi() and exit() */
#include <string.h>     /* for memset() */
#include <unistd.h>     /* for close() */

#include "BroadcastSender.h"

#define MAX_PACKET_SIZE	1500

static int sock;				/* Socket */
static struct sockaddr_in broadcastAddr;	/* Broadcast address */
static char *broadcastIP = "169.254.255.255";	/* IP broadcast address */
static unsigned short broadcastPort = 25565;    /* Server port */
static int broadcastPermission;          	/* Socket opt to set permission to broadcast */

void initSender() {
	if((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
		perror("failed to open socket");
	broadcastPermission = 1;
	if(setsockopt(sock, SOL_SOCKET, SO_BROADCAST, (void*) &broadcastPermission, sizeof(broadcastPermission)) < 0)
		perror("failed to set socket options");
	/* Construct local address structure */
	memset(&broadcastAddr, 0, sizeof(broadcastAddr));   /* Zero out structure */
	broadcastAddr.sin_family = AF_INET;                 /* Internet address family */
	broadcastAddr.sin_addr.s_addr = inet_addr(broadcastIP);/* Broadcast IP address */
	broadcastAddr.sin_port = htons(broadcastPort);         /* Broadcast port */
}

void sendNetData(packet_t* data) {
	int bytesSent = 0;
	bytesSent = sendto(sock, data, sizeof(packet_t), 0, (struct sockaddr*) &broadcastAddr,sizeof(broadcastAddr));
}
