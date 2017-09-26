#include "Render.h"



Render::Render(vector<Pelota> *pelota, SDL_Surface *d)
{
	mi_pelota = pelota;
	num_objetos = (*pelota).size();
	destination = d;
}

void Render::Pinta()
{
	for (int i = 0; i < num_objetos; i++)
	{
		int posicionX = (*mi_pelota)[i].getPosicionX() / 1000.0 *SCREEN_WIDTH;
		int posicionY = (*mi_pelota)[i].getPosicionY() / 1000.0 * SCREEN_HEIGHT;

		(*mi_pelota)[i].rect.x = posicionX;
		(*mi_pelota)[i].rect.y = posicionY;
	
		(*mi_pelota)[i].Dibuja(destination);
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
	SDL_FillRect(destination, NULL, SDL_MapRGB(destination->format, 0xFF, 0xFF, 0xFF));
}
