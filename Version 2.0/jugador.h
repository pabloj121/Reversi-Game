#ifndef _JUGADOR_H_
#define _JUGADOR_H_
#include "tablero.h"

class Jugador{
	private:
		int nturno;
		char *nombre;
		int puntuacion;
		int pganadas;
		int empatadas;
		int comodines;
	public:
		Jugador();
		Jugador(char nom[]);
		Jugador(const Jugador& j);
		~Jugador();
		Jugador& operator=(const Jugador& j);
		friend istream& operator>>(istream& is, Jugador& j);
		friend ostream& operator<<(ostream& os, const Jugador& j);
		int Longitud(char *n);
		void setTurno(int x);
		void setPuntuacion(const Tablero& t);
		int getTurno();
		void getNombre()const;
		int Puntuacion()const;
		int getpGanadas()const;	
		int Comodines()const;
		void restaComodin();
		int partidasEmpatadas()const;	
		bool escogePosicion(Tablero& t);
		void escogePosicionAutomatico(Tablero& t);
		void acumulaPartidas(const Tablero& t);
};

inline Jugador::~Jugador(){
	delete[] nombre;
	nombre = 0;
}

// Operador de entrada
istream& operator>>(istream& is, Jugador& j);
/*{
	while(isspace(is.peek())){
		is.ignore();
	}
	// nturno, puntuacion, ganadas, empatadas, comodines

    if (is.peek()=='!'){
    	char nom[255];
    	int t,p,g,e, c; 
    	
    	is.ignore();	// Ignoro la exclamación
    	is.getline(nom, 255);	// Leo el nombre, y el resto de miembros de la clase Jugador
		is >> t >> p >> g >> e >> c;
		
		if (is){
			Jugador aux(nom);
			aux.nturno = t;
			aux.puntuacion = p;
			aux.pganadas = g;
			aux.empatadas = e;
			aux.comodines = c;

			j=aux;
		}
    }
    else
    	is.setstate(ios::failbit);

    return is;
}*/

// Operador de salida
ostream& operator<<(ostream& os, const Jugador& j);
/*{
	os << " !";
	j.getNombre();
	os << endl;

	os << j.nturno << " " << j.puntuacion << " " << j.pganadas << " " << j.comodines;

	return os;
}*/

#endif