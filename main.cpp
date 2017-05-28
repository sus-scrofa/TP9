#include <cstdio>
#include "myDisplay.h"
#include "defines.h"


int main()
{
	myDisplay* display = new myDisplay;
	display->printDDRAM();
	display->lcdMoveCursorRight();
	display->printDDRAM();

	const unsigned char str[] = "EN EDA NADA ANDA";
	std::string s ("AHORA SOY STD::STRING");

	*display << &str[0];
	display->printDDRAM();
	*display << s;
	display->printDDRAM();
	display->lcdMoveCursorDown();
	display->printDDRAM();

	system("pause");
}


