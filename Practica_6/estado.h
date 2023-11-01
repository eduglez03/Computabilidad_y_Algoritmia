#include<iostream>

class Estado {
  public:
    Estado() {} // Constructor por defecto
    Estado(const Estado& estado); // Constructor de copia
    Estado(int identificador, bool aceptacion); // Constructor con parámetros

    // Getters
    int get_identificador() const { return identificador_; }
    bool get_aceptacion() const { return aceptacion_; }
    int get_numeroTransiciones() const { return numeroTransiciones_; }

    // Setters
    void set_identificador(int identificador) { identificador_ = identificador; }
    void set_aceptacion(bool aceptacion) { aceptacion_ = aceptacion; }
    void set_numeroTransiciones(int numeroTransiciones) { numeroTransiciones_ = numeroTransiciones; }

    // Sobrecarga del operador de salida
    void operator=(const Estado& estado);
    friend bool operator==(const Estado& estado1, const Estado& estado2);
    friend bool operator!=(const Estado& estado1, const Estado& estado2);
    friend bool operator<(const Estado& estado1, const Estado& estado2);
    friend bool operator>(const Estado& estado1, const Estado& estado2);
    friend std::ostream& operator<<(std::ostream& out, const Estado& estado);

  private:
    int numeroTransiciones_;
    int identificador_;
    bool aceptacion_;
};