#include "Campo.h"



Campo::Campo(float w, float h)
{
	ancho = w;
	alto = h;
	pos_porteria_izq = ancho*0.03;
	pos_porteria_dcha = ancho - ancho*0.03;
}

float Campo::getAnchoCampo()
{
	return ancho;
}

float Campo::getAltoCampo()
{
	return alto;
}

float Campo::getPosPorteriaIzq() 
{
	return pos_porteria_izq;
}

float Campo::getPosPorteriaDcha()
{
	return pos_porteria_dcha;
}


/*
Campo::~Campo()
{
}
*/

