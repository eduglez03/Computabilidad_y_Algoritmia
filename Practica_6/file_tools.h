#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

#include "NFA.h"


// Funcion que cuenta el numero de lineas de un fichero
int contar_lineas(std::string& fichero_entrada) {
  std::ifstream fichero{fichero_entrada, std::ios_base::in};
  std::string linea;
  int numero_lineas = 0;
  while (getline(fichero, linea)) {
    ++numero_lineas;
  }
  return numero_lineas;
}

// Funcion que genera un alfabeto a partir de una linea del fichero
Alfabeto linea_to_alfabeto(std::string& linea) {
  Alfabeto alfabeto;
  for (const auto& elem : linea) {
    Simbolo simbolo(&elem);
    if (elem != ' ') alfabeto.insertarSimbolo(simbolo);
  }
  return alfabeto;
}

// Funcion que genera un estado a partir de una linea del fichero
Estado linea_to_estado(std::string& linea) {
  Estado estado;
  std::string elemento;
  std::stringstream nueva_linea(linea);
  
  // Extraemos el identificador
  getline(nueva_linea, elemento, ' ');
  estado.set_identificador(stoi(elemento));
  
  // Extraemos si es de aceptacion
  getline(nueva_linea, elemento, ' ');
  estado.set_aceptacion(stoi(elemento) == 1);
  return estado;
}

// Funcion que crea transiciones a partir de una linea del fichero
void linea_to_transicion(std::string& linea, std::vector<Trancisiones>& transiciones) {
  std::string elem;
  std::stringstream nueva_linea(linea);
  
  // Necesitamos el id
  getline(nueva_linea, elem, ' ');
  int id = stoi(elem);

  // No necesitamos si es de aceptación o no
  getline(nueva_linea, elem, ' ');

  /// Extraemos el número de transiciones
  getline(nueva_linea, elem, ' ');
  int num = stoi(elem);
  for (int i = 0; i < int(num); ++i) {
    // Símbolo 
    getline(nueva_linea, elem, ' ');
    Simbolo simbolo = elem;
    // Estado origen 
    getline(nueva_linea, elem, ' ');
    Estado origen(id, 0);
    Estado destino(stoi(elem), 0);
    Trancisiones transition(origen, simbolo, destino);
    transiciones.push_back(transition);
  }
}

// Error en caso de que fichero de entrada no tenga el formato correcto
void error_formato() {
  std::cout << "El fichero de especificacion no tiene el formato correcto." << std::endl;
  std::cout << "Use la opcion --help para mas informacion." << std::endl;
  exit(EXIT_SUCCESS);
}

// Funcion que construye un NFA a partir de un fichero
NFA FicheroANFA(std::string& nombre_fichero) {
  std::ifstream fichero{nombre_fichero, std::ios_base::in};
  std::string linea;

  // Comprobamos que tiene al menos las 2 líneas obligatorias 
  int numero_lineas = contar_lineas(nombre_fichero);
  if (numero_lineas< 2) error_formato();

  /// Extraemos el alfabeto
  getline(fichero, linea);
  Alfabeto alfabeto(linea_to_alfabeto(linea));

  /// Extraemos el número de estados
  getline(fichero, linea);
  int numero_estados = stoi(linea);

  // Comprobamos que, si tiene al menos un estado, están definidos
  if (numero_lineas != numero_estados + 3)  error_formato();

  /// Extraemos el estado inicial
  getline(fichero, linea);
  int estado_inicial = stoi(linea);
  Estado inicial;

  /// Extraemos los estados y las transiciones
  std::set<Estado> estados;
  std::set<Estado> finales;
  std::vector<Trancisiones> transiciones;
  while (getline(fichero, linea)) {
    Estado estado(linea_to_estado(linea));
    linea_to_transicion(linea, transiciones);
    estados.insert(estado);
    if (estado.get_aceptacion()) finales.insert(estado);
    if (int(estado.get_identificador()) == estado_inicial) inicial = estado;
  }

  /// Creamos el NFA
  NFA nfa;
  nfa.setAlfabeto(alfabeto);
  nfa.setEstados(estados);
  nfa.setNumEstados(numero_estados);
  nfa.setEstadoInicial(inicial);
  nfa.setEstadosFinales(finales);
  nfa.setTrancisiones(transiciones);
  return nfa;
}


// Funcion que escribe un fichero a partir de un DFA
void EscribirFichero(std::string& nombre_fichero, DFA& dfa) {
  std::cout << "{";
  for(const auto& alfabeto : dfa.getAlfabeto().getAlfabeto()) {
    std::cout << alfabeto.getSimbolo();
  }
  std::cout << "}" << std::endl;

  std::cout << dfa.getNumEstados() << std::endl;

  for (const auto& estado : dfa.getEstadoInicial()) {
    std::cout << "Identificador estado: " << estado.get_identificador() << " Numero transiciones: " << estado.get_numeroTransiciones() << std::endl;
  }
}