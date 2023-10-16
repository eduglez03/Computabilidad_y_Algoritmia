/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 6
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 05 Nov 2022
 * @brief Archivo: transition.h
 *        Definición de la clase transición
 * 
 * @details 
 *    05/11/2022 - Creación del fichero
 *    05/11/2022 - Añadidos los constructores
 *    05/11/2022 - Añadidos los getters y setters
 *    05/11/2022 - Añadidas las sobrecargas
 */

#include <iostream>
#include "transition.h"

/// @brief Constructor de copia
Transition::Transition(const Transition& transition) {
  symbol_ = transition.getSymbol();
  next_state_ = transition.getNextState();
  actual_state_ = transition.getActualState();
}

/// @brief Constructor con parámetros
Transition::Transition(const Symbol symbol, const unsigned int actual_state, const unsigned int next_state) {
  symbol_ = symbol;
  next_state_ = next_state;
  actual_state_ = actual_state;
}

/// @brief Sobrecarga del operador ==
bool operator==(const Transition& transition1, const Transition& transition2) {
  bool equal = true;
  if (transition1.getActualState() != transition2.getActualState()) equal = false;
  if (transition1.getNextState() != transition2.getNextState()) equal = false;
  if (transition1.getSymbol() != transition2.getSymbol()) equal = false;
  return equal;
}

/// @brief Sobrecarga del operador !=
bool operator!=(const Transition& transition1, const Transition& transition2) {
  return !(transition1 == transition2);
}

/// @brief Sobrecarga del operador <
bool operator<(const Transition& transition1, const Transition& transition2) {
  return transition1.getActualState() < transition2.getActualState();
}

/// @brief Sobrecarga del operador >
bool operator>(const Transition& transition1, const Transition& transition2) {
  return !(transition1 < transition2);
}

/// @brief Sobrecarga del operador <<
std::ostream& operator<<(std::ostream& out, const Transition& transition) {
  out << transition.getActualState();
  out << "(" << transition.getSymbol() << "): ";
  out << transition.getNextState();
  return out;
}
