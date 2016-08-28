#include "menu.h"
extern int g_CurrentLevel;
extern char** txt;


void renderMenu()
{
	store_map(100);
	print_map();
}
void mainmenu()
{
	processUserInput();
}