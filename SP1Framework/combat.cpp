#include "combat.h"

//-----Extern Block-----//
extern Console g_Console;
extern EGAMESTATES g_eGameState;
extern CStopWatch g_Timer;
extern bool ;
extern double g_dElapsedTime;
extern double g_dDeltaTime;
extern double g_dBounceTime;
extern bool g_Level;
extern int g_CurrentLevel;
extern int g_CreativeLevel;

//-----Struct for Enemy Picture-----//
struct enemypic
{
	char** kambengF1 = new char*[53];
	char** kambengF2 = new char*[53];
	char** skeleton1 = new char*[53];
	char** skeleton2 = new char*[53];
	char** Fish1 = new char*[53];
	char** Fish2 = new char*[53];
	char** spider1 = new char*[53];
	char** spider2 = new char*[53];
	char** robot1 = new char*[53];
	char** robot2 = new char*[53];
	char** KAMBENG1 = new char*[53];
	char** KAMBENG2 = new char*[53];
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
	string attacktext[12];
	string kambengProj[2];
	string skeletonProj[3];
	string fishProj[8];
	string spiderProj[5];
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
int arraymax;
double thisisatime;
double thisisatime2;
double thisisatimeforspace;
double waittime;
double thisisatimeforanimation = g_dElapsedTime + 0.5;
double damagecheck = g_dElapsedTime + 0.2;
bool isUpPressed = true;
bool isEnemyAttActive = false;
bool charmoved = false;
bool textboxprinted = false;
bool updatedtextprinted = true;
bool defended = false;
bool animate = false;
bool projectiles = false;

string projectile[20];
COORD projectileCoord[20];
int Xcoord[20];
int thisisacount;
int hold = 0;
double thisisatimeforprojectiles = 0;

string SkeletonProjectile[6];
COORD SkeletonProjectileCoord[6];
string FishProjectile[8];
COORD FishProjectileCoord[8];
string SpiderProjectile[5];
COORD SpiderProjectilCoord[5];
COORD RobotSafeSpot[10];
char RobotElectric[9][18];


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
			waittime = g_dElapsedTime + 2.5;
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
				if (enemySelector == 0 && ((projectileCoord[19].X == 73 && Xcoord[19] == 0) || (projectileCoord[19].X == 54 && Xcoord[19] == 1)))
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
					thisisacount = 0;
					textboxprinted = false;
					updatedtextprinted = false;
					waittime = g_dElapsedTime + 2.5;
					int damage = enemy1.getAttack(enemy1.boss1.MaxAttack, enemy1.boss1.MinAttack);
					damagetaken = player1.damageSustained(damage, player1.character.Defence) * counter;
					player1.healthUpdate(damagetaken);
					combatgameplay = COMBAT_ATT_UPDATEALLSTATS;
				}
			}
		}
		else if (combatgameplay == COMBAT_ATT_UPDATEALLSTATS)
		{
			isEnemyAttActive = false;
			if (waittime > g_dElapsedTime) //use in display and for diff states
			{
				return;
			}
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
			enemy1.enemyattackgame();
			combatgameplay = COMBAT_DEF_ENEMYGAME;
			return;
		}
		else if (combatgameplay == COMBAT_DEF_ENEMYGAME)
		{
			if (enemySelector == 0 && ((projectileCoord[19].X == 73 && Xcoord[19] == 0) || (projectileCoord[19].X == 54 && Xcoord[19] == 1)))
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
				waittime = g_dElapsedTime + 2.5;
				thisisacount = 0;
				int damage = enemy1.getAttack(enemy1.boss1.MaxAttack, enemy1.boss1.MinAttack);
				int hold = player1.damageSustained(damage, player1.character.Defence) * counter;
				player1.healthUpdate(hold);
				isEnemyAttActive = false;
				counter = 0;
				defended = true;
				updatedtextprinted = false;
				combatgameplay = COMBAT_DEF_UPDATEALLSTATS;
			}
		}
		else if (combatgameplay == COMBAT_DEF_UPDATEALLSTATS)
		{
			arrayclear();
			if (waittime > g_dElapsedTime) //use in display and for diff states
			{
				return;
			}
			combatgameplay = COMBAT_VICTORY;
		}
	}

	//-----Checking for Victory-----//
	int checkVictory()
 	{
		counter = 0;

		if (enemy1.boss1.Health == 0) //Win
		{
			arrayclear();
			combatgameplay = COMBAT_RELOOP;
			victory = 1;
			return 1;
		}
		else if (player1.character.Health == 0) //Lose
		{
			arrayclear();
			combatgameplay = COMBAT_RELOOP;
			enemy1.boss1.Health = enemy1.boss1.MaxHealth;
			victory = 0;
			return 0;
		}
		else //Continue
		{
			arrayclear();
			combatgameplay = COMBAT_GETINPUT;
			victory = 2;
			return 2;
		}
	}

	//-----Adding a timer-----//
	void holdtimer()
	{
		thisisatime2 = g_dElapsedTime + 15;
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
		if (isKeyPressed(VK_SPACE))
		{
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
			playerinit();
			enemySelector = 0;
			combatgameplay = COMBAT_GETINPUT;
			g_eGameState = S_MENU;
			if (g_Level == true)
			{
				
			}
			else if (g_Level == false)
			{
				g_eGameState = S_LOADCREATIVE;
			}
		}
		else if (victory == 1)
		{
			enemySelector += 1;
			enemyinit(enemySelector);
			victory = 2;
			BossesDefeated++;
			player1.statsUpdate(BossesDefeated);
			thisisatimeforspace = g_dElapsedTime + 2;
			if (g_Level == true)
			{
				g_eGameState = S_LOADGAME;
			}
			else if (g_Level == false)
			{
				g_eGameState = S_LOADCREATIVE;
			}
		}
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
		int check;
		if (damagecheck > g_dElapsedTime)
		{
			return;
		}

		switch (displayno1)
		{
		case ENEMYPIC_KAMBENGF1:
			for (int i = 0; i < 20; i++)
			{
				if (characterspawn.X == projectileCoord[i].X && characterspawn.Y == projectileCoord[i].Y)
				{
					damagecheck = g_dElapsedTime + 0.25;
					counter++;
				}
			}
			break;

		case ENEMYPIC_KAMBENGF2:
			for (int i = 0; i < 20; i++)
			{
				if (characterspawn.X == projectileCoord[i].X && characterspawn.Y == projectileCoord[i].Y)
				{
					damagecheck = g_dElapsedTime + 0.25;
					counter++;
				}
			}
			break;

		case ENEMYPIC_SKELETON1:
			check = 0;
			for (int i = 0; i < 2; i++)
			{
				if (Xcoord[check] == 0)
				{
					if ((characterspawn.X >= SkeletonProjectileCoord[i + 1].X && characterspawn.Y >= SkeletonProjectileCoord[i + 1].Y) || (characterspawn.X <= SkeletonProjectileCoord[i + 1].X + 13 && characterspawn.Y <= SkeletonProjectileCoord[i + 1].Y))
					{
						damagecheck = g_dElapsedTime + 2.5;
						counter++;
					}
					else if ((characterspawn.X == SkeletonProjectileCoord[i + 2].X && characterspawn.Y >= SkeletonProjectileCoord[i + 2].Y) || (characterspawn.X <= SkeletonProjectileCoord[i + 2].X + 13 && characterspawn.Y <= SkeletonProjectileCoord[i + 2].Y))
					{
						damagecheck = g_dElapsedTime + 2.5;
						counter++;
					}

				}
				else if (Xcoord[check] == 1)
				{
					if ((characterspawn.X >= SkeletonProjectileCoord[i + 1].X && characterspawn.Y >= SkeletonProjectileCoord[i + 1].Y) || (characterspawn.X <= SkeletonProjectileCoord[i + 1].X + 13 && characterspawn.Y <= SkeletonProjectileCoord[i + 1].Y))
					{
						damagecheck = g_dElapsedTime + 2.5;
						counter++;
					}
					else if ((characterspawn.X == SkeletonProjectileCoord[i + 2].X && characterspawn.Y >= SkeletonProjectileCoord[i + 2].Y) || (characterspawn.X <= SkeletonProjectileCoord[i + 2].X + 13 && characterspawn.Y <= SkeletonProjectileCoord[i + 2].Y))
					{
						damagecheck = g_dElapsedTime + 2.5;
						counter++;
					}
				}

				check += 3;
			}
			break;

		case ENEMYPIC_SKELETON2:
			check = 0;
			for (int i = 0; i < 2; i++)
			{
				if (Xcoord[check] == 0)
				{
					if ((characterspawn.X >= SkeletonProjectileCoord[i + 1].X && characterspawn.Y >= SkeletonProjectileCoord[i + 1].Y) || (characterspawn.X <= SkeletonProjectileCoord[i + 1].X + 13 && characterspawn.Y <= SkeletonProjectileCoord[i + 1].Y))
					{
						damagecheck = g_dElapsedTime + 2.5;
						counter++;
					}
					else if ((characterspawn.X == SkeletonProjectileCoord[i + 2].X && characterspawn.Y >= SkeletonProjectileCoord[i + 2].Y) || (characterspawn.X <= SkeletonProjectileCoord[i + 2].X + 13 && characterspawn.Y <= SkeletonProjectileCoord[i + 2].Y))
					{
						damagecheck = g_dElapsedTime + 2.5;
						counter++;
					}

				}
				else if (Xcoord[check] == 1)
				{
					if ((characterspawn.X >= SkeletonProjectileCoord[i + 1].X && characterspawn.Y >= SkeletonProjectileCoord[i + 1].Y) || (characterspawn.X <= SkeletonProjectileCoord[i + 1].X + 13 && characterspawn.Y <= SkeletonProjectileCoord[i + 1].Y))
					{
						damagecheck = g_dElapsedTime + 2.5;
						counter++;
					}
					else if ((characterspawn.X == SkeletonProjectileCoord[i + 2].X && characterspawn.Y >= SkeletonProjectileCoord[i + 2].Y) || (characterspawn.X <= SkeletonProjectileCoord[i + 2].X + 13 && characterspawn.Y <= SkeletonProjectileCoord[i + 2].Y))
					{
						damagecheck = g_dElapsedTime + 2.5;
						counter++;
					}
				}

				check += 3;
			}
			break;

		case ENEMYPIC_FISH1:
			check = 0;
			for (int i = 0; i < 2; i++)
			{
				if (Xcoord[check] == 0)
				{
					if ((characterspawn.X >= FishProjectileCoord[i + 1].X && characterspawn.Y >= FishProjectileCoord[i + 1].Y) || (characterspawn.X <= FishProjectileCoord[i + 1].X + 3 && characterspawn.Y <= FishProjectileCoord[i + 1].Y))
					{
						damagecheck = g_dElapsedTime + 5;
						counter++;
					}
					else if ((characterspawn.X == FishProjectileCoord[i + 2].X && characterspawn.Y >= FishProjectileCoord[i + 2].Y) || (characterspawn.X <= FishProjectileCoord[i + 2].X + 3 && characterspawn.Y <= FishProjectileCoord[i + 2].Y))
					{
						damagecheck = g_dElapsedTime + 5;
						counter++;
					}

				}
				else if (Xcoord[check] == 1)
				{
					if ((characterspawn.X >= FishProjectileCoord[i + 1].X && characterspawn.Y >= FishProjectileCoord[i + 1].Y) || (characterspawn.X <= FishProjectileCoord[i + 1].X + 3 && characterspawn.Y <= FishProjectileCoord[i + 1].Y))
					{
						damagecheck = g_dElapsedTime + 5;
						counter++;
					}
					else if ((characterspawn.X == FishProjectileCoord[i + 2].X && characterspawn.Y >= FishProjectileCoord[i + 2].Y) || (characterspawn.X <= FishProjectileCoord[i + 2].X + 3 && characterspawn.Y <= FishProjectileCoord[i + 2].Y))
					{
						damagecheck = g_dElapsedTime + 5;
						counter++;
					}
				}

				check += 4;
			}
			break;

		case ENEMYPIC_FISH2:
			check = 0;
			for (int i = 0; i < 2; i++)
			{
				if (Xcoord[check] == 0)
				{
					if ((characterspawn.X >= FishProjectileCoord[i + 1].X && characterspawn.Y >= FishProjectileCoord[i + 1].Y) || (characterspawn.X <= FishProjectileCoord[i + 1].X + 3 && characterspawn.Y <= FishProjectileCoord[i + 1].Y))
					{
						damagecheck = g_dElapsedTime + 5;
						counter++;
					}
					else if ((characterspawn.X == FishProjectileCoord[i + 2].X && characterspawn.Y >= FishProjectileCoord[i + 2].Y) || (characterspawn.X <= FishProjectileCoord[i + 2].X + 3 && characterspawn.Y <= FishProjectileCoord[i + 2].Y))
					{
						damagecheck = g_dElapsedTime + 5;
						counter++;
					}

				}
				else if (Xcoord[check] == 1)
				{
					if ((characterspawn.X >= FishProjectileCoord[i + 1].X && characterspawn.Y >= FishProjectileCoord[i + 1].Y) || (characterspawn.X <= FishProjectileCoord[i + 1].X + 3 && characterspawn.Y <= FishProjectileCoord[i + 1].Y))
					{
						damagecheck = g_dElapsedTime + 5;
						counter++;
					}
					else if ((characterspawn.X == FishProjectileCoord[i + 2].X && characterspawn.Y >= FishProjectileCoord[i + 2].Y) || (characterspawn.X <= FishProjectileCoord[i + 2].X + 3 && characterspawn.Y <= FishProjectileCoord[i + 2].Y))
					{
						damagecheck = g_dElapsedTime + 5;
						counter++;
					}
				}

				check += 4;
			}
			break;

		case ENEMYPIC_SPIDER1:
			//Spider();
			break;

		case ENEMYPIC_SPIDER2:
			//Spider();
			break;

		case ENEMYPIC_ROBOT1:
			//Robot();
			break;

		case ENEMYPIC_ROBOT2:
			//Robot();
			break;

		case ENEMYPIC_KAMBENG1:
			//UltimateKambeng();
			break;

		case ENEMYPIC_KAMBENG2:
			//UltimateKambeng();
			break;

		default:
			break;
		}
	}

	//---Clear Arrays---//
	void arrayclear()
	{
		for (int i = 0; i < 20; i++)
		{
			projectile[i].erase();
			projectileCoord[i].X = 0;
			projectileCoord[i].Y = 0;
		}
	}

