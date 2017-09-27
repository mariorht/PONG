#include "InterfazUsuario.h"



InterfazUsuario::InterfazUsuario()
{
}


InterfazUsuario::~InterfazUsuario()
{
}


int InterfazUsuario::DetectaPulsacion(SDL_Event & e)
{
//If a key was pressed
if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
{
	//Adjust the velocity
	switch (e.key.keysym.sym)
	{
		case SDLK_UP: return ARRIBA;
		case SDLK_DOWN: return ABAJO;
		case SDLK_LEFT: return  IZQUIERDA;
		case SDLK_RIGHT: return DERECHA;
		
	}
}
return 0;
}

