// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnologíıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: Eduardo González Gutiérrez
// Correo: alu0101461588@ull.edu.es
// Fecha: 18/09/2023
// Archivo cya-P01-single-grades.cc: programa cliente.
// Contiene los metodos de la clase StudentMap que permite
// clasificar y mostrar las mayores notas de los diferentes alumnos de una determinada asignatura
// Referencias:
// Enlaces de interés

// Historial de revisiones
// 12/09/2023 - Creación (primera versión) del código

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

#include "p01_single_grades.h"


/**
 * @brief Method that Create a Map with the students name and their highest mark
 * 
 * @param inputfile 
 */
void StudentMap::CreateMap(const char* inputfile) {

  std::ifstream file(inputfile);

  if (!file.is_open()) {
    std::cerr << "Error: no se pudo abrir el archivo " << std::endl;
    return; // Código de error
  }

  std::string name;
  double mark;

  while (file >> name >> mark) {
    // Verificamos si el alumno ya está en el mapaS
    if (students.find(name) == students.end() || mark > students[name]) {
        students[name] = mark; // Actualizamos la nota si es mayor
    }
  }

  file.close();
}


/**
 * @brief Method for print a map
 * 
 */
void StudentMap::PrintMap() const {
  for (const auto& par : students) {
    std::cout << par.first << ": " << par.second << std::endl;
  }
}

/**
 * @brief Method for add a new student to the map with his mark
 * 
 * @param name
 * @param mark
 * @param fileName 
 */
void StudentMap::AddStudent(const std::string& name, double mark, const std::string& fileName) {
    students[name] = mark;

    std::ofstream file(fileName, std::ios::app);
    if (file.is_open()) {
        file << std::endl;
        file << name << " " << mark << std::endl;
        file.close();
    } else {
        std::cerr << "Error: no se pudo abrir el archivo para agregar el nuevo alumno." << std::endl;
    }
}