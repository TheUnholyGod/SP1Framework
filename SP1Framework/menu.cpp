#include "menu.h"
extern int g_CurrentLevel;
extern char** txt;


void renderMenu()
{
	//char** txt = new char*[100];
	txt = store_map(txt, 100);
	print_map(txt);
}
void mainmenu()
{
	processUserInput();
}