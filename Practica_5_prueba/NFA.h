#include<iostream>
#include<set>

#include "cadena.h"
#include "transicion.h"
#include "alfabeto.h"
#include "simbolo.h"


class NFA {
  public:
    NFA() {} // Constructor por defecto

    // Getters
    Alfabeto get_Alfabeto() const { return alfabeto_; }; // Getter alfabeto
    std::set<Estado> get_Estados() const { return estados_; } // Getter estados NFA
    unsigned int get_numEstados() const { return numEstados_; } // Getter numero de estados
    Estado get_estadoInicial() const { return inicial_; } // Getter estado inicial NFA
    std::set<Estado> get_estadosFinales() const { return finales_; } // Getter estados finales
    std::vector<Transicion> get_transiciones() const { return transiciones_; } // Getter transiciones 
    
    // Setters
    void set_Alfabeto(const Alfabeto& alfabeto) { alfabeto_ = alfabeto; } // Setter alfabeto
    void set_Estados(std::set<Estado> estados) { estados_ = estados; } // Setter estados
    void set_numEstados(unsigned int numero) { numEstados_ = numero; } // Setter numero de estados
    void set_estadoInicial(Estado inicial) { inicial_ = inicial; } // Setter estado inicial
    void set_estadosFinales(std::set<Estado> finales) { finales_ = finales; } // Setter estados finales
    void set_transiciones(std::vector<Transicion> transiciones) { transiciones_ = transiciones; } // Setter transiciones
  

    bool aceptacion(const Cadena& cadena); // Funcion que comprueba si el automata acepta o no una cadena
    Estado encontrarEstado(unsigned int identificador); // Funcion que busca un estado con un identificador concreto
    void epsilonTransiciones(std::vector<Estado>& estados); // Funcion que calcula las e-transiciones de un conjunto de estados

    // Sobrecarga operador <<
    friend std::ostream& operator<<(std::ostream& out, const NFA& nfa);

  private:
    Alfabeto alfabeto_;
    std::set<Estado> estados_;
    unsigned int numEstados_;
    Estado inicial_;
    std::set<Estado> finales_;
    std::vector<Transicion> transiciones_;
};