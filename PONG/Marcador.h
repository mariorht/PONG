#pragma once

#ifndef MARCADOR_H
#define MARCADOR_H

// Clase que almacena los goles
class Marcador 
{
protected:
	int goles_A=0, goles_B=0;

public:

	/** Constructor:
	param int goles_A : goles del equipo 1
	param int goles_B : goles del equipo 2*/
	Marcador(int goles_A, int goles_B);
	 
	/** Función que aumenta los goles del equipo 1*/
	void AumentaGolA();

	/** Función que aumenta los goles del equipo 2*/
	void AumentaGolB();

	/** Función que devuelve los goles del equipo 1*/
	int getGolesA();

	/** Función que devuelve los goles del equipo 2*/
	int getGolesB();


};

#endif
