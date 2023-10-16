#include <iostream>
#include <string>
#include <fstream>
#include <sstream> // stringstream

#include "NFA.h"


// Erroro en el formato de entrada del NFA
void error_formato() {
  std::cout << "El fichero de especificacion no tiene el formato correcto." << std::endl;
  std::cout << "Use la opcion --help para mas informacion." << std::endl;
  exit(EXIT_SUCCESS);
}

// Metodo que cuenta las lineas del fichero de entrada del NFA
int ContarLineas(std::string& fichero) {
  std::ifstream fichero_entrada{fichero, std::ios_base::in};
  std::string linea;
  int numero_lineas = 0;
  while (getline(fichero_entrada, linea)) {
    ++numero_lineas;
  }
  return numero_lineas;
}

// Funcion que genera un alfabeto
Alfabeto ObtenerAlfabeto(std::string& linea) {
  Alfabeto alfabeto;
  for (const auto& simbolo : linea) {
    if (simbolo != ' ') alfabeto.add(simbolo);
  }
  return alfabeto;
}

// Funcion que genera las transiciones
void GenerarTransiciones(std::string& linea, std::vector<Transicion>& transiciones) {
  std::string elemento;
  std::stringstream nueva_linea(linea);

  // Obtenemos el identificador del estado
  getline(nueva_linea, elemento, ' ');
  unsigned int identificador = stoi(elemento);

  getline(nueva_linea, elemento, ' '); // No necesitamos saber si es de aceptacion o no, por lo que lo leemos y lo descartamos
  

  // Extraemos el numero de transiciones
  getline(nueva_linea, elemento, ' ');
  unsigned int num_transiciones = stoi(elemento);

  for (int i = 0; i < int(num_transiciones); ++i) {
    // Creamos el simbolo de la transicion
    getline(nueva_linea, elemento, ' ');
    Simbolo simbolo = elemento; 

    // Estado de origen 
    getline(nueva_linea, elemento, ' ');
    Transicion transicion(simbolo, identificador, stoi(elemento));
    transiciones.push_back(transicion);
  }
}

// Funcion que genera los estados
Estado GeneraEstados(std::string& linea) {
  Estado estado;
  std::string elemento;
  std::stringstream nueva_linea(linea);

  //Obtenemos el ID del estado
  getline(nueva_linea, elemento, ' ');
  estado.set_identificador(stoi(elemento));

  // Obtenemos si es o no de aceptacion
  getline(nueva_linea, elemento, ' ');
  estado.set_aceptacion(stoi(elemento) == 1);
  return estado;
}

// Funcion que crea un NFA
NFA CrearNFA(std::string& fichero_entrada) {
  std::ifstream fichero{fichero_entrada, std::ios_base::in};
  std::string linea;

  // Comprobamos que el fichero cuenta con al menos las dos lineas obligatorias
  int numero_lineas = ContarLineas(fichero_entrada);
  if (numero_lineas < 2) error_formato();

  // Obtenemos el alfabeto
  getline(fichero, linea);
  Alfabeto alfabeto(ObtenerAlfabeto(linea));

  // Extraemos el numero de estados
  getline(fichero, linea);
  int total_estados = stoi(linea);

  // Comprobamos que si tiene al menos un estado, estan definidos
  if (numero_lineas != total_estados + 3) {
    error_formato();
  }

  // Obtenemos el estado inicial
  getline(fichero, linea);
  int estado_inicial = stoi(linea);
  Estado Inicial;

  // Obtenemos los estados y las transiciones
  std::set<Estado> estados;
  std::set<Estado> aceptacion;
  std::vector<Transicion> transiciones;
  
  while(getline(fichero, linea)) {
    Estado estado(GeneraEstados(linea));
    GenerarTransiciones(linea, transiciones);
    estados.insert(estado);
    if(estado.get_aceptacion() == true) {
      aceptacion.insert(estado);
    }
    if(int(estado.get_identificador()) == estado_inicial) {
      Inicial = estado;
    }
  }

  // Creamos el NFA
  NFA nfa;
  nfa.set_Alfabeto(alfabeto);
  nfa.set_Estados(estados);
  nfa.set_numEstados(total_estados);
  nfa.set_estadoInicial(Inicial);
  nfa.set_estadosFinales(aceptacion);
  nfa.set_transiciones(transiciones);
  return nfa;
}

// Funcion que imprime si una cadena es o no aceptada por el NFA
void ComprobarCadena(std::string& nombre_fichero, NFA& nfa) {
  std::ifstream fichero{nombre_fichero, std::ios_base::in};
  std::string linea;
  while(getline(fichero, linea)) {
    std::cout << linea << " --- ";
    if(nfa.aceptacion(linea) == true) {
      std::cout << "Aceptada" << std::endl;
    } else {
      std::cout << "Rechazada" << std::endl;
    }
  }
}