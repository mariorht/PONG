#include "Raqueta.h"



Raqueta::Raqueta(Uint32 color, float px, float py, float vy, float ay, float w, float h, float roz, Campo *mi_campo)
	:ObjetoJuego(color, px, py, 0, vy, 0, ay, w, h, roz, mi_campo) 
{
	ControladoPorIA = false;
	AfectadoPorPulsacion = true;
	V_max = 7.0;

} 



void Raqueta::setIAoff()
{
	ControladoPorIA = false;
	AfectadoPorPulsacion = true;
}

void Raqueta::setIAon()
{
	ControladoPorIA = true;
	AfectadoPorPulsacion = false;
}

void Raqueta::setVelocidadX(float vx)
{
	velX = vx;
	if (velX > V_max)
		velX = V_max;

	if (velX < - V_max)
		velX = -V_max;

}

void Raqueta::setVelocidadY(float vy)
{
	velY = vy;
	if (velY > V_max)
		velY = V_max;
	if (velY < -V_max)
		velY = -V_max;
}

void Raqueta::setPosicionY(float py)
{
	float alto_campo = campo->getAltoCampo();
	if (py > alto_campo - 2*ancho - alto)
		posY = alto_campo - 2*ancho - alto;
	else if (py < 2*ancho)
		posY = 2*ancho;
	else posY = py;

}

bool Raqueta::esControladoPorIA()
{
	return ControladoPorIA;
}