// This is the main file for the game logic and function
//
//
#include "game.h"

using namespace std;

double  g_dElapsedTime;
double  g_dDeltaTime;
double  g_dSpikeTriggerTime;
double	g_dSpikeActivationTime;
double  g_dDeathPitTriggerTime;
double	g_dDeathPitActivationTime;
double	g_dProjectileTravelTime;
double	g_dProjectileFireTime;
double	g_dProjectileWaitTime;
bool DeathPitOpened;
bool SpikesActivated;
bool SpikeSwitch;
bool ProjectileFired;
bool ProjectileCollision;
double  g_flareTime;
bool    g_abKeyPressed[K_COUNT];
char    map[40][130]; // <------ load map into this array
bool    g_isMapLoaded;
bool    g_isTorchEnabled;
bool    g_Level;
bool    g_isflareActive;
bool    g_isTimerStarted;
int     g_KeysObtain, g_PicksObtain;
int     g_flares;
string  g_playerDirection;

// Game specific variables here
int character_X;
int character_Y;
int g_CurrentLevel;
int g_CreativeLevel;
SGameChar   g_sChar;
vector<AI *>EnemyArray;
AI * AIEnemy;
vector<Projectile *>ProjectileArray;
Projectile * AIProjectile;
SEditor     g_sCursor;
SCreaChar   g_sCreaChar;
SSelector   g_sSelector;
EGAMESTATES g_eGameState = S_SPLASHSCREEN;

