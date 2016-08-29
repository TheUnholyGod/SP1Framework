#include "collision.h"

extern SGameChar   g_sChar;
extern SCreaChar   g_sCreaChar;
extern bool    g_abKeyPressed[K_COUNT];
extern char map[40][130];


bool colDetection(int levelnumber)
{
	if (g_abKeyPressed[K_UP] && g_sChar.m_cLocation.X > 0)
	{
			if (map[g_sChar.m_cLocation.Y - 2][g_sChar.m_cLocation.X] == (char)178 || map[g_sChar.m_cLocation.Y - 2][g_sChar.m_cLocation.X] == (char)219 || map[g_sChar.m_cLocation.Y - 2][g_sChar.m_cLocation.X] == (char)254)
				return false;
	}
	if (g_abKeyPressed[K_LEFT] && g_sChar.m_cLocation.Y > 0)
	{
			if (map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X - 1] == (char)178 || map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X - 1] == (char)219 || map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X - 1] == (char)254)
				return false;
	}
	if (g_abKeyPressed[K_DOWN] && g_sChar.m_cLocation.X < g_Console.getConsoleSize().X - 1)
	{
			if (map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] == (char)178 || map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] == (char)219 || map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] == (char)254)
				return false;
	}
	if (g_abKeyPressed[K_RIGHT] && g_sChar.m_cLocation.Y < g_Console.getConsoleSize().Y - 1)
	{
		if (map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X + 1] == (char)178 || map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X + 1] == (char)219 || map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X + 1] == (char)254)
			return false;
	}
	else
		return true;
}
bool creativeColDetection(int levelnumber)
{
	if (g_abKeyPressed[K_UP] && g_sCreaChar.m_cCreativeLocation.X > 0)
	{
		if (map[g_sCreaChar.m_cCreativeLocation.Y - 2][g_sCreaChar.m_cCreativeLocation.X] == (char)178 || map[g_sCreaChar.m_cCreativeLocation.Y - 2][g_sCreaChar.m_cCreativeLocation.X] == (char)219 || map[g_sCreaChar.m_cCreativeLocation.Y - 2][g_sCreaChar.m_cCreativeLocation.X] == (char)254)
			return false;
	}
	if (g_abKeyPressed[K_LEFT] && g_sCreaChar.m_cCreativeLocation.Y > 0)
	{
		if (map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X - 1] == (char)178 || map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X - 1] == (char)219 || map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X - 1] == (char)254)
			return false;
	}
	if (g_abKeyPressed[K_DOWN] && g_sCreaChar.m_cCreativeLocation.X < g_Console.getConsoleSize().X - 1)
	{
		if (map[g_sCreaChar.m_cCreativeLocation.Y][g_sCreaChar.m_cCreativeLocation.X] == (char)178 || map[g_sCreaChar.m_cCreativeLocation.Y][g_sCreaChar.m_cCreativeLocation.X] == (char)219 || map[g_sCreaChar.m_cCreativeLocation.Y][g_sCreaChar.m_cCreativeLocation.X] == (char)254)
			return false;
	}
	if (g_abKeyPressed[K_RIGHT] && g_sCreaChar.m_cCreativeLocation.Y < g_Console.getConsoleSize().Y - 1)
	{
		if (map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X + 1] == (char)178 || map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X + 1] == (char)219 || map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X + 1] == (char)254)
			return false;
	}
	else
		return true;
}
