// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnologíıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 9: Maquina de Turing
// Autor: Eduardo González Gutiérrez
// Correo: alu0101461588@ull.edu.es
// Fecha: 15/11/2023
// Archivo tupla.cc: Implementación de la clase Tupla

#include "tupla.h"
#include "simbolo.h"

/**
 * @brief Construct a new tupla t::tupla t object
 * 
 * @param estado 
 * @param entrada 
 * @param escribe 
 * @param movimiento 
 * @param sig_estado 
 */
Tupla::Tupla(int estado, Simbolo entrada, Simbolo escribe, char movimiento, int sig_estado){
  estado_ = estado;
  entrada_ = entrada;
  escribe_ = escribe;
  movimiento_ = movimiento;
  sig_estado_ = sig_estado;
}

/**
 * @brief Sobrecarga del operador de salida
 * 
 * @param os 
 * @param t 
 * @return ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Tupla& t){
  os << t.estado_ << " " << t.entrada_ << " " << t.escribe_ << " " << t.movimiento_ << " " << t.sig_estado_;
  return os;
}
