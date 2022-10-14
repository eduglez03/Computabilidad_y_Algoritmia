// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Inforḿatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pŕactica 2: Símbolos, alfabetos y cadenas
// Autor: Eduardo González Gutiérrez
// Correo: alu01014615888@ull.es
// Fecha: 03/10/2022
// Archivo cya-P02-Strings.cc: programa cliente.
//         Contiene la función main del proyecto que usa las clases X e Y
//         que realizan el trabajo de leer el fichero de entrada
//         identificando patrones en el texto que dan lugar
//         al fichero de salida.


#include <iostream>
#include <vector>

#include "cadena.h"

// Calcula la longitud de la cadena
int Cadena::Longitud(std::vector<std::string> alfabeto) {
  std::string cadena_auxiliar{""};
  int size{0};
  if (cadena_ == "&") {  // Se comprueba la cadena vacía
    return 0;
  }
  // Se pasa cada caracter a una cadena_auxiliar
  for (size_t i = 0; i < cadena_.length(); ++i) {
    cadena_auxiliar += cadena_.at(i);
    // En caso de que coincida con un alfabeto, se le suma uno al size
    for (size_t j = 0; j < alfabeto.size(); ++j) {
      if (cadena_auxiliar == alfabeto[j]) {
        ++size;
        cadena_auxiliar.erase();
      }
    }
  }
  return size;
}

// Calcula la inversa de la cadena
std::string Cadena::Inversa(std::vector<std::string> alfabetos) {
  std::string inversa_final{""};
  std::string inversa_cadena{""};
  std::string inversa{""};
  std::vector<std::string> inversa_alfabetos;
  if (cadena_ == "&") {
    return "";
  }
  // Se invierten los alfabetos
  for (size_t j = 0; j < alfabetos.size(); j++) {
    for (size_t i = alfabetos[j].length() - 1; i > 0; i--) {
      inversa += alfabetos[j].at(i);
    }
    inversa += alfabetos[j].at(0);
    inversa_alfabetos.push_back(inversa);
    inversa.erase();
  }

  // Se recorre la cadena de detrás para delante y se compara con los alfabetos
  // invertidos
  for (size_t i = cadena_.length() - 1; i > 0; i--) {
    inversa_cadena += cadena_.at(i);
    for (size_t j = 0; j < alfabetos.size(); j++) {
      std::string alfabeto_invertido{inversa_alfabetos[j]};
      // En caso de que haya coincidencia, se le añade a una cadena el
      // simbolo(original) con el que coincide
      if (inversa_cadena == alfabeto_invertido) {
        inversa_final += alfabetos[j];
        inversa_cadena = "";
      }
    }
  }
  // Se hace la comparación hasta el elemento 0 del vector;
  inversa_cadena += cadena_.at(0);
  for (size_t j = 0; j < alfabetos.size(); j++) {
    if (inversa_cadena == inversa_alfabetos[j]) {
      inversa_final += alfabetos[j];
    }
  }
  return inversa_final;
}

// Calcula los prefijos de la cadena
std::string Cadena::Prefijos(std::vector<std::string> alfabetos) {
  std::string prefijos{""};
  std::string prefijos_final{"& "};
  std::string complemento{""};
  if (cadena_ == "&") {
    return "&";
  }
  // Se pasa cada caracter a una nueva cadena
  for (size_t i = 0; i < cadena_.length(); i++) {
    prefijos += cadena_.at(i);
    for (size_t j = 0; j < alfabetos.size(); j++) {
      // En caso de que coincida la cadena nueva con los alfabetos, se irán
      // añadiendo los prefijos a una cadena final
      if (prefijos == alfabetos[j]) {
        prefijos_final += complemento;
        prefijos_final += prefijos;
        complemento += prefijos;
        prefijos_final += " ";
        prefijos.erase();
      }
    }
  }
  return prefijos_final;
}

