#include "combat.h"

//-----Extern Block-----//
extern Console g_Console;
extern CStopWatch g_Timer;
extern bool g_isUpdated;
extern bool g_isUpdated;
extern double g_dElapsedTime;
extern double g_dDeltaTime;
extern double g_dBounceTime;

//-----Struct for Enemy Picture-----//
struct enemypic
{
	char** kambengF1 = new char*[53];
	char** spider1 = new char*[53];
}enemypicture;

//-----Struct for Button Picture-----//
struct buttonpic
{
	char** AttackButton = new char*[63];
	char** DefendButton = new char*[63];
}buttonpicture;

//-----Structs for Textbox Picture-----//
struct textboxpic
{
	char** textbox = new char*[75];
	char** attackbox = new char*[75];
}textboxpicture;

//-----Struct for Names-----//
struct stringcompiled
{
	string names[6];
	string idleTexts;
	string updateTexts[6];
	string attacktext;
}stringz;

//-----Object and Identifier Declaration-----//
Player player1;
Enemy enemy1;
COORD combatdisplaycoord;
COORD characterspawn;
COORD holdcoord;
COORD a;
COORD lineoftext;
COMBAT combatgameplay;
ENEMYPIC displayno1;
BUTTONPIC displayno2;
TEXTBOXPIC displayno3;
WORD color = 0x0B;
char** display = new char*[53];
char** buttonfiller = new char*[63];
char** textboxfiller = new char*[75];
char** textforline = new char*[40];
int enemySelector = 0;
int victory = 2;
int BossesDefeated = 0;
int counter;
int holddamage;
int damagetaken;
double thisisatime ;
double thisisatime2;
double thisisatimeforspace;
double waittime;
bool isUpPressed = true;
bool isEnemyAttActive = false;
bool whenSpacePressed = false;
bool charmoved = false;
bool textboxprinted = false;
bool updatedtextprinted = true;
bool defended = false;

string projectile1 = "<=";
string projectile2 = "=>";
string projectile[20];
COORD projectileCoord[20];
double ProjectileTime = 0;
int Xcoord[20];
int thisisacount;
int hold = 0;
int thisisatimeforprojectiles = 0;


/*/
-Functions from Main Combat File-
/*/

