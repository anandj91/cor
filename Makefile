# Makefile for the cor project

CC=gcc
CFLAGS=-I/usr/include
LDFLAGS=-L/usr/lib -lc -lm -lpthread -lrt -lpcap

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
	
clean:
  rm -rf *.o
