#ifndef MAP_H
#define MAP_H
#include <raylib.h>

typedef struct {
    const char *name;
    const char *musicfile;
} MapEntry;

extern MapEntry maps[];
extern const int mapCount;
extern Music currentMusic;

void InitMap(int index);  // Declaration for the init function

#endif
