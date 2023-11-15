// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnologíıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 9: Maquina de Turing
// Autor: Eduardo González Gutiérrez
// Correo: alu0101461588@ull.edu.es
// Fecha: 15/11/2023
// Archivo simbolo.h: Clase que representa un símbolo

#pragma once

#include<iostream>

class Simbolo {
  private:
    char simbolo_;

  public:
    Simbolo() {}; // Constructor por defecto
    Simbolo(char simbolo) {simbolo_ = simbolo;} // Constructor con parámetros

    // Getters y Setters
    char getSimbolo() {return simbolo_;} // Devuelve el simbolo
    void setSimbolo(char simbolo) {simbolo_ = simbolo;} // Modifica el simbolo

    // Sobrecarga de operadores
    bool operator==(const Simbolo &s) const; // Sobrecarga del operador ==
    bool operator!=(const Simbolo &s) const; // Sobrecarga del operador !=
    friend std::ostream& operator<<(std::ostream &flujo, const Simbolo &s); // Sobrecarga del operador <<
};