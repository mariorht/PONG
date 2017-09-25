#pragma once
#ifndef RENDER_H
#define RENDER_H

#include "Pelota.h"
#include <Windows.h>

class Render
{
protected:
	Pelota *mi_pelota;


public:
	Render(Pelota *pelota);
	//~Render();

	void GotoXY(int x, int y);
	void Pinta();

	void BorraPantalla();

};







#endif //RENDER_H
