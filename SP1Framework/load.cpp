#include "load.h"

extern bool g_Level;
extern int g_CurrentLevel;
extern int g_CreativeLevel;
extern EGAMESTATES g_eGameState;
extern SGameChar   g_sChar;
extern SCreaChar   g_sCreaChar;
extern Player player1;

void loadingGame() 
{
	g_Level = true;
	g_sChar.m_cLocation.Y = 2;
	g_sChar.m_cLocation.X = 1;
	store_map(g_CurrentLevel);
	player1.character.Health = player1.character.MaxHealth;
	g_eGameState = S_GAME;
}
void loadingCreative()
{
	g_Level = false;
	g_sCreaChar.m_cCreativeLocation.Y = 2;
	g_sCreaChar.m_cCreativeLocation.X = 1;
	store_map(g_CreativeLevel);
	player1.character.Health = player1.character.MaxHealth;
	g_eGameState = S_CREATIVE;
}
void loadingEditor()
{
	store_map(g_CreativeLevel);
	g_eGameState = S_EDITOR;
}