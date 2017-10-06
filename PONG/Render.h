#pragma once
#ifndef RENDER_H
#define RENDER_H

#include "Pelota.h"
#include <Windows.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include "ColeccionObjetos.h"
#include "Menu.h"
#include "Campo.h"

#define SCREEN_WIDTH  1280
#define SCREEN_HEIGHT 700


class Render
{
protected:
	ColeccionObjetos *coleccion;
	int num_objetos;
	SDL_Surface *destination; //Pantalla donde pintar
	SDL_Surface *image;
	SDL_Rect rect;



public:
	Render(ColeccionObjetos *objetos, SDL_Surface *d);
	//~Render();

	void DibujaRectangulo();
	void DibujaTodo(Campo *campo);

	void BorraPantalla();


	void Escribe(Menu menu, SDL_Window *window, string texto_escribir, SDL_Color color, float pos_x, float pos_y, Campo *campo);


};







#endif //RENDER_H
