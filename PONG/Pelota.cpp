#include "Pelota.h"



Pelota::Pelota(Uint32 color, float px, float py, float vx, float vy, float ax, float ay, float w, float h, float roz)
	:ObjetoJuego(color, px, py, vx, vy, ax, ay, w, h, roz) 
{
	AfectadoPorPulsacion = false;
	PuedoMeterGol = true;
}





