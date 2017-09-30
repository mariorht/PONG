#include "Pared.h"



Pared::Pared(Uint32 color, float px, float py, float w, float h) 
	:ObjetoJuego(color, px, py, 0, 0, 0, 0, w, h, 0)  //FIJAR SIEMPRE VELOCIDAD, ACELERACIÓN, NO SOLO EN CONSTRUCTOR 
{}


Pared::~Pared()
{
}
