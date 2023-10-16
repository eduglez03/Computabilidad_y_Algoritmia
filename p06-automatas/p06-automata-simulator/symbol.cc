/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 6
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 29 Sep 2022
 * @brief Archivo: symbol.cc
 *        Implementación de la clase símbolo
 * 
 * @details 
 *    29/09/2022 - Creación del fichero
 *    30/09/2022 - Implementación de la sobrecarga de salida
 *    08/10/2022 - Revisiones
 *    09/10/2022 - Añadidas sobrecargas
 */

#include <iostream>
#include "symbol.h"

/** 
 *  @brief Sobrecarga del operador <<
 *  @param[out] out
 *  @param[in] symbol
 */
std::ostream& operator<<(std::ostream& out, const Symbol& symbol) {
  out << symbol.getSymbol();
  return out;
}

/** 
 *  @brief Sobrecarga del operador ==
 *  @param[in] symbol1
 *  @param[in] symbol2
 */
bool operator==(const Symbol& symbol1, const Symbol& symbol2) {
  return symbol1.getSymbol() == symbol2.getSymbol();
}

/** 
 *  @brief Sobrecarga del operador !=
 *  @param[in] symbol1
 *  @param[in] symbol2
 */
bool operator!=(const Symbol& symbol1, const Symbol& symbol2) {
  return symbol1.getSymbol() != symbol2.getSymbol();
}

/** 
 *  @brief Sobrecarga del operador <
 *  @param[in] symbol1
 *  @param[in] symbol2
 */
bool operator<(const Symbol& symbol1, const Symbol& symbol2) {
  return symbol1.getSymbol() < symbol2.getSymbol();
}