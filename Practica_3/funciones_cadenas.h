// Universidad de La Laguna. Escuela Superior de Ingeniería y Tecnología
// 2º de Grado en Ingeniería Informática.  
// Asignatura: Computabilidad y Algoritmia

// Práctica 3: Calculadora lenguajes formales
// Autor: Eduardo González Gutiérrez
// Correo: alu0101461588@ull.edu.es
// Fecha: 17/10/2022

// Historial de revisiones
// 28/09/2022 - Creación, primera versión del código


#include <iostream>
#include <stack>
#include <string>

#include "alfabeto.h"
#include "lenguaje.h"

#ifndef FUNCIONES_H
#define FUNCIONES_H

bool EsOperador(const char& kElementoComprobar);  // comprueba si es un operador para poder realizar la operacion en la pila
std::string SacaOperarcionesRPN(const std::string& kLineaLeer, int& posicion_leer);  // Método que saca la siguiente operacion a hacer del fichero para trabajar con la pila
Lenguaje RPNLenguajes(const std::vector<Lenguaje>& kVectorLenguaje, const std::string& kLineaLeer);  // metodo que realiza la notacion polaca inversa y devuelve el lenguaje resultante
Lenguaje SacaLenguajeString(const std::string kStringSacarLenguaje);  // metodo que te saca el lenguaje de una string dada en un formato válido
bool EncuentraSimbolo(const std::string& kPalabraComprobar, const char& kCaracterComprobar);  // metodo que dice si un carácter se encuentra en la string

#endif