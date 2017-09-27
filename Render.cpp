#include "Render.h"





Render::Render(ColeccionObjetos objetos) : coleccion(objetos), num_objetos(coleccion.getTamColeccion()) {}

void Render::Pinta()
{
	vector<ObjetoJuego*> mis_objetos=coleccion.getColeccionObjetos();
	for (int i = 0; i < num_objetos; i++)
	{
		int posicionX = mis_objetos[i]->getPosicionX() / 1000.0 *SCREEN_WIDTH;
		int posicionY = mis_objetos[i]->getPosicionY() / 1000.0 * SCREEN_HEIGHT;
	GotoXY( posicionX, posicionY);
	cout << (mis_objetos)[i]->getForma();
	}

}

void Render::GotoXY(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	_COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hConsole, pos);
}


void Render::BorraPantalla()
{
	COORD coordScreen = { 0, 0 }; /* here's where we'll home the cursor */
	BOOL bSuccess;
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi; /* to get buffer info */
	DWORD dwConSize; /* number of character cells in the current buffer */
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	/* get the number of character cells in the current buffer */
	bSuccess = GetConsoleScreenBufferInfo(hConsole, &csbi);
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	/* fill the entire screen with blanks */
	bSuccess = FillConsoleOutputCharacter(hConsole, (TCHAR) ' ',
		dwConSize, coordScreen, &cCharsWritten);
	/* get the current text attribute */
	bSuccess = GetConsoleScreenBufferInfo(hConsole, &csbi);
	/* now set the buffer's attributes accordingly */
	bSuccess = FillConsoleOutputAttribute(hConsole, csbi.wAttributes,
		dwConSize, coordScreen, &cCharsWritten);
	return;
}
