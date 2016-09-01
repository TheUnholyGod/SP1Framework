#include "creative.h"
extern Player player1;
extern bool g_isKeyObtain;
extern bool g_isMapLoaded;
extern char** creative;
extern int g_CreativeLevel;
extern SEditor g_sCursor;
extern SCreaChar g_sCreaChar;
extern double  g_dBounceTime;
extern double  g_dElapsedTime;
extern bool    g_abKeyPressed[K_COUNT];
extern bool    g_isTorchEnabled;
extern int cX;
extern int cY;
extern int g_flares;
extern bool g_isTimerStarted;
extern bool g_isflareActive;
extern char map[40][130];
extern EGAMESTATES g_eGameState;

void creativeGameplay()
{
	if (map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X] == (char)255)
	{
		g_eGameState = S_GAMEOVER;
	}
	if (map[g_sCreaChar.m_cCreativeLocation.X][g_sCreaChar.m_cCreativeLocation.Y] == (char)215)
	{
		player1.healthUpdate(10);
	}
	KeyObtain();
	DoorOpen();
	pickObtain();
	objectStatus();
	updateSlide();
	sliding();
	flare();
	checkCreativeGameGoal();
	processUserInput();
	creativeMoveCharacter();
}
void creativeMoveCharacter()
{
	bool bSomethingHappened = false;
	if (g_dBounceTime > g_dElapsedTime)
		return;
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
	// Updating the location of the character based on the key press
	if (g_abKeyPressed[K_UP] && g_sCreaChar.m_cCreativeLocation.Y > 1)
	{
		moveBoulder();
		if (creativeColDetection(g_CreativeLevel))
		{
			g_sCreaChar.m_cCreativeLocation.Y--;
			bSomethingHappened = true;
		}

	}
	if (g_abKeyPressed[K_LEFT] && g_sCreaChar.m_cCreativeLocation.X > 0)
	{
		moveBoulder();
		if (creativeColDetection(g_CreativeLevel))
		{
			g_sCreaChar.m_cCreativeLocation.X--;
			bSomethingHappened = true;
		}

	}
	if (g_abKeyPressed[K_DOWN] && g_sCreaChar.m_cCreativeLocation.Y < g_Console.getConsoleSize().Y - 15)
	{
		moveBoulder();
		if (creativeColDetection(g_CreativeLevel))
		{
			g_sCreaChar.m_cCreativeLocation.Y++;
			bSomethingHappened = true;
		}
	}
	if (g_abKeyPressed[K_RIGHT] && g_sCreaChar.m_cCreativeLocation.X < g_Console.getConsoleSize().X - 1)
	{
		moveBoulder();
		if (creativeColDetection(g_CreativeLevel))
		{
			g_sCreaChar.m_cCreativeLocation.X++;
			bSomethingHappened = true;
		}

	}
	if (bSomethingHappened)
	{
		// set the bounce time to some time in the future to prevent accidental triggers
		g_dBounceTime = g_dElapsedTime + 0.125; // 125ms should be enough
		g_isMapLoaded = false;
	}
}
void renderCreative()
{
	renderCreativeInstruction();
	creativeRenderMap();
	creativeRenderCharacter();
}
void creativeRenderMap()
{
	print_map();
}
void creativeRenderCharacter()
{
	WORD color = 0x0A;
	g_Console.writeToBuffer(g_sCreaChar.m_cCreativeLocation, (char)178, color);
}
