#include "combat.h"
#include <vector>
using std::vector;

//-----Object Declaration-----//
Player player1;
Enemy enemy1;
Enemy enemy2;
COORD combatdisplaycoord;

char** display = new char*[115];

void combat()
{
	string line;
	int Victory;
	int action;

	player1.init();

	//for (int i = 0;; i++)
	//{

	/*	if (i >= 1)
		{
			if (Victory != 2)
			{
				break;
			}
		}
*/
		/* if (i >= 1)
		{
		if (Victory != 2)
		{
		break;
		}
		}
		*/

		//cout << ">Action: ";
		//cin >> action;

		/*if (action == 1)
		{

			attackProcess();

		attackProcess();

		}

		else if (action == 2)
		{

			return 0;

		return 0;

		}*/

		//Victory = checkVictory(player1.character.Health, enemy1.boss.Health);
	//}

	//if (Victory == 1)
	//{

	//	system("CLS");

	//	fstream Victory;
	//	Victory.open("Victory.txt");
	//	if (Victory.is_open())
	//	{
	//		system("COLOR 0B");
	//		while (getline(Victory, line))
	//		{
	//			//cout << line << '\n';
	//		}
	//		Victory.close();
	//	}
	//}
	//else if (Victory == 0)
	//{
	//	system("CLS");

	//	fstream Lose;
	//	Lose.open("Lose.txt");
	//	if (Lose.is_open())
	//	{
	//		system("COLOR 0B");
	//		while (getline(Lose, line))
	//		{
	//			//cout << line << '\n';
	//		}
	//		Lose.close();
	//	}

	// system("CLS");

	// fstream Victory;
	// Victory.open("Victory.txt");
	// if (Victory.is_open())
	// {
	//  system("COLOR 0B");
	//  while (getline(Victory, line))
	//  {
	//   //cout << line << '\n';
	//  }
	//  Victory.close();
	// }
	//}
	//else if (Victory == 0)
	//{
	// system("CLS");

	// fstream Lose;
	// Lose.open("Lose.txt");
	// if (Lose.is_open())
	// {
	//  system("COLOR 0B");
	//  while (getline(Lose, line))
	//  {
	//   //cout << line << '\n';
	//  }
	//  Lose.close();
	// }

	//}
}


void attackProcess()
{
	int holddamage = player1.damageDealt(player1.character.Attack, enemy1.boss1.Defence);
	enemy1.healthUpdate(holddamage);
	int hold = player1.damageSustained(enemy1.getAttack(enemy1.boss1.MaxAttack, enemy1.boss1.MinAttack), player1.character.Defence);
	player1.healthUpdate(hold);
}

void combatdisplay()
{
	enemy1.display(combatdisplaycoord, enemy1.boss1.Health, enemy1.boss1.MaxHealth, enemy1.boss1.Attack, enemy1.boss1.Defence);
	display = store_map(display, 69);

	combatdisplaycoord.X = 0;
	combatdisplaycoord.Y = 5;

	for (int i = 0; i < 24; ++i)
	{
		combatdisplaycoord.Y = i + 1;
		for (int j = 0; j <= 115; ++j)
		{
			if (display[i][j] == '-')
			{
				display[i][j] = (char)(32);
			}
			g_Console.writeToBuffer(combatdisplaycoord, display[i][j]);
		}
	}

	player1.display(combatdisplaycoord);
}

int checkVictory(int playerhealth, int enemyhealth)
{
	if (enemyhealth <= 0)
	{
		return 1;
	}
	else if (playerhealth <= 0)
	{
		return 0;
	}
	else
	{
		return 2;
	}
}

void enemyinit()
{
	int i = 0;
	int att = 20;
	int max = 40;

	/*if (i == 0)
	{
		att = 1;
		max = 1;
		i++;
	}
	else if (i == 1)
	{
		att = 30;
		max = 50;
		i++;
	}
	else if (i == 2)
	{
		att = 75;
		max = 90;
		i++;
	}
	else if (i == 3)
	{
		att = 100;
		max = 125;
		i++;
	}
	else if (i == 4)
	{
		att = 1000;
		max = 1000;
		i++;
	}
	else if (i == 5)
	{
		att = 250;
		max = 450;
	}*/
	enemy1.init(att,max);
	enemy2.init(att, max);
}

