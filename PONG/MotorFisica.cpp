#include "MotorFisica.h"



MotorFisica::MotorFisica(ColeccionObjetos objetos) : coleccion(objetos),
	num_objetos(coleccion.getTamColeccion()) {}

void MotorFisica::Actualiza(int tecla)
{
	vector<ObjetoJuego*> mis_objetos = coleccion.getColeccionObjetos();
	for (int i = 0; i < num_objetos; i++)
	{
		if (mis_objetos[i]->getAfectadoPorPulsacion())
		{
			
			if (tecla == ARRIBA)
				mis_objetos[i]->setVelocidadY(-15.0);
			else if (tecla == ABAJO)
				mis_objetos[i]->setVelocidadY(+15.0);
			

			mis_objetos[i]->setPosicion(mis_objetos[i]->getPosicionX() + mis_objetos[i]->getVelocidadX(),
				mis_objetos[i]->getPosicionY() + mis_objetos[i]->getVelocidadY());
		}

		else
		{
			int px, py;
			px = mis_objetos[i]->getPosicionX();
			py = mis_objetos[i]->getPosicionY();

			if (px >= (1000 - 10) || px <= (1))
				mis_objetos[i]->setVelocidadX(-mis_objetos[i]->getVelocidadX());

			if (py >= (1000 - 10) || py <= (1))
				mis_objetos[i]->setVelocidadY(-mis_objetos[i]->getVelocidadY());


			mis_objetos[i]->setPosicion(mis_objetos[i]->getPosicionX() + mis_objetos[i]->getVelocidadX(),
				mis_objetos[i]->getPosicionY() + mis_objetos[i]->getVelocidadY());
		}
	}

	/*for (int i = 0; i < num_objetos; i++)
	{
		for (int j = i+1; j < num_objetos-i; j++)
		{
			if (abs((mis_objetos[i]->getPosicionX() - mis_objetos[j]->getPosicionX())< 1) &&
				abs((mis_objetos[i]->getPosicionY() - mis_objetos[j]->getPosicionY()) <1))
			{
				mis_objetos[i]->setVelocidadX(-mis_objetos[i]->getVelocidadX());
				mis_objetos[j]->setVelocidadX(-mis_objetos[j]->getVelocidadX());

				mis_objetos[i]->setVelocidadY(-mis_objetos[i]->getVelocidadY());
				mis_objetos[j]->setVelocidadY(-mis_objetos[j]->getVelocidadY());
			}
		}
	}
	*/
}

