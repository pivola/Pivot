#pragma once
#include<raylib.h>
#define MAX_CIRCLES 1024

typedef struct {
    Vector2 position;
    float spawnTime;
    bool isHit;
} Circle;

typedef struct {
    Circle circle[MAX_CIRCLES];
    int totalCircles;
    int circlesHit;

    float duration;
    float elapsedTime;

    float BPM;
    Music music;
    bool isLoaded;
} MapData;
