# Change it to your disired compiler
CC := gcc

# The flags that will be passed to the compiler
CFLAGS := -Wall -g
LDFLAGS := -lpthread

export CC
export CFLAGS

all: mocserver mocclient

# This will compile and execute the test program
# in order to find out if the appropriate GStreamer libraries.
# If all are ok, a video player that will play a video stream
# should appear.
#
# NOTE: Internet access is required to play the video!!!
# So execute "make test" as wait for the magic (or erros :-P )
test:
	$(MAKE) -C media $@

mocserver: server.c music_on_cloud.h
	$(CC) $(CFLAGS) $(LDFLAGS) -o mocserver server.c

mocclient: client.c music_on_cloud.h
	$(CC) $(CFLAGS) $(LDFLAGS) -o mocclient client.c

clean:
	$(MAKE) -C media $@
	@rm -fv mocserver
	@rm -fv mocclient