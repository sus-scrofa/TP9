#include "myDisplay.h"
#include "defines.h"

myDisplay::myDisplay()
{
	cadd = 1;
	lcdInitOk();
}

myDisplay::~myDisplay()
{
}

bool myDisplay::lcdInitOk()
{
	
}

FT_STATUS myDisplay::lcdGetError()
{

}

bool myDisplay::lcdClear()
{
	lcdWriteByteIR(LCD_CLEAR);
}

basicLCD& myDisplay::operator<<(const BYTE c)
{

}

bool myDisplay::lcdMoveCursorUp()
{

}

bool myDisplay::lcdMoveCursorDown()
{

}

bool myDisplay::lcdMoveCursorRight()
{

}

bool myDisplay::lcdMoveCursorLeft()
{

}

bool myDisplay::lcdSetCursorPosition()
{

}

cursorPosition myDisplay::lcdGetCursorPosition()
{
	return ;
}

void myDisplay::lcdUpdateCursor()
{
	lcdWriteByteIR(LCD_SETDDR | (cadd -1));
}

#ifdef DEBUG
void lcdWriteByteIR(BYTE by)
{
	std::cout << "IR: " << std::hexa << by << std::endl;
}
void lcdWriteByteDR(BYTE by)
{
	std::cout << "DR: " << std::hexa << by << std::endl;
}
void lcdWriteNibble(BYTE by)
{
	std::cout << "nib " << std::hexa << by << std::endl;
}
#endif // DEBUG