//--------Main Code Runs-------//

	//-----Main Combat File-----//
	void combat()
{
	switch (combatgameplay)
	{
	case COMBAT_GETINPUT:
		buttonsinput();
		break;
	case COMBAT_AFTINPUT:
		aftinput();
		break;
	case COMBAT_ATT:
		attackProcess();
		break;
	case COMBAT_ATT_PLAYER_TEXTUPDATE:
		attackProcess();
		break;
	case  COMBAT_ATT_ENEMYGAME:
		attackProcess();
		break;
	case COMBAT_ATT_UPDATEALLSTATS:
		attackProcess();
		break;
	case COMBAT_DEF:
		defendProcess();
		break;
	case COMBAT_DEF_ENEMYGAME:
		defendProcess();
		break;
	case COMBAT_DEF_UPDATEALLSTATS:
		defendProcess();
		break;
	case COMBAT_VICTORY:
		checkVictory();
		break;
	case COMBAT_RELOOP:
		combatreloop();
		break;
	default:
		break;
	}
}

	//-----Process of Attack-----//
	void attackProcess()	
	{
		if (combatgameplay == COMBAT_ATT)
		{
			characterspawn.X = 64;
			characterspawn.Y = 35;
			holddamage = player1.damageDealt(player1.character.Attack, enemy1.boss1.Defence);
			enemy1.healthUpdate(holddamage);
			waittime = g_dElapsedTime + 5;
			updatedtextprinted = false;
			combatgameplay = COMBAT_ATT_PLAYER_TEXTUPDATE;
			return;
		}
		else if (combatgameplay == COMBAT_ATT_PLAYER_TEXTUPDATE)
		{
			if (waittime > g_dElapsedTime) //use in display and for diff states
			{
				return;
			}
			if (enemy1.boss1.Health == 0)
			{
				updatedtextprinted = true;
				combatgameplay = COMBAT_ATT_UPDATEALLSTATS;
			}
			else if (g_dElapsedTime >= waittime)
			{
				updatedtextprinted = true;
				isEnemyAttActive = true;
				textboxprinted = false;
				holdtimer();
				enemy1.enemyattackgame();
				combatgameplay = COMBAT_ATT_ENEMYGAME;
			}
			return;
		}
		else if (combatgameplay == COMBAT_ATT_ENEMYGAME)
		{
			if (enemy1.boss1.Health != 0 && player1.character.Health != 0)
			{
				if ((projectileCoord[19].X == 73 && Xcoord[19] == 0) || (projectileCoord[19].X == 54 && Xcoord[19] == 1))
				{
					thisisacount = 0;
					enemy1.enemyattackgame();
				}
				enemy1.bullet();
				symbolMovement();
				checkdamage();
				if (g_dElapsedTime < thisisatime2)
				{
					return;
				}
				if (thisisatime2 <= g_dElapsedTime)
				{
					combatgameplay = COMBAT_ATT_UPDATEALLSTATS;
				}
			}
			else
			{
				combatgameplay = COMBAT_ATT_UPDATEALLSTATS;
				return;
			}
		}
		else if (combatgameplay == COMBAT_ATT_UPDATEALLSTATS)
		{
			thisisacount = 0;
			textboxprinted = false;
			int damage = enemy1.getAttack(enemy1.boss1.MaxAttack, enemy1.boss1.MinAttack);
			damagetaken = player1.damageSustained(damage, player1.character.Defence) * counter;
			player1.healthUpdate(hold);
			isEnemyAttActive = false;
			combatgameplay = COMBAT_VICTORY;
			return;
		}
	}

	//-----Process of Defend-----//
	void defendProcess()
	{
		if (combatgameplay == COMBAT_DEF)
		{
			characterspawn.X = 64;
			characterspawn.Y = 35;
			isEnemyAttActive = true;
			holdtimer();
			textboxprinted = false;
			combatgameplay = COMBAT_DEF_ENEMYGAME;
			return;
		}
		else if (combatgameplay == COMBAT_DEF_ENEMYGAME)
		{
			if ((projectileCoord[19].X == 73 && Xcoord[19] == 0) || (projectileCoord[19].X == 54 && Xcoord[19] == 1))
			{
				thisisacount = 0;
				enemy1.enemyattackgame();
			}
			enemy1.bullet();
			symbolMovement();
			checkdamage();
			if (g_dElapsedTime < thisisatime2)
			{
				return;
			}
			if (g_dElapsedTime >= thisisatime2)
			{
				combatgameplay = COMBAT_DEF_UPDATEALLSTATS;
			}
		}
		else if (combatgameplay == COMBAT_DEF_UPDATEALLSTATS)
		{
			int damage = enemy1.getAttack(enemy1.boss1.MaxAttack, enemy1.boss1.MinAttack);
			int hold = player1.damageSustained(damage, player1.character.Defence) * counter;
			player1.healthUpdate(hold);
			isEnemyAttActive = false;
			counter = 0;
			defended = true;
			updatedtextprinted == false;
			combatgameplay = COMBAT_VICTORY;
		}
	}

	//-----Checking for Victory-----//
	int checkVictory()
	{
		counter = 0;

		if (enemy1.boss1.Health == 0) //Win
		{
			combatgameplay = COMBAT_RELOOP;
			return 1;
		}
		else if (player1.character.Health == 0) //Lose
		{
			combatgameplay = COMBAT_RELOOP;
			return 0;
		}
		else //Continue
		{
			combatgameplay = COMBAT_GETINPUT;
			return 2;
		}
	}

	//-----Adding a timer-----//
	void holdtimer()
	{
		thisisatime2 = g_dElapsedTime + 5;
	}

	//-----Input Get-----//
	void buttonsinput()
	{
		if (isKeyPressed(VK_UP))
		{
			isUpPressed = true;
			displayno2 = BUTTONPIC_ATTBUTTON;
		}
		else if (isKeyPressed(VK_DOWN))
		{
			isUpPressed = false;
			displayno2 = BUTTONPIC_DEFBUTTON;
		}
		if (isKeyPressed(VK_SPACE))
		{
			combatgameplay = COMBAT_AFTINPUT;
		}
		return;
	}

	//-----After Input Is Recieved-----//
	void aftinput()
	{
		if (thisisatimeforspace > g_dElapsedTime)
			return;

		if (isKeyPressed(VK_SPACE))
		{
			whenSpacePressed = true;
			if (whenSpacePressed == true)
			{
				thisisatime = g_dElapsedTime;
			}

			if (victory == 2)
			{
				if (isUpPressed == true) //Attack
				{
					combatgameplay = COMBAT_ATT;
				}
				else //Defend
				{
					combatgameplay = COMBAT_DEF;
				}
			}
		}
	}

	//-----Restarting the Combat-----//
	void combatreloop()
	{
		if (victory == 0)
		{
			if (isKeyPressed(VK_SPACE))
			{
				enemySelector = 0;
			}
		}
		else if (victory == 1)
		{
			if (isKeyPressed(VK_SPACE))
			{
				enemySelector += 1;
				enemyinit(enemySelector);
				victory = 2;
				BossesDefeated++;
				player1.statsUpdate(BossesDefeated);
				thisisatimeforspace = g_dElapsedTime + 2;
			}
		}
		whenSpacePressed = false;
		combatgameplay = COMBAT_GETINPUT;
	}

	//---Moving The Character---//
	void symbolMovement()
	{
		bool bSomethingHappened = false;
		holdcoord.Y = characterspawn.Y;
		holdcoord.X = characterspawn.X;
		if (thisisatime > g_dElapsedTime)
			return;

		if (isKeyPressed(VK_UP))
		{
			characterspawn.Y--;
			if (characterspawn.Y <= 30)
			{
				characterspawn.Y = holdcoord.Y;
			}
			else
			{
				bSomethingHappened = true;
			}
		}
		else if (isKeyPressed(VK_LEFT))
		{
			characterspawn.X--;
			if (characterspawn.X <= 54)
			{
				characterspawn.X = holdcoord.X;
			}
			else
			{
				bSomethingHappened = true;
			}
		}
		else if (isKeyPressed(VK_DOWN))
		{
			characterspawn.Y++;
			if (characterspawn.Y >= 39 || characterspawn.Y >= 40)
			{
				characterspawn.Y = holdcoord.Y;
			}
			else
			{
				bSomethingHappened = true;
			}
		}
		else if (isKeyPressed(VK_RIGHT))
		{
			characterspawn.X++;
			if (characterspawn.X >= 73)
			{
				characterspawn.X = holdcoord.X;
			}
			else
			{
				bSomethingHappened = true;
			}
		}

		if (bSomethingHappened)
		{
			// set the bounce time to some time in the future to prevent accidental triggers
			thisisatime = g_dElapsedTime + 0.15; // 125ms should be enough
		}
	}

	//---Checking Damage from  the Enemy---//
	void checkdamage()
	{
		for (int i = 0; i < 20; i++)
		{
			if (characterspawn.X == projectileCoord[i].X && characterspawn.Y == projectileCoord[i].Y)
			{
				counter++;
			}
		}
	}

