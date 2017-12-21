#ifndef BROADCAST_RECEIVER_H_
#define BROADCAST_RECEIVER_H_

#include "NetworkPacket.h"

void receiveNetData(packet_t *);
void cleanupReceiver();
void initReceiver();

#endif
