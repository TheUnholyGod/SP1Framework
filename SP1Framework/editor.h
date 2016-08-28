#ifndef _EDITOR_H
#define _EDITOR_H

#include "game.h"

void renderEditor();
void editor();
void moveCursor();
void renderCursor();
void editmap(int levelnumber,char change);
void edits();
void renderEndpoint();
void saveMap(int levelnumber);

#endif // !_EDITOR_H
