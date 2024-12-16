all:example1

CC=g++
CPPFLAGS=-Wall -std=c++11 -ggdb
LDFLAGS=-pthread

example1:example1.o
	$(CC) $(LDFLAGS) -o $@ $^

example1.o:example1.cpp
	$(CC) $(CPPFLAGS) -o $@ -c $^


.PHONY:
	clean

clean:
	rm example1.o example1
