#include <raylib.h>
#include <stddef.h>
#include "../headers/map.h"
#include"../headers/map_data.h"


MapEntry maps[] = {
    {"Map 1", "assets/music1.mp3"},
    {"Map 2", "assets/music2.mp3"}
};

const int mapCount = sizeof(maps)/sizeof(maps[0]);

void InitMap(MapData *map) {
    map->BPM = 120.0f;
    map->totalCircles = 3;
    map->circle[0] = (Circle){ .position = {300, 300}, .spawnTime = 1.0f };
    map->circle[1] = (Circle){ .position = {500, 200}, .spawnTime = 3.0f };
    map->circle[2] = (Circle){ .position = {700, 400}, .spawnTime = 5.0f };
    map->circlesHit = 0;
    map->elapsedTime = 0.0f;

    map->music = LoadMusicStream("assets/music1.mp3");
    map->isLoaded = true;
    PlayMusicStream(map->music);
    map->duration = GetMusicTimeLength(map->music);
}