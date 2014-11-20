/*
 * client.c
 *
 *  Created on: Nov 5, 2014
 *      Author: surligas
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "music_on_cloud.h"


int
main(int argc, char **argv)
{
	int opt;
	int server_listen_port;

	/* A very easy way to parse command line arguments */
	while ((opt = getopt(argc, argv, "hp:")) != -1) {
		switch (opt)
			{
		case 'p':
			server_listen_port = atoi(optarg);
			/* To check or not to check? */
			break;
		default:
			printf("Usage: mocclient -p server_port\n"
			       "Options:\n"
			       "   -p <int>            The listening port of the server\n"
			       "   -h                  prints this help\n");
			exit(EXIT_FAILURE);
			}
	}

	printf("MediaOnCloud Client:\n"
	       "-->Server listen port: %d\n",
	       server_listen_port);

	return 0;
}



