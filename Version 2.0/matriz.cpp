#include <iostream>
#include <cassert>
#include "matriz.h"
using namespace std;
		
Matriz::Matriz(){
	fils = cols = 0;
	datos = 0;
}
		
Matriz::Matriz(int f, int c){
	if(f > 0 && c >= 0 && f <= 10 && c <= 10){
		fils = f;
		cols = c;

		datos = new int[f*c];

		for(int i=0; i<fils; i++){
			for(int j=0; j<cols; j++){
				datos[i] = 0;
			}
		}

	}
	else{
		fils = 0;
		cols = 0;
	}
}

Matriz::Matriz(const Matriz& m){
	if (m.datos == 0){
		fils = cols = 0;
		datos = 0;
	}
	else{
		fils = m.fils;
		cols = m.cols;
		int tam = fils * cols;
		datos = new int[fils * cols];

		for (int i = 0; i < tam; ++i){
			datos[i] = m.datos[i];
		}
	}
}

// DUDA
Matriz& Matriz::operator=(const Matriz& m){
	if (this != &m){
		delete[] datos;
		if (m.datos == 0){
			fils = cols = 0;
			datos = 0;
		}
		else{
			fils = m.fils;
			cols = m.cols;
			datos = new int[m.fils * m.cols];
			int tam = fils * cols;
					
			for (int i = 0; i < tam; ++i){
				datos[i] = m.datos[i];
			}
		}			
	}
	return *this;
}

int Matriz::getFils()const{
	return fils;
}

int Matriz::getCols()const{
	return cols;
}

void Matriz::setFils(int f){
	fils = f;
}

void Matriz::setCols(int c){
	cols = c;
}

int Matriz::getPos(int f,int c)const{
	int valor;

	if(f<0 || c<0 || f>=getFils() || c>=getCols()){
		valor = -1;
	}
	else{
		valor = datos[(f * cols) + c];
	}
	return valor;
}			

void Matriz::setPos(int f,int c, int v){			
	assert(f>=0 && f<getFils() && c>=0 && c<getCols());
	datos[(f * cols) + c]= v;
}

ostream& operator<<(ostream& os, const Matriz& m){
	for (int i = 0; i < m.getFils(); ++i){
		for (int j = 0; j < m.getCols(); ++j){
			os << m.getPos(i,j);
		}
	}

	return os;
}

istream& operator>>(istream& is, Matriz& m){
	int f, c, v;

	is >> f >> c;
	Matriz aux(f,c);

	for (int i = 0; i < m.getFils(); ++i){
		for (int j = 0; j < m.getCols(); ++j){
			is >> v;
			m.setPos(i,j,v);
		}
	}

	if(is)
		m = aux;

	return is;
}

void Avanzar(istream& is)
{
  while (isspace(is.peek()) || is.peek()=='%') {
    if (is.peek()=='%')
      is.ignore(1024,'\n'); // Suponemos una línea tiene menos de 1024
    else is.ignore();
  }
}


