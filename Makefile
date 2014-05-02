CC = gcc
CFLAGS = $(GLOBAL_CFLAGS) -arch i386 -arch x86_64 -mmacosx-version-min=10.5
TEST_OFILES = rtk/io.o rtk/midi.o test.o

test: $(TEST_OFILES)
	$(CC) $(CFLAGS) $(TEST_OFILES) -o test

clean:
	rm -rf $(TEST_OFILES)
