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

// Tama�o de la pantalla en p�xeles
#define SCREEN_WIDTH  1280
#define SCREEN_HEIGHT 700

// Clase que dibuja los objetos de la colecci�n en la pantalla
class Render
{
protected:
	ColeccionObjetos *coleccion;	// Puntero a la colecci�n de objetos a pintar
	int num_objetos;				// N�mero de objetos de la colecci�n
	SDL_Surface *destination;		// Puntero a la pantalla donde pintar
	SDL_Rect rect;					// Rect�ngulo

	/** Dibuja un rect�ngulo*/
	void DibujaRectangulo(SDL_Surface *image);


public:

	/** Constructor :
	param ColeccionObjetos *objeto : Colecci�n de objetos a pintar
	param SDL_Surface *d : Superficie donde pintar*/
	Render(ColeccionObjetos *objetos, SDL_Surface *d);

	/**Destructor*/
	~Render();


	/** Dibuja todos los objetos de la colecci�n
	param Campo *campo : Puntero al objeto campo*/
	void DibujaTodo(Campo *campo);

	/** Pinta la pantalla de blanco*/
	void BorraPantalla();
	
	/** Escribe un texto
	param Menu menu : Almacena la fuente
	param SDL_Window *window : pantalla donde escribir
	param string texto_escribir : texto a escribir
	param SDL_Color color : color del texto
	param float pos_x : posici�n X donde escribir
	param float pos_y : posici�n Y donde escribir
	param Campo *campo : puntero al objeto campo
	*/
	void Escribe(Menu menu, SDL_Window *window, string texto_escribir, SDL_Color color, float pos_x, float pos_y, Campo *campo);

	/** Vuelca el contenido de la superficie destination en la pantalla
	param SDL_Window *window : pantalla donde se vuelca el contenido*/
	void RefrescaPantalla(SDL_Window *window);


};







#endif //RENDER_H
