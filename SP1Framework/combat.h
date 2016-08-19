#ifndef _COMBAT_H
#define _COMBAT_H

//-----Incluion Block-----//
#include <windows.h>
#include <time.h>
#include <string>
#include <fstream>
#include <iostream>
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
	void playerBase(int health, int attack, int defence)
	{
		character.Health = health;
		character.MaxHealth = health;
		character.Attack = attack;
		character.Defence = defence;
	}

	//---Initialisation---//
	void init()
	{
		playerBase(character.Health, character.Attack, character.Defence);
	}

	//---Display Update---//
	
	void display(COORD a)
	{
		unsigned int number_of_digits = 0;

		for (int tempHealth = character.Health; tempHealth <= 0; number_of_digits++)
		{
			tempHealth = character.Health / 10;
			if (tempHealth == 0)
			{
				break;
			}
		}

		a.X = 0;
		a.Y = 38;
		g_Console.writeToBuffer(a, "Player Health: "); // character.Health "/" character.MaxHealth);
		a.X += 15;
		g_Console.writeToBuffer(a, character.Health);
		a.X += number_of_digits;
		g_Console.writeToBuffer(a, "/");
		a.X++;
		g_Console.writeToBuffer(a, character.MaxHealth);
		a.X = 0;
		a.Y++;
		g_Console.writeToBuffer(a, "Player Attack: ");
		a.X += 15;
		g_Console.writeToBuffer(a, character.Attack);
		a.X = 0;
		a.Y++;
		g_Console.writeToBuffer(a, "Player Defence: ");
		a.X += 15;
		g_Console.writeToBuffer(a, character.Defence);
		/*cout << "Player Health: " << character.Health << "/" << character.MaxHealth << endl;
		cout << "Player Attack: " << character.Attack << endl;
		cout << "Player Defence: " << character.Defence << endl;*/
	}

	//---Damage Done Calculation---//
	int damageDealt(int playerdamage, int enemydefence)
	{
		srand(time(NULL));
		int max = rand() % 5;
		max += playerdamage;
		int min = rand() % 3;
		min = playerdamage - min;

		for (;;)
		{
			playerdamage = rand() % max;
			if (playerdamage >= min && playerdamage <= max)
			{
				break;
			}
		}
		playerdamage = playerdamage - (enemydefence / 2);
		if (playerdamage <= 0)
		{
			playerdamage = 1;
		}
		return playerdamage;
	}

	//---Damage Taken Calculation---//
	int damageSustained(int enemyattack, int playerdefence)
	{
		enemyattack = enemyattack - (playerdefence * (5 / 8));
		return enemyattack;
	}

	//---Update of Health Stat after getting hit---//
	void healthUpdate(int damageSustained)
	{
		if (damageSustained > character.Health)
		{
			character.Health = 0;
		}
		else
		{
			character.Health -= damageSustained;
		}
	}
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
	void init(int baseatt, int maxatt)
	{
		boss1.Attack = setAttack(baseatt, maxatt);
		boss1.Defence = setDefence();
		boss1.MaxHealth = setHealth();
		boss1.Health = boss1.MaxHealth;
	}

	//---Getting Random Attack Stat---//
	int setAttack(int base, int maxatt)
	{
		srand(time(NULL));
		int basedmg;
		for (basedmg = 0; basedmg >= maxatt;)
		{
			basedmg = rand() % maxatt;
		}
		maxatt = rand() % 10;
		if (maxatt < 1)
			maxatt = 1;
		maxatt += basedmg;
		boss1.MaxAttack = maxatt;
		int min = rand() % 10;
		min = basedmg - min;
		boss1.MinAttack = min;
		for (;;)
		{
			boss1.Attack = rand() % maxatt;
			if (boss1.Attack >= min && boss1.Attack <= maxatt)
			{
				break;
			}
		}
		return boss1.Attack;
	}

	//---Formula for Defence Stat---//
	int setDefence()
	{
		boss1.Defence = boss1.Attack * 4 / 3;
		return boss1.Defence;
	}

	//---Formula for Health Stat---//
	int setHealth()
	{
		boss1.Health = boss1.Defence * 3;
		boss1.MaxHealth = boss1.Health;
		return boss1.MaxHealth;
	}

	//---Display Update---//
	void display(COORD a, int i, int i1, int i2, int i3)
	{
		double oneUnit = i1 / 100.0f;
		int counthash = i * oneUnit;

		a.X = 0;
		a.Y = 1;
		g_Console.writeToBuffer(a, "Boss Health:");

		a.Y++;
		for (a.X = 0; a.X <= 119; a.X++)
		{
			if (a.X == 0)
			{
				g_Console.writeToBuffer(a, "[");
			}

			else if (a.X <= counthash + 1)
			{
				g_Console.writeToBuffer(a, "#");
			}
			else
			{
				g_Console.writeToBuffer(a, "-");
			}
 		}
		g_Console.writeToBuffer(a, "]");
		a.X = 0;
		a.Y++;
		g_Console.writeToBuffer(a, "Boss Attack: ");
		a.X += 13;
		g_Console.writeToBuffer(a, i2);
		a.X = 0;
		a.Y++;
		g_Console.writeToBuffer(a, "Boss Defence: ");
		a.X += 14;
		g_Console.writeToBuffer(a, i3);
		/*cout << "Boss Health" << endl;
		for (int i = 1; i <= 118; i++)
		{
			if (i == 1)
			{
				cout << "[";
			}

			if (i <= counthash)
			{
				cout << "#";
			}
			else
			{
				cout << "-";
			}

			if (i == 118)
				cout << "]" << endl;

		if (i == 1)
		{
		cout << "[";
		}

		if (i <= counthash)
		{
		cout << "#";
		}
		else
		{
		cout << "-";
		}

		if (i == 118)
		cout << "]" << endl;

		}

		cout << "Boss Attack: " << boss.Attack << endl;
		cout << "Boss Defence: " << boss.Defence << endl;*/
	}

	//---Calling for the attack---//
	int getAttack(int max ,int min)
	{
		for (;;)
		{
			boss1.Attack = rand() % max;
			if (boss1.Attack >= min && boss1.Attack <= max)
			{
				break;
			}
		}
		return boss1.Attack;
	}

	//---Update of Health Stat after getting hit---//
	void healthUpdate(int damageDone)
	{
		if (damageDone > boss1.Health)
		{
			boss1.Health = 0;
		}
		else
		{
			boss1.Health -= damageDone;
		}
	}
};


//-----Function Declaration-----//
void combat();
void combatdisplay();
void attackProcess();
int checkVictory(int playerhealth, int enemyhealth);
void enemyinit();

#endif //End of _COMBAT_H