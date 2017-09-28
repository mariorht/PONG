#include "Raqueta.h"



Raqueta::Raqueta(Uint32 color, float px, float py, float vy, float ay, float w, float h, float roz)
	:ObjetoJuego(color, px, py, 0, vy, 0, ay, w, h, roz) 
{
	AfectadoPorPulsacion = true;
} //DEFINIR VEL_X=0 SIEMPRE


Raqueta::~Raqueta()
{
}
