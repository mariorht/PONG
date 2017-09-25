#pragma once
#ifndef FISICA_H
#define FISICA_H


#include "Pelota.h"

class MotorFisica
{

protected:
	Pelota *mi_pelota;
public:
	MotorFisica(Pelota *pelota);
	//~MotorFisica();

	void Actualiza();
};



#endif