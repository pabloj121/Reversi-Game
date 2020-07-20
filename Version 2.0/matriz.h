#ifndef _MATRIZ_BIT_H_
#define _MATRIZ_BIT_H_

#include <iostream>
using namespace std;

class Matriz{
	private:
		int fils, cols;
		int *datos;
	public:
		Matriz();
		Matriz(int f, int c);
		~Matriz();
		Matriz(const Matriz& m);
		Matriz& operator=(const Matriz& m);
		friend ostream& operator<<(ostream& os, const Matriz& m);
		friend istream& operator>>(istream& is, Matriz& m);
		int getFils()const;
		int getCols()const;
		int getPos(int f,int c)const;		
		void setFils(int f);	
		void setCols(int c);
		void setPos(int f,int c, int v);
};

inline Matriz::~Matriz(){
	delete [] datos;
}

void Avanzar(istream& is);


// Operador de salida
//ostream& operator<< (ostream& os, const Matriz& m);
/*{
	
	for (int i = 0; i < m.getFils(); ++i)
	{
		for (int j = 0; j < m.getCols(); ++j)
		{
			os << m.getPos(i,j);
		}
	}
	return os;
}*/

// Operador de entrada
//istream& operator>> (istream& is, Matriz& m);
/*{
	int v;

	m.datos = new int[m.getFils() * m.getCols()];

	for (int i = 0; i < m.getFils(); ++i)
	{
		for (int j = 0; j < m.getCols(); ++j)
		{
			is >> v;
			m.setPos(i,j,v);
		}
	}
	return is;
}*/

#endif