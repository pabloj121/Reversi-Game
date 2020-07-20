#include "tablero.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


void Tablero::cambiarTurno(){
	if(turno == 1){
		turno = 2;
	}		
	else{
		turno = 1;
	}

	if(!puedoPoner()){
		if(turno == 1){
			turno = 2;	
		}	
		else{
			turno = 1;
		}

		if(!puedoPoner()){
			turno = 0;
		}
	}	
}

Tablero::Tablero(){
	tablero.setFils(0);
	tablero.setCols(0);
	turno = primer_turno = 1;
	max_fichas_turno = fichas_restantes_turno = 0;
	vaciarTablero(false);
}

Tablero::Tablero(int f, int c){
	tablero.setFils(f);
	tablero.setCols(c);
	turno = primer_turno =1;
	max_fichas_turno = fichas_restantes_turno = 0;
	this->vaciarTablero(false);
	this->iniciarTablero();
}

int Tablero::getFils() const{
	return tablero.getFils();
}
		
int Tablero::getCols() const{
	return tablero.getCols();
}

int Tablero::getPos(int f, int c) const{
	return tablero.getPos(f, c);
}

int Tablero::getTurno() const{
	return turno;// inicializamos al jugador negro
}

bool Tablero::getFinal() const{ 
	return (turno == 0);
}

int Tablero::getScore(int player) const{
	int score = 0;
	if(getFinal()){			
		for(int i= 0; i< getFils(); i++){
			for(int j= 0; j < getCols(); j++){
					if(getPos(i,j) == player){
							score++;
					}	
			}
		}
	}
	return score;
}

int Tablero::fichasPorTurno()const{
	return max_fichas_turno;
}

int Tablero::fichasRestantes()const{
	return fichas_restantes_turno;
}

void Tablero::setFichasTurno(int n){
	if(n >= 1 and n <= 3)
		max_fichas_turno = n;
	else{
		while(n < 1 and n > 3){
			cout << "Introduce las fichas por turno: ";
			cin >> n; 
		}
		max_fichas_turno = n;
	}
}

// Función que coloca las 4 primeras fichas de la partida
void Tablero::iniciarTablero(){
	int iniciof = tablero.getFils()/2;
	int inicioc = tablero.getCols()/2;
	
	tablero.setPos(iniciof-1, inicioc-1, 1);	
	tablero.setPos(iniciof-1, inicioc, 2);
	tablero.setPos(iniciof, inicioc, 1);
	tablero.setPos(iniciof, inicioc-1, 2);
}

void Tablero::vaciarTablero(bool cambia){
	for(int i= 0; i< getFils(); i++){
		for(int j= 0; j<getCols(); j++){
			tablero.setPos(i,j,0);
		}
	}

	if(cambia){
		// Alternar el jugador que empieza las partidas
		if (primer_turno == 1){
			primer_turno = 2;
		}
		else
			primer_turno = 1;
	}
}

int Tablero::getGanador()const{
	int ganador = 0; // inicializo a empate;
	// Al quitar player1 y player2 de tablero.h
	/*if(player1.score() > player2.score()){
		ganador = 1; 
	}
	else if(player2.score() > player1.score()){
		ganador = 2; 
	}*/
	if (getScore(1) > getScore(2)){
		ganador = 1;
	}
	else if (getScore(2) > getScore(1)){
		ganador = 2;
	}
	return ganador;
}		