//-------Combat Render-------//

	//-----Combat Render-----//
	void combatdisplay()
	{
		WORD color = 0x0B;
		enemy1.display(combatdisplaycoord, enemy1.boss1.Health, enemy1.boss1.MaxHealth, enemy1.boss1.Attack, enemy1.boss1.Defence);

		enemyrender();

		buttonrender();

		textboxrender();

		if (isEnemyAttActive == false)
		{
			player1.display(combatdisplaycoord);
			if (updatedtextprinted == false)
			{
				printinglinesoftext(enemySelector);
			}
		}
		else
		{
			renderCharacterSymbol(characterspawn);
			printprojectiles(thisisacount);
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
			if (animate == true)
			{
				thisisatimeforanimation = g_dElapsedTime + 1;
				displayno1 = ENEMYPIC_KAMBENGF2;
				animate = false;
			}
			break;

		case ENEMYPIC_KAMBENGF2:
			display = enemypicture.kambengF2;
			if (animate == true)
			{
				thisisatimeforanimation = g_dElapsedTime + 1;
				displayno1 = ENEMYPIC_KAMBENGF1;
				animate = false;
			}
			break;

		case ENEMYPIC_SKELETON1:
			display = enemypicture.skeleton1;
			if (animate == true)
			{
				thisisatimeforanimation = g_dElapsedTime + 1;
				displayno1 = ENEMYPIC_SKELETON2;
				animate = false;
			}
			break;

		case ENEMYPIC_SKELETON2:
			display = enemypicture.skeleton2;
			if (animate == true)
			{
				thisisatimeforanimation = g_dElapsedTime + 1;
				displayno1 = ENEMYPIC_SKELETON1;
				animate = false;
			}
			break;

		case ENEMYPIC_FISH1:
			display = enemypicture.Fish1;
			if (animate == true)
			{
				thisisatimeforanimation = g_dElapsedTime + 1;
				displayno1 = ENEMYPIC_FISH2;
				animate = false;
			}
			break;

		case ENEMYPIC_FISH2:
			display = enemypicture.Fish2;
			if (animate == true)
			{
				thisisatimeforanimation = g_dElapsedTime + 1;
				displayno1 = ENEMYPIC_FISH1;
				animate = false;
			}
			break;

		case ENEMYPIC_SPIDER1:
			display = enemypicture.spider1;
			if (animate == true)
			{
				thisisatimeforanimation = g_dElapsedTime + 1;
				displayno1 = ENEMYPIC_SPIDER2;
				animate = false;
			}
			break;

		case ENEMYPIC_SPIDER2:
			display = enemypicture.spider2;
			if (animate == true)
			{
				thisisatimeforanimation = g_dElapsedTime + 1;
				displayno1 = ENEMYPIC_SPIDER1;
				animate = false;
			}
			break;

		case ENEMYPIC_ROBOT1:
			display = enemypicture.robot1;
			if (animate == true)
			{
				thisisatimeforanimation = g_dElapsedTime + 1;
				displayno1 = ENEMYPIC_ROBOT2;
				animate = false;
			}
			break;

		case ENEMYPIC_ROBOT2:
			display = enemypicture.robot2;
			if (animate == true)
			{
				thisisatimeforanimation = g_dElapsedTime + 1;
				displayno1 = ENEMYPIC_ROBOT1;
				animate = false;
			}
			break;

		case ENEMYPIC_KAMBENG1:
			display = enemypicture.KAMBENG1;
			if (animate == true)
			{
				thisisatimeforanimation = g_dElapsedTime + 1;
				displayno1 = ENEMYPIC_KAMBENG2;
				animate = false;
			}
			break;

		case ENEMYPIC_KAMBENG2:
			display = enemypicture.KAMBENG2;
			if (animate == true)
			{
				thisisatimeforanimation = g_dElapsedTime + 1;
				displayno1 = ENEMYPIC_KAMBENG1;
				animate = false;
			}
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
		if (thisisatimeforanimation < g_dElapsedTime)
		{
			animate = true;
			return;
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

		if (combatgameplay == COMBAT_ATT_PLAYER_TEXTUPDATE)
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
		else if (combatgameplay == COMBAT_ATT_UPDATEALLSTATS || combatgameplay == COMBAT_DEF_UPDATEALLSTATS)
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
	}

	//---Spawning Projectiles---//
	void printprojectiles(int arraycounter)
	{
		int arraynumber = 0;
		switch (displayno1)
		{
		case ENEMYPIC_KAMBENGF1:
			for (int j = 0; j <= arraycounter; j++)
			{
				g_Console.writeToBuffer(projectileCoord[j], projectile[j], 0x0A);
			}
			break;

		case ENEMYPIC_KAMBENGF2:
			for (int j = 0; j <= arraycounter; j++)
			{
				g_Console.writeToBuffer(projectileCoord[j], projectile[j], 0x0A);
			}
			break;

		case ENEMYPIC_SKELETON1:
			for (int i = 0; i < 2; i++)
			{
				g_Console.writeToBuffer(SkeletonProjectileCoord[arraynumber], SkeletonProjectile[arraynumber], 0x0C);
				g_Console.writeToBuffer(SkeletonProjectileCoord[arraynumber + 1], SkeletonProjectile[arraynumber + 1], 0x0C);
				g_Console.writeToBuffer(SkeletonProjectileCoord[arraynumber + 2], SkeletonProjectile[arraynumber + 2], 0x0C);
				arraynumber += 3;
			}
			arraynumber = 0;
			break;

		case ENEMYPIC_SKELETON2:
			for (int i = 0; i < 2; i++)
			{
				g_Console.writeToBuffer(SkeletonProjectileCoord[arraynumber], SkeletonProjectile[arraynumber], 0x0C);
				g_Console.writeToBuffer(SkeletonProjectileCoord[arraynumber + 1], SkeletonProjectile[arraynumber + 1], 0x0C);
				g_Console.writeToBuffer(SkeletonProjectileCoord[arraynumber + 2], SkeletonProjectile[arraynumber + 2], 0x0C);
				arraynumber += 3;
			}
			arraynumber = 0;
			break;

		case ENEMYPIC_FISH1:
			for (int i = 0; i < 2; i++)
			{
				g_Console.writeToBuffer(FishProjectileCoord[arraynumber], FishProjectile[arraynumber], 0x0C);
				g_Console.writeToBuffer(FishProjectileCoord[arraynumber + 1], FishProjectile[arraynumber + 1], 0x0C);
				g_Console.writeToBuffer(FishProjectileCoord[arraynumber + 2], FishProjectile[arraynumber + 2], 0x0C);
				g_Console.writeToBuffer(FishProjectileCoord[arraynumber + 3], FishProjectile[arraynumber + 3], 0x0C);
				arraynumber += 3;
			}
			arraynumber = 0;
			break;

		case ENEMYPIC_FISH2:
			for (int i = 0; i < 2; i++)
			{
				g_Console.writeToBuffer(FishProjectileCoord[arraynumber], FishProjectile[arraynumber], 0x0C);
				g_Console.writeToBuffer(FishProjectileCoord[arraynumber + 1], FishProjectile[arraynumber + 1], 0x0C);
				g_Console.writeToBuffer(FishProjectileCoord[arraynumber + 2], FishProjectile[arraynumber + 2], 0x0C);
				g_Console.writeToBuffer(FishProjectileCoord[arraynumber + 3], FishProjectile[arraynumber + 3], 0x0C);
				arraynumber += 3;
			}
			arraynumber = 0;
			break;

		case ENEMYPIC_SPIDER1:
			for (int i = 0; i < 5; i++)
			{
				g_Console.writeToBuffer(SpiderProjectilCoord[i], SpiderProjectile[i]);
			}
			break;

		case ENEMYPIC_SPIDER2:
			for (int i = 0; i < 5; i++)
			{
				g_Console.writeToBuffer(SpiderProjectilCoord[i], SpiderProjectile[i]);
			}
			break;

		case ENEMYPIC_ROBOT1:
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 18; j++)
				{
					g_Console.writeToBuffer(56, 31, RobotElectric[i][j]);
				}
			}
			break;

		case ENEMYPIC_ROBOT2:
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 18; j++)
				{
					g_Console.writeToBuffer(56, 31, RobotElectric[i][j]);
				}
			}
			break;

		case ENEMYPIC_KAMBENG1:
			//UltimateKambeng();
			break;

		case ENEMYPIC_KAMBENG2:
			//UltimateKambeng();
			break;

		default:
			break;
		}
	}
	

