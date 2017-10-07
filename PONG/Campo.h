#pragma once
#ifndef CAMPO_H
#define CAMPO_H

// Clase Campo: Almacena el tamaño del campo y la posición de las porterías
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

	/** Devuelve la posición de la portería izquierda */
	float getPosPorteriaIzq();

	/** Devuelve la posición de la portería derecha */
	float getPosPorteriaDcha();
};


#endif