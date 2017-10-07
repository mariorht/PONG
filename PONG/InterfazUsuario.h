#pragma once

#include <Windows.h>

// Definición pulsaciones de teclas
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

// Clase que detecta pulsaciones del teclado
class InterfazUsuario
{
public:

	/** Constructor */
	InterfazUsuario();
	
	/** Devuelve qué tecla se ha pulsado*/
	int DetectaPulsacion();

};

