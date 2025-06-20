#ifndef SCENE_H
#define SCENE_H

#include<raylib.h>

typedef enum {
    STATE_MENU,
    STATE_MAP_SELECT,
    STATE_GAME
} GameState;


typedef struct {
    Rectangle playButton;
    Rectangle quitButton;
    float rotation;
    float BPM;
    int selectMapIndex;
    GameState currentState;
    int screenWidth;
    int screenHeight;
    int buttonWidth;
    int buttonHeight;
} GameData;

/**
 @param playButton button redirects to MapSelectScene
 @param quitButton button redirects to exit
 @param int screenWidth
 @param int screenHeight

 @return renders the main menu
 */
void DrawMenuScene(GameData *game);

/**
 @param int selectMapIndex index of the map chosen
 
 @return renders the map selection scenen
*/
void DrawMapSelectScene(GameData *game);

/**
 @param rotation calculates at which speed the arrow rotates
 @param BPM the BPM of the map, will influence rotation

 @return renders the game scene
*/
void DrawGameScene(GameData *game);

#endif