#pragma once
#ifndef CAMPO_H
#define CAMPO_H

#define SCREEN_WIDTH  1280
#define SCREEN_HEIGHT 700

class Campo 
{
protected:
	float ancho;
	float alto;
	float pos_porteria_izq;
	float pos_porteria_dcha;
	
public:
	Campo(float w, float h);
	//~Campo();
	float getAnchoCampo();
	float getAltoCampo();
	float getPosPorteriaIzq();
	float getPosPorteriaDcha();
};


#endif