#ifndef OBJETO_JUEGO
#define OBJETO_JUEGO

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
using namespace std;

class ObjetoJuego
{
protected:
	float posX, posY;
	float velX, velY;
	float aX, aY;

	float ancho, alto;
	char forma;
	string forma_2D;




public:
	//ObjetoJuego();
	ObjetoJuego(float px, float py, float vx, float vy, float ax, float ay, float w, float h, char forma);
	//~ObjetoJuego();

	void setPosicion(float, float);
	void setVelocidadX(float);
	void setVelocidadY(float);
	void setAceleracion(float, float);
	void setDimensiones(float, float);

	float getPosicionX();
	float getPosicionY();
	float getVelocidadX();
	float getVelocidadY();

	char getForma();
	void setForma(char);

	void construir_forma(); //por hacer
	string getForma2D();




};



#endif