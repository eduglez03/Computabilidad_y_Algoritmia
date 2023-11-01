#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<map>

#include "DFA.h"

class NFA {
  public:
    NFA() {} // Constructor por defecto
    NFA(const NFA& nfa); // Constructor de copia

    // Getters
    Alfabeto getAlfabeto() const { return alfabeto_; }
    std::set<Estado> getEstados() const { return estados_; }
    int getNumEstados() const { return numEstados_; }
    Estado getEstadoInicial() const { return estadoInicial_; }
    std::set<Estado> getEstadosFinales() const { return estadosFinales_; }
    std::vector<Trancisiones> getTrancisiones() const { return trancisiones_; }
    std::vector<Trancisiones> getTransicionesDesdeEstado(const Estado& estado) const;

    Estado getEstado(int id) const;
    
    // Setters
    void setAlfabeto(Alfabeto alfabeto) { alfabeto_ = alfabeto; }
    void setEstados(std::set<Estado> estados) { estados_ = estados; }
    void setNumEstados(int numEstados) { numEstados_ = numEstados; }
    void setEstadoInicial(Estado estadoInicial) { estadoInicial_ = estadoInicial; }
    void setEstadosFinales(std::set<Estado> estadosFinales) { estadosFinales_ = estadosFinales; }
    void setTrancisiones(std::vector<Trancisiones> trancisiones) { trancisiones_ = trancisiones; }

    // Funciones
    DFA NFAtoDFA(const NFA& nfa);
    std::set<Estado> epsilonClausura(const std::set<Estado>& estados, const NFA& nfa) const;
    std::set<Estado> move(const std::set<Estado>& states, const Simbolo& symbol, const NFA& nfa) const;

  private:
    Alfabeto alfabeto_;
    std::set<Estado> estados_;
    int numEstados_;
    Estado estadoInicial_;
    std::set<Estado> estadosFinales_;
    std::vector<Trancisiones> trancisiones_;
};