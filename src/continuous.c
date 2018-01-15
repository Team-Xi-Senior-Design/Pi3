/* -*- c-basic-offset: 4; indent-tabs-mode: nil -*- */
/* ====================================================================
 * Copyright (c) 1999-2010 Carnegie Mellon University.  All rights
 * reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer. 
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * This work was supported in part by funding from the Defense Advanced 
 * Research Projects Agency and the National Science Foundation of the 
 * United States of America, and the CMU Sphinx Speech Consortium.
 *
 * THIS SOFTWARE IS PROVIDED BY CARNEGIE MELLON UNIVERSITY ``AS IS'' AND 
 * ANY EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL CARNEGIE MELLON UNIVERSITY
 * NOR ITS EMPLOYEES BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ====================================================================
 *
 */
/*
 * continuous.c - Simple pocketsphinx command-line application to test
 *                both continuous listening/silence filtering from microphone
 *                and continuous file transcription.
 */

/*
 * This is a simple example of pocketsphinx application that uses continuous listening
 * with silence filtering to automatically segment a continuous stream of audio input
 * into utterances that are then decoded.
 * 
 * Remarks:
 *   - Each utterance is ended when a silence segment of at least 1 sec is recognized.
 *   - Single-threaded implementation for portability.
 *   - Uses audio library; can be replaced with an equivalent custom library.
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>

#if defined(_WIN32) && !defined(__CYGWIN__)
#include <windows.h>
#else
#include <sys/select.h>
#endif

#include <sphinxbase/err.h>
#include <sphinxbase/ad.h>

#include "pocketsphinx.h"

static ps_decoder_t *ps;
static cmd_ln_t *config;

static void print_word_times()
{
    int frame_rate = cmd_ln_int32_r(config, "-frate");
    ps_seg_t *iter = ps_seg_iter(ps);
    while (iter != NULL) {
        int32 sf, ef, pprob;
        float conf;

        ps_seg_frames(iter, &sf, &ef);
        pprob = ps_seg_prob(iter, NULL, NULL, NULL);
        conf = logmath_exp(ps_get_logmath(ps), pprob);
        printf("%s %.3f %.3f %f\n", ps_seg_word(iter), ((float)sf / frame_rate),
               ((float) ef / frame_rate), conf);
        iter = ps_seg_next(iter);
    }
}

char* processAudio(int16_t* buffer, int size)
{
	uint8 utt_started, in_speech;
	char const * hyp;

	ps_start_utt(ps);
	utt_started = FALSE;


	ps_process_raw(ps, buffer, size, FALSE, FALSE);
	in_speech = ps_get_in_speech(ps);
	if (in_speech && !utt_started) {
		utt_started = TRUE;
	}
	if (!in_speech && utt_started) {
		ps_end_utt(ps);
		hyp = ps_get_hyp(ps, NULL);
		if (hyp != NULL)
		{
			printf("%s\n", hyp);
		}
		fflush(stdout);

		ps_start_utt(ps);
		utt_started = FALSE;
        }
	if (utt_started) {
		hyp = ps_get_hyp(ps, NULL);
		if (hyp != NULL) {
			printf("%s\n", hyp);
		}
	}
	ps_end_utt(ps);
}


/* Sleep for specified msec */
static void sleep_msec(int32 ms)
{
#if (defined(_WIN32) && !defined(GNUWINCE)) || defined(_WIN32_WCE)
    Sleep(ms);
#else
    /* ------------------- Unix ------------------ */
    struct timeval tmo;

    tmo.tv_sec = 0;
    tmo.tv_usec = ms * 1000;

    select(0, NULL, NULL, NULL, &tmo);
#endif
}

void cleanupAudioProcessor(int argc, char *argv[])
{
    ps_free(ps);
    cmd_ln_free_r(config);
}
