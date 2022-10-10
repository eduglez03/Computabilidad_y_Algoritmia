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
#include <fstream>
#include <vector>
#include <set>

#include "cadena.h"

#ifndef ALFABETO_H
#define ALFABETO_H

// clase Alfabeto que permite crear alfabetos apartir de simbolos y trabajar con ellos
class Alfabeto {
 public:
  Alfabeto(const Simbolo& kSimboloAnadir);  // constructor de la clase apartir de un simbolo
  Alfabeto(const std::vector<Simbolo>& kVectorSimboloAnadir);  // constructor de la clase con un vector
  Alfabeto(const Cadena& kCadenaAlfabetoAnadir);  // constructor de la clase apartir de una cadena

  std::vector<Simbolo> GetAlfabeto() const;  //getter
  void SetAlfabeto(const Alfabeto& kAlfabetoCambiar);  //setter
  Simbolo AtAlfabeto(const int kPosicion) const;  // te da un simbolo en una determinada posicion del alfabeto

  void AnadirAlfabeto(const Simbolo& kSimboloAnadir) ;   // Método para añadir un simbolo en el alfabeto
  int LongitudAlfabeto() const;   // Muestra cuantos simbolos tiene el alfabeto
  bool CadenaPertenceAlfabeto(const Cadena& kCadenaComprobar) const;    // Método que comprueba si la cadena pertenece al alfabeto
  int CantidadSimbolosCadena(const Cadena& kCadenaComprobar) const;    // Método que te dice cuantos simbolos de ese alfabeto tienes en esa cadena
  std::vector<int> NumeroRepeticionesSimbolos(const Cadena& kCadenaComprobar) const;   // Método que te dice las repeticones de los simbolos del alfabeto en la cadena
  void ClearAlfabeto();  // elimina todos los simbolos del alfabeto (un alfabeto no puede ser vacío pero es necesario para un método)

 private:
  std::set<Simbolo> alfabeto_;     // el conjunto donde se guardaran los simbolos

};

std::ostream& operator<<(std::ostream& out, const Alfabeto& kAlfabetoMostrar);   // sobrecarga del operador de inserción en flujo para mostrar el alfabeto
bool operator<(const Simbolo& simbolo_comparar1, const Simbolo& simbolo_comparar2);   // sobrecarga del operador < para la clase set

#endif