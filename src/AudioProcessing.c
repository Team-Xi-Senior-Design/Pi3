#include "AudioProcessing.h"

#include <pocketsphinx.h>
#include <sphinxbase/err.h>
#include <sphinxbase/ad.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MODELDIR "/usr/local/share/pocketsphinx/model/en-us/"

ps_decoder_t* ps = NULL;
cmd_ln_t* config = NULL;
int rv;
int32_t score;
int8_t in_speech;
char const *hyp, *uttid;

void initAudioProcessing() {
	config = cmd_ln_init(NULL, ps_args(), TRUE,
		"-hmm", MODELDIR "en-us",
		"-lm", MODELDIR "en-us.lm.bin",
		"-dict", MODELDIR "cmudict-en-us.dict",
		NULL);

	if (config == NULL) {
		fprintf(stderr,"Failed to create config object, see log\n");
		exit(EXIT_FAILURE);
	}

	ps = ps_init(config);
	if(ps==NULL) {
		fprintf(stderr,"failed to create recognizer, see log\n");
	}

	rv = ps_start_utt(ps);
}

void processData(packet_t* data) {
	rv = ps_process_raw(ps,((int16_t*)data->data), data->size, FALSE, FALSE);
}

char* getWords() {
	rv = ps_end_utt(ps);
	char const *words = ps_get_hyp(ps, &score);
	printf("Recognized: %s\n", hyp);

	rv = ps_start_utt(ps);
}
