// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnologíıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: Eduardo González Gutiérrez
// Correo: alu0101461588@ull.edu.es
// Fecha: 18/09/2023
// Archivo cya-P01-multiple-grades.cc: Metodos de la clase.
// Contiene los métodos del proyecto que usa la clase StudentMap
// para ordenar, clasificar y mostrar las notas de los diferentes alumnos de una determinada asignatura
// Referencias:
// Enlaces de interés

// Historial de revisiones
// 12/09/2023 - Creación (primera versión) del código

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <vector>

#include "p01_multiple_grades.h"

/**
 * @brief Method that print a Map
 * 
 */
void StudentMap::PrintMap() {
  for (const auto& par : students) {
    std::cout << par.first << ": ";
        
    for (const double& value : par.second) {
      std::cout << value << " ";
    }   
    std::cout << std::endl;
  }
}


/**
 * @brief Method that create a map with the students name as key, and their marks as value 
 * 
 * @param input_file 
 */
void StudentMap::CreateMap(const char* input_file) {
  
  std::ifstream file(input_file);

  if (!file.is_open()) {
    std::cerr << "Error: no se pudo abrir el archivo " << std::endl;
    return; // Código de error
  }

  std::string studentName;
  double mark;

  while (file >> studentName >> mark) {
    // Verificar si el nombre del alumno ya existe en el mapa
    if (students.find(studentName) == students.end()) {
      // Si no existe, creamos un nuevo vector de notas
      std::vector<double> marks;
      marks.push_back(mark);
      students[studentName] = marks;
    } else {
        // Si el nombre ya existe, agregamos la nota al vector existente
        students[studentName].push_back(mark);
      }
    }

  file.close();
}


/**
 * @brief Method for add a new student to the map and to the inputfile
 * 
 * @param name 
 * @param mark 
 * @param file 
 */
void StudentMap::AddStudent(std::string name, double mark, const char* file) {

  // Verificar si el nombre del alumno ya existe en el mapa
  if (students.find(name) == students.end()) {
    // Si no existe, creamos un nuevo vector de notas
    std::vector<double> marks;
    marks.push_back(mark);
    students[name] = marks;
  } else {
      // Si el nombre ya existe, agregamos la nota al vector existente
      students[name].push_back(mark);
  }

  std::ofstream archivo(file, std::ios::app);
  if (archivo.is_open()) {
    archivo << std::endl;
    archivo << name << " " << mark << std::endl;
    archivo.close();
  } else {
      std::cerr << "Error: no se pudo abrir el archivo para agregar el nuevo alumno." << std::endl;
  }
}