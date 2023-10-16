#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib> /// Exit

#include "programTools.cc"

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


void FileExist(std::string& name_of_file) {
  std::ifstream input_file{name_of_file, std::ios_base::in};
  if (!input_file) {
    std::cout << "No se ha podido abrir el archivo: " << name_of_file << std::endl;
    exit(EXIT_SUCCESS);
  }
}


int main(int argc, char* argv[]) {
  // Comprobamos los parámetros
  if (argc == 1) { Error(argv[0]); }
  Usage(argc, argv);

  // Comprobamos el fichero del NFA y el fichero de las cadenas
  std::string ficheroNFA = argv[1];
  FileExist(ficheroNFA);
  std::string fichero_entrada = argv[2];
  FileExist(fichero_entrada);

  // Llamamos a la funcion que genera un NFA
  NFA nfa(CrearNFA(ficheroNFA));

  // Llamamos a la funcion que comprueba si la cadena es o no aceptada
  ComprobarCadena(fichero_entrada, nfa);

  return 0;
}