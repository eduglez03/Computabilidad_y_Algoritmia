#include<iostream>
#include<vector>

#include "simbolo.h"
#include "alfabeto.h"

class Cadena {
  public:
    Cadena(std::string); // Constructor de la clase

    Alfabeto get_alfabeto(); // Getter alfabeto cadena
    std::string get_cadena(); // Getter cadena
    int length(); // Getter longitud cadena

  private:
    Alfabeto alfabeto_;
    std::vector<Simbolo> cadena_
};

// Constructor de la clase
Cadena::Cadena(std::string cadena) {
  for(auto simbolo : cadena) {
    cadena_.push_back(simbolo);
  }
}

// Getter alfabeto cadena
Afabeto Cadena::get_alfabeto() {
  return alfabeto_;
}

// Getter cadena
std::string Cadena::get_cadena() {
  std::string cadena;
  for (auto simbolo : cadena_) {
    cadena += " " + simbolo.get_simbolo();
  }
  return cadena_;
}

// Getter longitud cadena
int Cadena::length() {
  return cadena_.size();
}

