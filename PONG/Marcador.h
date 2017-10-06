#pragma once

#ifndef MARCADOR_H
#define MARCADOR_H


class Marcador 
{
protected:
	int goles_A=0, goles_B=0;

public:
	Marcador(int goles_A, int goles_B);
	~Marcador();
	 
	void AumentaGolA();
	void AumentaGolB();
	int getGolesA();
	int getGolesB();


};

#endif
