#include "DFA.h"

// Constructor con parámetros
DFA::DFA(const DFA& dfa) {
  alfabeto_ = dfa.getAlfabeto();
  estados_ = dfa.getEstados();
  numEstados_ = dfa.getNumEstados();
  estadoInicial_ = dfa.getEstadoInicial();
  estadosFinales_ = dfa.getEstadosFinales();
  trancisiones_ = dfa.getTrancisiones();
}

// Constructor con parametros
DFA::DFA(Alfabeto alfabeto, std::vector<std::set<Estado>> estados, int numEstados, std::set<Estado> estadoInicial, std::vector<std::set<Estado>> estadosFinales, std::vector<TrancisionesDFA> trancisiones) {
  alfabeto_ = alfabeto;
  estados_ = estados;
  numEstados_ = numEstados;
  estadoInicial_ = estadoInicial;
  estadosFinales_ = estadosFinales;
  trancisiones_ = trancisiones;
}