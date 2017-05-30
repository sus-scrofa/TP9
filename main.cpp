#include <iostream>
#include "myDisplay.h"
#include "defines.h"
#include <string>

int main()
{
	myDisplay dis;	
	dis.printDDRAM();

	std::cout << "Bienvenido al adivinador de nombres de vidas pasadas. Para iniciar, presione enter" << std::endl << std::endl;
	while (getchar() != '\n') {}
	dis.lcdClear();	
	dis << "Su nombre...";
	dis.printDDRAM();

	std::cout << "Presione enter para ver su nombre en su vida anterior" << std::endl << std::endl;
	while (getchar() != '\n') {}
	dis.lcdMoveCursorLeft();
	dis.lcdMoveCursorLeft();
	dis.lcdMoveCursorLeft();
	dis.lcdClearToEOL();		//borrar los puntos suspensivos
	dis.lcdMoveCursorRight();	//dejar un espacio
	dis << std::string("fue");	//imprimir "fue"

	dis.lcdSetCursorPosition({ 4, 0 });	//mover el cursor al inicio de la linea de abajo
	dis << 'J' << 'a' << 'c' << 'o' << 'b' << 'o';
	dis.printDDRAM();

	std::cout << "Presione enter para leer una reflexion final" << std::endl << std::endl;

	while (getchar() != '\n') {}
	dis.lcdClear();
	dis.lcdSetCursorPosition({ 0,0 });

	dis.printDDRAM();
	dis << 'M';
	dis.lcdMoveCursorRight();

	while (getchar() != '\n') {}
	dis.printDDRAM();
	dis << 'u';
	dis.lcdMoveCursorRight();

	while (getchar() != '\n') {}
	dis.printDDRAM();
	dis << 'y';

	cursorPosition namePos = dis.lcdGetCursorPosition();	//guardar la posicion para usarla mas adelante
	
	dis.lcdMoveCursorRight();
	dis.lcdMoveCursorRight();

	while (getchar() != '\n') {}
	dis.printDDRAM();
	dis << 'b';
	dis.lcdMoveCursorRight();

	while (getchar() != '\n') {}
	dis.printDDRAM();
	dis << 'i';
	dis.lcdMoveCursorRight();

	while (getchar() != '\n') {}
	dis.printDDRAM();
	dis << 'e';
	dis.lcdMoveCursorRight();

	while (getchar() != '\n') {}
	dis.printDDRAM();
	dis << 'n';
	dis.lcdMoveCursorRight();
	
	while (getchar() != '\n') {}
	dis.printDDRAM();
	dis << '!';
	dis.printDDRAM();

	dis.lcdSetCursorPosition(namePos);
	dis.lcdMoveCursorDown();

	dis << std::string("Chau Jaco");
	dis.printDDRAM();

	std::cout << "Presione enter para salir" << std::endl << std::endl;
	getchar();

}


