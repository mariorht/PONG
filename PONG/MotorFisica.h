#pragma once
#ifndef FISICA_H
#define FISICA_H

// Definición tipo de rebote
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
	ColeccionObjetos *coleccion; // Colección que almacena los objetos a controlar
	int num_objetos; // Número de objetos que forman la colección

	/** Función que gestiona el rebote por arriba
	param ObjetoJuego *obj1 : Objeto que choca con la parte de arriba 
	param ObjetoJuego *obj2 : Objeto que recibe el impacto*/
	void GestionaRebotePorArriba(ObjetoJuego *obj1, ObjetoJuego *obj2);

	/** Función que gestiona el rebote por abajo
	param ObjetoJuego *obj1 : Objeto que choca con la parte de abajo
	param ObjetoJuego *obj2 : Objeto que recibe el impacto*/
	void GestionaRebotePorAbajo(ObjetoJuego *obj1, ObjetoJuego *obj2);

	/** Función que gestiona el rebote por la izquierda
	param ObjetoJuego *obj1 : Objeto que choca con la parte de la izquierda
	param ObjetoJuego *obj2 : Objeto que recibe el impacto*/
	void GestionaRebotePorIzquierda(ObjetoJuego *obj1, ObjetoJuego *obj2);

	/** Función que gestiona el rebote por la derecha
	param ObjetoJuego *obj1 : Objeto que choca con la parte de la derecha
	param ObjetoJuego *obj2 : Objeto que recibe el impacto*/
	void GestionaRebotePorDerecha(ObjetoJuego *obj1, ObjetoJuego *obj2);

	/** Función que gestiona el rebote entre círculos
	param ObjetoJuego *obj1 : Objeto 1 que choca
	param ObjetoJuego *obj2 : Objeto 2 que choca*/
	void GestionaReboteCirculos(ObjetoJuego *obj1, ObjetoJuego *obj2);

	/** Función que mueve objetos:
	param ObjetoJuego *obj : Objeto a mover*/
	void Mueve(ObjetoJuego *obj);

public:
	/** Constructor:
	param ColeccionObjetos *objetos : colección de objetos a controlar*/
	MotorFisica(ColeccionObjetos *objetos);
	
	/** */
	bool Actualiza(int tecla);

	/** Devuelve la parte del objeto 1 que rebotó */
	int DetectaColision(ObjetoJuego obj1, ObjetoJuego obj2);
};



#endif