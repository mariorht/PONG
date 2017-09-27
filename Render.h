#pragma once
#ifndef RENDER_H
#define RENDER_H

#include "Pelota.h"
#include "ColeccionObjetos.h"
#include <Windows.h>
#include <vector>
#include "ColeccionObjetos.h"



#define SCREEN_WIDTH  80;
#define SCREEN_HEIGHT  30;

class Render
{
protected:
	ColeccionObjetos coleccion;
	int num_objetos;


public:
	Render(ColeccionObjetos coleccion);
	//~Render();

	void GotoXY(int x, int y);
	void Pinta();

	void BorraPantalla();


};







#endif //RENDER_H
