#include<iostream>

#include "alfabeto.h"
#include "estado.h"

class Trancisiones {
  public:
    Trancisiones() {} // Constructor por defecto
    Trancisiones(Estado estadoActual, Simbolo simbolo, Estado estadoSiguiente) : estadoActual_(estadoActual), simbolo_(simbolo), estadoSiguiente_(estadoSiguiente) {} // Constructor con parámetros
    Trancisiones(const Trancisiones& trancision); // Constructor de copia

    // Getters
    Estado getEstadoActual() const { return estadoActual_; }
    Simbolo getSimbolo() const { return simbolo_; }
    Estado getEstadoSiguiente() const { return estadoSiguiente_; }

    // Setters
    void setEstadoActual(Estado estadoActual) { estadoActual_ = estadoActual; }
    void setSimbolo(Simbolo simbolo) { simbolo_ = simbolo; }
    void setEstadoSiguiente(Estado estadoSiguiente) { estadoSiguiente_ = estadoSiguiente; }

    /// Sobrecargas
    friend bool operator==(const Trancisiones& trancision1, const Trancisiones& trancision2);
    friend bool operator!=(const Trancisiones& trancision1, const Trancisiones& trancision2);
    friend bool operator<(const Trancisiones& trancision1, const Trancisiones& trancision2);
    friend bool operator>(const Trancisiones& trancision1, const Trancisiones& trancision2);
    friend std::ostream& operator<<(std::ostream& out, const Trancisiones& trancision);
  
  private:
    Simbolo simbolo_;
    Estado estadoActual_;
    Estado estadoSiguiente_;
};