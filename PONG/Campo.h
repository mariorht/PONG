#pragma once
#ifndef CAMPO_H
#define CAMPO_H

#include "ObjetoJuego.h"



class Campo : public ObjetoJuego
{
protected:
	float ancho;
	float alto;
	
public:
	Campo(Uint32 color, float w, float h);
	//~Campo();
	float getAnchoCampo();
	float getAltoCampo();
};


#endif