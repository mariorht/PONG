#pragma once
#ifndef CAMPO_H
#define CAMPO_H

// Clase Campo: Almacena el tama�o del campo y la posici�n de las porter�as
class Campo 
{
protected:
	float ancho;
	float alto;
	float pos_porteria_izq;
	float pos_porteria_dcha;
	
public:

	/** Constructor:
	param float w : ancho del campo
	param float h : alto del campo
	*/
	Campo(float w, float h); 

	/** Devuelve el ancho del campo */
	float getAnchoCampo();

	/** Devuelve el alto del campo */
	float getAltoCampo();

	/** Devuelve la posici�n de la porter�a izquierda */
	float getPosPorteriaIzq();

	/** Devuelve la posici�n de la porter�a derecha */
	float getPosPorteriaDcha();
};


#endif