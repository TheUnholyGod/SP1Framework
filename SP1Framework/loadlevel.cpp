#include "loadlevel.h"

	unsigned int maxMapWidth;
	unsigned int maxMapHeight;
	extern int character_X;
	extern int character_Y;
<<<<<<< HEAD
	extern bool g_isKeyObtain, g_DoorLocked;
	extern vector<COORD> locationDoor;
	extern vector<COORD> locationWall;
=======
	extern int isKeyObtain;
	extern SGameChar g_sChar;
	extern SCreaChar g_sCreaChar;
	extern int Y;
	extern int X;
	extern int cY;
	extern int cX;
	extern EGAMESTATES g_eGameState;

>>>>>>> ddbd923ab7dfd419a50cdb303fd0166fa6dff6e5

////////// Function CREATE THE FIELD //////////
char** store_map(char** field, int levelnumber)
{
	ifstream file;
	
	//load campaign maps here
	if (levelnumber == 1)
	{
		file.open("CampaignLevels/Level_1.txt");
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
		maxMapHeight = 39;
	}

	if (levelnumber == 100)
	{
		file.open("MainMenu.txt");
		maxMapWidth = 130;
		maxMapHeight = 39;
	}

	if (levelnumber == 1001)
	{
		file.open("TextboxMaxe.txt");
		maxMapWidth = 130;
		maxMapHeight = 39;
	}
	//stores the map data into a 2d array and returns it
	for (unsigned int i = 0; i < maxMapHeight; i++)
	{
		field[i] = new char[maxMapWidth];
		for (unsigned int j = 0; j < maxMapWidth; j++)
		{
			file >> field[i][j];
		}
	}
	return field;
}

void print_map(char ** field)
{
	//Codes for the torch light effect (game mode)
	if (g_eGameState == S_GAME)
	{
	
		unsigned int offsetX = g_sChar.m_cLocation.X - 6;
		unsigned int offsetY = g_sChar.m_cLocation.Y - 3;
		unsigned int maxY = maxMapHeight - Y;
		unsigned int maxX = maxMapWidth - X;

		//conditions for gamemode
		if (g_sChar.m_cLocation.X <= 6)
		{
<<<<<<< HEAD
			WORD color = 0x0B;
			//convert legend to actual ascii characters
			if (field[i][j] == '-' || field[i][j] == 'k')
			{
				color = 0x07;
				field[i][j] = ' ';
			}
			else if (field[i][j] == 'W')
			{	
				color = 0x0B;
				field[i][j] = (char)178;
			}
			else if (field[i][j] == '*')
			{
				field[i][j] = ' ';
			}
			else if (field[i][j] == 'D')
			{
				if (g_DoorLocked == true)
				{
					color = 0x67;
					field[i][j] = (char)178;
				}					
				else
				{
				color = 0x07;
				field[i][j] = ' ';
				}
			}
			
			else if (field[i][j] == 'K')
			{
				if (g_isKeyObtain == false)
				{
					color = 0x67;
					field[i][j] = (char)177;
=======
			offsetX = 0;
		}
		if (g_sChar.m_cLocation.Y <= 3)
		{
			offsetY = 0;
		}
		if (g_sChar.m_cLocation.X >= 126)
		{
			maxX = 130;
		}
		if (g_sChar.m_cLocation.Y >= 23)
		{
			maxY = 25;
		}
		COORD c;
		for (unsigned int i = offsetY; i < maxY; ++i)
		{
			c.Y = i + 1;
			for (unsigned int j = offsetX; j < maxX; ++j)
			{
				WORD color = 0x0B;
				//convert legend to actual ascii characters
				if (field[i][j] == '-')
				{
					color = 0x07;
					field[i][j] = (char)176;
				}
				else if (field[i][j] == 'W')
				{
					color = 0x0B;
					field[i][j] = (char)178;
				}
				else if (field[i][j] == 'K')
				{
					if (isKeyObtain == 0)
					{
						color = 0x7C;
						field[i][j] = (char)207;
					}
					else
					{
						color = 0x00;
						field[i][j] = (char)176;
					}
				}
				else if (field[i][j] == '+')
				{
					field[i][j] = (char)177;
					color = 0x7C;
>>>>>>> ddbd923ab7dfd419a50cdb303fd0166fa6dff6e5
				}
				c.X = j;
				g_Console.writeToBuffer(c, field[i][j], color);
			}
		}
	}
	//Codes for the torch light effect (creative mode)
	else if (g_eGameState == S_CREATIVE)
	{

		unsigned int CoffsetX = g_sCreaChar.m_cCreativeLocation.X - 6;
		unsigned int CoffsetY = g_sCreaChar.m_cCreativeLocation.Y - 3;
		unsigned int CmaxY = maxMapHeight - cY;
		unsigned int CmaxX = maxMapWidth - cX;

		if (g_sCreaChar.m_cCreativeLocation.X <= 6)
		{
			CoffsetX = 0;
		}
		if (g_sCreaChar.m_cCreativeLocation.Y <= 3)
		{
			CoffsetY = 0;
		}
		if (g_sCreaChar.m_cCreativeLocation.X >= 126)
		{
			CmaxX = 130;
		}
		if (g_sCreaChar.m_cCreativeLocation.Y >= 23)
		{
			CmaxY = 25;
		}
		COORD c;
		for (unsigned int i = CoffsetY; i < CmaxY; ++i)
		{
			c.Y = i + 1;
			for (unsigned int j = CoffsetX; j < CmaxX; ++j)
			{
				WORD color = 0x0B;
				//convert legend to actual ascii characters
				if (field[i][j] == '-')
				{
					color = 0x07;
<<<<<<< HEAD
					field[i][j] = ' ';
=======
					field[i][j] = (char)176;
>>>>>>> ddbd923ab7dfd419a50cdb303fd0166fa6dff6e5
				}
				else if (field[i][j] == 'W')
				{
					color = 0x0B;
					field[i][j] = (char)178;
				}
				else if (field[i][j] == 'K')
				{
					if (isKeyObtain == 0)
					{
						color = 0x7C;
						field[i][j] = (char)207;
					}
					else
					{
						color = 0x00;
						field[i][j] = (char)176;
					}
				}
				else if (field[i][j] == '+')
				{
					field[i][j] = (char)177;
					color = 0x7C;
				}
				c.X = j;
				g_Console.writeToBuffer(c, field[i][j], color);
			}
		}
	}

	//For editor,menu and splashscreens
	else
	{
		COORD c;
		for (int i = 0; i < maxMapHeight; ++i)
		{
			c.Y = i + 1;
			for (int j = 0; j < maxMapWidth; ++j)
			{
				WORD color = 0x0B;
				//convert legend to actual ascii characters
				if (field[i][j] == '-')
				{
					color = 0x07;
					field[i][j] = ' ';
				}
				if (field[i][j] == 'W')
				{
					color = 0x0B;
					field[i][j] = (char)178;
				}
				if (field[i][j] == '+')
				{
					field[i][j] = (char)177;
					color = 0x7C;
				}
				c.X = j;
				g_Console.writeToBuffer(c, field[i][j], color);
			}
		}
	}
}
