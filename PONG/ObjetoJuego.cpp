#include "ObjetoJuego.h"
#include "Campo.h"


ObjetoJuego::ObjetoJuego(Uint32 c, float px, float py, float vx, float vy, float ax, float ay, float w, float h, float roz, Campo *mi_campo_)
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
	PuedoMeterGol = false;
	AfectadoPorPulsacion = false;
	AfectadoPorChoque = false;
	SiRebotoSueno = false;
	Forma = "rectangulo";
	campo = mi_campo_;
	EsAtravesado = false;

}



Uint32 ObjetoJuego::getColor()
{
	return color;
}

void ObjetoJuego::setPosicionX(float px)
{
	float ancho_campo = campo->getAnchoCampo();
	if (px > ancho_campo-ancho) 
		posX = ancho_campo - ancho;
	else if (px < 0)
		posX = 0;
	else posX = px;

}

void ObjetoJuego::setPosicionY(float py)
{
	float alto_campo = campo->getAltoCampo();
	if (py > alto_campo - alto)
		posY = alto_campo - alto;
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

bool ObjetoJuego::getPuedoMeterGol()
{
	return PuedoMeterGol;
}

bool ObjetoJuego::getSiRebotoSueno()
{
	return SiRebotoSueno;
}

bool ObjetoJuego::getAfectadoPorChoque()
{
	return AfectadoPorChoque;
}

bool ObjetoJuego::getEsAtravesado()
{
	return EsAtravesado;
}

string ObjetoJuego::getForma()
{
	return Forma;
}

