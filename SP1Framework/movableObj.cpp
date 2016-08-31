#include "movableObj.h"

extern char map[40][130];
extern SGameChar g_sChar;
extern SCreaChar g_sCreaChar;
extern bool g_abKeyPressed[K_COUNT];
extern EGAMESTATES g_eGameState;

void moveBoulder()
{
	if (g_eGameState == S_GAME)
	{
		if (g_abKeyPressed[K_LEFT] && map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X - 1] == (char)254 && map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X - 2] == (char)176) //move left
		{
			map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X - 1] = (char)176;
			map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X - 2] = (char)254;
		}
		if (g_abKeyPressed[K_RIGHT] && map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X + 1] == (char)254 && map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X + 2] == (char)176) //move right
		{
			map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X + 1] = (char)176;
			map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X + 2] = (char)254;
		}
		if (g_abKeyPressed[K_UP] && map[g_sChar.m_cLocation.Y - 2][g_sChar.m_cLocation.X] == (char)254 && map[g_sChar.m_cLocation.Y - 3][g_sChar.m_cLocation.X] == (char)176) //move up
		{
			map[g_sChar.m_cLocation.Y - 2][g_sChar.m_cLocation.X] = (char)176;
			map[g_sChar.m_cLocation.Y - 3][g_sChar.m_cLocation.X] = (char)254;
		}
		if (g_abKeyPressed[K_DOWN] && map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] == (char)254 && map[g_sChar.m_cLocation.Y + 1][g_sChar.m_cLocation.X] == (char)176) //move down
		{
			map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] = (char)176;
			map[g_sChar.m_cLocation.Y + 1][g_sChar.m_cLocation.X] = (char)254;
		}
	}
	if (g_eGameState == S_CREATIVE)
	{
		if (g_abKeyPressed[K_LEFT] && map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X - 1] == (char)254 && map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X - 2] == (char)176) //move left
		{
			map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X - 1] = (char)176;
			map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X - 2] = (char)254;
		}
		if (g_abKeyPressed[K_RIGHT] && map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X + 1] == (char)254 && map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X + 2] == (char)176) //move right
		{
			map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X + 1] = (char)176;
			map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X + 2] = (char)254;
		}
		if (g_abKeyPressed[K_UP] && map[g_sCreaChar.m_cCreativeLocation.Y - 2][g_sCreaChar.m_cCreativeLocation.X] == (char)254 && map[g_sCreaChar.m_cCreativeLocation.Y - 3][g_sCreaChar.m_cCreativeLocation.X] == (char)176) //move up
		{
			map[g_sCreaChar.m_cCreativeLocation.Y - 2][g_sCreaChar.m_cCreativeLocation.X] = (char)176;
			map[g_sCreaChar.m_cCreativeLocation.Y - 3][g_sCreaChar.m_cCreativeLocation.X] = (char)254;
		}
		if (g_abKeyPressed[K_DOWN] && map[g_sCreaChar.m_cCreativeLocation.Y][g_sCreaChar.m_cCreativeLocation.X] == (char)254 && map[g_sCreaChar.m_cCreativeLocation.Y + 1][g_sCreaChar.m_cCreativeLocation.X] == (char)176) //move down
		{
			map[g_sCreaChar.m_cCreativeLocation.Y][g_sCreaChar.m_cCreativeLocation.X] = (char)176;
			map[g_sCreaChar.m_cCreativeLocation.Y + 1][g_sCreaChar.m_cCreativeLocation.X] = (char)254;
		}
	}
}