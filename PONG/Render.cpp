#include "Render.h"



Render::Render(ColeccionObjetos objetos, SDL_Surface *d)
{
	coleccion = objetos;
	num_objetos = coleccion.getTamColeccion();
	destination = d;
}

void Render::Pinta()
{
	vector<ObjetoJuego*> mis_objetos = coleccion.getColeccionObjetos();
	for (int i = 0; i < num_objetos; i++)
	{
		int posicionX = mis_objetos[i]->getPosicionX() / 1000.0 *SCREEN_WIDTH;
		int posicionY = mis_objetos[i]->getPosicionY() / 1000.0 * SCREEN_HEIGHT;

		
		mis_objetos[i]->rect.x = posicionX;
		mis_objetos[i]->rect.y = posicionY;
				

		mis_objetos[i]->Dibuja(destination);
	}

}




void Render::BorraPantalla()
{
	SDL_FillRect(destination, NULL, SDL_MapRGB(destination->format, 0xFF, 0xFF, 0xFF));
}
