#include "MotorFisica.h"



MotorFisica::MotorFisica(ColeccionObjetos *objetos) : coleccion(objetos),
	num_objetos(coleccion->getTamColeccion()) {}


void MotorFisica::Mueve(ObjetoJuego *obj)
{
	float px, py;
	px = obj->getPosicionX();
	py = obj->getPosicionY();

	float vx, vy;
	vx = obj->getVelocidadX();
	vy = obj->getVelocidadY();

	float ax, ay;
	ax = obj->getAceleracionX();
	ay = obj->getAceleracionY();

	vx += ax;
	vy += ay;

	obj->setVelocidadX(vx);
	obj->setVelocidadY(vy);
	obj->setPosicionX(px + vx);
	obj->setPosicionY(py + vy);
}

bool MotorFisica::Actualiza(int tecla)
{
	vector<ObjetoJuego*> mis_objetos = coleccion->getColeccionObjetos();
	num_objetos = coleccion->getTamColeccion();
	bool HayColision = FALSE;

	//Detectar colisiones
	for (int i = 0; i < num_objetos; i++)
	{
		if (mis_objetos[i]->getEsAtravesado()) continue;
		for (int j = i + 1; j < num_objetos; j++)
		{
			if (mis_objetos[j]->getEsAtravesado()) continue;
			int colision = DetectaColision(*mis_objetos[i], *mis_objetos[j]);

			if (mis_objetos[i]->getForma() == "rectangulo" ||
				mis_objetos[j]->getForma() == "rectangulo")
			{
				if (colision == RebotaArriba )
				{
					if ((mis_objetos[i]->getSiRebotoSueno()) || (mis_objetos[j]->getSiRebotoSueno()))
						HayColision = TRUE;

					if (mis_objetos[i]->getAfectadoPorChoque())
					{
						mis_objetos[i]->setVelocidadY(-mis_objetos[i]->getVelocidadY());
						mis_objetos[i]->setPosicionY(mis_objetos[i]->getPosicionY() + 20);
					}


					if (mis_objetos[j]->getAfectadoPorChoque())
					{
						mis_objetos[j]->setVelocidadY(-mis_objetos[j]->getVelocidadY());
						mis_objetos[j]->setPosicionY(mis_objetos[j]->getPosicionY() - 20);
					}

				}

				if (colision == RebotaAbajo)
				{
					if ((mis_objetos[i]->getSiRebotoSueno()) || (mis_objetos[j]->getSiRebotoSueno()))
						HayColision = TRUE;

					if (mis_objetos[i]->getAfectadoPorChoque())
					{
						mis_objetos[i]->setVelocidadY(-mis_objetos[i]->getVelocidadY());
						mis_objetos[i]->setPosicionY(mis_objetos[i]->getPosicionY()-20);
					}


					if (mis_objetos[j]->getAfectadoPorChoque())
					{
						mis_objetos[j]->setVelocidadY(-mis_objetos[j]->getVelocidadY());
						mis_objetos[j]->setPosicionY(mis_objetos[j]->getPosicionY() + 20);
					}

				}

				else if (colision == RebotaIzquierda)
				{
					if ((mis_objetos[i]->getSiRebotoSueno()) || (mis_objetos[j]->getSiRebotoSueno()))
						HayColision = TRUE;

					if (mis_objetos[i]->getAfectadoPorChoque())
					{
						mis_objetos[i]->setVelocidadX(-mis_objetos[i]->getVelocidadX());
						mis_objetos[i]->setPosicionX(mis_objetos[i]->getPosicionX() + 10);
					}
					if (mis_objetos[j]->getAfectadoPorChoque())
					{
						mis_objetos[j]->setVelocidadX(-mis_objetos[j]->getVelocidadX());
						mis_objetos[j]->setPosicionX(mis_objetos[j]->getPosicionX() - 10);

					}
				}

				else if (	colision == RebotaDerecha)
				{
					if ((mis_objetos[i]->getSiRebotoSueno()) || (mis_objetos[j]->getSiRebotoSueno()))
						HayColision = TRUE;

					if (mis_objetos[i]->getAfectadoPorChoque())
					{
						mis_objetos[i]->setVelocidadX(-mis_objetos[i]->getVelocidadX());
						mis_objetos[i]->setPosicionX(mis_objetos[i]->getPosicionX() - 10);
					}
					if (mis_objetos[j]->getAfectadoPorChoque())
					{
						mis_objetos[j]->setVelocidadX(-mis_objetos[j]->getVelocidadX());
						mis_objetos[j]->setPosicionX(mis_objetos[j]->getPosicionX() + 10);
					}
				}
			}

			else if (colision > 0 && mis_objetos[i]->getForma() == "circulo" && mis_objetos[j]->getForma() == "circulo")
			{
				if ((mis_objetos[i]->getSiRebotoSueno()) || (mis_objetos[j]->getSiRebotoSueno()))
					HayColision = TRUE;

				double dx = (mis_objetos[i]->getPosicionX()) -(mis_objetos[j]->getPosicionX());
				double dy = mis_objetos[i]->getPosicionY() - mis_objetos[j]->getPosicionY();

				float dx_2, dy_2;
				float deno = sqrt(dx*dx + dy*dy);
				if (deno == 0)
				{
					dx_2 = rand() % (10);
					dy_2 = rand() % (10);
				}
				else
				{
					dx_2 = dx / deno;
					dy_2 = dy / deno;
				}


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
			if(mis_objetos[i]->getPosicionX()>500)
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

			if (mis_objetos[i]->getPosicionX()<500)
			{
				if (tecla == TECLA_W)
					mis_objetos[i]->setAceleracionY(-5.0);
				else if (tecla == TECLA_S)
					mis_objetos[i]->setAceleracionY(+5.0);
				else
				{
					float roz = mis_objetos[i]->getRozamiento();
					float vy = mis_objetos[i]->getVelocidadY();

					mis_objetos[i]->setAceleracionY(-roz*vy);
				}
			}
			
		}


		Mueve(mis_objetos[i]);
	
	}
	return HayColision;

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