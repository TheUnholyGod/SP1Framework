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
	ENEMYPIC_SPIDER1
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
void printingtextupdate();
void displayinit();
void enemyrender();
void buttonrender();
void textboxrender();
void combatinit();
void buttonsinput();
void aftinput();
void combatreloop();
void printprojectiles(int arraycounter);

#endif //End of _COMBAT_H