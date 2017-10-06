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
#include "Campo.h"

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

	//Inicilizar SDL
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
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

		//Update the surface
		SDL_UpdateWindowSurface(window);
			
		// Campo
		Campo *mi_campo = new Campo(1920, 1080);
		float ancho_campo = mi_campo->getAnchoCampo();
		float alto_campo = mi_campo->getAltoCampo();

		//Vector de objetos
		ColeccionObjetos mi_coleccion = ColeccionObjetos();

		Uint32 white = SDL_MapRGB(screen->format, 242, 254, 255);
		
		// Crear pelotas
		Pelota *mi_pelota;
		for (int i = 1; i <2; i++)
		{
			mi_pelota = new Pelota(white, ancho_campo*0.12*i, alto_campo*0.05*i, 6.5, 7, 0, 0, 20/**De momento este es el tamaño del punto*/, 0, mi_campo);
			mi_coleccion.AgregaObjeto(mi_pelota);
		}


		

		//Crear resto de elementos

		float ancho_raqueta = ancho_campo * 0.01;
		float alto_raqueta = alto_campo * 0.15;
		Raqueta mi_raqueta_izq(white, mi_campo->getPosPorteriaIzq(), ancho_campo*0.5, 0, 0, ancho_raqueta, alto_raqueta, .1, mi_campo);
		Raqueta mi_raqueta_dcha(white, mi_campo->getPosPorteriaDcha()-ancho_raqueta, ancho_campo*0.5, 0, 0, ancho_raqueta, alto_raqueta, .1, mi_campo);
		mi_coleccion.AgregaObjeto(&mi_raqueta_izq);
		mi_coleccion.AgregaObjeto(&mi_raqueta_dcha);

		InteligenciaArtificial miIA(&mi_raqueta_dcha);

		
		Pared p_arriba(white, 0, 0.02*alto_campo, ancho_campo, 0.02*alto_campo, mi_campo, false);
		Pared p_abajo(white, 0, 0.96*alto_campo, ancho_campo, 0.02*alto_campo, mi_campo, false);

		mi_coleccion.AgregaObjeto(&p_abajo);
		mi_coleccion.AgregaObjeto(&p_arriba);
		
		Pared decoracion(white, 0.5*ancho_campo, 0.1*alto_campo, 0.02*alto_campo, 0.15*alto_campo, mi_campo, true);
		Pared decoracion2(white, 0.5*ancho_campo, 0.30*alto_campo, 0.02*alto_campo, 0.15*alto_campo, mi_campo, true);
		Pared decoracion3(white, 0.5*ancho_campo, 0.50*alto_campo, 0.02*alto_campo, 0.15*alto_campo, mi_campo, true);
		Pared decoracion4(white, 0.5*ancho_campo, 0.70*alto_campo, 0.02*alto_campo, 0.15*alto_campo, mi_campo, true);
		
		mi_coleccion.AgregaObjeto(&decoracion);
		mi_coleccion.AgregaObjeto(&decoracion2);
		mi_coleccion.AgregaObjeto(&decoracion3);
		mi_coleccion.AgregaObjeto(&decoracion4);


		LogicaJuego logicaJuego = LogicaJuego();
		Render motorRender = Render(&mi_coleccion, screen);
		MotorFisica motorFisica = MotorFisica(&mi_coleccion);

		//Inicialización del marcador

		Marcador mi_marcador = Marcador(0, 0);
		int golesA = 0, golesB = 0;
		string s_golesA, s_golesB;

		//Inicialización parámetros escritura
		string fuente = "Equalize.ttf";
		string fuente_menu = "AldoTheApache.ttf";
		float tam_fuente_titulo = alto_campo*0.07;
		float tam_fuente_titulo2 = alto_campo*0.02;
		float tam_fuente_menu = alto_campo*0.03;
		float tam_fuente_marcador = alto_campo*0.035;
		SDL_Color blanco = { 255, 255, 255, 0 };
		SDL_Color azul = { 92, 156, 188, 0 };

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
				if (e.type == SDL_QUIT || e.key.keysym.sym== SDLK_ESCAPE)
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
					motorRender.Escribe(menu_titulo, window, "PONG", blanco, 0.3*ancho_campo, 0.35*alto_campo, mi_campo);
					motorRender.Escribe(menu_titulo2, window, "Pulsa ENTER para continuar", blanco, 0.20*ancho_campo, 0.6*alto_campo, mi_campo);
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
						motorRender.Escribe(menu_titulo, window, "PONG", blanco, 0.3*ancho_campo, 0.35*alto_campo, mi_campo);
						motorRender.Escribe(menu_modos, window, "UN JUGADOR", azul, 0.25*ancho_campo, 0.65*alto_campo, mi_campo);
						motorRender.Escribe(menu_modos, window, "DOS JUGADORES", blanco, 0.25*ancho_campo, 0.75*alto_campo, mi_campo);
						motorRender.Escribe(menu_modos, window, "MODO EXPERTO (DOS JUGADORES)", blanco, 0.25*ancho_campo, 0.85*alto_campo, mi_campo);
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
						motorRender.Escribe(menu_titulo, window, "PONG", blanco, 0.3*ancho_campo, 0.35*alto_campo, mi_campo);
						motorRender.Escribe(menu_modos, window, "UN JUGADOR", blanco, 0.25*ancho_campo, 0.65*alto_campo, mi_campo);
						motorRender.Escribe(menu_modos, window, "DOS JUGADORES", azul, 0.25*ancho_campo, 0.75*alto_campo, mi_campo);
						motorRender.Escribe(menu_modos, window, "MODO EXPERTO (DOS JUGADORES)", blanco, 0.25*ancho_campo, 0.85*alto_campo, mi_campo);
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
						motorRender.Escribe(menu_titulo, window, "PONG", blanco, 0.3*ancho_campo, 0.35*alto_campo, mi_campo);
						motorRender.Escribe(menu_modos, window, "UN JUGADOR", blanco, 0.25*ancho_campo, 0.65*alto_campo, mi_campo);
						motorRender.Escribe(menu_modos, window, "DOS JUGADORES", blanco, 0.25*ancho_campo, 0.75*alto_campo, mi_campo);
						motorRender.Escribe(menu_modos, window, "MODO EXPERTO (DOS JUGADORES)", azul, 0.25*ancho_campo, 0.85*alto_campo, mi_campo);
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

					mi_pelota = new Pelota(white, 55, 25, 6.5, 7, 0, 0, 12/**De momento este es el tamaño del punto*/, 0, mi_campo);
					mi_coleccion.AgregaObjeto(mi_pelota);
					for (int i = 1; i < 0; i++)
					{
						mi_pelota = new Pelota(white, 55 * i, 25 * i, 6.5, 7, 0, 0, 20/**De momento este es el tamaño del punto*/, 0, mi_campo);
						mi_coleccion.AgregaObjeto(mi_pelota);
					}
				}


					cont++;


					if (cont == 1000)
					{
						mi_pelota = new Pelota(white,
							400 + rand() % (600 - 400),
							100 + rand() % (900 - 100),
							6.5,
							7,
							0,
							0,
							12/**De momento este es el tamaño del punto*/,
							0,
							mi_campo);
						mi_coleccion.AgregaObjeto(mi_pelota);

						Pared *pared = new Pared(white,
							400 + rand() % (700 - 300),
							100 + rand() % (900 - 100),
							20 + rand() % (150 - 20),
							20 + rand() % (150 - 20),
							mi_campo,
							false);
						mi_coleccion.AgregaObjeto(pared);


					}

					if (cont == 2000)
					{

						mi_coleccion.EliminaUltimoObjeto();
						Pared *pared = new Pared(white,
							400 + rand() % (700 - 300),
							100 + rand() % (900 - 100),
							20 + rand() % (150 - 20),
							20 + rand() % (150 - 20),
							mi_campo,
							false);
						mi_coleccion.AgregaObjeto(pared);
						cont = 0;
					}
				

			}
			break;
			}


			motorRender.BorraPantalla();
			miIA.EligeMovimiento(mi_pelota);
			motorFisica.Actualiza(miIU.DetectaPulsacion());

			motorRender.DibujaTodo(mi_campo);

			logicaJuego.ControlaMarcador(&mi_marcador, mi_coleccion, mi_campo);


			golesA = mi_marcador.getGolesA();
			golesB = mi_marcador.getGolesB();

			s_golesA = to_string(golesA);
			s_golesB = to_string(golesB);

			motorRender.Escribe(menu_marcador, window, s_golesA, blanco, 0.35*ancho_campo, 0.1*alto_campo, mi_campo);
			motorRender.Escribe(menu_marcador, window, s_golesB, blanco, 0.55*ancho_campo, 0.1*alto_campo, mi_campo);

			


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