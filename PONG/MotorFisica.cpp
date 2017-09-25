#include "MotorFisica.h"



MotorFisica::MotorFisica(vector<Pelota> * pelota): mi_pelota(pelota), 
	num_objetos((*pelota).size()) {}

void MotorFisica::Actualiza()
{
	for (int i = 0; i < num_objetos; i++)
	{
		int px, py;
		px = (*mi_pelota)[i].getPosicionX();
		py = (*mi_pelota)[i].getPosicionY();

		if (px >= (40 - 1)  || px <= (1))
			(*mi_pelota)[i].setVelocidadX(-(*mi_pelota)[i].getVelocidadX());

		if (py >= (20 - 1) || py <= (1))
			(*mi_pelota)[i].setVelocidadY(-(*mi_pelota)[i].getVelocidadY());


		(*mi_pelota)[i].setPosicion((*mi_pelota)[i].getPosicionX() + (*mi_pelota)[i].getVelocidadX(),
			(*mi_pelota)[i].getPosicionY() + (*mi_pelota)[i].getVelocidadY());
	}

	for (int i = 0; i < num_objetos; i++)
	{
		for (int j = i; j < num_objetos-i; j++)
		{
			if (abs(((*mi_pelota)[i].getPosicionX() - (*mi_pelota)[j].getPosicionX())< 2) &&
				abs(((*mi_pelota)[i].getPosicionY() - (*mi_pelota)[j].getPosicionY()) <2) )
			{
				(*mi_pelota)[i].setVelocidadX(-(*mi_pelota)[i].getVelocidadX());
				(*mi_pelota)[j].setVelocidadX(-(*mi_pelota)[j].getVelocidadX());

				(*mi_pelota)[i].setVelocidadY(-(*mi_pelota)[i].getVelocidadY());
				(*mi_pelota)[j].setVelocidadY(-(*mi_pelota)[j].getVelocidadY());
			}
		}
	}
}

