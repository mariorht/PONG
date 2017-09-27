#pragma once
#ifndef FISICA_H
#define FISICA_H


#include "Pelota.h"
#include "ColeccionObjetos.h"
#include "InterfazUsuario.h"



class MotorFisica
{

protected:
	ColeccionObjetos coleccion;
	int num_objetos;
public:
	MotorFisica(ColeccionObjetos objetos);
	//~MotorFisica();

	void Actualiza(int tecla);
};



#endif