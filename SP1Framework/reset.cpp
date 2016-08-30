#include "reset.h"
extern int g_CurrentLevel;
extern int g_CreativeLevel;
extern EGAMESTATES g_eGameState;
extern int g_KeysObtain;
extern int g_PicksObtain;
extern bool ;
extern SGameChar g_sChar;
extern SCreaChar g_sCreaChar;

void reset()
{
	if (g_eGameState == S_GAME)
	{
		g_sChar.m_cLocation.Y = 2;
		g_sChar.m_cLocation.X = 1;
		g_KeysObtain = 0;
		g_PicksObtain = 0;
		store_map(g_CurrentLevel);
	}

	if (g_eGameState == S_CREATIVE)
	{
		g_sCreaChar.m_cCreativeLocation.Y = 2;
		g_sCreaChar.m_cCreativeLocation.X = 1;
		g_KeysObtain = 0;
		g_PicksObtain = 0;
		store_map(g_CreativeLevel);
	}
}