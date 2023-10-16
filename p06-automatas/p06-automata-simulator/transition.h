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

#ifndef TRANSITION_H
#define TRANSITION_H

#include <iostream>
#include "symbol.cc"
#include "state.cc"

/** 
 *  @brief Esta clase se usa para guardar las transiciones
 *         Guarda los siguientes datos:
 *            - Símbolo con el que se transita (symbol_)
 *            - Siguientes estados (next_state_)
 *            - Estado actual (actual_state_)
 */
class Transition {
 private:
  Symbol symbol_;
  unsigned int actual_state_;
  unsigned int next_state_;

 public:
  /// Constructores
  Transition() {};
  Transition(const Transition& transition);
  Transition(const Symbol symbol, const unsigned int actual_state, const unsigned int next_state);

  /// Getters y setters
  void setSymbol(Symbol symbol) { symbol_ = symbol; };
  Symbol getSymbol() const { return symbol_; };
  void setActualState(unsigned int state) { actual_state_ = state; };
  unsigned int getActualState() const { return actual_state_; };
  void setNextState(unsigned int states) { next_state_ = states; };
  unsigned int getNextState() const { return next_state_; };

  /// Sobrecargas
  friend bool operator==(const Transition& transition1, const Transition& transition2);
  friend bool operator!=(const Transition& transition1, const Transition& transition2);
  friend bool operator<(const Transition& transition1, const Transition& transition2);
  friend bool operator>(const Transition& transition1, const Transition& transition2);
  friend std::ostream& operator<<(std::ostream& out, const Transition& transition);
};

#endif