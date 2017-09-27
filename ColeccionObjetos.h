#pragma once
#ifndef COLECCIONOBJETOS_H
#define COLECCIONOBJETOS_H

#include "ObjetoJuego.h"
#include <vector>

using namespace std;

class ColeccionObjetos
{
protected:
	vector<ObjetoJuego*> objetos;
	int tam_coleccion;

	


public:
	ColeccionObjetos();
	~ColeccionObjetos();

	vector<ObjetoJuego*> getColeccionObjetos();
	int getTamColeccion();
	void AgregaObjeto(ObjetoJuego *objeto);
	void EliminaObjeto(ObjetoJuego *objeto);
};

#endif