double  g_dBounceTime; // this is to prevent key bouncing, so we won't trigger keypresses more than once
double	g_dProjBounceTime;
double	g_dEnemyBounceTime;
double  g_SlidingSpeed; // this is to control the speed of sliding
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
	store_map(1000); //stores splash screen map

    // Set precision for floating point output
    g_dElapsedTime = 0.0;
    g_dBounceTime = 0.0;
	g_dElapsedTime = 0.0;
	g_dBounceTime = 0.0;
	g_dProjBounceTime = 0.0;
	g_dEnemyBounceTime = 0.0;
	g_dSpikeTriggerTime = 5.0;
	g_dSpikeActivationTime = 8.0;
	g_dDeathPitTriggerTime = 9.0;
	g_dDeathPitActivationTime = 12.0;
	g_dProjectileFireTime = 0.5;
	g_SlidingSpeed = 0.0;
	g_flareTime = 0.0;
    // sets the initial state for the game
	g_isMapLoaded = false;
	g_isTorchEnabled = true;
	SpikesActivated = false;
	DeathPitOpened = false;
	ProjectileFired = true;
	ProjectileCollision = false;
	g_isTimerStarted = false;
	g_KeysObtain = 0;
	g_PicksObtain = 0;
	g_flares = 3;
	g_playerDirection = "NULL";
    g_eGameState = S_SPLASHSCREEN;
	g_CurrentLevel = 1;
	g_CreativeLevel = 101;
	if (g_CurrentLevel == 1)
	{
		AIEnemy = new class AI;
		AIEnemy->m_eLocation.X = 3;
		AIEnemy->m_eLocation.Y = 7;
		AIEnemy->AI_id = 1;
		EnemyArray.push_back(AIEnemy);


		AIEnemy = new class AI;
		AIEnemy->m_eLocation.X = 4;
		AIEnemy->m_eLocation.Y = 8;
		AIEnemy->AI_id = 2;
		EnemyArray.push_back(AIEnemy);
	}

	if (g_CurrentLevel == 1)
	{
		AIProjectile = new class Projectile;
		AIProjectile->m_pLocation.X = 2;
		AIProjectile->m_pLocation.Y = 4;
		AIProjectile->Proj_id = 1;
		ProjectileArray.push_back(AIProjectile);
	}

	// sets the initial position of the character
	g_sChar.m_cLocation.X = 1; //g_Console.getConsoleSize().X / 2;
	g_sChar.m_cLocation.Y = 2;//g_Console.getConsoleSize().Y / 2;
    g_sChar.m_bActive = true;
	// sets the initial position of the cursor
	g_sCursor.m_cEditorLocation.X = g_Console.getConsoleSize().X / 2;
	g_sCursor.m_cEditorLocation.Y = g_Console.getConsoleSize().Y / 2;
	// set initial position of the creative character
	g_sCreaChar.m_cCreativeLocation.X = 1;
	g_sCreaChar.m_cCreativeLocation.Y = 2;
	// set initial position of the menu selector
	g_sSelector.m_cSelectorLocation.X = 50;
	g_sSelector.m_cSelectorLocation.Y = 16;
    // sets the width, height and the font name to use in the console
    g_Console.setConsoleFont(0, 16, L"Raster");

	//Initializes the Player
	combatinit();
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
	//TODO: Clean up double pointer arrays here
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
	g_abKeyPressed[K_C]      = isKeyPressed(0x43);
	g_abKeyPressed[K_S]      = isKeyPressed(0x53);
	g_abKeyPressed[K_B]      = isKeyPressed(0x42);
	g_abKeyPressed[K_R]      = isKeyPressed(0x52);
	g_abKeyPressed[K_P]      = isKeyPressed(0x50);
	g_abKeyPressed[K_O]      = isKeyPressed(0x4F);
	g_abKeyPressed[K_T]      = isKeyPressed(0x54);
	g_abKeyPressed[K_I]      = isKeyPressed(0x49);
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
	switch (g_eGameState)
    {
        case S_SPLASHSCREEN : splashScreenWait(); // game logic for the splash screen
            break;
        case S_GAME: gameplay(); // gameplay logic when we are in the game
            break;
		case S_MENU: mainmenu(); //process user inputs and decide which state the program will enter
			break;
		case S_EDITOR: editor(); //process user inputs, move cursor and make amends to map array
			break;
		case S_COMBAT: combat(); 
			break;
		case S_CREATIVE: creativeGameplay(); //Creative mode, plays user created levels
			break;
		case S_LOADGAME: loadingGame(); //initialise maps based on level number, then changes to game state
			break;
		case S_LOADCREATIVE: loadingCreative(); //initialise maps based on level number, then changes to creative game state
			break;
		case S_LOADEDITOR: loadingEditor();
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
	{
		clearScreen();        // clears the current screen and draw from scratch 
		renderFramerate();    // renders debug information, frame rate, elapsed time, etc
		switch (g_eGameState)
		{
		case S_SPLASHSCREEN: renderSplashScreen(); //stores the splash screen map into array and renders it
			break;
		case S_GAME: renderGame();
			break;
		case S_MENU: renderMenu();
			break;
		case S_EDITOR: renderEditor();
			break;
		case S_COMBAT: combatdisplay();
			break;
		case S_CREATIVE: renderCreative();
			break;
		}
		renderToScreen();   // dump the contents of the buffer to the screen, one frame worth of game
	}
}

void splashScreenWait()    // waits for time to pass in splash screen
{
	if (g_dElapsedTime > 2.0) // wait for 2 seconds to switch to game mode, else do nothing
	{
		g_eGameState = S_MENU;
		//play music
		PlaySound(TEXT("Music.wav"), NULL, SND_ASYNC);
	}
}

