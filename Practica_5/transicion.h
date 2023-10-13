#include<iostream>

#include "simbolo.h"
#include "estado.h"

class Transicion {
  public:
    Transicion() {} // Constructor por defecto
    Transicion(Simbolo, int, int); // Constructor de la clase

    Simbolo get_simbolo(); // Getter simbolo con el que se transita
    int get_estadoActual(); // Getter estado actual
    int get_estadoSiguiente(); // Getter estado siguiente

    void set_simbolo(Simbolo); // Setter simbolo con el que se transita
    void set_estadoActual(int); // Setter estado actual
    void set_estadoSiguiente(int); // Setter estado siguiente

    friend bool operator==(const Transicion& transicion1, const Transicion& transicion2); // Sobrecarga operador ==
    friend bool operator!=(const Transicion& transicion1, const Transicion& transicion2); // Sobrecarga operador !=
    friend bool operator<(const Transicion& transicion1, const Transicion& transicion2); // Sobrecarga operador <
    friend bool operator>(const Transicion& transicion1, const Transicion& transicion2); // Sobrecarga operador >
    friend std::ostream& operator<<(std::ostream& out, const Transicion& transicion); // Sobrecarga operador extraccion

  private:
    Simbolo simbolo_; // Simbolo con el que se transita
    int estadoActual_;
    int estadoSiguiente_;

};

// Constructor de la clase
Transicion::Transicion(Simbolo simbolo, int estadoActual, int estadoSiguiente) {
  simbolo_ = simbolo;
  estadoActual_ = estadoActual;
  estadoSiguiente_ = estadoSiguiente;
}

// Getter simbolo con el que se transita
Simbolo Transicion::get_simbolo() {
  return simbolo_;
}

// Getter estado actual
int Transicion::get_estadoActual() {
  return estadoActual_;
}

// Getter estado siguiente
int Transicion::get_estadoSiguiente() {
  return estadoSiguiente_;
}

// Setter simbolo con el que se transita
void Transicion::set_simbolo(Simbolo simbolo) {
  simbolo_ = simbolo;
}

// Setter estado actual
void Transicion::set_estadoActual(int estadoActual) {
  estadoActual_ = estadoActual;
}

// Setter estado siguiente
void Transicion::set_estadoSiguiente(int estadoSiguiente) {
  estadoSiguiente_ = estadoSiguiente;
}

// Sobrecarga del operador ==
bool operator==(const Transicion& transicion1, const Transicion& transicion2) {
  bool condicion = true;
  if (transicion1.estadoActual_ != transicion2.estadoActual_) condicion = false;
  if (transicion1.estadoSiguiente_ != transicion2.estadoSiguiente_) condicion = false;
  if (transicion1.simbolo_ != transicion2.simbolo_) condicion = false;
  return condicion;
}

// Sobrecarga del operador !=
bool operator!=(const Transicion& transicion1, const Transicion& transicion2) {
  return !(transicion1 == transicion2);
}

// Sobrecarga del operador <
bool operator<(const Transicion& transicion1, const Transicion& transicion2) {
  return transicion1.estadoActual_ < transicion2.estadoActual_;
}

// Sobrecarga del operador >
bool operator>(const Transicion& transicion1, const Transicion& transicion2) {
  return !(transicion1 < transicion2);
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream& out, const Transicion& transicion) {
  out << transicion.estadoActual_;
  out << "(" << transicion.simbolo_ << "): ";
  out << transicion.estadoSiguiente_;
  return out;
}