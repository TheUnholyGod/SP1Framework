// This is the main file for the game logic and function
//
//
#include "game.h"

using namespace std;

double  g_dElapsedTime;
double  g_dDeltaTime;
bool    g_abKeyPressed[K_COUNT];
char** txt = new char*[100]; // <------- Read levels from txt into this 2d array
bool g_isUpdated;

// Game specific variables here
extern int character_X;
extern int character_Y;
int g_CurrentLevel;
SGameChar   g_sChar;
Enemy	g_sEnemy;
Enemy enemies[100];
SEditor     g_sCursor;
EGAMESTATES g_eGameState = S_SPLASHSCREEN;

double  g_dBounceTime; // this is to prevent key bouncing, so we won't trigger keypresses more than once
// Console object
Console g_Console(130, 40, "SP1 Framework");

//--------------------------------------------------------------
// Purpose  : Initialisation function
//            Initialize variables, allocate memory, load data from file, etc. 
//            This is called once before entering into your main loop
// Input    : void
// Output   : void
//--------------------------------------------------------------
void init( void )
{
    // Set precision for floating point output
    g_dElapsedTime = 0.0;
    g_dBounceTime = 0.0;

    // sets the initial state for the game
	g_isUpdated = false;
    g_eGameState = S_SPLASHSCREEN;
	g_CurrentLevel = 1;
	// sets the initial position of the character
	g_sChar.m_cLocation.X = 1; //g_Console.getConsoleSize().X / 2;
	g_sChar.m_cLocation.Y = 2;//g_Console.getConsoleSize().Y / 2;
	//g_sEnemy.m_eLocation.X = 25;
	//g_sEnemy.m_eLocation.Y = 16;
    g_sChar.m_bActive = true;
	//g_sEnemy.m_bActive = true;
	g_sChar.m_cLocation.Y = 2; //g_Console.getConsoleSize().Y / 2;
    g_sChar.m_bActive = true;
	// sets the initial position of the cursor
	g_sCursor.m_cEditorLocation.X = g_Console.getConsoleSize().X / 2;
	g_sCursor.m_cEditorLocation.Y = g_Console.getConsoleSize().Y / 2;
    // sets the width, height and the font name to use in the console
    g_Console.setConsoleFont(0, 16, L"Consolas");

	//Initializes the Enemies
	enemyinit();
	//Initializes the Player
	playerinit();

}

