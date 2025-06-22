CC = gcc
SRC = src/
BUILD = build/
CFLAGS = -Wall -Wextra -std=c99 -pedantic $(shell pkg-config --cflags raylib)
LIBS = $(shell pkg-config --libs raylib) -lm
HEAD = headers/
OBJECTS = ${BUILD}main.o ${BUILD}utils.o ${BUILD}map.o ${BUILD}scene.o

all: main

main: ${OBJECTS}
		${CC} -o $@ ${OBJECTS} ${LIBS}

${BUILD}main.o: ${SRC}main.c ${HEAD}utils.h ${HEAD}map_data.h
	@mkdir -p ${BUILD}
	${CC} ${CFLAGS} -c $< -o $@

${BUILD}utils.o: ${SRC}utils.c ${HEAD}utils.h ${HEAD}map_data.h
	@mkdir -p ${BUILD}
	${CC} ${CFLAGS} -c $< -o $@

${BUILD}map.o: ${SRC}map.c ${HEAD}map.h ${HEAD}map_data.h
	@mkdir -p ${BUILD}
	${CC} ${CFLAGS} -c $< -o $@

${BUILD}scene.o: ${SRC}scene.c ${HEAD}scene.h ${HEAD}utils.h ${HEAD}map_data.h
	@mkdir -p ${BUILD}
	${CC} ${CFLAGS} -c $< -o $@

clean:
		rm main
		rm -rf ${BUILD}
	