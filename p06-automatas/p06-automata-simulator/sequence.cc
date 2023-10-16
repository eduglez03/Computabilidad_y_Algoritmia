/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 1
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 29 Sep 2022
 * @brief Archivo: sequence.cc
 *        Implementación de la clase cadena
 * 
 * @details 
 *    01/10/2022 - Creación del fichero
 *    01/10/2022 - Constructor
 *    02/10/2022 - Constructor
 *    02/10/2022 - Funciones
 */

#include <iostream>
#include <string>
#include <cstdlib> /// Exit
#include "sequence.h"
#include "alphabet.cc"

const char EMPTY = '&';
const std::string EMPTY_STR = "&";
const std::string MARKS = "'";
const std::string SPACE_STR = " ";

/// Constructor
Sequence::Sequence(std::string& string) {
  /// Primero, contamos la cantidad de espacios de la línea
  int spaces = 0;
  for (const auto& elem : string) {
    if (elem == SPACE) ++spaces;
  }
  /// Si hay más de un espacio, tenemos cadena y alfabeto
  std::string sequence_string;
  if (spaces > 0) {
    /// Lo último es la cadena
    int last_space = string.find_last_of(SPACE);
    int length = string.length();
    for (int i = last_space + 1; i < length; ++i) {
      sequence_string += string[i];
    }
    /// El resto es el alfabeto
    std::string aux_string;
    for (int i = 0; i <= last_space; ++i) {
      if (string[i] == SPACE) {
        alphabet_.add(aux_string);
        aux_string.erase();
      } else aux_string += string[i];
    }
  } else { 
    /// Si no, solo tenemos cadena
    sequence_string = string;
    alphabet_ = string;
  }
  /// Por último, separamos y comprobamos que pertenece al alfabeto dado
  string_ = sequence_string;
  std::string aux_string;
  for (const auto& elem : sequence_string) {
    aux_string += elem;
    if (alphabet_.find(aux_string)) {
      sequence_.push_back(aux_string);
      aux_string.erase();
    }
  }
  if (aux_string != "") {
    std::cout << "Cadena incorrecta. Revise el fichero de entrada." << std::endl;
    exit(EXIT_SUCCESS); 
  }
}

/// Getter de la cadena
std::string Sequence::getSequence() const {
  std::string sequence = MARKS;
  for (const auto& symbol : sequence_) {
    sequence += SPACE + symbol.getSymbol();
  }
  sequence += SPACE + MARKS;
  return sequence;
}

/** 
 *  @brief Calcula cuantos símbolos tiene una cadena
 *  @return Número de símbolos
 */
int Sequence::length() { 
  return sequence_.size();
}

/** 
 *  @brief Calcula la cadena al revés
 *  @return String con la cadena al revés
 */
std::string Sequence::reverse() {
  std::string reverse_string;
  for (const auto& elem : sequence_) {
    reverse_string = elem.getSymbol() + reverse_string;
  }
  return reverse_string;
}

/** 
 *  @brief Calcula los prefijos de una cadena
 *  @return String con los prefijos separados
 */
std::string Sequence::prefixes() {
  std::string aux_string, prefixes{EMPTY};
  for (const auto& elem : sequence_) {
    aux_string += elem.getSymbol();
    prefixes += SPACE + aux_string;
  }
  return prefixes;
}

/** 
 *  @brief Calcula los sufijos de una cadena
 *  @return String con los sufijos separados
 */
std::string Sequence::suffixes() {
  std::string aux_string, suffixes{EMPTY};
  for (int i = sequence_.size() - 1;  i >= 0 ; --i) {
    aux_string = sequence_[i].getSymbol() + aux_string;
    suffixes += SPACE + aux_string;
  }
  return suffixes;
}

/** 
 *  @brief Comprueba si un string pertenece al vector
 *  @return True si pertenece
 */
bool find(std::vector<std::string> vector, std::string string) {
  bool found = false;
  for (const auto& elem : vector) {
    if (elem == string) found = true;
  }
  return found;
}

/** 
 *  @brief Pasa de vector de string a una sola string
 *  @return Vector en string
 */
std::string vector_to_string(std::vector<std::string> vector) {
  std::string string_vector;
  for (const auto& elem : vector) string_vector += elem + SPACE;
  return string_vector;
}

/** 
 *  @brief Calcula las subcadenas de una cadena
 *  @return String con las subcadenas separadas
 */
std::string Sequence::substrings() {
  std::vector<std::string> substrings;
  substrings.push_back(EMPTY_STR);
  std::string aux_string;
  int size = sequence_.size();
  for (int i = 0; i < size; ++i) {
    for (int j = i; j < size; ++j) {
      aux_string += sequence_[j].getSymbol();
      if (!find(substrings, aux_string)) substrings.push_back(aux_string);
    }
    aux_string.erase();
  } 
  return vector_to_string(substrings) + SPACE;
}

/** 
 *  @brief Sobrecarga del operador <<
 *  @param[out] out
 *  @param[in] sequence
 */
std::ostream& operator<<(std::ostream& out, const Sequence& sequence) {
  out << "'";
  
  out << "'";
  return out;
}

/** 
 *  @brief Comprueba qué símbolos no se han usado
 *  @return Devuelve un string con los símbolos no usados
 */
std::string Sequence::non_used() {
  std::string non_used;
  for (int i = 0; i < getAlphabet().getSize(); ++i) {
    if (string_.find(getAlphabet().getAlphabet()[i].getSymbol()) == std::string::npos) {
      non_used += getAlphabet().getAlphabet()[i].getSymbol();
    }
  }
  return non_used;
}
  