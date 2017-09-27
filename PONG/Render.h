#pragma once
#ifndef RENDER_H
#define RENDER_H

#include "Pelota.h"
#include <Windows.h>
#include <SDL.h>
#include "ColeccionObjetos.h"

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT  480


class Render
{
protected:
	ColeccionObjetos coleccion;
	int num_objetos;
	SDL_Surface *destination;
	SDL_Surface *image;
	SDL_Rect rect;


public:
	Render(ColeccionObjetos objetos, SDL_Surface *d);
	//~Render();

	void DibujaRectangulo();
	void DibujaTodo();

	void BorraPantalla();


};







#endif //RENDER_H
