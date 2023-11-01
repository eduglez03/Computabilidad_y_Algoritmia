#include "simbolo.h"

std::ostream& operator<<(std::ostream& out, const Simbolo& simbolo) {
  out << simbolo.getSimbolo();
  return out;
}

bool operator<(const Simbolo& simbolo1, const Simbolo& simbolo2) {
  return simbolo1.getSimbolo() < simbolo2.getSimbolo();
}

bool operator==(const Simbolo& simbolo1, const Simbolo& simbolo2) {
  return simbolo1.getSimbolo() == simbolo2.getSimbolo();
}

bool operator!=(const Simbolo& simbolo1, const Simbolo& simbolo2) {
  return simbolo1.getSimbolo() != simbolo2.getSimbolo();
}