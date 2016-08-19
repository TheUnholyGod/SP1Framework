#include"collision.h"

extern SGameChar   g_sChar;
extern bool    g_abKeyPressed[K_COUNT];

bool colDetection(int levelnumber)
{
	char txt[130][25];
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

	//COORD c;
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

	if (g_abKeyPressed[K_UP] && g_sChar.m_cLocation.Y > 0)
	{
		//Beep(1440, 30);
		// --------------------------------- UNABLE TO MOVE UP IF ITS NOT ' ' ---------------------------------------------// 
		if (txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 2] != '-' && txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 2] != '+')
		{
			return false;
		}

	}
	if (g_abKeyPressed[K_LEFT] && g_sChar.m_cLocation.X > 0)
	{
		//Beep(1440, 30);
		// --------------------------------- UNABLE TO MOVE LEFT IS ITS NOT ' ' -------------------------------------------//
		if (txt[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y - 1] != '-' && txt[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y - 1] != '+')
		{
			return false;
		}

	}
	if (g_abKeyPressed[K_DOWN] && g_sChar.m_cLocation.Y < g_Console.getConsoleSize().Y - 1)
	{
		//Beep(1440, 30);
		// ---------------------------------- UNABLE TO MOVE DOWN IF ITS NOT ' ' -----------------------------------------//
		if (txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] != '-' && txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] != '+')
		{
			return false;
		}
	}
	if (g_abKeyPressed[K_RIGHT] && g_sChar.m_cLocation.X < g_Console.getConsoleSize().X - 1)
	{
		//Beep(1440, 30);
		// ---------------------------------- UNABLE TO MOVE RIGHT IF ITS NOT ' ' ----------------------------------------//
		if (txt[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y - 1] != '-' && txt[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y - 1] != '+')
		{
			return false;
		}

	}
	else
		return true;
}