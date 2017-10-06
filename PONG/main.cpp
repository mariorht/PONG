#include "ObjetoJuego.h"
#include "Render.h"
#include "Pelota.h"
#include "MotorFisica.h"
#include"InterfazUsuario.h"
#include "Raqueta.h"
#include "Marcador.h"
#include "LogicaJuego.h"
#include "Pared.h"
#include "InteligenciaArtificial.h"

#include <SDL.h>
#include <SDL_ttf.h>





#define MenuInicio 1
#define ModosJuego 2

#define ModoUnJugador 3
#define ModoDosJugadores 4
#define ModoCaos 5

#define JuegoUnJugador 6
#define JuegoDosJugadores 7
#define JuegoCaos 8
#define Jugando 9





int main(int arcg, char * args[])
{
	srand (GetTickCount());

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
			
	
		//Vector de objetos
		ColeccionObjetos mi_coleccion = ColeccionObjetos();

		Uint32 black = SDL_MapRGB(screen->format, 0, 0, 0);
			
		Pelota *mi_pelota;
		// Crear pelotas
		for (int i = 1; i <2; i++)
		{
			mi_pelota = new Pelota(black, 55*i, 25*i, 6.5, 7, 0, 0, 20/**De momento este es el tamaño del punto*/, 0);
			mi_coleccion.AgregaObjeto(mi_pelota);
		}

		


		//Crear resto de basura
		Raqueta mi_raqueta_izq(black, 50.0, 100.0, 0, 0, 20, 150.0, .1);
		Raqueta mi_raqueta_dcha(black, 950.0, 500.0, 0, 0, 20, 200.0, .1);
		mi_coleccion.AgregaObjeto(&mi_raqueta_izq);
		mi_coleccion.AgregaObjeto(&mi_raqueta_dcha);

		InteligenciaArtificial miIA(&mi_raqueta_dcha);

		
		
		
		
		Pared p_dcha(black, 1000 - 20, 100, 20, 1000);
		Pared p_izda(black, 0, 100, 20, 1000);
		Pared p_arriba(black, 0, 0, 1000, 20);
		Pared p_abajo(black, 0, 1000 - 20, 1000, 20);
		mi_coleccion.AgregaObjeto(&p_abajo);
		mi_coleccion.AgregaObjeto(&p_arriba);
		mi_coleccion.AgregaObjeto(&p_dcha);
		mi_coleccion.AgregaObjeto(&p_izda);

		LogicaJuego logicaJuego = LogicaJuego();
		Render motorRender = Render(&mi_coleccion, screen);
		MotorFisica motorFisica = MotorFisica(&mi_coleccion);

		//Inicialización del marcador

		Marcador mi_marcador = Marcador(black, 0, 0, 30, 20, 0, 0);
		mi_coleccion.AgregaObjeto(&mi_marcador);
		int golesA = 0, golesB = 0;
		string s_golesA, s_golesB;

		//Inicialización parámetros escritura
		string fuente = "Equalize.ttf";
		string fuente_menu = "Flying Bird.ttf";
		float tam_fuente_titulo = 70;
		float tam_fuente_titulo2 = 18;
		float tam_fuente_menu = 50;
		float tam_fuente_marcador = 50;
		SDL_Color negro = { 0, 0, 0, 0 };
		SDL_Color azul = { 96, 111, 140, 0 };

		Menu menu_titulo(fuente, tam_fuente_titulo, window);
		Menu menu_titulo2(fuente, tam_fuente_titulo2, window);
		Menu menu_modos(fuente_menu, tam_fuente_menu, window);
		Menu menu_marcador(fuente, tam_fuente_marcador, window);
	

		InterfazUsuario miIU;

		//Flag bucle
		bool cerrar = FALSE;
		// Flag menu
		bool recien_entrado = true;
		SDL_Event e;

		int estado = MenuInicio;
		int modo = ModoUnJugador;

		int cont = 0;

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

			case MenuInicio:
			{
				if (recien_entrado)
				{
					recien_entrado = false;
					motorRender.Escribe(menu_titulo, window, "PONG", negro, 300, 400);
					motorRender.Escribe(menu_titulo2, window, "Pulsa ENTER para continuar", negro, 225, 650);
					SDL_UpdateWindowSurface(window);
				}

				if (miIU.DetectaPulsacion() == ENTER)
				{
					estado = ModosJuego;
					recien_entrado = true;
					SDL_Delay(150);
				}

			}break;

			case ModosJuego:
			{

				switch (modo)
				{
				case ModoUnJugador:
				{
					if (recien_entrado)
					{
						recien_entrado = false;
						motorRender.BorraPantalla();
						motorRender.Escribe(menu_titulo, window, "PONG", negro, 300, 400);
						motorRender.Escribe(menu_modos, window, "Un jugador", azul, 225, 650);
						motorRender.Escribe(menu_modos, window, "Dos jugadores", negro, 225, 750);
						motorRender.Escribe(menu_modos, window, "Modo caos (Dos jugadores)", negro, 225, 850);
						SDL_UpdateWindowSurface(window);
					}

					if (miIU.DetectaPulsacion() == ENTER)
					{
						modo = JuegoUnJugador;
						estado = Jugando;
						recien_entrado = true;
						SDL_Delay(150);
					}
					if (miIU.DetectaPulsacion() == ARRIBA)
					{
						recien_entrado = true;
						modo = ModoCaos;
						SDL_Delay(150);
					}
					if (miIU.DetectaPulsacion() == ABAJO)
					{
						recien_entrado = true;
						modo = ModoDosJugadores;
						SDL_Delay(150);
					}
				}break;


				case ModoDosJugadores:
				{
					if (recien_entrado)
					{
						recien_entrado = false;
						motorRender.BorraPantalla();
						motorRender.Escribe(menu_titulo, window, "PONG", negro, 300, 400);
						motorRender.Escribe(menu_modos, window, "Un jugador", negro, 225, 650);
						motorRender.Escribe(menu_modos, window, "Dos jugadores", azul, 225, 750);
						motorRender.Escribe(menu_modos, window, "Modo caos (Dos jugadores)", negro, 225, 850);
						SDL_UpdateWindowSurface(window);
					}

					if (miIU.DetectaPulsacion() == ENTER)
					{
						modo = JuegoDosJugadores;
						estado = Jugando;
						SDL_Delay(150);
						recien_entrado = true;
					}
					if (miIU.DetectaPulsacion() == ARRIBA)
					{
						modo = ModoUnJugador;
						SDL_Delay(150);
						recien_entrado = true;
					}
					if (miIU.DetectaPulsacion() == ABAJO)
					{
						modo = ModoCaos;
						SDL_Delay(150);
						recien_entrado = true;
					}

				}break;

				case ModoCaos:
				{
					if (recien_entrado)
					{
						recien_entrado = false;
						motorRender.BorraPantalla();
						motorRender.Escribe(menu_titulo, window, "PONG", negro, 300, 400);
						motorRender.Escribe(menu_modos, window, "Un jugador", negro, 225, 650);
						motorRender.Escribe(menu_modos, window, "Dos jugadores", negro, 225, 750);
						motorRender.Escribe(menu_modos, window, "Modo caos (Dos jugadores)", azul, 225, 850);
						SDL_UpdateWindowSurface(window);
					}

					if (miIU.DetectaPulsacion() == ENTER)
					{
						modo = JuegoCaos;
						estado = Jugando;
						SDL_Delay(150);
						recien_entrado = true;
					}

					if (miIU.DetectaPulsacion() == ARRIBA)
					{
						modo = ModoDosJugadores;
						SDL_Delay(150);
						recien_entrado = true;
					}
					if (miIU.DetectaPulsacion() == ABAJO)
					{
						modo = ModoUnJugador;
						SDL_Delay(150);
						recien_entrado = true;
					}

				}break;
				}

			}break;

			case Jugando:
			{	
				switch (modo)
			{

			case JuegoUnJugador:
			{
				if (recien_entrado)
				{
					
					mi_raqueta_dcha.setIAon();
					recien_entrado = false;
				}
				



			} break;

			case JuegoDosJugadores:
			{

			}
			break;
			case JuegoCaos:
			{
				if (recien_entrado)
				{
					recien_entrado = false;

					//mi_pelota = new Pelota(black, 555, 25, 6.5, 7, 0, 0, 20/**De momento este es el tamaño del punto*/, 0);
					//mi_coleccion.AgregaObjeto(mi_pelota);
					for (int i = 0; i < 1; i++)
					{
						mi_pelota = new Pelota(black, 55 * i, 25 * i, 6.5, 7, 0, 0, 20/**De momento este es el tamaño del punto*/, 0);
						mi_coleccion.AgregaObjeto(mi_pelota);
					}


				}
				cont++;


				if (cont == 1000 )
				{
					mi_pelota = new Pelota(black,
										400 + rand() % (600 - 400),
										100 + rand() % (900 - 100),
										6.5,
										7,
										0,
										0,
										20/**De momento este es el tamaño del punto*/, 
										0);
					mi_coleccion.AgregaObjeto(mi_pelota);

					Pared *pared = new Pared(black,
						400 + rand() % (700 - 300),
						100 + rand() % (900 - 100),
						20 + rand() % (150 - 20),
						20 + rand() % (150 - 20));
					mi_coleccion.AgregaObjeto(pared);


				}

				if (cont == 2000)
				{
				
					mi_coleccion.EliminaUltimoObjeto();
					Pared *pared= new Pared(black,	
											400 + rand() % (700 - 300),
											100 + rand() % (900 - 100), 
											20 + rand() % (150 - 20),
											20 + rand() % (150 - 20));
											mi_coleccion.AgregaObjeto(pared);
					cont = 0;
				}



			}
			break;
			}


			motorRender.BorraPantalla();
			miIA.EligeMovimiento(mi_pelota);
			


			motorFisica.Actualiza(miIU.DetectaPulsacion());
			
			motorRender.DibujaTodo();

			logicaJuego.ControlaMarcador(&mi_marcador, mi_coleccion);


			golesA = mi_marcador.getGolesA();
			golesB = mi_marcador.getGolesB();

			s_golesA = to_string(golesA);
			s_golesB = to_string(golesB);

			motorRender.Escribe(menu_marcador, window, s_golesA, negro, 300, 400);
			motorRender.Escribe(menu_marcador, window, s_golesB, negro, 600, 400);

			/*
			Campo mi_campo = Campo(black, ancho_campo, alto_campo);
			mi_coleccion.AgregaObjeto(&mi_campo);
			*/


			SDL_UpdateWindowSurface(window);
			} 
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