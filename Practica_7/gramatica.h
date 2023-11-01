// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnologíıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 7: Forma Normal de Chomsky
// Autor: Eduardo González Gutiérrez
// Correo: alu0101461588@ull.edu.es
// Fecha: 02/11/2023
// Archivo gramatica.h: Definicion clase Gramatica

#ifndef Gramatica_H
#define Gramatica_H

#include <utility>
#include <iostream>
#include <fstream>
#include <utility>
#include <sstream>
#include <string>
#include <vector>
#include <set>

#include "alfabeto.cc"
#include "simbolo.cc"

typedef std::pair<Simbolo, std::vector<Simbolo>> pair;
typedef std::set<std::pair<Simbolo, std::vector<Simbolo>>> set_pair;

// Clase Gramatica
class Gramatica {
  public:
    Gramatica() {}; // Constructor por defecto
    Gramatica(const Gramatica& Gramatica); // Constructor de copia
    Gramatica(const std::string& fichero); // Constructor por parametros

    void setNoTerminales(const Alfabeto& Simbolos) { noTerminales_ = Simbolos; }; // Setter no terminales
    void setTerminales(const Alfabeto& Alfabeto) { terminales_ = Alfabeto; }; // Setter terminales
    void setInicial(const Simbolo inicial) { inicial_ = inicial; }; // Setter inicial
    void setProducciones(const set_pair& producciones) { producciones_ = producciones; }; // Setter producciones

    Alfabeto getNoTerminales() const { return noTerminales_; }; // Getter no terminales
    Alfabeto getTerminales() const { return terminales_; }; // Getter terminales
    Simbolo getInicial() const { return inicial_; }; // Getter inicial
    set_pair getProducciones() const { return producciones_; }; // Getter producciones

    void write(const std::string& kFicheroSalida); // Metodo que escribe la gramatica en un fichero
    Gramatica ConvertirToCNF(); // Metodo que convierte una gramatica a CNF
    void Comprobar(); // Metodo que comprueba formato de una gramatica

  private:
    Alfabeto noTerminales_;
    Alfabeto terminales_;
    Simbolo inicial_;
    set_pair producciones_;
};

#endif