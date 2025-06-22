#ifndef SCENE_H
#define SCENE_H

#include<raylib.h>
#include"map_data.h"

typedef enum {
    STATE_MENU,
    STATE_MAP_SELECT,
    STATE_GAME,
    STATE_MAP_END
} GameState;


typedef struct {
    Rectangle playButton, quitButton;
    int selectMapIndex;
    GameState currentState;
    int screenWidth, screenHeight;
    int buttonWidth, buttonHeight;
    float rotation;

    MapData currentMap;

} GameData;


/**
 @param GameData struct
@param bool shouldExit (error handling)

 @return renders the main menu
 */
void DrawMenuScene(GameData *game, bool *shouldExit);

/**
 @param GameData struct
 
 @return renders the map selection scenen
*/
void DrawMapSelectScene(GameData *game);

/**
 @param GameData struct

 @return renders the game scene
*/
void DrawGameScene(GameData *game);


/**
 
*/
void DrawMapEndScene(GameData *game);
#endif