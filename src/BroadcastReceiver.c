#include <stdio.h>      /* for printf() and fprintf() */
#include <sys/socket.h> /* for socket(), connect(), sendto(), and recvfrom() */
#include <arpa/inet.h>  /* for sockaddr_in and inet_addr() */
#include <stdlib.h>     /* for atoi() and exit() */
#include <string.h>     /* for memset() */
#include <unistd.h>     /* for close() */
#include <netinet/in.h>

#define BROADCAST_PORT 25565

static int sock;                         /* Socket */
static struct sockaddr_in broadcastAddr; /* Broadcast Address */
static unsigned short broadcastPort = BROADCAST_PORT;     /* Port */


int receiveNetData(char * recvBuff, int receiveBuffSize) {
	return recvfrom(sock, recvBuff, receiveBuffSize, 0, NULL, 0);
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
}

void cleanupReceiver() {
	close(sock);
}
