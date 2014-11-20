MusicOnCloud
============

MusicOnCloud is the class project for the cs335a lesson http://www.csd.uoc.gr/~hy335a. 

It relies on GStreamer in order to play .mp3 and .flac music files

Gstreamer dependencies
============

For .deb distributions:
* gstreamer−0.10 gstreamer−0_10−dev
* gstreamer−0.10−fluendo−mp3
* gstreamer−0.10−plugins−base
* gstreamer−0.10−plugins−base−dev


For .rpm distributions
* gstreamer−0_10 gstreamer−0_10−devel
* gstreamer−0_10−fluendo−mp3
* gstreamer−0_10−plugins−base
* gstreamer−0_10−plugins−base−devel

Testing the deoendencies
============
After installing the dependencies of gstreamer check if the test program can be compiled.
To do that:
* cd MusicOnCloud
* make test
* ./media/test path_to_a_music_file
where path_to_a_music_file is the absolute path to a .mp3 or .flac music file.
