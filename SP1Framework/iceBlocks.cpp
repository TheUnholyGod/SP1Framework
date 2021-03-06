#include "iceBlocks.h"

extern char				map[40][130];
extern bool				g_abKeyPressed[K_COUNT];
extern SGameChar	    g_sChar;
extern EGAMESTATES	    g_eGameState;
extern SCreaChar		g_sCreaChar;
extern string			g_playerDirection;
extern double			g_dElapsedTime, g_SlidingSpeed;
unsigned int			DirectionX = 0, DirectionY = 0; 

void updateSlide()
{
	if (g_eGameState == S_GAME)
	{
		if (g_abKeyPressed[K_LEFT])
		{
			DirectionX = -1;
			DirectionY = 0;
		}

		if (g_abKeyPressed[K_RIGHT])
		{
			DirectionX = 1;
			DirectionY = 0;
		}

		if (g_abKeyPressed[K_UP])
		{
			DirectionX = 0;
			DirectionY = 1;
		}

		if (g_abKeyPressed[K_DOWN])
		{
			DirectionX = 0;
			DirectionY = -1;
		}
	}
	if (g_eGameState == S_CREATIVE)
	{
		if (g_abKeyPressed[K_LEFT])
		{
			DirectionX = -1;
			DirectionY = 0;
		}

		if (g_abKeyPressed[K_RIGHT])
		{
			DirectionX = 1;
			DirectionY = 0;
		}

		if (g_abKeyPressed[K_UP])
		{
			DirectionX = 0;
			DirectionY = 1;
		}

		if (g_abKeyPressed[K_DOWN])
		{
			DirectionX = 0;
			DirectionY = -1;
		}
	}
}

void sliding()
{
	bool isPlayerSliding = false;
	if (g_SlidingSpeed > g_dElapsedTime)
		return;

	if (g_eGameState == S_GAME)
	{
		// ---------------------- IF THE PLAYER IS ON THE ICE BLOCK AND IS FACING LEFT, SLIDE LEFT ---------------------- //
		if (map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] == (char)223 && DirectionX == -1 && DirectionY == 0)
		{
			if (map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X - 1] != (char)178 && map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X - 1] != (char)254 && map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X - 1] != (char)219)
			{
				g_sChar.m_cLocation.X--;
				g_sChar.m_cLocation.Y;
				isPlayerSliding = true;
			}
		}

		// ---------------------- IF THE PLAYER IS ON THE ICE BLOCK AND IS FACING RIGHT, SLIDE RIGHT ---------------------- //
		if (map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] == (char)223 && DirectionX == 1 && DirectionY == 0)
		{
			if (map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X + 1] != (char)178 && map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X + 1] != (char)254 && map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X + 1] != (char)219)
			{
				g_sChar.m_cLocation.X++;
				g_sChar.m_cLocation.Y;
				isPlayerSliding = true;
			}
		}

		// ---------------------- IF THE PLAYER IS ON THE ICE BLOCK AND IS FACING UP, SLIDE UP ---------------------- //
		if (map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] == (char)223 && DirectionX == 0 && DirectionY == 1)
		{
			if (map[g_sChar.m_cLocation.Y - 2][g_sChar.m_cLocation.X] != (char)178 && map[g_sChar.m_cLocation.Y - 2][g_sChar.m_cLocation.X] != (char)254 && map[g_sChar.m_cLocation.Y - 2][g_sChar.m_cLocation.X] != (char)219)
			{
				g_sChar.m_cLocation.X;
				g_sChar.m_cLocation.Y--;
				isPlayerSliding = true;
			}
		}

		// ---------------------- IF THE PLAYER IS ON THE ICE BLOCK AND IS FACING DOWN, SLIDE DOWN ---------------------- //
		if (map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] == (char)223 && DirectionX == 0 && DirectionY == -1)
		{
			if (map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] != (char)178 && map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] != (char)254 && map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] != (char)219)
			{
				g_sChar.m_cLocation.X;
				g_sChar.m_cLocation.Y++;
				isPlayerSliding = true;
			}
		}

		if (isPlayerSliding)
		{
			g_SlidingSpeed = g_dElapsedTime + 0.05;
		}
	}
	if (g_eGameState == S_CREATIVE)
	{
		// ---------------------- IF THE PLAYER IS ON THE ICE BLOCK AND IS FACING LEFT, SLIDE LEFT ---------------------- //
		if (map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X] == (char)223 && DirectionX == -1 && DirectionY == 0)
		{
			if (map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X - 1] != (char)178 && map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X - 1] != (char)254 && map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X - 1] != (char)219)
			{
				g_sCreaChar.m_cCreativeLocation.X--;
				g_sCreaChar.m_cCreativeLocation.Y;
				isPlayerSliding = true;
			}
		}

		// ---------------------- IF THE PLAYER IS ON THE ICE BLOCK AND IS FACING RIGHT, SLIDE RIGHT ---------------------- //
		if (map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X] == (char)223 && DirectionX == 1 && DirectionY == 0)
		{
			if (map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X + 1] != (char)178 && map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X + 1] != (char)254 && map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X + 1] != (char)219)
			{
				g_sCreaChar.m_cCreativeLocation.X++;
				g_sCreaChar.m_cCreativeLocation.Y;
				isPlayerSliding = true;
			}
		}

		// ---------------------- IF THE PLAYER IS ON THE ICE BLOCK AND IS FACING UP, SLIDE UP ---------------------- //
		if (map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X] == (char)223 && DirectionX == 0 && DirectionY == 1)
		{
			if (map[g_sCreaChar.m_cCreativeLocation.Y - 2][g_sCreaChar.m_cCreativeLocation.X] != (char)178 && map[g_sCreaChar.m_cCreativeLocation.Y - 2][g_sCreaChar.m_cCreativeLocation.X] != (char)254 && map[g_sCreaChar.m_cCreativeLocation.Y - 2][g_sCreaChar.m_cCreativeLocation.X] != (char)219)
			{
				g_sCreaChar.m_cCreativeLocation.X;
				g_sCreaChar.m_cCreativeLocation.Y--;
				isPlayerSliding = true;
			}
		}

		// ---------------------- IF THE PLAYER IS ON THE ICE BLOCK AND IS FACING DOWN, SLIDE DOWN ---------------------- //
		if (map[g_sCreaChar.m_cCreativeLocation.Y - 1][g_sCreaChar.m_cCreativeLocation.X] == (char)223 && DirectionX == 0 && DirectionY == -1)
		{
			if (map[g_sCreaChar.m_cCreativeLocation.Y][g_sCreaChar.m_cCreativeLocation.X] != (char)178 && map[g_sCreaChar.m_cCreativeLocation.Y][g_sCreaChar.m_cCreativeLocation.X] != (char)254 && map[g_sCreaChar.m_cCreativeLocation.Y][g_sCreaChar.m_cCreativeLocation.X] != (char)219)
			{
				g_sCreaChar.m_cCreativeLocation.X;
				g_sCreaChar.m_cCreativeLocation.Y++;
				isPlayerSliding = true;
			}
		}

		if (isPlayerSliding)
		{
			g_SlidingSpeed = g_dElapsedTime + 0.05;
		}
	}
}