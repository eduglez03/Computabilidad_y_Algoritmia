#include "NFA.h"

NFA::NFA(const NFA& nfa) {
  alfabeto_ = nfa.getAlfabeto();
  estados_ = nfa.getEstados();
  numEstados_ = nfa.getNumEstados();
  estadoInicial_ = nfa.getEstadoInicial();
  estadosFinales_ = nfa.getEstadosFinales();
  trancisiones_ = nfa.getTrancisiones();
}

Estado NFA::getEstado(int id) const {
  for (const Estado& estado : estados_) {
    if (estado.get_identificador() == id) {
      return estado;
    }
  }
}

std::vector<Trancisiones> NFA::getTransicionesDesdeEstado(const Estado& estado) const {
  std::vector<Trancisiones> resultado;

  for (const Trancisiones& transicion : trancisiones_) {
    if (transicion.getEstadoActual() == estado) {
      resultado.push_back(transicion);
    }
  }

  return resultado;
}

std::set<Estado> NFA::epsilonClausura(const std::set<Estado>& estados, const NFA& nfa) const {
  std::set<Estado> resultado = estados;
  std::stack<Estado> pila;

  // Agrega los estados iniciales a la pila
  for (const Estado& estado : estados) {
    pila.push(estado);
  }

  while (!pila.empty()) {
    Estado estadoActual = pila.top();
    pila.pop();

    // Obtiene las transiciones epsilon desde el estado actual
    std::vector<Trancisiones> transicionesEpsilon = nfa.getTransicionesDesdeEstado(estadoActual);

    for (const Trancisiones& transicion : transicionesEpsilon) {
      Estado estadoSiguiente = transicion.getEstadoSiguiente();

      // Si el estado siguiente no está en el resultado, agrégalo y agrégalo a la pila
      if (resultado.find(estadoSiguiente) == resultado.end()) {
        resultado.insert(estadoSiguiente);
        pila.push(estadoSiguiente);
      }
    }
  }

  return resultado;
}

std::set<Estado> NFA::move(const std::set<Estado>& estados, const Simbolo& symbol, const NFA& nfa) const {
  std::set<Estado> resultado;

  for (const Estado& estado : estados) {
    // Obtiene las transiciones desde el estado actual con el símbolo dado
    std::vector<Trancisiones> transiciones = nfa.getTransicionesDesdeEstado(estado);

    for (const Trancisiones& transicion : transiciones) {
      if (transicion.getSimbolo() == symbol) {
        resultado.insert(transicion.getEstadoSiguiente());
      }
    }
  }

  return resultado;
}

// NFA to DFA
DFA NFA::NFAtoDFA(const NFA& nfa) {
  DFA dfa;

  dfa.setAlfabeto(nfa.getAlfabeto());

  // Cola de estados no procesados
  std::queue<std::set<Estado>> NoProcesados;
  std::vector<std::set<Estado>> estadosDFA;
  std::vector<std::set<Estado>> estadosFinalesDFA;

  // Obtiene la epsilon clausura del estado inicial
  std::set<Estado> estadoInicial = nfa.epsilonClausura({nfa.getEstadoInicial()}, nfa);

  // Agrega el estado inicial a los estados no procesados
  NoProcesados.push(estadoInicial);
  dfa.setEstadoInicial(estadoInicial);

  // Mientras la cola de estados no procesados no esté vacía
  while (!NoProcesados.empty()) {
    // Obtiene el primer estado de la cola
    std::set<Estado> estadoActual = NoProcesados.front();
    NoProcesados.pop();

    // Bucle for que comprueba si el estado actual esta en estadosDFA, si no esta lo agrega
    bool esta = false;
    for (const std::set<Estado>& estado : estadosDFA) {
      if (estado == estadoActual) {
        esta = true;
      }
    }
    if (!esta) {
      estadosDFA.push_back(estadoActual);
    }

    //  Bucle for que recorre los estados finales del nfa y comprueba si el estado actual es final, si lo es lo agrega a estadosFinalesDFA
    for (const Estado& estado : nfa.getEstadosFinales()) {
      for (const Estado& estadoSet : estadoActual) {
        if (estadoSet == estado) {
          estadosFinalesDFA.push_back(estadoActual);
        }
      }
    }

    // Para cada símbolo del alfabeto
    for (Simbolo simbolo : nfa.getAlfabeto().getAlfabeto()) {
      // Obtiene el estado siguiente
      std::set<Estado> estadoSiguiente = nfa.epsilonClausura(nfa.move(estadoActual, simbolo, nfa), nfa);

      // Si el estado siguiente no esta en estadosDFA, lo agrega
      bool esta = false;
      for (const std::set<Estado>& estado : estadosDFA) {
        if (estado == estadoSiguiente) {
          esta = true;
        }
      }
      if (!esta) {
        estadosDFA.push_back(estadoSiguiente);
      }

      // Agrega la transición al DFA
      TrancisionesDFA trancisionesDFA(estadoActual, simbolo, estadoSiguiente);
      dfa.addTrancision(trancisionesDFA);

      // Si el estado siguiente no esta en la cola de NoProcesados, lo agrega
      bool esta2 = false;
      for (const std::set<Estado>& estado : estadosDFA) {
        if (estado == estadoSiguiente) {
          esta2 = true;
        }
      }
      if (!esta2) {
        NoProcesados.push(estadoSiguiente);
      }
    }
  }


  dfa.setEstados(estadosDFA);
  dfa.setEstadosFinales(estadosFinalesDFA);
  dfa.setNumEstados(estadosDFA.size());

  return dfa;
}