#include<iostream>
#include<set>
#include <vector>
#include <string>

#include "simbolo.h"

class Alfabeto {
  public:
    Alfabeto() {} // Constructor por defecto
    Alfabeto(std::string& string); // Constructor con parámetros
    Alfabeto(std::set<Simbolo> alfabeto) {alfabeto_ = alfabeto;} // Constructor con parámetros

    std::set<Simbolo> getAlfabeto() const { return alfabeto_; } // Getter Alfabetoç
    void setAlfabeto(std::set<Simbolo> alfabeto) { alfabeto_ = alfabeto; } // Setter Alfabeto
    int getSize() const { return alfabeto_.size(); } // Getter tamaño alfabeto

    void insertarSimbolo(Simbolo simbolo); // Inserta un símbolo en el alfabeto
    bool encontrarSimbolo(Simbolo simbolo) const; // Encuentra un símbolo en el alfabeto

    friend std::ostream& operator<<(std::ostream& out, const Alfabeto& alfabeto); // Sobrecarga del operador de salida

  private:
    std::set<Simbolo> alfabeto_;
};
