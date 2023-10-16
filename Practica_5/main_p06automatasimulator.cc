#include <iostream>
#include <string>

#include "main_tools.h"
#include "file_tools.h"

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