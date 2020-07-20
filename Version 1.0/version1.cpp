#include <iostream>
#include <cassert>
using namespace std;

class Matriz
{
	private:
		int filas;
		int columnas;
		int matriz[10][10];
	public:
		Matriz(){
			filas = 0;
			columnas = 0;
		}

		Matriz(int fil, int col){
			filas = fil;
			columnas = col;
		}

		int Filas(){
			return filas;
		}

		int Columnas(){
			return columnas;
		}

		int Elemento(int fil, int col){
			// si lo que hay dentro del assert es false, el programa termina
			assert(fil >= 0 && fil < filas && col >= 0 && col < columnas);
			return matriz[fil][col];
		}

		void Modifica(int fil, int col, int dato){
			assert(fil >= 0 && fil < filas && col >= 0 && col < columnas && (dato == 0 | dato == 1 | dato ==2));			
			matriz[fil][col] = dato;
		}
	
};
// Contenido de las casillas:
// 0: posicion vacia; 1: ficha del primer jugador; 2: ficha del 2º jugador

class Tablero
{
private:
	Matriz matriz;
	int turno_actual;
	int ganador;
	bool empatada;
	bool partida_finalizada;
public:
	Tablero();
	int Filas(){
		return matriz.Filas();
	}
	int Columnas(){
		return matriz.Columnas();
	}
	int Posicion(int fil, int col){
		if (fil >= 0 && fil < filas && col >= 0 && col < columnas)
		{
			return matriz.Elemento(fil, col);
		}
		else
			cout << "Posicion errónea introducida" << endl;
	}
	int Turno(){
		return turno_actual;
	}
	bool Finalizada(){
		return partida_finalizada;
	}
	int Ganador(){
		if (empatada)
		{
			return 0;
		}
		else
			return ganador;
	}
	// ????????????????????????????????????????????????????????????????????
	int Puntuacion(){
		if (partida_finalizada)
		{
			return puntuacion;
		}
		else
			cout << "La partida aún no ha finalizado" << endl;
	}		
	bool Podria_insertar(){
		bool insercion = false;
	}
	void Insertar(int fil, int col){
		if (this.Podria_insertar(fil, col))
		{
			matriz.matriz[fil][col] = ficha;
		}
		else
			cout << "Posicion errónea introducida" << endl;
	}
	void Vaciar(){
		for (int i = 0; i < matriz.Filas(); ++i)
		{
			for (int j = 0; j < matriz.Columnas(); ++j)
			{
				matriz.matriz[i][j] = 0;
			}
		}
	}
	/* si la partida ha finalizado, pone todas las fichas del color del ganador
	void cambiaFichas(){
		for (int i = 0; i < matriz.Filas(); ++i)
		{
			for (int j = 0; j < matriz.Columnas(); ++j)
			{
				if (ganador == 1)
				{
					if (matriz.matriz[i][j] == 2)
					{
						matriz.matriz[i][j] == 1;
					}
				}
				else if (ganador == 2)
				{
					if (matriz.matriz[i][j] == 1)
					{
						matriz.matriz[i][j] == 2;
					}
				}
			}
		}
	}*/

	void prettyPint(){
		// Imprimir primera fila de letras
		int i = 0;
		char a = 'a';

		while(i < matriz.Filas()){
			cout << a++ << " ";
			i++;
		}

		cout << endl;
		for (int i = 0; i < matriz.Filas(); ++i)
		{
			cout << i << "|";
			for (int j = 0; j < matriz.Columnas(); ++j)
			{
				if (matriz.Elemento(i,j)==0)
				{
					cout << " ";
				}
				else if(matriz.Elemento(i,j)==1)
					cout << "x ";
				else if(matriz.Elemento(i,j)==2)
					cout << "o ";
				cout << "|" ;
			}
		}

		if (partida_finalizada)
		{
			cout << "Partida finalizada. "
			if (empatada)
			{
				cout << "Ha habido empate"
			}
			else			
				cout << "Ganador: jugador " << ganador << endl;			
			cout << "Resultados tras esta partida: " << endl;
			// Necesitaria conocer la puntuacion de cada jugador así como las partidas 
			// ganadas, perdidas que llevan........ ??????????????????????????
		}

	}
	void dialogoEscoger(){
		prettyPint();
		escogePosicion();
	}
	
	
};

class Jugador
{
	private:
		char nombre[50];
		Tablero tablero;
		int puntuacion;
		int turno;
		int ganadas, perdidas, empatadas;
	public:
		Jugador(){
			nombre = {0};
			puntuacion = ganadas = perdidas = empatadas = 0;
		}
		Jugador(string n){
			nombre = n;
		}
		int Posiciones(){
			for (int i = 0; i < tablero.Filas(); ++i)
			{
				for (int i = 0; i < tablero.Columnas(); ++i)
				{
					
				}
			}
		}
		// contabilizar puntos ganados tras finalizar una partida
		void Puntuar(const Tablero& tab){
			puntuacion = puntuacion + tab.Puntuacion();
		}			
};

int main(){

}