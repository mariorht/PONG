#pragma once
#ifndef JUEGO_H
#define JUEGO_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>

using namespace std;

class Juego
{
protected:
	SDL_Window* window;
	SDL_Surface* screen;
public:
	Juego();
	~Juego();
	int Inicializar();
};

#endif