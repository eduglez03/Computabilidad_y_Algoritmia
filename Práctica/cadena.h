// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Inforḿatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pŕactica 2: S ́ımbolos, alfabetos y cadenas
// Autor: Eduardo González Gutiérrez
// Correo: alu01014615888@ull.es
// Fecha: 03/10/2022


#pragma once
#include <iostream>
#include <vector>

#include "alfabeto.h"



class Cadena {
 public:
  Cadena(std::string cadena = "") { cadena_ = cadena; }
  int Longitud(std::vector<std::string> alfabeto);
  std::string Inversa(std::vector<std::string> alfabeto);
  std::string Prefijos(std::vector<std::string> alfabeto);
  std::string Sufijos(std::vector<std::string> alfabeto);
  std::string Subcadenas(std::vector<std::string> alfabeto);

 private:
  std::string cadena_;
};