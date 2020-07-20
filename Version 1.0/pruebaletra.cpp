#include <iostream>
using namespace std;

int main(){
	int i = 0;
	int filas;

	cout << "Introduce filas: ";
	cin >> filas;
	char a = 'a';

	while(i < filas){
		cout << a++ << " ";
		i++;
	}
}