#include "LogicaJuego.h"
#include "Campo.h"




LogicaJuego::LogicaJuego()
{
}


LogicaJuego::~LogicaJuego()
{
}

void LogicaJuego::ControlaMarcador(Marcador * mi_marcador, ColeccionObjetos coleccion)
{
	int puntuacion_A, puntuacion_B;
	puntuacion_A = mi_marcador->getGolesA();
	puntuacion_B = mi_marcador->getGolesB();

	vector<ObjetoJuego*> mis_objetos = coleccion.getColeccionObjetos();
	int n_objetos = coleccion.getTamColeccion();

	for (int i = 0; i < n_objetos; i++) {

		if (mis_objetos[i]->getPuedoMeterGol()) 
		{
			if ((mis_objetos[i]->getPosicionX()) > 940) //MIRAR TAMAÑO
			{
				mi_marcador->AumentaGolA();
				cout << "Gol del equipo A" << endl;
			}

			else if ((mis_objetos[i]->getPosicionX()) < 20)//MIRAR TAMAÑO
			{
				mi_marcador->AumentaGolB();
				cout << "Gol del equipo B" << endl;
			}
		}
	}

	

	



}
