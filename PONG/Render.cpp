#include "Render.h"



Render::Render(ColeccionObjetos objetos, SDL_Surface *d)
{
	coleccion = objetos;
	num_objetos = coleccion.getTamColeccion();
	destination = d;

}

void Render::DibujaTodo()
{
	vector<ObjetoJuego*> mis_objetos = coleccion.getColeccionObjetos();
	num_objetos = coleccion.getTamColeccion();
	for (int i = 0; i < num_objetos; i++)
	{
		int posicionX = mis_objetos[i]->getPosicionX() / 1000.0 *SCREEN_WIDTH;
		int posicionY = mis_objetos[i]->getPosicionY() / 1000.0 * SCREEN_HEIGHT;

		float w = mis_objetos[i]->getAncho() / 1000.0 *SCREEN_WIDTH;
		float h = mis_objetos[i]->getAlto() / 1000.0 *SCREEN_HEIGHT;

		//Quizá meterlo en DibujaRectangulo
		if (mis_objetos[i]->Forma == "rectangulo")
		{
			image = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
			SDL_FillRect(image, NULL, mis_objetos[i]->getColor());
		}
		else if (mis_objetos[i]->Forma == "circulo")
		{
			image = SDL_LoadBMP("dot.bmp");
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
	SDL_FillRect(destination, NULL, SDL_MapRGB(destination->format, 0xFF, 0xFF, 0xFF));
}


void Render::Escribe(SDL_Window *window, string texto_escribir, SDL_Color color,
	string fuente_texto, float tam_fuente, float pos_x, float pos_y)
{


	TTF_Font *fuente = TTF_OpenFont(fuente_texto.c_str(), tam_fuente / 1000.0 * SCREEN_WIDTH);

	if (fuente != NULL)
	{
		SDL_Renderer *gRenderer = SDL_CreateRenderer(window, -1, 0);
		SDL_Surface *texto = TTF_RenderText_Solid(fuente, texto_escribir.c_str(), color);

		SDL_Rect CuadroTexto;
		CuadroTexto.x = pos_x / 1000.0 * SCREEN_WIDTH;
		CuadroTexto.y = pos_y / 1000.0 * SCREEN_HEIGHT;

		SDL_BlitSurface(texto, NULL, destination, &CuadroTexto);

		SDL_RenderPresent(gRenderer);
		SDL_UpdateWindowSurface(window);

		SDL_FreeSurface(destination);
		SDL_FreeSurface(texto);
		TTF_CloseFont(fuente);
		//SDL_DestroyRenderer(gRenderer);


	}

	else
		cout << "No se ha encontrado la fuente solicitada: " << fuente_texto << endl;


}


