#include "Raqueta.h"



Raqueta::Raqueta(Uint32 color, float px, float py, float vy, float ay, float w, float h, float roz, bool IA)
	:ObjetoJuego(color, px, py, 0, vy, 0, ay, w, h, roz) 
{
	ControladoPorIA = IA;
	if (ControladoPorIA)
		AfectadoPorPulsacion = false;
	else
		AfectadoPorPulsacion = true;

	V_max = 7.0;

} //DEFINIR VEL_X=0 SIEMPRE


Raqueta::~Raqueta()
{
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