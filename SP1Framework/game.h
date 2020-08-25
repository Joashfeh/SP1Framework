#ifndef _GAME_H
#define _GAME_H

#include "Position.h"
#include "Framework\timer.h"
#include "Framework\console.h"
#include "generateMap.h"

extern CStopWatch g_swTimer;
extern bool g_bQuitGame;

// Enumeration for the different screen states
enum EGAMESTATES
{
    S_SPLASHSCREEN,
    S_GAME,
    S_SHOP,
    S_INVENTORY,
    S_BATTLE,
    S_GAMEOVER,
    S_FINISH,
    S_COUNT,
    S_MAINSCREEN
};

void init        ( void );      // initialize your variables, allocate memory, etc
void update      ( double dt ); // update the game and the state of the game
void render      ( void );      // renders the current state of the game to the console
void shutdown    ( void );      // do clean up, free memory

void splashScreenWait();    // waits for time to pass in splash screen
void updateGame();          // gameplay logic
void processUserInput();    // checks if you should change states or do something else with the game, e.g. pause, exit
void clearScreen();         // clears the current screen and draw from scratch 
void renderGame();          // renders the game stuff
void renderSplashScreen();  // renders the splash screen
void renderFramerate();     // renders debug information, frame rate, elapsed time, etc
void renderToScreen();      // dump the contents of the buffer to the screen, one frame worth of game
void renderInputEvents();   // renders the status of input events
void gameplayKBHandler(const KEY_EVENT_RECORD& keyboardEvent);
void gameplayMouseHandler(const MOUSE_EVENT_RECORD& mouseEvent);
void getInput();
void keyboardHandler(const KEY_EVENT_RECORD& keyboardEvent);
void mouseHandler(const MOUSE_EVENT_RECORD& mouseEvent);
void moveCharacter();       // moves the character, collision detection, physics, etc
void spawnGoldCrate(Map& map);

#endif // _GAME_H