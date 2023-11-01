#include <iostream>
#include <string>
#include <fstream>
#include <sstream> // stringstream

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

// Funcion que comprueba si un fichero existe
void ComprobarFichero(std::string& name_of_file) {
  std::ifstream input_file{name_of_file, std::ios_base::in};
  if (!input_file) {
    std::cout << "No se ha podido abrir el archivo: " << name_of_file << std::endl;
    exit(EXIT_SUCCESS);
  }
}