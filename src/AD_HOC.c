/* Author: MSOE Team Xi Senior Design 2017
 * Date: 12/2017
 * Description: This file contains the functions that will control all AD-HOC network communications
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <netdb.h>
#include <sys/types.h>

#include "AD_HOC.h"


static struct sockaddr_in thisBoard;
static struct sockaddr_in broadcastAddr;
static int sockfd;
char* broadcastIP; /* IP broadcast address */
static char*  send_buffer;
static char*  recv_buffer ;
static const RESV_BUF_SIZE =  100;
static const SEND_BUF_SIZE =  100;

/*
 * Description:
 * @param:
 * @return: NULL
 */
void broadcast(char* voice){


}

/*
 * Description:
 * @param:
 * @retrun: NULL
 */
void initAD_HOC(){
    char *dstIP = "169.254.255.255";
    char *localIP = "localhost";
    int BroadcastPort = 25565;
    char *broadcastIP = "169.254.255.255";

    uint16_t broadcastPort;      /* Server port */
    char *audioString;           /* Audio string to broadcast */
    int broadcastOpt;            /* Socket opt to set permission to broadcast */
    uint32_t sendStringLen;

    struct sockaddr_in broadcastAddr;
    unsigned int localIPLen;

    recv_buffer = (char *) malloc(RESV_BUF_SIZE);
    send_buffer = (char *) malloc(SEND_BUF_SIZE);

    if ((sockfd = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
        perror("socket() failed");
    }
    int broadcastPermission = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, (void*) &broadcastPermission, sizeof(broadcastPermission)) < 0) {
        perror("setsockopt() failed");
    }
    memset(&broadcastAddr, 0, sizeof(broadcastAddr));
    broadcastAddr.sin_family = AF_INET;
    broadcastAddr.sin_addr.s_addr = inet_addr(dstIP);
    broadcastAddr.sin_port = htons(BroadcastPort);

    localIPLen = strlen(localIP);
    for (int j = 0; j < 1; j++) {
        if (sendto(sockfd, localIP, localIPLen, 0, (struct sockaddr*)&broadcastAddr, sizeof(broadcastAddr))!=localIPLen) {
            perror("sendto() sent a different number of bytes than expected");
        }
	memset(recv_buffer,0,12);
	recvfrom(sockfd, recv_buffer, 10, NULL, (struct sockaddr*)&broadcastAddr, sizeof(broadcastAddr));
	printf(recv_buffer);
    }
}

void test() {
}

/*
 * Description:
 * @param:
 * @return:
 */
char* recieve(){
  return 0;
}










/*communications stuff*/