bool Tablero::posValida(int x, int y)const{
	//algoritmo para encerrar la ficha del contrincante
	bool puedo = false;
	int nturno = getTurno();
	int elotro = 1;
	int iterador= 2;
			
		if(nturno == 1){
			elotro = 2;
		}
				
		if(getPos(x,y) == 0){
			if(getPos(x, y-1) == elotro){ // columna -i
				iterador= 2;
				while(getPos(x, y-iterador) == elotro){
					iterador++;
				}
				if(getPos(x, y-iterador) == nturno){
					return true;
				}
			}

			if(getPos(x,y+1) == elotro){ // columna +i
				iterador= 2;
				while(getPos(x, y+iterador) == elotro){
					iterador++;
				}
				if(getPos(x, y+iterador) == nturno){
					return true;

				}
			}

			if(getPos(x-1, y) == elotro){ // fila -i
				iterador= 2;
				while(getPos(x-iterador, y) == elotro){
					iterador++;
				}
				if(getPos(x-iterador, y) == nturno){
					return true;

				}
			}

			if(getPos(x+1, y) == elotro){ // fila +i
				iterador= 2;
				while(getPos(x+iterador, y) == elotro){
					iterador++;
				}
				if(getPos(x+iterador, y) == nturno){
					return true;

				}
			}

			if(getPos(x+1, y+1) == elotro){ // fila +i cols +i
				iterador= 2;
				while(getPos(x+iterador, y+iterador) == elotro){
					iterador++;
				}
				if(getPos(x+iterador, y+iterador) == nturno){
					return true;
				}
			}
			if(getPos(x-1, y-1) == elotro){ // fila -i cols -i
				iterador= 2;
				while(getPos(x-iterador, y-iterador) == elotro){
					iterador++;
				}
				if(getPos(x-iterador, y-iterador) == nturno){
					return true;
				}
			}
			if(getPos(x+1, y-1) == elotro){ // fila +i cols -i
				iterador= 2;
				while(getPos(x+iterador, y-iterador) == elotro){
					iterador++;
				}
				if(getPos(x+iterador, y-iterador) == nturno){
					return true;
				}
				if(x== 1 && y==4){
					//cout<< puedo << endl;
				}
			}

			if(getPos(x-1, y+1) == elotro){ // fila -i cols +i
				iterador= 2;
				while(getPos(x-iterador, y+iterador) == elotro){
					iterador++;
				}
				if(getPos(x-iterador, y+iterador) == nturno){
					return true;
				}
			}
		}
		
		return puedo;
}

int Tablero::numPos(){
	int contador =0;
		for(int i=0; i<getFils(); i++){
			for(int j=0; j<getCols(); j++){
				if(posValida(i,j)){
					contador++;
				}
			}
		}
	return contador;
}

pair<int,int>* Tablero::numPosiciones(){
	pair<int,int>* posiciones = new pair<int,int>[numPos()];
	int contador = 0;

	for (int i = 0; i < getFils(); ++i){
		for (int j = 0; j < getCols(); ++j){
			if (posValida(i,j)){
				posiciones[contador].first = i;
				posiciones[contador].second = j;
				contador++;
			}
		}
	}

	return posiciones;
}

bool Tablero::puedoPoner()const{
	for(int i= 0; i< getFils(); i++){
		for(int j= 0; j< getCols(); j++){
			if(posValida(i, j)){
				return true;
			}
		}
	}
	return false;

}

void Tablero::rotaEnemigo(int x, int y){
			//algoritmo para rotar las fichas del enemigo.
			int elotro = 1;
			int iterador;
			if(getTurno() == 1){
				elotro = 2;
			}
			//cout << "La posicion en la que escribo vale: "<<getPos(x,y)<< endl;
				
			if(getPos(x, y-1) == elotro){ // columna -i
				iterador= 1;
				while(getPos(x, y-iterador) == elotro){
					iterador++;
				}
				if(getPos(x, y-iterador) == getTurno()){
					for(int j= 1; j< iterador; j++){
						tablero.setPos(x,y-j,getTurno());
					}
				}
			}

			if(getPos(x,y+1) == elotro){ // columna +i
				iterador= 1;
				while(getPos(x, y+iterador) == elotro){
					iterador++;
				}
				if(getPos(x, y+iterador) == getTurno()){
					for(int j= 1; j< iterador; j++){
						tablero.setPos(x,y+j,getTurno());
					}				
				}
			}

			if(getPos(x-1, y) == elotro){ // fila -i
				iterador= 1;
				while(getPos(x-iterador, y) == elotro){
					iterador++;
				}
				if(getPos(x-iterador, y) == getTurno()){
					for(int i= 1; i< iterador; i++){
						tablero.setPos(x-i,y,getTurno());
					}
				}
			}

			if(getPos(x+1, y) == elotro){ // fila +i
				iterador= 1;
				while(getPos(x+iterador, y) == elotro){
					iterador++;
				}
				if(getPos(x+iterador, y) == getTurno()){
					for(int i= 1; i< iterador; i++){
						tablero.setPos(x+i,y,getTurno());
					}				
				}
			}

			if(getPos(x+1, y+1) == elotro){ // fila +i cols +i
				iterador= 1;
				while(getPos(x+iterador, y+iterador) == elotro){
					iterador++;
				}
				if(getPos(x+iterador, y+iterador) == getTurno()){
					for(int i= 1; i< iterador; i++){
						tablero.setPos(x+i,y+i,getTurno());
					}		
				}				
			}
				
			if(getPos(x-1, y-1) == elotro){ // fila -i cols -i
				iterador= 1;
				while(getPos(x-iterador, y-iterador) == elotro){
					iterador++;
				}
				if(getPos(x-iterador, y-iterador) == getTurno()){
					for(int i= 1; i< iterador; i++){
						tablero.setPos(x-i,y-i,getTurno());
					}				
				}
			}

			if(getPos(x+1, y-1) == elotro){ // fila +i cols -i
				iterador= 1;
				while(getPos(x+iterador, y-iterador) == elotro){
					iterador++;
				}
				if(getPos(x+iterador, y-iterador) == getTurno()){
					for(int i= 1; i< iterador; i++){
						tablero.setPos(x+i,y-i,getTurno());
					}				
				}
			}

			if(getPos(x-1, y+1) == elotro){ // fila -i cols +i
				iterador= 1;
				while(getPos(x-iterador, y+iterador) == elotro){
					iterador++;
				}
				if(getPos(x-iterador, y+iterador) == getTurno()){
					for(int i= 1; i< iterador; i++){
						tablero.setPos(x-i,y+i,getTurno());
					}					
				}
			}		
		}

