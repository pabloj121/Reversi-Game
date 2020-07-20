#include <iostream>
#include <fstream>
#include <stdlib.h>	// srand
#include "tablero.h"
#include "jugador.h"
#include <cstring>	// strlen
using namespace std;

/*void Avanzar(istream& is)
{
  while (isspace(is.peek()) || is.peek()=='#') {
    if (is.peek()=='#')
      is.ignore(1024,'\n'); // Suponemos una línea tiene menos de 1024
    else is.ignore();
  }
}*/

void presentarResultados(const Tablero& t, const Jugador& j1, const Jugador& j2, bool continua){
	if (!continua){
		cout << "Resultados finales:" << endl;
	}
	else{
		t.prettyPrint(false);
		cout << "Partida finalizada.";
		if (t.getGanador() == 0)
		{
			cout << "¡¡Empate!!" << endl;;
		}
		else{
			cout << "Ganador: jugador " << t.getGanador() << endl;
		}
			cout << "Resultados tras esta partida:" << endl;
	}
	cout << "\t"; j1.getNombre(); cout << ": " << j1.getpGanadas(); cout << " que acumulan " << j1.Puntuacion() << " puntos" << endl;
	cout << "\t"; j2.getNombre(); cout << ": " << j2.getpGanadas(); cout << " que acumulan " << j2.Puntuacion() << " puntos" << endl;

	// Solo mostramos las partidas empatadas cuando no queremos jugar más
	if (!continua){
		cout << j1.partidasEmpatadas() << " empatadas";
	}
}

bool Cargar(const char* fichero, Jugador& j1, Jugador& j2, Tablero& t){
	ifstream f(fichero, ios::in);

	if(f){
		/* Dato lo utilizaba cuando verificaba la cabecera "manualmente"
		char dato;*/
		char linea[100];
		const char* cabecera = "#MP-SUPER-REVERSI-1.0";

		Avanzar(f);

		f.getline(linea, 100);

		// Tambien podemos comparar con strcmp

		// Verficamos que estamos leyendo un archivo de configuración del juego 
		for (unsigned int i = 0; i < strlen(cabecera); ++i){			
			if (linea[i] != cabecera[i]){
				cout << "Partida errónea introducida";				
				return false;
			}
		}

		// Leo los dos jugadores y el tablero recibidos como parámetros
		f >> j1;
		Avanzar(f);
		f >> j2;
		Avanzar(f);
		f >> t;
	}
	else
		cerr << "Error al cargar la partida" << endl;

	return !f.fail();
}

void Salvar(char* fichero, Jugador& j1, Jugador& j2, Tablero& t){
	ofstream f(fichero, ios::out);

	if(f){
		f << "#MP-SUPER-REVERSI-1" << endl;
		f << j1 << endl;
		f << j2 << endl;
		f << t;

		f.close();
	}
	else
		cerr << "Error al salvar la partida" << endl;

}

void reversi(Jugador& j1, Jugador& j2, Tablero& t){
	bool sigue= true;
	char fichero[256];
	
	while(sigue){
		//Tablero tab(fils, cols);
		char c;
		while(!t.getFinal()){ // aquí empieza el juego.			
			if(t.getTurno() == 1){
				if(j1.escogePosicion(t)){
					sigue = false;
					cout << "Interrupción de la partida. ¿Quiere guardar la partida?";
					// Indicamos si queremos guardar la partida
					cin >> c;
					if(c=='s' or c=='S'){
						// QUE TAMAÑO RESERVO PARA FICHERO?
						cin.ignore(100,'\n');
						cout << "Introduzca nombre de archivo: ";
						cin.getline(fichero,256);

						Salvar(fichero, j1, j2, t);						
					}
				}
			}
			else if(t.getTurno() == 2){
				if(j2.escogePosicion(t)){
					sigue = false;
				}
			}								
		}
		// Acaba la partida
		if (t.getGanador() == 1){
			j1.acumulaPartidas(t);
		}
		else
			j2.acumulaPartidas(t);
		presentarResultados(t, j1, j2, true);
		
		cout << "¿Jugar de nuevo(S/N)?: ";
		cin >> c;
		if(c=='S' || c == 's'){
			t.vaciarTablero(true);
			t.iniciarTablero();
		}
		else{
			sigue = false;
			presentarResultados(t, j1, j2, false);
		}
		// Acaba el juego (sigue = false)
	}
}

