#pragma once
#ifndef PARED_H
#define PARED_H

#include "ObjetoJuego.h"

class Pared :
	public ObjetoJuego
{
protected:
public:
	Pared(Uint32 color, float px, float py, float w, float h, Campo *mi_campo, bool atravesado);
	~Pared();

};

#endif
