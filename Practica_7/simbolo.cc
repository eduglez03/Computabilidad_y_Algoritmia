// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnologíıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 7: Forma Normal de Chomsky
// Autor: Eduardo González Gutiérrez
// Correo: alu0101461588@ull.edu.es
// Fecha: 02/11/2023
// Archivo simbolo.cc: Implementacion metodos clase Simbolo

#include <iostream>
#include "simbolo.h"

/**
 * @brief Sobrecarga del operador de salida
 * 
 * @param out 
 * @param simbolo 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& out, const Simbolo& simbolo) {
  out << simbolo.getSimbolo();
  return out;
}

/**
 * @brief Sobrecarga operador ==
 * 
 * @param simbolo1 
 * @param simbolo2 
 * @return true 
 * @return false 
 */
bool operator==(const Simbolo& simbolo1, const Simbolo& simbolo2) {
  return simbolo1.getSimbolo() == simbolo2.getSimbolo();
}

/**
 * @brief Sobrecarga operador !=
 * 
 * @param simbolo1 
 * @param simbolo2 
 * @return true 
 * @return false 
 */
bool operator!=(const Simbolo& simbolo1, const Simbolo& simbolo2) {
  return simbolo1.getSimbolo() != simbolo2.getSimbolo();
}

/**
 * @brief Sobrecarga operador <
 * 
 * @param simbolo1 
 * @param simbolo2 
 * @return true 
 * @return false 
 */
bool operator<(const Simbolo& simbolo1, const Simbolo& simbolo2) {
  return simbolo1.getSimbolo() < simbolo2.getSimbolo();
}