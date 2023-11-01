// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnologíıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 7: Forma Normal de Chomsky
// Autor: Eduardo González Gutiérrez
// Correo: alu0101461588@ull.edu.es
// Fecha: 02/11/2023
// Archivo main_p07Chomsky.cc: Programa cliente

#include <iostream>
#include <string>

#include "main_tools.cc"
#include "file_tools.cc"
#include "gramatica.cc"

int main(int argc, char* argv[]) {
  // Comprobamos los parámetros
  if (argc == 1) { Error(argv[0]); }
  Usage(argc, argv);

  // Preparamos el fichero
  std::string kFicheroEntrada = argv[1];
  FicheroExiste(kFicheroEntrada);
  std::string kFicheroSalida = argv[2];
  FicheroExiste(kFicheroSalida);

  // Llamamos al programa
  Gramatica gramatica(kFicheroEntrada);
  gramatica.Comprobar();
  Gramatica gramaticaCNF = gramatica.ConvertirToCNF();
  gramaticaCNF.write(kFicheroSalida);

  return 0;
}