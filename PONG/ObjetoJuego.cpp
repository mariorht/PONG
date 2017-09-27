#include "ObjetoJuego.h"


ObjetoJuego::ObjetoJuego(Uint32 c, float px, float py, float vx, float vy, float ax, float ay, float w, float h)
{
	color = c;
	posX=px;
	posY=py;
	velX=vx;
	velY=vy;
	aX=ax;
	aY=ay;
	ancho=w;
	alto=h;


}



Uint32 ObjetoJuego::getColor()
{
	return color;
}

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


/*
void ObjetoJuego::Dibuja(SDL_Surface * destination)
{
	SDL_BlitSurface(image, NULL, destination, &rect);
}
*/
float ObjetoJuego::getAncho()
{
	return ancho;
}

float ObjetoJuego::getAlto()
{
	return alto;
}