#include "doors.h"

extern EGAMESTATES g_eGameState;
extern SCreaChar   g_sCreaChar;
extern SGameChar   g_sChar;
extern bool		   g_abKeyPressed[K_COUNT];
extern int		   g_CurrentLevel;
extern bool	       g_isKeyObtain;
extern bool		   g_isUpdated;
extern char        map[40][130];

void KeyObtain()
{
	if (g_eGameState == S_GAME)
	{
		if (g_abKeyPressed[K_E] && map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] == (char)168)
		{
			g_isKeyObtain = true;
			map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] = (char)176;
			g_isUpdated = false;
		}
	}
	if (g_eGameState == S_CREATIVE)
	{
		if (g_abKeyPressed[K_E] && map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X] == (char)168)
		{
			g_isKeyObtain = true;
			map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X] = (char)176;
			g_isUpdated = false;
		}
	}
}

void DoorOpen()
{
	if (g_eGameState == S_GAME)
	{
		if (g_abKeyPressed[K_E] && map[g_sChar.m_cLocation.Y - 2][g_sChar.m_cLocation.X] == (char)219 && g_isKeyObtain == true) //if door is above player
		{
			map[g_sChar.m_cLocation.Y - 2][g_sChar.m_cLocation.X] = (char)176;
		}
		if (g_abKeyPressed[K_E] && map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] == (char)219 && g_isKeyObtain == true) //if door is below player
		{
			map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] = (char)176;
		}
		if (g_abKeyPressed[K_E] && map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X - 1] == (char)219 && g_isKeyObtain == true) //if door is to the left
		{
			map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X - 1] = (char)176;
		}
		if (g_abKeyPressed[K_E] && map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X + 1] == (char)219 && g_isKeyObtain == true) //if door is to the right
		{
			map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X + 1] = (char)176;
		}
	}

	if (g_eGameState == S_CREATIVE)
	{
		if (g_abKeyPressed[K_E] && map[g_sCreaChar.m_cCreativeLocation.Y - 2][g_sCreaChar.m_cCreativeLocation.X] == (char)219 && g_isKeyObtain == true) //if door is above player
		{
			map[g_sCreaChar.m_cCreativeLocation.Y - 2][g_sCreaChar.m_cCreativeLocation.X] = (char)176;
		}
		if (g_abKeyPressed[K_E] && map[g_sCreaChar.m_cCreativeLocation.Y][g_sCreaChar.m_cCreativeLocation.X] == (char)219 && g_isKeyObtain == true) //if door is below player
		{
			map[g_sCreaChar.m_cCreativeLocation.Y][g_sCreaChar.m_cCreativeLocation.X] = (char)176;
		}
		if (g_abKeyPressed[K_E] && map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X - 1] == (char)219 && g_isKeyObtain == true) //if door is to the left
		{
			map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X - 1] = (char)176;
		}
		if (g_abKeyPressed[K_E] && map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X + 1] == (char)219 && g_isKeyObtain == true) //if door is to the right
		{
			map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X + 1] = (char)176;
		}
	}
}