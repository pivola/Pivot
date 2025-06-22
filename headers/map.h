#ifndef MAP_H
#define MAP_H
#include <raylib.h>
#include"map_data.h"

typedef struct {
    const char *name;
    const char *musicfile;
} MapEntry;

extern MapEntry maps[];
extern const int mapCount;
extern Music currentMusic;
extern bool isMusicLoaded;


void InitMap(MapData *map);  // Declaration for the init function

#endif
