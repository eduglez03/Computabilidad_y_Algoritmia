#include <iostream>
#include "simbolo.h"

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