//-------Initalization of All Characters/Enemies-------//

	//-----Initalizing all Combat-----//
	void combatinit()
	{
		srand(time(NULL));
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
				enemy1.boss1.Defence = 1;
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
				att = 45;
				max = 90;
				i++;
				enemy1.init(att, max);
				displayno1 = ENEMYPIC_FISH1;
				break;
			}
			else if (i == 3) //For Fourth Boss
			{
				att = 75;
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
		int health = 100;
		int attack = 1000;
		int defence = 10000;

		player1.playerBase(health, attack, defence);
	}

	//-----Writing into Double Array-----//
	void displayinit()
	{
		for (int i = 12; enemySelector < i; enemySelector++)
		{
			if (enemySelector == 0)
			{
				enemypicture.kambengF1 = enemyselector(enemypicture.kambengF1, enemySelector);
			}
			else if (enemySelector == 1)
			{
				enemypicture.kambengF2 = enemyselector(enemypicture.kambengF2, enemySelector);
			}
			else if (enemySelector == 2)
			{
				enemypicture.skeleton1 = enemyselector(enemypicture.skeleton1, enemySelector);
			}
			else if (enemySelector == 3)
			{
				enemypicture.skeleton2 = enemyselector(enemypicture.skeleton2, enemySelector);
			}
			else if (enemySelector == 4)
			{
				enemypicture.Fish1 = enemyselector(enemypicture.Fish1, enemySelector);
			}
			else if (enemySelector == 5)
			{
				enemypicture.Fish2 = enemyselector(enemypicture.Fish2, enemySelector);
			}
			else if (enemySelector == 6)
			{
				enemypicture.spider1 = enemyselector(enemypicture.spider1, enemySelector);
			}
			else if (enemySelector == 7)
			{
				enemypicture.spider2 = enemyselector(enemypicture.spider2, enemySelector);
			}
			else if (enemySelector == 8)
			{
				enemypicture.robot1 = enemyselector(enemypicture.robot1, enemySelector);
			}
			else if (enemySelector == 9)
			{
				enemypicture.robot2 = enemyselector(enemypicture.robot2, enemySelector);
			}
			else if (enemySelector == 10)
			{
				enemypicture.KAMBENG1 = enemyselector(enemypicture.KAMBENG1, enemySelector);
			}
			else if (enemySelector == 11)
			{
				enemypicture.KAMBENG2 = enemyselector(enemypicture.KAMBENG2, enemySelector);
			}
		}

		enemySelector = 0;

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
		projectilefilling();
	}

	//-----Writing Enemy-----//
	char** enemyselector(char** dp, int enemyno)
	{
		int monsterHeight = 24;
		int monsterLength = 53;
		ifstream monster;

		if (enemyno == 0)
			monster.open("Combat/KambengF1.txt");
		else if (enemyno == 1)
			monster.open("Combat/KambengF2.txt");
		else if (enemyno == 2)
			monster.open("Combat/Skeleton1.txt");
		else if (enemyno == 3)
			monster.open("Combat/Skeleton2.txt");
		else if (enemyno == 4)
			monster.open("Combat/Fish1.txt");
		else if (enemyno == 5)
			monster.open("Combat/Fish2.txt");
		else if (enemyno == 6)
			monster.open("Combat/Spider1.txt");
		else if (enemyno == 7)
			monster.open("Combat/Spider2.txt");
		else if (enemyno == 8)
			monster.open("Combat/Robot1.txt");
		else if (enemyno == 9)
			monster.open("Combat/Robot2.txt");
		else if (enemyno == 10)
			monster.open("Combat/KAMBENG1.txt");
		else if (enemyno == 11)
			monster.open("Combat/KAMBENG2.txt");

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
		}
		else if (printno == 1)
		{
			buttons.open("Combat/Attack_Defend_Buttons_if_Def.txt");
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
				getline(name, hold);
				return hold;
			}
			else if (no == 2)
			{
				getline(name, hold);
				getline(name, hold); 
				getline(name, hold);
				return hold;
			}
			else if (no == 3)
			{
				getline(name, hold);
				getline(name, hold);
				getline(name, hold);
				getline(name, hold);
				return hold;
			}
			else if (no == 4)
			{
				getline(name, hold);
				getline(name, hold);
				getline(name, hold);
				getline(name, hold);
				getline(name, hold);
				return hold;
			}
			else if (no == 5)
			{
				getline(name, hold);
				getline(name, hold);
				getline(name, hold);
				getline(name, hold);
				getline(name, hold);
				getline(name, hold);
				return hold;
			}
		}
	}

	//-----Filling in the Projectiles-----//
	void projectilefilling()
	{
		ifstream Projectiles;
		Projectiles.open("Combat/Projectiles.txt");

		if (Projectiles.is_open())
		{
			for (int i = 0; i < 2; i++)
			{
				getline(Projectiles, stringz.kambengProj[i]);
			}
			for (int i = 0; i < 3; i++)
			{
				getline(Projectiles, stringz.skeletonProj[i]);
			}
			for (int i = 0; i < 8; i++)
			{
				getline(Projectiles, stringz.fishProj[i]);
			}
			for (int i = 0; i < 5; i++)
			{
				getline(Projectiles, stringz.spiderProj[i]);
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
	switch (displayno1)
	{
	case ENEMYPIC_KAMBENGF1:
		Kambeng();
		break;

	case ENEMYPIC_KAMBENGF2:
		Kambeng();
		break;

	case ENEMYPIC_SKELETON1:
		Skeleton();
		break;

	case ENEMYPIC_SKELETON2:
		Skeleton();
		break;

	case ENEMYPIC_FISH1:
		Fish();
		break;

	case ENEMYPIC_FISH2:
		Fish();
		break;

	case ENEMYPIC_SPIDER1:
		Spider();
		break;

	case ENEMYPIC_SPIDER2:
		Spider();
		break;

	case ENEMYPIC_ROBOT1:
		Robot();
		break;

	case ENEMYPIC_ROBOT2:
		Robot();
		break;

	case ENEMYPIC_KAMBENG1:
		UltimateKambeng();
		break;

	case ENEMYPIC_KAMBENG2:
		UltimateKambeng();
		break;

	default:
		break;
	}
}

//---Kambeng Boss---//
void Enemy::Kambeng()
{
	for (int i = 0; i <= 19; i++)
	{
		Xcoord[i] = rand() % 2; //Randomize left or right

		if (Xcoord[i] == 0) //Setting projectile type and which directions
		{
			projectileCoord[i].X = 55;
			projectile[i] = stringz.kambengProj[0];
		}
		else
		{
			projectileCoord[i].X = 71;
			projectile[i] = stringz.kambengProj[1];
		}

		int Ycoord = (rand() % 8) + 31; //Randomize which row it spawns
		projectileCoord[i].Y = Ycoord;

		if (projectileCoord[i].Y == projectileCoord[i - 1].Y)
		{
			i--;
			continue;
		}
	}
}

//---Skeleton Boss---//
void Enemy::Skeleton()
{
	for (int i = 0; i <= 3; i+=3)
	{
		Xcoord[i] = rand() % 2; //Randomize left or right

		if (Xcoord[i] == 0) //Setting projectile type and which directions
		{
			SkeletonProjectileCoord[i].X = 55;
			SkeletonProjectileCoord[i + 1].X = 55;
			SkeletonProjectileCoord[i + 2].X = 55;
			SkeletonProjectile[i] = stringz.skeletonProj[0];
			SkeletonProjectile[i+1] = stringz.skeletonProj[1];
			SkeletonProjectile[i+2] = stringz.skeletonProj[2];
		}
		else
		{
			SkeletonProjectileCoord[i].X = 71;
			SkeletonProjectileCoord[i + 1].X = 71;
			SkeletonProjectileCoord[i + 2].X = 71;
			SkeletonProjectile[i] = stringz.skeletonProj[0];
			SkeletonProjectile[i + 1] = stringz.skeletonProj[1];
			SkeletonProjectile[i + 2] = stringz.skeletonProj[2];
		}

		int Ycoord = (rand() % 6) + 31; //Randomize which row it spawns
		SkeletonProjectileCoord[i].Y = Ycoord;
		SkeletonProjectileCoord[i + 1].Y = Ycoord + 1;
		SkeletonProjectileCoord[i + 2].Y = Ycoord + 2;

		if ((SkeletonProjectileCoord[i].Y == SkeletonProjectileCoord[i - 1].Y && SkeletonProjectileCoord[i].Y <= SkeletonProjectileCoord[i - 1].Y + 4) || (SkeletonProjectileCoord[i].Y <= SkeletonProjectileCoord[i - 1].Y && SkeletonProjectileCoord[i].Y == SkeletonProjectileCoord[i - 1].Y - 4))
		{
			i--;
			continue;
		}
	}
}

//---Fish Boss---//
void Enemy::Fish()
{
	int fishloopcount = 0;
	for (int i = 0; i < 2; i++)
	{
		Xcoord[fishloopcount] = rand() % 2;
		if (Xcoord[fishloopcount] == 0) //Setting projectile type and which directions
		{
			FishProjectileCoord[fishloopcount].X = 55;
			FishProjectileCoord[fishloopcount + 1].X = 55;
			FishProjectileCoord[fishloopcount + 2].X = 55;
			FishProjectileCoord[fishloopcount + 3].X = 55;
			FishProjectile[fishloopcount] = stringz.fishProj[0];
			FishProjectile[fishloopcount + 1] = stringz.fishProj[1];
			FishProjectile[fishloopcount + 2] = stringz.fishProj[2];
			FishProjectile[fishloopcount + 3] = stringz.fishProj[3];
		}
		else
		{
			FishProjectileCoord[fishloopcount].X = 71;
			FishProjectileCoord[fishloopcount + 1].X = 71;
			FishProjectileCoord[fishloopcount + 2].X = 71;
			FishProjectileCoord[fishloopcount + 3].X = 71;
			FishProjectile[fishloopcount] = stringz.fishProj[4];
			FishProjectile[fishloopcount + 1] = stringz.fishProj[5];
			FishProjectile[fishloopcount + 2] = stringz.fishProj[6];
			FishProjectile[fishloopcount + 3] = stringz.fishProj[7];
		}

		int Ycoord = (rand() % 5) + 31; //Randomize which row it spawns
		FishProjectileCoord[fishloopcount].Y = Ycoord;
		FishProjectileCoord[fishloopcount + 1].Y = Ycoord + 1;
		FishProjectileCoord[fishloopcount + 2].Y = Ycoord + 2;
		FishProjectileCoord[fishloopcount + 3].Y = Ycoord + 3;

		if ((FishProjectileCoord[fishloopcount].Y == FishProjectileCoord[fishloopcount - 1].Y && FishProjectileCoord[fishloopcount].Y <= FishProjectileCoord[fishloopcount - 1].Y + 1) || (FishProjectileCoord[fishloopcount].Y == FishProjectileCoord[fishloopcount - 1].Y && FishProjectileCoord[fishloopcount].Y >= FishProjectileCoord[fishloopcount - 1].Y - 1))
		{
			i--;
			continue;
		}
		fishloopcount += 4;
	}
}

//---Spider Boss---//
void Enemy::Spider()
{
	int i = 0;
	Xcoord[0] = (rand() % 9) + 55;
	
	for (i = 0; i < 5; i++)
	{
		SpiderProjectilCoord[i].X = Xcoord[0];
	}
	SpiderProjectilCoord[0].Y = 35;
	SpiderProjectilCoord[1].Y = 34;
	SpiderProjectilCoord[2].Y = 33;
	SpiderProjectilCoord[3].Y = 32;
	SpiderProjectilCoord[4].Y = 31;
	SpiderProjectile[0] = stringz.spiderProj[4];
	SpiderProjectile[1] = stringz.spiderProj[3];
	SpiderProjectile[2] = stringz.spiderProj[2];
	SpiderProjectile[3] = stringz.spiderProj[1];
	SpiderProjectile[4] = stringz.spiderProj[0];
}

//---Robot Boss---//
void Enemy::Robot()
{
	for (int i = 0; i < 10; i++)
	{
		RobotSafeSpot[i].X = (rand() % 18) + 56;
		RobotSafeSpot[i].Y = (rand() % 8) + 31;
		RobotElectric[RobotSafeSpot[i].X - 56][RobotSafeSpot[i].Y - 31] = '0';
	}
}

//---FINALKAMBENG---//
void Enemy::UltimateKambeng()
{

}

//---Update the Projectiles---//
void Enemy::bullet()
{
	switch (displayno1)
	{
	case ENEMYPIC_KAMBENGF1:
		kambengUpdate();
		break;

	case ENEMYPIC_KAMBENGF2:
		kambengUpdate();
		break;

	case ENEMYPIC_SKELETON1:
		SkeletonUpdate();
		break;

	case ENEMYPIC_SKELETON2:
		SkeletonUpdate();
		break;

	case ENEMYPIC_FISH1:
		FishUpdate();
		break;

	case ENEMYPIC_FISH2:
		FishUpdate();
		break;

	case ENEMYPIC_SPIDER1:
		SpiderUpdate();
		break;

	case ENEMYPIC_SPIDER2:
		SpiderUpdate();
		break;

	case ENEMYPIC_ROBOT1:
		RobotUpdate();
		break;

	case ENEMYPIC_ROBOT2:
		RobotUpdate();
		break;

	case ENEMYPIC_KAMBENG1:
		UltimateKambengUpdate();
		break;

	case ENEMYPIC_KAMBENG2:
		UltimateKambengUpdate();
		break;

	default:
		break;
	}
}

//---Update for Kambeng Boss---//
void Enemy::kambengUpdate()
{
	if (thisisatimeforprojectiles > g_dElapsedTime)
	{
		return;
	}
	thisisatimeforprojectiles = g_dElapsedTime + 0.15;
	if (thisisacount <= 19)
	{
		thisisacount++;
	}
	for (int i = 0; i < thisisacount; i++)
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
			else
			{
				projectileCoord[i].X--;
			}
		}
	}
}

