// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnologíıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 7: Forma Normal de Chomsky
// Autor: Eduardo González Gutiérrez
// Correo: alu0101461588@ull.edu.es
// Fecha: 02/11/2023
// Archivo alfabeto.cc: Implementacion metodos clase Alfabeto

#include <iostream>
#include "alfabeto.h"
#include "simbolo.h"

/**
 * @brief Construct a new Alfabeto:: Alfabeto object
 * 
 * @param string 
 */
Alfabeto::Alfabeto(std::string& string) {
  for (const auto& elem : string) {
    Simbolo simbolo = elem;
    add(simbolo);
  }
}

/**
 * @brief Sobrecarga del operador de salida
 * 
 * @param out 
 * @param alfabeto 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& out, const Alfabeto& alfabeto) {
  out << "{ ";
  for (const auto& simbolo : alfabeto.getAlfabeto()) {
    out << simbolo.getSimbolo() << ' ';
  }
  out << "}";
  return out;
}

/**
 * @brief Metodo que comprueba si un simbolo pertenece a un alfabeto
 * 
 * @param simbolo 
 * @return true 
 * @return false 
 */
bool Alfabeto::Encontrar(Simbolo simbolo) const {
  bool encontrado = false;
  for (const auto& elem : getAlfabeto()) {
    if (simbolo.getSimbolo() == elem.getSimbolo()) encontrado = true;
  }
  return encontrado;
}

/**
 * @brief Metodo que añade un simbolo al alfabeto
 * 
 * @param simbolo 
 */
void Alfabeto::add(Simbolo simbolo) {
  alfabeto_.insert(simbolo);
}