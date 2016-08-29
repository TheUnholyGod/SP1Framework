#include "creative.h"

extern bool g_isKeyObtain;
extern bool g_isUpdated;
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

void creativeGameplay()
{
	KeyObtain();
	DoorOpen();
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
		g_isTorchEnabled = !g_isTorchEnabled;
		bSomethingHappened = true;
	}
	// Updating the location of the character based on the key press
	if (g_abKeyPressed[K_UP] && g_sCreaChar.m_cCreativeLocation.Y > 0)
	{
		moveBoulder();
		if (creativeColDetection(g_CreativeLevel))
		{
			g_sCreaChar.m_cCreativeLocation.Y--;
			bSomethingHappened = true;
			g_isUpdated = false;
		}

	}
	if (g_abKeyPressed[K_LEFT] && g_sCreaChar.m_cCreativeLocation.X > 0)
	{
		moveBoulder();
		if (creativeColDetection(g_CreativeLevel))
		{
			g_sCreaChar.m_cCreativeLocation.X--;
			bSomethingHappened = true;
			g_isUpdated = false;
		}

	}
	if (g_abKeyPressed[K_DOWN] && g_sCreaChar.m_cCreativeLocation.Y < g_Console.getConsoleSize().Y - 1)
	{
		moveBoulder();
		if (creativeColDetection(g_CreativeLevel))
		{
			g_sCreaChar.m_cCreativeLocation.Y++;
			bSomethingHappened = true;
			g_isUpdated = false;
		}
	}
	if (g_abKeyPressed[K_RIGHT] && g_sCreaChar.m_cCreativeLocation.X < g_Console.getConsoleSize().X - 1)
	{
		moveBoulder();
		if (creativeColDetection(g_CreativeLevel))
		{
			g_sCreaChar.m_cCreativeLocation.X++;
			bSomethingHappened = true;
			g_isUpdated = false;
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
