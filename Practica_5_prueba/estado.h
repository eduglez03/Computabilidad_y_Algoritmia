#pragma once

#include<iostream>
#include<set>

class Estado {
  public:
    Estado() {} // Constructor por defecto
    Estado(std::string nombre, unsigned int identificador, bool aceptacion); // Constructor de la clase

    bool get_aceptacion() const { return aceptacion_;} // Getter si el estado es o no de aceptacion
    unsigned int get_identificador() const { return identificador_; } // Getter identificador del estado

    void set_aceptacion(bool aceptacion) { aceptacion_ = aceptacion; } // Setter si el estado es o no de aceptacion
    void set_identificador(unsigned int identificador) { identificador_ = identificador; } // Setter identificador estado
    std::string get_nombre() const { return nombre_; } // Getter nombre
    void set_nombre(std::string nombre) { nombre_ = nombre; } // Setter nombre

    friend bool operator==(const Estado& estado1, const Estado& estado2); // Sobrecarga operador ==
    friend bool operator!=(const Estado& estado1, const Estado& estado2); // Sobrecarga operador !=
    friend bool operator<(const Estado& estado1, const Estado& estado2); // Sobrecarga operador <
    friend bool operator>(const Estado& estado1, const Estado& estado2); // Sobrecarga operador >
    friend std::ostream& operator<<(std::ostream& out, const Estado& estado); // Sobrecarga operador extraccion

  private:
    std::string nombre_ = "";
    unsigned int identificador_;
    bool aceptacion_ = false;
};