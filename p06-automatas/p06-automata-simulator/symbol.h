/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 6
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 29 Sep 2022
 * @brief Archivo: symbol.h
 *        Definición de la clase símbolo
 * 
 * @details 
 *    29/09/2022 - Creación del fichero
 *    30/09/2022 - Atributo y constructores
 *    01/10/2022 - Getter y setter
 *    08/10/2022 - Revisiones
 *    09/10/2022 - Añadidas sobrecargas
 */

#ifndef SYMBOL_H
#define SYMBOL_H

#include <iostream>
#include <string>

class Symbol {
 private:
  std::string symbol_;

 public:
  /// Constructores
  Symbol() {};
  Symbol(const std::string& symbol) { symbol_ = symbol; };
  Symbol(const char symbol) { symbol_ = symbol; };
  
  /// Getters
  std::string getSymbol() const { return symbol_; };
  int getLength() const { return symbol_.length(); };
  /// Setter
  void setSymbol(std::string& symbol) { symbol_ = symbol; };

  /// Sobrecargas
  friend std::ostream& operator<<(std::ostream& out, const Symbol& symbol);
  friend bool operator==(const Symbol& symbol1, const Symbol& symbol2);
  friend bool operator!=(const Symbol& symbol1, const Symbol& symbol2);
  friend bool operator<(const Symbol& symbol1, const Symbol& symbol2);
};

#endif