#include <iostream>
#include <vector>
#include <set>

#pragma once 

#include "simbolo.h"

class Alfabeto {
  public:
    Alfabeto() {} // Constructor por defecto
    Alfabeto(std::string& cadena); // Constructor de la clase

    std::vector<Simbolo> get_alfabeto() const { return alfabeto_;} // Getter alfabeto
    int get_size() const { return alfabeto_.size();} // Getter tamaño alfabeto
    void add(Simbolo simbolo); // Metodo que añade un nuevo simbolo al alfabeto
    bool buscar(Simbolo simbolo) const; // Metodo que comprueba si un elemento existe en el alfabeto

    friend std::ostream& operator<<(std::ostream& out, const Alfabeto& alfabeto); // Sobrecarga operador extraccion

  private:
    std::vector<Simbolo> alfabeto_;
};