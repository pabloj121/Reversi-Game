CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++03 -pedantic -g

reversi : matriz.h matriz.cpp tablero.h tablero.cpp jugador.h jugador.cpp main.cpp
	$(CXX) $(CXXFLAGS) -o reversi -g matriz.cpp jugador.cpp tablero.cpp main.cpp
clean:
	-rm reversi ./*~ ./*.o