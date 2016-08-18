#include "levelTransition.h"

extern int g_CurrentLevel;
extern SGameChar   g_sChar;
extern bool    g_abKeyPressed[K_COUNT];

void checkGameGoal()
{
	if(g_abKeyPressed[K_E])
	{
		if (g_CurrentLevel == 1 && (g_sChar.m_cLocation.Y == 2 && g_sChar.m_cLocation.X == 2))
		{
			g_CurrentLevel = 2;
			g_sChar.m_cLocation.Y = 10;
			g_sChar.m_cLocation.X = 10;
		}
		if (g_CurrentLevel == 2 && (g_sChar.m_cLocation.Y == 2 && g_sChar.m_cLocation.X == 2))
		{
			g_CurrentLevel = 3;
			g_sChar.m_cLocation.Y = 10;
			g_sChar.m_cLocation.X = 10;
		}
		if (g_CurrentLevel == 3 && (g_sChar.m_cLocation.Y == 2 && g_sChar.m_cLocation.X == 2))
		{
			g_CurrentLevel = 4;
			g_sChar.m_cLocation.Y = 10;
			g_sChar.m_cLocation.X = 10;
		}
		if (g_CurrentLevel == 4 && (g_sChar.m_cLocation.Y == 2 && g_sChar.m_cLocation.X == 2))
		{
			g_CurrentLevel = 5;
			g_sChar.m_cLocation.Y = 10;
			g_sChar.m_cLocation.X = 10;
		}
		if (g_CurrentLevel == 5 && (g_sChar.m_cLocation.Y == 2 && g_sChar.m_cLocation.X == 2))
		{
			g_CurrentLevel = 6;
			g_sChar.m_cLocation.Y = 10;
			g_sChar.m_cLocation.X = 10;
		}
		if (g_CurrentLevel == 6 && (g_sChar.m_cLocation.Y == 2 && g_sChar.m_cLocation.X == 2))
		{
			g_CurrentLevel = 1;
			g_sChar.m_cLocation.Y = 10;
			g_sChar.m_cLocation.X = 10;
		}
	}
}