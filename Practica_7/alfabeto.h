// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnologíıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 7: Forma Normal de Chomsky
// Autor: Eduardo González Gutiérrez
// Correo: alu0101461588@ull.edu.es
// Fecha: 02/11/2023
// Archivo alfabeto.h: Definicion clase Alfabeto

#ifndef ALFABETO_H
#define ALFABETO_H

/// Para comprobaciones
const std::vector<char> kAlfabeto = {'S', 'A', 'B', 'C', 'D', 'E', 'F' , 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'K', 'R', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
std::vector<bool> Usado = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

#include <iostream>
#include <vector>
#include <string> 
#include <set>
#include "simbolo.h"

// Clase Alfabeto
class Alfabeto {
  public:
    Alfabeto() {}; // Constructor por defecto
    Alfabeto(std::string& string); // Constructor por parametros

    std::set<Simbolo> getAlfabeto() const { return alfabeto_; }; // Getter alfabeto
    int getSize() const { return alfabeto_.size(); }; // Getter tamaño alfabeto

    bool Encontrar(Simbolo simbolo) const; // Metodo que comprueba si un simbolo pertenece a un alfabeto
    void add(Simbolo simbolo); // Metodo que añade un simbolo al alfabeto

    friend std::ostream& operator<<(std::ostream& out, const Alfabeto& alfabeto); // Sobrecarga del operador de salida
  
  private:
    std::set<Simbolo> alfabeto_;
};

#endif