#include<iostream>

#include "transicionesDFA.h"

class DFA {
  public:
    DFA() {} // Constructor por defecto
    DFA(const DFA& dfa); // Constructor de copia
    DFA(Alfabeto alfabeto, std::vector<std::set<Estado>> estados, int numEstados, std::set<Estado> estadoInicial, std::vector<std::set<Estado>> estadosFinales, std::vector<TrancisionesDFA> trancisiones); // Constructor con parametros

    // Getters
    Alfabeto getAlfabeto() const { return alfabeto_; }
    std::vector<std::set<Estado>> getEstados() const { return estados_; }
    int getNumEstados() const { return numEstados_; }
    std::set<Estado> getEstadoInicial() const { return estadoInicial_; }
    std::vector<std::set<Estado>> getEstadosFinales() const { return estadosFinales_; }
    std::vector<TrancisionesDFA> getTrancisiones() const { return trancisiones_; }

    // Setters
    void setAlfabeto(Alfabeto alfabeto) { alfabeto_ = alfabeto; }
    void setEstados(std::vector<std::set<Estado>> estados) { estados_ = estados; }
    void setNumEstados(int numEstados) { numEstados_ = numEstados; }
    void setEstadoInicial(std::set<Estado> estadoInicial) { estadoInicial_ = estadoInicial; }
    void setEstadosFinales(std::vector<std::set<Estado>> estadosFinales) { estadosFinales_ = estadosFinales; }
    void setTrancisiones(std::vector<TrancisionesDFA> trancisiones) { trancisiones_ = trancisiones; }

    // Funciones
    void addEstado(std::set<Estado> estado) { estados_.push_back(estado); }
    void addTrancision(TrancisionesDFA transicion) { trancisiones_.push_back(transicion); }

    // Sobrecarga de operadores
    DFA& operator=(const DFA& dfa);
    friend std::ostream& operator<<(std::ostream& os, const DFA& dfa);

  private:
    Alfabeto alfabeto_;
    std::vector<std::set<Estado>> estados_;
    int numEstados_;
    std::set<Estado> estadoInicial_;
    std::vector<std::set<Estado>> estadosFinales_;
    std::vector<TrancisionesDFA> trancisiones_;
};
