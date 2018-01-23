#include <errno.h>
#include <stdio.h>      /* for printf() and fprintf() */
#include <sys/socket.h> /* for socket(), connect(), sendto(), and recvfrom() */
#include <arpa/inet.h>  /* for sockaddr_in and inet_addr() */
#include <stdlib.h>     /* for atoi() and exit() */
#include <string.h>     /* for memset() */
#include <unistd.h>     /* for close() */
#include <netinet/in.h>

#include "BroadcastReceiver.h"

#define BROADCAST_PORT 25565
#define MAX_PACKET_SIZE 1500

static int sock;                         /* Socket */
static struct sockaddr_in broadcastAddr; /* Broadcast Address */
static unsigned short broadcastPort = BROADCAST_PORT;     /* Port */


void receiveNetData(packet_t * data) {
	int bytesRead = 0;
	while (bytesRead < sizeof(packet_t)) {
		int bytes = recvfrom(sock, &data[bytesRead], (sizeof(packet_t)-bytesRead)>MAX_PACKET_SIZE?MAX_PACKET_SIZE:(sizeof(packet_t)-bytesRead), 0, NULL, 0);
		if (bytes>0) {
			bytesRead += bytes;
			fprintf(stderr,"recieved: %d bytes\n",bytesRead);
		} else {
			fprintf(stderr,"error sending %i\n",errno);
			break;
		}
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
}

void cleanupReceiver() {
	close(sock);
}
