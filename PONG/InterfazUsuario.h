#pragma once

#include <Windows.h>

#define ARRIBA 1
#define ABAJO 2
#define IZQUIERDA 3
#define DERECHA 4
#define ENTER 5
#define TECLA_W 6
#define TECLA_S 7
#define TECLA_A 8
#define TECLA_D 9
#define ESC 10

class InterfazUsuario
{
public:
	InterfazUsuario();
	~InterfazUsuario();

	int DetectaPulsacion();

};

