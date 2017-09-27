
#include "ObjetoJuego.h"
#include "Render.h"
#include "Pelota.h"
#include "MotorFisica.h"

#include <SDL.h>

#include <SDL.h>
#include <stdio.h>





int main(int arcg, char * args[])
{
	SDL_Window* window = NULL;
	SDL_Surface* screen = NULL;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL could not initialize! SDL_Error:" << SDL_GetError() << endl;
	}
	else
	{
		//Create window
		window = SDL_CreateWindow("PONG",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			cout << "Window could not be created! SDL_Error:" << SDL_GetError() << endl;
		}
		else
		{
			//Get window surface
			screen = SDL_GetWindowSurface(window);

			//Fill the surface white
			SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));

			//Update the surface
			SDL_UpdateWindowSurface(window);
			


			//Vector de objetos
			vector<Pelota> mis_pelotas;

			Uint32 black = SDL_MapRGB(screen->format, 0, 0, 0);
			
			for (int i = 1; i < 2; i++)
			{
				Pelota mi_pelota(black, 25*i, 25*i, 20, 10, 0, 0, 20, 20);
				mis_pelotas.push_back(mi_pelota);
			}
			
			Render motorRender = Render(&mis_pelotas, screen);
			MotorFisica motorFisica = MotorFisica(&mis_pelotas);

			SDL_UpdateWindowSurface(window);


			//Flag bucle
			bool cerrar = FALSE;
			SDL_Event e;

			while (!cerrar)
			{
				while (SDL_PollEvent(&e))
				{
					if (e.type == SDL_QUIT)
						cerrar = true;
				}
				motorFisica.Actualiza();
				motorRender.BorraPantalla();
				motorRender.Pinta();

				SDL_UpdateWindowSurface(window);




				Sleep(50);

			}

			

		}
	}
	



	
	


	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();

	return 0;

	

}