// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnologíıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 7: Forma Normal de Chomsky
// Autor: Eduardo González Gutiérrez
// Correo: alu0101461588@ull.edu.es
// Fecha: 02/11/2023
// Archivo file_tools.cc: Implementacion funciones para comprobaciones fichero

#include <iostream>
#include <string>
#include <fstream>
#include <sstream> // stringstream

/** 
 *  @brief Muestra el mensaje de error de formato
 *  @return void, pero termina el programa
 */
void ErrorFormato() {
  std::cout << "El fichero de especificacion no tiene el formato correcto." << std::endl;
  std::cout << "Use la opcion --help para mas informacion." << std::endl;
  exit(EXIT_SUCCESS);
}

/** 
 *  @brief Comprueba si un fichero existe
 *  @param[in] nombre
 *  @return (void) Pero termina el programa si no existe
 */
void FicheroExiste(std::string& nombre) {
  std::ifstream input_file{nombre, std::ios_base::in};
  if (!input_file) {
    std::cout << "No se ha podido abrir el archivo: " << nombre << std::endl;
    exit(EXIT_SUCCESS);
  }
}