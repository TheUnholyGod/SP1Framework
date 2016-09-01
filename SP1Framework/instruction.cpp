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
	g_Console.writeToBuffer(65, 28, "<LEGEND>");
	ostringstream legend;
	legend.str("");
	legend << "Wall           = " << (char)178;
	g_Console.writeToBuffer(65, 29, legend.str(),0x0B);
	legend.str("");
	legend << "Walkable tile  = " << (char)176;
	g_Console.writeToBuffer(65, 30, legend.str(), 0x07);
	legend.str("");
	legend << "End point      = " << (char)177;
	g_Console.writeToBuffer(65, 31, legend.str(), 0x0A);
	legend.str("");
	legend << "Key            = " << (char)168;
	g_Console.writeToBuffer(65, 32, legend.str(), 0x0E);
	legend.str("");
	legend << "Door           = " << (char)219;
	g_Console.writeToBuffer(65, 33, legend.str(), 0x0E);
	legend.str("");
	legend << "Movable object = " << (char)254;
	g_Console.writeToBuffer(65, 34, legend.str(), 0x05);
	legend.str("");
	legend << "Smashable rock = " << (char)220;
	g_Console.writeToBuffer(65, 35, legend.str(), 0x04);
	legend.str("");
	legend << "Pickaxe        = " << (char)156;
	g_Console.writeToBuffer(65, 36, legend.str());
	legend.str("");
	legend << "Ice block      = " << (char)223;
	g_Console.writeToBuffer(65, 37, legend.str(), 0x0B);
	legend.str("");
	legend << "Death Pit(open)= " << (char)253;
	g_Console.writeToBuffer(65, 38, legend.str(), 0x00);
	legend.str("");
	legend << "Death Pit(open)= " << (char)255;
	g_Console.writeToBuffer(65, 38, legend.str());
	legend.str("");
	legend << "Spikes  (open) = " << (char)215;
	g_Console.writeToBuffer(65, 39, legend.str(), 0x0C);
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
	ostringstream legend;
	legend.str("");
	legend << "Wall           = " << (char)178;
	g_Console.writeToBuffer(65, 29, legend.str(), 0x0B);
	legend.str("");
	legend << "Walkable tile  = " << (char)176;
	g_Console.writeToBuffer(65, 30, legend.str(), 0x07);
	legend.str("");
	legend << "End point      = " << (char)177;
	g_Console.writeToBuffer(65, 31, legend.str(), 0x0A);
	legend.str("");
	legend << "Key            = " << (char)168;
	g_Console.writeToBuffer(65, 32, legend.str(), 0x0E);
	legend.str("");
	legend << "Door           = " << (char)219;
	g_Console.writeToBuffer(65, 33, legend.str(), 0x0E);
	legend.str("");
	legend << "Movable object = " << (char)254;
	g_Console.writeToBuffer(65, 34, legend.str(), 0x05);
	legend.str("");
	legend << "Smashable rock = " << (char)220;
	g_Console.writeToBuffer(65, 35, legend.str(), 0x04);
	legend.str("");
	legend << "Pickaxe        = " << (char)156;
	g_Console.writeToBuffer(65, 36, legend.str());
	legend.str("");
	legend << "Ice block      = " << (char)223;
	g_Console.writeToBuffer(65, 37, legend.str(), 0x0B);
	legend.str("");
	legend << "Death Pit(open)= " << (char)255;
	g_Console.writeToBuffer(65, 38, legend.str());
	legend.str("");
	legend << "Spikes  (open) = " << (char)215;
	g_Console.writeToBuffer(65, 39, legend.str(), 0x0C);
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
	g_Console.writeToBuffer(40, 30, "<X>     for Death Pit");
	g_Console.writeToBuffer(40, 31, "<Y>     for Spikes");
	ostringstream legend;
	legend.str("");
	legend << "Wall           = " << (char)178;
	g_Console.writeToBuffer(65, 29, legend.str(), 0x0B);
	legend.str("");
	legend << "Walkable tile  = " << (char)176;
	g_Console.writeToBuffer(65, 30, legend.str(), 0x07);
	legend.str("");
	legend << "End point      = " << (char)177;
	g_Console.writeToBuffer(65, 31, legend.str(), 0x0A);
	legend.str("");
	legend << "Key            = " << (char)168;
	g_Console.writeToBuffer(65, 32, legend.str(), 0x0E);
	legend.str("");
	legend << "Door           = " << (char)219;
	g_Console.writeToBuffer(65, 33, legend.str(), 0x0E);
	legend.str("");
	legend << "Movable object = " << (char)254;
	g_Console.writeToBuffer(65, 34, legend.str(), 0x05);
	legend.str("");
	legend << "Smashable rock = " << (char)220;
	g_Console.writeToBuffer(65, 35, legend.str(), 0x04);
	legend.str("");
	legend << "Pickaxe        = " << (char)156;
	g_Console.writeToBuffer(65, 36, legend.str());
	legend.str("");
	legend << "Ice block      = " << (char)223;
	g_Console.writeToBuffer(65, 37, legend.str(), 0x0B);
	legend.str("");
	legend << "Death Pit      = " << (char)240;
	g_Console.writeToBuffer(65, 38, legend.str(), 0x04);
	legend.str("");
	legend << "Spikes         = " << (char)196;
	g_Console.writeToBuffer(65, 39, legend.str(), 0x0E);
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