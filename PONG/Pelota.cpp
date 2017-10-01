#include "Pelota.h"



Pelota::Pelota(Uint32 color, float px, float py, float vx, float vy, float ax, float ay, float r, float roz)
	:ObjetoJuego(color, px, py, vx, vy, ax, ay, 2*r, 2*r, roz) 
{
	AfectadoPorPulsacion = false;
	PuedoMeterGol = true;
	AfectadoPorChoque = true;
	Forma = "circulo";
}





