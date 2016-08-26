#include "collision.h"

extern SGameChar   g_sChar;
extern SCreaChar   g_sCreaChar;
extern bool    g_abKeyPressed[K_COUNT];
extern bool g_isKeyEnough, g_DoorLocked;


bool colDetection(int levelnumber)
{
	char txt[130][25];
	int height = 0;
	int width = 0;
	ifstream file;

	if (levelnumber == 1)
		file.open("CampaignLevels/Level_1.txt");
	if (levelnumber == 2)
		file.open("CampaignLevels/Level_2.txt");
	if (levelnumber == 3)
		file.open("CampaignLevels/Level_3.txt");
	if (levelnumber == 4)
		file.open("CampaignLevels/Level_4.txt"); 
	if (levelnumber == 5)
		file.open("CampaignLevels/Level_5.txt");
	if (levelnumber == 6)
		file.open("CampaignLevels/Level_6.txt");

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
		if (g_DoorLocked == true)
		{
			if (txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 2] == 'W' || txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 2] == 'D')
				return false;
		}
<<<<<<< HEAD

		else
		{
			if (txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 2] == 'W')
				return false;
		}

=======
>>>>>>> ddbd923ab7dfd419a50cdb303fd0166fa6dff6e5
	}
	if (g_abKeyPressed[K_LEFT] && g_sChar.m_cLocation.X > 0)
	{
		//Beep(1440, 30);
		// --------------------------------- UNABLE TO MOVE LEFT IS ITS NOT ' ' -------------------------------------------//
		if (g_DoorLocked == true)
		{
			if (txt[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y - 1] == 'W' || txt[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y - 1] == 'D')
				return false;
		}
<<<<<<< HEAD
		
		else
		{
			if (txt[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y - 1] == 'W')
				return false;
		}

=======
>>>>>>> ddbd923ab7dfd419a50cdb303fd0166fa6dff6e5
	}
	if (g_abKeyPressed[K_DOWN] && g_sChar.m_cLocation.Y < g_Console.getConsoleSize().Y - 1)
	{
		//Beep(1440, 30);
		// ---------------------------------- UNABLE TO MOVE DOWN IF ITS NOT ' ' -----------------------------------------//
		if (g_DoorLocked == true)
		{
			if (txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == 'W' || txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == 'D')
				return false;
		}
<<<<<<< HEAD

		else
		{
			if (txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == 'W')
				return false;
		}
=======
>>>>>>> ddbd923ab7dfd419a50cdb303fd0166fa6dff6e5
	}
	if (g_abKeyPressed[K_RIGHT] && g_sChar.m_cLocation.X < g_Console.getConsoleSize().X - 1)
	{
		//Beep(1440, 30);
		// ---------------------------------- UNABLE TO MOVE RIGHT IF ITS NOT ' ' ----------------------------------------//
		if (g_DoorLocked == true)
		{
			if (txt[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y - 1] == 'W' || txt[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y - 1] == 'D')
				return false;
		}
<<<<<<< HEAD

		else
		{
			if (txt[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y - 1] == 'W')
				return false;
		}

	}

=======
	}
>>>>>>> ddbd923ab7dfd419a50cdb303fd0166fa6dff6e5
		return true;
}

bool creativeColDetection(int levelnumber)
{
	char txt[130][25];
	int height = 0;
	int width = 0;
	ifstream file;

	if (levelnumber == 101)
		file.open("CreativeLevels/Level_1.txt");
	if (levelnumber == 102)
		file.open("CreativeLevels/Level_2.txt");
	if (levelnumber == 103)
		file.open("CreativeLevels/Level_3.txt");
	if (levelnumber == 104)
		file.open("CreativeLevels/Level_4.txt");
	if (levelnumber == 105)
		file.open("CreativeLevels/Level_5.txt");
	if (levelnumber == 106)
		file.open("CreativeLevels/Level_6.txt");

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

	if (g_abKeyPressed[K_UP] && g_sCreaChar.m_cCreativeLocation.Y > 0)
	{
		//Beep(1440, 30);
		// --------------------------------- UNABLE TO MOVE UP IF ITS NOT ' ' ---------------------------------------------// 
		if (txt[g_sCreaChar.m_cCreativeLocation.X][g_sCreaChar.m_cCreativeLocation.Y - 2] == 'W')
		{
			return false;
		}
	}
	if (g_abKeyPressed[K_LEFT] && g_sCreaChar.m_cCreativeLocation.X > 0)
	{
		//Beep(1440, 30);
		// --------------------------------- UNABLE TO MOVE LEFT IS ITS NOT ' ' -------------------------------------------//
		if (txt[g_sCreaChar.m_cCreativeLocation.X - 1][g_sCreaChar.m_cCreativeLocation.Y - 1] == 'W')
		{
			return false;
		}
	}
	if (g_abKeyPressed[K_DOWN] && g_sCreaChar.m_cCreativeLocation.Y < g_Console.getConsoleSize().Y - 1)
	{
		//Beep(1440, 30);
		// ---------------------------------- UNABLE TO MOVE DOWN IF ITS NOT ' ' -----------------------------------------//
		if (txt[g_sCreaChar.m_cCreativeLocation.X][g_sCreaChar.m_cCreativeLocation.Y] == 'W')
		{
			return false;
		}
	}
	if (g_abKeyPressed[K_RIGHT] && g_sCreaChar.m_cCreativeLocation.X < g_Console.getConsoleSize().X - 1)
	{
		//Beep(1440, 30);
		// ---------------------------------- UNABLE TO MOVE RIGHT IF ITS NOT ' ' ----------------------------------------//
		if (txt[g_sCreaChar.m_cCreativeLocation.X + 1][g_sCreaChar.m_cCreativeLocation.Y - 1] == 'W')
		{
			return false;
		}
	}
<<<<<<< HEAD
	
	return true;
}
=======
		return true;
}
>>>>>>> ddbd923ab7dfd419a50cdb303fd0166fa6dff6e5
