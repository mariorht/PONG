#include "ObjetoJuego.h"
#include "Render.h"
#include "Pelota.h"
#include "MotorFisica.h"




void main()
{
	vector<Pelota> mis_pelotas;

	for (int i = 3; i < 35; i++)
	{
		Pelota mi_pelota = Pelota(i, i, 1.5*i, 2*i, 1, 1, 1, 1);
		mis_pelotas.push_back(mi_pelota);
	}



	Render motorRender= Render(&mis_pelotas);
	MotorFisica motorFisica = MotorFisica(&mis_pelotas);


	while (true)
	{
	motorFisica.Actualiza();	
	motorRender.BorraPantalla();
	motorRender.Pinta();




	Sleep(20);

	}

	cin.get();

	
	

}