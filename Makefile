CC=clang
CFLAGS=-Iinclude -Wall -g
SRC=src/multex.c main.c
TARGET=multex

all:
	clang -Iinclude -Wall -g -o multex src/multex.c main.c -lpthread

clean:
	rm -f multex