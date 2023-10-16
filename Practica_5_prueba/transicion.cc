#include "transicion.h"

// Constructor de la clase
Transicion::Transicion(Simbolo simbolo, unsigned int estadoActual, unsigned int estadoSiguiente) {
  simbolo_ = simbolo;
  estadoActual_ = estadoActual;
  estadoSiguiente_ = estadoSiguiente;
}

// Sobrecarga del operador ==
bool operator==(const Transicion& transicion1, const Transicion& transicion2) {
  bool condicion = true;
  if (transicion1.get_estadoActual() != transicion2.get_estadoActual()) condicion = false;
  if (transicion1.get_estadoSiguiente() != transicion2.get_estadoSiguiente()) condicion = false;
  if (transicion1.get_simbolo() != transicion2.get_simbolo()) condicion = false;
  return condicion;
}

// Sobrecarga del operador !=
bool operator!=(const Transicion& transicion1, const Transicion& transicion2) {
  return !(transicion1 == transicion2);
}

// Sobrecarga del operador <
bool operator<(const Transicion& transicion1, const Transicion& transicion2) {
  return transicion1.get_estadoActual() < transicion2.get_estadoActual();
}

// Sobrecarga del operador >
bool operator>(const Transicion& transicion1, const Transicion& transicion2) {
  return !(transicion1 < transicion2);
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream& out, const Transicion& transicion) {
  out << transicion.get_estadoActual();
  out << "(" << transicion.get_simbolo() << "): ";
  out << transicion.get_estadoSiguiente();
  return out;
}