#include "smashableObject.h"

extern EGAMESTATES g_eGameState;
extern SCreaChar   g_sCreaChar;
extern SGameChar   g_sChar;
extern bool		   g_abKeyPressed[K_COUNT];
extern char        map[40][130];
extern int		   g_PicksObtain;
extern bool		   g_isUpdated;

void pickObtain()
{
	if (g_eGameState == S_GAME)
	{
		if (g_abKeyPressed[K_E] && map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] == (char)156)
		{
			g_PicksObtain += 4;
			map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] = (char)176;
			g_isUpdated = false;
		}
	}

	if (g_eGameState == S_CREATIVE)
	{
		if (g_abKeyPressed[K_E] && map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X] == (char)156)
		{
			g_PicksObtain += 4;
			map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X] = (char)176;
			g_isUpdated = false;
		}
	}
}

void objectStatus()
{
	if (g_eGameState == S_GAME)
	{
		if (g_abKeyPressed[K_E] && g_abKeyPressed[K_UP] && map[g_sChar.m_cLocation.Y - 2][g_sChar.m_cLocation.X] == (char)220 && g_PicksObtain > 0) //if smashable object is above player
		{
			g_PicksObtain--;
			map[g_sChar.m_cLocation.Y - 2][g_sChar.m_cLocation.X] = (char)176;
		}
		if (g_abKeyPressed[K_E] && g_abKeyPressed[K_DOWN] && map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] == (char)220 && g_PicksObtain > 0) //if smashable object is below player
		{
			g_PicksObtain--;
			map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] = (char)176;
		}
		if (g_abKeyPressed[K_E] && g_abKeyPressed[K_LEFT] && map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X - 1] == (char)220 && g_PicksObtain > 0) //if smashable object is to the left
		{
			g_PicksObtain--;
			map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X - 1] = (char)176;
		}
		if (g_abKeyPressed[K_E] && g_abKeyPressed[K_RIGHT] && map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X + 1] == (char)220 && g_PicksObtain > 0) //if smashable object is to the right
		{
			g_PicksObtain--;
			map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X + 1] = (char)176;
		}
	}

	if (g_eGameState == S_CREATIVE)
	{
		if (g_abKeyPressed[K_E] && g_abKeyPressed[K_UP] && map[g_sCreaChar.m_cCreativeLocation.Y - 2][g_sCreaChar.m_cCreativeLocation.X] == (char)220 && g_PicksObtain > 0) //if smashable object is above player
		{
			g_PicksObtain--;
			map[g_sCreaChar.m_cCreativeLocation.Y - 2][g_sCreaChar.m_cCreativeLocation.X] = (char)176;
		}
		if (g_abKeyPressed[K_E] && g_abKeyPressed[K_DOWN] && map[g_sCreaChar.m_cCreativeLocation.Y][g_sCreaChar.m_cCreativeLocation.X] == (char)220 && g_PicksObtain > 0) //if smashable object is below player
		{
			g_PicksObtain--;
			map[g_sCreaChar.m_cCreativeLocation.Y][g_sCreaChar.m_cCreativeLocation.X] = (char)176;
		}
		if (g_abKeyPressed[K_E] && g_abKeyPressed[K_LEFT] && map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X - 1] == (char)220 && g_PicksObtain > 0) //if smashable object is to the left
		{
			g_PicksObtain--;
			map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X - 1] = (char)176;
		}
		if (g_abKeyPressed[K_E] && g_abKeyPressed[K_RIGHT] && map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X + 1] == (char)220 && g_PicksObtain > 0) //if smashable object is to the right
		{
			g_PicksObtain--;
			map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X + 1] = (char)176;
		}
	}
}