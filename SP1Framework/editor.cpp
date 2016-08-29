#include "editor.h"

extern bool g_isUpdated;
extern bool g_isMapLoaded;
extern char** creative;
extern int character_X;
extern int character_Y;
extern unsigned int maxMapWidth;
extern unsigned int maxMapHeight;
char ch = 'A';
extern SEditor g_sCursor;
extern double  g_dBounceTime;
extern double  g_dElapsedTime;
extern bool    g_abKeyPressed[K_COUNT];
extern int	   g_CreativeLevel;
extern char    map[40][130];

void renderEditor()
{
	renderEditorInstruction();
	print_map();
	renderCursor();
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

	if (g_abKeyPressed[K_UP] && g_sCursor.m_cEditorLocation.Y > 0)
	{
		{
			g_sCursor.m_cEditorLocation.Y--;
			bSomethingHappened = true;
			g_isUpdated = false;
		}

	}
	if (g_abKeyPressed[K_LEFT] && g_sCursor.m_cEditorLocation.X > 0)
	{
		{
			g_sCursor.m_cEditorLocation.X--;
			bSomethingHappened = true;
			g_isUpdated = false;
		}

	}
	if (g_abKeyPressed[K_DOWN] && g_sCursor.m_cEditorLocation.Y < g_Console.getConsoleSize().Y - 1)
	{
		{
			g_sCursor.m_cEditorLocation.Y++;
			bSomethingHappened = true;
			g_isUpdated = false;
		}
	}
	if (g_abKeyPressed[K_RIGHT] && g_sCursor.m_cEditorLocation.X < g_Console.getConsoleSize().X - 1)
	{
		{
			g_sCursor.m_cEditorLocation.X++;
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

void renderCursor()
{
	// Draw the location of the cursor
	WORD charColor = 0x0C;
	g_Console.writeToBuffer(g_sCursor.m_cEditorLocation, (char)178, charColor);
}
void editmap(int levelnumber,char change)
{
	map[g_sCursor.m_cEditorLocation.Y-1][g_sCursor.m_cEditorLocation.X] = change;
}
void edits()
{
	if (g_abKeyPressed[K_SPACE])
	{
		ch = '-';
		editmap(g_CreativeLevel, ch);
		g_isUpdated = false;
		g_isMapLoaded = false;
	}
	if (g_abKeyPressed[K_W])
	{
		ch = 'W';
		editmap(g_CreativeLevel, ch);
		g_isUpdated = false;
		g_isMapLoaded = false;
	}
	if (g_abKeyPressed[K_D])
	{
		ch = 'D';
		editmap(g_CreativeLevel, ch);
		g_isUpdated = false;
		g_isMapLoaded = false;
	}
	if (g_abKeyPressed[K_Q])
	{
		ch = '+';
		editmap(g_CreativeLevel, ch);
		g_isUpdated = false;
		g_isMapLoaded = false;
	}
	if (g_abKeyPressed[K_K])
	{
		ch = 'K';
		editmap(g_CreativeLevel, ch);
		g_isUpdated = false;
		g_isMapLoaded = false;
	}
	if (g_abKeyPressed[K_B])
	{
		ch = 'B';
		editmap(g_CreativeLevel, ch);
		g_isUpdated = false;
		g_isMapLoaded = false;
	}
	if (g_abKeyPressed[K_O])
	{
		ch = 'b';
		editmap(g_CreativeLevel, ch);
		g_isUpdated = false;
		g_isMapLoaded = false;
	}
	if (g_abKeyPressed[K_P])
	{
		ch = 'P';
		editmap(g_CreativeLevel, ch);
		g_isUpdated = false;
		g_isMapLoaded = false;
	}
}
void saveMap(int levelnumber)
{
	// opens/creates new file
	ofstream newfile("temp.txt");
	char oldname[] = "temp.txt";

	{
		int height = 0;
		int width = 0;
		if (newfile.is_open())
		{
			while (height < 25)
			{
				while (width < 130)
				{
					//converts the ascii codes back to letters to be stored in txt
					if (map[height][width] == (char)176) 
					{
						map[height][width] = '-';
					}
					else if (map[height][width] == (char)178) 
					{
						map[height][width] = 'W';
					}
					else if (map[height][width] == (char)177)
					{
						map[height][width] = '+';
					}
					else if (map[height][width] == (char)168)
					{
						map[height][width] = 'K';
					}
					else if (map[height][width] == (char)219)
					{
						map[height][width] = 'D';
					}
					else if (map[height][width] == (char)254)
					{
						map[height][width] = 'B';
					}
					newfile << map[height][width]; //loads the map data into temp.txt
					width++;
				}
				newfile << "\n";
				width = 0;
				height++;
			}
			newfile.close();
		}
		if (levelnumber == 101)
		{
			char newname[] = "CreativeLevels/Level_1.txt";
			remove(newname);
			rename(oldname, newname);
		}
		if (levelnumber == 102)
		{
			char newname[] = "CreativeLevels/Level_2.txt";
			remove(newname);
			rename(oldname, newname);
		}
		if (levelnumber == 103)
		{
			char newname[] = "CreativeLevels/Level_3.txt";
			remove(newname);
			rename(oldname, newname);
		}
		if (levelnumber == 104)
		{
			char newname[] = "CreativeLevels/Level_4.txt";
			remove(newname);
			rename(oldname, newname);
		}
		if (levelnumber == 105)
		{
			char newname[] = "CreativeLevels/Level_5.txt";
			remove(newname);
			rename(oldname, newname);
		}
		if (levelnumber == 106)
		{
			char newname[] = "CreativeLevels/Level_6.txt";
			remove(newname);
			rename(oldname, newname);
		}
	}
}