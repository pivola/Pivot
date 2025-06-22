#include <raylib.h>
#include <math.h>
#include"../headers/utils.h"
#include"../headers/map.h"
#include"../headers/scene.h"


int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(GetScreenWidth(), GetScreenHeight(), "Rhythm Game - Main Menu");
    SetTargetFPS(120);
    InitAudioDevice();
    bool shouldExit = false;
    



    GameData game = {
        .screenWidth = GetScreenWidth(),
        .screenHeight = GetScreenHeight(),
        .selectMapIndex = 0,
        .currentState = STATE_MENU,
    };


    game.buttonHeight = 50;
    game.buttonWidth = 200;

    game.playButton = (Rectangle){
        game.screenWidth / 2.0f - game.buttonWidth / 2.0f,
        game.screenHeight / 2.0f - game.buttonHeight - 10,
        game.buttonWidth,
        game.buttonHeight
    };

    game.quitButton = (Rectangle){
        game.screenWidth / 2.0f - game.buttonWidth / 2.0f,
        game.screenHeight / 2.0f + 10,
        game.buttonWidth,
        game.buttonHeight
    };


    while (!WindowShouldClose() && !shouldExit) {
        BeginDrawing();

        switch(game.currentState) {
            case STATE_MENU:
                DrawMenuScene(&game, &shouldExit);
                break;
            case STATE_MAP_SELECT:
                DrawMapSelectScene(&game);
                break;
            case STATE_GAME:
                DrawGameScene(&game);
                break;
            case STATE_MAP_END:
                DrawMapEndScene(&game);
                break;
        }

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
