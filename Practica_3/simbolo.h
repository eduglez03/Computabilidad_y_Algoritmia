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
#include <string>

#ifndef SIMBOLO_H
#define SIMBOLO_H

// clase simbolo que permite crear simbolos y trabajar con ellos 
class Simbolo {
 public:
  Simbolo(const std::string& kSimbolo = "");   // Constructor de la clase simbolo para strings
  Simbolo(const char& kSimbolo);   // Constructor de la clase simbolo para char
  void SetSimbolo(const std::string& kNuevoSimbolo);   //setter
  std::string GetSimbolo() const;   // getter
  
  void Concatenar(const char& kCaracterConcatenar);   // permite concatenar un char a al símbolo
  int Longitud() const;   // longitud del simbolo

 private:
  std::string simbolo_;
};

std::ostream& operator<<(std::ostream& out, const Simbolo& kSimboloMostrar);   // sobrecarga del operador de inserción en flujo para mostrar el simbolo
bool operator==(const Simbolo& kSimbolo1, const Simbolo& kSimbolo2);   // sobrecarga del operador de igualdad
bool operator!=(const Simbolo& kSimbolo1, const Simbolo& kSimbolo2);   // sobrecarga del operador de no igualdad


#endif