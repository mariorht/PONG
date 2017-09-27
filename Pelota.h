#pragma once
#ifndef PELOTA_H
#define PELOTA_H


#include "ObjetoJuego.h"

class Pelota :public ObjetoJuego
{
protected:

public:
	
	Pelota(float px, float py, float vx, float vy, float ax, float ay, float w, float h, char f);
	//~Pelota();
};




#endif // !PELOTA_H
