#include <iostream>
#include "myDisplay.h"
#include <string>
#include <thread>
#include <chrono>

int main()
{
	myDisplay dis;	

	if (dis.lcdInitOk() == false) {
		std::cout << "No se pudo inicializar el display" << std::endl;
		return EXIT_FAILURE;
	}

	std::cout << "Bienvenido al adivinador de nombres de vidas pasadas. Para iniciar, presione enter" << std::endl << std::endl;
	while (getchar() != '\n') {}

	dis.lcdClear();	
	dis << "Su nombre...";
	std::this_thread::sleep_for(std::chrono::seconds(1));

	dis.lcdMoveCursorLeft();
	dis.lcdMoveCursorLeft();
	dis.lcdMoveCursorLeft();
	dis.lcdClearToEOL();		//borrar los puntos suspensivos
	dis.lcdMoveCursorRight();	//dejar un espacio
	dis << "fue";	

	dis.lcdSetCursorPosition({ SECOND_ROW, 0 });	//mover el cursor al inicio de la linea de abajo
	dis << 'J' << 'a' << 'c' << 'o' << 'b' << 'o';

	std::this_thread::sleep_for(std::chrono::seconds(1));
	dis.lcdClear();
	dis << "Una reflexion final" << ':';
	std::this_thread::sleep_for(std::chrono::seconds(1));

	dis.lcdClear();

	dis << 'M';
	dis.lcdMoveCursorRight();
	dis << 'u';
	dis.lcdMoveCursorRight();
	dis << 'y';

	cursorPosition namePos = dis.lcdGetCursorPosition();	//guardar la posicion para usarla mas adelante
	
	dis.lcdMoveCursorRight();
	dis.lcdMoveCursorRight();

	dis << 'b';
	dis.lcdMoveCursorRight();
	dis << 'i';
	dis.lcdMoveCursorRight();
	dis << 'e';
	dis.lcdMoveCursorRight();
	dis << 'n';
	dis.lcdMoveCursorRight();
	dis << '!';

	dis.lcdSetCursorPosition(namePos);
	dis.lcdMoveCursorDown();

	const unsigned char mensajeMuyLargo[] = "chau jaco, ahora escribo hasta que no haya lugar";

	dis << mensajeMuyLargo;

	std::cout << "Presione enter para salir" << std::endl << std::endl;
	getchar();
	
	return EXIT_SUCCESS;	
}
