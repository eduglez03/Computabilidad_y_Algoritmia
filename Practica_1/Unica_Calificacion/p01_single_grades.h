// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnologíıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: Eduardo González Gutiérrez
// Correo: alu0101461588@ull.edu.es
// Fecha: 18/09/2023
// Archivo cya-P01-single-grades.h: Declaracion de la clase
// Contiene la declararcion de la clase StudentMap que permite
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


/**
 * @brief Declaration of the StudentMap Class
 * 
 */
class StudentMap {
  public:
    // Constructor por defecto
    StudentMap() {}

    void CreateMap(const char*);
    void AddStudent(const std::string&, double, const std::string&);
    void PrintMap() const;

  private:
    std::map<std::string, double> students;
};