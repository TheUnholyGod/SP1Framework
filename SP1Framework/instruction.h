#ifndef _INSTRUCTION_H
#define _INSTRUCTION_H

#include "game.h"

void renderGameInstruction();
void renderCreativeInstruction();
void renderEditorInstruction();
char** loadTextBox(char** textbox);
void renderTextBox();

#endif // !_INSTRUCTION_H