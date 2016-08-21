#include "levelTransition.h"

int character_X;
int character_Y;
extern int g_CurrentLevel;
extern SGameChar   g_sChar;
extern bool    g_abKeyPressed[K_COUNT];

void checkGameGoal()
{
	ifstream file;
	char txt[130][25];
	int height = 0;
	int width = 0;

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
				file >> txt[width][height];
				width++;
			}
			width = 0;
			height++;
		}
		file.close();
	}

	if(g_abKeyPressed[K_E])
	{
		if (g_CurrentLevel == 1 && (txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y-1] == '+'))
		{
			g_CurrentLevel = 2;
			g_sChar.m_cLocation.Y = 10;
			g_sChar.m_cLocation.X = 10;
		}
		if (g_CurrentLevel == 2 && (txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '+'))
		{
			g_CurrentLevel = 3;
			g_sChar.m_cLocation.Y = 10;
			g_sChar.m_cLocation.X = 10;
		}
		if (g_CurrentLevel == 3 && (txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '+'))
		{
			g_CurrentLevel = 4;
			g_sChar.m_cLocation.Y = 10;
			g_sChar.m_cLocation.X = 10;
		}
		if (g_CurrentLevel == 4 && (txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '+'))
		{
			g_CurrentLevel = 5;
			g_sChar.m_cLocation.Y = 10;
			g_sChar.m_cLocation.X = 10;
		}
		if (g_CurrentLevel == 5 && (txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '+'))
		{
			g_CurrentLevel = 6;
			g_sChar.m_cLocation.Y = 10;
			g_sChar.m_cLocation.X = 10;
		}
		if (g_CurrentLevel == 6 && (txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '+'))
		{
			g_CurrentLevel = 1;
			g_sChar.m_cLocation.Y = 10;
			g_sChar.m_cLocation.X = 10;
		}
	}
}