//-------Combat Render-------//

	//-----Combat Render-----//
	void combatdisplay()
	{
		WORD color = 0x0B;
		g_isUpdated = false;
		enemy1.display(combatdisplaycoord, enemy1.boss1.Health, enemy1.boss1.MaxHealth, enemy1.boss1.Attack, enemy1.boss1.Defence);

		enemyrender();

		buttonrender();

		textboxrender();

		if (isEnemyAttActive == false)
		{
			player1.display(combatdisplaycoord);
		}
		else
		{
			renderCharacterSymbol(characterspawn);
			printprojectiles(thisisacount);
		}
		if (updatedtextprinted == false)
		{
			printinglinesoftext(enemySelector);
		}
	}

	//-----Enemy Render-----//
	void enemyrender()
	{
		WORD color = 0x0B;
		combatdisplaycoord.X = 0;
		combatdisplaycoord.Y = 5;

		switch (displayno1)
		{
		case ENEMYPIC_KAMBENGF1:
			display = enemypicture.kambengF1;
			break;

		case ENEMYPIC_SPIDER1:
			display = enemypicture.spider1;
			break;

		default:
			break;
		}

		for (int i = 0; i < 24; ++i)
		{
			for (int j = 0; j < 53; ++j)
			{
				if (display[i][j] == '-')
				{
					display[i][j] = (char)(32);
				}
				g_Console.writeToBuffer(combatdisplaycoord, display[i][j], color);
				combatdisplaycoord.X++;
			}
			combatdisplaycoord.X = 0;
			combatdisplaycoord.Y++;
		}
	}

	//-----Buttons Render-----//
	void buttonrender()
	{
		WORD color = 0x0B;
		combatdisplaycoord.X = 53;
		combatdisplaycoord.Y = 5;

		switch (displayno2)
		{
		case BUTTONPIC_ATTBUTTON:
			buttonfiller = buttonpicture.AttackButton;
			break;

		case BUTTONPIC_DEFBUTTON:
			buttonfiller = buttonpicture.DefendButton;
			break;

		default:
			break;
		}

		for (int i = 0; i < 24; ++i)
		{
			for (int j = 0; j < 63; ++j)
			{
				if (buttonfiller[i][j] == '-')
				{
					buttonfiller[i][j] = (char)(32);
				}
				g_Console.writeToBuffer(combatdisplaycoord, buttonfiller[i][j], color);
				combatdisplaycoord.X++;
			}
			combatdisplaycoord.X = 53;
			combatdisplaycoord.Y++;
		}
	}

	//-----Printing the Update Text-----//
	void printinglinesoftext(int name)
	{
		unsigned int number_of_digits = 0;
		int temp;
		lineoftext.X = 4;
		lineoftext.Y = 32;

		if (combatgameplay == COMBAT_ATT_PLAYER_TEXTUPDATE || combatgameplay == COMBAT_DEF_UPDATEALLSTATS)
		{
			string Damage = static_cast<ostringstream*>(&(ostringstream() << holddamage))->str();

			for (temp = holddamage; temp >= 0; number_of_digits++)
			{
				temp /= 10;
				if (temp == 0)
				{
					number_of_digits++;
					break;
				}
			}

			g_Console.writeToBuffer(lineoftext, stringz.updateTexts[0]);

			lineoftext.X += 10;
			g_Console.writeToBuffer(lineoftext, Damage);

			lineoftext.X += number_of_digits;
			g_Console.writeToBuffer(lineoftext, ' ');

			lineoftext.X += 1;
			g_Console.writeToBuffer(lineoftext, stringz.updateTexts[1]);

			lineoftext.X += 10;
			g_Console.writeToBuffer(lineoftext, stringz.names[name]);

			lineoftext.X += stringz.names[name].length();
			g_Console.writeToBuffer(lineoftext, stringz.updateTexts[2]);
		}
		else if (combatgameplay == COMBAT_ATT_UPDATEALLSTATS)
		{
			string noOfTimesHit = static_cast<ostringstream*>(&(ostringstream() << counter))->str();
			string damagetook = static_cast<ostringstream*>(&(ostringstream() << damagetaken))->str();

			for (temp = counter; temp >= 0; number_of_digits++)
			{
				temp /= 10;
				if (temp == 0)
				{
					number_of_digits++;
					break;
				}
			}

			g_Console.writeToBuffer(lineoftext, stringz.updateTexts[3]);
			
			lineoftext.X += 8;
			g_Console.writeToBuffer(lineoftext, noOfTimesHit);

			lineoftext.X += number_of_digits;
			g_Console.writeToBuffer(lineoftext, stringz.updateTexts[2]);

			lineoftext.X = 4;
			lineoftext.Y++;
			g_Console.writeToBuffer(lineoftext, stringz.updateTexts[4]);

			for (temp = damagetaken; temp >= 0; number_of_digits++)
			{
				temp /= 10;
				if (temp == 0)
				{
					number_of_digits++;
					break;
				}
			}

			lineoftext.X += 9;
			g_Console.writeToBuffer(lineoftext, damagetook);

			lineoftext.X += number_of_digits;
			g_Console.writeToBuffer(lineoftext, stringz.updateTexts[5]);
		}
	}

	//-----Textbox Render-----//
	void textboxrender()
	{
		WORD color = 0x0B;
		combatdisplaycoord.X = 0;
		combatdisplaycoord.Y = 30;

		if (isEnemyAttActive == true)
		{
			displayno3 = TEXTBOXPIC_DEF;
		}
		else
		{
			displayno3 = TEXTBOXPIC_BASIC;
		}

		switch (displayno3)
		{
		case TEXTBOXPIC_BASIC:
			textboxfiller = textboxpicture.textbox;
			break;

		case TEXTBOXPIC_DEF:
			textboxfiller = textboxpicture.attackbox;
			break;

		default:
			break;
		}

		for (int i = 0; i < 11; ++i) //Edit this
		{
			for (int j = 0; j < 130; ++j)
			{
				if (textboxfiller[i][j] == '-')
				{
					textboxfiller[i][j] = (char)(32);
				}
				g_Console.writeToBuffer(combatdisplaycoord, textboxfiller[i][j], color);
				combatdisplaycoord.X++;
			}
			combatdisplaycoord.X = 0;
			combatdisplaycoord.Y++;
		}

		if (textboxprinted == false)
		{
			renderToScreen();
		}

		textboxprinted = true;
	}

	//---Spawning Character---//
	void renderCharacterSymbol(COORD a)
	{
		WORD charColor = 0x0A;
		if (a.X != characterspawn.X - 1 && a.Y != characterspawn.Y - 1 || a.X != characterspawn.X + 1 && a.Y != characterspawn.Y + 1)
		{
			g_Console.writeToBuffer(a, (char)32);
		}
		g_Console.writeToBuffer(characterspawn, (char)64, charColor);
		renderToScreen();
	}

	//---Spawning Projectiles---//
	void printprojectiles(int arraycounter)
	{
		for (int j = 0; j <= arraycounter; j++)
		{
			g_Console.writeToBuffer(projectileCoord[j], projectile[j], 0x03);
		}
	}

