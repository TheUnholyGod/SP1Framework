#ifndef _LOADLEVEL_H
#define _LOADLEVEL_H

#include <string>
#include <fstream>
#include "Framework\console.h"
#include "Framework\timer.h"
#include "game.h"
#include <windows.h>

extern Console g_Console;
using namespace std;

void store_map(int levelnumber);
void print_map();

#endif // !_LOADLEVEL_H
