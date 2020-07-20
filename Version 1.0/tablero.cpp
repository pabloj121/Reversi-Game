#include "tablero.h"
#include <iostream>
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
	turno = 1;
}
Tablero::Tablero(int f, int c){
	tablero.setFils(f);
	tablero.setCols(c);
	turno= 1;
	this->vaciarTablero();
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

bool Tablero::getFinal() const{ // queda otra posibilidad
	return (turno == 0);
}

int Tablero::getScore(int player) const{
	int score = 0;
	if(getFinal()){			
		for(int i= 0; i< getFils(); i++){
			for(int j= 0; j < getCols(); j++){
					/*if(player == 1){ //tipo de jugador
						if(getPos(i,j) == 1){
							score++;
						}
					}
					else if(player == 2){
						if(getPos(i,j) == 2){
							score++;
						}
					}
					*/
					if(getPos(i,j) == player){
							score++;
					}	
			}
		}
	}
	return score;
}

void Tablero::iniciarTablero(){
	int iniciof = tablero.getFils()/2;
	int inicioc = tablero.getCols()/2;
	tablero.setPos(iniciof-1, inicioc-1, 1);	
	tablero.setPos(iniciof-1, inicioc, 2);
	tablero.setPos(iniciof, inicioc, 1);
	tablero.setPos(iniciof, inicioc-1, 2);
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

void Tablero::setFicha(int x, int y){ // falta algoritmo de incluir que hay q 								
	if(posValida(x,y)){			//rotar las fichas del enemigo al poner ficha!!
		//	cout << "La posicion en la que escribo antes de escribir vale: "<<getPos(x,y)<< endl;

		tablero.setPos(x,y, getTurno());

		rotaEnemigo(x,y);
		cambiarTurno();
	}
}

void Tablero::vaciarTablero(){
	for(int i= 0; i< getFils(); i++){
		for(int j= 0; j<getCols(); j++){
			tablero.setPos(i,j,0);
		}
	}
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

void Tablero::prettyPrint(){ // revisar codigo
	char letra = 'a';
	cout << "   ";
	for(int i= 0; i< getCols(); i++){
		cout << "\033[1;33m" << (char)(letra+i) << "\033[1;0m" << " ";
	}
	cout << endl << "   ";
	for(int i= 0; i< getCols(); i++){
		cout << "--" ;
	}
	cout << endl;

	for(int i= 0; i< getFils(); i++){
		cout << " " << "\033[1;31m"<< i << "\033[1;0m"<< "|";
		for(int j= 0; j< getCols(); j++){			
			if(posValida(i,j)){
				cout << ".";
			}
			else if(getPos(i,j) == 1)
				cout << "\033[1;34m" <<"x" << "\033[1;0m"; 
			else if(getPos(i,j) == 2){
				cout << "\033[1;32m" << "o" << "\033[1;0m";
			}
			else{
				cout << " ";
			}
			cout << "|";			
		}
		cout << endl;
	}
	cout << "   ";
	for(int i= 0; i< getFils(); i++){
		cout << "--";
	}
	cout << endl;
}
