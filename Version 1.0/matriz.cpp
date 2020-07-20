#include <iostream>
#include <cassert>
#include "matriz.h"
using namespace std;
		Matriz::Matriz(){
			fils = cols = 0;
		}
		
		Matriz::Matriz(int f, int c){
			if(f > 0 && c >= 0 && f <= 10 && c <= 10){
				fils = f;
				cols = c;

				for(int i=0; i<fils; i++){
					for(int j=0; j<cols; j++){
						this->m[i][j]=0;
					}
				}

			}
			else{
				fils = 0;
				cols = 0;
			}
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
				valor = m[f][c];
			}
			return valor;
		}			

		void Matriz::setPos(int f,int c, int v){			
			assert(f>=0 && f<getFils() && c>=0 && c<getCols());
			m[f][c]= v;
		}
