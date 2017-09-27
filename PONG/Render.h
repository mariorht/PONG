#pragma once
#ifndef RENDER_H
#define RENDER_H

#include "Pelota.h"
#include <Windows.h>
#include <SDL.h>
#include "ColeccionObjetos.h"

#define SCREEN_WIDTH  500
#define SCREEN_HEIGHT  500


class Render
{
protected:
	ColeccionObjetos coleccion;
	int num_objetos;
	SDL_Surface *destination;


public:
	Render(ColeccionObjetos objetos, SDL_Surface *d);
	//~Render();

	void Pinta();

	void BorraPantalla();


};







#endif //RENDER_H
