#include "alfabeto.h"


// Constructor 
Alfabeto::Alfabeto(std::string& cadena) {
  for (const auto& elemento : cadena) {
    Simbolo simbolo(elemento);
    add(simbolo);
  }
}

// Sobrecarga operador extraccion
std::ostream& operator<<(std::ostream& out, const Alfabeto& alfabeto) {
  out << "{ ";
  for (auto simbolo : alfabeto.get_alfabeto()) {
    out << simbolo.get_simbolo() << " ";
  }
  out << "}";
  return out;
}

// Metodo que comprueba si un simbolo existe en el alfabeto
bool Alfabeto::buscar(Simbolo simbolo) const {
  bool encontrado = false;
  for (const auto& elemento : get_alfabeto()) {
    if (simbolo.get_simbolo() == elemento.get_simbolo()) encontrado = true;
  }
  return encontrado;
}

// Metodo que añade un nuevo simbolo al alfabeto si no existe en el
void Alfabeto::add(Simbolo simbolo_entrada) {
  if(!buscar(simbolo_entrada)) {
    alfabeto_.push_back(simbolo_entrada);
  }
}



