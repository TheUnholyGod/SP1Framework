#include "loadlevel.h"

////////// Function CREATE THE FIELD //////////
char** store_map(char** field)
{
	ifstream file("Level_1.txt");
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
			if (field[i][j] == 'i')
				{
					field[i][j] = (char)176;
				}
			if (field[i][j] == 'W')
			{
				field[i][j] = (char)178;
			}
			c.X = j;
			g_Console.writeToBuffer(c, field[i][j]);
		}
	}
}
