/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 6
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 05 Nov 2022
 * @brief Archivo: NFA.cc
 *        Implementación de la clase NFA
 * 
 * @details 
 *    05/11/2022 - Creación del fichero
 *    05/11/2022 - Añadidos los constructores
 *    05/11/2022 - Añadidos los getters y setters
 *    05/11/2022 - Añadidas las funciones
 *    05/11/2022 - Añadidas las sobrecargas
 */

#include <vector>
#include "NFA.h"

/// @brief Constructor de copia
NFA::NFA(const NFA& nfa) {
  alphabet_ = nfa.getAlphabet();
  states_ = nfa.getStates();
  num_ = nfa.getNum();
  initial_ = nfa.getInitial();
  finals_ = nfa.getFinals();
  transitions_ = nfa.getTransitions();
}

/// @brief Sobrecarga del operador <<
std::ostream& operator<<(std::ostream& out, const NFA& nfa) {
  out << "Alfabeto: " << nfa.getAlphabet() << std::endl;
  out << "Num: " << nfa.getNum() << std::endl;
  out << "Inicial: " << nfa.getInitial() << std::endl;
  out << "Estados: " << std::endl;
  for (const auto& elem : nfa.getStates()) out << elem << std::endl;
  out << "Finales: " << std::endl;
  for (const auto& elem : nfa.getFinals()) out << elem << std::endl;
  out << "Transiciones: " << std::endl;
  for (const auto& elem : nfa.getTransitions()) out << elem << std::endl;
  return out;
}

/// @brief Busca y devuelve el estado con ese id
State NFA::find_state(unsigned int id) {
  State state;
  for (const auto& elem : states_) {
    if (elem.getID() == id) state = elem;
  }
  return state;
}

/// Método que le pases un conjunto y te calcule E-clausura
/// Unión de los E-clausura del conjunto
/// Return cuando no tengas épsilon
void NFA::epsilon_transition(std::vector<State>& states) {
  bool flag = true;
  std::vector<State> saved = states;
  while (flag) {
    flag = false;
    std::vector<State> next_state;
    for (const auto& elem : states) {
      // std::cout << elem << std::endl;
      for (const auto& transition : transitions_) {
        if (transition.getActualState() == elem.getID()) {
          // std::cout << transition << std::endl;
          if (transition.getSymbol() == '&') {
            // std::cout << transition << std::endl;
            next_state.push_back(find_state(transition.getNextState()));
            saved.push_back(find_state(transition.getNextState()));
            // std::cout << find_state(transition.getNextState()) << std::endl;
            flag = true;
          }
        }
      }
    }
    states = next_state;
  }
  states = saved;
}

/** 
 *  @brief Comprueba si la cadena es aceptada por el autómata
 *  @param[in] sequence
 *  @return True si es aceptada, false si no
 */
bool NFA::accepted(const Sequence& sequence) {
  std::string string = sequence.getString();
  /// Comprobamos la cadena vacía
  if (string == "&") return initial_.getFinal();
  /// El vector de momento solo tiene el estado inicial
  std::vector<State> states;
  states.push_back(getInitial());
  /// Recorremos la cadena
  for (const auto& elem : string) {
    std::vector<State> new_states;
    Symbol symbol = elem;
    /// Buscamos las E-transiciones
    epsilon_transition(states);
    /// Para cada estado del vector
    for (const auto& state : states) {
      /// Buscamos las transiciones
      for (const auto& transition : transitions_) {
        if (transition.getActualState() == state.getID()) {
          /// Buscamos las que nos permiten transitar
          if (transition.getSymbol() == symbol) {
            State new_state = find_state(transition.getNextState());
            new_states.push_back(new_state);
          }
        }
      }
    }
    states = new_states;
  }
  /// Comprobamos si son de aceptación
  for (const auto& elem : states) {
    if (elem.getFinal()) return true;
  } 
  return false;
}