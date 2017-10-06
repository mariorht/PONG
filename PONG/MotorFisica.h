#pragma once
#ifndef FISICA_H
#define FISICA_H

#define NoRebota 0
#define RebotaAbajo 1
#define RebotaArriba 2
#define RebotaDerecha 3
#define RebotaIzquierda 4


#include "Pelota.h"
#include "ColeccionObjetos.h"
#include "InterfazUsuario.h"
#include <math.h>



class MotorFisica
{

protected:
	ColeccionObjetos *coleccion;
	int num_objetos;
public:
	MotorFisica(ColeccionObjetos *objetos);
	//~MotorFisica();

	bool Actualiza(int tecla);
	void Mueve(ObjetoJuego *obj);

	//Devuelve la parte del objeto 1 que rebotó
	int DetectaColision(ObjetoJuego obj1, ObjetoJuego obj2);
};



#endif