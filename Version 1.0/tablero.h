#ifndef _TABLERO_H_
#define _TABLERO_H_
#include "matriz.h"

class Tablero{
	private:
		Matriz tablero;
		int turno;
		void cambiarTurno();

	public:
		Tablero();
		Tablero(int f, int c);
		int getFils()const;
		int getCols()const;
		int getPos(int f, int c)const;
		int getTurno()const;
		void iniciarTablero();
		bool getFinal()const;
		int getGanador()const;
		int getScore(int player)const;
		bool posValida(int x, int y)const;
		bool puedoPoner()const;
		void setFicha(int x, int y); //void setFicha(int x, int y);
		void rotaEnemigo(int x, int y);
		void vaciarTablero();
		int numPos();
		void prettyPrint();
};

#endif