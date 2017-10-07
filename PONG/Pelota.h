#pragma once
#ifndef PELOTA_H
#define PELOTA_H


#include "ObjetoJuego.h"

//Clase heredada de ObjetoJuego que define una pelota
class Pelota:public ObjetoJuego
{
protected:

public:
	
	/**Constructor:
	param Uint32 color : color del objeto
	param float px : posición X del objeto
	param float py : posición Y del objeto
	param float vx : velocidad X del objeto
	param float vy : velocidad Y del objeto
	param float ax : aceleración X del objeto
	param float ay : aceleración y del objeto
	param float r : radio del objeto
	param float roz : coeficiente de rozamiento
	param Campo *mi_campo : puntero al objeto campo*/
	Pelota(Uint32 color, float px, float py, float vx, float vy, float ax, float ay, float r, float roz, Campo *mi_campo);
	
};




#endif // !PELOTA_H
