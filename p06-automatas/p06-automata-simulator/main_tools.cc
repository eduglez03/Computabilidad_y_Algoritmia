/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Sistemas Operativos
 * Parte 1: Programación de aplicaciones
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 24 Nov 2022
 * @brief Archivo: main_tools.cc
 *        Funciones para facilitar el programa principal
 * 
 * @details 
 *    29/09/2022 - Creación del fichero
 *    05/11/2022 - Adaptar a la práctica 6
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib> /// Exit

const std::string kHelpText = "Modo de empleo: ./p06_automata_simulator input.fa input.txt \n\
Pruebe 'p06_automata_simulator --help' para mas informacion. \n\
      (input.fa) \n\
          Automata finito definido de la siguiente forma: \n\
              Linea 1: Simbolos del alfabeto separados por espacios. \n\
              Linea 2: Numero total de estados del automata. \n\
              Linea 3: Estado de arranque. \n\
              El resto de lineas contendran los detalles de cada estado. \n\
      (input.txt) \n\
          Cadenas para probar en el automata.";

/// Mensaje de error para cuando no se usan parámetros
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

/** 
 *  @brief Comprueba si un fichero existe
 *  @param[in] name_of_file
 *  @return (void) Pero termina el programa si no existe
 */
void FileExist(std::string& name_of_file) {
  std::ifstream input_file{name_of_file, std::ios_base::in};
  if (!input_file) {
    std::cout << "No se ha podido abrir el archivo: " << name_of_file << std::endl;
    exit(EXIT_SUCCESS);
  }
}