#pragma once
#ifndef IA_H
#define IA_H

#include "Pelota.h"
#include "Raqueta.h"


class InteligenciaArtificial
{
protected:
	Raqueta *mi_raqueta;
	int dificultad;

public:
	InteligenciaArtificial(Raqueta* r);
	~InteligenciaArtificial();

	void EligeMovimiento(ObjetoJuego *pelota);

};

#endif