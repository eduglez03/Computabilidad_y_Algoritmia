#include<iostream>
#include<set>

class Estado {
  public:
    Estado() {} // Constructor por defecto
    Estado(unsigned int, bool); // Constructor de la clase

    bool get_aceptacion(); // Getter si el estado es o no de aceptacion
    unsigned int get_identificador(); // Getter identificador del estado

    void set_aceptacion(bool); // Setter si el estado es o no de aceptacion
    void set_identificador(int); // Setter identificador estado

    friend bool operator==(const Estado& estado1, const Estado& estado2); // Sobrecarga operador ==
    friend bool operator!=(const Estado& estado1, const Estado& estado2); // Sobrecarga operador !=
    friend bool operator<(const Estado& estado1, const Estado& estado2); // Sobrecarga operador <
    friend bool operator>(const Estado& estado1, const Estado& estado2); // Sobrecarga operador >
    friend std::ostream& operator<<(std::ostream& out, const Estado& estado); // Sobrecarga operador extraccion

  private:
    unsigned int identificador_;
    bool aceptacion_ = false;
};

Estado::Estado(unsigned int identificador, bool aceptacion) {
  identificador_ = identificador;
  aceptacion_ = aceptacion;
}

// Getter si el estado es o no de aceptacion
bool Estado::get_aceptacion() {
  return aceptacion_;
}

// Getter identificador del estado
unsigned int Estado::get_identificador() {
  return identificador_;
}

// Setter si el estado es o no de aceptacion
void Estado::set_aceptacion(bool aceptacion) {
  aceptacion_ = aceptacion;
}

// Setter identificador estado
void Estado::set_identificador(int identificador) {
  identificador_ = identificador;
}

// Sobrecarga del operador ==
bool operator==(const Estado& estado1, const Estado& estado2) {
  bool condicion = true;
  if (estado1.identificador_ != estado2.identificador_) condicion = false;
  return condicion;
}

// Sobrecarga del operador !=
bool operator!=(const Estado& estado1, const Estado& estado2) {
  return !(estado1 == estado2);
}

// Sobrecarga del operador <
bool operator<(const Estado& estado1, const Estado& estado2) {
  return (estado1.identificador_ < estado2.identificador_);
}

// Sobrecarga del operador >
bool operator>(const Estado& estado1, const Estado& estado2) {
  return !(estado1 < estado2);
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream& out, const Estado& estado) {
  out << "(" << estado.identificador_ << ")";
  out << "(" << estado.aceptacion_ << ")";
  return out;
}