#include"instruction.h"

void renderGameInstruction()
{
	renderTextBox();
	g_Console.writeToBuffer(5, 28, "Hello, you are in game mode :D");
}
void renderCreativeInstruction()
{
	renderTextBox();
	g_Console.writeToBuffer(5, 28, "Hello, you are in Creative mode :D");
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