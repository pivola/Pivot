#include <raylib.h>
#include <math.h>
#include"../headers/utils.h"


typedef enum {
    STATE_MENU,
    STATE_GAME
} GameState;

int main() {
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "Rhythm Game - Main Menu");
    SetTargetFPS(120);
    const int Swidth = GetScreenWidth();
    const int Sheight = GetScreenHeight();

    GameState currentState = STATE_MENU;

    float buttonWidth = 200;
    float buttonHeight = 50;

    Rectangle playButton = { 
        Swidth/2.0f - buttonWidth / 2.0f, 
        Sheight/2.0f - buttonHeight -10, 
        buttonWidth, 
        buttonHeight
    };
    Rectangle quitButton = {
        Swidth / 2.0f - buttonWidth / 2.0f,  
        Sheight / 2.0f + 10,                 
        buttonWidth,
        buttonHeight
    };

    static float rotation = 0.0f;
    static float BPM = 360.0f;
    while (!WindowShouldClose()) {
        BeginDrawing();

        if (currentState == STATE_MENU) {
            // Draw menu here
            ClearBackground(RAYWHITE);
            Vector2 mouse = GetMousePosition();

            // Handle clicks
            if (CheckCollisionPointRec(mouse, playButton)) {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    currentState = STATE_GAME;
                }
            }

            if (CheckCollisionPointRec(mouse, quitButton)) {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    CloseWindow(); // Optional: set a flag instead
                    return 0;
                }
            }

            // Draw buttons
            DrawRectangleRec(playButton, LIGHTGRAY);
            DrawRectangleRec(quitButton, LIGHTGRAY);

            DrawText("Play", playButton.x + 70, playButton.y + 15, 20, DARKGRAY);
            DrawText("Quit", quitButton.x + 70, quitButton.y + 15, 20, DARKGRAY);

        } else if (currentState == STATE_GAME) {
            Vector2 center = {screenWidth / 2.0f, screenHeight / 2.0f};
            float arrowLength = screenHeight/2.0f;

            rotation += BPM * GetFrameTime();
            if(rotation >= 360.0f) rotation -= 360.0f;

            Vector2 tip = {
                center.x + sinf(DEG2RAD * rotation) * arrowLength,
                center.y - cosf(DEG2RAD * rotation) * arrowLength
            };

            DrawText("Game Scene", screenWidth/2.0f-100, 100, 30, DARKBLUE);
            ClearBackground(LIGHTGRAY);
            DrawLineEx(center, tip, 4.0f, DARKGRAY);
            DrawSmoothCircleLines(center,screenHeight/2.0f ,RED, 500);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
