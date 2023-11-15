// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnologíıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 9: Maquina de Turing
// Autor: Eduardo González Gutiérrez
// Correo: alu0101461588@ull.edu.es
// Fecha: 15/11/2023
// Archivo main_tools.cc: Funciones auxiliares para el programa cliente


#include <iostream>
#include <string>
#include <fstream>
#include <sstream> // stringstream

const std::string kHelpText = "Modo de empleo: ./p09_MT input.tm input.tape \n\
Pruebe 'p09_MT --help' para mas informacion. \n\
      (input.tm) \n\
          Maquina de Turing definida de la siguiente forma: \n\
              Linea 1: Entero indicando el número de estados de la máquina. \n\
              Linea 2: Entero indicando el estado de arranque. \n\
              Linea 3: Enteros separados por espacios que indican que estados son de aceptación. \n\
              Linea 4: Entero indicando el número de tuplas \n\
              El resto de lineas contendran los detalles de cada tupla. \n\
      (input.tape) \n\
          Cadenas para probar la Maquina de Turing";


// Funcion Usage que muestra el modo de uso correcto del programa
void Usage(int argc, char *argv[]) {
  if (argc > 3) {
    std::cout << argv[0] << ": Ha introducido mas de 2 parametros." << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para mas informacion." << std::endl;
    exit(EXIT_SUCCESS);
  }
  std::string parameter{argv[1]};
  if (parameter == "--help") {
    std::cout << kHelpText << std::endl;
    exit(EXIT_SUCCESS);
  }
  if (argc != 3) {
    std::cout << argv[0] << ": Faltan parametros." << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para mas informacion." << std::endl;
    exit(EXIT_SUCCESS);
  }
}

// Mensaje de error para cuando no se usan parámetros
void Error(std::string argv0) {
  std::cout << "No se han introducido parametros." << std::endl;
  std::cout << "Pruebe " << argv0 << " --help para mas informacion." << std::endl;
  exit(EXIT_SUCCESS);
}