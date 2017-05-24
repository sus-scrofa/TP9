#pragma once
#include "basicLCD.h"
#include <iostream>

#define DEBUG

#ifdef DEBUG
void lcdWriteByteIR(BYTE by);
void lcdWriteByteDR(BYTE by);
void lcdWrtieNibble(BYTE by);
#endif	//DEBUG

class myDisplay : public basicLCD
{
public:
	myDisplay();
	~myDisplay();
	bool lcdInitOk();
	FT_STATUS lcdGetError();
	bool lcdClear();
	basicLCD & operator<<(const unsigned char c);
	bool lcdMoveCursorUp();
	bool lcdMoveCursorDown();
	bool lcdMoveCursorRight();
	bool lcdMoveCursorLeft();
	bool lcdSetCursorPosition();
	cursorPosition lcdGetCursorPosition();
	void lcdUpdateCursor();

private:
	int cadd;
};

