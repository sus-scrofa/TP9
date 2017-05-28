#pragma once

#define DEBUG

#include "basicLCD.h"
#include <iostream>
#include <string>

#ifdef DEBUG
#include "defines.h"
#endif // DEBUG

class myDisplay : public basicLCD
{
public:
	myDisplay();
	~myDisplay();
	bool lcdInitOk();
	FT_STATUS lcdGetError();
	bool lcdClear();
	bool lcdClearToEOL();
	basicLCD & operator<<(const unsigned char c);
	basicLCD & operator<<(const unsigned char * c);
	basicLCD & operator<<(std::string s);
	bool lcdMoveCursorUp();
	bool lcdMoveCursorDown();
	bool lcdMoveCursorRight();
	bool lcdMoveCursorLeft();
	bool lcdSetCursorPosition(const cursorPosition pos);
	cursorPosition lcdGetCursorPosition();

#ifdef DEBUG
	BYTE DDRAM[CHARXROW * ROWSXLINE * 2 + 1];
	void printDDRAM();
	void lcdWriteByteIR(BYTE by);
	void lcdWriteByteDR(BYTE by);
#endif // DEBUG

protected:
	void lcdUpdateCursor();
	int cadd;
	int getCursorRow();
	int getCursorCol();
};

