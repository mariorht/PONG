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
		for (int j = i + 1; j < num_objetos; j++)
		{
			int colision = DetectaColision(*mis_objetos[i], *mis_objetos[j]);
			if (colision == RebotaArriba ||
				colision ==  RebotaAbajo)
			{
				//mis_objetos[i]->setVelocidadX(-mis_objetos[i]->getVelocidadX());
				//mis_objetos[j]->setVelocidadX(-mis_objetos[j]->getVelocidadX());
				if (mis_objetos[i]->AfectadoPorChoque)
				{
					mis_objetos[i]->setVelocidadY(- mis_objetos[i]->getVelocidadY());
					
					
				}

				if (mis_objetos[j]->AfectadoPorChoque)
				{
					mis_objetos[j]->setVelocidadY(- mis_objetos[j]->getVelocidadY());
					
				}
				
			}

			else if (colision == RebotaIzquierda ||
				colision == RebotaDerecha)
			{
				if (mis_objetos[i]->AfectadoPorChoque)
					mis_objetos[i]->setVelocidadX(-mis_objetos[i]->getVelocidadX());
				if (mis_objetos[j]->AfectadoPorChoque)
					mis_objetos[j]->setVelocidadX(-mis_objetos[j]->getVelocidadX());

				//mis_objetos[i]->setVelocidadY(-mis_objetos[i]->getVelocidadY());
				//mis_objetos[j]->setVelocidadY(-mis_objetos[j]->getVelocidadY());
			}
		}
	}

	for (int i = 0; i < num_objetos; i++)
	{
		if (mis_objetos[i]->getAfectadoPorPulsacion())
		{
			if (tecla == ARRIBA)
				mis_objetos[i]->setAceleracionY(-5.0);
			else if (tecla == ABAJO)
				mis_objetos[i]->setAceleracionY(+5.0);
			else
			{
				float roz = mis_objetos[i]->getRozamiento();
				float vy = mis_objetos[i]->getVelocidadY();

				mis_objetos[i]->setAceleracionY(-roz*vy);
			}
		}

		Mueve(*mis_objetos[i]);
		
	}


}

int MotorFisica::DetectaColision(ObjetoJuego o1, ObjetoJuego o2)
{
	float borde_izq_o1, borde_dcho_o1, borde_arriba_o1, borde_abajo_o1;
	borde_izq_o1 = o1.getPosicionX();
	borde_dcho_o1 = borde_izq_o1 + o1.getAncho();
	borde_arriba_o1 = o1.getPosicionY();
	borde_abajo_o1 = borde_arriba_o1 + o1.getAlto();

	float borde_izq_o2, borde_dcho_o2, borde_arriba_o2, borde_abajo_o2;
	borde_izq_o2 = o2.getPosicionX();
	borde_dcho_o2 = borde_izq_o2 + o2.getAncho();
	borde_arriba_o2 = o2.getPosicionY();
	borde_abajo_o2 = borde_arriba_o2 + o2.getAlto();

	if (borde_abajo_o1 <= borde_arriba_o2		||
			borde_arriba_o1 >= borde_abajo_o2	||
			borde_dcho_o1 <= borde_izq_o2		||
			borde_izq_o1 >= borde_dcho_o2)
		return NoRebota;
	
	
	
	//Coregir parte de debajo
	//Detectar parte del objeto que rebota
	//Aquí ya rebotó

	if ( !((borde_abajo_o1-0.25*o1.getAlto()) <= borde_arriba_o2 ||
		(borde_arriba_o1 + 0.25*o1.getAlto()) >= borde_abajo_o2 ||
		borde_dcho_o1 <= borde_izq_o2 ||
		(borde_dcho_o1-0.1* o1.getAncho()) >= borde_dcho_o2))
		return RebotaDerecha;

	if (!((borde_abajo_o1 - 0.25*o1.getAlto()) <= borde_arriba_o2 ||
		(borde_arriba_o1 + 0.25*o1.getAlto()) >= borde_abajo_o2 ||
		(borde_izq_o1+ 0.1* o1.getAncho()) <= borde_izq_o2 ||
		borde_izq_o1 >= borde_dcho_o2))
		return RebotaIzquierda;

	if (!((borde_arriba_o1+0.1*o1.getAlto()) <= borde_arriba_o2 ||
		borde_arriba_o1 >= borde_abajo_o2 ||
		(borde_dcho_o1+0*o1.getAncho()) <= borde_izq_o2 ||
		(borde_izq_o1-0*o1.getAncho()) >= borde_dcho_o2))
		return RebotaArriba;

	if (!(borde_abajo_o1 <= borde_arriba_o2 ||
		(borde_abajo_o1-1*o1.getAlto()) >= borde_abajo_o2 ||
		(borde_dcho_o1 + 0*o1.getAncho()) <= borde_izq_o2 ||
		(borde_izq_o1 - 0*o1.getAncho()) >= borde_dcho_o2))
		return RebotaAbajo;


}