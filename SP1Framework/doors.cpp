#include "doors.h"

extern SGameChar   g_sChar;
extern bool		   g_abKeyPressed[K_COUNT];
extern int		   g_CurrentLevel;
extern bool		   isKeyObtain, DoorStatus;

void KeyObtain()
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
		if (g_CurrentLevel == 1)
		{
			isKeyObtain = false;
			if (txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'K')
				isKeyObtain = true;
		}

		else if (g_CurrentLevel == 2)
		{
			isKeyObtain = false;
			if (txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'K')
				isKeyObtain = true;
		}
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
		while (width < 130)
		{
			file >> txt[width][height];
			width++;
		}
		width = 0;
		height++;
	}

	if (g_abKeyPressed[K_E] && txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'k')
	{
		if (g_CurrentLevel == 1)
		{
			DoorStatus = false;
			if (isKeyObtain == false)
			{
				if (txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'k')
					DoorStatus = false;
			}

			else
			{
				if (txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'k')
					DoorStatus = true;
			}
		}
	}
}