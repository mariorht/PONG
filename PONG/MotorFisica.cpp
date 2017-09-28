#include "MotorFisica.h"



MotorFisica::MotorFisica(ColeccionObjetos objetos) : coleccion(objetos),
	num_objetos(coleccion.getTamColeccion()) {}


void MotorFisica::Mueve(ObjetoJuego &obj)
{
	float px, py;
	px = obj.getPosicionX();
	py = obj.getPosicionY();

	float vx, vy;
	vx = obj.getVelocidadX();
	vy = obj.getVelocidadY();

	float ax, ay;
	ax = obj.getAceleracionX();
	ay = obj.getAceleracionY();

	vx += ax;
	vy += ay;

	obj.setVelocidadX(vx);
	obj.setVelocidadY(vy);
	obj.setPosicion(px + vx, py + vy);
}

void MotorFisica::Actualiza(int tecla)
{
	vector<ObjetoJuego*> mis_objetos = coleccion.getColeccionObjetos();
	for (int i = 0; i < num_objetos; i++)
	{
		if (mis_objetos[i]->getAfectadoPorPulsacion())
		{
			if (tecla == ARRIBA)
				mis_objetos[i]->setAceleracionY(-10.0);
			else if (tecla == ABAJO)
				mis_objetos[i]->setAceleracionY(+10.0);
			else
			{
				float roz = mis_objetos[i]->getRozamiento();
				float vy = mis_objetos[i]->getVelocidadY();

				mis_objetos[i]->setAceleracionY(-roz*vy);
			}
		}

		else
		{
			int px, py;
			px = mis_objetos[i]->getPosicionX();
			py = mis_objetos[i]->getPosicionY();

			float roz = mis_objetos[i]->getRozamiento();

			int vx, vy;
			vx = mis_objetos[i]->getVelocidadX();
			vy = mis_objetos[i]->getVelocidadY();

			int ax, ay;
			ax = mis_objetos[i]->getAceleracionX();
			ay = mis_objetos[i]->getAceleracionY();
			

			if (px >= (1000 - 100) || px <= (1))
				mis_objetos[i]->setVelocidadX(-mis_objetos[i]->getVelocidadX());

			if (py >= (1000 - 100) || py <= (1))
				mis_objetos[i]->setVelocidadY(-mis_objetos[i]->getVelocidadY());

		}

		Mueve(*mis_objetos[i]);
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

