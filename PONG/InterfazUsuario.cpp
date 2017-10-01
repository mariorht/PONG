#include "InterfazUsuario.h"



InterfazUsuario::InterfazUsuario()
{
}


InterfazUsuario::~InterfazUsuario()
{
}


int InterfazUsuario::DetectaPulsacion()
{
	if (GetAsyncKeyState(VK_UP))
		return ARRIBA;
	if (GetAsyncKeyState(VK_DOWN))
		return ABAJO;
	if (GetAsyncKeyState(VK_LEFT))
		return  IZQUIERDA;
	if (GetAsyncKeyState(VK_RIGHT))
		return DERECHA;
	if (GetAsyncKeyState(VK_RETURN))
		return ENTER;





//If a key was pressed
/*if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
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
*/
return 0;
}

