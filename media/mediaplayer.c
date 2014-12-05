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
#include <string.h>


void
init_mediaplayer(int argc, char *argv[])
{
	gst_init(argc, argv);
}

void
free_mediaplayer();



/**
 * Converts a sycnhsafe integer to a normal one.
 * NOTE: You will not use it. Its just for internal purposes.
 * @param sync_safe the synch-safe integer
 * @return the normal integer from the synchsafe integer.
 */
static uint32_t
ID3_sync_safe_to_int( uint8_t* sync_safe )
{
    uint32_t byte0 = sync_safe[0];
    uint32_t byte1 = sync_safe[1];
    uint32_t byte2 = sync_safe[2];
    uint32_t byte3 = sync_safe[3];

    return byte0 << 21 | byte1 << 14 | byte2 << 7 | byte3;
}


/**
 * This function returns the bit rate of a .mp3 file
 * @param filename the absolute path of the .mp3 file
 * @return the bit rate in kbps (Kilo bits per second)
 *
 * NOTE: Kilo is 1000 for the bit representation. Do not
 * get confused with KB which Kilo stands for 1024.
 */
size_t
get_mp3_bit_rate(const char *filename)
{
	uint32_t 	frame_header;
	uint32_t	ID3_len;
	uint8_t		synch_safe_word[4];
	uint8_t		ID3tag_footer;
	uint8_t		versionID;
	uint8_t		layer;
	uint8_t		bit_rate_index;
	uint16_t	search_sync;

	const uint16_t	sync = 0b11111111111;

	char		ID3tag[3];

	FILE 		*fp = fopen(filename, "r");
	if(!fp){
		perror("could not open file");
		return 0;
	}

	/* Skip the ID3 header, if any */
	fread(&ID3tag[0], sizeof(char), 3, fp);

	if(strncmp(ID3tag, "ID3", 3) == 0 ){
		/* Skip ID3 version */
		fseek(fp, 2, SEEK_CUR);

		/* Check for footer */
		fread(&ID3tag_footer, sizeof(uint8_t), 1, fp);
		ID3tag_footer = (ID3tag_footer >> 4) & 0x1;
		fread(&synch_safe_word[0], sizeof(uint8_t), 4, fp);
		ID3_len = ID3_sync_safe_to_int(synch_safe_word);

		/* Skip the ID3 header and its footer if exists */
		if(ID3tag_footer){
			fseek(fp, ID3_len + 10, SEEK_CUR);
		}
		else{
			fseek(fp, ID3_len, SEEK_CUR);
		}
	}

	/* Now its the time to find the start of a valid frame */
	fread(&search_sync, sizeof(uint16_t), 1, fp);
	search_sync = ntohs(search_sync);

	while( ((search_sync & 0b1111111111100000) >> 5) != sync){
		fseek(fp, -1, SEEK_CUR);
		fread(&search_sync, sizeof(uint16_t), 1, fp);
		search_sync = ntohs(search_sync);
	}

	fseek(fp, -2, SEEK_CUR);

	fread(&frame_header, sizeof(uint32_t), 1, fp);
	frame_header = ntohl(frame_header);

	versionID = (frame_header >> 19) & 0b11;
	layer = (frame_header >> 17) & 0b11;
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

/**
 * This function returns the bit rate of a .flac file
 * @param filename the absolute path of the .flac file
 * @return the bit rate in kbps (Kilo bits per second)
 *
 * NOTE: Kilo is 1000 for the bit representation. Do not
 * get confused with KB which Kilo stands for 1024.
 */
size_t
get_flac_bit_rate(const char *filename)
{
	uint32_t	sample_rate;
	uint32_t	header_field;
	uint16_t	bits_per_sample;
	uint64_t	total_samples = 0;
	uint64_t	duration;

	FILE 		*fp = fopen(filename, "r");
	if(!fp){
		perror("could not open file");
		return 0;
	}

	fseek(fp, 4 + 10 + 4, SEEK_CUR);
	fread(&header_field, sizeof(uint32_t), 1, fp);

	header_field = ntohl(header_field);
	sample_rate = header_field >> 12;
	bits_per_sample = ((header_field >> 4) & 0b11111) + 1;

	total_samples =  (((uint64_t) header_field) & 0b1111) << 32;
	fread(&header_field, sizeof(uint32_t), 1, fp);
	header_field = ntohl(header_field);

	total_samples |= (uint64_t) header_field;

	duration = total_samples / sample_rate;

	return (total_samples * bits_per_sample) / (1000 *duration);
}
