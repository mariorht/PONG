#include "ObjetoJuego.h"


ObjetoJuego::ObjetoJuego(Uint32 c, float px, float py, float vx, float vy, float ax, float ay, float w, float h, float roz)
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
	rozamiento = roz;
}



Uint32 ObjetoJuego::getColor()
{
	return color;
}

void ObjetoJuego::setPosicion(float px, float py)
{
	posX = px;
	if (py > 950)
		posY = 950;
	else if (py < 0)
		posY = 0;
	else posY = py;

}

void ObjetoJuego::setVelocidadX(float vx)
{
	velX = vx;

}

void ObjetoJuego::setVelocidadY(float vy)
{
	velY = vy;

}

void ObjetoJuego::setAceleracionX(float ax)
{
	aX = ax;
}

void ObjetoJuego::setAceleracionY(float ay)
{
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

bool ObjetoJuego::getAfectadoPorPulsacion()
{
	return AfectadoPorPulsacion;
}

float ObjetoJuego::getAceleracionX()
{
	return aX;
}

float ObjetoJuego::getAceleracionY()
{
	return aY;
}

float ObjetoJuego::getRozamiento()
{
	return rozamiento;
}