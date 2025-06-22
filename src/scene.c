#include <raylib.h>
#include <math.h>
#include <stdio.h>
#include"../headers/utils.h"
#include"../headers/map.h"
#include"../headers/scene.h"
#include"../headers/map_data.h"






void DrawMenuScene(GameData *game, bool* shouldExit) {
    // Draw menu here
    ClearBackground(RAYWHITE);
    Vector2 mouse = GetMousePosition();

    // Handle clicks
    if (CheckCollisionPointRec(mouse, game->playButton)) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            game->currentState = STATE_MAP_SELECT;
        }
    }

    if (CheckCollisionPointRec(mouse, game->quitButton)) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            *shouldExit = true;
        }
    }

    // Draw buttons
    DrawRectangleRec(game->playButton, LIGHTGRAY);
    DrawRectangleRec(game->quitButton, LIGHTGRAY);

    DrawText("Play", game->playButton.x + 70, game->playButton.y + 15, 20, DARKGRAY);
    DrawText("Quit", game->quitButton.x + 70, game->quitButton.y + 15, 20, DARKGRAY);

}

void DrawMapSelectScene(GameData *game) {
    MapData *map = &game->currentMap;
    ClearBackground(LIGHTGRAY);
    Vector2 mouse = GetMousePosition();

    //Go back
    Rectangle buttonBack = {100, 1000, game->buttonWidth, game->buttonHeight};
    Color colorBack = CheckCollisionPointRec(mouse, buttonBack) ? LIGHTGRAY : GRAY;
    DrawRectangleRec(buttonBack, colorBack);
    DrawText("Go Back", 120,1015, 20, BLACK);

    if (CheckCollisionPointRec(mouse, buttonBack)&& IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
        game->currentState = STATE_MENU;
    }

    for(int i = 0; i < mapCount; i++){
        float x = game->screenWidth - 300 - game->buttonWidth/2.0f;
        float y = 100 + i * (game->buttonHeight + 20);

        Rectangle button = {x, y, game->buttonWidth, game->buttonHeight};

        Color color = CheckCollisionPointRec(mouse, button) ? LIGHTGRAY : GRAY;
        DrawRectangleRec(button, color);
        DrawText(maps[i].name, x+20, y+15, 20, BLACK);

        if (CheckCollisionPointRec(mouse, button) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
            //selectMapIndex = i;
            game->currentState = STATE_GAME;
            InitMap(map);
        }
    }
}

void DrawGameScene(GameData *game) {
    MapData *map = &game->currentMap;
    SetMusicVolume(map->music, 1.0f);
    UpdateMusicStream(map->music);
    map->duration = GetMusicTimeLength(map->music);
    map->elapsedTime += GetFrameTime();
    Vector2 center = {game->screenWidth / 2.0f, game->screenHeight / 2.0f};
    float arrowLength = game->screenHeight/2.0f;

    game->rotation += map->BPM * GetFrameTime();
    if(game->rotation >= 360.0f) game->rotation -= 360.0f;

    Vector2 tip = {
        center.x + sinf(DEG2RAD * game->rotation) * arrowLength,
        center.y - cosf(DEG2RAD * game->rotation) * arrowLength
    };

    DrawText("Game Scene", game->screenWidth/2.0f-100, 100, 30, DARKBLUE);
    ClearBackground(LIGHTGRAY);
    DrawLineEx(center, tip, 4.0f, DARKGRAY);
    DrawSmoothCircleLines(center,game->screenHeight/2.0f ,RED, 500);

    for(int i =0; i < map->totalCircles; i++){
        Circle *c = &map->circle[i];
        if(map->elapsedTime >= c->spawnTime && !c->isHit){
            DrawCircleV(c->position, 40,RED);
            if (IsKeyPressed(KEY_SPACE)){
                float dx = GetMouseX() - c->position.x;
                float dy = GetMouseY() - c->position.y;
                if(sqrtf(dx*dx + dy*dy)< 40.0f){
                    c->isHit = true;
                    map->circlesHit++;
                }
            }
        }
    }

    if (!IsMusicStreamPlaying(map->music) || map->elapsedTime >= map->duration) {
        StopMusicStream(map->music); // optional
        if(map->isLoaded){ 
            UnloadMusicStream(map->music);
        map->isLoaded = false;
        }
        game->currentState = STATE_MAP_END;
    }

}

void DrawMapEndScene(GameData *game){
    MapData *map = &game->currentMap;

    ClearBackground(DARKBLUE);
    DrawText("Map Complete!", 100,100,40,YELLOW);

    char stats[64];
    sprintf(stats, "Circles Hit: %d/%d", map->circlesHit, map->totalCircles);
    DrawText(stats, 100,160,30,WHITE);

    DrawText("Press ENTER to go back", 100, 220, 20, LIGHTGRAY);

    if(IsKeyPressed(KEY_ENTER)){
        game->currentState = STATE_MAP_SELECT;
    }
}