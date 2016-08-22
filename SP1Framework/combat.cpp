#include "combat.h"

//-----Object and Identifier Declaration-----//
extern bool g_isUpdated;
Player player1;
Enemy enemy1, enemy2, enemy3, enemy4, enemy5, enemy6, enemynonboss;
COORD combatdisplaycoord;
char** display = new char*[53];
char** buttonfiller = new char*[63];
char** textboxfiller = new char*[75];
int enemySelector = 0;
bool isUpPressed = true;

/*/
-Functions from Main Combat File-
/*/

//--------Main Code Runs-------//

	//-----Main Combat File-----//
	void combat()
	{
		string line;
		int Victory;
		int action;

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

	//-----Process of Attack-----//
	void attackProcess()	
	{
		int holddamage = player1.damageDealt(player1.character.Attack, enemy1.boss1.Defence);
		enemy1.healthUpdate(holddamage);
		int hold = player1.damageSustained(enemy1.getAttack(enemy1.boss1.MaxAttack, enemy1.boss1.MinAttack), player1.character.Defence);
		player1.healthUpdate(hold);
	}

	//-----Checking for Victory-----//
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

//-------Combat Render-------//

	//-----Combat Render-----//
	void combatdisplay()
	{
		enemy1.display(combatdisplaycoord, enemy1.boss1.Health, enemy1.boss1.MaxHealth, enemy1.boss1.Attack, enemy1.boss1.Defence);
		display = enemyselector(display, enemySelector);

		combatdisplaycoord.X = 0;
		combatdisplaycoord.Y = 5;

		for (int i = 0; i < 24; ++i)
		{
			for (int j = 0; j < 53; ++j)
			{
				if (display[i][j] == '-')
				{
					display[i][j] = (char)(32);
				}
				g_Console.writeToBuffer(combatdisplaycoord, display[i][j]);
				combatdisplaycoord.X++;
			}
			combatdisplaycoord.X = 0;
			combatdisplaycoord.Y++;
		}

		buttonfiller = buttonsdisplay(buttonfiller);

		combatdisplaycoord.X = 53;
		combatdisplaycoord.Y = 5;

		for (int i = 0; i < 24; ++i)
		{
			for (int j = 0; j < 63; ++j)
			{
				if (buttonfiller[i][j] == '-')
				{
					buttonfiller[i][j] = (char)(32);
				}
				g_Console.writeToBuffer(combatdisplaycoord, buttonfiller[i][j]);
				combatdisplaycoord.X++;
			}
			combatdisplaycoord.X = 53;
			combatdisplaycoord.Y++;
			g_isUpdated = false;
		}

		textboxfiller = textboxdisplay(textboxfiller);

		combatdisplaycoord.X = 0;
		combatdisplaycoord.Y = 30;

		for (int i = 0; i < 11; ++i)
		{
			for (int j = 0; j < 117; ++j)
			{
				if (textboxfiller[i][j] == '-')
				{
					textboxfiller[i][j] = (char)(32);
				}
				g_Console.writeToBuffer(combatdisplaycoord, textboxfiller[i][j]);
				combatdisplaycoord.X++;
			}
			combatdisplaycoord.X = 0;
			combatdisplaycoord.Y++;
		}

		player1.display(combatdisplaycoord);
	}

	//-----Choosing Enemy For Combat-----//
	char** enemyselector(char** dp, int enemyno)
	{
		int monsterHeight = 24;
		int monsterLength = 53;
		ifstream monster;

		if (enemyno == 0)
			monster.open("Combat/Goat1.txt");
		else if (enemyno == 1)
			monster.open("Combat/Spider.txt");

		if (monster.is_open())
		{
			for (int i = 0; i < monsterHeight; i++)
			{
				dp[i] = new char[monsterLength];

				for (int j = 0; j < monsterLength; j++)
				{
					monster >> dp[i][j];
				}
			}
			monster.close();
		}
		return dp;
	}

	//-----Rendering The Buttons-----//
	char** buttonsdisplay(char** buttonfill)
	{
		int buttonHeight = 24;
		int buttonLength = 63;

		if (isKeyPressed(VK_UP))
		{
			isUpPressed = true;
			g_isUpdated = false;
		}
		else if (isKeyPressed(VK_DOWN))
		{
			isUpPressed = false;
			g_isUpdated = false;
		}
		
		ifstream  buttons;

		if (isUpPressed == true)
		{
			buttons.open("Combat/Attack_Defend_Buttons_if_Att.txt");
			g_isUpdated = false;
		}
		else if (isUpPressed == false)
		{
			buttons.open("Combat/Attack_Defend_Buttons_if_Def.txt");
			g_isUpdated = false;
		}

		if (buttons.is_open())
		{
			for (int i = 0; i < buttonHeight; i++)
			{
				buttonfill[i] = new char[buttonLength];

				for (int j = 0; j < buttonLength; j++)
				{
					buttons >> buttonfill[i][j];
				}
			}
			buttons.close();
		}
		return buttonfill;
	}

	//-----Displaying Textbox-----//
	char** textboxdisplay(char** textboxfill)
	{
		int textboxHeight = 11;
		int textboxLength = 117;

		ifstream textbox;

		textbox.open("Textbox.txt");

		if (textbox.is_open())
		{
			for (int i = 0; i < textboxHeight; i++)
			{
				textboxfill[i] = new char[textboxLength];

				for (int j = 0; j < textboxLength; j++)
				{
					textbox >> textboxfill[i][j];
				}
			}
			textbox.close();
		}
		return textboxfill;
	}

//-------Initalization of All Characters/Enemies-------//

	//-----Initalizing for all enemies from Init-----//
	void enemyinit()
	{
		int i = 0;
		int att = 0;
		int max = 0;

		for (i = 0; i <= 7;)
		{
			if (i == 0) //For First Boss
			{
				att = 1;
				max = 1;
				i++;
				enemy1.init(att, max);
			}
			else if (i == 1) //For Second Boss
			{
				att = 30;
				max = 50;
				i++;
				enemy2.init(att, max);
			}
			else if (i == 2) //For Third Boss
			{
				att = 75;
				max = 90;
				i++;
				enemy3.init(att, max);
			}
			else if (i == 3) //For Fourth Boss
			{
				att = 100;
				max = 125;
				i++;
				enemy4.init(att, max);
			}
			else if (i == 4) //For Fifth Boss
			{
				att = 1000;
				max = 1000;
				i++;
				enemy5.init(att, max);
			}
			else if (i == 5) //For Sixth Boss
			{
				att = 250;
				max = 450;
				enemy6.init(att, max);
				i++;
			}
			else //For Normal AI
			{
				att = 10;
				max = 120;
				enemynonboss.init(att, max);
				i++;
			}
		}
	} 

	//-----Initilasing Player Stats-----//
	void playerinit()
	{
		int Health = 100;
		int Attack = 10;
		int Defence = 10;

		player1.playerBase(Health, Attack, Defence);
	}

/*/
-End of Main Function-
/*/

/*/
-Functions from Enemies Class-
/*/

//---Initialisation---//
void Enemy::init(int baseatt, int maxatt)
{
	boss1.Attack = setAttack(baseatt, maxatt);
	boss1.Defence = setDefence();
	boss1.MaxHealth = setHealth();
	boss1.Health = boss1.MaxHealth;
}

//---Getting Random Attack Stat---//
int Enemy::setAttack(int base, int maxatt)
{
	srand(time(NULL));
	int basedmg;
	for (basedmg = base; basedmg >= maxatt;)
	{
		basedmg = rand() % maxatt;
	}
	maxatt = rand() % 10;
	if (maxatt < 1)
	{
		maxatt = 1;
	}
	maxatt += basedmg;
	boss1.MaxAttack = maxatt;
	int min = rand() % 10;
	min = basedmg - min;
	if (min <= 0)
	{
		min = 1;
	}
	boss1.MinAttack = min;
	boss1.Attack = rand() % maxatt + min;
	return boss1.Attack;
}

//---Formula for Defence Stat---//
int Enemy::setDefence()
{
	boss1.Defence = (boss1.Attack * 4) / 3;
	return boss1.Defence;
}

//---Formula for Health Stat---//
int Enemy::setHealth()
{
	boss1.Health = boss1.Defence * 3;
	boss1.MaxHealth = boss1.Health;
	return boss1.MaxHealth;
}

//---Display Update---//
void Enemy::display(COORD a, int i, int i1, int i2, int i3)
{
	double oneUnit = i1 / 115.0f;
	int counthash = i / oneUnit;

	string Attack = static_cast<ostringstream*>(&(ostringstream() << i2))->str();
	string Defence = static_cast<ostringstream*>(&(ostringstream() << i3))->str();

	a.X = 0;
	a.Y = 1;
	g_Console.writeToBuffer(a, "Boss Health:");

	a.Y++;
	for (a.X = 0; a.X <= 117; a.X++)
	{
		if (a.X == 0)
		{
			g_Console.writeToBuffer(a, "[");
		}

		else if (a.X <= counthash + 2)
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
	g_Console.writeToBuffer(a, Attack);
	a.X = 0;
	a.Y++;
	g_Console.writeToBuffer(a, "Boss Defence: ");
	a.X += 14;
	g_Console.writeToBuffer(a, Defence);
}

//---Calling for the attack---//
int Enemy::getAttack(int max, int min)
{
	boss1.Attack = rand() % max + min;
	return boss1.Attack;
}

//---Update of Health Stat after getting hit---//
void Enemy::healthUpdate(int damageDone)
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

/*/
-End of Enemies Class-
/*/


/*/
-Functions from Player Class-
/*/

//---Setting Player Stats---//
void Player::playerBase(int health, int attack, int defence)
{
	character.Health = health;
	character.MaxHealth = health;
	character.Attack = attack;
	character.Defence = defence;
}

//---Display Update---//
void Player::display(COORD a)
{
	unsigned int number_of_digits = 0;
	int tempHealth = character.Health;
	
	string Health = static_cast<ostringstream*>(&(ostringstream() << character.Health))->str();
	string MaxHealth = static_cast<ostringstream*>(&(ostringstream() << character.MaxHealth))->str();
	string Attack = static_cast<ostringstream*>(&(ostringstream() << character.Attack))->str();
	string Defence = static_cast<ostringstream*>(&(ostringstream() << character.Defence))->str();

	for (tempHealth = character.Health; tempHealth >= 0; number_of_digits++)
	{
		tempHealth /= 10;
		if (tempHealth == 0)
		{
			number_of_digits++;
			break;
		}
	}

	a.X = 4;
	a.Y = 37;
	g_Console.writeToBuffer(a, "Player Health: ");
	a.X += 15;
	g_Console.writeToBuffer(a, Health);
	a.X += number_of_digits;
	g_Console.writeToBuffer(a, "/");
	a.X++;
	g_Console.writeToBuffer(a, MaxHealth);
	a.X += 10;
	g_Console.writeToBuffer(a, "Player Attack: ");
	a.X += 15;
	g_Console.writeToBuffer(a, Attack);
	a.X += 10;
	g_Console.writeToBuffer(a, "Player Defence: ");
	a.X += 16;
	g_Console.writeToBuffer(a, Defence);
}

//---Damage Done Calculation---//
int Player::damageDealt(int playerdamage, int enemydefence)
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
int Player::damageSustained(int enemyattack, int playerdefence)
{
	enemyattack = enemyattack - (playerdefence * (5 / 8));
	return enemyattack;
}

//---Update of Health Stat after getting hit---//
void Player::healthUpdate(int damageSustained)
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

/*/
-End of Player Class-
/*/