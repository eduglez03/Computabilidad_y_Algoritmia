# Makefile for Writing Make Files Example
 
# *****************************************************
# Variables to control Makefile operation
 
CC = g++
CFLAGS = -Wall -g
 
# ****************************************************
# Targets needed to bring the executable up to date
 
main: alfabetos_main.o alfabeto.o cadena.o
    $(CC) $(CFLAGS) -o main 
# The main.o target can be written more simply
 
alfabetos_main.o: alfabetos_main.cpp 
    $(CC) $(CFLAGS) -c alfabetos_main.cpp


alfabeto.o: alfabeto.cpp 
    $(CC) $(CFLAGS) -c alfabeto.cpp

cadena.o: cadena.cpp 
    $(CC) $(CFLAGS) -c cadena.cpp
	