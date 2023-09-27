// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnologíıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con Cadenas
// Autor: Eduardo González Gutiérrez
// Correo: alu0101461588@ull.edu.es
// Fecha: 27/09/2023
// Archivo cya-P02_alfabeto.h: archivo de cabecera
// Contiene la declaracion de la clase Alfabeto
// Referencias:
// Enlaces de interés

// Historial de revisiones
// 12/09/2023 - Creación (primera versión) del código

#include<iostream>
#include<vector>
#include<set>

#include "p02_cadena.h"
#include "p02_simbolo.h"

/**
 * @brief Clase Alfabeto
 * 
 */
class Alfabeto{
  public:
    // Constructor por defecto
    Alfabeto() {};

    // Declaracion del metodo que crea un alfabeto
    std::vector<Simbolo> CrearAlfabeto(Cadena); 

  private:
    std::vector<char> Alfabeto_;
};