#include "AudioProcessing.h"

#include <pocketsphinx.h>
#include <sphinxbase/err.h>
#include <sphinxbase/ad.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

ps_decoder_t* ps = NULL;
cmd_ln_t* config = NULL;

int rv;
int32_t score;
int8_t in_speech;
char const *hyp;
char *uttid;
int8_t utt_started = FALSE;

void initAudioProcessing() {
	//config = cmd_ln_init(NULL, ps_args(), TRUE,
		//"-hmm", MODELDIR "/en-us/en-us",
		//"-lm", MODELDIR "/en-us/en-us.lm.bin",
		//"-dict", MODELDIR "/en-us/cmudict-en-us.dict",
		//"-cmn","batch",
		//"-backtrace","yes",
		//"-lowerf","130",
		//"-upperf","6800",
		//"-nfilt","25",
		//"-transform","dct",
		//"-lifter","22",
		//"-feat","1s_c_d_dd",
		//"-svspec","0-12/13-25/26-38",
		//"-agc","none",
		//"-varnorm","no",
		//"-model","ptm",
		//"-cmninit","41.00,-5.29,-0.12,5.09,2.48,-4.07,-1.37,-1.78,-5.08,-2.05,-6.45,-1.42,1.17",
		//NULL);
	config = cmd_ln_parse_file_r(NULL, ps_args(), "./config.params", TRUE);
	if (config == NULL) {
		fprintf(stderr,"Failed to create config object, see log\n");
		exit(EXIT_FAILURE);
	}

	ps = ps_init(config);

	if(ps==NULL) {
		fprintf(stderr,"failed to create recognizer, see log\n");
		exit(EXIT_FAILURE);
	}

	rv = ps_start_utt(ps);
	if (rv < 0)
	{
		fprintf(stderr, "failed to start utterance\n");
		exit(EXIT_FAILURE);
	}

}

int i = 0;

void processData(packet_t* data) {
	rv = ps_process_raw(ps,(int16_t*) ((char*)data->data), (data->size)/2, FALSE, FALSE);
	in_speech = ps_get_in_speech(ps);
	if (in_speech && !utt_started)
	{
		utt_started = TRUE;
	}
	if (!in_speech && utt_started)
	{
		ps_end_utt(ps);
		hyp = ps_get_hyp(ps, NULL);
		if (hyp != NULL)
		{
			printf("Hypothesis:\n");
			printf("%s\n",hyp);
		}
		//initAudioProcessing();
		ps_start_utt(ps);
		utt_started = FALSE;
	}
}

char const* getWords() {
	/*
	rv = ps_end_utt(ps);
	char const *words = ps_get_hyp(ps, &score);
	if (ps == NULL)
	{
		fprintf(stderr, "for some ungodly reason, ps became null\n");
		exit(EXIT_FAILURE);
	}
	ps_start_utt(ps);
	if (ps == NULL)
	{
		fprintf(stderr, "for some ungodly reason, ps became null\n");
		exit(EXIT_FAILURE);
	}
	return words;
	*/
}
