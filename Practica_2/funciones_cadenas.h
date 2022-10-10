// Universidad de La Laguna. Escuela Superior de Ingeniería y Tecnología
// 2º de Grado en Ingeniería Informática.  
// Asignatura: Computabilidad y Algoritmia

// Práctica 2: Lenguajes
// Autor: Eduardo González Gutiérrez
// Correo: alu0101461588@ull.edu.es
// Fecha: 11/10/2022
// Archivo clase_alfabeto.cc: Implementación de la clase alfabeto

// Historial de revisiones
// 28/09/2022 - Creación, primera versión del código


#include <iostream>

#include "alfabeto.h"
#include "lenguaje.h"

#ifndef FUNCIONES_H
#define FUNCIONES_H

// Método que obtiene los lenguajes y el alfabeto del fichero
void ObtieneAlfabetoLenguaje(const std::string& kLineaEntrada, Alfabeto& alfabeto, Lenguaje& lenguaje);

// Método que contatena dos lenguajes y lo muestra por pantalla
void Concatenacion(std::ofstream& kFicheroSalida, const Lenguaje& kLenguaje1, const Lenguaje& kLenguaje2);

// Método que une dos lenguajes y lo muestra por pantalla
void Union(std::ofstream& kFicheroSalida, const Lenguaje& kLenguaje1, const Lenguaje& kLenguaje2);

// Método que intersecciona dos lenguajes y lo muestra por pantalla
void Interseccion(std::ofstream& kFicheroSalida, const Lenguaje& kLenguaje1, const Lenguaje& kLenguaje2);

// Método que hace la diferencia de dos lenguajes y lo muestra por pantalla
void Diferencia(std::ofstream& kFicheroSalida, const Lenguaje& kLenguaje1, const Lenguaje& kLenguaje2);

// Método que hace la inversa y lo muestra por pantalla
void Inversa(std::ofstream& kFicheroSalida, const Lenguaje& kLenguaje);

// Método que hace la potencia y lo muestra por pantalla
void Potencia(std::ofstream& kFicheroSalida, const Lenguaje& kLenguaje);


#endif