#pragma once
#ifndef RAQUETA_H
#define RAQUETA_H

#include "ObjetoJuego.h"
class Raqueta :
	public ObjetoJuego
{
public:
	Raqueta(Uint32 color, float px, float py, float vy, float ay, float w, float h);
	~Raqueta();
};

#endif
