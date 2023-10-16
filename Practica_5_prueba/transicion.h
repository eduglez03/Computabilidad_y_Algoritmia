#include<iostream>

#include "simbolo.h"
#include "estado.h"

class Transicion {
  public:
    Transicion() {} // Constructor por defecto
    Transicion(const Simbolo simbolo, const unsigned int estadoActual, const unsigned int estadoSiguiente); // Constructor de la clase

    Simbolo get_simbolo() const { return simbolo_; } // Getter simbolo con el que se transita
    int get_estadoActual() const { return estadoActual_; } // Getter estado actual
    int get_estadoSiguiente() const { return estadoSiguiente_; } // Getter estado siguiente

    void set_simbolo(Simbolo simbolo) { simbolo_ = simbolo; } // Setter simbolo con el que se transita
    void set_estadoActual(unsigned int estado) { estadoActual_ = estado; } // Setter estado actual
    void set_estadoSiguiente(unsigned int estado) { estadoSiguiente_ = estado; } // Setter estado siguiente

    friend bool operator==(const Transicion& transicion1, const Transicion& transicion2); // Sobrecarga operador ==
    friend bool operator!=(const Transicion& transicion1, const Transicion& transicion2); // Sobrecarga operador !=
    friend bool operator<(const Transicion& transicion1, const Transicion& transicion2); // Sobrecarga operador <
    friend bool operator>(const Transicion& transicion1, const Transicion& transicion2); // Sobrecarga operador >
    friend std::ostream& operator<<(std::ostream& out, const Transicion& transicion); // Sobrecarga operador extraccion

  private:
    Simbolo simbolo_; // Simbolo con el que se transita
    unsigned int estadoActual_;
    unsigned int estadoSiguiente_;

};