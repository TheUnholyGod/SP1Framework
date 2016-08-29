#include "loadlevel.h"

	unsigned int maxMapWidth;
	unsigned int maxMapHeight;
	extern int character_X;
	extern int character_Y;
	extern SGameChar g_sChar;
	extern SCreaChar g_sCreaChar;
	extern int Y;
	extern int X;
	extern int cY;
	extern int cX;
	extern char map[40][130];
	extern EGAMESTATES g_eGameState;

////////// Function CREATE THE FIELD //////////
void store_map(int levelnumber)
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
	if (file.is_open())
	{
		//stores the map data into a 2d array and returns it
		for (unsigned int i = 0; i < maxMapHeight; i++)
		{
			for (unsigned int j = 0; j < maxMapWidth; j++)
			{
				file >> map[i][j];
			}
		}
		file.close();
	}
}

void print_map()
{
	//Codes for the torch light effect (game mode)
	if (g_eGameState == S_GAME)
	{
		unsigned int offsetX = g_sChar.m_cLocation.X - 5;
		unsigned int offsetY = g_sChar.m_cLocation.Y - 3;
		unsigned int maxY = g_sChar.m_cLocation.Y + 2;
		unsigned int maxX = g_sChar.m_cLocation.X + 6;

		//conditions for gamemode
		if (g_sChar.m_cLocation.X <= 5)
		{
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
				WORD color = 0x07;
				//convert legend to actual ascii characters
				if (map[i][j] == '-' || map[i][j] == (char)176) //converts the '-' and walkable area
				{
					color = 0x07;
					map[i][j] = (char)176;
				}
				else if (map[i][j] == 'W' || map[i][j] == (char)178) //converts wall 'W', to ascii character 178
				{
					color = 0x0B;
					map[i][j] = (char)178;
				}
				else if (map[i][j] == '+' || map[i][j] == (char)177) //converts end point '+', to ascii character 177
				{
					map[i][j] = (char)177;
					color = 0x7C;
				}
				else if (map[i][j] == 'K' || map[i][j] == (char)168) //converts key 'K', to ascii character 168
				{
					map[i][j] = (char)168;
					color = 0x6E;
				}
				else if (map[i][j] == 'D' || map[i][j] == (char)219) //converts door 'D', to ascii character 219
				{
					map[i][j] = (char)219;
					color = 0x6E;
				}
				else if (map[i][j] == 'B' || map[i][j] == (char)254) //converts boulder 'B', to ascii character 254
				{
					map[i][j] = (char)254;
					color = 0x88;
				}
				else if (map[i][j] == 'b' || map[i][j] == (char)220)
				{
					map[i][j] = (char)220;
					color = 0x44;
				}
				else if (map[i][j] == 'P' || map[i][j] == (char)156)
				{
					map[i][j] = (char)156;
				}
				c.X = j;
				g_Console.writeToBuffer(c, map[i][j], color);
			}
		}
	}
	//Codes for the torch light effect (creative mode)
	else if (g_eGameState == S_CREATIVE)
	{
		unsigned int CoffsetX = g_sCreaChar.m_cCreativeLocation.X - 5;
		unsigned int CoffsetY = g_sCreaChar.m_cCreativeLocation.Y - 3;
		unsigned int CmaxY = g_sCreaChar.m_cCreativeLocation.Y + 2;
		unsigned int CmaxX = g_sCreaChar.m_cCreativeLocation.X + 6;

		if (g_sCreaChar.m_cCreativeLocation.X <= 5)
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
				WORD color = 0x07;
				//convert legend to actual ascii characters
				if (map[i][j] == '-' || map[i][j] == (char)176) //converts the key and walkable area
				{
					color = 0x07;
					map[i][j] = (char)176;
				}
				else if (map[i][j] == 'W' || map[i][j] == (char)178) //converts wall 'W', to ascii character 178
				{
					color = 0x0B;
					map[i][j] = (char)178;
				}
				else if (map[i][j] == '+' || map[i][j] == (char)177) //converts end point '+', to ascii character 177
				{
					map[i][j] = (char)177;
					color = 0x7C;
				}
				else if (map[i][j] == 'K' || map[i][j] == (char)168) //converts key 'K', to ascii character 168
				{
					map[i][j] = (char)168;
					color = 0x6E;
				}
				else if (map[i][j] == 'D' || map[i][j] == (char)219) //converts door 'D', to ascii character 219
				{
					map[i][j] = (char)219;
					color = 0x4C;
				}
				else if (map[i][j] == 'B' || map[i][j] == (char)254) //converts boulder 'B', to ascii character 254
				{
					map[i][j] = (char)254;
					color = 0x88;
				}
				c.X = j;
				g_Console.writeToBuffer(c, map[i][j], color);
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
				WORD color = 0x07;
				//convert legend to actual ascii characters
				if (map[i][j] == '-' || map[i][j] == (char)176) //converts the key and walkable area
				{
					color = 0x07;
					map[i][j] = (char)176;
				}
				else if (map[i][j] == 'W' || map[i][j] == (char)178) //converts wall 'W', to ascii character 178
				{
					color = 0x0B;
					map[i][j] = (char)178;
				}
				else if (map[i][j] == '+' || map[i][j] == (char)177) //converts end point '+', to ascii character 177
				{
					map[i][j] = (char)177;
					color = 0x7C;
				}
				else if (map[i][j] == '*') //converts the key and walkable area
				{
					color = 0x07;
					map[i][j] = ' ';
				}
				else if (map[i][j] == 'K' || map[i][j] == (char)168) //converts key 'K', to ascii character 168
				{
					map[i][j] = (char)168;
					color = 0x6E;
				}
				else if (map[i][j] == 'D' || map[i][j] == (char)219) //converts door 'D', to ascii character 219
				{
					map[i][j] = (char)219;
					color = 0x4C;
				}
				else if (map[i][j] == 'B' || map[i][j] == (char)254) //converts boulder 'B', to ascii character 254
				{
					map[i][j] = (char)254;
					color = 0x88;
				}
				c.X = j;
				g_Console.writeToBuffer(c, map[i][j], color);
			}
		}
	}
}
