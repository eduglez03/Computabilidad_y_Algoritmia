#include "estado.h"


// Constructor
Estado::Estado(std::string nombre, unsigned int identificador, bool aceptacion) {
  nombre_ = nombre;
  identificador_ = identificador;
  aceptacion_ = aceptacion;
}

// Sobrecarga del operador ==
bool operator==(const Estado& estado1, const Estado& estado2) {
  bool condicion = true;
  if (estado1.get_identificador() != estado2.get_identificador()) condicion = false;
  return condicion;
}

// Sobrecarga del operador !=
bool operator!=(const Estado& estado1, const Estado& estado2) {
  return !(estado1 == estado2);
}

// Sobrecarga del operador <
bool operator<(const Estado& estado1, const Estado& estado2) {
  return (estado1.get_identificador() < estado2.get_identificador());
}

// Sobrecarga del operador >
bool operator>(const Estado& estado1, const Estado& estado2) {
  return !(estado1 < estado2);
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream& out, const Estado& estado) {
  out << estado.get_nombre() << "(" << estado.get_identificador() << ")";
  out << "(" << estado.get_aceptacion() << ")";
  return out;
}