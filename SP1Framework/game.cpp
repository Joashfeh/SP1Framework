
#include <cstring>
#include "game.h"
#include "Map.h"
#include "Framework\console.h"
#include "Player.h"
#include "renderCharacter.h"
#include "renderMap.h"
#include "generateMap.h"
#include "keyEvents.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Entity.h"
#include "Enemy.h"
#include "renderBattle.h"
#include "renderMainMenu.h"
#include "updateMainMenu.h"
#include "updateBattle.h"
#include "renderShop.h"
#include "updateShop.h"

double  g_dElapsedTime;
double  g_dDeltaTime;

SKeyEvent g_skKeyEvent[K_COUNT];
SMouseEvent g_mouseEvent;

// Game specific variables here
Map map;
Player plr;
Enemy* enemies[3] = { nullptr, nullptr, nullptr };

Enemy* battleEnemy = nullptr;
int battleTurn = 1;
bool showMessage;

SGameChar   g_sChar;
EGAMESTATES g_eGameState = S_SPLASHSCREEN; // initial state

// Console object
Console g_Console(120, 40, "SP1 Framework");

void init( void )
{
    generateMap(map, plr, enemies, 4);

    // Set precision for floating point output
    g_dElapsedTime = 0.0;    

    // sets the initial state for the game
    g_eGameState = S_MAINSCREEN;

    showMessage = false;

    g_sChar.m_cLocation.X = g_Console.getConsoleSize().X / 2;
    g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y / 2;
    g_sChar.m_bActive = true;
    g_sChar.canBattle[0] = false;
    g_sChar.canBattle[1] = false;
    g_sChar.canBattle[2] = false;
    g_sChar.frameTimer = 0;
    // sets the width, height and the font name to use in the console
    g_Console.setConsoleFont(0, 16, L"Consolas");

    // remember to set your keyboard handler, so that your functions can be notified of input events
    g_Console.setKeyboardHandler(keyboardHandler);
    g_Console.setMouseHandler(mouseHandler);

}