//-------Initalization of All Characters/Enemies-------//

	//-----Initalizing all Combat-----//
	void combatinit()
	{
		playerinit();
		displayinit();
		enemyinit(0);
	}

	//-----Initalizing for all enemies from Init-----//
	void enemyinit(int select)
	{
		int i = select;
		int att = 0;
		int max = 0;

		for (; i <= 7;)
		{
			if (i == 0) //For First Boss
			{
				att = 1;
				max = 1;
				i++;
				enemy1.init(att, max);
				enemy1.boss1.Defence = 50;
				displayno1 = ENEMYPIC_KAMBENGF1;
				break;
			}
			else if (i == 1) //For Second Boss
			{
				att = 30;
				max = 50;
				i++;
				enemy1.init(att, max);
				displayno1 = ENEMYPIC_SKELETON1;
				break;
			}
			else if (i == 2) //For Third Boss
			{
				att = 75;
				max = 90;
				i++;
				enemy1.init(att, max);
				displayno1 = ENEMYPIC_FISH1;
				break;
			}
			else if (i == 3) //For Fourth Boss
			{
				att = 100;
				max = 125;
				i++;
				enemy1.init(att, max);
				displayno1 = ENEMYPIC_SPIDER1;
				break;
			}
			else if (i == 4) //For Fifth Boss
			{
				att = 1000;
				max = 1000;
				i++;
				enemy1.init(att, max);
				displayno1 = ENEMYPIC_ROBOT1;
				break;
			}
			else if (i == 5) //For Sixth Boss
			{
				att = 250;
				max = 450;
				enemy1.init(att, max);
				i++;
				displayno1 = ENEMYPIC_KAMBENG1;
				break;
			}
			else //For Normal AI
			{
				att = 10;
				max = 120;
				enemy1.init(att, max);
				i++;
				break;
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

	//-----Writing into Double Array-----//
	void displayinit()
	{
		for (int i = 2; enemySelector < i; enemySelector++)
		{
			if (enemySelector == 0)
			{
				enemypicture.kambengF1 = enemyselector(enemypicture.kambengF1, enemySelector);
			}
			else if (enemySelector == 1)
			{
				enemypicture.spider1 = enemyselector(enemypicture.spider1, enemySelector);
			}
		}

		for (int i = 0; i < 2; i++)
		{
			if (i == 0)
			{
				buttonpicture.AttackButton = buttonsdisplay(buttonpicture.AttackButton, i);
			}
			else if (i == 1)
			{
				buttonpicture.DefendButton = buttonsdisplay(buttonpicture.DefendButton, i);
			}
		}

		for (int i = 0; i < 2; i++)
		{
			if (i == 0)
			{
				textboxpicture.textbox = textboxdisplay(textboxpicture.textbox, i);
			}
			else if (i == 1)
			{
				textboxpicture.attackbox = textboxdisplay(textboxpicture.attackbox, i);
			}
		}

		for (int i = 0; i < 6; i++)
		{
			stringz.names[i] = namefilling(i);
			stringz.updateTexts[i] = updatetext(i);
		}
	}

	//-----Writing Enemy-----//
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

	//-----Writing Buttons-----//
	char** buttonsdisplay(char** buttonfill,int printno)
	{
		int buttonHeight = 24;
		int buttonLength = 63;

		ifstream  buttons;

		if (printno == 0)
		{
			buttons.open("Combat/Attack_Defend_Buttons_if_Att.txt");
			g_isUpdated = false;
		}
		else if (printno == 1)
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

	//-----Writing Textbox-----//
	char** textboxdisplay(char** textboxfill,int read)
	{
		int Height;
		int Length;

		ifstream textbox;

		if (read == 0)
		{
			textbox.open("Textbox.txt");
			Height = 11;
			Length = 130;
		}
		else
		{
			textbox.open("Combat/AttackBox.txt");
			Height = 11;
			Length = 130;
		}

		if (textbox.is_open())
		{
			for (int i = 0; i < Height; i++)
			{
				textboxfill[i] = new char[Length];

				for (int j = 0; j < Length; j++)
				{
					textbox >> textboxfill[i][j];
				}
			}
			textbox.close();
		}
		return textboxfill;
	}

	//-----Writing Text-----//
	string updatetext(int number)
	{
		string hold;
		ifstream textlines;
		textlines.open("Combat/CombatUpdateText.txt");

		if (textlines.is_open())
		{
			if (number == 0)
			{
				getline(textlines, hold);
				return hold;
			}
			else if (number == 1)
			{
				getline(textlines, hold);
				getline(textlines, hold);
				return hold;
			}
			else if (number == 2)
			{
				getline(textlines, hold);
				getline(textlines, hold);
				getline(textlines, hold);
				return hold;
			}
			else if (number == 3)
			{
				getline(textlines, hold);
				getline(textlines, hold);
				getline(textlines, hold);
				getline(textlines, hold);
				return hold;
			}
			else if (number == 4)
			{
				getline(textlines, hold);
				getline(textlines, hold);
				getline(textlines, hold);
				getline(textlines, hold);
				getline(textlines, hold);
				return hold;
			}
			else if (number == 5)
			{
				getline(textlines, hold);
				getline(textlines, hold);
				getline(textlines, hold);
				getline(textlines, hold);
				getline(textlines, hold);
				return hold;
			}
		}
	}

	//-----Writing Names-----//
	string namefilling(int no)
	{
		string hold;
		ifstream name;
		name.open("Combat/Names.txt");

		if (name.is_open())
		{
			if (no == 0)
			{
				getline(name, hold);
				return hold;
			}
			else if (no == 1)
			{
				getline(name, hold);
				return hold;
			}
			else if (no == 2)
			{
				getline(name, hold);
				return hold;
			}
			else if (no == 3)
			{
				getline(name, hold);
				return hold;
			}
			else if (no == 4)
			{
				getline(name, hold);
				return hold;
			}
			else if (no == 5)
			{
				getline(name, hold);
				return hold;
			}
		}
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

		else if (a.X <= counthash)
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
	renderToScreen();
}

//---Calling for the attack---//
int Enemy::getAttack(int max, int min)
{
	int dmg;
	dmg = rand() % max + min;
	return dmg;
}

//---Update of Health Stat after getting hit---//
void Enemy::healthUpdate(int damageDone)
{
	if (damageDone >= boss1.Health)
	{
		boss1.Health = 0;
	}
	else
	{
		boss1.Health -= damageDone;
	}
}

//---Boss Attack/Defend MiniGame---//
void Enemy::enemyattackgame()
{
	srand(time(NULL));
	for (int i = 0; i <= 19; i++)
	{
		Xcoord[i] = rand() % 2; //Randomize left or right

		if (Xcoord[i] == 0) //Setting projectile type and which directions
		{
			projectileCoord[i].X = 54;
			projectile[i] = projectile2;
		}
		else
		{
			projectileCoord[i].X = 72;
			projectile[i] = projectile1;
		}

		int Ycoord = (rand() % 7) + 31; //Randomize which row it spawns
		projectileCoord[i].Y = Ycoord;
	}
}

//---Update the Projectiles---//
void  Enemy::bullet()
{
	if (thisisatimeforprojectiles > g_dElapsedTime)
	{
		return;
	}
	if (thisisacount <= 19)
	{
		thisisacount++;
	}
	for (int i = 0; i < thisisacount * 2; i++)
	{
		if (Xcoord[i] == 0)
		{
			if (projectileCoord[i].X == 73)
			{
				projectile[i].erase();
				projectileCoord[i].X = 0;
				projectileCoord[i].Y = 0;
				continue;
			}
			else if (thisisacount % 2 == 1)
			{
				continue;
			}
			else
			{
				projectileCoord[i].X++;
			}
		}
		else
		{
			if (projectileCoord[i].X == 54)
			{
				projectile[i].erase();
				projectileCoord[i].X = 0;
				projectileCoord[i].Y = 0;
				continue;
			}
			else if (thisisacount % 2 == 1)
			{
				continue;
			}
			else
			{
				projectileCoord[i].X--;
			}
		}
	}
	thisisatimeforprojectiles = g_dElapsedTime + 0.5;
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

	if (defended == true)
	{
		playerdamage = (playerdamage * 3) / 2;
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

//---Update of all Stats---//
void Player::statsUpdate(int killcount)
{
	for (int i = 0; i <= killcount; i++)
	{
		character.Health *= 1.5f;
		character.MaxHealth *= 1.5f;
		character.Attack = (character.Attack + 10) * 1.2f;
		character.Defence = (character.Defence + 25) * 1.3f;
	}
}

/*/
-End of Player Class-
/*/