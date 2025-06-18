CC = gcc
SRC = src/main.c src/utils.c
BUILD = /build
CFLAGS = -Wall -std=c99 $(shell pkg-config --cflags raylib)
LIBS = $(shell pkg-config --libs raylib) -lm

main: ${SRC}
		${CC} -o main ${SRC} ${CFLAGS} $(LIBS)


clean:
		rm main
		rm utils
	