#pragma once
#ifndef FISICA_H
#define FISICA_H

// Definici�n tipo de rebote
#define NoRebota 0
#define RebotaAbajo 1
#define RebotaArriba 2
#define RebotaDerecha 3
#define RebotaIzquierda 4


#include "Pelota.h"
#include "ColeccionObjetos.h"
#include "InterfazUsuario.h"
#include <math.h>


// Clase que controla el movimiento de los objetos del juego
class MotorFisica
{

protected:
	ColeccionObjetos *coleccion; // Colecci�n que almacena los objetos a controlar
	int num_objetos; // N�mero de objetos que forman la colecci�n

	/** Funci�n que gestiona el rebote por arriba
	param ObjetoJuego *obj1 : Objeto que choca con la parte de arriba 
	param ObjetoJuego *obj2 : Objeto que recibe el impacto*/
	void GestionaRebotePorArriba(ObjetoJuego *obj1, ObjetoJuego *obj2);

	/** Funci�n que gestiona el rebote por abajo
	param ObjetoJuego *obj1 : Objeto que choca con la parte de abajo
	param ObjetoJuego *obj2 : Objeto que recibe el impacto*/
	void GestionaRebotePorAbajo(ObjetoJuego *obj1, ObjetoJuego *obj2);

	/** Funci�n que gestiona el rebote por la izquierda
	param ObjetoJuego *obj1 : Objeto que choca con la parte de la izquierda
	param ObjetoJuego *obj2 : Objeto que recibe el impacto*/
	void GestionaRebotePorIzquierda(ObjetoJuego *obj1, ObjetoJuego *obj2);

	/** Funci�n que gestiona el rebote por la derecha
	param ObjetoJuego *obj1 : Objeto que choca con la parte de la derecha
	param ObjetoJuego *obj2 : Objeto que recibe el impacto*/
	void GestionaRebotePorDerecha(ObjetoJuego *obj1, ObjetoJuego *obj2);

	/** Funci�n que gestiona el rebote entre c�rculos
	param ObjetoJuego *obj1 : Objeto 1 que choca
	param ObjetoJuego *obj2 : Objeto 2 que choca*/
	void GestionaReboteCirculos(ObjetoJuego *obj1, ObjetoJuego *obj2);

	/** Funci�n que mueve objetos:
	param ObjetoJuego *obj : Objeto a mover*/
	void Mueve(ObjetoJuego *obj);

public:
	/** Constructor:
	param ColeccionObjetos *objetos : colecci�n de objetos a controlar*/
	MotorFisica(ColeccionObjetos *objetos);
	
	/** */
	bool Actualiza(int tecla);

	/** Devuelve la parte del objeto 1 que rebot� */
	int DetectaColision(ObjetoJuego obj1, ObjetoJuego obj2);
};



#endif