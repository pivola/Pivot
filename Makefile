CC = gcc
SRC = src/
BUILD = build/
CFLAGS = -Wall -std=c99 $(shell pkg-config --cflags raylib)
LIBS = $(shell pkg-config --libs raylib) -lm
HEAD = headers/
OBJECTS = ${BUILD}main.o ${BUILD}utils.o

all: main

main: ${OBJECTS}
		${CC} -o $@ ${OBJECTS} ${LIBS}

${BUILD}main.o: ${SRC}main.c ${HEAD}utils.h ${HEAD}button.h
	@mkdir -p ${BUILD}
	${CC} ${CFLAGS} -c $< -o $@

${BUILD}utils.o: ${SRC}utils.c ${HEAD}utils.h
	@mkdir -p ${BUILD}
	${CC} ${CFLAGS} -c $< -o $@

clean:
		rm main
		rm -rf ${BUILD}
	