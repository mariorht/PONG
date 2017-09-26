#include "ObjetoJuego.h"


ObjetoJuego::ObjetoJuego(Uint32 color, float px, float py, float vx, float vy, float ax, float ay, float w, float h)
{
	posX=px;
	posY=py;
	velX=vx;
	velY=vy;
	aX=ax;
	aY=ay;
	ancho=w;
	alto=h;

	image = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);

	SDL_FillRect(image, NULL, color);
	rect = image->clip_rect;
	
	rect.x = px ;
	rect.y = py ;
}





void ObjetoJuego::setPosicion(float px, float py)
{
	posX = px;
	posY = py;
	rect.x = px;
	rect.y = py;
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

void ObjetoJuego::Dibuja(SDL_Surface * destination)
{
	SDL_BlitSurface(image, NULL, destination, &rect);
}