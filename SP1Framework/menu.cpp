#include "menu.h"
extern int g_CurrentLevel;
void renderMenu()
{
	renderMap();
}
void mainmenu()
{
	g_CurrentLevel = 100;
}