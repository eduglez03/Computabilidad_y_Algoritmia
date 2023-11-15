// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnologíıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 9: Maquina de Turing
// Autor: Eduardo González Gutiérrez
// Correo: alu0101461588@ull.edu.es
// Fecha: 15/11/2023
// Archivo simbolo.cc: Implementación de la clase Simbolo

#include<iostream>

#include "simbolo.h"

/**
 * @brief Sobrecarga del operador ==
 * 
 * @param s 
 * @return true 
 * @return false 
 */
bool Simbolo::operator==(const Simbolo &s) const {
  if (simbolo_ == s.simbolo_) {
    return true;
  }
  else {
    return false;
  }
}

/**
 * @brief Sobrecarga del operador !=
 * 
 * @param s 
 * @return true 
 * @return false 
 */
bool Simbolo::operator!=(const Simbolo &s) const {
  if (simbolo_ != s.simbolo_) {
    return true;
  }
  else {
    return false;
  }
}

/**
 * @brief Sobrecarga del operador <<
 * 
 * @param flujo 
 * @param s 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream &flujo, const Simbolo &s) {
  flujo << s.simbolo_;
  return flujo;
}