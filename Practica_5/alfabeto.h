#include<iostream>
#include<vector>
#include<set>

#include "simbolo.h"

class Alfabeto {
  public:
    Alfabeto() {} // Constructor por defecto
    Alfabeto(std::string& cadena); // Constructor de la clase

    std::vector<Simbolo> get_alfabeto(); // Getter alfabeto
    int get_size(); // Getter tamaño alfabeto

    friend std::ostream& operator<<(std::ostream& out, const Alfabeto& alfabeto); // Sobrecarga operador extraccion

  private:
    std::set<Simbolo> alfabeto_;
};


Alfabeto::Alfabeto(std::string& cadena) {
  for (const auto& elemento : cadena) {
    Simbolo simbolo = elemento;
    alfabeto_.insert(simbolo);
  }
}

// Getter alfabeto
std::vector<Simbolo> Alfabeto::get_alfabeto() {
  std::vector<Simbolo> vector_simbolos(alfabeto_.begin(), alfabeto_.end());
  return vector_simbolos;
}

// Getter tamaño alfabeto
int Alfabeto::get_size() {
  return alfabeto_.size();
}

// Sobrecarga operador extraccion
std::ostream& operator<<(std::ostream& out, Alfabeto& alfabeto) {
  out << "{ ";
  for (auto simbolo : alfabeto.get_alfabeto()) {
    out << simbolo.get_simbolo() << " ";
  }
  out << "}";
  return out;
}