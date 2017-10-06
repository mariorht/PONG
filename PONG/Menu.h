#pragma once
#ifndef MENU_H
#define MENU_H

#include <string>
#include <iostream>

#include <SDL.h>
#include <SDL_ttf.h>

#define SCREEN_WIDTH  1280
#define SCREEN_HEIGHT 700


using namespace std;



class Menu
{
protected:
	TTF_Font *fuente;
	TTF_Font *CargarFuente(string tipo_fuente, float tam_fuente);
	

public:
	Menu(string tipo_fuente, float tam_fuente, SDL_Window *window);
	~Menu();
	TTF_Font *GetFuente();

};

#endif