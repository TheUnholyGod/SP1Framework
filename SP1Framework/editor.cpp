#include "editor.h"

extern int character_X;
extern int character_Y;
extern unsigned int maxMapWidth;
extern unsigned int maxMapHeight;
char ch = 'A';
extern SEditor g_sCursor;
extern double  g_dBounceTime;
extern double  g_dElapsedTime;
extern bool    g_abKeyPressed[K_COUNT];
extern int	   g_CurrentLevel;

void renderEditor()
{
	char** currentMap = new char*[100];
	currentMap = store_map(currentMap, g_CurrentLevel);
	print_map(currentMap);
	renderCursor();
	renderEndpoint();
}
void editor()
{
	edits();
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
	g_Console.writeToBuffer(g_sCursor.m_cEditorLocation, (char)178, charColor);
}
void editmap(int levelnumber,char change)
{
	char txt[130][25];
	char replacement[130][25];
	int height = 0;
	int width = 0;
	ifstream file;

	if (levelnumber == 1)
		file.open("Level_1.txt");
	if (levelnumber == 2)
		file.open("Level_2.txt");
	if (levelnumber == 3)
		file.open("Level_3.txt");
	if (levelnumber == 4)
		file.open("Level_4.txt");
	if (levelnumber == 5)
		file.open("Level_5.txt");
	if (levelnumber == 6)
		file.open("Level_6.txt");

	if (file.is_open())
	{
		while (height < 25)
		{
			while (width < 130)
			{
				file >> txt[width][height];
				width++;
			}
			width = 0;
			height++;
		}
		file.close();
	}

	// opens/creates new file
	ofstream newfile("temp.txt");
	char oldname[] = "temp.txt";

	txt[g_sCursor.m_cEditorLocation.X][g_sCursor.m_cEditorLocation.Y-1] = change;
	{
		height = 0;
		width = 0;
		if (newfile.is_open())
		{
			while (height < 25)
			{
				while (width < 130)
				{
					newfile << txt[width][height];
					width++;
				}
				newfile << "\n";
				width = 0;
				height++;
			}
			newfile.close();
		}
		if (levelnumber == 1)
		{
			char newname[] = "Level_1.txt";
			remove(newname);
			rename(oldname, newname);
		}
		if (levelnumber == 2)
		{
			char newname[] = "Level_2.txt";
			remove(newname);
			rename(oldname, newname);
		}
		if (levelnumber == 3)
		{
			char newname[] = "Level_3.txt";
			remove(newname);
			rename(oldname, newname);
		}
		if (levelnumber == 4)
		{
			char newname[] = "Level_4.txt";
			remove(newname);
			rename(oldname, newname);
		}
		if (levelnumber == 5)
		{
			char newname[] = "Level_5.txt";
			remove(newname);
			rename(oldname, newname);
		}
		if (levelnumber == 6)
		{
			char newname[] = "Level_6.txt";
			remove(newname);
			rename(oldname, newname);
		}
	}
}
void edits()
{
	if (g_abKeyPressed[K_SPACE])
	{
		ch = '-';
		editmap(g_CurrentLevel, ch);
	}
	if (g_abKeyPressed[K_W])
	{
		ch = 'W';
		editmap(g_CurrentLevel, ch);
	}
	if (g_abKeyPressed[K_D])
	{
		ch = 'D';
		editmap(g_CurrentLevel, ch);
	}
	if (g_abKeyPressed[K_Q])
	{
		character_Y = g_sCursor.m_cEditorLocation.Y;
		character_X = g_sCursor.m_cEditorLocation.X;
		ch = '+';
		editmap(g_CurrentLevel, ch);
	}
}
void renderEndpoint()
{
	char check[130][25];
	int height = 0;
	int width = 0;
	ifstream file;

	if (g_CurrentLevel == 1)
		file.open("Level_1.txt");
	if (g_CurrentLevel == 2)
		file.open("Level_2.txt");
	if (g_CurrentLevel == 3)
		file.open("Level_3.txt");
	if (g_CurrentLevel == 4)
		file.open("Level_4.txt");
	if (g_CurrentLevel == 5)
		file.open("Level_5.txt");
	if (g_CurrentLevel == 6)
		file.open("Level_6.txt");

	if (file.is_open())
	{
		while (height < 25)
		{
			while (width < 130)
			{
				file >> check[width][height];
				width++;
			}
			width = 0;
			height++;
		}
		file.close();
	}
}