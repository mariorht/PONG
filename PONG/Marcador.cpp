#include "Marcador.h"




Marcador::Marcador(Uint32 color, float px, float py, float w, float h, int goles_A, int goles_B)
	:ObjetoJuego(color, px, py, 0, 0, 0, 0, w, h, 0) {
	PuedoMeterGol = 0;
}



Marcador::~Marcador()
{
}

void Marcador::AumentaGolA()
{
	goles_A++;
}

void Marcador::AumentaGolB()
{
	goles_B++;
}

int Marcador::getGolesA()
{
	return goles_A;
}

int Marcador::getGolesB()
{
	return goles_B;
}
