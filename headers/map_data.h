#pragma once
#include<raylib.h>
#define MAX_CIRCLES 1024

typedef struct Circle {
    Vector2 position;
    float radius;
    float spawnTime;
    float lifeTime;
    //float overallDifficulty;
    //float HP;
    bool isHit;
    bool active;
} Circle;

typedef struct MapData {
    Circle *circle;
    int totalCircles;
    int circlesHit;
    float circleMaxDist;

    float duration;
    float elapsedTime;

    float BPM;
    Music music;
    bool isLoaded;
} MapData;
