#include "simbolo.h"

// Sobrecarga operador extraccion
std::ostream& operator<<(std::ostream& out, const Simbolo& simbolo) {
  out << simbolo.get_simbolo();
  return out;
}

// Sobrecarga operador ==
bool operator==(const Simbolo& simbolo1, const Simbolo& simbolo2) {
  return simbolo1.get_simbolo() == simbolo2.get_simbolo();
}

// Sobrecarga operador !=
bool operator!=(const Simbolo& simbolo1, const Simbolo& simbolo2) {
  return simbolo1.get_simbolo() != simbolo2.get_simbolo();
}

// Sobrecarga operador < 
bool operator<(const Simbolo& simbolo1, const Simbolo& simbolo2) {
  return simbolo1.get_simbolo() < simbolo2.get_simbolo();
}