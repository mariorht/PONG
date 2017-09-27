#pragma once
#ifndef FISICA_H
#define FISICA_H


#include "Pelota.h"
#include <vector>
#include "ColeccionObjetos.h"



#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 30

class MotorFisica
{

protected:
	ColeccionObjetos coleccion;
	int num_objetos;
public:
	MotorFisica(ColeccionObjetos coleccion);
	//~MotorFisica();

	void Actualiza();
};



#endif