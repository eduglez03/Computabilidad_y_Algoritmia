/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 6
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 29 Sep 2022
 * @brief Archivo: main_p06automatasimulator.cc
 *        Contiene la función main del proyecto
 *        Este programa recibe por línea de comandos lo siguiente:
 *        ./p06_automata_simulator input.fa input.txt
 *        Compilación del programa: make
 * 
 * @details 
 *    29/09/2022 - Creación del fichero
 *    05/11/2022 - Adaptar a la práctica 6
 */

#include <iostream>
#include <string>

#include "main_tools.cc"
#include "file_tools.cc"

int main(int argc, char* argv[]) {
  /// Comprobamos los parámetros
  if (argc == 1) { Error(argv[0]); }
  Usage(argc, argv);
  /// Preparamos el fichero
  std::string kNFAFileName = argv[1];
  FileExist(kNFAFileName);
  std::string kStringsFileName = argv[2];
  FileExist(kStringsFileName);
  /// Llamamos al programa
  NFA nfa(FileToNFA(kNFAFileName));
  // std::cout << nfa << std::endl;
  CheckStrings(kStringsFileName, nfa);
  return 0;
}