void Tablero::setFicha(int x, int y){ // falta algoritmo de incluir que hay q 								
	if(posValida(x,y)){			//rotar las fichas del enemigo al poner ficha!!
		//	cout << "La posicion en la que escribo antes de escribir vale: "<<getPos(x,y)<< endl;

		tablero.setPos(x,y, getTurno());

		rotaEnemigo(x,y);
		cambiarTurno();
	}
}

void Tablero::prettyPrint(bool ayuda, ostream& os)const{ 
	char letra = 'a';
	os << "   ";
	for(int i= 0; i< getCols(); i++){
		os << "\033[1;33m" << (char)(letra+i) << "\033[1;0m" << " ";
	}
	os << endl << "   ";
	for(int i= 0; i< getCols(); i++){
		os << "--" ;
	}
	os << endl;

	for(int i= 0; i< getFils(); i++){
		os << " " << "\033[1;31m"<< i << "\033[1;0m"<< "|";
		for(int j= 0; j< getCols(); j++){
			if(ayuda){
				if(posValida(i,j)){
					os << ".";
				}
			}						
			if(getPos(i,j) == 1)
				os << "\033[1;34m" <<"x" << "\033[1;0m"; 
			else if(getPos(i,j) == 2){
				os << "\033[1;32m" << "o" << "\033[1;0m";
			}
			else{
				os << " ";
			}
			os << "|";			
		}
		os << endl;
	}
	os << "   ";
	for(int i= 0; i< getFils(); i++){
		os << "--";
	}
	os << endl;

	cout << "Turno " << fichas_restantes_turno << "/" << max_fichas_turno << " de jugador "; getTurno(); cout << ": (";
						
	if (getTurno()==1){
		cout << "x)";
	}
	else if(getTurno()==2)
		cout << "o";
}

istream& operator>>(istream& is, Tablero& t){
	int fil, col;

	is >> fil >> col;
	cout << "filas y columnas leidas" << endl;
	Tablero tab(fil, col);
	
	cout << "vamos a leer tablero" << endl;
	is >> tab.tablero;
	cout << "ya hemos leido el tablero" << endl;
	is >> tab.turno;
	is >> tab.fichas_restantes_turno;
	is >> tab.max_fichas_turno;

	if(is){
		tab.setFichasTurno(tab.max_fichas_turno);
		t = tab;
	}
	return is;
}

ostream& operator<<(ostream& os, const Tablero& t){
	os << t.getFils() << " " << t.getCols() << endl;
	os << " Fichas máximas por turno: " << t.fichasPorTurno() << endl;

	os << t.tablero;
	/*for (int i = 0; i < t.getFils(); ++i){
		for (int j = 0; j < t.getCols(); ++j){
			t.getPos(i, j);
		}
	}*/
	return os;
}

// Esta función no modifica el objeto this... const??
// La funcion avanzar recibe como parámetro un objeto istream... puedo usarla con un ifstream??
bool Tablero::Cargar(const char* fichero){
	ifstream fi(fichero, ios::in);
	//bool carga = true;

	if(fi){
		const char* cadena = "#MP-TABLERO-REVERSI-1.0";
		char linea[100];
		Tablero t;
		
		fi.getline(linea, 100);
		Avanzar(fi);

		// Verficamos que estamos leyendo un archivo de configuración del juego 
		for (unsigned int i = 0; i < strlen(cadena); ++i){			
			if (linea[i] != cadena[i]){
				cout << "Tablero erróneo introducida";				
				return false;
			}
		}

		cout << "cabecera correcta" << endl;
		Avanzar(fi);
		// operador>> (de entrada) de tablero
		fi >> t;
		cout << "ya hemos leido" << endl;
	}
	else{
		cout << "Lectura fallida" << endl;
		//carga = false;
	}

	return fi.good();
}
