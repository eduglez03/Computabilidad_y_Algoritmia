// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnologíıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: Eduardo González Gutiérrez
// Correo: alu0101461588@ull.edu.es
// Fecha: 18/09/2023
// Archivo cya-P01-multiple-grades.h: Declararción de la clase StudentMap.
// Contiene la declaración de la clase StudentMap, donde se declaran los métodos de la clase, que permiten
// ordenar, clasificar y mostrar las notas de los diferentes alumnos de una determinada asignatura
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

/**
 * @brief Class StudentMap
 * 
 */
class StudentMap {
  public:
    StudentMap() {};

    void PrintMap();
    void CreateMap(const char*);
    void AddStudent(std::string, double, const char*);

  private:
    std::map<std::string, std::vector<double>> students;
};