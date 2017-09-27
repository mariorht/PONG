#ifndef OBJETO_JUEGO
#define OBJETO_JUEGO

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <SDL.h>

#define SCREEN_WIDTH  500
#define SCREEN_HEIGHT  500

using namespace std;

class ObjetoJuego
{
protected:
	float posX, posY;
	float velX, velY;
	float aX, aY;
	Uint32 color;
	
	float ancho, alto;

public:

	ObjetoJuego(Uint32 color,
		float px, float py, 
		float vx, float vy,
		float ax, float ay,
		float w, float h);
	//~ObjetoJuego();

	void setPosicion(float, float);
	void setVelocidadX(float);
	void setVelocidadY(float);
	void setAceleracion(float, float);
	void setDimensiones(float, float);

	Uint32 getColor();
	float getAncho();
	float getAlto();
	float getPosicionX();
	float getPosicionY();
	float getVelocidadX();
	float getVelocidadY();

};



#endif