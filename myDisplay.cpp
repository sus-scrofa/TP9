#include "myDisplay.h"
#include "defines.h"

#define MAX_S_LEN 32

#define	FIRST_ROW	0	//numero de fila de las dos que se ven en el lcd
#define	SECOND_ROW	4

myDisplay::myDisplay()
{
	cadd = 1;
	lcdInitOk();
	
	for (int i = 0; i < CHARXROW*ROWSXLINE * 2 + 1; i++)
	{
		DDRAM[i] = 'x';
	}

}

myDisplay::~myDisplay()
{
}

bool myDisplay::lcdInitOk()
{
	return true;
}

FT_STATUS myDisplay::lcdGetError()
{
	return FT_OK;
}

bool myDisplay::lcdClear()
{
	lcdWriteByteIR(LCD_CLEAR);	//actualiza el cursor automaticamente, no es necesario llamar a lcdUpdateCursor()
#ifdef DEBUG
	std::cout << "lcdClear()" << std::endl;
	for (int i = 0; i < CHARXROW*ROWSXLINE * 2 + 1; i++)
	{
		DDRAM[i] = ' ';
	}
#endif // DEBUG

	cadd = 1;
	return true;
	//TODO: cuando podria devolver false?
}

bool myDisplay::lcdClearToEOL()	//TODO: cuando podria devolver false?
{
	int oldcadd = cadd;		//se debe mantener la direccion original del cursor
	do
	{	
		lcdWriteByteDR(' ');
	} while (cadd % (CHARXROW + 1));

	cadd = oldcadd;			
	lcdUpdateCursor();		//como cadd volvio a su valor original, el cursor vuelve a la posicion que tenia al inicio
#ifdef DEBUG
	std::cout << "lcdClearTOEOL()" << std::endl;
#endif // DEBUG
	return true;
}

basicLCD & myDisplay::operator<<(const unsigned char c)
{
	lcdWriteByteDR(c);
#ifdef DEBUG
	std::cout << " operator << (" << c << ')' << std::endl;
#endif // DEBUG
	if (getCursorCol() == 0)	// si se cambio de columna, correr el cursor a la otra linea que se muestra
	{
		cursorPosition c = { FIRST_ROW,0 };
		if (getCursorRow() == FIRST_ROW + 1) //si estoy en la fila 1 tengo que ir a la 2da linea, si no a la primera
			c.row = SECOND_ROW;
		lcdSetCursorPosition(c);
	}
	return *this;
}

basicLCD & myDisplay::operator<<(const unsigned char * c)
{
	std::string sentence((const char*)(c));
	unsigned int len = sentence.size();
	if (len > MAX_S_LEN)	//si la longitud excede el limite
	{
		//solamente quedarse con los ultimos MAX_S_LEN caracteres
		sentence.erase(sentence.begin(), sentence.end() - CHARXROW * 2);	
		len = MAX_S_LEN;
	}
	for (int i = 0; i < len; i++)
	{
		lcdWriteByteDR(sentence[i]);

		if (getCursorCol() == 0)	// si se cambio de columna, correr el cursor a la otra linea que se muestra
		{
			cursorPosition c = { FIRST_ROW,0 };
			if (getCursorRow() == FIRST_ROW + 1) //si estoy en la fila 1 tengo que ir a la 2da linea, si no a la primera
				c.row = SECOND_ROW;
			lcdSetCursorPosition(c);
		}
	}
#ifdef DEBUG
	std::cout << " operator << (" << c << ')' << std::endl;
#endif	//DEBUG
	return *this;
}

basicLCD & myDisplay::operator<<(std::string s)
{
	std::string sentence(s);	//copiar el string recibido para poder modificarlo
	unsigned int len = sentence.size();
	
	if (len > MAX_S_LEN)	//si la longitud excede el limite
	{
		//solamente quedarse con los ultimos MAX_S_LEN caracteres
		sentence.erase(sentence.begin(), sentence.end() - CHARXROW * 2);
		len = MAX_S_LEN;
	}
	
	for (int i = 0; i < len; i++)
	{
		lcdWriteByteDR(sentence[i]);
		if (getCursorCol() == 0)	// si se cambio de columna, correr el cursor a la otra linea que se muestra
		{
			cursorPosition c = { FIRST_ROW,0 };
			if (getCursorRow() == FIRST_ROW + 1) //si estoy en la fila 1 tengo que ir a la 2da linea, si no a la primera
				c.row = SECOND_ROW;
			lcdSetCursorPosition(c);
		}
	}

	// TODO: insert return statement here
#ifdef DEBUG
	std::cout << " operator << (" << sentence << ')' << std::endl;
#endif	//DEBUG
	return *this;
}

