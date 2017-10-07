#include "InterfazUsuario.h"



InterfazUsuario::InterfazUsuario()
{
}



int InterfazUsuario::DetectaPulsacion()
{
	if (GetAsyncKeyState(VK_UP))
		return ARRIBA;
	if (GetAsyncKeyState(VK_DOWN))
		return ABAJO;
	if (GetAsyncKeyState(VK_LEFT))
		return IZQUIERDA;
	if (GetAsyncKeyState(VK_RIGHT))
		return DERECHA;
	if (GetAsyncKeyState(VK_RETURN))
		return ENTER;
	if (GetAsyncKeyState(0x57))
		return TECLA_W;
	if (GetAsyncKeyState(0x53))
		return TECLA_S;
	if (GetAsyncKeyState(0x41))
		return TECLA_A;
	if (GetAsyncKeyState(0x44))
		return TECLA_D;
	
return 0;
}

