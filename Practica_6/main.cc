#include<iostream>
#include<string>

#include "main_tools.h"
#include "file_tools.h"

int main(int argc, char* argv[]){
  // Comprobamos los parámetros
  if (argc < 3) { Error(argv[0]); }
  Usage(argc, argv);

  // Preparamos el fichero
  std::string ficheroNFA = argv[1];
  ComprobarFichero(ficheroNFA);

  // Generamos NFA y DFA
  NFA nfa(FicheroANFA(ficheroNFA));
  DFA dfa(nfa.NFAtoDFA(nfa));

  // Escribimos el fichero
  std::string ficheroDFA = argv[2];
  EscribirFichero(ficheroDFA, dfa);

  return 0;
}