#include "levelSelection.h"

void levelSelection(int *maxWidth, int *maxHeight, string *readLevel)
{
	string level = "";
	int width = 0, height = 0;

	//Give some condition for example like if its level 1, the will print out the map

	width = 80;             // <-------- JUST FOR TESTING ----------------------> //
	height = 25;			// <-------- JUST FOR TESTING ----------------------> //
	level = "Level_1.txt";  // <-------- JUST FOR TESTING ----------------------> //
	*readLevel = level;    // <-------- JUS FOR TESTING ----------------------> //
	*maxWidth = width;	   // <-------- JUST FOR TESTING ----------------------> //
	*maxHeight = height;   // <-------- JUST FOR TESTING ----------------------> //
}