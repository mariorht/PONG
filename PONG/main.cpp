
#include "ObjetoJuego.h"
#include "Render.h"
#include "Pelota.h"
#include "MotorFisica.h"
#include"InterfazUsuario.h"
#include "Raqueta.h"
#include "Marcador.h"
#include "LogicaJuego.h"

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
			ColeccionObjetos mi_coleccion = ColeccionObjetos();

			Uint32 black = SDL_MapRGB(screen->format, 0, 0, 0);
			
			for (int i = 1; i < 4; i++)
			{
				Pelota *mi_pelota = new Pelota(black, 250*i, 250*i, 5, 10, 0, 0, 50, 50, 0);
				mi_coleccion.AgregaObjeto(mi_pelota);
			}

			Raqueta mi_raqueta(black, 50.0, 500.0, 0, 0, 25.0, 200.0, .4);
			mi_coleccion.AgregaObjeto(&mi_raqueta);
			
			Render motorRender = Render(mi_coleccion, screen);
			MotorFisica motorFisica = MotorFisica(mi_coleccion);

			Marcador mi_marcador = Marcador(black, 0, 0, 30, 20, 0, 0);
			mi_coleccion.AgregaObjeto(&mi_marcador);
			LogicaJuego logicaJuego = LogicaJuego();

			SDL_UpdateWindowSurface(window);

			InterfazUsuario miIU;

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


				motorFisica.Actualiza(miIU.DetectaPulsacion());
				motorRender.BorraPantalla();
				motorRender.DibujaTodo();
				logicaJuego.ControlaMarcador(&mi_marcador, mi_coleccion);

				/*
				Campo mi_campo = Campo(black, ancho_campo, alto_campo);
				mi_coleccion.AgregaObjeto(&mi_campo);
				*/

				SDL_UpdateWindowSurface(window);
				
				if (GetAsyncKeyState(VK_UP))
					cout << "Pulsado arriba" << endl;
				if (GetAsyncKeyState(VK_DOWN))
					cout << "Pulsado abajo" << endl;




				Sleep(20);

			}

			

		}
	}
	



	
	


	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();

	return 0;

	

}