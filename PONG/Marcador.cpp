#include "Marcador.h"




Marcador::Marcador(int goles_A, int goles_B) 
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
