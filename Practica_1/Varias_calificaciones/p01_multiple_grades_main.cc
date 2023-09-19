// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnologíıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: Eduardo González Gutiérrez
// Correo: alu0101461588@ull.edu.es
// Fecha: 18/09/2023
// Archivo cya-P01-multiple-grades_main.cc: programa cliente.
// Contiene la función main del proyecto que usa la clase StudentMap
// para ordenar, clasificar y mostrar las notas de los diferentes alumnos de una determinada asignatura
// Referencias:
// Enlaces de interés

// Historial de revisiones
// 12/09/2023 - Creación (primera versión) del código

#pragma once

#include<iostream>

#include "p01_multiple_grades.cc"

/**
 * @brief Help Function that print the information about how to use the program
 * 
 */
void help() {
  std::cout << "Este es un programa que muestra por pantalla los identificadores del alumnado así como sus diversas calificaciones en la asignatura "  << std::endl;          
  std::cout << "El programa debe recibir como parámetro el archivo de texto donde se almacenen los nombres y calificaciones en formato txt" << std::endl;
}

/**
 * @brief Main Function
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Modo de empleo: " << argv[0] << " <nombre_del_archivo>" << std::endl;
    std::cout << "Pruebe: " << argv[0] << " --help para mas información" << std::endl; 
    return 1; // Código de error
  }
  else if (std::string (argv[1]) == "--help") {
    help();
    return 0;
  }

  StudentMap map;
  const char* filename = argv[1];

  map.CreateMap(filename); // Llamada a funcion para crear mapa
  map.PrintMap(); // Llamada a funcion para imprimir mapa

  std::string option;
  std::cout << "¿Desea agregar un nuevo alumno? (S/N): ";
  std::cin >> option;

  if (option == "S" || option == "s") {
    std::string newName;
    double newMark;

    std::cout << "Ingrese el nombre del nuevo alumno: ";
    std::cin >> newName;
    std::cout << "Ingrese la calificación del nuevo alumno: ";
    std::cin >> newMark;

    map.AddStudent(newName, newMark, filename);
    map.PrintMap();
  }

  return 0;
}