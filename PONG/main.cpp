
#include "ObjetoJuego.h"
#include "Render.h"
#include "Pelota.h"
#include "MotorFisica.h"
#include"InterfazUsuario.h"
#include "Raqueta.h"
#include "Marcador.h"
#include "LogicaJuego.h"
#include "Pared.h"

#include <SDL.h>
#include <SDL_ttf.h>


#include <stdio.h>


#define Menu 1
#define Juego 2


int main(int arcg, char * args[])
{
	SDL_Window* window = NULL;
	SDL_Surface* screen = NULL;

	



	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL could not initialize! SDL_Error:" << SDL_GetError() << endl;
		return 0;
	}

	if (TTF_Init() < 0)
	{
		cout << "TTF SDL could not initialize!" << endl;
		return 0;
	}
	
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
			
		//MENU----------------------
		
		SDL_Renderer *gRenderer=SDL_CreateRenderer(window, -1, 0);
		SDL_Color negro = { 0, 0, 0, 0 };
		
		TTF_Font *fuente = TTF_OpenFont("C:\\Users\\mario\\Desktop\\PONG\\Debug\\Equalize.ttf", 70);
		SDL_Surface *texto = TTF_RenderText_Solid(fuente, "PONG", negro);
		
		TTF_Font *fuente2 = TTF_OpenFont("C:\\Users\\mario\\Desktop\\PONG\\Debug\\Equalize.ttf", 18);
		SDL_Surface *texto2 = TTF_RenderText_Solid(fuente2, "Pulsa ENTER para jugar", negro);
		
		SDL_Rect CuadroTexto;
		CuadroTexto.x = 300.0 / 1000.0 * SCREEN_WIDTH;
		CuadroTexto.y = 400.0 / 1000.0 * SCREEN_HEIGHT;

		SDL_Rect CuadroTexto2;
		CuadroTexto2.x = 225.0 / 1000.0 * SCREEN_WIDTH;
		CuadroTexto2.y = 650.0 / 1000.0 * SCREEN_HEIGHT;

		SDL_BlitSurface(texto, NULL, screen, &CuadroTexto);
		SDL_BlitSurface(texto2, NULL, screen, &CuadroTexto2);
		SDL_RenderPresent(gRenderer);

		//----------------------

		//Vector de objetos
		ColeccionObjetos mi_coleccion = ColeccionObjetos();

		Uint32 black = SDL_MapRGB(screen->format, 0, 0, 0);
			

		// Crear pelotas
		for (int i = 1; i < 10; i++)
		{
			Pelota *mi_pelota = new Pelota(black, 20*i, 25*i, 10, 7, 0, 0, 20/**De momento este es el tamaño del punto*/, 0);
			mi_coleccion.AgregaObjeto(mi_pelota);
		}

		//Crear resto de basura
		Raqueta mi_raqueta_izq(black, 50.0, 100.0, 0, 0, 20, 200.0, .4);
		Raqueta mi_raqueta_dcha(black, 950.0, 100.0, 0, 0, 20, 200.0, .4);
		mi_coleccion.AgregaObjeto(&mi_raqueta_izq);
		mi_coleccion.AgregaObjeto(&mi_raqueta_dcha);
			


		//Marcador mi_marcador = Marcador(black, 0, 0, 30, 20, 0, 0);
		//mi_coleccion.AgregaObjeto(&mi_marcador);

		Pared p_dcha(black, 1000 - 20, 0, 20, 1000);
		Pared p_izda(black, 0, 0, 20, 1000);
		Pared p_arriba(black, 0, 0, 1000, 20);
		Pared p_abajo(black, 0, 1000 - 20, 1000, 20);
		mi_coleccion.AgregaObjeto(&p_abajo);
		mi_coleccion.AgregaObjeto(&p_arriba);
		mi_coleccion.AgregaObjeto(&p_dcha);
		mi_coleccion.AgregaObjeto(&p_izda);

		LogicaJuego logicaJuego = LogicaJuego();
		Render motorRender = Render(mi_coleccion, screen);
		MotorFisica motorFisica = MotorFisica(mi_coleccion);

		SDL_UpdateWindowSurface(window);

		InterfazUsuario miIU;

		//Flag bucle
		bool cerrar = FALSE;
		SDL_Event e;

		int estado = Menu;

		while (!cerrar)
		{

			while (SDL_PollEvent(&e))
			{
				if (e.type == SDL_QUIT)
					cerrar = true;
			}

			//Menú de inicio
				
			switch (estado)
			{

			case Menu: 
			{
				if (miIU.DetectaPulsacion() == ENTER)
					estado = Juego;
			
			}break;


			case Juego:
			{

				motorFisica.Actualiza(miIU.DetectaPulsacion());
				motorRender.BorraPantalla();
				motorRender.DibujaTodo();
				//logicaJuego.ControlaMarcador(&mi_marcador, mi_coleccion);

				/*
				Campo mi_campo = Campo(black, ancho_campo, alto_campo);
				mi_coleccion.AgregaObjeto(&mi_campo);
				*/

				SDL_UpdateWindowSurface(window);

				if (GetAsyncKeyState(VK_UP))
					cout << "Pulsado arriba" << endl;
				if (GetAsyncKeyState(VK_DOWN))
					cout << "Pulsado abajo" << endl;
			} break;

			}

				




			Sleep(10);

		}

			

	}
	
	



	
	


	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();
	TTF_Quit();

	return 0;

	

}