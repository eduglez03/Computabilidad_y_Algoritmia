all: programa$
$
programa: alfabeto.o cadena.o  alfabetos_main.o $
    g++ -g -o archivo2.out alfabeto.o cadena.o alfabetos_main.o
$
alfabetos_main.o: alfabetos_main.cpp$
    g++ -c alfabetos_main.cpp
$
cadena.o: cadena.cpp$
    g++ -c cadena.cpp
$
alfabeto.o: alfabeto.cpp$
    g++ -c alfabeto.cpp
$
clean: $
    rm -f archivo2.out *.o$
 
	