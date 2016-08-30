#include "levelTransition.h"

extern int g_CurrentLevel;
extern int g_CreativeLevel;
extern SGameChar   g_sChar;
extern SCreaChar   g_sCreaChar;
extern EGAMESTATES g_eGameState;
extern bool    g_abKeyPressed[K_COUNT];
extern bool	   g_isMapLoaded;
extern bool	   g_isUpdated;
extern int X;
extern int Y;
extern int cX;
extern int cY;
extern char map[40][130];
extern int g_KeysObtain;

//Checks if the player is on the end point, if true, teleports to next level and set spawn coordinates
void checkGameGoal()
{
	if(g_abKeyPressed[K_E])
	{
		if (g_CurrentLevel == 1 && (map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] == (char)177))
		{
			g_CurrentLevel = 2;
			g_sChar.m_cLocation.Y = 2;
			g_sChar.m_cLocation.X = 1;
			g_KeysObtain = 0;
			g_eGameState = S_COMBAT;
		}
		if (g_CurrentLevel == 2 && (map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] == (char)177))
		{
			g_CurrentLevel = 3;
			g_sChar.m_cLocation.Y = 2;
			g_sChar.m_cLocation.X = 1;
			g_eGameState = S_COMBAT;
		}
		if (g_CurrentLevel == 3 && (map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] == (char)177))
		{
			g_CurrentLevel = 4;
			g_sChar.m_cLocation.Y = 2;
			g_sChar.m_cLocation.X = 1;
			g_eGameState = S_COMBAT;
		}
		if (g_CurrentLevel == 4 && (map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] == (char)177))
		{
			g_CurrentLevel = 5;
			g_sChar.m_cLocation.Y = 2;
			g_sChar.m_cLocation.X = 1;
			g_eGameState = S_COMBAT;
		}
		if (g_CurrentLevel == 5 && (map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] == (char)177))
		{
			g_CurrentLevel = 6;
			g_sChar.m_cLocation.Y = 2;
			g_sChar.m_cLocation.X = 1;
			g_eGameState = S_COMBAT;
		}
		if (g_CurrentLevel == 6 && (map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] == (char)177))
		{
			g_CurrentLevel = 1;
			g_sChar.m_cLocation.Y = 2;
			g_sChar.m_cLocation.X = 1;
			g_eGameState = S_COMBAT;
		}
		g_isUpdated = false;
	}
}
void checkCreativeGameGoal()
{
	if (g_abKeyPressed[K_E])
	{
		if (g_CreativeLevel == 101 && (map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X] == (char)177))
		{
			g_CreativeLevel = 102;
			g_sCreaChar.m_cCreativeLocation.Y = 2;
			g_sCreaChar.m_cCreativeLocation.X = 1;
			g_eGameState = S_COMBAT;
		}
		if (g_CreativeLevel == 102 && (map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X] == (char)177))
		{
			g_CreativeLevel = 103;
			g_sCreaChar.m_cCreativeLocation.Y = 2;
			g_sCreaChar.m_cCreativeLocation.X = 1;
			g_eGameState = S_COMBAT;
		}
		if (g_CreativeLevel == 103 && (map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X] == (char)177))
		{
			g_CreativeLevel = 104;
			g_sCreaChar.m_cCreativeLocation.Y = 2;
			g_sCreaChar.m_cCreativeLocation.X = 1;;
			g_eGameState = S_COMBAT;
		}
		if (g_CreativeLevel == 104 && (map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X] == (char)177))
		{
			g_CreativeLevel = 105;
			g_sCreaChar.m_cCreativeLocation.Y = 2;
			g_sCreaChar.m_cCreativeLocation.X = 1;
			g_eGameState = S_COMBAT;
		}
		if (g_CreativeLevel == 105 && (map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X] == (char)177))
		{
			g_CreativeLevel = 106;
			g_sCreaChar.m_cCreativeLocation.Y = 2;
			g_sCreaChar.m_cCreativeLocation.X = 1;
			g_eGameState = S_COMBAT;
		}
		if (g_CreativeLevel == 106 && (map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X] == (char)177))
		{
			g_CreativeLevel = 101;
			g_sCreaChar.m_cCreativeLocation.Y = 2;
			g_sCreaChar.m_cCreativeLocation.X = 1;
			g_eGameState = S_COMBAT;
		}
		g_isUpdated = false;
	}
}