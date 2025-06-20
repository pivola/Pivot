#include <raylib.h>
#include <math.h>
#include"../headers/utils.h"
#include"../headers/map.h"
#include"../headers/scene.h"





void DrawMenuScene(GameData *game) {
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
            CloseWindow(); // Optional: set a flag instead
            //return 0;
        }
    }

    // Draw buttons
    DrawRectangleRec(game->playButton, LIGHTGRAY);
    DrawRectangleRec(game->quitButton, LIGHTGRAY);

    DrawText("Play", game->playButton.x + 70, game->playButton.y + 15, 20, DARKGRAY);
    DrawText("Quit", game->quitButton.x + 70, game->quitButton.y + 15, 20, DARKGRAY);

}

void DrawMapSelectScene(GameData *game) {
    ClearBackground(LIGHTGRAY);
    Vector2 mouse = GetMousePosition();
    for(int i = 0; i < mapCount; i++){
        float x = game->screenWidth - 300 - game->buttonWidth/2.0f;
        float y = 100 + i * (game->buttonHeight + 20);

        Rectangle button = {x, y, game->buttonWidth, game->buttonHeight};

        Color color = CheckCollisionPointRec(mouse, button) ? LIGHTGRAY : GRAY;
        DrawRectangleRec(button, color);
        DrawText(maps[i].name, x+20, y+15, 20, BLACK);

        if (CheckCollisionPointRec(mouse, button) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
            //selectMapIndex = i;
            InitMap(i);
            game->currentState = STATE_GAME;
        }
    }
}

void DrawGameScene(GameData *game) {
    SetMusicVolume(currentMusic, 1.0f);
    UpdateMusicStream(currentMusic);
    Vector2 center = {game->screenWidth / 2.0f, game->screenHeight / 2.0f};
    float arrowLength = game->screenHeight/2.0f;

    game->rotation += game->BPM * GetFrameTime();
    if(game->rotation >= 360.0f) game->rotation -= 360.0f;

    Vector2 tip = {
        center.x + sinf(DEG2RAD * game->rotation) * arrowLength,
        center.y - cosf(DEG2RAD * game->rotation) * arrowLength
    };

    DrawText("Game Scene", game->screenWidth/2.0f-100, 100, 30, DARKBLUE);
    ClearBackground(LIGHTGRAY);
    DrawLineEx(center, tip, 4.0f, DARKGRAY);
    DrawSmoothCircleLines(center,game->screenHeight/2.0f ,RED, 500);

    if (!IsMusicStreamPlaying(currentMusic)) {
        StopMusicStream(currentMusic); // optional
        game->currentState = STATE_MAP_SELECT;
    }

}
