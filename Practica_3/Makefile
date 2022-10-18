main_cadenas: main_cadenas.o alfabeto.o cadena.o simbolo.o funciones_cadenas.o lenguaje.o
	g++ -Wall -std=c++17 main_cadenas.o lenguaje.o alfabeto.o cadena.o simbolo.o funciones_cadenas.o -o main_cadenas 

main_cadenas.o: main_cadenas.cc alfabeto.h
	g++ -c main_cadenas.cc -o main_cadenas.o 

lenguaje.o: lenguaje.cc alfabeto.h
	g++ -c lenguaje.cc -o lenguaje.o

alfabeto.o: alfabeto.cc alfabeto.h
	g++ -c alfabeto.cc -o alfabeto.o

cadena.o: cadena.cc cadena.h
	g++ -c cadena.cc -o cadena.o

simbolo.o: simbolo.cc simbolo.h
	g++ -c simbolo.cc -o simbolo.o

funciones_cadenas.o: funciones_cadenas.cc 
	g++ -c funciones_cadenas.cc -o funciones_cadenas.o

clean:
	rm main_cadenas main_cadenas.o lenguaje.o alfabeto.o cadena.o simbolo.o funciones_cadenas.o 