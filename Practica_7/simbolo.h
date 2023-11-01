// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnologíıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 7: Forma Normal de Chomsky
// Autor: Eduardo González Gutiérrez
// Correo: alu0101461588@ull.edu.es
// Fecha: 02/11/2023
// Archivo simbolo.h: Definicion clase Simbolo

#ifndef SYMBOL_H
#define SYMBOL_H

#include <iostream>
#include <string>

// Clase Simbolo
class Simbolo {
  public:
    Simbolo() {}; // Constructor por defecto
    Simbolo(const std::string& simbolo) { simbolo_ = simbolo; }; // Constructor por parametros
    Simbolo(const char simbolo) { simbolo_ = simbolo; }; // Constructor por parametros
  
    std::string getSimbolo() const { return simbolo_; }; // Getter simbolo
    char getChar() const { return simbolo_[0]; }; // Getter char
    int getLength() const { return simbolo_.length(); }; // Getter longitud

    void setSimbolo(std::string& simbolo) { simbolo_ = simbolo; }; // Setter simbolo

    friend std::ostream& operator<<(std::ostream& out, const Simbolo& simbolol); // Sobrecarga del operador de salida
    friend bool operator==(const Simbolo& simbolo1, const Simbolo& simbolo2); // Sobrecarga operador ==
    friend bool operator!=(const Simbolo& simbolo1, const Simbolo& simbolo2); // Sobrecarga operador !=
    friend bool operator<(const Simbolo& simbolo1, const Simbolo& simbolo2); // Sobrecarga operador <

  private:
    std::string simbolo_;
};

#endif