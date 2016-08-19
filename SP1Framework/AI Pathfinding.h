#ifndef _AI_PATHFINDING_H
#define _AI_PATHFINDING_H

#include <iostream>
#include "Framework\console.h"
#include "Framework\timer.h"
#include "loadlevel.h"
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include "game.h"

using namespace std;

class Enemy
{
private:
	int x;
	int y;
	char dir;
	char dirOld;
	char dirNew;
	char dirOpp;

public:

	COORD m_eLocation;
	bool m_bActive;
	void EnemyMove(int, int);
	void AIPathfinding(bool[4]);
	void RandomDirection();
	void GetOpposite();
	bool EnemyCollision();
	void ChangePos();
};

const int KAMBENG = 0;

const char no_collision[1] = { '-' };

const char directions[4] = { 'w', 'a', 's', 'd' };


#endif