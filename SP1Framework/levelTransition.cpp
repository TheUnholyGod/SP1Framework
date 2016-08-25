#include "levelTransition.h"

int character_X;
int character_Y;
extern int g_CurrentLevel;
extern int g_CreativeLevel;
extern SGameChar   g_sChar;
extern SCreaChar   g_sCreaChar;
extern bool    g_abKeyPressed[K_COUNT];
extern bool	   g_isMapLoaded;
extern bool	   g_isUpdated;

void checkGameGoal()
{
	ifstream file;
	char txt[130][25];
	int height = 0;
	int width = 0;

	switch (g_CurrentLevel)
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
			g_sChar.m_cLocation.Y = 2;
			g_sChar.m_cLocation.X = 1;
			//g_isUpdated = false;
			//g_isMapLoaded = false;
		}
		if (g_CurrentLevel == 2 && (txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '+'))
		{
			g_CurrentLevel = 3;
			g_sChar.m_cLocation.Y = 2;
			g_sChar.m_cLocation.X = 1;
			//g_isUpdated = false;
			//g_isMapLoaded = false;
		}
		if (g_CurrentLevel == 3 && (txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '+'))
		{
			g_CurrentLevel = 4;
			g_sChar.m_cLocation.Y = 2;
			g_sChar.m_cLocation.X = 1;
			//g_isUpdated = false;
			//g_isMapLoaded = false;
		}
		if (g_CurrentLevel == 4 && (txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '+'))
		{
			g_CurrentLevel = 5;
			g_sChar.m_cLocation.Y = 2;
			g_sChar.m_cLocation.X = 1;
			//g_isUpdated = false;
			//g_isMapLoaded = false;
		}
		if (g_CurrentLevel == 5 && (txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '+'))
		{
			g_CurrentLevel = 6;
			g_sChar.m_cLocation.Y = 2;
			g_sChar.m_cLocation.X = 1;
			//g_isUpdated = false;
			//g_isMapLoaded = false;
		}
		if (g_CurrentLevel == 6 && (txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '+'))
		{
			g_CurrentLevel = 1;
			g_sChar.m_cLocation.Y = 2;
			g_sChar.m_cLocation.X = 1;
			//g_isUpdated = false;
			//g_isMapLoaded = false;
		}
		g_isUpdated = false;
		g_isMapLoaded = false;
	}
}

void checkCreativeGameGoal()
{
	ifstream file;
	char txt[130][25];
	int height = 0;
	int width = 0;

	switch (g_CreativeLevel)
	{
	case 101:
			file.open("CreativeLevels/Level_1.txt");
			break;
	case 102:
			file.open("CreativeLevels/Level_2.txt");
			break;
	case 103:
			file.open("CreativeLevels/Level_3.txt");
			break;
	case 104:
			file.open("CreativeLevels/Level_4.txt");
			break;
	case 105:
			file.open("CreativeLevels/Level_5.txt");
			break;
	case 106:
			file.open("CreativeLevels/Level_6.txt");
			break;
	}
	

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

	if (g_abKeyPressed[K_E])
	{
		if (g_CreativeLevel == 101 && (txt[g_sCreaChar.m_cCreativeLocation.X][g_sCreaChar.m_cCreativeLocation.Y - 1] == '+'))
		{
			g_CreativeLevel = 102;
			g_sCreaChar.m_cCreativeLocation.Y = 2;
			g_sCreaChar.m_cCreativeLocation.X = 1;
			//g_isUpdated = false;
			//g_isMapLoaded = false;
		}
		if (g_CreativeLevel == 102 && (txt[g_sCreaChar.m_cCreativeLocation.X][g_sCreaChar.m_cCreativeLocation.Y - 1] == '+'))
		{
			g_CreativeLevel = 103;
			g_sCreaChar.m_cCreativeLocation.Y = 2;
			g_sCreaChar.m_cCreativeLocation.X = 1;
			//g_isUpdated = false;
			//g_isMapLoaded = false;
		}
		if (g_CreativeLevel == 103 && (txt[g_sCreaChar.m_cCreativeLocation.X][g_sCreaChar.m_cCreativeLocation.Y - 1] == '+'))
		{
			g_CreativeLevel = 104;
			g_sCreaChar.m_cCreativeLocation.Y = 2;
			g_sCreaChar.m_cCreativeLocation.X = 1;
			//g_isUpdated = false;
			//g_isMapLoaded = false;
		}
		if (g_CreativeLevel == 104 && (txt[g_sCreaChar.m_cCreativeLocation.X][g_sCreaChar.m_cCreativeLocation.Y - 1] == '+'))
		{
			g_CreativeLevel = 105;
			g_sCreaChar.m_cCreativeLocation.Y = 2;
			g_sCreaChar.m_cCreativeLocation.X = 1;
			//g_isUpdated = false;
			//g_isMapLoaded = false;
		}
		if (g_CreativeLevel == 105 && (txt[g_sCreaChar.m_cCreativeLocation.X][g_sCreaChar.m_cCreativeLocation.Y - 1] == '+'))
		{
			g_CreativeLevel = 106;
			g_sCreaChar.m_cCreativeLocation.Y = 2;
			g_sCreaChar.m_cCreativeLocation.X = 1;
			//g_isUpdated = false;
			//g_isMapLoaded = false;
		}
		if (g_CreativeLevel == 106 && (txt[g_sCreaChar.m_cCreativeLocation.X][g_sCreaChar.m_cCreativeLocation.Y - 1] == '+'))
		{
			g_CreativeLevel = 101;
			g_sCreaChar.m_cCreativeLocation.Y = 2;
			g_sCreaChar.m_cCreativeLocation.X = 1;
			//g_isUpdated = false;
			//g_isMapLoaded = false;
		}
		g_isUpdated = false;
		g_isMapLoaded = false;
	}
}