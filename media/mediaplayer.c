/*
 * mediaplayer.c
 *
 *  Created on: Nov 4, 2014
 *      Author: surligas
 */

#include "mediaplayer.h"
#include <error.h>
#include <stdio.h>

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
	FILE *fp = fopen(filename, "r");
	if(!fp){
		perror("could not open file");
		return 0;
	}
}
