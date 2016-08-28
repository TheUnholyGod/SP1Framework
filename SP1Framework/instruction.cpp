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
	g_Console.writeToBuffer(5, 28, "Hello, you are in the editor mode :D");
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
		}
	}
}