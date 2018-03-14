#include "NetworkPacket.h"

#ifndef AUDIO_PROCESSING_H
#define AUDIO_PROCESSING_H

void initAudioProcessing();
void processData(packet_t *);
char const* getWords();

#endif
