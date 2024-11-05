Mochila.o: Mochila.cpp
	g++ -c Mochila.cpp
testMochila: Mochila.o
	g++ -o testMochila Mochila.o

Monedas.o: Monedas.cpp
	g++ -c Monedas.cpp
testCambio: Monedas.o
	g++ -o testCambio Monedas.o

