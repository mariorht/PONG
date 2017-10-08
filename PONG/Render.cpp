#include "Render.h"



Render::Render(ColeccionObjetos *objetos, SDL_Surface *d)
{
	coleccion = objetos;
	num_objetos = coleccion->getTamColeccion();
	destination = d;

}

Render::~Render()
{
	SDL_FreeSurface(destination);
}

void Render::DibujaTodo(Campo *campo)
{
	//Variable auxiliar
	SDL_Surface *image=NULL;

	// Obtener dimensiones del campo
	float ancho_campo = campo->getAnchoCampo();
	float alto_campo = campo->getAltoCampo();

	// Obtener la colección de objetos
	vector<ObjetoJuego*> mis_objetos = coleccion->getColeccionObjetos();
	num_objetos = coleccion->getTamColeccion();

	for (int i = 0; i < num_objetos; i++)
	{
		// Obtener la posición de los objetos de la colección
		float posicionX = mis_objetos[i]->getPosicionX() / ancho_campo *SCREEN_WIDTH;
		float posicionY = mis_objetos[i]->getPosicionY() / alto_campo * SCREEN_HEIGHT;

		// Obtener el tamaño de los objetos de la colección
		float w = mis_objetos[i]->getAncho() / ancho_campo *SCREEN_WIDTH;
		float h = mis_objetos[i]->getAlto() / alto_campo *SCREEN_HEIGHT;

		// Si tiene forma de rectángulo, dibujar un rectángulo
		if (mis_objetos[i]->getForma() == "rectangulo")
		{
			image = SDL_CreateRGBSurface(0,(int)w, (int)h, 32, 0, 0, 0, 0);
			SDL_FillRect(image, NULL, mis_objetos[i]->getColor());
		}

		// Si tiene forma de círculo, cargar la imagen de un círculo 
		else if (mis_objetos[i]->getForma() == "circulo")
		{
			image = SDL_LoadBMP("dot_black.bmp");
			SDL_SetColorKey(image, SDL_TRUE, (0,0,0));
		}

		// Se crea el rectángulo
		rect = image->clip_rect;
		rect.x = (int)posicionX;
		rect.y = (int)posicionY;

		// Se copia el rectángulo en la imagen que se volcará a la pantalla
		DibujaRectangulo(image);
		SDL_FreeSurface(image);


	}

}

void Render::DibujaRectangulo(SDL_Surface *image)
{

	SDL_BlitSurface(image, NULL, destination, &rect);
}



void Render::BorraPantalla()
{
	SDL_FillRect(destination, NULL, SDL_MapRGB(destination->format, 5, 5, 5));

}


void Render::Escribe(Menu menu, SDL_Window *window, string texto_escribir, SDL_Color color, float pos_x, float pos_y, Campo *campo)
{
	// Se obtiene la superficie con el texto escrito
	SDL_Surface *texto = TTF_RenderText_Solid(menu.GetFuente(), texto_escribir.c_str(), color);

	// Se crea el rectángulo con la posición del texto
	SDL_Rect CuadroTexto;
	CuadroTexto.x = (int) pos_x / campo->getAnchoCampo() * SCREEN_WIDTH;
	CuadroTexto.y = (int) pos_y / campo->getAltoCampo() * SCREEN_HEIGHT;

	// Se copia el rectángulo en la imagen que se volcará a la pantalla 
	SDL_BlitSurface(texto, NULL, destination, &CuadroTexto);

	// Se liberan las superficies donde se escribe
	SDL_FreeSurface(destination);
	SDL_FreeSurface(texto);

}

void Render::RefrescaPantalla(SDL_Window * window)
{
	SDL_UpdateWindowSurface(window);
}



