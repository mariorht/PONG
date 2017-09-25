#include "ObjetoJuego.h"



ObjetoJuego::ObjetoJuego(float px, float py, float vx, float vy, float ax, float ay, float w, float h) :
	posX(px), posY(py), velX(vx), velY(vy), aX(ax), aY(ay), ancho(w), alto(h) {}



void ObjetoJuego::setPosicion(float px, float py) 
{
	posX = px;
	posY = py;
}

void ObjetoJuego::setVelocidadX(float vx)
{
	velX = vx;

}

void ObjetoJuego::setVelocidadY(float vy)
{
	velY = vy;

}

void ObjetoJuego::setAceleracion(float ax, float ay)
{
	aX = ax;
	aY = ay;
}

void ObjetoJuego::setDimensiones(float w, float h)
{
	ancho = w;
	alto = h;
}

float ObjetoJuego::getPosicionX()
{
	return posX;
}

float ObjetoJuego::getPosicionY()
{
	return posY;
}

float ObjetoJuego::getVelocidadX()
{
	return velX;
}

float ObjetoJuego::getVelocidadY()
{
	return velY;
}

