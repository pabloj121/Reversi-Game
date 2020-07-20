#ifndef _MATRIZ_BIT_H_
#define _MATRIZ_BIT_H_

class Matriz{
	private:
		static const int MAX = 10;
		int fils, cols;
		int m[MAX][MAX];
	public:
		Matriz();
		Matriz(int f, int c);
		int getFils()const;
		int getCols()const;
		int getPos(int f,int c)const;		
		void setFils(int f);	
		void setCols(int c);
		void setPos(int f,int c, int v);
};

#endif