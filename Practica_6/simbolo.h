#include<iostream>
#include<string>

class Simbolo {
  public:
    Simbolo() {} // Constructor por defecto
    Simbolo(const std::string& simbolo) {simbolo_ = simbolo;} // Constructor con parámetros
    Simbolo(const char simbolo) {simbolo_ = simbolo;} // Constructor con parámetros

    std::string getSimbolo() const { return simbolo_; } // Getter
    int getLength() const { return simbolo_.length(); } // Getter
    
    void setSimbolo(std::string& simbolo) { simbolo_ = simbolo; } // Setter

    // Sobrecargas
    friend std::ostream& operator<<(std::ostream& out, const Simbolo& simbolol);
    friend bool operator==(const Simbolo& simbolo1, const Simbolo& simbolo2);
    friend bool operator!=(const Simbolo& simbolo1, const Simbolo& simbolo2);
    friend bool operator<(const Simbolo& simbolo1, const Simbolo& simbolo2);

  private:
    std::string simbolo_;
};
