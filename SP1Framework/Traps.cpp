#include "Traps.h"

extern SGameChar	 g_sChar;
extern Projectile * AIProjectile;
extern Player player1;
extern EGAMESTATES g_eGameState;
extern char** txt;
extern bool SpikesActivated;
extern bool DeathPitOpened;
extern bool ProjectileFired;
extern bool ProjectileCollision;
extern bool SpikeSwitch;
extern int g_CurrentLevel;
extern double g_dProjBounceTime;
extern double g_dElapsedTime;
extern double g_dSpikeTriggerTime;
extern double g_dSpikeActivationTime;
extern double g_dDeathPitTriggerTime;
extern double g_dDeathPitActivationTime;
extern double g_dProjectileTravelTime;
extern double g_dProjectileFireTime;
extern char map[40][130];


void Spikes()
{

		if (g_dElapsedTime > g_dSpikeTriggerTime)
		{
			SpikesActivated = true;
			g_dSpikeTriggerTime = 5.0 + g_dElapsedTime;

		}
		if (g_dElapsedTime > g_dSpikeActivationTime)
		{
			SpikesActivated = false;
			g_dSpikeActivationTime = 3.0 + g_dSpikeTriggerTime;

		}
}

void DeathPit()
{

	if (g_dElapsedTime > g_dDeathPitTriggerTime)
	{
		DeathPitOpened = true;
		g_dDeathPitTriggerTime = 9.0 + g_dElapsedTime;
	
	}
	if (g_dElapsedTime > g_dDeathPitActivationTime)
	{
		DeathPitOpened = false;
		g_dDeathPitActivationTime = 3.0 + g_dDeathPitTriggerTime;

	}
}
void Projectile::ProjectileFire(char proj_direction, int InitX, int InitY)
{	
		
	if(ProjectileCollision(g_CurrentLevel) == true)
	{
		projdir = 'w';
		ProjectileMove();
	}
	else
	{
		AIProjectile->m_pLocation.X = InitX;
		AIProjectile->m_pLocation.Y = InitY;
	}
		
}


bool Projectile::ProjectileCollision(int levelnumber)
{

	if (projdir == 'w' && AIProjectile->m_pLocation.X > 0)
	{
		if (map[AIProjectile->m_pLocation.Y - 2][AIProjectile->m_pLocation.X] == (char)178 || map[AIProjectile->m_pLocation.Y - 2][AIProjectile->m_pLocation.X] == (char)219 || map[AIProjectile->m_pLocation.Y - 2][AIProjectile->m_pLocation.X] == (char)254 || map[AIProjectile->m_pLocation.Y - 2][AIProjectile->m_pLocation.X] == (char)220)
			return false;
	}
	if (projdir == 'a' && AIProjectile->m_pLocation.Y > 0)
	{
		if (map[AIProjectile->m_pLocation.Y - 1][AIProjectile->m_pLocation.X - 1] == (char)178 || map[AIProjectile->m_pLocation.Y - 1][AIProjectile->m_pLocation.X - 1] == (char)219 || map[AIProjectile->m_pLocation.Y - 1][AIProjectile->m_pLocation.X - 1] == (char)254 || map[AIProjectile->m_pLocation.Y - 1][AIProjectile->m_pLocation.X - 1] == (char)220)
			return false;
	}
	if (projdir == 's' && AIProjectile->m_pLocation.X < g_Console.getConsoleSize().X - 1)
	{
		if (map[AIProjectile->m_pLocation.Y][AIProjectile->m_pLocation.X] == (char)178 || map[AIProjectile->m_pLocation.Y][AIProjectile->m_pLocation.X] == (char)219 || map[AIProjectile->m_pLocation.Y][AIProjectile->m_pLocation.X] == (char)254 || map[AIProjectile->m_pLocation.Y][AIProjectile->m_pLocation.X] == (char)220)
			return false;
	}
	if (projdir == 'd' && AIProjectile->m_pLocation.Y < g_Console.getConsoleSize().Y - 1)
	{
		if (map[AIProjectile->m_pLocation.Y - 1][AIProjectile->m_pLocation.X + 1] == (char)178 || map[AIProjectile->m_pLocation.Y - 1][AIProjectile->m_pLocation.X + 1] == (char)219 || map[AIProjectile->m_pLocation.Y - 1][AIProjectile->m_pLocation.X + 1] == (char)254 || map[AIProjectile->m_pLocation.Y - 1][AIProjectile->m_pLocation.X + 1] == (char)220)
			return false;
	}
	else
		return true;
}

void Projectile::ProjectileMove()
{
	bool bProjectileSomethingHappened = false;
	if (g_dProjBounceTime > g_dElapsedTime)
		return;
	if (projdir == 'a')
	{
		if (ProjectileCollision(g_CurrentLevel))
		{
			bProjectileSomethingHappened = true;
			--AIProjectile->m_pLocation.X;
		}
	}

	else if (projdir == 'd')
	{
		if (ProjectileCollision(g_CurrentLevel))
		{
			bProjectileSomethingHappened = true;
			++AIProjectile->m_pLocation.X;
		}

	}

	else if (projdir == 'w')
	{
		if (ProjectileCollision(g_CurrentLevel))
		{
			bProjectileSomethingHappened = true;
			--AIProjectile->m_pLocation.Y;
		}

	}
	else if (projdir == 's')
	{
		if (ProjectileCollision(g_CurrentLevel))
		{
			bProjectileSomethingHappened = true;
			++AIProjectile->m_pLocation.Y;
		}

	}
	if (bProjectileSomethingHappened)
	{
		// set the bounce time to some time in the future to prevent accidental triggers
		g_dProjBounceTime = g_dElapsedTime + 0.250; // 125ms should be enough
	}

}



