/*
 * mediaplayer.h
 *
 *  Created on: Nov 3, 2014
 *      Author: surligas
 */

#ifndef MEDIA_MEDIAPLAYER_H_
#define MEDIA_MEDIAPLAYER_H_

#include <gst/gst.h>
#include <stdint.h>

/**
 * @file mediaplayer.h
 * @author surligas@csd.uoc.gr
 *
 * This header file includes all the necessary functions that allow
 * the playback of music files received over the network.
 *
 * To accomplish that GStreamer (http://gstreamer.freedesktop.org/) is used.
 * For this reason, GStreamer libraries and development files should be installed.
 * Hopefully most Linux distributions have already installed it.
 *
 */
#define MPEGv1 3
#define MPEGv2 2
#define MPEGv2_1 0

#define LAYER1 3
#define LAYER2 2
#define LAYER3 1
static uint16_t
_mp3_bit_rates[16][5] = {
	{0,      0,      0,      0,      0},
	{32, 	32, 	32, 	32, 	8},
	{64, 	48, 	40, 	48, 	16},
	{96, 	56, 	48, 	56, 	24},
	{128, 	64, 	56, 	64, 	32},
	{160, 	80, 	64, 	80, 	40},
	{192, 	96, 	80, 	96, 	48},
	{224, 	112, 	96, 	112, 	56},
	{256, 	128, 	112, 	128, 	64},
	{288, 	160, 	128, 	144, 	80},
	{320, 	192, 	160, 	160, 	96},
	{352, 	224, 	192, 	176, 	112},
	{384, 	256, 	224, 	192, 	128},
	{416, 	320, 	256, 	224, 	144},
	{448, 	384, 	320, 	256, 	160},
	{0, 	0, 	0, 	0, 	0}
};

void
init_mediaplayer();

void
free_mediaplayer();

size_t
get_mp3_bit_rate(const char *filename);



#endif /* MEDIA_MEDIAPLAYER_H_ */
