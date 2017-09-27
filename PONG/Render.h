#pragma once
#ifndef RENDER_H
#define RENDER_H

#include "Pelota.h"
#include <Windows.h>
#include <vector>
#include <SDL.h>

#define SCREEN_WIDTH  500
#define SCREEN_HEIGHT  500


class Render
{
protected:
	vector<Pelota> *mi_pelota;
	int num_objetos;
	SDL_Surface *destination;


public:
	Render(vector<Pelota> *pelota, SDL_Surface *d);
	//~Render();

	void GotoXY(int x, int y);
	void Pinta();

	void BorraPantalla();


};







#endif //RENDER_H
