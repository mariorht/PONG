#include "InteligenciaArtificial.h"



InteligenciaArtificial::InteligenciaArtificial(Raqueta* r)
{
	mi_raqueta = r;
}


InteligenciaArtificial::~InteligenciaArtificial()
{
}


void InteligenciaArtificial::EligeMovimiento(ObjetoJuego * p)
{

	float distanciaY = p->getPosicionY() - (mi_raqueta->getPosicionY() + mi_raqueta->getAlto() / 2);
	float distanciaX = p->getPosicionX() - mi_raqueta->getPosicionX();

	float distancia_con_centro = 500 - (mi_raqueta->getPosicionY() + mi_raqueta->getAlto() / 2);
	if (distanciaX<500)
	{
		if (distanciaY > mi_raqueta->getAlto() / 2)
			mi_raqueta->setAceleracionY(2);

		if (-distanciaY > mi_raqueta->getAlto() / 2)
			mi_raqueta->setAceleracionY(-2);
		if(abs(distanciaY) < mi_raqueta->getAlto()/2)
			mi_raqueta->setAceleracionY(0);

	}

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
