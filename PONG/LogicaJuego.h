#pragma once
#ifndef LOGICAJUEGO_H
#define LOGICAJUEGO_H

#include "Marcador.h"
#include "ColeccionObjetos.h"

class LogicaJuego
{
public:
	LogicaJuego();
	~LogicaJuego();

	void ControlaMarcador(Marcador *mi_marcador, ColeccionObjetos coleccion);
};

#endif
