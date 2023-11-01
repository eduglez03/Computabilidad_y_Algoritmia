#include<iostream>

#include "transiciones.h"

class TrancisionesDFA {
  public:
    TrancisionesDFA() {} // Constructor por defecto
    TrancisionesDFA(std::set<Estado> estadoActual, Simbolo simbolo, std::set<Estado> estadoSiguiente) : estadoActual_(estadoActual), simbolo_(simbolo), estadoSiguiente_(estadoSiguiente) {} // Constructor con parámetros

    // Getters
    std::set<Estado> getEstadoActual() const { return estadoActual_; }
    Simbolo getSimbolo() const { return simbolo_; }
    std::set<Estado> getEstadoSiguiente() const { return estadoSiguiente_; }

    // Setters
    void setEstadoActual(std::set<Estado> estadoActual) { estadoActual_ = estadoActual; }
    void setSimbolo(Simbolo simbolo) { simbolo_ = simbolo; }
    void setEstadoSiguiente(std::set<Estado> estadoSiguiente) { estadoSiguiente_ = estadoSiguiente; }


    /// Sobrecargas
    friend bool operator==(const Trancisiones& trancision1, const Trancisiones& trancision2);
    friend bool operator!=(const Trancisiones& trancision1, const Trancisiones& trancision2);
    friend bool operator<(const Trancisiones& trancision1, const Trancisiones& trancision2);
    friend bool operator>(const Trancisiones& trancision1, const Trancisiones& trancision2);
    friend std::ostream& operator<<(std::ostream& out, const Trancisiones& trancision);
  
  private:
    Simbolo simbolo_;
    std::set<Estado> estadoActual_;
    std::set<Estado> estadoSiguiente_;
};