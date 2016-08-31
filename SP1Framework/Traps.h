#ifndef _TRAPS_H
#define _TRAPS_H

#include <iostream>
#include "Framework\console.h"
#include "Framework\timer.h"
#include "loadlevel.h"
#include <fstream>
#include <cstdlib>
#include "Windows.h"
#include <string>
#include <vector>
#include "game.h"


using namespace std;

class Projectile
{
private:
	char projdir;
public:
	COORD m_pLocation;
	int Proj_id;
	void ProjectileMove();
	void ProjectileFire(char, int, int);
	bool ProjectileCollision(int);
};
const int ARROW = 0;

void Spikes();

void Projectiles();

#endif