//--------------------------------------------------------------
// Purpose  : Reset before exiting the program
//            Do your clean up of memory here
//            This is called once just before the game exits
// Input    : Void
// Output   : void
//--------------------------------------------------------------
void shutdown( void )
{
    // Reset to white text on black background
    colour(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
    g_Console.clearBuffer();
}

//--------------------------------------------------------------
// Purpose  : Getting all the key press states
//            This function checks if any key had been pressed since the last time we checked
//            If a key is pressed, the value for that particular key will be true
//
//            Add more keys to the enum in game.h if you need to detect more keys
//            To get other VK key defines, right click on the VK define (e.g. VK_UP) and choose "Go To Definition" 
//            For Alphanumeric keys, the values are their ascii values (uppercase).
// Input    : Void
// Output   : void
//--------------------------------------------------------------
void getInput( void )
{    
    g_abKeyPressed[K_UP]     = isKeyPressed(VK_UP);
    g_abKeyPressed[K_DOWN]   = isKeyPressed(VK_DOWN);
    g_abKeyPressed[K_LEFT]   = isKeyPressed(VK_LEFT);
    g_abKeyPressed[K_RIGHT]  = isKeyPressed(VK_RIGHT);
    g_abKeyPressed[K_SPACE]  = isKeyPressed(VK_SPACE);
    g_abKeyPressed[K_ESCAPE] = isKeyPressed(VK_ESCAPE);
	g_abKeyPressed[K_M]      = isKeyPressed(0x4D);
	g_abKeyPressed[K_E]      = isKeyPressed(0x45);
	g_abKeyPressed[K_L]      = isKeyPressed(0x4C);
	g_abKeyPressed[K_W]      = isKeyPressed(0x57);
	g_abKeyPressed[K_D]      = isKeyPressed(0x44);
	g_abKeyPressed[K_Q]      = isKeyPressed(0x51);
	g_abKeyPressed[K_K]      = isKeyPressed(0x4B);

}

//--------------------------------------------------------------
// Purpose  : Update function
//            This is the update function
//            double dt - This is the amount of time in seconds since the previous call was made
//
//            Game logic should be done here.
//            Such as collision checks, determining the position of your game characters, status updates, etc
//            If there are any calls to write to the console here, then you are doing it wrong.
//
//            If your game has multiple states, you should determine the current state, and call the relevant function here.
//
// Input    : dt = deltatime
// Output   : void
//--------------------------------------------------------------
void update(double dt)
{
    // get the delta time
    g_dElapsedTime += dt;
    g_dDeltaTime = dt;
	txt = store_map(txt, g_CurrentLevel);
    switch (g_eGameState)
    {
        case S_SPLASHSCREEN : splashScreenWait(); // game logic for the splash screen
            break;
        case S_GAME: gameplay(); // gameplay logic when we are in the game
            break;
		case S_MENU: mainmenu();
			break;
		case S_EDITOR: editor();
			break;
		case S_COMBAT: combat();
			break;
    }
}
//--------------------------------------------------------------
// Purpose  : Render function is to update the console screen
//            At this point, you should know exactly what to draw onto the screen.
//            Just draw it!
//            To get an idea of the values for colours, look at console.h and the URL listed there
// Input    : void
// Output   : void
//--------------------------------------------------------------
void render()
{
	if (g_isUpdated == false)
	{
		clearScreen();      // clears the current screen and draw from scratch 
		switch (g_eGameState)
		{
		case S_SPLASHSCREEN: renderSplashScreen();
			g_isUpdated = false;
			break;
		case S_GAME: renderGame();
			g_isUpdated = false;
			break;
		case S_MENU: renderMenu();
			g_isUpdated = false;
			break;
		case S_EDITOR: renderEditor();
			g_isUpdated = false;
			break;
		case S_COMBAT: combatdisplay();
			g_isUpdated = false;
			break;
		}
		
		renderToScreen();   // dump the contents of the buffer to the screen, one frame worth of game
		g_isUpdated = true;
	}
	renderFramerate();  // renders debug information, frame rate, elapsed time, etc
}

void splashScreenWait()    // waits for time to pass in splash screen
{
    if (g_dElapsedTime > 2.0) // wait for 2 seconds to switch to game mode, else do nothing
        g_eGameState = S_MENU;
	g_isUpdated = false;
}

void gameplay()            // gameplay logic
{
	checkGameGoal();
    processUserInput(); // checks if you should change states or do something else with the game, e.g. pause, exit
    moveCharacter();    // moves the character, collision detection, physics, etc
                        // sound can be played here too.
}

void moveCharacter()
{
    bool bSomethingHappened = false;
    if (g_dBounceTime > g_dElapsedTime)
        return;
    // Updating the location of the character based on the key press
    // providing a beep sound whenver we shift the character
    if (g_abKeyPressed[K_UP] && g_sChar.m_cLocation.Y > 0)
    {
        //Beep(1440, 30);
	// --------------------------------- UNABLE TO MOVE UP IF ITS NOT ' ' ---------------------------------------------// 
		if (colDetection(g_CurrentLevel))
		{
			g_sChar.m_cLocation.Y--;
			bSomethingHappened = true;
			g_isUpdated = false;
		}

    }
    if (g_abKeyPressed[K_LEFT] && g_sChar.m_cLocation.X > 0)
    {
        //Beep(1440, 30);
	// --------------------------------- UNABLE TO MOVE LEFT IS ITS NOT ' ' -------------------------------------------//
		if (colDetection(g_CurrentLevel))
		{
			g_sChar.m_cLocation.X--;
			bSomethingHappened = true;
			g_isUpdated = false;
		}

    }
    if (g_abKeyPressed[K_DOWN] && g_sChar.m_cLocation.Y < g_Console.getConsoleSize().Y - 1)
    {
        //Beep(1440, 30);
	// ---------------------------------- UNABLE TO MOVE DOWN IF ITS NOT ' ' -----------------------------------------//
		if (colDetection(g_CurrentLevel))
		{
			g_sChar.m_cLocation.Y++;
			bSomethingHappened = true;
			g_isUpdated = false;
		}
    }
    if (g_abKeyPressed[K_RIGHT] && g_sChar.m_cLocation.X < g_Console.getConsoleSize().X - 1)
    {
        //Beep(1440, 30);
	// ---------------------------------- UNABLE TO MOVE RIGHT IF ITS NOT ' ' ----------------------------------------//
		if (colDetection(g_CurrentLevel))
		{
			g_sChar.m_cLocation.X++;
			bSomethingHappened = true;
			g_isUpdated = false;
		}
        
    }
    if (g_abKeyPressed[K_SPACE])
    {
        g_sChar.m_bActive = !g_sChar.m_bActive;
        bSomethingHappened = true;
		g_isUpdated = false;
    }

    if (bSomethingHappened)
    {
        // set the bounce time to some time in the future to prevent accidental triggers
        g_dBounceTime = g_dElapsedTime + 0.125; // 125ms should be enough
    }
}

void processUserInput()
{
	if (g_eGameState == S_GAME)
	{
		if (g_abKeyPressed[K_M])
		{
			g_eGameState = S_MENU;
			g_isUpdated = false;
		}
			
	}
	if (g_eGameState == S_MENU)
	{
		// quits the game if player hits the escape key
		if (g_abKeyPressed[K_ESCAPE])
			g_bQuitGame = true;
		// start game if player hits the space key
		if (g_abKeyPressed[K_SPACE])
		{
			g_eGameState = S_GAME;
			g_isUpdated = false;
		}
		// Go to the level editor mode (TO DO)
		if (g_abKeyPressed[K_E])
		{
			g_eGameState = S_EDITOR;
			g_isUpdated = false;
		}
		if (g_abKeyPressed[K_K])
		{
			g_eGameState = S_COMBAT;
			g_isUpdated = false;
		}
			
	}
	if (g_eGameState == S_EDITOR)
	{
		if (g_abKeyPressed[K_M])
		{
			g_eGameState = S_MENU;
			g_isUpdated = false;
		}
	}
}

void clearScreen()
{
    // Clears the buffer with this colour attribute
    g_Console.clearBuffer(0x1F);
}

void renderSplashScreen()  // renders the splash screen
{
	txt = store_map(txt, 1000);
	print_map(txt);
}

void renderGame()
{
    renderMap();        // renders the map to the buffer first
    renderCharacter();  // renders the character into the buffer
}

void renderMap()
{
	// -------- TO STOP FLICKERING, DO CHECK CONDITION! IF CHARACTER IS NOT MOVING: STOP RENDERING, ELSE RENDER AGAIN! -------- //
	print_map(txt);
}

void renderCharacter()
{ 
    // Draw the location of the character
    WORD charColor = 0x0A;
	WORD enemyColor = 0xFF;
    g_Console.writeToBuffer(g_sChar.m_cLocation, (char)178, charColor);

	//if (g_sEnemy.m_bActive)
	//{
	//	enemies[KAMBENG].EnemyMove(g_sChar.m_cLocation.Y, g_sChar.m_cLocation.X);
	//}
	//g_Console.writeToBuffer(g_sEnemy.m_eLocation, (char)178, enemyColor);
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

    // displays the elapsed time
    ss.str("");
    ss << g_dElapsedTime << "secs";
    c.X = 0;
    c.Y = 0;
    g_Console.writeToBuffer(c, ss.str(), 0x59);
}

void renderToScreen()
{
    // Writes the buffer to the console, hence you will see what you have written
    g_Console.flushBufferToConsole();
}
