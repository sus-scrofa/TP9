#include <iostream>
#include "myDisplay.h"
#include <string>
#include <thread>
#include <chrono>

int main()
{
	myDisplay dis;	
//	dis.printDDRAM();

	std::cout << "Bienvenido al adivinador de nombres de vidas pasadas. Para iniciar, presione enter" << std::endl << std::endl;
	while (getchar() != '\n') {}

	dis.lcdClear();	
	dis << "Su nombre...";
//	dis.printDDRAM();
	std::this_thread::sleep_for(std::chrono::seconds(1));

	dis.lcdMoveCursorLeft();
	dis.lcdMoveCursorLeft();
	dis.lcdMoveCursorLeft();
	dis.lcdClearToEOL();		//borrar los puntos suspensivos
	dis.lcdMoveCursorRight();	//dejar un espacio
	dis << "fue";	

	dis.lcdSetCursorPosition({ SECOND_ROW, 0 });	//mover el cursor al inicio de la linea de abajo
	dis << 'J' << 'a' << 'c' << 'o' << 'b' << 'o';
//	dis.printDDRAM();

	std::this_thread::sleep_for(std::chrono::seconds(1));
	dis.lcdClear();
	dis << "Una reflexion final" << ':';
	std::this_thread::sleep_for(std::chrono::seconds(1));

	dis.lcdClear();

//	dis.printDDRAM();

	dis << 'M';
	dis.lcdMoveCursorRight();

//	dis.printDDRAM();
	dis << 'u';
	dis.lcdMoveCursorRight();

//	dis.printDDRAM();
	dis << 'y';

	cursorPosition namePos = dis.lcdGetCursorPosition();	//guardar la posicion para usarla mas adelante
	
	dis.lcdMoveCursorRight();
	dis.lcdMoveCursorRight();

//	dis.printDDRAM();
	dis << 'b';
	dis.lcdMoveCursorRight();

//	dis.printDDRAM();
	dis << 'i';
	dis.lcdMoveCursorRight();

//	dis.printDDRAM();
	dis << 'e';
	dis.lcdMoveCursorRight();

//	dis.printDDRAM();
	dis << 'n';
	dis.lcdMoveCursorRight();
	
//	dis.printDDRAM();
	dis << '!';
//	dis.printDDRAM();

	dis.lcdSetCursorPosition(namePos);
	dis.lcdMoveCursorDown();

	const unsigned char mensajeMuyLargo[] = "chau jaco, ahora escribo hasta que no haya lugar";

	dis << mensajeMuyLargo;
//	dis.printDDRAM();

	std::cout << "Presione enter para salir" << std::endl << std::endl;
	getchar();
	
	return EXIT_SUCCESS;	
}




//using namespace std;
//#include <thread>
//#include <chrono>
//int main(void)
//{
//	//Se continua a realizar pruebas sobre las funciones de la clase basicLCD.
//
//	myDisplay display; //creamos objeto.
//
//					  //string mens ("HELLO WORLD!!"); //Como se explica en el .h, esta funcion es para customizar y debe estar en private pero asi no se puede acceder desde aqui.
//					  //display.lcdWriteString(mens);
//	if (display.lcdInitOk() == false)
//	{
//		std::cout << "The display could not be initialized" << std::endl;
//		display.lcdClear();
//	}
//	else // No se realizo control de error en cada una de las funciones por un tema de hacer mas amena la lectura de main pero se podria hacer con los returns values y lcdGetError
//	{
//
//		cout << "Lets send a message with the overload operator" << endl;
//		display << 'I' << ' ' << 'L' << ' O' << 'V' << 'E' << ' ' << 'E' << 'D' << 'A';
//		this_thread::sleep_for(chrono::seconds(1));
//
//		cout << "Lets clean the screen" << endl;
//		display.lcdClear();
//		this_thread::sleep_for(chrono::seconds(1));
//
//		cout << "Lets send a new message" << endl;
//		display << 'L' << 'C' << 'D';
//		this_thread::sleep_for(chrono::seconds(1));
//
//		cout << "Lets move the cursor down" << endl;
//		display.lcdMoveCursorDown();
//		this_thread::sleep_for(chrono::seconds(1));
//
//		cout << "And complete the message" << endl;
//		display << 'D' << 'I' << 'S' << 'P' << 'L' << 'A' << 'Y';
//		this_thread::sleep_for(chrono::seconds(1));
//
//		cout << "What happens if we want to go more below" << endl;
//		display.lcdMoveCursorDown();
//		this_thread::sleep_for(chrono::seconds(1));
//
//		cout << "Or up" << endl;
//		display.lcdMoveCursorUp();
//		display.lcdMoveCursorUp();
//		this_thread::sleep_for(chrono::seconds(1));
//
//		cout << "Lets send the final message with the overload operator" << endl;
//		display << 'B' << 'Y' << 'E' << ' ' << 'B' << 'Y' << 'E';
//		this_thread::sleep_for(chrono::seconds(1));
//
//		cout << "But clean de line" << endl;
//		display.lcdClearToEOL();
//		this_thread::sleep_for(chrono::seconds(1));
//
//		cout << "Now the destructor will be called and will clean the screen" << endl;
//		display.lcdClear();
//		display << 'N' << 'O' << ' ' << 'M' << 'E' << ' ' << 'M' << 'A' << 'T' << 'E' << 'S' << ' ' << 'T' << 'E' << 'N' << 'G' << 'O' << ' ' << 'F' << 'A' << 'M' << 'I' << 'L' << 'I' << 'A' << ' ' << 'D' << ':';
//		this_thread::sleep_for(chrono::seconds(1));
//		display.lcdClear();
//		display << 'A' << 'H' << 'H' << 'H' << 'H' << 'H' << 'H' << 'H' << 'H' << 'H' << 'H' << 'H' << 'H' << 'H' << 'H' << 'H';
//
//
//	}
//
//	return 0;
//}