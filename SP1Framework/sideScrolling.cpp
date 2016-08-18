#include "sideScrolling.h"

// --------------------------------------------- SIDE SCROLLING ------------------------------------------ //

extern SGameChar   g_sChar;

void Camera()
{
	int maxBorderX = 40;		// -------- SCREEN STARTS TO MOVE WHEN THE X AXIS IS MORE THAN 40 -------- //
	int maxBorderY = 12;		// -------- SCREEN STARTS TO MOVE WHEN THE Y AXIS IS MORE THAN 12 -------- //
	int OffsetX = 0;			 
	int OffsetY = 0;			

	if (g_sChar.m_cLocation.X > maxBorderX)
		OffsetX = g_sChar.m_cLocation.X - maxBorderX;
	if (g_sChar.m_cLocation.Y > maxBorderY)
		OffsetY = g_sChar.m_cLocation.Y - maxBorderY;

	for (int Y = 0 + OffsetX; Y < 12 + OffsetY; Y++)		// -------- RENDER THE MAP FOR THE VALUE OF Y -------- //
	{



		for (int X = 0 + OffsetX; X < 40 + OffsetY; X++)		// -------- RENDER THE MAP FOR THE VALUE OF X -------- //
		{

		}
	}

}