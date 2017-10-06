#include "ColeccionObjetos.h"



vector<ObjetoJuego*> ColeccionObjetos::getColeccionObjetos()
{
	return objetos;
}

int ColeccionObjetos::getTamColeccion()
{
	return tam_coleccion;;
}

void ColeccionObjetos::AgregaObjeto(ObjetoJuego * objeto)
{
	objetos.push_back(objeto);
	tam_coleccion = objetos.size();
}


void ColeccionObjetos::EliminaObjeto(ObjetoJuego *objeto)
{
	ObjetoJuego* obj;
	for (int i = 0; i < tam_coleccion; i++) {
		obj = objetos[i];
		if (obj == objeto)
		{
			objetos.erase(objetos.begin() + i);
			tam_coleccion--;
		}

	}

}

void ColeccionObjetos::EliminaUltimoObjeto()
{
	objetos.pop_back();
	tam_coleccion--;
}

ColeccionObjetos::ColeccionObjetos() 
{
}




ColeccionObjetos::~ColeccionObjetos()
{
}
