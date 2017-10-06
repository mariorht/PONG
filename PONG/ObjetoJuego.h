#ifndef OBJETO_JUEGO
#define OBJETO_JUEGO

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <SDL.h>
#include "Campo.h"



using namespace std;

class ObjetoJuego
{
protected:
	float posX, posY;
	float velX, velY;
	float aX, aY;
	bool AfectadoPorPulsacion;
	bool SiRebotoSueno;
	bool AfectadoPorChoque;
	bool EsAtravesado;
	bool PuedoMeterGol;
	
	Uint32 color;
	float rozamiento;
	float ancho, alto;
	
	Campo *campo;
	string Forma;

public:
	
	ObjetoJuego(Uint32 color,
		float px, float py, 
		float vx, float vy,
		float ax, float ay,
		float w, float h,
		float roz, Campo *campo);
	//~ObjetoJuego();

	void setPosicionX(float);
	virtual void setPosicionY(float);
	virtual void setVelocidadX(float);
	virtual void setVelocidadY(float);
	void setAceleracionX(float);
	void setAceleracionY(float);
	void setDimensiones(float, float);

	Uint32 getColor();

	bool getAfectadoPorPulsacion();
	bool getPuedoMeterGol();
	bool getSiRebotoSueno();
	bool getAfectadoPorChoque();
	bool getEsAtravesado();

	float getAncho();
	float getAlto();
	float getPosicionX();
	float getPosicionY();
	float getVelocidadX();
	float getVelocidadY();
	float getAceleracionX();
	float getAceleracionY();
	float getRozamiento();

	string getForma();

};



#endif