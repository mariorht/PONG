#pragma once

#include <Windows.h>

#define ARRIBA 1
#define ABAJO 2
#define IZQUIERDA 3
#define DERECHA 4
#define ENTER 5

class InterfazUsuario
{
public:
	InterfazUsuario();
	~InterfazUsuario();

	int DetectaPulsacion();

};

