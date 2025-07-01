#include <raylib.h>
#include <stddef.h>
#include <stdlib.h>
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
    map->circle = malloc(sizeof(Circle) * map->totalCircles);

    for (int i = 0; i < map->totalCircles; i++){
        map->circle[i].position = (Vector2){200 + i*100, 300};
        map->circle[i].radius = 30;
        map->circle[i].spawnTime = i* 2.0f;
        map->circle[i].active = false;
        map->circle[i].isHit = false;
        map->circle[i].lifeTime = 2.0f;
    }
    map -> circlesHit = 0;

    map->music = LoadMusicStream("assets/music1.mp3");
    map->isLoaded = true;
    PlayMusicStream(map->music);
    map->duration = GetMusicTimeLength(map->music);
}