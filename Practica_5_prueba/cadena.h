#include<iostream>
#include<vector>

#include "simbolo.h"
#include "alfabeto.h"

class Cadena {
  public:
    Cadena(std::string& string); // Constructor de la clase

    Alfabeto get_alfabeto() const { return alfabeto_; } // Getter alfabeto cadena
    std::string get_cadena() const; // Getter cadena
    std::string get_string() const { return string_; } // Getter string
    int length() { return cadena_.size(); } // Getter longitud cadena

    friend std::ostream& operator<<(std::ostream& out, const Cadena& cadena); // Sobrecarga operador <<

  private:
    Alfabeto alfabeto_;
    std::vector<Simbolo> cadena_;
    std::string string_;
};