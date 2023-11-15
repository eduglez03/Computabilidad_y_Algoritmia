// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnologíıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 9: Maquina de Turing
// Autor: Eduardo González Gutiérrez
// Correo: alu0101461588@ull.edu.es
// Fecha: 15/11/2023
// Archivo tupla.h: Clase que representa una tupla de una máquina de Turing

#include <iostream>

#include "simbolo.h"

/**
 * @brief Clase que representa una tupla de una máquina de Turing
 * 
 */
class Tupla {
  private:
    int estado_; // Identificador del estado
    Simbolo entrada_; // Caracter de entrada
    Simbolo escribe_; // Caracter que se escribe
    char movimiento_; // Movimiento de la cinta
    int sig_estado_; // Identificador del siguiente estado

  public:
    Tupla() {}; // Constructor por defecto
    Tupla(int estado, Simbolo entrada, Simbolo escribe, char movimiento, int sig_estado); // Constructor parametrizado
    ~Tupla() {}; // Destructor

    // Getters
    int get_identificador() const {return estado_;}; // Devuelve el identificador del estado
    Simbolo get_entrada() const {return entrada_;}; // Devuelve el caracter de entrada
    Simbolo get_escribe() const {return escribe_;}; // Devuelve el caracter que se escribe
    char get_movimiento() const {return movimiento_;}; // Devuelve el movimiento de la cinta
    int get_sig_estado() const {return sig_estado_;}; // Devuelve el identificador del siguiente estado
  
    // Setters
    void set_identificador(int estado) {estado_ = estado;}; // Asigna el identificador del estado
    void set_entrada(Simbolo entrada) {entrada_ = entrada;}; // Asigna el caracter de entrada
    void set_escribe(Simbolo escribe) {escribe_ = escribe;}; // Asigna el caracter que se escribe
    void set_movimiento(char movimiento) {movimiento_ = movimiento;}; // Asigna el movimiento de la cinta
    void set_sig_estado(int sig_estado) {sig_estado_ = sig_estado;}; // Asigna el identificador del siguiente estado

    // Sobrecarga del operador de salida
    friend std::ostream& operator<<(std::ostream& os, const Tupla& t);
};