bool myDisplay::lcdMoveCursorUp()
{
#ifdef DEBUG
	std::cout << "lcdMoveCursorUp()" << std::endl;
#endif // DEBUG

	//Mover solamente si no se encuentra en la primera fila
	if (getCursorRow())	
	{
		if (!(cadd %= CHARXROW))	//si se encuentra en la ultima columna, cadd va a ser 0 cuando en realidad deberia ser CHARXROW
		{
			cadd = CHARXROW;
		}
		lcdUpdateCursor();
		return true;
	}
	else
	{
		return false;
	}
}

bool myDisplay::lcdMoveCursorDown()
{
#ifdef DEBUG
	std::cout << "lcdMoveCursorDown()" << std::endl;
#endif // DEBUG

	//Mover solamente si no se encuentra en la ultima fila
	if (getCursorRow() != ROWSXLINE)
	{
		if (!(cadd %= CHARXROW))	
		{
			cadd += CHARXROW;		// si se encuentra en la ultima columna, cadd va a ser 0 cuando en realidad deberia ser CHARXROW
		}
		cadd += CHARXROW*ROWSXLINE;
		lcdUpdateCursor();
		return true;
	}
	else
	{
		return false;
	}
}

bool myDisplay::lcdMoveCursorRight()
{
#ifdef DEBUG
	std::cout << "lcdMoveCursorRight()" << std::endl;
#endif // DEBUG

	//Mover solamente si no se encuentra en la ultima columna
	if (getCursorCol() < CHARXROW - 1)
	{
		cadd++;
		lcdUpdateCursor();
		return true;
	}
	else
	{
		return false;
	}
}

bool myDisplay::lcdMoveCursorLeft()
{	
#ifdef DEBUG
	std::cout << "lcdMoveCursorLeft()" << std::endl;
#endif // DEBUG
	//Mover solamente si no se encuentra en la primer columna
	if (getCursorCol())	
	{
		cadd--;
		lcdUpdateCursor();
		return true;
	}
	else
	{
		return false;
	}
}

bool myDisplay::lcdSetCursorPosition(const cursorPosition pos)
{
	if (pos.column<CHARXROW && pos.column>=0 && (pos.row==4 || pos.row==0))
	//solo se puede mover el cursor a las posiciones que se muestran
	{
		cadd = pos.column + pos.row*CHARXROW + 1;
		lcdUpdateCursor();

		return true;
	}
	else
		return false;
}

cursorPosition myDisplay::lcdGetCursorPosition()
{
	cursorPosition pos = { cadd / CHARXROW , cadd % CHARXROW };

	return pos;
}

void myDisplay::lcdUpdateCursor()
{
	lcdWriteByteIR(LCD_SETDDR | cadd - 1);	//TODO: borrar magic number
}

int myDisplay::getCursorRow()
{
	return (int)((cadd - 1) / CHARXROW);
}

int myDisplay::getCursorCol()
{
	return ((cadd - 1) % 0x10);
}

#ifdef DEBUG
void myDisplay::printDDRAM()
{
	for (int i = 1; i <= CHARXROW*ROWSXLINE * 2; i++)
	{
		std::cout << "| " << ((i == cadd) ? (char)2 : (char)DDRAM[i]) << ' ';

		if (!(i % CHARXROW))
		{
			std::cout << '|' << std::endl;
		}
	}
}
void myDisplay::lcdWriteByteIR(BYTE by)
{
//	printf("\nIR: %X\n", by);
}
void myDisplay::lcdWriteByteDR(BYTE by)
{
	DDRAM[cadd] = by;
	if (cadd < (CHARXROW*ROWSXLINE * 2))
	{
		cadd++;			//si no se esta en la ultima posicion (NOTA 1) //TODO: rechequear nota 1 porque estoy dormida
	}
}
#endif // DEBUG