int main(int argc, char* argv[]){
	Jugador player1, player2;
	Tablero tab;
	// int fils, cols;
	char tablero[20];
	//bool sigue= true;
	//char c = ' ';
	//char* fichero = 0;

	srand(time(NULL));

	cout << "Introduzca tablero inicial: ";
	cin.getline(tablero, 20);

	if(tab.Cargar(tablero)){
		char nombre1[50];
		char nombre2[50];

		cout << "Introduzca el nombre del primer jugador: ";
		cin.ignore();
		cin.getline(nombre1,50);
		Jugador p3(nombre1);
		player1 = p3;
		player1.setTurno(1);
		cout << "Introduzca el nombre del segundo jugador: ";
		cin.ignore();
		cin.getline(nombre2,50);
		Jugador p4(nombre2);
		player2 = p4;
		player2.setTurno(2);

		reversi(player1, player2, tab);
	}
	else
		cout << "Tablero incorrecto introducido" << endl;
	
	/*if (argc == 1){
		char nombre1[50];
		char nombre2[50];
		do{
			cout << "Introduzca el numero de filas: ";
			cin >> fils;
			cout << "Introduzca el numero de columnas: ";
			cin >> cols;
		}while(fils <=0 || fils > 10 || cols > 10 || cols <=0 );
		
		Tablero t(fils, cols);
		cout << "Introduzca el nombre del primer jugador: ";
		cin.ignore();
		cin.getline(nombre1,50);
		Jugador p3(nombre1);
		player1 = p3;
		//player1.setNombre();
		player1.setTurno(1);
		cout << "Introduzca el nombre del segundo jugador: ";
		cin.getline(nombre2,50);
		Jugador p4(nombre2);
		player2 = p4;
		//player2.setNombre();
		player2.setTurno(2);

		reversi(player1, player2, t);
	}
	else{
		if(Cargar(argv[1], player1, player2, tab))
			cout << "Partida cargada" << endl;
		else
			cout << "Error al cargar la partida" << endl;
		reversi(player1, player2, tab);
	}*/


	/*while(sigue){		
		while(!tab.getFinal()){ // aquí empieza el juego.
			char s = '';
			
			if(tab.getTurno() == 1){
				if(player1.escogePosicion(tab)){
					sigue = false;
					//cout << "Interrupción de la partida. ¿Quiere guardar la partida?";
					// Inidicamos si queremos guardar la partida
					cin >> s;
					if(c=='s' or c=='S'){
						cout << "Introduzca nombre de archivo: ";
						// FALTA CORREGIR EL PARAMETRO DEL FICHERO EN EL QUE SE SALVA LA PARTIDA
						Salvar(char* fichero, player1, player2, tab);
					}
				}
			}
			else if(tab.getTurno() == 2){
				if(player2.escogePosicion(tab)){
					sigue = false;
				}
			}								
		}

		acumulaPartidas(tab);
		//aquí se acaba la partida
		presentarResultados(tab, player1, player2, true);
		
		tab.prettyPrint();
		cout << "Partida finalizada. Ganador: jugador " << tab.getGanador() << endl;
		cout << "Resultados tras esta partida:" << endl;
		player1.acumulaPartidas(tab);
		player2.acumulaPartidas(tab);
			//cambiar get score
		cout << "\t";  player1.getNombre(); cout << ": "<< player1.getpGanadas() << " ganadas que acumulan "<< player1.Puntuacion() << " puntos"<< endl;
		cout << "\t"; player2.getNombre(); cout << ": "<< player2.getpGanadas() << " ganadas que acumulan "<<  player2.Puntuacion() << " puntos"<< endl;
		
		if(tab.getGanador()== 1){
			player1.setPuntuacion();
			cout << "El ganador es: ";
			 
			player1.getNombre();
			cout << endl;
		}
		else if(tab.getGanador()== 2){
			cout << "El ganador es: ";

			player2.getNombre();
			cout << endl;
		}
		else{
			cout << "¡¡Empate!!" << endl;
			tab.setEmpatadas();
		}
		
		cout << "¿Jugar de nuevo(S/N)?: ";
		cin >> c;
		if(c=='S' || c == 's'){
			tab.vaciarTablero();
			tab.iniciarTablero();
		}
		else{
			cout << "Resultados finales:" << endl;
			jugador1.getNombre();
			cout << ": " << jugador1.getpGanadas() << " ganadas que acumulan ";
			jugador1.acumulaPartidas();
			cout  << " puntos" << endl;
			sigue = false;
			presentarResultados(tab, player1, player2, false);
			// Llamo a acumular justo después de finalizar la partida (línea 137)
			//jugador1.acumulaPartidas();
		}
	}*/
	cout << endl << "Fin de la ejecución." << endl;
}
