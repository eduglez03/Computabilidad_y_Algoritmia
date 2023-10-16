// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnologíıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con Cadenas
// Autor: Eduardo González Gutiérrez
// Correo: alu0101461588@ull.edu.es
// Fecha: 27/09/2023
// Archivo cya-P02_cadena.h: archivo de cabecera
// Contiene la declaracion de la clase Cadena
// Referencias:
// Enlaces de interés

// Historial de revisiones
// 12/09/2023 - Creación (primera versión) del código

#include<iostream>
#include<vector>
#include<string>

/**
 * @brief Clase Cadena
 * 
 */
class Cadena {
  public:
    Cadena(){}; // Constructor por defecto
    Cadena(std::string string) : strings_{string} {} // Constructor de la clase
    
    char at(const int); // Declaracion del metodo que accede a un elemento concreto de una cadena
    
    int get_length(); // Declaracion del metodo que calcula el tamaño de una cadena
    std::string inversa(); // Declracion del metodo que calcula la inversa de una cadena
    std::vector<Cadena> prefijos(); // Declaracion del metodo que calcula los prefijos de una cadena
    std::vector<Cadena> sufijos(); // Declaracion del metodo que calcula los sufijos de una cadena
    void subcadenas(int);  // Declaracion del metodo que calcula las subcadenas de una cadena

    friend std::ostream& operator<<(std::ostream&, const Cadena&); // Sobrecarga operador extraccion
    bool operator<(const Cadena&) const; // Sobrecarga operador "menor que" para usarlo en el set
  
  private:
    std::string strings_;
};