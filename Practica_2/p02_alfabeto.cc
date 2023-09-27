// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnologíıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con Cadenas
// Autor: Eduardo González Gutiérrez
// Correo: alu0101461588@ull.edu.es
// Fecha: 27/09/2023
// Archivo cya-P02_alfabeto.cc: Implementacion metodos clase Alfabeto
// Contiene la implementacion de los metodos declarados en la clase Alfabeto
// Referencias:
// Enlaces de interés

// Historial de revisiones
// 12/09/2023 - Creación (primera versión) del código

#include "p02_alfabeto.h"

/**
 * @brief Método que permite crear un alfabeto a partir de una cadena
 * 
 * @param cadenas 
 * @return std::vector<char> 
 */
std::vector<Simbolo> Alfabeto::CrearAlfabeto(Cadena cadenas) {

  std::vector<Simbolo> vector_char;
  std::set<Simbolo> set_char;

  for (int i = 0; i < cadenas.get_length(); i++) {
    set_char.insert(cadenas.at(i));
  }
  
  for (Simbolo elemento : set_char) {
    vector_char.push_back(elemento);
  }

  return vector_char;
}