#ifndef _COMBAT_H
#define _COMBAT_H

//-----Incluion Block-----//
#include <windows.h>
#include <time.h>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Framework\console.h"
#include "game.h"

//-----Extern Block-----//
extern Console g_Console;

//-----Namespace Block-----//
using namespace std;
using std::string;

//-----Player Class-----//
class Player
{
public:
	//---Player Stats---//
	struct character
	{
		int MaxHealth;
		int Health;
		int Attack;
		int Defence;
	}character;

	//---Setting Player Stats---//
	void playerBase(int health, int attack, int defence);

	//---Display Update---//
	
	void display(COORD a);

	//---Damage Done Calculation---//
	int damageDealt(int playerdamage, int enemydefence);

	//---Damage Taken Calculation---//
	int damageSustained(int enemyattack, int playerdefence);

	//---Update of Health Stat after getting hit---//
	void healthUpdate(int damageSustained);
};

//-----Enemy Class-----//
class Enemy
{
public:
	//---Enemy Stats---//

	struct boss
	{
		int MaxHealth;
		int Health;
		int Attack;
		int MaxAttack;
		int MinAttack;
		int Defence;
	}boss1;

	//---Initialisation---//
	void init(int baseatt, int maxatt);

	//---Getting Random Attack Stat---//
	int setAttack(int base, int maxatt);

	//---Formula for Defence Stat---//
	int setDefence();

	//---Formula for Health Stat---//
	int setHealth();

	//---Display Update---//
	void display(COORD a, int i, int i1, int i2, int i3);

	//---Calling for the attack---//
	int getAttack(int max, int min);

	//---Update of Health Stat after getting hit---//
	void healthUpdate(int damageDone);
};


//-----Function Declaration-----//
void combat();
void combatdisplay();
void attackProcess();
int checkVictory(int playerhealth, int enemyhealth);
void enemyinit();
void playerinit();

#endif //End of _COMBAT_H