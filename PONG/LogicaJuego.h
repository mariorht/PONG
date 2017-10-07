#pragma once
#ifndef LOGICAJUEGO_H
#define LOGICAJUEGO_H

#include "Marcador.h"
#include "ColeccionObjetos.h"
#include "Campo.h"

// Clase que controla los goles
class LogicaJuego
{
public:

	/** Constructor*/
	LogicaJuego();
	
	/** Función que controla los goles y actualiza el marcador*/
	bool ControlaMarcador(Marcador *mi_marcador, ColeccionObjetos coleccion, Campo *campo);
};

#endif
