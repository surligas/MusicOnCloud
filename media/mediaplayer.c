/*
 * mediaplayer.c
 *
 *  Created on: Nov 4, 2014
 *      Author: surligas
 */

#include "mediaplayer.h"
#include <error.h>
#include <stdio.h>
#include <arpa/inet.h>


void
init_mediaplayer(int argc, char *argv[])
{
	gst_init(argc, argv);
}

void
free_mediaplayer();


size_t
get_mp3_bit_rate(const char *filename)
{
	uint32_t 	frame_header;
	uint8_t		versionID;
	uint8_t		layer;
	uint8_t		bit_rate_index;

	FILE 		*fp = fopen(filename, "r");
	if(!fp){
		perror("could not open file");
		return 0;
	}

	fseek(fp, 32, SEEK_SET);
	fread(&frame_header, sizeof(uint32_t), 1, fp);
	frame_header = ntohl(frame_header);
	printf("0x%x\n", frame_header);

	versionID = (frame_header >> 19) & 0b11;
	layer = (frame_header >> 17) & 0b11;

	printf("version: %u\n", versionID);
	printf("layer: %u\n", layer);
	bit_rate_index = (frame_header >> 12) & 0b1111;

	fclose(fp);

	if(versionID == MPEGv1){
		return _mp3_bit_rates[bit_rate_index][versionID ^ layer];
	}
	else{
		if(layer == LAYER1){
			return _mp3_bit_rates[bit_rate_index][3];
		}
		else{
			return _mp3_bit_rates[bit_rate_index][4];
		}
	}
}
