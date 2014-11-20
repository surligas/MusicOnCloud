/*
 * music_on_cloud.h
 *
 *  Created on: Nov 5, 2014
 *      Author: surligas
 */

#ifndef MUSIC_ON_CLOUD_H_
#define MUSIC_ON_CLOUD_H_

/**
 * This is the type of the media files that are transfered
 * through network.
 *
 * The provided file types are the minimum that your project
 * should support.
 *
 * NOTE 1: Enum is an 4 byte integer, so take care the endianess
 * NOTE 2: You can extend to other media types, even video!!
 */
typedef enum e_media_type {
	UKNOWN = 0,         //!< UKNOWN for unknown media files
	MP3 = 1,            //!< MP3 for .mp3 media files
	FLAC = 2,           //!< FLAC for .flac lossless media files
	LIVE_STREAM = 3,    //!< For live-streaming
	/* You can add your own here!! */
	UNSUPPORTED = 0xFFFF//!< UNSUPPORTED for unsupported media files
} media_t;

#endif /* MUSIC_ON_CLOUD_H_ */
