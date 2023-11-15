// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnologíıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 9: Maquina de Turing
// Autor: Eduardo González Gutiérrez
// Correo: alu0101461588@ull.edu.es
// Fecha: 15/11/2023
// Archivo MaquinaTuring.h: Clase que representa una máquina de Turing

#pragma once

#include <set>
#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>

#include "tupla.h"


/**
 * @brief Clase que representa una máquina de Turing.
 * 
 */
class MaquinaTuring{
  private:
    int numEstados_; // Entero que indica el número de estados
    int EstadoArranque_; // Entero que indica el estado de arranque
    int EstadoAceptacion_; // Estado de aceptación
    int numTuplas_; // Entero indicando el número de t-uplas que componen la máquina
    std::vector<Tupla> Tuplas_; // T-uplas de cada estado
    std::string Cinta_; // Cadena de caracteres que representa la cinta

  public:
    MaquinaTuring(char nombrefichero1 [], char nombrefichero2 [], bool& error); // Constructor parametrizado
    ~MaquinaTuring() {}; // Destructor

    void MostrarMaquinaTuring(); // Muestra la máquina de turing
    bool SimularMT(); // Simula la máquina de turing

    void MostrarRecorrido(std::string& temporal, unsigned posicion, int estado_actual); // Muestra el recorrido de la máquina de turing
    int BuscarTransicion(char entrada, int id); // Busca una transicion determinada
};