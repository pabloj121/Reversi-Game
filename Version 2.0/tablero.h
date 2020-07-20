#ifndef _TABLERO_H_
#define _TABLERO_H_
#include "matriz.h"
#include <iostream>
#include <utility>
using namespace std;

class Tablero{
	private:
		Matriz tablero;
		int turno;
		int primer_turno;
		int max_fichas_turno;
		int fichas_restantes_turno;
		void cambiarTurno();

	public:
		Tablero();
		Tablero(int f, int c);
		Tablero(const Tablero& t);
		void iniciarTablero();
		int getFils()const;
		int getCols()const;
		int getPos(int f, int c)const;
		int getTurno()const;
		bool getFinal()const;
		bool posValida(int x, int y)const;
		bool puedoPoner()const;
		int getGanador()const;
		int getScore(int player)const;
		int fichasPorTurno()const;
		int fichasRestantes()const;
		void setFichasTurno(int n);
		void setFicha(int x, int y);
		void rotaEnemigo(int x, int y);
		void vaciarTablero(bool cambia);
		int numPos();
		pair<int,int>* numPosiciones();
		void prettyPrint(bool ayuda, ostream& os = cout)const;
		friend ostream& operator<<(ostream& os, const Tablero& t);
		friend istream& operator>>(istream& is, Tablero& t);
		bool Cargar(const char* fichero);

};

#endif