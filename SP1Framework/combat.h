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
		int Defence;
	}boss;

	//---Initialisation---//
	void init()
	{
		setAttack();
		setDefence();
		setHealth();
	}

	//---Getting Random Attack Stat---//
	void setAttack()
	{
		srand(time(NULL));
		int basedmg;
		for (basedmg = 0; basedmg < 30;)
		{
			basedmg = rand() % 60;
		}
		int max = rand() % 10;
		max += basedmg;
		int min = rand() % 10;
		min = basedmg - min;
		for (;;)
		{
			boss.Attack = rand() % max;
			if (boss.Attack >= min && boss.Attack <= max)
			{
				break;
			}
		}
	}

	//---Formula for Defence Stat---//
	void setDefence()
	{
		boss.Defence = boss.Attack * 4 / 3;
	}

	//---Formula for Health Stat---//
	void setHealth()
	{
		boss.Health = boss.Defence * 3;
		boss.MaxHealth = boss.Health;
	}

	//---Display Update---//
	void display(COORD a)
	{
		double oneUnit = boss.MaxHealth / 118.0f;
		int counthash = boss.Health * oneUnit;

		a.X = 0;
		a.Y = 1;
		g_Console.writeToBuffer(a, "Boss Health:");

		a.Y = 2;
		for (a.X = 0; a.X <= 118; a.X++)
		{
			if (a.X == 0)
			{
				g_Console.writeToBuffer(a, "[");
			}

			else if (a.X <= counthash + 1)
			{
				g_Console.writeToBuffer(a, "#");
			}
			else if (a.X == 119)
			{
				g_Console.writeToBuffer(a, "]");
			}
			else
			{
				g_Console.writeToBuffer(a, "-");
			}
		}
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
		}

		cout << "Boss Attack: " << boss.Attack << endl;
		cout << "Boss Defence: " << boss.Defence << endl;*/
	}

	//---Calling for the attack---//
	int getAttack()
	{
		return boss.Attack; //This may be changed
	}

	//---Update of Health Stat after getting hit---//
	void healthUpdate(int damageDone)
	{
		if (damageDone > boss.Health)
		{
			boss.Health = 0;
		}
		else
		{
			boss.Health -= damageDone;
		}
	}
};


//-----Function Declaration-----//
void combat();
void display();
void attackProcess();
int checkVictory(int playerhealth, int enemyhealth);

<<<<<<< HEAD
#endif //End of _COMBAT_H
=======
#endif //End of _COMBAT_H
>>>>>>> 7d035a5a080004b03e07b72a090ecd634fd191ac
