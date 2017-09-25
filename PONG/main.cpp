#include "ObjetoJuego.h"
#include "Render.h"
#include "Pelota.h"
#include "MotorFisica.h"




void main()
{


	Pelota *pelota1 = &Pelota(0,0,1,1,1,1,1,1);
	Render motorRender= Render(pelota1);
	MotorFisica motorFisica = MotorFisica(pelota1);

	Pelota *pelota2 = &Pelota(20, 30, 1, 1, 1, 1, 1, 1);
	Render motorRender2 = Render(pelota2);
	MotorFisica motorFisica2 = MotorFisica(pelota2);

	while (true)
	{
	motorFisica.Actualiza();
	
	motorRender.BorraPantalla();
	motorRender.Pinta();

	motorFisica2.Actualiza();

	motorRender2.Pinta();


	Sleep(20);

	}

	cin.get();

	
	

}