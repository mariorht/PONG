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

	void GestionaRebotePorArriba(ObjetoJuego *obj1, ObjetoJuego *obj2);
	void GestionaRebotePorAbajo(ObjetoJuego *obj1, ObjetoJuego *obj2);
	void GestionaRebotePorIzquierda(ObjetoJuego *obj1, ObjetoJuego *obj2);
	void GestionaRebotePorDerecha(ObjetoJuego *obj1, ObjetoJuego *obj2);
	void GestionaReboteCirculos(ObjetoJuego *obj1, ObjetoJuego *obj2);
	void Mueve(ObjetoJuego *obj);
public:
	MotorFisica(ColeccionObjetos *objetos);
	//~MotorFisica();

	bool Actualiza(int tecla);

	//Devuelve la parte del objeto 1 que rebotó
	int DetectaColision(ObjetoJuego obj1, ObjetoJuego obj2);
};



#endif