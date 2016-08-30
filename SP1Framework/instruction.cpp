#include"instruction.h"

extern int g_PicksObtain;
extern int g_KeysObtain;

void renderGameInstruction()
{
	string key = to_string(g_KeysObtain);
	string PickUse = to_string(g_PicksObtain);
	g_Console.writeToBuffer(5, 28, "<GAME MODE>");
	g_Console.writeToBuffer(5, 29, "<Arrow Keys> to move character");
	g_Console.writeToBuffer(5, 30, "<E>          to interact");
	g_Console.writeToBuffer(5, 31, "<R>          to restart ");
	g_Console.writeToBuffer(5, 32, "<M>          for main menu");
	g_Console.writeToBuffer(40, 28, "Number of keys: ");
	g_Console.writeToBuffer(40, 29, "Pickaxe uses left: ");
	g_Console.writeToBuffer(60, 28, key);
	g_Console.writeToBuffer(60, 29, PickUse);
}
void renderCreativeInstruction()
{
	string key = to_string(g_KeysObtain);
	string PickUse = to_string(g_PicksObtain);
	renderTextBox();
	g_Console.writeToBuffer(5, 28, "<CREATIVE MODE>");
	g_Console.writeToBuffer(5, 29, "<Arrow Keys> to move character");
	g_Console.writeToBuffer(5, 30, "<E>          to interact");
	g_Console.writeToBuffer(5, 31, "<R>          to suicide");
	g_Console.writeToBuffer(5, 32, "<L>          for level editor");
	g_Console.writeToBuffer(5, 33, "<M>          for main menu");
	g_Console.writeToBuffer(40, 28, "Number of keys: ");
	g_Console.writeToBuffer(40, 29, "Pickaxe uses left: ");
	g_Console.writeToBuffer(60, 28, key);
	g_Console.writeToBuffer(60, 29, PickUse);
}
void renderEditorInstruction()
{
	renderTextBox();

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