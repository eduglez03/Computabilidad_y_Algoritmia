#include <iostream>
#include "alfabeto.h"

Alfabeto::Alfabeto(std::string& string) {
  for (const auto& elem : string) {
    Simbolo simbolo = elem;
    insertarSimbolo(simbolo);
  }
}

// Sobrecarga del operador de salida
std::ostream& operator<<(std::ostream& out, const Alfabeto& alfabeto) {
  out << "{";
  for (const auto& simbolo : alfabeto.getAlfabeto()) {
    out << simbolo << " ";
  }
  out << "}";
  return out;
}

// Encuentra un símbolo en el alfabeto
bool Alfabeto::encontrarSimbolo(Simbolo simbolo) const {
  bool encontrado = false;
  for (const auto& elem : getAlfabeto()) {
    if (simbolo.getSimbolo() == elem.getSimbolo()) encontrado = true;
  }
  return encontrado;
}


// Inserta un símbolo en el alfabeto
void Alfabeto::insertarSimbolo(Simbolo simbolo) {
  alfabeto_.insert(simbolo);
}