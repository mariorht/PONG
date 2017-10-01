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
	obj.setPosicionX(px + vx);
	obj.setPosicionY(py + vy);
}

void MotorFisica::Actualiza(int tecla)
{
	vector<ObjetoJuego*> mis_objetos = coleccion.getColeccionObjetos();

	for (int i = 0; i < num_objetos; i++)
	{
		for (int j = i + 1; j < num_objetos; j++)
		{
			int colision = DetectaColision(*mis_objetos[i], *mis_objetos[j]);

			if (mis_objetos[i]->Forma == "rectangulo" ||
				mis_objetos[j]->Forma == "rectangulo")
			{
				if (colision == RebotaArriba )
				{
					//mis_objetos[i]->setVelocidadX(-mis_objetos[i]->getVelocidadX());
					//mis_objetos[j]->setVelocidadX(-mis_objetos[j]->getVelocidadX());
					if (mis_objetos[i]->AfectadoPorChoque)
					{
						mis_objetos[i]->setVelocidadY(-mis_objetos[i]->getVelocidadY());
						mis_objetos[i]->setPosicionY(mis_objetos[i]->getPosicionY() + 20);
					}


					if (mis_objetos[j]->AfectadoPorChoque)
					{
						mis_objetos[j]->setVelocidadY(-mis_objetos[j]->getVelocidadY());
						mis_objetos[j]->setPosicionY(mis_objetos[j]->getPosicionY() - 20);
					}

				}

				if (colision == RebotaAbajo)
				{
					//mis_objetos[i]->setVelocidadX(-mis_objetos[i]->getVelocidadX());
					//mis_objetos[j]->setVelocidadX(-mis_objetos[j]->getVelocidadX());
					if (mis_objetos[i]->AfectadoPorChoque)
					{
						mis_objetos[i]->setVelocidadY(-mis_objetos[i]->getVelocidadY());
						mis_objetos[i]->setPosicionY(mis_objetos[i]->getPosicionY()-20);
					}


					if (mis_objetos[j]->AfectadoPorChoque)
					{
						mis_objetos[j]->setVelocidadY(-mis_objetos[j]->getVelocidadY());
						mis_objetos[j]->setPosicionY(mis_objetos[j]->getPosicionY() + 20);
					}

				}

				else if (colision == RebotaIzquierda)
				{
					if (mis_objetos[i]->AfectadoPorChoque)
					{
						mis_objetos[i]->setVelocidadX(-mis_objetos[i]->getVelocidadX());
						mis_objetos[i]->setPosicionX(mis_objetos[i]->getPosicionX() + 20);
					}
					if (mis_objetos[j]->AfectadoPorChoque)
					{
						mis_objetos[j]->setVelocidadX(-mis_objetos[j]->getVelocidadX());
						mis_objetos[j]->setPosicionX(mis_objetos[j]->getPosicionX() - 20);

					}
				}

				else if (	colision == RebotaDerecha)
				{
					if (mis_objetos[i]->AfectadoPorChoque)
					{
						mis_objetos[i]->setVelocidadX(-mis_objetos[i]->getVelocidadX());
						mis_objetos[i]->setPosicionX(mis_objetos[i]->getPosicionX() - 20);
					}
					if (mis_objetos[j]->AfectadoPorChoque)
					{
						mis_objetos[j]->setVelocidadX(-mis_objetos[j]->getVelocidadX());
						mis_objetos[j]->setPosicionX(mis_objetos[j]->getPosicionX() + 20);
					}
				}
			}

			else if (colision > 0 && mis_objetos[i]->Forma == "circulo" && mis_objetos[j]->Forma == "circulo")
			{
				double dx = (mis_objetos[i]->getPosicionX()) -(mis_objetos[j]->getPosicionX());
				double dy = mis_objetos[i]->getPosicionY() - mis_objetos[j]->getPosicionY();

				//Revisar por qué no unitario
				float dx_2 = dx / sqrt(dx*dx + dy*dy);
				float dy_2 = dy / sqrt(dx*dx + dy*dy);


				float v = sqrt(mis_objetos[i]->getVelocidadX() * mis_objetos[i]->getVelocidadX() +
					mis_objetos[i]->getVelocidadY() *mis_objetos[i]->getVelocidadY());

				//Actualmente para la misma velocidad las dos bolas
				mis_objetos[i]->setVelocidadX(dx_2*v);
				mis_objetos[i]->setVelocidadY(dy_2*v);

				 v = sqrt(mis_objetos[i]->getVelocidadX() * mis_objetos[i]->getVelocidadX() +
					mis_objetos[i]->getVelocidadY() *mis_objetos[i]->getVelocidadY());

				mis_objetos[j]->setVelocidadX(-dx_2*v);
				mis_objetos[j]->setVelocidadY(-dy_2*v);
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