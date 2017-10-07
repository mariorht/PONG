#ifndef OBJETO_JUEGO
#define OBJETO_JUEGO

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <SDL.h>
#include "Campo.h"

using namespace std;

// Clase con las principales propiedades de los objetos del juego
class ObjetoJuego
{
protected:
	float posX, posY;			// Posici�n
	float velX, velY;			// Velocidad		
	float aX, aY;				// Aceleraci�n
	bool AfectadoPorPulsacion;	// Indica si es afectado por pulsaci�n
	bool SiRebotoSueno;			// Si rebota permite que se reproduzca un sonido
	bool AfectadoPorChoque;		// Indica si es afectado por choques
	bool EsAtravesado;			// Indica si es atravesado
	bool PuedoMeterGol;			// Indica si puede meter gol
	
	Uint32 color;				// Color
	float rozamiento;			// Rozamiento
	float ancho, alto;			// Tama�o
	string Forma;				// Forma
	
	Campo *campo;				// Puntero al campo
	

public:
	
	/** Constructor:
	param Uint32 color : color del objeto
	param float px : Posici�n en X del objeto
	param float py : Posici�n en Y del objeto
	param float vx : Velocidad en X del objeto
	param float vy : Velocidad en Y del objeto
	param float ax : Aceleraci�n en X del objeto
	param float ay : Aceleraci�n en Y del objeto
	param float w : Ancho del objeto
	param float h : Alto del objeto
	param float roz : Coeficiente de rozamiento
	param Campo *campo : Puntero al objeto campo
	*/
	ObjetoJuego(Uint32 color,
		float px, float py, 
		float vx, float vy,
		float ax, float ay,
		float w, float h,
		float roz, Campo *campo);

	/** Asigna la posici�n X del objeto*/
	void setPosicionX(float);

	/** Asigna la posici�n Y del objeto*/
	virtual void setPosicionY(float);

	/** Asigna la velocidad X del objeto*/
	virtual void setVelocidadX(float);

	/** Asigna la velocidad Y del objeto*/
	virtual void setVelocidadY(float);

	/** Asigna la aceleraci�n X del objeto*/
	void setAceleracionX(float);

	/** Asigna la aceleraci�n Y del objeto*/
	void setAceleracionY(float);

	/** Asigna las dimensiones ancho y alto del objeto*/
	void setDimensiones(float w, float h);

	/** Devuelve el color del objeto*/
	Uint32 getColor();

	/** Devuelve si es afectado por pulsaci�n*/
	bool getAfectadoPorPulsacion();

	/** Devuelve si puede meter gol*/
	bool getPuedoMeterGol();

	/** Devuelve si permite el sonido al rebotar*/
	bool getSiRebotoSueno();

	/** Devuelve si es afectado por choque*/
	bool getAfectadoPorChoque();

	/** Devuelve si es atraveasado*/
	bool getEsAtravesado();

	/** Devuelve el ancho del objeto */
	float getAncho();

	/** Devuelve el alto del objeto */
	float getAlto();

	/** Devuelve la posici�n X del objeto */
	float getPosicionX();

	/** Devuelve la posici�n Y del objeto */
	float getPosicionY();

	/** Devuelve la velocidad X del objeto */
	float getVelocidadX();

	/** Devuelve la velocidad Y del objeto */
	float getVelocidadY();

	/** Devuelve la aceleraci�n X del objeto */
	float getAceleracionX();

	/** Devuelve la aceleraci�n Y del objeto */
	float getAceleracionY();

	/** Devuelve elcoeficiente de rozamiento */
	float getRozamiento();

	/** Devuelve la forma del objeto */
	string getForma();

};



#endif