// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnologíıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 7: Forma Normal de Chomsky
// Autor: Eduardo González Gutiérrez
// Correo: alu0101461588@ull.edu.es
// Fecha: 02/11/2023
// Archivo main_tools.cc: Funciones para comprobaciones de parametros

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib> /// Exit

const std::string kHelpText = "Modo de empleo: ./Grammar2CNF input.gra output.gra \n\
Pruebe 'Grammar2CNF --help' para mas informacion. \n\
      (input.gra) \n\
          Fichero de especificacion de una gramatica: \n\
              1: Simbolos terminales (alfabeto). \n\
              2: Simbolos no terminales. \n\
              3: Simbolo de arranque. \n\
              4: Producciones. \n";
/**
 * @brief Mensaje de error en caso de que no se introduzcan parametros
 * 
 * @param argv0 
 */
void Error(std::string argv0) {
  std::cout << "No se han introducido parametros." << std::endl;
  std::cout << "Pruebe " << argv0 << " --help para mas informacion." << std::endl;
  exit(EXIT_SUCCESS);
}

/** @brief Muestra el modo de uso correcto del programa
 *         En caso de que el uso no sea el correcto finaliza la ejecución del programa.
 *  @param[in] argc Número de parámetros.
 *  @param[in] argv Vector con los parámetros.
 */
void Usage(int argc, char *argv[]) {
  if (argc > 3) {
    std::cout << argv[0] << ": Ha introducido mas de 2 parametros." << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para mas informacion." << std::endl;
    exit(EXIT_SUCCESS);
  }
  std::string parametro{argv[1]};
  if (parametro == "--help") {
    std::cout << kHelpText << std::endl;
    exit(EXIT_SUCCESS);
  }
  if (argc != 3) {
    std::cout << argv[0] << ": Faltan parametros." << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para mas informacion." << std::endl;
    exit(EXIT_SUCCESS);
  }
}

