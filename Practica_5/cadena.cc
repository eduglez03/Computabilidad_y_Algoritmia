#include "cadena.h"

// Constructor de la clase
Cadena::Cadena(std::string& cadena) {
  for(const auto& simbolo : cadena) {
    cadena_.push_back(simbolo);
  }
}

// Getter cadena
std::string Cadena::get_cadena() const{
  std::string cadena;
  for (const auto& simbolo : cadena_) {
    cadena += " " + simbolo.get_simbolo();
  }
  return cadena;
}

// Sobrecarga operador extraccion
std::ostream& operator<<(std::ostream& out, const Cadena& cadena) {
  out << "'";
  
  out << "'";
  return out;
}

