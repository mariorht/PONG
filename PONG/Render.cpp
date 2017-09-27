#include "Render.h"



Render::Render(ColeccionObjetos objetos, SDL_Surface *d)
{
	coleccion = objetos;
	num_objetos = coleccion.getTamColeccion();
	destination = d;
}

void Render::DibujaTodo()
{
	vector<ObjetoJuego*> mis_objetos = coleccion.getColeccionObjetos();
	for (int i = 0; i < num_objetos; i++)
	{
		int posicionX = mis_objetos[i]->getPosicionX() / 1000.0 *SCREEN_WIDTH;
		int posicionY = mis_objetos[i]->getPosicionY() / 1000.0 * SCREEN_HEIGHT;

		float w = mis_objetos[i]->getAncho() / 1000.0 *SCREEN_WIDTH;
		float h = mis_objetos[i]->getAlto() / 1000.0 *SCREEN_WIDTH;

		image = SDL_CreateRGBSurface(0, w * SCREEN_WIDTH / 1000, h * SCREEN_HEIGHT / 1000, 32, 0, 0, 0, 0);

		SDL_FillRect(image, NULL, mis_objetos[i]->getColor());
		rect = image->clip_rect;

		rect.x = posicionX;
		rect.y = posicionY;


		DibujaRectangulo();
	}

}

void Render::DibujaRectangulo()
{
	SDL_BlitSurface(image, NULL, destination, &rect);
}



void Render::BorraPantalla()
{
	SDL_FillRect(destination, NULL, SDL_MapRGB(destination->format, 0xFF, 0xFF, 0xFF));
}
