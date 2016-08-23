#include "doors.h"

extern SGameChar   g_sChar;
extern bool		   g_abKeyPressed[K_COUNT];
extern int		   g_CurrentLevel;
extern int		   isKeyObtain, DoorStatus;

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

	if (g_abKeyPressed[K_E])
	{
		if (g_CurrentLevel == 1 && (txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'K'))
		{
			isKeyObtain++;
		}
	}
}