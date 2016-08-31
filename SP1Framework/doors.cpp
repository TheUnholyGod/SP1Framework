#include "doors.h"

extern EGAMESTATES g_eGameState;
extern SCreaChar   g_sCreaChar;
extern SGameChar   g_sChar;
extern bool		   g_abKeyPressed[K_COUNT];
extern char        map[40][130];
extern int	       g_KeysObtain;

void KeyObtain()
{
	if (g_eGameState == S_GAME)
	{
		if (map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] == (char)168)
		{
			g_KeysObtain++;
			map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] = (char)176;
		}
	}
	if (g_eGameState == S_CREATIVE)
	{
		if (map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X] == (char)168)
		{
			g_KeysObtain++;
			map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X] = (char)176;
		}
	}
}

void DoorOpen()
{
	if (g_eGameState == S_GAME)
	{
		if (g_abKeyPressed[K_E] && g_abKeyPressed[K_UP] && map[g_sChar.m_cLocation.Y - 2][g_sChar.m_cLocation.X] == (char)219 && g_KeysObtain > 0) //if door is above player
		{
			g_KeysObtain--;
			map[g_sChar.m_cLocation.Y - 2][g_sChar.m_cLocation.X] = (char)176;
		}
		if (g_abKeyPressed[K_E] && g_abKeyPressed[K_DOWN] && map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] == (char)219 && g_KeysObtain > 0) //if door is below player
		{
			g_KeysObtain--;
			map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] = (char)176;
		}
		if (g_abKeyPressed[K_E] && g_abKeyPressed[K_LEFT] && map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X - 1] == (char)219 && g_KeysObtain > 0) //if door is to the left
		{
			g_KeysObtain--;
			map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X - 1] = (char)176;
		}
		if (g_abKeyPressed[K_E] && g_abKeyPressed[K_RIGHT] && map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X + 1] == (char)219 && g_KeysObtain > 0) //if door is to the right
		{
			g_KeysObtain--;
			map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X + 1] = (char)176;
		}
	}

	if (g_eGameState == S_CREATIVE)
	{
		if (g_abKeyPressed[K_E] && g_abKeyPressed[K_UP] && map[g_sCreaChar.m_cCreativeLocation.Y - 2][g_sCreaChar.m_cCreativeLocation.X] == (char)219 && g_KeysObtain > 0) //if door is above player
		{
			g_KeysObtain--;
			map[g_sCreaChar.m_cCreativeLocation.Y - 2][g_sCreaChar.m_cCreativeLocation.X] = (char)176;
		}
		if (g_abKeyPressed[K_E] && g_abKeyPressed[K_DOWN] && map[g_sCreaChar.m_cCreativeLocation.Y][g_sCreaChar.m_cCreativeLocation.X] == (char)219 && g_KeysObtain > 0) //if door is below player
		{
			g_KeysObtain--;
			map[g_sCreaChar.m_cCreativeLocation.Y][g_sCreaChar.m_cCreativeLocation.X] = (char)176;
		}
		if (g_abKeyPressed[K_E] && g_abKeyPressed[K_LEFT] && map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X - 1] == (char)219 && g_KeysObtain > 0) //if door is to the left
		{
			g_KeysObtain--;
			map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X - 1] = (char)176;
		}
		if (g_abKeyPressed[K_E] && g_abKeyPressed[K_RIGHT] && map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X + 1] == (char)219 && g_KeysObtain > 0) //if door is to the right
		{
			g_KeysObtain--;
			map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X + 1] = (char)176;
		}
	}
}