void shutdown( void )
{

    // Reset to white text on black background
    colour(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

    g_Console.clearBuffer();
}

void getInput( void )
{
    // resets all the keyboard events
    memset(g_skKeyEvent, 0, K_COUNT * sizeof(*g_skKeyEvent));
    // then call the console to detect input from user
    g_Console.readConsoleInput();    
}

void keyboardHandler(const KEY_EVENT_RECORD& keyboardEvent)
{    
    switch (g_eGameState)
    {
    case S_SPLASHSCREEN: // don't handle anything for the splash screen
        break;
    case S_GAME: gameplayKBHandler(keyboardEvent); // handle gameplay keyboard event 
        break;
    case S_SHOP: gameplayKBHandler(keyboardEvent);
        break;
    case S_MAINSCREEN: gameplayKBHandler(keyboardEvent);
        break;
    }
}

void mouseHandler(const MOUSE_EVENT_RECORD& mouseEvent)
{    
    switch (g_eGameState)
    {
    case S_SPLASHSCREEN: // don't handle anything for the splash screen
        break;
    case S_GAME: gameplayMouseHandler(mouseEvent); // handle gameplay mouse event
        break;
    case S_BATTLE: gameplayMouseHandler(mouseEvent);
        break;
    case S_SHOP: gameplayMouseHandler(mouseEvent);
        break;
    }
}

void gameplayKBHandler(const KEY_EVENT_RECORD& keyboardEvent)
{
    // here, we map the key to our enums
    EKEYS key = K_COUNT;
    switch (keyboardEvent.wVirtualKeyCode)
    {
    case VK_UP: key = K_UP; break;
    case VK_DOWN: key = K_DOWN; break;
    case VK_LEFT: key = K_LEFT; break; 
    case VK_RIGHT: key = K_RIGHT; break;
    case 0x43: key = K_SHOP; break;
    case VK_SPACE: key = K_SPACE; break;
    case VK_ESCAPE: key = K_ESCAPE; break; 
    }
    // a key pressed event would be one with bKeyDown == true
    // a key released event would be one with bKeyDown == false
    // if no key is pressed, no event would be fired.
    // so we are tracking if a key is either pressed, or released
    if (key != K_COUNT)
    {
        g_skKeyEvent[key].keyDown = keyboardEvent.bKeyDown;
        g_skKeyEvent[key].keyReleased = !keyboardEvent.bKeyDown;
    }    
}

void gameplayMouseHandler(const MOUSE_EVENT_RECORD& mouseEvent)
{
    if (mouseEvent.dwEventFlags & MOUSE_MOVED) // update the mouse position if there are no events
    {
        g_mouseEvent.mousePosition = mouseEvent.dwMousePosition;
    }
    g_mouseEvent.buttonState = mouseEvent.dwButtonState;
    g_mouseEvent.eventFlags = mouseEvent.dwEventFlags;
}


void update(double dt)
{
    // get the delta time
    g_dElapsedTime += dt;
    g_dDeltaTime = dt;

    switch (g_eGameState)
    {
        case S_SPLASHSCREEN : splashScreenWait(); // game logic for the splash screen
            break;
        case S_MAINSCREEN: updateMainMenu(g_skKeyEvent, g_eGameState);
            break;
        case S_GAME: updateGame(); // gameplay logic when we are in the game
            break;
        case S_BATTLE: updateBattle(g_Console, g_mouseEvent, g_eGameState, plr, *battleEnemy, battleTurn, g_dDeltaTime);
            break;
        case S_SHOP: updateShop(g_Console, g_mouseEvent, g_skKeyEvent, g_eGameState);
             break;
        case S_GAMEOVER:
            break;
    }
}


void splashScreenWait()    // waits for time to pass in splash screen
{
    if (g_dElapsedTime > 3.0) // wait for 3 seconds to switch to game mode, else do nothing
        g_eGameState = S_GAME;
}

void updateGame()       // gameplay logic
{
    for (int i = 0; i < 3; i++) {
        if (enemies[i] != nullptr) {
            int plrRow = plr.Pos.row;
            int plrCol = plr.Pos.col;

            int enemyRow = enemies[i]->Pos.row;
            int enemyCol = enemies[i]->Pos.col;
            if (pow((enemyRow - plrRow), 2) + pow((enemyCol - plrCol), 2) < 3) {
                enemies[i]->inRange = true;
            }
            else {
                enemies[i]->inRange = false;
            }

            if (enemies[i]->HP == 0) {
                map.display[enemies[i]->Pos.row][enemies[i]->Pos.col] = '0';
                delete enemies[i];
                enemies[i] = nullptr;
                return;
            }

            if (enemies[i]->inRange)
                g_sChar.canBattle[i] = true;

            else if (!enemies[i]->inRange)
                g_sChar.canBattle[i] = false;

            if (g_skKeyEvent[K_SPACE].keyDown)
            {
                if (g_sChar.canBattle[i] == true) {
                    g_eGameState = S_BATTLE;
                    battleEnemy = enemies[i];
                }
            }
        }
    }
    


    // check if player is on ladder

    int ladderPosX;
    int ladderPoxY;

    for (int row = 0; row < 96; row++) {
        for (int col = 0; col < 192; col++) {
            if (map.display[row][col] == 'L') {
                ladderPosX = col;
                ladderPoxY = row;
            }
        }
    }

    if (ladderPosX == plr.Pos.col && ladderPoxY == plr.Pos.row) {
        if (Enemy::enemyCount == 0) {          
            generateMap(map, plr, enemies, ++map.floor);
            plr.HP = 100;
        }

        else
            showMessage = true;
    }
    else showMessage = false;

    if (map.floor == 13)
        g_eGameState = S_FINISH;

    processUserInput(); // checks if you should change states or do something else with the game, e.g. pause, exit
    moveCharacter();    // moves the character, collision detection, physics, etc
    moveChar(g_sChar, plr, map, g_dDeltaTime);                    // sound can be played here too.
}


void processUserInput()
{
    // quits the game if player hits the escape key
    if (g_skKeyEvent[K_ESCAPE].keyReleased)
        g_bQuitGame = true;
    if (g_skKeyEvent[K_SHOP].keyDown)
    {
        if (g_eGameState == S_GAME)
            g_eGameState = S_SHOP;
        else if (g_eGameState == S_SHOP)
            g_eGameState = S_GAME;
    }
}

void render()
{
    clearScreen();      // clears the current screen and draw from scratch 
    switch (g_eGameState)
    {
    case S_SPLASHSCREEN: renderSplashScreen();
        break;
    case S_MAINSCREEN: renderMainMenu(g_Console);
        break;
    case S_GAME: renderGame();
        break;
    case S_SHOP: renderShop(g_Console);
        break;
    case S_BATTLE: renderBattle(g_dDeltaTime, g_Console, plr, *battleEnemy);
        break;
    }
    renderFramerate();      // renders debug information, frame rate, elapsed time, etc
    renderInputEvents();    // renders status of input events
    renderToScreen();       // dump the contents of the buffer to the screen, one frame worth of game
}

void clearScreen()
{
    // Clears the buffer with this colour attribute
    g_Console.clearBuffer(0);
}

void renderToScreen()
{
    // Writes the buffer to the console, hence you will see what you have written
    g_Console.flushBufferToConsole();
}

void renderSplashScreen()  // renders the splash screen
{
    COORD c = g_Console.getConsoleSize();
    c.Y /= 3;
    c.X = c.X / 2 - 9;
    g_Console.writeToBuffer(c, "A game in 3 seconds", 0x03);
    c.Y += 1;
    c.X = g_Console.getConsoleSize().X / 2 - 20;
    g_Console.writeToBuffer(c, "Press <Space> to change character colour", 0x09);
    c.Y += 1;
    c.X = g_Console.getConsoleSize().X / 2 - 9;
    g_Console.writeToBuffer(c, "Press 'Esc' to quit", 0x09);
}

void renderGame()
{
    
    renderMap(g_Console, plr, map);        // renders the map to the buffer first
    renderCharacter(g_sChar, g_Console);  // renders the character into the buffer

    std::string message = "You have not defeated all the enemies!";
    if (showMessage == true)
        g_Console.writeToBuffer(g_Console.getConsoleSize().X / 2 - message.size() / 2, 3, message);
}

void renderFramerate()
{
    COORD c;
    // displays the framerate
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(3);
    ss << 1.0 / g_dDeltaTime << "fps";
    c.X = g_Console.getConsoleSize().X - 9;
    c.Y = 0;
    g_Console.writeToBuffer(c, ss.str());

    ss.str("");
    ss << "Floor: " << map.floor;
    c.Y += 2;
    g_Console.writeToBuffer(c, ss.str());

    c.X = g_Console.getConsoleSize().X - 15;
    c.Y = 0;
    g_Console.writeToBuffer(c, std::to_string(Enemy::enemyCount));

    //c.X = g_Console.getConsoleSize().X - 9;
    //c.Y++;
    // g_Console.writeToBuffer(c, g_sChar.dir);

    // displays the elapsed time
    ss.str("");
    ss << g_dElapsedTime << "secs";
    c.X = 0;
    c.Y = 0;
    g_Console.writeToBuffer(c, ss.str(), 0x59);
}

// this is an example of how you would use the input events
void renderInputEvents()
{
    // keyboard events
    COORD startPos = {48, 2};
    std::ostringstream ss;
    std::string key;
    /*for (int i = 0; i < K_COUNT; ++i)
    {
        ss.str("");
        switch (i)
        {
        case K_UP: key = "UP";
            break;
        case K_DOWN: key = "DOWN";
            break;
        case K_LEFT: key = "LEFT";
            break;
        case K_RIGHT: key = "RIGHT";
            break;
        case K_SPACE: key = "SPACE";
            break;
        default: continue;
        }
        if (g_skKeyEvent[i].keyDown)
            ss << key << " pressed";
        else if (g_skKeyEvent[i].keyReleased)
            ss << key << " released";
        else
            ss << key << " not pressed";

        COORD c = { startPos.X, startPos.Y + i };
        g_Console.writeToBuffer(c, ss.str(), 0x17);
    }*/

    // mouse events    
    // g_mouseEvent.mousePosition.X
    // g_mouseEvent.mousePosition.Y 
    ss.str("");
    ss << "Player position (" << plr.Pos.col << ", " << plr.Pos.row << ")";
    g_Console.writeToBuffer(g_mouseEvent.mousePosition, ss.str(), 0x59);
    ss.str("");
    switch (g_mouseEvent.eventFlags)
    {
    case 0:
        if (g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED)
        {
            ss.str("Left Button Pressed");
            g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 1, ss.str(), 0x59);
        }
        else if (g_mouseEvent.buttonState == RIGHTMOST_BUTTON_PRESSED)
        {
            ss.str("Right Button Pressed");
            g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 2, ss.str(), 0x59);
        }
        else
        {
            ss.str("Some Button Pressed");
            g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 3, ss.str(), 0x59);
        }
        break;
    case DOUBLE_CLICK:
        ss.str("Double Clicked");
        g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 4, ss.str(), 0x59);
        break;        
    case MOUSE_WHEELED:
        if (g_mouseEvent.buttonState & 0xFF000000)
            ss.str("Mouse wheeled down");
        else
            ss.str("Mouse wheeled up");
        g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 5, ss.str(), 0x59);
        break;
    default:        
        break;
    }
    
}

void moveCharacter() {

    if (g_skKeyEvent[K_UP].keyDown)
    {   
        g_sChar.moving.UP = true;
    }
    if (g_skKeyEvent[K_RIGHT].keyDown)
    {
        g_sChar.moving.RIGHT = true;
    }
    if (g_skKeyEvent[K_DOWN].keyDown)
    {
        g_sChar.moving.DOWN = true;
    }
    if (g_skKeyEvent[K_LEFT].keyDown)
    {
        g_sChar.moving.LEFT = true;
    }

    if (g_skKeyEvent[K_UP].keyReleased)
    {
        g_sChar.moving.UP = false;
    }
    if (g_skKeyEvent[K_RIGHT].keyReleased)
    {
        g_sChar.moving.RIGHT = false;
    }
    if (g_skKeyEvent[K_DOWN].keyReleased)
    {
        g_sChar.moving.DOWN = false;
    }
    if (g_skKeyEvent[K_LEFT].keyReleased)
    {
        g_sChar.moving.LEFT = false;
    }
}

