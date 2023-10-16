#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <string>
#include <vector>

#include "simbolo.h"
#include "alfabeto.h"

class Sequence {
 private:
  Alphabet alphabet_;
  std::vector<Symbol> sequence_;
  std::string string_;
 public:
  /// Constructor
  Sequence(std::string& string);
  /// Getters
  Alphabet getAlphabet() const { return alphabet_; };
  std::string getSequence() const;
  std::string getString() const { return string_; };
  /// Funciones
  int length();
  std::string reverse();
  // Sequence reverse();
  std::string prefixes();
  std::string suffixes();
  std::string substrings();
  /// Modificación
  bool is_in(Symbol symbol);
  std::string non_used();
};

#endif