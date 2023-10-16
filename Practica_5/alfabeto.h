#ifndef ALPHABET_H
#define ALPHABET_H

#include <iostream>
#include <vector>
#include <string>
#include "simbolo.h"

const char SPACE = ' ';

class Alphabet {
 private:
  std::vector<Symbol> alphabet_;

 public:
  /// Constructores
  Alphabet() {};
  Alphabet(std::string& string);

  /// Getters
  std::vector<Symbol> getAlphabet() const { return alphabet_; };
  int getSize() const { return alphabet_.size(); };

  /// Funciones
  bool find(Symbol symbol) const;
  void add(Symbol symbol);

  /// Sobrecargas
  friend std::ostream& operator<<(std::ostream& out, const Alphabet& alphabet);
  friend Alphabet operator+(const Alphabet& alphabet1, const Alphabet& alphabet2);
};

#endif