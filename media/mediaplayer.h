/*
 * mediaplayer.h
 *
 *  Created on: Nov 3, 2014
 *      Author: surligas
 */

#ifndef MEDIA_MEDIAPLAYER_H_
#define MEDIA_MEDIAPLAYER_H_

#include <gst/gst.h>

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

void
init_mediaplayer();

void
free_mediaplayer();




#endif /* MEDIA_MEDIAPLAYER_H_ */
