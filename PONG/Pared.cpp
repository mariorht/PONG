#include "Pared.h"



Pared::Pared(Uint32 color, float px, float py, float w, float h, Campo *mi_campo, bool atravesado) 
	:ObjetoJuego(color, px, py, 0, 0, 0, 0, w, h, 0, mi_campo)  //FIJAR SIEMPRE VELOCIDAD, ACELERACIÓN, NO SOLO EN CONSTRUCTOR 
{
	EsAtravesado = atravesado;
}


Pared::~Pared()
{
}