void gameplay()            // gameplay logic
{
	KeyObtain();
	DoorOpen();
	pickObtain();
	objectStatus();
	updateSlide();
	sliding();
	flare();
	checkGameGoal();
	Spikes();
	DeathPit();
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
	
	if (g_abKeyPressed[K_T])
	{
		if (g_flares > 0)
		{
			g_flares--;
			g_isTimerStarted = false;
			g_isflareActive = true;
		}
		bSomethingHappened = true;
	}
    if (g_abKeyPressed[K_UP] && g_sChar.m_cLocation.Y > 0)
    {
		moveBoulder();
        //Beep(1440, 30);
	// --------------------------------- UNABLE TO MOVE UP IF ITS NOT ' ' ---------------------------------------------// 
		if (colDetection(g_CurrentLevel))
		{
			g_sChar.m_cLocation.Y--;
			bSomethingHappened = true;
		}

    }
    if (g_abKeyPressed[K_LEFT] && g_sChar.m_cLocation.X > 0)
    {
		moveBoulder();
        //Beep(1440, 30);
	// --------------------------------- UNABLE TO MOVE LEFT IS ITS NOT ' ' -------------------------------------------//
		if (colDetection(g_CurrentLevel))
		{
			g_sChar.m_cLocation.X--;
			bSomethingHappened = true;
		}

    }
    if (g_abKeyPressed[K_DOWN] && g_sChar.m_cLocation.Y < g_Console.getConsoleSize().Y - 1)
    {
		moveBoulder();
        //Beep(1440, 30);
	// ---------------------------------- UNABLE TO MOVE DOWN IF ITS NOT ' ' -----------------------------------------//
		if (colDetection(g_CurrentLevel))
		{
			
			g_sChar.m_cLocation.Y++;
			bSomethingHappened = true;
		}
    }
    if (g_abKeyPressed[K_RIGHT] && g_sChar.m_cLocation.X < g_Console.getConsoleSize().X - 1)
    {
		moveBoulder();
        //Beep(1440, 30);
	// ---------------------------------- UNABLE TO MOVE RIGHT IF ITS NOT ' ' ----------------------------------------//
		if (colDetection(g_CurrentLevel))
		{
			
			g_sChar.m_cLocation.X++;
			bSomethingHappened = true;
		}
        
    }
    if (g_abKeyPressed[K_SPACE])
    {
        g_sChar.m_bActive = !g_sChar.m_bActive;
        bSomethingHappened = true;
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
		}
		if (g_abKeyPressed[K_R])
		{
			reset();
		}
	}
	if (g_eGameState == S_EDITOR)
	{
		if (g_abKeyPressed[K_M])
		{
			g_eGameState = S_MENU;
		}
		if (g_abKeyPressed[K_C])
		{
			g_eGameState = S_LOADCREATIVE;
		}
		if (g_abKeyPressed[K_S])
		{
			saveMap(g_CreativeLevel);
		}
	}
	if (g_eGameState == S_CREATIVE)
	{
		if (g_abKeyPressed[K_M])
		{
			g_eGameState = S_MENU;
		}
		if (g_abKeyPressed[K_L])
		{
			g_eGameState = S_LOADEDITOR;
		}
		if (g_abKeyPressed[K_R])
		{
			reset();
		}
	}

}

void clearScreen()
{
    // Clears the buffer with this colour attribute
    g_Console.clearBuffer(0x0F);
}

void renderSplashScreen()  // renders the splash screen
{
	print_map();
}

void renderGame()
{
	renderGameInstruction();
    renderMap();        // renders the map to the buffer first
    renderCharacter();  // renders the character into the buffer
	renderEnemy();
	renderProjectile();
}

void renderMap()
{
	// -------- TO STOP FLICKERING, DO CHECK CONDITION! IF CHARACTER IS NOT MOVING: STOP RENDERING, ELSE RENDER AGAIN! -------- //
	print_map();
}

void renderCharacter()
{
	// Draw the location of the character
	WORD charColor = 0x0C;
	g_Console.writeToBuffer(g_sChar.m_cLocation, (char)178, charColor);

}
void renderEnemy()
{
	WORD enemyColor = 0xFF;

	EnemyArray.at(0)->RandomDirection();
	
	g_Console.writeToBuffer(EnemyArray.at(0)->m_eLocation, (char)178, enemyColor);
	g_Console.writeToBuffer(EnemyArray.at(1)->m_eLocation, (char)178, enemyColor);


}
void renderProjectile()
{
	WORD projectileColor = 0x06;
	
	ProjectileArray.at(0)->ProjectileFire('s', 2, 4);

	g_Console.writeToBuffer(ProjectileArray.at(0)->m_pLocation, (char)164, projectileColor);


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
