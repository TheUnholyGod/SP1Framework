#include "flare.h"

extern double g_flareTime; 
extern double g_dElapsedTime;
extern bool   g_isTorchEnabled;
extern bool   g_isflareActive;
extern bool   g_isTimerStarted;
void flare()
{
	if (g_isflareActive == true)
	{
		g_isTorchEnabled = false;
		if (g_isTimerStarted == false)
		{
			g_flareTime = g_dElapsedTime + 2.0;
			g_isTimerStarted = true;
		}
		if (g_flareTime < g_dElapsedTime)
		{
			g_isTorchEnabled = true;
			g_isflareActive = false;
		}
	}
}