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

void MotorFisica::GestionaRebotePorArriba(ObjetoJuego *obj1, ObjetoJuego *obj2)
{
	// Si el objeto es afectado por choque se cambia la posición y velocidad en Y 
	if (obj1->getAfectadoPorChoque())
	{
		obj1->setVelocidadY(-obj1->getVelocidadY());	
		obj1->setPosicionY(obj1->getPosicionY() + 20);	
	}

	// Si el objeto es afectado por choque se cambia la posición y velocidad en Y
	if (obj2->getAfectadoPorChoque())
	{
		obj2->setVelocidadY(-obj2->getVelocidadY());
		obj2->setPosicionY(obj2->getPosicionY() - 20);
	}
}

void MotorFisica::GestionaRebotePorAbajo(ObjetoJuego *obj1, ObjetoJuego *obj2)
{
	// Si el objeto es afectado por choque se cambia la posición y velocidad en Y
	if (obj1->getAfectadoPorChoque())
	{
		obj1->setVelocidadY(-obj1->getVelocidadY());
		obj1->setPosicionY(obj1->getPosicionY() - 20);
	}

	// Si el objeto es afectado por choque se cambia la posición y velocidad en Y
	if (obj2->getAfectadoPorChoque())
	{
		obj2->setVelocidadY(-obj2->getVelocidadY());
		obj2->setPosicionY(obj2->getPosicionY() + 20);
	}
}

void MotorFisica::GestionaRebotePorIzquierda(ObjetoJuego *obj1, ObjetoJuego *obj2)
{
	// Si el objeto es afectado por choque se cambia la posición y velocidad en X
	if (obj1->getAfectadoPorChoque())
	{
		obj1->setVelocidadX(-obj1->getVelocidadX());
		obj1->setPosicionX(obj1->getPosicionX() + 20);
	}

	// Si el objeto es afectado por choque se cambia la posición y velocidad en X
	if (obj2->getAfectadoPorChoque())
	{
		obj2->setVelocidadX(-obj2->getVelocidadX());
		obj2->setPosicionX(obj2->getPosicionX() - 20);

	}
}

void MotorFisica::GestionaRebotePorDerecha(ObjetoJuego *obj1, ObjetoJuego *obj2)
{
	// Si el objeto es afectado por choque se cambia la posición y velocidad en X
	if (obj1->getAfectadoPorChoque())
	{
		obj1->setVelocidadX(-obj1->getVelocidadX());
		obj1->setPosicionX(obj1->getPosicionX() - 10);
	}

	// Si el objeto es afectado por choque se cambia la posición y velocidad en X
	if (obj2->getAfectadoPorChoque())
	{
		obj2->setVelocidadX(-obj2->getVelocidadX());
		obj2->setPosicionX(obj2->getPosicionX() + 10);
	}
}

void MotorFisica::GestionaReboteCirculos(ObjetoJuego *obj1, ObjetoJuego *obj2)
{
	// Vector en la dirección de los centros
	double dx = (obj1->getPosicionX()) - (obj2->getPosicionX());
	double dy = obj1->getPosicionY() - obj2->getPosicionY();

	// Si las bolas están una encima de la otra la dirección será aleatoria
	if (dx == 0 && dy == 0)
	{
		dx = rand() % (10);
		dy = rand() % (10);
	}
	
	// Hagámoslo unitario
	float dx_2, dy_2;
	float deno = sqrt(dx*dx + dy*dy);
	dx_2 = dx / deno;
	dy_2 = dy / deno;

	// Velocidad de la primera pelota
	float v1 = sqrt(obj1->getVelocidadX() * obj1->getVelocidadX() +
		obj1->getVelocidadY() *obj1->getVelocidadY());

	// Velocidad de la segunda pelota
	float v2 = sqrt(obj2->getVelocidadX() * obj2->getVelocidadX() +
		obj2->getVelocidadY() *obj2->getVelocidadY());

	// Cambiamos la dirección de la velocidad
	obj1->setVelocidadX(dx_2*v1);
	obj1->setVelocidadY(dy_2*v1);

	obj2->setVelocidadX(-dx_2*v2);
	obj2->setVelocidadY(-dy_2*v2);

}





bool MotorFisica::Actualiza(int tecla)
{
	vector<ObjetoJuego*> mis_objetos = coleccion->getColeccionObjetos();
	num_objetos = coleccion->getTamColeccion();
	bool HayColision = FALSE;

	// Detectar colisiones
	for (int i = 0; i < num_objetos; i++)
	{
		if (mis_objetos[i]->getEsAtravesado()) continue;
		for (int j = i + 1; j < num_objetos; j++)
		{
			if (mis_objetos[j]->getEsAtravesado()) continue;
			int colision = DetectaColision(*mis_objetos[i], *mis_objetos[j]);

			// Colisiones con "Rectángulos"
			if (mis_objetos[i]->getForma() == "rectangulo" ||
				mis_objetos[j]->getForma() == "rectangulo")
			{
				if (colision == RebotaArriba )
				{
					if ((mis_objetos[i]->getSiRebotoSueno()) || (mis_objetos[j]->getSiRebotoSueno()))
						HayColision = TRUE;

					GestionaRebotePorArriba(mis_objetos[i], mis_objetos[j]);					
				}

				else if (colision == RebotaAbajo)
				{
					if ((mis_objetos[i]->getSiRebotoSueno()) || (mis_objetos[j]->getSiRebotoSueno()))
						HayColision = TRUE;

					GestionaRebotePorAbajo(mis_objetos[i], mis_objetos[j]);

				}

				else if (colision == RebotaIzquierda)
				{
					if ((mis_objetos[i]->getSiRebotoSueno()) || (mis_objetos[j]->getSiRebotoSueno()))
						HayColision = TRUE;

					GestionaRebotePorIzquierda(mis_objetos[i], mis_objetos[j]);
				}

				else if (colision == RebotaDerecha)
				{
					if ((mis_objetos[i]->getSiRebotoSueno()) || (mis_objetos[j]->getSiRebotoSueno()))
						HayColision = TRUE;

					GestionaRebotePorDerecha(mis_objetos[i], mis_objetos[j]);

				}
			}

			// Colisiones entre círculos
			else if (colision > 0 && mis_objetos[i]->getForma() == "circulo" && mis_objetos[j]->getForma() == "circulo")
			{
				if ((mis_objetos[i]->getSiRebotoSueno()) || (mis_objetos[j]->getSiRebotoSueno()))
					HayColision = TRUE;

				GestionaReboteCirculos(mis_objetos[i], mis_objetos[j]);
				
			}
		}
	}

	// Control de las raquetas
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
	// Definir bordes de los objetos
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


	// Detección de colisiones
	if (borde_abajo_o1 <= borde_arriba_o2		||
			borde_arriba_o1 >= borde_abajo_o2	||
			borde_dcho_o1 <= borde_izq_o2		||
			borde_izq_o1 >= borde_dcho_o2)
		return NoRebota;
	
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

	return NoRebota;

}