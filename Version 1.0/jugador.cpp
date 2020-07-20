#include <iostream>
#include "jugador.h"
using namespace std;
		Jugador::Jugador(){ //AQUI DARLE EL NOMBRE Y EL TURNO
			pganadas= puntuacion=0;
			for(int i= 0; i< 20; i++){
				nombre[i] = '\0';
			}
		}
		

		int Jugador::getpGanadas(){
			return pganadas;
		}
		void Jugador::setTurno(int x){
			nturno = x;
		}

		void Jugador::getNombre(){
			for(int i=0; i<20; i++){
				cout << nombre[i];
			}
		}


		void Jugador::setNombre(){ //USAR GETLINE
			cin.getline(nombre,20);
		}

		void Jugador::acumulaPartidas(const Tablero& t){
			if(t.getGanador() == nturno){
				pganadas++;
			}			
		}
		
	
		
		void Jugador::escogePosicion(Tablero& t){
			int a, b;
			a = b =0;
			char letra = ' ';
			
			getNombre();
			
			cout<< " tiene las siguientes posiciones para colocar ficha: ";
			
			for(int i=0; i<t.getFils(); i++){
				for(int j=0; j<t.getCols();j++){
					if(t.posValida(i,j)){
						cout << "(" << i << "," << (char)('a'+j) << ")" << " ";	
					}
				}
			}

			cout << endl;

			if (t.numPos()==1){
				for(int i=0; i<t.getFils(); i++){
					for(int j=0; j<t.getCols();j++){
						if(t.posValida(i,j)){
							a= i;
							b= j;
						}
					}
				}
				cout << "Ficha colocada automáticamente" << endl;
			}			
			else{
				t.prettyPrint();
				do{
				
					if(t.getTurno() == 1){
						cout << "\033[1;34m";
						getNombre();
						cout << "\033[1;0m"; 
					}
					else{
						cout << "\033[1;32m";
					 	getNombre();
					 	cout << "\033[1;0m"; 
					}
		
					cout << ", escoja una columna (letra a-" << (char)('a'+t.getCols()-1) << ") y una fila(0-" << t.getCols()-1 << "): ";
					cin >> letra >> a;
					b= letra -'a';

				}while(a<0 || a >= t.getFils() || b <0 || b>=t.getCols());
			}
			t.setFicha(a,b);


		}

	


