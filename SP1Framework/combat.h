#ifndef _COMBAT_H
#define _COMBAT_H

//-----Incluion Block-----//
#include <windows.h>
#include <time.h>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "Framework\console.h"
#include "game.h"

//-----Namespace Block-----//
using namespace std;
using std::string;
using std::vector;

//-----Combat Gamestates-----//
enum COMBAT
{
	COMBAT_GETINPUT,
	COMBAT_AFTINPUT,
	COMBAT_ATT,
	COMBAT_ATT_PLAYER_TEXTUPDATE,
	COMBAT_ATT_ENEMYGAME,
	COMBAT_ATT_UPDATEALLSTATS,
	COMBAT_DEF,
	COMBAT_DEF_ENEMYGAME,
	COMBAT_DEF_UPDATEALLSTATS,
	COMBAT_VICTORY,
	COMBAT_RELOOP
};

//-----Enum for Enemy Picture-----//
enum ENEMYPIC
{
	ENEMYPIC_KAMBENGF1,
	ENEMYPIC_KAMBENGF2,
	ENEMYPIC_SKELETON1,
	ENEMYPIC_SKELETON2,
	ENEMYPIC_FISH1,
	ENEMYPIC_FISH2,
	ENEMYPIC_SPIDER1,
	ENEMYPIC_SPIDER2,
	ENEMYPIC_ROBOT1,
	ENEMYPIC_ROBOT2,
	ENEMYPIC_KAMBENG1,
	ENEMYPIC_KAMBENG2
};

//-----Enum for Button Picture-----//
enum BUTTONPIC
{
	BUTTONPIC_ATTBUTTON,
	BUTTONPIC_DEFBUTTON
};

//-----Enum for Textbox Picture-----//
enum TEXTBOXPIC
{
	TEXTBOXPIC_BASIC,
	TEXTBOXPIC_DEF
};

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

	//---Update of all Stats---//
	void statsUpdate(int killcount);
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

	//---Boss Attack/Defend MiniGame---//
	void enemyattackgame();

	//---Updating the Bullets---//
	void bullet();

	//---Kambeng Boss---//
	void Kambeng();

	//---Skeleton Boss---//
	void Skeleton();

	//---Fish Boss---//
	void Fish();

	//---Spider Boss---//
	void Spider();

	//---Robot Boss---//
	void Robot();

	//---FINALKAMBENG---//
	void UltimateKambeng();

	//---Update for Kambeng Boss---//
	void kambengUpdate();

	//---Update for Skeleton Boss---//
	void SkeletonUpdate();

	//---Update for Fish Boss---//
	void FishUpdate();

	//---Update for Spider Boss---//
	void SpiderUpdate();

	//---Update for Robot Boss---//
	void RobotUpdate();

	//---Update for FINALKAMBENG---//
	void UltimateKambengUpdate();
};


//-----Function Declaration-----//
void combat();
void combatdisplay();
void attackProcess();
void defendProcess();
int checkVictory();
void enemyinit(int select);
void playerinit();
char** enemyselector(char** dp, int enemyno);
char** buttonsdisplay(char** buttonfill, int printno);
char** textboxdisplay(char** textboxfill, int read);
void renderCharacterSymbol(COORD a);
void symbolMovement();
void holdtimer();
string updatetext(int number);
void displayinit();
void enemyrender();
void buttonrender();
void textboxrender();
void combatinit();
void buttonsinput();
void aftinput();
void combatreloop();
void printprojectiles(int arraycounter);
void printinglinesoftext(int name);
void checkdamage();
string namefilling(int no);
void projectilefilling();
void arrayclear();

#endif //End of _COMBAT_H