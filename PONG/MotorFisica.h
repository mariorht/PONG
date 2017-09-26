#pragma once
#ifndef FISICA_H
#define FISICA_H


#include "Pelota.h"
#include <vector>



class MotorFisica
{

protected:
	vector<Pelota>* mi_pelota;
	int num_objetos;
public:
	MotorFisica(vector<Pelota>* pelota);
	//~MotorFisica();

	void Actualiza();
};



#endif