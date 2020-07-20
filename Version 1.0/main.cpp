#include <iostream>
//#include <stdlib.h>	
#include "tablero.h"
#include "jugador.h"
using namespace std;

//#define CLEAR

int main(){
	//DECLARACIÓN DE VARIABLES;
	Jugador player1, player2;
	int fils, cols;
	bool sigue= true;

	char c = ' ';
		do{
			cout << "Introduzca el numero de filas: ";
			cin >> fils;
			cout << "Introduzca el numero de columnas: ";
			cin >> cols;
		}while(fils <=0 || fils > 10 || cols > 10 || cols <=0 );
		cout << "Introduzca el nombre del primer jugador: ";
		cin.ignore();

		player1.setNombre();
		player1.setTurno(1);
		cout << "Introduzca el nombre del segundo jugador: ";
		player2.setNombre();
		player2.setTurno(2);

	while(sigue){
		
		Tablero tab(fils, cols);
		//cout << tab.getTurno() << endl;
		while(!tab.getFinal()){ // aquí empieza el juego.
			#ifdef CLEAR
				system("clear");
			#endif
			if(tab.getTurno() == 1){
				player1.escogePosicion(tab);
			}
			else if(tab.getTurno() == 2){
				player2.escogePosicion(tab);
			}						
		
		}//aquí se acaba la pardia.
		tab.prettyPrint();
		cout << "Partida finalizada. Ganador: jugador " << tab.getGanador() << endl;
		cout << "Resultados tras esta partida:" << endl;
		player1.acumulaPartidas(tab);
		player2.acumulaPartidas(tab);
		
		cout << "\t";  player1.getNombre(); cout << ": "<< player1.getpGanadas() << " ganadas que acumulan "<< tab.getScore(1) << " puntos"<< endl;
		cout << "\t"; player2.getNombre(); cout << ": "<< player2.getpGanadas() << " ganadas que acumulan "<<  tab.getScore(2) << " puntos"<< endl;
		
		
		if(tab.getGanador()== 1){
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
		}
		
		cout << "¿Quiere seguir jugando? (S/N) ";
		cin >> c;
		if(c=='S' || c == 's'){
			tab.vaciarTablero();
			tab.iniciarTablero();
		}
		else{
			sigue = false;
		}
	}
	cout << endl <<"Fin de la ejecución." << endl;
}
	
	



