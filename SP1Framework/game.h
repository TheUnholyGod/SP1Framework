#ifndef _GAME_H
#define _GAME_H

#include "Framework\timer.h"
#include "Framework\console.h"
#include "loadlevel.h"
#include "collision.h"
//#include "AI Pathfinding.h"
#include "menu.h"
#include "levelTransition.h"
#include "editor.h"
#include "combat.h"
#include "creative.h"
#include "instruction.h"
#include "load.h"
#include "doors.h"
#include "movableObj.h"
#include "reset.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "smashableObject.h"

extern CStopWatch g_swTimer;
extern bool g_bQuitGame;

// Enumeration to store the control keys that your game will have
enum EKEYS
{
	K_UP,
	K_DOWN,
	K_LEFT,
	K_RIGHT,
	K_ESCAPE,
	K_SPACE,
	K_M,
	K_E,
	K_L,
	K_W,
	K_D,
	K_K,
	K_Q,
	K_C,
	K_S,
	K_B,
	K_R,
	K_P,
	K_O,
	K_T,
    K_COUNT
};

// Enumeration for the different screen states
enum EGAMESTATES
{
    S_SPLASHSCREEN,
    S_GAME,
	S_MENU,
	S_COMBAT,
    S_COUNT,
	S_EDITOR,
	S_CREATIVE,
	S_LOADGAME,
	S_LOADCREATIVE,
	S_LOADEDITOR
};

// struct for the game character
struct SGameChar
{
    COORD m_cLocation;
    bool  m_bActive;
};
// struct for the editor cursor
struct SEditor
{
	COORD m_cEditorLocation;
};
//struct for the creative character
struct SCreaChar
{
	COORD m_cCreativeLocation;
};
//struct for menu selector
struct SSelector
{
	COORD m_cSelectorLocation;
};


void init        ( void );      // initialize your variables, allocate memory, etc
void getInput    ( void );      // get input from player
void update      ( double dt ); // update the game and the state of the game
void render      ( void );      // renders the current state of the game to the console
void shutdown    ( void );      // do clean up, free memory

void splashScreenWait();    // waits for time to pass in splash screen
void gameplay();            // gameplay logic
void moveCharacter();       // moves the character, collision detection, physics, etc
void processUserInput();    // checks if you should change states or do something else with the game, e.g. pause, exit
void clearScreen();         // clears the current screen and draw from scratch 
void renderSplashScreen();  // renders the splash screen
void mapFiles();            // To extract the map from .txt <---- additional function created by mc
void renderGame();          // renders the game stuff
void renderMap();           // renders the map to the buffer first
void renderCharacter();     // renders the character into the buffer
void renderFramerate();     // renders debug information, frame rate, elapsed time, etc
void renderToScreen();      // dump the contents of the buffer to the screen, one frame worth of game

#endif // _GAME_H