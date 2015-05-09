CC=gcc
CFLAGS=-I/usr/include
LDFLAGS=-L/usr/lib -lc -lm -lpthread

clean:
  rm -rf *.o