// Calcula los sufijos de la cadena
std::string Cadena::Sufijos(std::vector<std::string> alfabetos) {
  std::string sufijos{""};
  std::string sufijos_final{"& "};
  Cadena complemento2{""};
  std::string complemento2_string{complemento2.cadena_};
  Cadena complemento{""};
  std::string complemento_string{complemento.cadena_};
  // std::string complemento2{""};
  std::string inversa{""};
  std::vector<std::string> inversa_alfabetos;
  if (cadena_ == "&") {
    return "&";
  }
  // Se invierten los alfabetos
  for (size_t j = 0; j < alfabetos.size(); j++) {
    for (size_t i = alfabetos[j].length() - 1; i > 0; i--) {
      inversa += alfabetos[j].at(i);
    }
    inversa += alfabetos[j].at(0);
    inversa_alfabetos.push_back(inversa);
    inversa.erase();
  }
  // Se recorre la cadena de detrás para delante y se va comparando con los
  // alfabetos invertidos
  for (size_t i = cadena_.length() - 1; i > 0; i--) {
    sufijos += cadena_.at(i);
    for (size_t j = 0; j < alfabetos.size(); j++) {
      // En caso de que coincidan, se añaden los sufijos a una nueva cadena
      if (sufijos == inversa_alfabetos[j]) {
        sufijos_final += alfabetos[j];
        sufijos_final += complemento2_string;
        complemento_string += alfabetos[j];
        complemento = complemento_string;
        complemento2_string = complemento.Inversa(alfabetos);
        sufijos_final += " ";
        sufijos.erase();
      }
    }
  }
  // Se compara también el elemento 0 de la cadena
  sufijos += cadena_.at(0);
  for (size_t j = 0; j < alfabetos.size(); j++) {
    if (sufijos == inversa_alfabetos[j]) {
      sufijos_final += alfabetos[j];
      sufijos_final += complemento2_string;
      complemento_string += alfabetos[j];
      complemento = complemento_string;
      complemento2_string = complemento.Inversa(alfabetos);
      sufijos_final += " ";
      sufijos.erase();
    }
  }
  return sufijos_final;
}

// Calcula las subcadenas de la cadena
std::string Cadena::Subcadenas(std::vector<std::string> alfabetos) {
  Cadena cadena{cadena_};
  std::string complemento{""};
  std::string subcadena{""};
  std::string subcadena_final{"& "};
  std::vector<int> inicio{0};
  inicio.reserve(cadena_.length());
  int inicio_i{0};
  int contador{0};
  // Un bucle while que permite recorrer la cadena tantas veces como su longitud
  while (contador != cadena.Longitud(alfabetos)) {
    // Se recorre la cadena comenzando desde el primer alfabeto y por cada
    // iteración del while el comienxo pasa al siguiente alfabeto de la cadena
    for (size_t i = inicio[0]; i < cadena_.length(); i++) {
      subcadena += cadena_.at(i);
      for (size_t j = 0; j < alfabetos.size(); j++) {
        //  // Si coincide la nueva cadena con los alfabetos, se añaden las
        //  // subcadenas a una nueva cadena
        if (subcadena == alfabetos[j]) {
          inicio[inicio_i] = i + 1;
          subcadena_final += complemento;
          subcadena_final += subcadena;
          complemento += alfabetos[j];
          subcadena_final += " ";
          subcadena.erase();
          inicio_i++;
        }
      }
    }
    // Restauramos e iteramos el contador
    complemento.erase();
    inicio_i = 0;
    contador++;
  }
    return subcadena_final;
}



// ----------------------------------------------------- MODIFICACIÓN -----------------------------------------------------------------

int Cadena::Repeticiones(std::vector<std::string> alfabeto) {
  std::string cadena_auxiliar{""};
  int size{0};
  for (size_t i{0}; i < cadena.length(); ++i) {
    cadena_auxiliar += cadena.at(i);
    for (size_t j{0}; j < alfabeto.size(); ++j) {
      if (cadena_auxiliar == alfabeto[j]) {
        ++size;
        cadena_auxiliar.erase();
      }
    }
  }

  
  for (int i = 0; i < size; i++) {
    if (cadena[i] == cadena[i -1]) {
      if (/* condition */) {
        /* code */
      }
      



      i++;
    }
    
  }

}

size_t countOccurrences(std::string cadena, std::vector<std::string> alfabeto) {
  size_t count = 0;
  for (char i : cadena)
    if (i == c)
      count++;

  return count;
}

