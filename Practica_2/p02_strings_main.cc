// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnologíıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con Cadenas
// Autor: Eduardo González Gutiérrez
// Correo: alu0101461588@ull.edu.es
// Fecha: 27/09/2023
// Archivo cya-P02-strings-grades_main.cc: programa cliente.
// Contiene la función main del proyecto que usa la clase p02_alfabeto.h
// Referencias:
// Enlaces de interés

// Historial de revisiones
// 12/09/2023 - Creación (primera versión) del código

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<set>

#include "p02_alfabeto.h"

/**
 * @brief Funcion help que muestra información acerca del funcionamiento del porgrama
 * 
 */
void help() {
  std::cout << "Este es un programa que permite realizar diferentes operaciones sobre cadenas. El código que debe introducir para cada operacion es:\n\n"
            << "1. Alfabeto con el que se componen las cadenas\n"
            << "2. Longitudes de las cadenas\n"
            << "3. Inversas de las cadenas\n"
            << "4. Sufijos de las cadenas\n"
            << "5. Prefijos de las cadenas\n";        
}

/**
 * @brief Funcion main
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char* argv[]) {
  
  if (std::string (argv[1]) == "--help") {
    help();
    return 0;
  }
  else if (argc < 4 || argc > 4) {
    std::cerr << "Modo de empleo: " << argv[0] << " <nombre_del_archivo entrada>" << " <nombre_del_archivo salida>" << " <opcode>" << std::endl;
    std::cout << "Pruebe: " << argv[0] << " --help para mas información" << std::endl; 
    return 1; // Código de error
  }

  // Obtenemos el codigo de la operacion a realizar
  std::string opcode_opcion{argv[3]};
  int opcode{stoi(opcode_opcion)};

  // Comprobacion de que el opcode sea válido
  if (opcode > 5) {
    std::cerr << "Modo de empleo: " << argv[0] << " <nombre_del_archivo entrada>" << " <nombre_del_archivo salida>" << " <opcode>" << std::endl;
    std::cout << "Pruebe: " << argv[0] << " --help para mas información" << std::endl; 
    return 1; // Código de error
  }
  
  
  std::ifstream fichero_entrada(argv[1]); // Abrimos el fichero de entrada

  // Si no se puede abrir el archivo muestra un mensaje de error
  if (!fichero_entrada.is_open()) {
    std::cerr << "Error: no se pudo abrir el archivo " << std::endl;
    return 1; // Código de error
  }

  std::string linea_auxiliar;
  std::set<Cadena> cadenas; // Set para almacenar las cadenas leidas desde el fichero
  
  // Almacenamos las cadenas
  while(getline(fichero_entrada, linea_auxiliar)) {
    Cadena linea = linea_auxiliar;
    cadenas.insert(linea);
  }

  fichero_entrada.close(); // Cerramos el fichero de entrada

  std::ofstream fichero_salida(argv[2]);
  
  // Si no se puede abrir el archivo de salida, se muestra mensaje de error
  if (!fichero_salida.is_open()) {
    std::cout << "Error al abrir el archivo de salida." << std::endl;
    return 1;
  }

  // Selecctor con las diferentes opciones de operaciones 
  switch (opcode) {
    case 1: // Muestra el alfabeto con el que se compone cada cadena
      fichero_salida << "Los alfabetos con los cuales se han formado las cadenas, son respectivamente: " << std::endl;
  
      for (Cadena elemento : cadenas) {
        Alfabeto alfabeto; // Creamos objeto de la clase alfabeto
        unsigned int contador{0};
        std::vector<Simbolo> vector_simbolos = alfabeto.CrearAlfabeto(elemento); // Llamamos al metodo para crear el alfabeto
        
        fichero_salida << elemento << " -----> {"; 
        
        while (contador != (vector_simbolos.size())) {
          fichero_salida << vector_simbolos[contador].get_simbolo();

          // Si el elemento que se va a escribir en el fichero, no es el ultimo, lo separamos por una coma
          if (contador < vector_simbolos.size() - 1) {
            fichero_salida << ", ";
          } 
          contador++;
        }
        fichero_salida << "}" << std::endl;
      }
      break;
    
    case 2: // Muestra la longitud de cada cadena
      fichero_salida << "Las Longitudes de las cadenas son respectivamente: " << std::endl;
      for (Cadena elemento : cadenas) {
        fichero_salida << elemento << " -----> " << elemento.get_length() << std::endl; // Llamamos al metodo que calcula la longitud de una cadena
      }
      break;

    case 3: // Muestra la inversa de cada cadena
      fichero_salida << "Las cadenas inversas son respectivamente: " << std::endl;
      for (Cadena elemento : cadenas) {
        fichero_salida << elemento << " ----->  " << elemento.inversa() << std::endl; // Llamamos al metodo que calcula la inversa de una cadena
      }
      break;
    
    case 4: // Muestra los prefijos de cada cadena
      fichero_salida << "Los prefijos de las cadenas son respectivamnete: " << std::endl;
  
      for (Cadena elemento : cadenas) {
        unsigned int contador{0};
        
        fichero_salida << elemento << " -----> {"; 
        
        while (contador != (elemento.prefijos().size())) {
          fichero_salida << elemento.prefijos().at(contador); // Llamamos al metodo que calcula los prefijos de una cadena
          
          // Si el elemento que se va a escribir en el fichero, no es el ultimo, lo separamos por una coma
          if (contador < elemento.prefijos().size() - 1) {
            fichero_salida << ", ";
          } 
          contador++;
        }
        fichero_salida << "}" << std::endl;
      }

      break;

    case 5: // // Muestra los sufijos de cada cadena
      fichero_salida << "Los sufijos de las cadenas son respectivamnete: " << std::endl;
  
      for (Cadena elemento : cadenas) {
        unsigned int contador{0};
        
        fichero_salida << elemento << " -----> {"; 
        
        while (contador != (elemento.sufijos().size())) {
          fichero_salida << elemento.sufijos().at(contador); // Llamamos al metodo que calcula los sufijos de una cadena
          
          // Si el elemento que se va a escribir en el fichero, no es el ultimo, lo separamos por una coma
          if (contador < elemento.sufijos().size() - 2) {
            fichero_salida << ", ";
          } 
          contador++;
        }
        fichero_salida << "}" << std::endl;
      }
      break;
  }

  return 0;
}