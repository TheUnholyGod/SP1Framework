#include "loadlevel.h"

////////// Function CREATE THE FIELD //////////
char** store_map(char** field,int levelnumber)
{
	ifstream file;
	if (levelnumber == 1)
		file.open ("Level_1.txt");
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
	if (levelnumber == 1000)
		file.open("StartUp.txt");
	if (levelnumber == 100)
		file.open("MainMenu.txt");

	if (file.is_open())
	{
		for (int i = 0; i < 25; i++)
		{
			field[i] = new char[80];

			for (int j = 0; j < 80; j++)
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
	for (int i = 0; i < 25; ++i)
	{
		c.Y = i + 1;
		for (int j = 0; j < 80; ++j)
		{
			//convert legend to actual ascii characters
			if (field[i][j] == '-')
			{
				field[i][j] = (char)176;
			}
			if (field[i][j] == 'W')
			{
				field[i][j] = (char)178;
			}
			if (field[i][j] == 'A')
			{
				field[i][j] = ' ';
			}
			c.X = j;
			g_Console.writeToBuffer(c, field[i][j]);
		}
	}
}
