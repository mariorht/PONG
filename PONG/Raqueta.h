#pragma once
#ifndef RAQUETA_H
#define RAQUETA_H

#include "ObjetoJuego.h"

// Clase heredada de ObjetoJuego que define una raqueta
class Raqueta :	public ObjetoJuego
{
protected:
	bool ControladoPorIA;	// Indica si es controlado por la Inteligencia Artificial
	float V_max;			// Velocidad m�xima
	
public:

	/**Constructor:
	param Uint32 color : color del objeto
	param float px : posici�n X del objeto
	param float py : posici�n Y del objeto
	param float vy : velocidad Y del objeto
	param float ay : aceleraci�n y del objeto
	param float w : ancho del objeto
	param float h: alto del objeto
	param float roz : coeficiente de rozamiento
	param Campo *mi_campo : puntero al objeto campo*/
	Raqueta(Uint32 color, float px, float py, float vy, float ay, float w, float h, float roz, Campo *mi_campo);
	
	/** Asigna la posici�n Y del objeto*/
	void setPosicionY(float);

	/** Asigna la posici�n X del objeto*/
	void setVelocidadX(float);

	/** Asigna la velocidad Y del objeto*/
	void setVelocidadY(float);

	/** Desactiva el control de la raqueta por IA*/
	void setIAoff();

	/** Activa el control de la raqueta por IA*/
	void setIAon();

	bool esControladoPorIA();
};

#endif
