/******************************************************/
/* AUTOR: Mario Roos Hoefgeest Toribio                */
/*        Sara Roos Hoefgeest Toribio                 */
/* FECHA: 08/10/2017                                  */
/* CONTENIDO: Implementación de PONG en C++           */
/*                                                    */
/******************************************************/


// Inclusión de librerías
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
#include <SDL_mixer.h>

// Definición constantes
#define MenuInicio 1
#define ModosJuego 2

#define MenuUnJugador 3
#define MenuDosJugadores 4
#define MenuExperto 5

#define JuegoUnJugador 6
#define JuegoDosJugadores 7
#define JuegoExperto 8
#define Jugando 9

#define VictoriaJugador1 10
#define VictoriaJugador2 11



// Comienzo del programa principal
int main(int arcg, char * args[])
{
	// Inicialización de semilla para generar números aleatorios
	srand(GetTickCount());
	

	// Inicilizar SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		cout << "SDL could not initialize! SDL_Error:" << SDL_GetError() << endl;
		return 0;
	}

	if (TTF_Init() < 0)
	{
		cout << "TTF SDL could not initialize!" << endl;
		return 0;
	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		cout << "SDL MIXER could not initialize!" << endl;
		return 0;
	}
	

	// Variables para el manejo del sonido
	Mix_Chunk *sonido_colision;
	sonido_colision = Mix_LoadWAV("colision.wav"); //Cargar sonido para colisiones
	if (sonido_colision == NULL)
	{
		cout << "No se puede abrir el archivo de audio de colision" << Mix_GetError() << endl;
		return 0;
	}

	Mix_Chunk *sonido_gol;
	sonido_gol = Mix_LoadWAV("goal.wav"); //Cargar sonido para goles
	if (sonido_gol == NULL)
	{
		cout << "No se puede abrir el archivo de audio de gol" << Mix_GetError() << endl;
		return 0;
	}

	Mix_Chunk *sonido_victoria;
	sonido_victoria = Mix_LoadWAV("victoria.wav"); //Cargar sonido para victoria
	if (sonido_victoria == NULL)
	{
		cout << "No se puede abrir el archivo de audio de victoria" << Mix_GetError() << endl;
		return 0;
	}


	// Variables para el manejo de la pantalla
	SDL_Window* window = NULL;
	SDL_Surface* screen = NULL;
	
	// Crear ventana
	window = SDL_CreateWindow("PONG",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		cout << "Window could not be created! SDL_Error:" << SDL_GetError() << endl;
		return 0;
	}
	
	// Crear superficie del tamaño de la ventana
	// Aquí se pinta todo lo que se muestra por pantalla
	screen = SDL_GetWindowSurface(window);
		

	// Crear campo de juego
	Campo *mi_campo = new Campo(1920, 1080);
	float ancho_campo = mi_campo->getAnchoCampo();
	float alto_campo = mi_campo->getAltoCampo();

	// Crear colección de objetos de juego
	ColeccionObjetos mi_coleccion = ColeccionObjetos();

	// Definición de colores
	Uint32 white = SDL_MapRGB(screen->format, 242, 254, 255);
	Uint32 blue = SDL_MapRGB(screen->format, 3, 169, 244);

	// Crear pelotas y añadir a la colección
	Pelota *mi_pelota;
	for (int i = 1; i < 2; i++)
	{
		mi_pelota = new Pelota(white, ancho_campo*0.12*i, alto_campo*0.05*i, 6.5, 7, 0, 0, 20/**De momento este es el tamaño del punto*/, 0, mi_campo);
		mi_coleccion.AgregaObjeto(mi_pelota);
	}

	// Crear raquetas y añadir a la colección
	float ancho_raqueta = ancho_campo * 0.01;
	float alto_raqueta = alto_campo * 0.15;
	Raqueta mi_raqueta_izq(white, mi_campo->getPosPorteriaIzq()+ancho_raqueta, alto_campo*0.5, 0, 0, ancho_raqueta, alto_raqueta, .1, mi_campo);
	Raqueta mi_raqueta_dcha(white, mi_campo->getPosPorteriaDcha() - 2*ancho_raqueta, alto_campo*0.5, 0, 0, ancho_raqueta, alto_raqueta, .1, mi_campo);
	mi_coleccion.AgregaObjeto(&mi_raqueta_izq);
	mi_coleccion.AgregaObjeto(&mi_raqueta_dcha);

	// Crear inteligencia artificial que controla el movimiento de la raqueta derecha en el Modo Un jugador
	InteligenciaArtificial miIA(&mi_raqueta_dcha);

	// Crear paredes y añadir a la colección
	Pared p_arriba(white, 0, 0.02*alto_campo, ancho_campo, 0.02*alto_campo, mi_campo, false);
	Pared p_abajo(white, 0, 0.96*alto_campo, ancho_campo, 0.02*alto_campo, mi_campo, false);
	mi_coleccion.AgregaObjeto(&p_abajo);
	mi_coleccion.AgregaObjeto(&p_arriba);

	// Crear línea de medio campo y añadir a la colección
	int largo_linea = (alto_campo - 10) / 20;
	for (int i = 0; 2 * i*largo_linea <= alto_campo - 0.04*alto_campo; i++)
	{
		Pared *decoracion = new Pared(white, 0.5*ancho_campo - 0.02*alto_campo, 0.04*alto_campo + 2 * i*largo_linea, 0.02*ancho_campo, largo_linea, mi_campo, true);
		mi_coleccion.AgregaObjeto(decoracion);
	}

	// Crear lógica del juego 
	LogicaJuego logicaJuego = LogicaJuego();

	// Crear el motor Render que se encarga de dibujar
	Render motorRender = Render(&mi_coleccion, screen);

	// Crear el motor Física que se encarga del movimiento de los objetos del juego
	MotorFisica motorFisica = MotorFisica(&mi_coleccion);

	// Crear el marcador
	Marcador mi_marcador = Marcador(0, 0);

	// Inicializar parámetros escritura
	string fuente = "Equalize.ttf";
	string fuente_menu = "AldoTheApache.ttf";
	float tam_fuente_titulo = alto_campo*0.07;
	float tam_fuente_titulo2 = alto_campo*0.02;
	float tam_fuente_menu = alto_campo*0.03;
	float tam_fuente_marcador = alto_campo*0.035;
	SDL_Color blanco = { 255, 255, 255, 0 };
	SDL_Color azul = { 92, 156, 188, 0 };

	// Crear objetos Menu donde se cargan las fuentes
	Menu menu_titulo(fuente, tam_fuente_titulo, window);
	Menu menu_titulo2(fuente, tam_fuente_titulo2, window);
	Menu menu_modos(fuente_menu, tam_fuente_menu, window);
	Menu menu_marcador(fuente, tam_fuente_marcador, window);

	// Crear Interfaz de usuario para detectar pulsaciones de teclado
	InterfazUsuario miIU;

	// Flag bucle
	bool cerrar = FALSE;

	// Flag menu
	bool recien_entrado = true;

	// Event handler 
	SDL_Event e;

	// Variables para controlar el estado del programa
	int estado = MenuInicio;
	int modo = MenuUnJugador;

	// Contador 
	int cont = 0;


	while (!cerrar)
	{

		while (SDL_PollEvent(&e)) // Salir del bucle si se cierra la ventana o se pulsa ESCAPE
		{
			if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
				cerrar = true;
		}


		// Máquina de estados del programa
		switch (estado)
		{

		// Pantalla de inicio
		case MenuInicio:
		{
			if (recien_entrado)
			{
				recien_entrado = false;
				// Escribir títulos
				motorRender.Escribe(menu_titulo, window, "PONG", blanco, 0.3*ancho_campo, 0.35*alto_campo, mi_campo);
				motorRender.Escribe(menu_titulo2, window, "Pulsa ENTER para continuar", azul, 0.20*ancho_campo, 0.6*alto_campo, mi_campo);

			}

			// Cambio de estado
			if (miIU.DetectaPulsacion() == ENTER)
			{
				estado = ModosJuego;
				recien_entrado = true;
				SDL_Delay(150); // Esperar para no detectar dos pulsaciones
			}

		}break;

		// Pantalla de menu de modos de juego
		case ModosJuego:
		{
			// Controlar la selección de modo
			switch (modo)
			{
			case MenuUnJugador:
			{
				if (recien_entrado)
				{
					recien_entrado = false;
					// Escribir menú
					motorRender.BorraPantalla();
					motorRender.Escribe(menu_titulo, window, "PONG", blanco, 0.3*ancho_campo, 0.35*alto_campo, mi_campo);
					motorRender.Escribe(menu_modos, window, "UN JUGADOR", azul, 0.25*ancho_campo, 0.65*alto_campo, mi_campo);
					motorRender.Escribe(menu_modos, window, "DOS JUGADORES", blanco, 0.25*ancho_campo, 0.75*alto_campo, mi_campo);
					motorRender.Escribe(menu_modos, window, "MODO EXPERTO (DOS JUGADORES)", blanco, 0.25*ancho_campo, 0.85*alto_campo, mi_campo);

				}

				// Cambio de estado
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
					modo = MenuExperto;
					SDL_Delay(150);
				}
				if (miIU.DetectaPulsacion() == ABAJO)
				{
					recien_entrado = true;
					modo = MenuDosJugadores;
					SDL_Delay(150);
				}
			}break;


			case MenuDosJugadores:
			{
				if (recien_entrado)
				{
					recien_entrado = false;
					// Escribir menú
					motorRender.BorraPantalla();
					motorRender.Escribe(menu_titulo, window, "PONG", blanco, 0.3*ancho_campo, 0.35*alto_campo, mi_campo);
					motorRender.Escribe(menu_modos, window, "UN JUGADOR", blanco, 0.25*ancho_campo, 0.65*alto_campo, mi_campo);
					motorRender.Escribe(menu_modos, window, "DOS JUGADORES", azul, 0.25*ancho_campo, 0.75*alto_campo, mi_campo);
					motorRender.Escribe(menu_modos, window, "MODO EXPERTO (DOS JUGADORES)", blanco, 0.25*ancho_campo, 0.85*alto_campo, mi_campo);

				}

				// Cambio de estado
				if (miIU.DetectaPulsacion() == ENTER)
				{
					modo = JuegoDosJugadores;
					estado = Jugando;
					SDL_Delay(150);
					recien_entrado = true;
				}
				if (miIU.DetectaPulsacion() == ARRIBA)
				{
					modo = MenuUnJugador;
					SDL_Delay(150);
					recien_entrado = true;
				}
				if (miIU.DetectaPulsacion() == ABAJO)
				{
					modo = MenuExperto;
					SDL_Delay(150);
					recien_entrado = true;
				}

			}break;

			case MenuExperto:
			{
				if (recien_entrado)
				{
					recien_entrado = false;
					// Escribir menú
					motorRender.BorraPantalla();
					motorRender.Escribe(menu_titulo, window, "PONG", blanco, 0.3*ancho_campo, 0.35*alto_campo, mi_campo);
					motorRender.Escribe(menu_modos, window, "UN JUGADOR", blanco, 0.25*ancho_campo, 0.65*alto_campo, mi_campo);
					motorRender.Escribe(menu_modos, window, "DOS JUGADORES", blanco, 0.25*ancho_campo, 0.75*alto_campo, mi_campo);
					motorRender.Escribe(menu_modos, window, "MODO EXPERTO (DOS JUGADORES)", azul, 0.25*ancho_campo, 0.85*alto_campo, mi_campo);

				}

				// Cambio de estado
				if (miIU.DetectaPulsacion() == ENTER)
				{
					modo = JuegoExperto;
					estado = Jugando;
					SDL_Delay(150);
					recien_entrado = true;
				}

				if (miIU.DetectaPulsacion() == ARRIBA)
				{
					modo = MenuDosJugadores;
					SDL_Delay(150);
					recien_entrado = true;
				}
				if (miIU.DetectaPulsacion() == ABAJO)
				{
					modo = MenuUnJugador;
					SDL_Delay(150);
					recien_entrado = true;
				}

			}break;
			} // Fin control menús

		}break;

		// Estado de juego según el modo seleccionado
		case Jugando:
		{
			switch (modo)
			{

			// Un jugador contra la inteligencia artificial
			case JuegoUnJugador:
			{
				if (recien_entrado)
				{
					mi_raqueta_dcha.setIAon(); // Activamos IA en la raqueta derecha
					recien_entrado = false;
				}

				// Control de la raqueta en función de la pelota
				miIA.EligeMovimiento(mi_pelota);

			} break;

			// Dos jugadores
			case JuegoDosJugadores:
			{
				// Parámetros por defecto
			}
			break;

			// Dos jugadores modo experto
			case JuegoExperto:
			{
				if (recien_entrado)
					recien_entrado = false;

				cont++; // Se aumenta el contador

				// Si el contador llega a 1000, se añaden una pelota y una pared
				if (cont == 1000)
				{
					mi_pelota = new Pelota(white,
						0.4*ancho_campo + rand() % ((int)(0.6*ancho_campo - 0.4*ancho_campo)),
						0.1*alto_campo + rand() % ((int)(0.9*alto_campo - 0.1*alto_campo)),
						6.5,
						7,
						0,
						0,
						12/**De momento este es el tamaño del punto*/,
						0,
						mi_campo);
					mi_coleccion.AgregaObjeto(mi_pelota);

						Pared *pared = new Pared(blue,
						0.4*ancho_campo + rand() % ((int)(0.6*ancho_campo - 0.4*ancho_campo)),
						0.3*alto_campo + rand() % ((int)(0.7*alto_campo - 0.3*alto_campo)),
						0.05*ancho_campo + rand() % ((int)(0.2*ancho_campo - 0.05*ancho_campo)),
						0.05*alto_campo + rand() % ((int)(0.2*alto_campo - 0.05*alto_campo)),
						mi_campo,
						false);
					mi_coleccion.AgregaObjeto(pared);


				}

				// Si el contador llega a 2000, se destruye la última pared y se crea otra
				if (cont == 2000)
				{

					mi_coleccion.EliminaUltimoObjeto();
					Pared *pared = new Pared(blue,
						0.4*ancho_campo + rand() % ((int)(0.6*ancho_campo - 0.4*ancho_campo)),
						0.3*alto_campo + rand() % ((int)(0.9*alto_campo - 0.3*alto_campo)),
						0.05*ancho_campo + rand() % ((int)(0.2*ancho_campo - 0.05*ancho_campo)),
						0.05*alto_campo + rand() % ((int)(0.2*alto_campo - 0.05*alto_campo)),
						mi_campo,
						false);
					mi_coleccion.AgregaObjeto(pared);

					cont = 0; // Reseteo contador
				}


			}
			break;
			} 

			// Borrar pantalla
			motorRender.BorraPantalla();

			// El motor de física actualiza las posiciones y velocidades de los objetos
			// Se reproduce un sonido en caso de colision
			if (motorFisica.Actualiza(miIU.DetectaPulsacion()))
				Mix_PlayChannel(-1, sonido_colision, 0);

			// Se dibujan todos los objetos
			motorRender.DibujaTodo(mi_campo);

			// Lógica del juego actualiza el marcador 
			// Se reproduce un sonido en caso de gol
			if (logicaJuego.ControlaMarcador(&mi_marcador, mi_coleccion, mi_campo))
				Mix_PlayChannel(-1, sonido_gol, 0);

			// Obtener los goles de cada equipo
			int golesA = mi_marcador.getGolesA();
			int golesB = mi_marcador.getGolesB();

			string s_golesA = to_string(golesA);
			string s_golesB = to_string(golesB);

			// Pintar el marcador
			motorRender.Escribe(menu_marcador, window, s_golesA, blanco, 0.35*ancho_campo, 0.1*alto_campo, mi_campo);
			motorRender.Escribe(menu_marcador, window, s_golesB, blanco, 0.59*ancho_campo, 0.1*alto_campo, mi_campo);

			// Si un equipo llega a 10 goles gana y cambia de estado. 
			if (golesA >= 10)
			{
				estado = VictoriaJugador1;
				recien_entrado = true;
			}
			if (golesB >= 10)
			{
				estado = VictoriaJugador2;
				recien_entrado = true;
			}

		}break;

		// Estado de victoria del juagador 1
		case VictoriaJugador1:
		{
			if (recien_entrado)
			{
				recien_entrado = false;
				// Se reproduce un sonido de victoria
				Mix_PlayChannel(-1, sonido_victoria, 0);
				motorRender.BorraPantalla();
				motorRender.Escribe(menu_marcador, window, "VICTORIA DEL JUGADOR 1", blanco, 0.1*ancho_campo, 0.4*alto_campo, mi_campo);
			}

			// Si se pulsa ENTER se reinicia el juego
			if (miIU.DetectaPulsacion() == ENTER) 
			{
				// Destruye ventana
				SDL_DestroyWindow(window);
				// Cierra SDL 
				SDL_Quit();
				TTF_Quit();
				Mix_Quit();
				
				main(NULL, NULL);
			}
							
		}break;

		// Estado de victoria del juagador 2
		case VictoriaJugador2:
		{
			if (recien_entrado)
			{
				recien_entrado = false;
				// Se reproduce un sonido de victoria
				Mix_PlayChannel(-1, sonido_victoria, 0);
				motorRender.BorraPantalla();
				motorRender.Escribe(menu_marcador, window, "VICTORIA DEL JUGADOR 2", blanco, 0.1*ancho_campo, 0.4*alto_campo, mi_campo);
			}

				
			// Si se pulsa ENTER se reinicia el juego	
			if (miIU.DetectaPulsacion() == ENTER)
			{
				// Destruye ventana
				SDL_DestroyWindow(window);
				// Cierra SDL 
				SDL_Quit();
				TTF_Quit();
				Mix_Quit();

				main(NULL, NULL);
			}
				
		}break;
		
		} // Fin máquina de estados

		// Refresca pantalla
		motorRender.RefrescaPantalla(window);
		// Espera 10 ms para volver a empezar el bucle
		Sleep(10);


	} // Fin bucle infinito


	// Destruye ventana
	SDL_DestroyWindow(window);

	// Cierra SDL 
	SDL_Quit();
	TTF_Quit();
	Mix_Quit();

	return 0;


} // Fin programa principal