//---Update for Skeleton Boss---//
void Enemy::SkeletonUpdate()
{
	int coord = 0;
	if (thisisatimeforprojectiles > g_dElapsedTime)
	{
		return;
	}
	thisisatimeforprojectiles = g_dElapsedTime + 0.10;
	for (int i = 0; i < 2; i++)
	{
		if (Xcoord[coord] == 0)
		{
			if (SkeletonProjectileCoord[0].X == 73 + 13)
			{
				enemyattackgame();
				continue;
			}
			else
			{
				SkeletonProjectileCoord[coord].X++;
				SkeletonProjectileCoord[coord + 1].X++;
				SkeletonProjectileCoord[coord + 2].X++;
			}
		}
		else
		{
			if (SkeletonProjectileCoord[0].X == 54 - 13)
			{
				enemyattackgame();
				continue;
			}
			else
			{
				SkeletonProjectileCoord[coord].X--;
				SkeletonProjectileCoord[coord + 1].X--;
				SkeletonProjectileCoord[coord + 2].X--;
			}
		}
		coord += 3;
	}
	coord = 0;
}

//---Update for Fish Boss---//
void Enemy::FishUpdate()
{
	int coord = 0;
	int randomupdown;
	if (thisisatimeforprojectiles > g_dElapsedTime)
	{
		return;
	}
	thisisatimeforprojectiles = g_dElapsedTime + 0.15;
	for (int i = 0; i < 2; i++)
	{
		if (Xcoord[coord] == 0)
		{
			if (FishProjectileCoord[0].X == 73 + 4)
			{
				enemyattackgame();
				continue;
			}
			else
			{
				FishProjectileCoord[coord].X++;
				FishProjectileCoord[coord + 1].X++;
				FishProjectileCoord[coord + 2].X++;
				FishProjectileCoord[coord + 3].X++;
				randomupdown = rand() % 3;
				if (randomupdown == 1)
				{
					if (FishProjectileCoord[coord].Y <= 32)
					{
						FishProjectileCoord[coord].Y++;
						FishProjectileCoord[coord + 1].Y++;
						FishProjectileCoord[coord + 2].Y++;
						FishProjectileCoord[coord + 3].Y++;
					}
					else if (FishProjectileCoord[coord].Y >= 35)
					{
						FishProjectileCoord[coord].Y--;
						FishProjectileCoord[coord + 1].Y--;
						FishProjectileCoord[coord + 2].Y--;
						FishProjectileCoord[coord + 3].Y--;
					}
				}
				else if (randomupdown = 2)
				{
					if (FishProjectileCoord[coord].Y >= 35)
					{
						FishProjectileCoord[coord].Y--;
						FishProjectileCoord[coord + 1].Y--;
						FishProjectileCoord[coord + 2].Y--;
						FishProjectileCoord[coord + 3].Y--;
					}
					else if (FishProjectileCoord[coord].Y >= 32)
					{
						FishProjectileCoord[coord].Y++;
						FishProjectileCoord[coord + 1].Y++;
						FishProjectileCoord[coord + 2].Y++;
						FishProjectileCoord[coord + 3].Y++;
					}
				}
			}
		}
		else
		{
			if (FishProjectileCoord[0].X == 54 - 4)
			{
				enemyattackgame();
				continue;
			}
			else
			{
				FishProjectileCoord[coord].X--;
				FishProjectileCoord[coord + 1].X--;
				FishProjectileCoord[coord + 2].X--;
				FishProjectileCoord[coord + 3].X--;
			}
			randomupdown = rand() % 3;
			if (randomupdown == 1)
			{
				if (FishProjectileCoord[coord].Y <= 32)
				{
					FishProjectileCoord[coord].Y++;
					FishProjectileCoord[coord + 1].Y++;
					FishProjectileCoord[coord + 2].Y++;
					FishProjectileCoord[coord + 3].Y++;
				}
				else if (FishProjectileCoord[coord].Y >= 35)
				{
					FishProjectileCoord[coord].Y--;
					FishProjectileCoord[coord + 1].Y--;
					FishProjectileCoord[coord + 2].Y--;
					FishProjectileCoord[coord + 3].Y--;
				}
			}
			else if (randomupdown = 2)
			{
				if (FishProjectileCoord[coord].Y >= 35)
				{
					FishProjectileCoord[coord].Y--;
					FishProjectileCoord[coord + 1].Y--;
					FishProjectileCoord[coord + 2].Y--;
					FishProjectileCoord[coord + 3].Y--;
				}
				else if (FishProjectileCoord[coord].Y >= 32)
				{
					FishProjectileCoord[coord].Y++;
					FishProjectileCoord[coord + 1].Y++;
					FishProjectileCoord[coord + 2].Y++;
					FishProjectileCoord[coord + 3].Y++;
				}
			}
		}
		coord += 4;
	}
	coord = 0;
}

//---Update for Spider Boss---//
void Enemy::SpiderUpdate()
{
	if (thisisatimeforprojectiles > g_dElapsedTime)
	{
		return;
	}
	thisisatimeforprojectiles = g_dElapsedTime + 0.15;
	for (int i = 0; i < 5; i++)
	{
		SpiderProjectilCoord[i].Y++;
		if (SpiderProjectilCoord[0].Y == 39)
		{
			enemyattackgame();
			return;
		}
	}
	
}

//---Update for Robot Boss---//
void Enemy::RobotUpdate()
{
	if (thisisatimeforprojectiles > g_dElapsedTime)
	{
		return;
	}
	thisisatimeforprojectiles = g_dElapsedTime + 5;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 18; j++)
		{
			if (RobotElectric[i][j] != 0)
			{
				RobotElectric[i][j] = '1';
			}
		}
	}
}

//---Update for FINALKAMBENG---//
void Enemy::UltimateKambengUpdate()
{

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
		character.Attack = (character.Attack + 20) * 1.2f;
		character.Defence = (character.Defence + 25) * 1.3f;
	}
}

/*/
-End of Player Class-
/*/