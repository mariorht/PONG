#include "ObjetoJuego.h"
#include "Render.h"
#include "Pelota.h"
#include "MotorFisica.h"




void main()
{
	vector<Pelota> mis_pelotas;

	for (int i = 5; i < 10; i++)
	{
		Pelota mi_pelota = Pelota(i, i, i/2, i/5, 1, 1, 1, 1);
		mis_pelotas.push_back(mi_pelota);
	}



	Render motorRender= Render(&mis_pelotas);
	MotorFisica motorFisica = MotorFisica(&mis_pelotas);


	while (true)
	{
	motorFisica.Actualiza();	
	motorRender.BorraPantalla();
	motorRender.Pinta();




	Sleep(50);

	}

	cin.get();

	
	

}