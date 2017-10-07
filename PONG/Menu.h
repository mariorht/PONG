#pragma once
#ifndef MENU_H
#define MENU_H

#include <string>
#include <iostream>

#include <SDL.h>
#include <SDL_ttf.h>

// Tamaño de la ventana en píxeles
#define SCREEN_WIDTH  1280
#define SCREEN_HEIGHT 700


using namespace std;

// Clase que carga y almacena la fuente para escribir
class Menu
{
protected:
	TTF_Font *fuente; // Fuente

	/** Carga la fuente
	param string tipo_fuente : ruta al archivo de la fuente
	float tam_fuente : Tamaño de la fuente*/
	TTF_Font *CargarFuente(string tipo_fuente, float tam_fuente); 
	

public:
	/** Constructor
	param string tipo_fuente : ruta al archivo de la fuente
	float tam_fuente : Tamaño de la fuente
	SDL_Window *window : ventana donde se escribe*/
	Menu(string tipo_fuente, float tam_fuente, SDL_Window *window);

	/** Destructor que cierra la fuente*/
	~Menu();

	/** Devuelve la fuente*/
	TTF_Font *GetFuente();

};

#endif