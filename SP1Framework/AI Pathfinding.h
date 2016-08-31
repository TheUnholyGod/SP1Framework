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

class AI
{
private:
	int x;
	int y;
	char dir;
	char dirOpp;

public:

	int AI_id;
	COORD m_eLocation;
	bool m_bActive;
	void xCorridorMove();
	void yCorridorMove();
	void AIPathfinding();
	void RandomDirection();
	void GetOpp();
	bool AICollision(int);
	void ChangePos();
};

const int KAMBENG = 0;

const char directions[4] = { 'w', 'a', 's', 'd' };
const char xDirections[2] = {'a', 'd'};
const char yDirections[2] = {'w', 's'};


#endif