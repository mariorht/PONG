#include "MotorFisica.h"



MotorFisica::MotorFisica(Pelota *pelota): mi_pelota(pelota) {}

void MotorFisica::Actualiza()
{
	int px, py;
	px = mi_pelota->getPosicionX();
	py = mi_pelota->getPosicionY();



	if (px >= (80 - 1))
		mi_pelota->setVelocidadX(-3);

	if (px <= (1))
		mi_pelota->setVelocidadX(3);

	if (py >= (40 - 1))
		mi_pelota->setVelocidadY(-2);

	if (py <= (1))
		mi_pelota->setVelocidadY(2);


	mi_pelota->setPosicion(mi_pelota->getPosicionX() + mi_pelota->getVelocidadX(),
		mi_pelota->getPosicionY() + mi_pelota->getVelocidadY());
}

