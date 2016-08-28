#include "doors.h"

extern SGameChar   g_sChar;
extern bool		   g_abKeyPressed[K_COUNT];
extern int		   g_CurrentLevel;
extern bool	       g_isKeyObtain;
extern bool		   g_isUpdated;
extern char        map[40][130];

void KeyObtain()
{
	if (g_abKeyPressed[K_E] && map[g_sChar.m_cLocation.Y-1][g_sChar.m_cLocation.X] == (char)168)
	{
		g_isKeyObtain = true;
		map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] = (char)176;
		g_isUpdated = false;
	}
}

void DoorOpen()
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