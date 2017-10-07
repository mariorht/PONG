#pragma once
#ifndef IA_H
#define IA_H

#include "Pelota.h"
#include "Raqueta.h"

// Clase InteligenciaArtificial que controla el movimiento de una raqueta
class InteligenciaArtificial
{
protected:
	Raqueta *mi_raqueta; // Raqueta a controlar
	int dificultad;		 // Nivel de dificultad

public:

	/** Constructor: 
	param Raqueta *r : Raqueta a controlar*/
	InteligenciaArtificial(Raqueta* r);

	/** Controla el movimiento de la raqueta
	param ObjetoJuego *pelota: pelota en función de la que se moverá la pelota*/
	void EligeMovimiento(ObjetoJuego *pelota);

};

#endif