#include "Render.h"



Render::Render(ColeccionObjetos *objetos, SDL_Surface *d)
{
	coleccion = objetos;
	num_objetos = coleccion->getTamColeccion();
	destination = d;

}

void Render::DibujaTodo(Campo *campo)
{
	float ancho_campo = campo->getAnchoCampo();
	float alto_campo = campo->getAltoCampo();

	vector<ObjetoJuego*> mis_objetos = coleccion->getColeccionObjetos();
	num_objetos = coleccion->getTamColeccion();
	for (int i = 0; i < num_objetos; i++)
	{
		int posicionX = mis_objetos[i]->getPosicionX() / ancho_campo *SCREEN_WIDTH;
		int posicionY = mis_objetos[i]->getPosicionY() / alto_campo * SCREEN_HEIGHT;

		float w = mis_objetos[i]->getAncho() / ancho_campo *SCREEN_WIDTH;
		float h = mis_objetos[i]->getAlto() / alto_campo *SCREEN_HEIGHT;

		//Quizá meterlo en DibujaRectangulo
		if (mis_objetos[i]->Forma == "rectangulo")
		{
			image = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
			SDL_FillRect(image, NULL, mis_objetos[i]->getColor());
		}
		else if (mis_objetos[i]->Forma == "circulo")
		{
			image = SDL_LoadBMP("dot_black.bmp");
		}

		rect = image->clip_rect;

		rect.x = posicionX;
		rect.y = posicionY;

		DibujaRectangulo();
		SDL_FreeSurface(image);


	}

}

void Render::DibujaRectangulo()
{

	SDL_BlitSurface(image, NULL, destination, &rect);
}



void Render::BorraPantalla()
{
	SDL_FillRect(destination, NULL, SDL_MapRGB(destination->format, 5, 5, 5));

}


void Render::Escribe(Menu menu, SDL_Window *window, string texto_escribir, SDL_Color color, float pos_x, float pos_y, Campo *campo)
{
	SDL_Surface *texto = TTF_RenderText_Solid(menu.GetFuente(), texto_escribir.c_str(), color);

	SDL_Rect CuadroTexto;
	CuadroTexto.x = pos_x / campo->getAnchoCampo() * SCREEN_WIDTH;
	CuadroTexto.y = pos_y / campo->getAltoCampo() * SCREEN_HEIGHT;

	SDL_BlitSurface(texto, NULL, destination, &CuadroTexto);

	SDL_FreeSurface(destination);
	SDL_FreeSurface(texto);

}



