#include <stdio.h>      /* for printf() and fprintf() */
#include <sys/socket.h> /* for socket() and bind() */
#include <arpa/inet.h>  /* for sockaddr_in */
#include <stdlib.h>     /* for atoi() and exit() */
#include <string.h>     /* for memset() */
#include <unistd.h>     /* for close() */

static int sock;                         /* Socket */
static struct sockaddr_in broadcastAddr; /* Broadcast address */
static char *broadcastIP = "169.254.255.255";                /* IP broadcast address */
static unsigned short broadcastPort = 25565;     /* Server port */
static char *sendString;                 /* String to broadcast */
static int broadcastPermission;          /* Socket opt to set permission to broadcast */

void initSender() {
	if((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
		perror("failed to open socket");
	broadcastPermission = 1;
	if(setsockopt(sock, SOL_SOCKET, SO_BROADCAST, (void*) &broadcastPermission, sizeof(broadcastPermission)) < 0)
		perror("failed to set socket options");
}

void sendNetData(char* buffer, int size) {
	/* Construct local address structure */
	memset(&broadcastAddr, 0, sizeof(broadcastAddr));   /* Zero out structure */
	broadcastAddr.sin_family = AF_INET;                 /* Internet address family */
	broadcastAddr.sin_addr.s_addr = inet_addr(broadcastIP);/* Broadcast IP address */
	broadcastAddr.sin_port = htons(broadcastPort);         /* Broadcast port */
	if (sendto(sock, buffer, size, 0, (struct sockaddr *) &broadcastAddr, sizeof(broadcastAddr)) != size) {
		printf("wrong number of bytes sent");
	}
}
