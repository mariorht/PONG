#pragma once
#ifndef RENDER_H
#define RENDER_H

#include "Pelota.h"
#include <Windows.h>
#include <vector>


#define SCREEN_WIDTH  80;
#define SCREEN_HEIGHT  30;

class Render
{
protected:
	vector<Pelota> *mi_pelota;
	int num_objetos;


public:
	Render(vector<Pelota> *pelota);
	//~Render();

	void GotoXY(int x, int y);
	void Pinta();

	void BorraPantalla();


};







#endif //RENDER_H
