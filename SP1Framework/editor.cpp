#include "editor.h"

extern SEditor g_sCursor;
extern double  g_dBounceTime;
extern double  g_dElapsedTime;
extern bool    g_abKeyPressed[K_COUNT];

void renderEditor()
{
	//TO DO:
	//read the maps
	g_Console.writeToBuffer(1, 1, "THIS IS THE INTERFACE OF EDITOR");
	renderCursor();
}
void editor()
{
	moveCursor();
	processUserInput();
}
void moveCursor()
{
	bool bSomethingHappened = false;
	if (g_dBounceTime > g_dElapsedTime)
		return;
	// Updating the location of the character based on the key press
	// providing a beep sound whenver we shift the character
	if (g_abKeyPressed[K_UP] && g_sCursor.m_cEditorLocation.Y > 0)
	{
		//Beep(1440, 30);
		// --------------------------------- UNABLE TO MOVE UP IF ITS NOT ' ' ---------------------------------------------// 
		//if (colDetection(g_CurrentLevel))
		{
			g_sCursor.m_cEditorLocation.Y--;
			bSomethingHappened = true;
		}

	}
	if (g_abKeyPressed[K_LEFT] && g_sCursor.m_cEditorLocation.X > 0)
	{
		//Beep(1440, 30);
		// --------------------------------- UNABLE TO MOVE LEFT IS ITS NOT ' ' -------------------------------------------//
		//if (colDetection(g_CurrentLevel))
		{
			g_sCursor.m_cEditorLocation.X--;
			bSomethingHappened = true;
		}

	}
	if (g_abKeyPressed[K_DOWN] && g_sCursor.m_cEditorLocation.Y < g_Console.getConsoleSize().Y - 1)
	{
		//Beep(1440, 30);
		// ---------------------------------- UNABLE TO MOVE DOWN IF ITS NOT ' ' -----------------------------------------//
		//if (colDetection(g_CurrentLevel))
		{
			g_sCursor.m_cEditorLocation.Y++;
			bSomethingHappened = true;
		}
	}
	if (g_abKeyPressed[K_RIGHT] && g_sCursor.m_cEditorLocation.X < g_Console.getConsoleSize().X - 1)
	{
		//Beep(1440, 30);
		// ---------------------------------- UNABLE TO MOVE RIGHT IF ITS NOT ' ' ----------------------------------------//
		//if (colDetection(g_CurrentLevel))
		{
			g_sCursor.m_cEditorLocation.X++;
			bSomethingHappened = true;
		}

	}
	if (bSomethingHappened)
	{
		// set the bounce time to some time in the future to prevent accidental triggers
		g_dBounceTime = g_dElapsedTime + 0.125; // 125ms should be enough
	}
}

void renderCursor()
{
	// Draw the location of the cursor
	WORD charColor = 0x0C;
	g_Console.writeToBuffer(g_sCursor.m_cEditorLocation, (char)220, charColor);
}