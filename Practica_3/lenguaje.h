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
#include <fstream>
#include <vector>
#include <set>

#include "cadena.h"
#include "alfabeto.h"

#ifndef LENGUAJE_H
#define LENGUAJE_H


// clase Lenguaje que permite crear alfabetos apartir de cadenas y trabajar con ellos
class Lenguaje{
 public:
  Lenguaje(const Cadena& kCadenaAnadir);  // constructor de la clase apartir de una cadena
  Lenguaje(const std::vector<Cadena>& kVectorCadenaAnadir);  // constructor de la clase con un vector
  Lenguaje();  // constructor por defecto de la clase que no hace nada

  std::vector<Cadena> GetLenguaje() const;  // getter que devuelve un vector de cadenas
  void SetLenguaje(const Lenguaje& kLenguajeCambiar);  // setter que modifica la clase 
  Cadena AtLenguaje(const int kPosicion) const;  // te da una cadena en una determinada posicion del lenguaje

  int LongitudLenguaje() const; // devuelve la cantidad de cadenas del lenguaje
  void AnadirLenguaje(const Cadena& kCadenaAnadir) ;   // Método para añadir una cadena en el lenguaje
  bool ExisteCadenaLenguaje(const Cadena& kCadenaComprobar) const;  // comprueba si una determinada cadena está en el lenguaje
  void EliminaCadena(const Cadena& kCadenaEliminar);  // elimina una cadena dada del lenguaje
  bool LenguajePertenceAlfabeto(const Alfabeto& kAlfabeto);  // comprueba que el lenguaje se puede formar con el alfabeto

  Lenguaje Concatenacion(const Lenguaje& kLenguajeOperar) const;   // metodo que devuelve el lenguaje concatenado con otro por parámetros
  Lenguaje Union(const Lenguaje& kLenguajeOperar) const;   // metodo que devuelve la union del lenguaje con otro por parámetros
  Lenguaje Interseccion(const Lenguaje& kLenguajeOperar) const;   // metodo que devuelve la interseccion del lenguaje con otro por parámetros
  Lenguaje Diferencia(const Lenguaje& kLenguajeOperar) const;   // metodo que devuelve la diferencia del lenguaje con otro por parámetros
  Lenguaje Inversa() const;   // metodo que devuelve la inversa del lenguaje
  Lenguaje Potencia(const int kPotencia) const;   // metodo que devuelve la potencia del lenguaje segun un indice dado
  Lenguaje LenguajeSubcadenas() const;  // metodo que devuelve un lenguaje a partir de subcadenas
  Alfabeto CreaAlfabetoDeLenguaje() const;  // metodo que crea un alfabeto que contiene todas los simbolos del lenguaje

 private:
  std::set<Cadena> lenguaje_;   // el conjunto donde se guardaran las cadenas

};

std::ostream& operator<<(std::ostream& out, const Lenguaje& kLenguajeMostrar);   // sobrecarga del operador de inserción en flujo para mostrar el alfabeto
bool operator<(const Cadena& cadena_comparar1, const Cadena& cadena_comparar2);   // sobrecarga del operador < para la clase set
Lenguaje operator+(const Lenguaje& kLenguaje1, const Lenguaje& kLenguaje2);  // sobrecarga del operador union
Lenguaje operator-(const Lenguaje& kLenguaje1, const Lenguaje& kLenguaje2);  // sobrecarga del operador diferencia
Lenguaje operator^(const Lenguaje& kLenguaje1, const Lenguaje& kLenguaje2);  // sobrecarga del operador de intersección
Lenguaje operator|(const Lenguaje& kLenguaje1, const Lenguaje& kLenguaje2);  // sobrecarga del operador de union
Lenguaje operator!(const Lenguaje& kLenguaje1);  // sobrecarga del operador de contrario para hacer la inversa
Lenguaje operator*(const Lenguaje& kLenguaje, const int kPotencia);  // sobrecarga del operador de multiplicación para hacerlo potencia

# endif