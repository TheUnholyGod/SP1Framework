#include "loadlevel.h"

	unsigned int maxMapWidth;
	unsigned int maxMapHeight;
	extern int character_X;
	extern int character_Y;

////////// Function CREATE THE FIELD //////////
char** store_map(char** field,int levelnumber)
{
	ifstream file;
	if (levelnumber == 1)
	{
		file.open ("Level_1.txt");
		maxMapWidth = 130;
		maxMapHeight = 25;
	}
		
	if (levelnumber == 2)
	{
		file.open("Level_2.txt");
		maxMapWidth = 130;
		maxMapHeight = 25;
	}
		
	if (levelnumber == 3)
	{
		file.open("Level_3.txt");
		maxMapWidth = 130;
		maxMapHeight = 25;
	}

	if (levelnumber == 4)
	{
		file.open("Level_4.txt");
		maxMapWidth = 130;
		maxMapHeight = 25;
	}

	if (levelnumber == 5)
	{
		file.open("Level_5.txt");
		maxMapWidth = 130;
		maxMapHeight = 25;
	}

	if (levelnumber == 6)
	{
		file.open("Level_6.txt");
		maxMapWidth = 130;
		maxMapHeight = 25;
	}

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

	if (levelnumber == 69)
	{
		file.open("Spider.txt");
		maxMapWidth = 115;
		maxMapHeight = 24;
	}

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
