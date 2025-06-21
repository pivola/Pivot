#include <raylib.h>
#include <stddef.h>
#include "../headers/map.h"


MapEntry maps[] = {
    {"Map 1", "assets/music1.mp3"},
    {"Map 2", "assets/music2.mp3"}
};

const int mapCount = sizeof(maps)/sizeof(maps[0]);

Music currentMusic;

void InitMap(int index) {
    if (!FileExists("assets/music2.mp3")) {
        TraceLog(LOG_ERROR, "FILE NOT FOUND!");
    }
    currentMusic = LoadMusicStream(maps[index].musicfile);
    if (currentMusic.stream.buffer == NULL) {
        TraceLog(LOG_ERROR, "Failed to load music: %s", maps[index].musicfile);
    }
    PlayMusicStream(currentMusic);
}