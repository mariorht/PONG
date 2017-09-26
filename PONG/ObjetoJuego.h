#ifndef OBJETO_JUEGO
#define OBJETO_JUEGO

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <SDL.h>

using namespace std;

class ObjetoJuego
{
protected:
	float posX, posY;
	float velX, velY;
	float aX, aY;

	float ancho, alto;

	SDL_Surface *image;
	




public:
	SDL_Rect rect;
	//ObjetoJuego();
	ObjetoJuego(Uint32 color, float px, float py, float vx, float vy, float ax, float ay, float w, float h);
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



	void Dibuja(SDL_Surface *destination);





};



#endif