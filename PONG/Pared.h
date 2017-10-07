#pragma once
#ifndef PARED_H
#define PARED_H

#include "ObjetoJuego.h"

// Clase heredada de ObjetoJuego que define una pared
class Pared :
	public ObjetoJuego
{

protected:
public:

	/**Constructor: 
	param Uint32 color : color del objeto
	param float px : posici�n X del objeto
	param float py : posici�n Y del objeto
	param float w : ancho del objeto
	param float h : alto del objeto
	param Campo *mi_campo : puntero al objeto campo
	param bool atravesado : indica si el objeto puede ser atravesado*/
	Pared(Uint32 color, float px, float py, float w, float h, Campo *mi_campo, bool atravesado);


};

#endif
