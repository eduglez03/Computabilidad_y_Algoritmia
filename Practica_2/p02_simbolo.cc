// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnologíıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con Cadenas
// Autor: Eduardo González Gutiérrez
// Correo: alu0101461588@ull.edu.es
// Fecha: 27/09/2023
// Archivo cya-P02_simbolo.cc: Implementacion metodos clase Simbolo
// Contiene la implementacion de los metodos declarados en la clase Simbolo
// Referencias:
// Enlaces de interés

// Historial de revisiones
// 12/09/2023 - Creación (primera versión) del código

#include "p02_simbolo.h"

/**
 * @brief Construct a new Simbolo:: Simbolo object
 * 
 * @param simbolo 
 */
Simbolo::Simbolo(char simbolo) {
    simbolo_ = simbolo;
}

/**
 * @brief Getter simbolo
 * 
 * @return char 
 */
char Simbolo::get_simbolo() {
  return simbolo_;
}

/**
 * @brief Sobrecarga operador "menor que" para usarlo con un set de simbolos en metodos de la clase Alfabeto
 * 
 * @param simbolo2 
 * @return true 
 * @return false 
 */
bool Simbolo::operator<(const Simbolo& simbolo2) const {
  return simbolo_ < simbolo2.simbolo_;
}