#include "Menu.h"


TTF_Font *Menu::CargarFuente(string tipo_fuente, float tam_fuente)
{
	fuente = TTF_OpenFont(tipo_fuente.c_str(), tam_fuente / 1000.0 * SCREEN_WIDTH); // Se carga la fuente con un tamaño determinado
	
	// Si no se puede abrir se lanza una excepción
	if (fuente == NULL)
		throw 0;
	return fuente;

}

Menu::Menu(string tipo_fuente, float tam_fuente, SDL_Window * window)
{
	// Se carga la fuente, si se produce una excepción se escribe un mensaje de error
	try 
	{
		fuente = CargarFuente(tipo_fuente, tam_fuente);
	}
	catch (int error)
	{
		cout << "Error al cargar la fuente: " << error <<  endl;
	}
}



TTF_Font *Menu::GetFuente()
{
	return fuente;
}
