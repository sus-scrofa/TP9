#include <cstdio>
#include "myDisplay.h"
#include "defines.h"


int main()
{
	myDisplay* display = new myDisplay;
	display->printDDRAM();
	display->lcdMoveCursorRight();
	display->printDDRAM();

	const char * str = "EN EDA NADA ANDA";

	*display << (const unsigned char)str;
	display->printDDRAM();
	display->lcdMoveCursorDown();
	display->printDDRAM();

	getchar();
}


