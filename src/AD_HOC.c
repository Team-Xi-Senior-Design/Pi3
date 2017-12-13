/* Author: MSOE Team Xi Senior Design 2017
 * Date: 12/2017
 * Description: This file contains the functions that will control all AD-HOC network communications
 */

#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

#include "AD_HOC.h"


static struct sockaddr_in thisBoard;
static struct sockaddr_in broadcastAddr;
static int thisSockFd;
uint8_t* broadcastIP; /* IP broadcast address */
static uint8[]*  send_buffer;
stacic uint8[]*  recv_buffer;

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
    char *broadcastIP;
    uint16_t broadcastPort;      /* Server port */
    char *audioString;           /* Audio string to broadcast */
    int broadcastOpt;            /* Socket opt to set permission to broadcast */
    uint32_t sendStringLen;

    recv_buffer(uint8_t *) malloc(RESV_BUF_SIZE);
    if((thisSockFd = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP)) <0){
        printf("socket 1 creation failed\n");
    }
    /*gives broadcast premission to the socket*/
    broadcastOpt = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, (void *)&broadcastOpt,
         sizeof(broadcastOpt)) < 0){
         printf("failed to set socket broadcast option!\n");
    }
    memset(&broadcastAddr, 0 , sizeof(broadcastAddr));
    broadcastAddr.sin_family = AF_INET;
    broadcastAddr.sin_addr.s_addr = inet_addr(broadcastIP);
    broadcastAddr.sin_port =htons(broadcastPort);
    sendStringLen  = strlen(audioString);
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
