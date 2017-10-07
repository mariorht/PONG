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
	int i = 0;
	obj = objetos[i];
	// Búsqueda del objeto a borra en la colección 
	while (i < tam_coleccion && obj != objeto)
	{
		i++;
		obj = objetos[i];
	}

	// Si se encuentra se borra
	if (i < tam_coleccion)
	{
		objetos.erase(objetos.begin() + i);
		tam_coleccion--;
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


