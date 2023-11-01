#include "estado.h"

Estado::Estado(const Estado& estado) {
  identificador_ = estado.identificador_;
  aceptacion_ = estado.aceptacion_;
}

Estado::Estado(int identificador, bool aceptacion) {
  identificador_ = identificador;
  aceptacion_ = aceptacion;
}

void Estado::operator=(const Estado& estado) {
  identificador_ = estado.identificador_;
  aceptacion_ = estado.aceptacion_;
}

bool operator==(const Estado& estado1, const Estado& estado2) {
  bool equal = true;
  if (estado1.identificador_ != estado2.identificador_) equal = false;
  return equal;
}

bool operator!=(const Estado& estado1, const Estado& estado2) {
  return !(estado1 == estado2);
}

bool operator<(const Estado& estado1, const Estado& estado2) {
  return (estado1.identificador_ < estado2.identificador_);
}

bool operator>(const Estado& estado1, const Estado& estado2) {
  return !(estado1 < estado2);
}

std::ostream& operator<<(std::ostream& out, const Estado& estado) {
  out << estado.identificador_;
  out << "(" << estado.aceptacion_ << ")";
  return out;
}