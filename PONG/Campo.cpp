#include "Campo.h"



Campo::Campo(Uint32 color, float w, float h)
	:ObjetoJuego(color, 0, 0, 0, 0, 0, 0, ancho, alto, 0) {
	PuedoMeterGol = 0;	
}

float Campo::getAnchoCampo()
{
	return ancho;
}

float Campo::getAltoCampo()
{
	return alto;
}




/*
Campo::~Campo()
{
}
*/

