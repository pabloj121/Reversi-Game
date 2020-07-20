#ifndef _JUGADOR_H_
#define _JUGADOR_H_
#include "tablero.h"

class Jugador{
	private:
		int nturno;
		char nombre[20];
		int puntuacion;
		int pganadas;

	public:
		Jugador();		
		int getTurno();
		int getpGanadas();
		void getNombre();
		void setNombre();
		void setTurno(int x);		
		void escogePosicion(Tablero& t);
		void acumulaPartidas(const Tablero& t);
};


#endif