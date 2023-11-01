#include "transiciones.h"

/// @brief Constructor de copia
Trancisiones::Trancisiones(const Trancisiones& trancision) {
  estadoActual_ = trancision.getEstadoActual();
  simbolo_ = trancision.getSimbolo();
  estadoSiguiente_ = trancision.getEstadoSiguiente();
}

/// @brief Sobrecarga del operador ==
bool operator==(const Trancisiones& trancision1, const Trancisiones& trancision2) {
  bool equal = true;
  if (trancision1.getEstadoActual() != trancision2.getEstadoActual()) equal = false;
  if (trancision1.getEstadoSiguiente() != trancision2.getEstadoSiguiente()) equal = false;
  if (trancision1.getSimbolo() != trancision2.getSimbolo()) equal = false;
  return equal;
}

/// @brief Sobrecarga del operador !=
bool operator!=(const Trancisiones& trancision1, const Trancisiones& trancision2) {
  return !(trancision1 == trancision2);
}

/// @brief Sobrecarga del operador <
bool operator<(const Trancisiones& trancision1, const Trancisiones& trancision2) {
  return trancision1.getEstadoActual() < trancision2.getEstadoActual();
}

/// @brief Sobrecarga del operador >
bool operator>(const Trancisiones& trancision1, const Trancisiones& trancision2) {
  return !(trancision1 < trancision2);
}

/// @brief Sobrecarga del operador <<
std::ostream& operator<<(std::ostream& out, const Trancisiones& trancision) {
  out << trancision.getEstadoActual();
  out << "(" << trancision.getSimbolo() << "): ";
  out << trancision.getEstadoSiguiente();
  return out;
}