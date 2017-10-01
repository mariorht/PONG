#pragma once

#ifndef MARCADOR_H
#define MARCADOR_H

#include "ObjetoJuego.h"

class Marcador : public ObjetoJuego
{
protected:
	int goles_A=0, goles_B=0;

public:
	Marcador(Uint32 color, float px, float py, float w, float h, int goles_A, int goles_B);
	~Marcador();
	 
	void AumentaGolA();
	void AumentaGolB();
	int getGolesA();
	int getGolesB();


};

#endif
