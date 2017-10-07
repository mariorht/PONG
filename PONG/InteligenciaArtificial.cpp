#include "InteligenciaArtificial.h"



InteligenciaArtificial::InteligenciaArtificial(Raqueta* r)
{
	mi_raqueta = r;
}



void InteligenciaArtificial::EligeMovimiento(ObjetoJuego * p)
{
	// Distancia entra la raqueta y la pelota
	float distanciaY = p->getPosicionY() - (mi_raqueta->getPosicionY() + mi_raqueta->getAlto() / 2);
	float distanciaX = p->getPosicionX() - mi_raqueta->getPosicionX();

	// Distancia entre la raqueta y el centro del campo
	float distancia_con_centro = 500 - (mi_raqueta->getPosicionY() + mi_raqueta->getAlto() / 2);

	// Si la pelota está cerca de la raqueta, ésta sigue la pelota
	if (abs(distanciaX)<500)
	{
		if (distanciaY > mi_raqueta->getAlto() / 2)
			mi_raqueta->setAceleracionY(2);

		if (-distanciaY > mi_raqueta->getAlto() / 2)
			mi_raqueta->setAceleracionY(-2);
		if(abs(distanciaY) < mi_raqueta->getAlto()/2)
			mi_raqueta->setAceleracionY(0);

	}

	// Si está lejos, se lleva la raqueta al centro
	else
	{
		
		if (distancia_con_centro >  mi_raqueta->getAlto() / 2)
			mi_raqueta->setAceleracionY(0.25);
		if (-distancia_con_centro >  mi_raqueta->getAlto() / 2)
			mi_raqueta->setAceleracionY(-0.25);
		if (abs(distancia_con_centro) <  mi_raqueta->getAlto() / 2)
			mi_raqueta->setAceleracionY(-mi_raqueta->getRozamiento()*
										mi_raqueta->getVelocidadY());
	}
}
