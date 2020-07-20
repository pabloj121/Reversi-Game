#include "jugador.h"
#include <stdlib.h>
#include <time.h>
#include <utility>
#include <iostream>
using namespace std;

		Jugador::Jugador(){ //AQUI DARLE EL NOMBRE Y EL TURNO
			// Inicio el turno a 0 y asumo que tengo que asignarle el turno manualmente 
			nturno = pganadas = empatadas = puntuacion = comodines = 0;
			nombre = 0;
		}
		
		Jugador::Jugador(char nom[]){
			int tam = 0;

			while(nom[tam])
				tam++;

			nombre = new char[tam+1];

			for (int i = 0; i <= tam; ++i){
				nombre[i] = nom[i];
			}
		}

		Jugador::Jugador(const Jugador& j){
			if (j.nombre == 0)
			{
				nombre = 0;
				nturno = puntuacion = pganadas = comodines = 0;
			}
			else{
				nturno = j.nturno;
				puntuacion = j.puntuacion;
				pganadas = j.pganadas;
				comodines = j.comodines;
				int tam = Longitud(j.nombre);
				nombre = new char[tam];
				
				for (int i = 0; i < tam; ++i){
					nombre[i] = j.nombre[i];
				}
			}
		}

		Jugador& Jugador::operator=(const Jugador& j){
			if (this != &j){
				delete[] nombre;
				if (j.nombre == 0)
				{
					nombre = 0;
					nturno = puntuacion = pganadas = 0;
				}
				else{
					nturno = j.nturno;
					puntuacion = j.puntuacion;
					pganadas = j.pganadas;
					int tam = Longitud(j.nombre);
					nombre = new char[tam];
					
					for (int i = 0; i < tam; ++i)
					{
						nombre[i] = j.nombre[i];
					}
				}

			}
			return *this;
		}
		// Funcion para calcular la longitud de un nombre
		int Jugador::Longitud(char* n){
			int longitud = 0;
			
			while(*n++)
				longitud++;

			return longitud;
		}

		int Jugador::getpGanadas()const{
			return pganadas;
		}

		int Jugador::partidasEmpatadas()const{
			return empatadas;
		}

		void Jugador::setTurno(int x){
			nturno = x;
		}

		void Jugador::getNombre()const{
			int i = 0;
			while(cout << nombre[i])
				i++;
		}

		void Jugador::setPuntuacion(const Tablero& t){
			puntuacion += t.getScore(nturno);
		}

		int Jugador::Puntuacion()const{
			return puntuacion;
		}

		/*void Jugador::setNombre(){ 
			cin.getline(nombre,20);
		}*/

		void Jugador::acumulaPartidas(const Tablero& t){
			if(t.getGanador() == nturno){
				pganadas++;
				puntuacion += t.getScore(nturno);
				if (t.getGanador()==0){
					empatadas++;
				}
			}
		}
		
		void Jugador::restaComodin(){
			comodines = comodines - 1;
		}

		int Jugador::Comodines()const{
			return comodines;
		}

		bool Jugador::escogePosicion(Tablero& t){
			bool acaba = false;
			int a, b;
			a=b=0;
			char letra = ' ';

			if(nombre[0] == '@'){
				// Jugador automatico
				// FALTA TODO
				int num;
				pair <int, int>* posiciones;

				//num = 1 + rand()%((t.numPos()) - 0);
				num = rand()%t.numPos();

				posiciones = t.numPosiciones();

				a = posiciones[num].first;				
				b = posiciones[num].second;

				delete[] posiciones;			
			}
			else{
				// Jugador humano
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
					t.prettyPrint(false);
					do{
						
						cout << "Turno de jugador " << t.getTurno() << ": (";
						
						if (t.getTurno()==1)
						{
							cout << "x)";
						}
						else if(t.getTurno()==2)
							cout << "o";

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
			
						cout << ", le quedan " << 5-comodines << " comodines de 5, escoja una columna (letra a-" << (char)('a'+t.getCols()-1) << ") y una fila(0-" << t.getCols()-1 << "): ";
						cin >> letra >> a;
						b= letra -'a';

					}while(a<0 || a >= t.getFils() || b <0 || b>=t.getCols());
				}

				if (letra == '!'){
					acaba = true;
				}
				else if(letra == '?'){
					if (comodines == 0)
					{
						cout << "No te quedan comodines";
					}
					else{
						t.prettyPrint(true);
						restaComodin();
					}
				}
				else{
					t.setFicha(a,b);
				}
			}
					
			return acaba;
		}

		/*void Jugador::escogePosicionAutomatico(Tablero& t){
			bool acaba = false;
			int a, b;
			a=b=0;
			char letra = ' ';
			
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
				t.prettyPrint(false);
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

			if (letra == '!'){
				acaba = true;
			}
			else if(letra == '?'){
				if (comodines == 0)
				{
					cout << "No te quedan comodines";
				}
				else{
					t.prettyPrint(true);
					restaComodin();
				}
			}
			else{
				t.setFicha(a,b);
			}
					
		}*/

		istream& operator>>(istream& is, Jugador& j){
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
		}

		ostream& operator<<(ostream& os, const Jugador& j){
			os << " !";
			j.getNombre();
			os << endl;

			os << j.nturno << " " << j.puntuacion << " " << j.pganadas << " " << j.comodines;

			return os;
		}
