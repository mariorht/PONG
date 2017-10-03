#pragma once
#ifndef RENDER_H
#define RENDER_H

#include "Pelota.h"
#include <Windows.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include "ColeccionObjetos.h"

#define SCREEN_WIDTH  600
#define SCREEN_HEIGHT 600


class Render
{
protected:
	ColeccionObjetos coleccion;
	int num_objetos;
	SDL_Surface *destination; //Pantalla donde pintar
	SDL_Surface *image;
	SDL_Rect rect;



public:
	Render(ColeccionObjetos objetos, SDL_Surface *d);
	//~Render();

	void DibujaRectangulo();
	void DibujaTodo();

	void BorraPantalla();

	void Escribe(SDL_Window *window, string texto, SDL_Color color, string fuente, float tam_fuente, float pos_x, float pos_y);


};







#endif //RENDER_H
