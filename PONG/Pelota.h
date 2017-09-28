#pragma once
#ifndef PELOTA_H
#define PELOTA_H


#include "ObjetoJuego.h"


class Pelota:public ObjetoJuego
{
protected:

public:
	
	Pelota(Uint32 color, float px, float py, float vx, float vy, float ax, float ay, float w, float h, float roz);
	//~Pelota();
};




#endif // !PELOTA_H
