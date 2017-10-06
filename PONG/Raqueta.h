#pragma once
#ifndef RAQUETA_H
#define RAQUETA_H

#include "ObjetoJuego.h"
class Raqueta :	public ObjetoJuego
{
	
public:
	bool ControladoPorIA;
	float V_max;


	Raqueta(Uint32 color, float px, float py, float vy, float ay, float w, float h, float roz, Campo *mi_campo);
	~Raqueta();

	void setPosicionY(float);
	void setVelocidadX(float);
	void setVelocidadY(float);
	void setIAoff();
	void setIAon();
};

#endif
