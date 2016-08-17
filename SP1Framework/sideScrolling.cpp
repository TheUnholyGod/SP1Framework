#include "sideScrolling.h"

// DONT NOT TOUCH THIS FILE, I STILL HAVE TO FIGURE OUT HOW TO DO IT!! -Man Cong <3
void Camera(int playerPosX, int playerPosY, int cameraX, int cameraY)
{
	cameraX = playerPosX - 40;
	cameraY = playerPosY - 12;

	if (cameraX < 0)
		cameraX = 0;
	if (cameraY < 0)
		cameraY = 0;
}