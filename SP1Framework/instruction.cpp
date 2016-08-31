#include"instruction.h"

extern int g_PicksObtain;
extern int g_KeysObtain;
extern int g_flares;

void renderGameInstruction()
{
	string key = to_string(g_KeysObtain);
	string PickUse = to_string(g_PicksObtain);
	string flare = to_string(g_flares);
	g_Console.writeToBuffer(5, 28, "<GAME MODE>");
	g_Console.writeToBuffer(5, 29, "<Arrow Keys> to move character");
	g_Console.writeToBuffer(5, 30, "<E>          to interact");
	g_Console.writeToBuffer(5, 31, "<R>          to restart ");
	g_Console.writeToBuffer(5, 32, "<M>          for main menu");
	g_Console.writeToBuffer(5, 33, "<T>          To use flares");
	g_Console.writeToBuffer(40, 28, "Keys: ", 0x0C);
	g_Console.writeToBuffer(40, 29, "Pickaxe: ", 0x0C);
	g_Console.writeToBuffer(40, 30, "Flares: ", 0x0C);
	g_Console.writeToBuffer(60, 28, key, 0x0A);
	g_Console.writeToBuffer(60, 29, PickUse, 0x0A);
	g_Console.writeToBuffer(60, 30, flare, 0x0A);

}
void renderCreativeInstruction()
{
	string key = to_string(g_KeysObtain);
	string PickUse = to_string(g_PicksObtain);
	string flare = to_string(g_flares);
	g_Console.writeToBuffer(5, 28, "<CREATIVE MODE>");
	g_Console.writeToBuffer(5, 29, "<Arrow Keys> to move character");
	g_Console.writeToBuffer(5, 30, "<E>          to interact");
	g_Console.writeToBuffer(5, 31, "<R>          to suicide");
	g_Console.writeToBuffer(5, 32, "<L>          for level editor");
	g_Console.writeToBuffer(5, 33, "<M>          for main menu");
	g_Console.writeToBuffer(5, 34, "<T>          To use flares");
	g_Console.writeToBuffer(40, 28, "Keys: ",0x0C);
	g_Console.writeToBuffer(40, 29, "Pickaxe: ",0x0C);
	g_Console.writeToBuffer(40, 30, "Flares: ",0x0C);
	g_Console.writeToBuffer(60, 28, key, 0x0A);
	g_Console.writeToBuffer(60, 29, PickUse, 0x0A);
	g_Console.writeToBuffer(60, 30, flare, 0x0A);
}
void renderEditorInstruction()
{
	g_Console.writeToBuffer(5, 27, "<Arrow Keys> to move cursor");
	g_Console.writeToBuffer(5, 28, "Press:");
	g_Console.writeToBuffer(5, 29, "<W>     for Wall");
	g_Console.writeToBuffer(5, 30, "<SPACE> for Walkable Area");
	g_Console.writeToBuffer(5, 31, "<K>     for Collectable Key");
	g_Console.writeToBuffer(5, 32, "<D>     for Door");
	g_Console.writeToBuffer(5, 33, "<B>     for Movable Boulder");
	g_Console.writeToBuffer(5, 34, "<P>     for Collectable Pickaxe");
	g_Console.writeToBuffer(5, 35, "<O>     for Breakable Boulder");
	g_Console.writeToBuffer(5, 36, "<Q>     for Game End point");
	g_Console.writeToBuffer(5, 37, "<C>     for creative mode");
	g_Console.writeToBuffer(5, 38, "<S>     to save");
	g_Console.writeToBuffer(40, 29, "<I>     for Ice Block");
}
void renderTextBox()
{
	COORD c;
	for (int i = 0; i < 15; ++i)
	{
		c.Y = i + 26;
		for (int j = 0; j < 130; ++j)
		{
			c.X = j;
			g_Console.writeToBuffer(c, (char)176);
		}
	}
}