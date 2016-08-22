#include "loadlevel.h"

	unsigned int maxMapWidth;
	unsigned int maxMapHeight;
	extern int character_X;
	extern int character_Y;

////////// Function CREATE THE FIELD //////////
char** store_map(char** field,int levelnumber)
{
	ifstream file;
	//load campaign maps here
	if (levelnumber == 1)
	{
		file.open ("CampaignLevels/Level_1.txt");
		maxMapWidth = 130;
		maxMapHeight = 25;
	}
		
	if (levelnumber == 2)
	{
		file.open("CampaignLevels/Level_2.txt");
		maxMapWidth = 130;
		maxMapHeight = 25;
	}
		
	if (levelnumber == 3)
	{
		file.open("CampaignLevels/Level_3.txt");
		maxMapWidth = 130;
		maxMapHeight = 25;
	}

	if (levelnumber == 4)
	{
		file.open("CampaignLevels/Level_4.txt");
		maxMapWidth = 130;
		maxMapHeight = 25;
	}

	if (levelnumber == 5)
	{
		file.open("CampaignLevels/Level_5.txt");
		maxMapWidth = 130;
		maxMapHeight = 25;
	}

	if (levelnumber == 6)
	{
		file.open("CampaignLevels/Level_6.txt");
		maxMapWidth = 130;
		maxMapHeight = 25;
	}
	//Load creative levels below
	if (levelnumber == 101)
	{
		file.open("CreativeLevels/Level_1.txt");
		maxMapWidth = 130;
		maxMapHeight = 25;
	}

	if (levelnumber == 102)
	{
		file.open("CreativeLevels/Level_2.txt");
		maxMapWidth = 130;
		maxMapHeight = 25;
	}

	if (levelnumber == 103)
	{
		file.open("CreativeLevels/Level_3.txt");
		maxMapWidth = 130;
		maxMapHeight = 25;
	}

	if (levelnumber == 104)
	{
		file.open("CreativeLevels/Level_4.txt");
		maxMapWidth = 130;
		maxMapHeight = 25;
	}

	if (levelnumber == 105)
	{
		file.open("CreativeLevels/Level_5.txt");
		maxMapWidth = 130;
		maxMapHeight = 25;
	}

	if (levelnumber == 106)
	{
		file.open("CreativeLevels/Level_6.txt");
		maxMapWidth = 130;
		maxMapHeight = 25;
	}
	//special numbers for menu and splashscreen
	if (levelnumber == 1000)
	{
		file.open("StartUp.txt");
		maxMapWidth = 130;
		maxMapHeight = 25;
	}

	if (levelnumber == 100)
	{
		file.open("MainMenu.txt");
		maxMapWidth = 130;
		maxMapHeight = 25;
	}
	//stores the map data into a 2d array and returns it
	if (file.is_open())
	{
		for (int i = 0; i < maxMapHeight; i++)
		{
			field[i] = new char[maxMapWidth];

			for (int j = 0; j < maxMapWidth; j++)
			{
				file >> field[i][j];
			}
		}
		file.close();
	}
	return field;
}
void print_map(char ** field)
{
	COORD c;
	for (int i = 0; i < maxMapHeight; ++i)
	{
		c.Y = i + 1;
		for (int j = 0; j < maxMapWidth; ++j)
		{
			WORD color = 0x7F;
			//convert legend to actual ascii characters
			if (field[i][j] == '-')
			{
				field[i][j] = (char)176;
			}
			if (field[i][j] == 'W')
			{
				field[i][j] = (char)178;
			}
			if (field[i][j] == '*')
			{
				field[i][j] = ' ';
			}
			if (field[i][j] == '+')
			{
				character_X = i;
				character_Y = j;
				field[i][j] = (char)177;
				color = 0x4C;
			}
			c.X = j;
				g_Console.writeToBuffer(c, field[i][j],color);
		}
	}
}
