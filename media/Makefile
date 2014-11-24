GSTREAMER_FLAGS = `pkg-config --cflags gstreamer-0.10 gstreamer-app-0.10`
GSTREAMER_LD_LIBS = `pkg-config --libs gstreamer-0.10 gstreamer-app-0.10`
test: test.c
	$(CC) $(CFLAGS) $(GSTREAMER_FLAGS) -o test test.c $(GSTREAMER_LD_LIBS)

clean:
	@rm -fv test