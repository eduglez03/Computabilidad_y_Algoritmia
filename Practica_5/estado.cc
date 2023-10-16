#include <iostream>
#include "estado.h"

/// @brief Constructor de copia
State::State(const State& state) {
  name_ = state.getName();
  id_ = state.getID();
  final_ = state.getFinal();
}

/// @brief Constructor con parámetros
State::State(std::string name, unsigned int id, bool final) {
  name_ = name;
  id_ = id;
  final_ = final;
}

/// @brief Sobrecarga del operador =
void State::operator=(const State& state) {
  name_ = state.getName();
  id_ = state.getID();
  final_ = state.getFinal();
}


/// @brief Sobrecarga del operador ==
bool operator==(const State& state1, const State& state2) {
  bool equal = true;
  if (state1.getID() != state2.getID()) equal = false;
  return equal;
}

/// @brief Sobrecarga del operador !=
bool operator!=(const State& state1, const State& state2) {
  return !(state1 == state2);
}

/// @brief Sobrecarga del operador <
bool operator<(const State& state1, const State& state2) {
  return (state1.getID() < state2.getID());
}

/// @brief Sobrecarga del operador >
bool operator>(const State& state1, const State& state2) {
  return !(state1 < state2);
}

/// @brief Sobrecarga del operador <<
std::ostream& operator<<(std::ostream& out, const State& state) {
  out << state.getName() << "(" << state.getID() << ")";
  out << "(" << state.getFinal() << ")";
  return out;
}
