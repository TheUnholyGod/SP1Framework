#include"instruction.h"

void renderGameInstruction()
{
	g_Console.writeToBuffer(0, 26, "Hello, you are in game mode :D");
}
void renderCreativeInstruction()
{
	g_Console.writeToBuffer(0, 26, "Hello, you are in Creative mode :D");
}
void renderEditorInstruction()
{
	g_Console.writeToBuffer(0, 26, "Hello, you are in the editor mode :D");
}