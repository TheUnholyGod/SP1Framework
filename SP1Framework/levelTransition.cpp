#include "levelTransition.h"

extern int g_CurrentLevel;
extern SGameChar   g_sChar;
extern bool    g_abKeyPressed[K_COUNT];

void checkGameGoal()
{
	//game end condition for lv 1
	if (g_CurrentLevel == 1 && g_abKeyPressed[K_SPACE] && g_sChar.m_cLocation.X == 79 && g_sChar.m_cLocation.Y == 24)
	{
		g_CurrentLevel = 2;
		g_sChar.m_cLocation.X = 20;
		g_sChar.m_cLocation.Y = 20;
		//insert spawn location for lv2
	}
	//game end condition for lv 2
	if (g_CurrentLevel == 2 && g_abKeyPressed[K_LEFT] && g_sChar.m_cLocation.X == 0 && g_sChar.m_cLocation.Y == 0)
	{
		g_CurrentLevel = 3;
	}
	//game end condition for lv 3
	if (g_CurrentLevel == 3 && g_abKeyPressed[K_LEFT] && g_sChar.m_cLocation.X == 0 && g_sChar.m_cLocation.Y == 0)
	{
		g_CurrentLevel = 4;
	}
	//game end condition for lv 4
	if (g_CurrentLevel == 4 && g_abKeyPressed[K_LEFT] && g_sChar.m_cLocation.X == 0 && g_sChar.m_cLocation.Y == 0)
	{
		g_CurrentLevel = 5;
	}
	//game end condition for lv 5
	if (g_CurrentLevel == 5 && g_abKeyPressed[K_LEFT] && g_sChar.m_cLocation.X == 0 && g_sChar.m_cLocation.Y == 0)
	{
		g_CurrentLevel = 6;
	}
}