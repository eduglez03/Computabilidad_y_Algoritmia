// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Inforḿatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pŕactica 2: S ́ımbolos, alfabetos y cadenas
// Autor: Eduardo González Gutiérrez
// Correo: alu01014615888@ull.es
// Fecha: 03/10/2022
// Archivo cya-P02-Strings.cc: programa cliente.
//         Contiene la función main del proyecto que usa las clases X e Y
//         que realizan el trabajo de leer el fichero de entrada
//         identificando patrones en el texto que dan lugar
//         al fichero de salida.
// Referencias:
//          Enlaces de inteŕes
//
// Historial de revisiones
//          04/10/2021 - Creacíon (primera versíon) del ćodigo

#include <fstream>
#include <iostream>
#include <vector>

#include "cadena.h"

int main(int argc, char* argv[]) {
  if (argc != 4) {
    std::cout << "Introduzca el fichero de entrada, el fichero de salida y el "
                 "opcode.";
    return 1;
  }
  std::string archivo_entrada{argv[1]};
  std::string archivo_salida{argv[2]};
  std::string opcion_string{argv[3]};
  int opcode{stoi(opcion_string)};

  std::ifstream archivo;
  archivo.open(archivo_entrada);

  // En caso de que el archivo de un error, se imprimirá por pantalla un mensaje
  // de aviso
  if (!archivo.is_open()) {
    std::cout << "Error en el archivo." << std::endl;
    return 1;
  }
  std::string line{""};
  std::vector<std::string> cadenas;

  // Cada línea del archivo leído se guarda en una posición del vector cadenas;
  while (getline(archivo, line)) {
    cadenas.push_back(line);
  }

  // Cerramos el archivo de entrada y abrimos el archivo de salida
  archivo.close();

  std::ofstream archivo2;
  archivo2.open(archivo_salida);

  // En caso de que el archivo2 de un error, se imprimirá por pantalla un
  // mensaje de aviso
  if (!archivo2.is_open()) {
    std::cout << "Error en el archivo2." << std::endl;
    return 1;
  }

  for (size_t i = 0; i < cadenas.size(); i++) {
    std::string linea_leida{""};
    linea_leida += cadenas.at(i);
    std::string cadena_leida{""};

    std::vector<std::string> alfabeto_leido;
    // Separamos las cadenas y los alfabetos y los guardamos en vectores
    for (size_t i = 0; i < linea_leida.length(); i++) {
      if (linea_leida.at(i) != ' ') {
        cadena_leida.push_back(linea_leida.at(i));
      } else {
        alfabeto_leido.push_back(cadena_leida);
        cadena_leida.erase();
      }
    }
    std::string alfabeto_vacio{""};
    alfabeto_leido.reserve(cadena_leida.length());
    if (alfabeto_leido.empty()) {
      for (size_t i = 0; i < cadena_leida.length(); i++) {
        alfabeto_vacio.push_back(cadena_leida.at(i));
        alfabeto_leido.push_back(alfabeto_vacio);
        alfabeto_vacio.erase();
      }
    }

    Alfabeto alfabeto{alfabeto_leido};
    Cadena cadena{cadena_leida};

    // Según la opción opcode se calculará la longitud, la inversa, los
    // prefijos, los sufijos o las subcadenas
    switch (opcode) {
      case 1:
        archivo2 << "Longitud: " << std::endl;
        archivo2 << cadena.Longitud(alfabeto_leido) << std::endl;
        break;
      case 2:
        archivo2 << "Inversa: " << std::endl;
        archivo2 << cadena.Inversa(alfabeto_leido) << std::endl;
        break;
      case 3:
        archivo2 << "Prefijos: " << std::endl;
        archivo2 << cadena.Prefijos(alfabeto_leido) << std::endl;
        break;
      case 4:
        archivo2 << "Sufijos: " << std::endl;
        archivo2 << cadena.Sufijos(alfabeto_leido) << std::endl;
        break;
      case 5:
        archivo2 << "Sucadenas: " << std::endl;
        archivo2 << cadena.Subcadenas(alfabeto_leido) << std::endl;
        break;
      default:
        break;
    }
  }
  archivo2.close();
  return 0;
}
