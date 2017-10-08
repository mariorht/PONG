#include "LogicaJuego.h"
#include "Campo.h"




LogicaJuego::LogicaJuego()
{
}



bool LogicaJuego::ControlaMarcador(Marcador * mi_marcador, ColeccionObjetos coleccion, Campo *campo)
{
	bool GolMarcado = false;
	int puntuacion_A, puntuacion_B;
	puntuacion_A = mi_marcador->getGolesA();
	puntuacion_B = mi_marcador->getGolesB();

	float ancho_campo = campo->getAnchoCampo();
	float alto_campo = campo->getAltoCampo();

	vector<ObjetoJuego*> mis_objetos = coleccion.getColeccionObjetos();
	int n_objetos = coleccion.getTamColeccion();

	for (int i = 0; i < n_objetos; i++) {

		if (mis_objetos[i]->getPuedoMeterGol()) 
		{
			// Si la pelota supera la portería derecha se aumentan los goles del equipo 1 
			// y la pelota se traslada a una posición aleatoria alrededor del centro del campo
			// con velocidad aleatoria entre ciertos valores
			if ((mis_objetos[i]->getPosicionX()) > campo->getPosPorteriaDcha() ) 
			{

				mi_marcador->AumentaGolA();
				GolMarcado = true;
				mis_objetos[i]->setPosicionX(0.3*ancho_campo + rand()% (int)(0.6*ancho_campo-0.3*ancho_campo));
				mis_objetos[i]->setPosicionY(0.1*alto_campo + rand() % (int)(0.9*alto_campo - 0.1*alto_campo));

				mis_objetos[i]->setVelocidadX(3.0 + rand() % (8 - 3));
				mis_objetos[i]->setVelocidadY(3.0 + rand() % (8 - 3));
				

			}

			// Si la pelota supera la portería izquierda se aumentan los goles del equipo 2 
			// y la pelota se traslada a una posición aleatoria alrededor del centro del campo
			// con velocidad aleatoria entre ciertos valores
			else if ((mis_objetos[i]->getPosicionX()) < campo->getPosPorteriaIzq())
			{
				mi_marcador->AumentaGolB();
				GolMarcado = true;
				mis_objetos[i]->setPosicionX(0.3*ancho_campo + rand() % (int)(0.6*ancho_campo - 0.3*ancho_campo));
				mis_objetos[i]->setPosicionY(0.1*alto_campo + rand() % (int)(0.9*alto_campo - 0.1*alto_campo));

				mis_objetos[i]->setVelocidadX(-8.0 + rand() % (-3 + 8));
				mis_objetos[i]->setVelocidadY(-8.0 + rand() % (-3 + 8));


			}
		}
		
	}

	
	return GolMarcado;
}
