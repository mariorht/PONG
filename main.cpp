#include "ObjetoJuego.h"
#include "Render.h"
#include "Pelota.h"
#include "MotorFisica.h"
#include "ColeccionObjetos.h"

//#include <SDL.h>

#include <stdio.h>






int main(int arcg, char * args[])
{
	/*//The window we'll be rendering to
	SDL_Window* window = NULL;

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);

			//Fill the surface white
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

			//Update the surface
			SDL_UpdateWindowSurface(window);


		}
	}
	*/





	//vector<Pelota> mis_pelotas;
	ColeccionObjetos mi_coleccion= ColeccionObjetos();

	for (int i = 5; i < 15; i+=2)
	{
		Pelota mi_pelota = Pelota(i*5.5, i*10, 20, 20, 1, 1, 2, 2, 'O');
		mi_coleccion.AgregaObjeto(&mi_pelota);
	}



	Render motorRender= Render(mi_coleccion);
	MotorFisica motorFisica = MotorFisica(mi_coleccion);


	while (true)
	{
	motorFisica.Actualiza();	
	motorRender.BorraPantalla();
	motorRender.Pinta();




	Sleep(50);

	}

	cin.get();

	


	//Destroy window
//	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	//SDL_Quit();

	

}