#include "combat.h"

//-----Object Declaration-----//
Player player1;
Enemy enemy1;
COORD combatdisplaycoord;

void combat()
{
	string line;
	int Victory;
	int action;

	player1.init();
	enemy1.init();

	for (int i = 0;; i++)
	{
		display();

	/*	if (i >= 1)
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
		}

		else if (action == 2)
		{
			return 0;
		}*/

		//Victory = checkVictory(player1.character.Health, enemy1.boss.Health);
	}

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
	//}
}


void attackProcess()
{
	int holddamage = player1.damageDealt(player1.character.Attack, enemy1.boss.Defence);
	enemy1.healthUpdate(holddamage);
	int hold = player1.damageSustained(enemy1.getAttack(), player1.character.Defence);
	player1.healthUpdate(hold);
}

void display()
{
	string line;

	system("CLS");

	enemy1.display(combatdisplaycoord);
//	fstream myEnemy;
//	myEnemy.open("Spider.txt");
//	if (myEnemy.is_open())
//	{
//		system("COLOR 0B");
//		while (getline(myEnemy, line))
//		{
//			//cout << line << '\n';
//		}
//		myEnemy.close();
//	}
//
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