GSTREAMER_FLAGS = `pkg-config --cflags --libs gstreamer-0.10 gstreamer-app-0.10`

test: test.c
	$(CC) $(CFLAGS) $(GSTREAMER_FLAGS) -o test test.c
	
clean:
	@rm -fv test