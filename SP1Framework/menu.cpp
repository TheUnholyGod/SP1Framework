#include "menu.h"

extern SSelector g_sSelector;
extern Console g_sConsole;
extern char map[40][130];
extern bool g_abKeyPressed[K_COUNT];
extern double  g_dElapsedTime;
extern double  g_dBounceTime;
extern EGAMESTATES g_eGameState;
extern int g_KeysObtain;
extern int g_PicksObtain;
extern bool g_Level;

void renderMenu()
{
	if (g_eGameState == S_MENU)
	{
		store_map(100);
		print_map();
		renderSelector();
		menuInput();
		g_Console.writeToBuffer(45, 36, "<Arrow Keys> to change Selection", 0x07);
		g_Console.writeToBuffer(45, 37, "<SPACE>      to Select", 0x07);
	}
	if (g_eGameState == S_GAMEOVER)
	{
		store_map(999);
		print_map();
		renderSelector();
		menuInput();
		g_Console.writeToBuffer(45, 36, "<Arrow Keys> to change Selection", 0x07);
		g_Console.writeToBuffer(45, 37, "<SPACE>      to Select", 0x07);
	}
}
void mainmenu()
{
	moveSelector();
}
void renderSelector()
{
	if (g_eGameState == S_MENU)
	{
		if (g_abKeyPressed[K_Q])
		{
			renderTroll();
		}
		g_Console.writeToBuffer(g_sSelector.m_cSelectorLocation, (char)62, 0x07);
		if (g_sSelector.m_cSelectorLocation.Y - 1 == 15)
		{
			g_Console.writeToBuffer(52, 16, "Start Campaign", 0x0C);
			g_Console.writeToBuffer(40, 25, "Enjoy the classic goat hunting experience", 0x0C);
		}
		else
		{
			g_Console.writeToBuffer(52, 16, "Start Campaign", 0x07);
		}

		if (g_sSelector.m_cSelectorLocation.Y - 1 == 16)
		{
			g_Console.writeToBuffer(52, 17, "Start Creative", 0x0C);
			g_Console.writeToBuffer(40, 25, "Campaign too boring? Make your own levels then!", 0x0C);
		}
		else
		{
			g_Console.writeToBuffer(52, 17, "Start Creative", 0x07);
		}

		if (g_sSelector.m_cSelectorLocation.Y - 1 == 17)
		{
			g_Console.writeToBuffer(52, 18, "Controls", 0x0C);
			g_Console.writeToBuffer(50, 25, "<Arrow Keys> to move", 0x0C);
			g_Console.writeToBuffer(50, 26, "<E>          to interact", 0x0C);
			g_Console.writeToBuffer(50, 26, "<T>          to use flares", 0x0C);
		}
		else
		{
			g_Console.writeToBuffer(52, 18, "Controls", 0x07);
		}

		if (g_sSelector.m_cSelectorLocation.Y - 1 == 18)
		{
			g_Console.writeToBuffer(52, 19, "Quit", 0x0C);
			g_Console.writeToBuffer(40, 25, "Really? You want to quit this game? But why......?", 0x0C);
			g_Console.writeToBuffer(40, 26, "You make me cry *Sobs* if you really want to quit,", 0x0C);
			g_Console.writeToBuffer(40, 27, "press <Q>", 0x0C);
		}
		else
		{
			g_Console.writeToBuffer(52, 19, "Quit", 0x07);
		}
	}
	if (g_eGameState == S_GAMEOVER)
	{
		g_Console.writeToBuffer(g_sSelector.m_cSelectorLocation, (char)62, 0x07);
		if (g_sSelector.m_cSelectorLocation.Y - 1 == 15)
		{
			g_Console.writeToBuffer(52, 16, "Retry", 0x0C);
			g_Console.writeToBuffer(40, 25, "Back to the last level played. Practice makes perfect!", 0x0C);
		}
		else
		{
			g_Console.writeToBuffer(52, 16, "Retry", 0x07);
		}

		if (g_sSelector.m_cSelectorLocation.Y - 1 == 16)
		{
			g_Console.writeToBuffer(52, 17, "Quit", 0x0C);
			g_Console.writeToBuffer(40, 25, "This game making your blood boil? Take a break!", 0x0C);
		}
		else
		{
			g_Console.writeToBuffer(52, 17, "Quit", 0x07);
		}

	}
}
void menuInput()
{
	if (g_eGameState == S_MENU)
	{
		if (g_sSelector.m_cSelectorLocation.Y - 1 == 15 && g_abKeyPressed[K_SPACE]) //Game
		{
			g_KeysObtain = 0;
			g_PicksObtain = 0;
			g_eGameState = S_LOADGAME;
		}
		if (g_sSelector.m_cSelectorLocation.Y - 1 == 16 && g_abKeyPressed[K_SPACE]) //Creative
		{
			g_KeysObtain = 0;
			g_PicksObtain = 0;
			g_eGameState = S_LOADCREATIVE;
		}
		if (g_sSelector.m_cSelectorLocation.Y - 1 == 17 && g_abKeyPressed[K_SPACE]) //Controls
		{
			//Print instructions
		}
		if (g_sSelector.m_cSelectorLocation.Y - 1 == 18 && g_abKeyPressed[K_SPACE]) //quit
		{
			g_bQuitGame = true;
		}
	}
	if (g_eGameState == S_GAMEOVER)
	{
		if (g_sSelector.m_cSelectorLocation.Y - 1 == 15 && g_abKeyPressed[K_SPACE]) //Game
		{
			if(g_Level == true)
				g_eGameState = S_LOADGAME;
			if (g_Level == false)
				g_eGameState = S_LOADCREATIVE;

		}
		if (g_sSelector.m_cSelectorLocation.Y - 1 == 16 && g_abKeyPressed[K_SPACE]) //quit
		{
			g_bQuitGame = true;
		}
	}
}
void moveSelector()
{
	if (g_eGameState == S_MENU)
	{
		bool bSomethingHappened = false;
		if (g_dBounceTime > g_dElapsedTime)
			return;
		if (g_abKeyPressed[K_UP] && g_sSelector.m_cSelectorLocation.Y > 16)
		{
			g_sSelector.m_cSelectorLocation.Y--;
			bSomethingHappened = true;
		}
		if (g_abKeyPressed[K_DOWN] && g_sSelector.m_cSelectorLocation.Y < 19)
		{
			g_sSelector.m_cSelectorLocation.Y++;
			bSomethingHappened = true;
		}
		if (bSomethingHappened)
		{
			g_dBounceTime = g_dElapsedTime + 0.125;
		}
	}
	if (g_eGameState == S_GAMEOVER)
	{
		bool bSomethingHappened = false;
		if (g_dBounceTime > g_dElapsedTime)
			return;
		if (g_abKeyPressed[K_UP] && g_sSelector.m_cSelectorLocation.Y > 16)
		{
			g_sSelector.m_cSelectorLocation.Y--;
			bSomethingHappened = true;
		}
		if (g_abKeyPressed[K_DOWN] && g_sSelector.m_cSelectorLocation.Y < 17)
		{
			g_sSelector.m_cSelectorLocation.Y++;
			bSomethingHappened = true;
		}
		if (bSomethingHappened)
		{
			g_dBounceTime = g_dElapsedTime + 0.125;
		}
	}
}
void renderTroll()
{
	char trolled[15][31];

	ifstream troll("troll.txt");
	if (troll.is_open())
	{
		for (unsigned int i = 0; i < 15; i++)
		{
			for (unsigned int j = 0; j < 31; j++)
			{
				troll >> trolled[i][j];
			}
		}
		troll.close();
	}
	COORD c;
	for (unsigned int i = 0; i < 15; ++i)
	{
		c.Y = i + 13;
		for (unsigned int j = 0; j < 31; ++j)
		{
			if (trolled[i][j] == 'C')
				trolled[i][j] = ' ';
			if (trolled[i][j] == 'B')
				trolled[i][j] = ' ';
			if (trolled[i][j] == 'D')
				trolled[i][j] = (char)223;
			if (trolled[i][j] == 'E')
				trolled[i][j] = (char)220;
			if (trolled[i][j] == 'F')
				trolled[i][j] = (char)219;
			c.X = j + 5;
			g_Console.writeToBuffer(c, trolled[i][j]);
		}
	}
}