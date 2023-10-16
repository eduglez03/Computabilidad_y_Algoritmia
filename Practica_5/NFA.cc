#include "NFA.h"

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream& out, const NFA& nfa) {
  out << "Alfabeto: " << nfa.get_Alfabeto() << std::endl;
  out << "Num: " << nfa.get_numEstados() << std::endl;
  out << "Inicial: " << nfa.get_estadoInicial() << std::endl;
  out << "Estados: " << std::endl;
  for (const auto& elem : nfa.get_Estados()) out << elem << std::endl;
  out << "Finales: " << std::endl;
  for (const auto& elem : nfa.get_estadosFinales()) out << elem << std::endl;
  out << "Transiciones: " << std::endl;
  for (const auto& elem : nfa.get_transiciones()) out << elem << std::endl;
  return out;
}

// Funcion que encuentra un estado con un identificador concreto
Estado NFA::encontrarEstado(unsigned int identificador) {
  Estado estado;
  for(const auto& elemento : estados_) {
    if (elemento.get_identificador() == identificador) {
      estado = elemento;
    }
  }
  return estado;
}

// Metodo que calcula las e-clausuras de un conjunto de estados
void NFA::epsilonTransiciones(std::vector<Estado>& estados) {
  bool flag = true;
  std::vector<Estado> copia = estados;

  while(flag == true) {
    flag = false;
    std::vector<Estado> estado_siguiente;

    // Recorremos el vector de estados
    for (const auto& elemento : estados)  {
      for (const auto& transicion : transiciones_) {
        if (transicion.get_estadoActual() == elemento.get_identificador()) {
          if (transicion.get_simbolo() == '&') {
            estado_siguiente.push_back(encontrarEstado(transicion.get_estadoSiguiente()));
            copia.push_back(encontrarEstado(transicion.get_estadoSiguiente()));
            flag = true;
          }
        }
      }
    }
    estados = estado_siguiente;
  }
  estados = copia;
}

// Funcion que comprueba si una cadena es o no aceptada por el NFA
bool NFA::aceptacion(const Cadena& cadena_pasada) {
  std::string cadena = cadena_pasada.get_cadena(); // Obtenemos la cadena como string para trabajar mas facil
  
  // Comprobamos la cadena vacia
  if(cadena == "&") {
    return inicial_.get_aceptacion();
  }

  std::vector<Estado> estados;
  estados.push_back(get_estadoInicial()); // El vector de estados recooridos en el NFA solo tiene de meomento el estado inical

  // Recorremos la cadena
  for (const auto& elemento : cadena) {
    std::vector<Estado> nuevos_estados;
    Simbolo simbolo = elemento;

    // Buscamos las e-transiciones
    epsilonTransiciones(estados);

    // Recorremos los estados del vector
    for (const auto& estado : estados) {
      // Buscamos las transiciones del estado
      for (const auto& transicion : transiciones_) {
        if (transicion.get_estadoActual() == estado.get_identificador()) {
          if (transicion.get_simbolo() == simbolo) {
            Estado nuevo_estado = encontrarEstado(transicion.get_estadoSiguiente());
            nuevos_estados.push_back(nuevo_estado);
          }
        }
      }

    }
    estados = nuevos_estados;
  }

  // Compprobamos si los estados son de aceptacion
  for (const auto& elemento : estados) {
    if (elemento.get_aceptacion()) {
      return true;
    }
  }
  return false;
}