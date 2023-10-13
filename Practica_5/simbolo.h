#include<iostream>


class Simbolo {
  public:
    Simbolo() {}; // Constructor por defecto
    Simbolo(const char); // Constructor de la clase
    Simbolo(std::string&); // Constructor de la clase

    std::string get_simbolo(); // Getter simbolo
    int get_length(); // Getter longitud string simbolo

    void set_simbolo(std::string&); // Setter simbolo

    friend std::ostream& operator<<(std::ostream& out, const Simbolo& simbolo); // Sobrecarga operador extraccion
    friend bool operator==(const Simbolo& simbolo1, const Simbolo& simbolo2);  // Sobrecarga operador ==
    friend bool operator!=(const Simbolo& simbolo1, const Simbolo& simbolo2);  // Sobrecarga operador !=
    friend bool operator<(const Simbolo& simbolo1, const Simbolo& simbolo2);  // Sobrecarga operador <

  private:
    std::string simbolo_;
};

// Constructor de la clase
Simbolo::Simbolo(const char simbolo) {
  simbolo_ = simbolo;
}

// Constructor de la clase
Simbolo::Simbolo(std::string& simbolo) {
  simbolo_ = simbolo;
}

// Getter simbolo
std::string Simbolo::get_simbolo() {
  return simbolo_;
}

// Getter longitud string simbolo
int Simbolo::get_length() {
  return simbolo_.size();
}

// Setter simbolo
void Simbolo::set_simbolo(std::string& simbolo) {
  simbolo_ = simbolo;
}

// Sobrecarga operador extraccion
std::ostream& operator<<(std::ostream& out, const Simbolo& simbolo) {
  out << simbolo.simbolo_;
  return out;
}

// Sobrecarga operador ==
bool operator==(const Simbolo& simbolo1, const Simbolo& simbolo2) {
  return simbolo1.simbolo_ == simbolo2.simbolo_;
}

// Sobrecarga operador !=
bool operator!=(const Simbolo& simbolo1, const Simbolo& simbolo2) {
  return simbolo1.simbolo_ != simbolo2.simbolo_;
}

// Sobrecarga operador < 
bool operator<(const Simbolo& simbolo1, const Simbolo& simbolo2) {
  return simbolo1.simbolo_ < simbolo2.simbolo_;
}