#include"instruction.h"

extern char** textbox;

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
			WORD color = 0x0B;
			//convert legend to actual ascii characters
			if (textbox[i][j] == '-')
			{
				color = 0x07;
				textbox[i][j] = ' ';
			}
			if (textbox[i][j] == 'W')
			{
				color = 0x0B;
				textbox[i][j] = (char)178;
			}
			if (textbox[i][j] == '*')
			{
				textbox[i][j] = ' ';
			}
			if (textbox[i][j] == '+')
			{
				textbox[i][j] = (char)177;
				color = 0x7C;
			}
			c.X = j;
			g_Console.writeToBuffer(c, textbox[i][j], color);
		}
	}
}