#include "doors.h"

extern SGameChar   g_sChar;
extern bool		   g_abKeyPressed[K_COUNT];
extern int		   g_CurrentLevel;
extern bool		   g_isKeyObtain, g_DoorLocked;
extern bool g_isUpdated;

void KeyObtain()
{
	COORD c;
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

	if (g_abKeyPressed[K_E] && txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'K')
	{
		g_isKeyObtain = true;
		g_isUpdated = false;
	}
}

void isDoorOpen()
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
	}

	while (height < 25)
	{
		if (g_CurrentLevel == 1 && (txt[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X - 1] == 'K'))
		while (width < 130)
		{
			file >> txt[width][height];
			width++;
		}
		width = 0;
		height++;
	}

	if (g_abKeyPressed[K_E] && txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'k' && g_isKeyObtain == true)
	{
		g_DoorLocked = false;
		g_isUpdated = false;
	}
}