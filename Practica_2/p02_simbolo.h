// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnologíıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con Cadenas
// Autor: Eduardo González Gutiérrez
// Correo: alu0101461588@ull.edu.es
// Fecha: 27/09/2023
// Archivo cya-P02_simbolo.h: archivo de cabecera
// Contiene la declaracion de la clase Simbolo
// Referencias:
// Enlaces de interés

// Historial de revisiones
// 12/09/2023 - Creación (primera versión) del código

#include<iostream>

/**
 * @brief Declaracion de clase Simbolo
 * 
 */
class Simbolo {
  public:
    Simbolo(char); // Constructor de la clase
    
    char get_simbolo(); // Getter simbolo

    bool operator<(const Simbolo&) const; // Sobrecarga operador "menor que" para usarlo en el set

  private:
    char simbolo_;
};