#include<iostream>
#include<string>

#pragma once 

class Simbolo {
  public:
    Simbolo() {}; // Constructor por defecto
    Simbolo(const char simbolo) { simbolo_ = simbolo; } // Constructor de la clase
    Simbolo(const std::string& simbolo) { simbolo_ = simbolo; } // Constructor de la clase

    std::string get_simbolo() const { return simbolo_; } // Getter simbolo
    int get_length() const { return simbolo_.length(); } // Getter longitud string simbolo

    void set_simbolo(std::string& simbolo) { simbolo_ = simbolo; } // Setter simbolo

    friend std::ostream& operator<<(std::ostream& out, const Simbolo& simbolo); // Sobrecarga operador extraccion
    friend bool operator==(const Simbolo&simbolo1, const Simbolo& simbolo2);  // Sobrecarga operador ==
    friend bool operator!=(const Simbolo& simbolo1, const Simbolo& simbolo2);  // Sobrecarga operador !=
    friend bool operator<(const Simbolo& simbolo1, const Simbolo& simbolo2);  // Sobrecarga operador <

  private:
    std::string simbolo_;
};