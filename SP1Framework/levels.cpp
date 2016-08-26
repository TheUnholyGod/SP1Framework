#include "levels.h"

extern unsigned int maxMapHeight;
extern unsigned int maxMapWidth;
extern char map[40][130];
extern SGameChar g_sChar;
extern int X, Y;

void initMap(int levelnumber)
{
	ifstream file;
	switch (levelnumber)
	{
	case 1:
		file.open("CampaignLevels/Level_1.txt");
		break;
	case 2:
		file.open("CampaignLevels/Level_2.txt");
		break;
	case 3:
		file.open("CampaignLevels/Level_3.txt");
		break;
	case 4:
		file.open("CampaignLevels/Level_4.txt");
		break;
	case 5:
		file.open("CampaignLevels/Level_5.txt");
		break;
	case 6:
		file.open("CampaignLevels/Level_6.txt");
		break;
	}

	if (file.is_open())
	{
		for (unsigned int i = 0; i < 25; ++i)
		{
			for (unsigned int j = 0; j < 130; ++j)
			{
				file >> map[i][j];
			}
		}
		file.close();
	}
}
void printMap()
{
	//unsigned int offsetX = g_sChar.m_cLocation.X - 6;
	//unsigned int offsetY = g_sChar.m_cLocation.Y - 3;

	//unsigned int maxY = maxMapHeight - Y;
	//unsigned int maxX = maxMapWidth - X;

	//if (g_sChar.m_cLocation.X <= 6)
	//{
	//	offsetX = 0;
	//}
	//if (g_sChar.m_cLocation.Y <= 3)
	//{
	//	offsetY = 0;
	//}
	/*COORD c;
	for (unsigned int i = offsetY; i < maxY; ++i)
	{
		c.Y = i + 1;
		for (unsigned int j = offsetX; j < maxX; ++j)
		{
			c.X = j;
			g_Console.writeToBuffer(c, map[i][j]);
		}
	}*/
	COORD c;
	for (unsigned int i = 0; i < 40; ++i)
	{
		c.Y = i + 1;
		for (unsigned int j = 0; j < 130; ++j)
		{
			c.X = j;
			g_Console.writeToBuffer(c, map[i][j]);
		}
	}
}