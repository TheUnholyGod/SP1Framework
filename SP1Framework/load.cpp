#include "load.h"

extern bool g_isUpdated;
extern int g_CurrentLevel;
extern int g_CreativeLevel;
extern EGAMESTATES g_eGameState;

void loadingGame() 
{
	store_map(g_CurrentLevel);
	g_eGameState = S_GAME;
}
void loadingCreative()
{
	store_map(g_CreativeLevel);
	g_eGameState = S_CREATIVE;
	g_isUpdated = false;
}
void loadingEditor()
{
	store_map(g_CreativeLevel);
	g_eGameState = S_EDITOR;
	g_isUpdated = false;
}