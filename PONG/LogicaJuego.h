#pragma once
#ifndef LOGICAJUEGO_H
#define LOGICAJUEGO_H

#include "Marcador.h"
#include "ColeccionObjetos.h"
#include "Campo.h"

class LogicaJuego
{
public:
	LogicaJuego();
	~LogicaJuego();

	bool ControlaMarcador(Marcador *mi_marcador, ColeccionObjetos coleccion, Campo *campo);
};

#endif
