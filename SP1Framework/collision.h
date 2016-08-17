#ifndef _COLLISION_H
#define _COLLISION_H

#include <string>
#include <fstream>
#include "Framework\console.h"
#include "Framework\timer.h"
#include "game.h"
#include <windows.h>

extern Console g_sChar;
extern bool g_isKeyPressed;
extern bool g_abKeyPressed[K_COUNT];
using namespace std;

bool colDetection();

#endif // End _COLLISION_H