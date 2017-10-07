#pragma once
#ifndef COLECCIONOBJETOS_H
#define COLECCIONOBJETOS_H

#include "ObjetoJuego.h"
#include <vector>

using namespace std;

// Clase ColeccionObjetos: Almacena punteros a objetos tipo ObjetoJuego en un vector y su tama�o
class ColeccionObjetos
{
protected:
	vector<ObjetoJuego*> objetos;
	int tam_coleccion;


public:

	/** Constructor :*/
	ColeccionObjetos();

	/** Destructor :*/
	~ColeccionObjetos();

	/** Devuelve un vector de punteros */ 
	vector<ObjetoJuego*> getColeccionObjetos();

	/** Devuelve el tama�o de la colecci�n */
	int getTamColeccion();

	/** Agrega un puntero a la coleccion:
	param ObjetoJuego *objeto: puntero al objeto a agregar*/
	void AgregaObjeto(ObjetoJuego *objeto);

	/** Elimina un puntero de la coleccion:
	param ObjetoJuego *objeto: puntero del objeto a eliminar*/
	void EliminaObjeto(ObjetoJuego *objeto);

	/** Elimina el �ltimo puntero de la colecci�n*/
	void EliminaUltimoObjeto();
};

#endif
