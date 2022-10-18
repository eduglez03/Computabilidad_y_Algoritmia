// Universidad de La Laguna. Escuela Superior de Ingeniería y Tecnología
// 2º de Grado en Ingeniería Informática.  
// Asignatura: Computabilidad y Algoritmia

// Práctica 3: Calculadora lenguajes formales
// Autor: Eduardo González Gutiérrez
// Correo: alu0101461588@ull.edu.es
// Fecha: 17/10/2022

// Historial de revisiones
// 28/09/2022 - Creación, primera versión del código

#include "simbolo.h"
#include <string>

//------------------Métodos-de-clase------------------//
// Constructor de la clase simbolo para strings
Simbolo::Simbolo(const std::string& kSimbolo) {
  simbolo_ = kSimbolo;
}

// Constructor de la clase simbolo para char
Simbolo::Simbolo(const char& kSimbolo) {
  simbolo_ = kSimbolo;
} 

// Setter de la clase simbolo para cambiar el simbolo
void Simbolo::SetSimbolo(const std::string& kNuevoSimbolo) {
  simbolo_ = kNuevoSimbolo;
}

// Getter de la clase simbolo para obtener la string de el simbolo
std::string Simbolo::GetSimbolo() const {
  return simbolo_;
}

// metodo para concatenar un carácter a un símbolo cambiando este
void Simbolo::Concatenar(const char& kCaracterConcatenar) {
  std::string nuevo_simbolo{simbolo_ + kCaracterConcatenar};
  simbolo_ = nuevo_simbolo;

}

// Metodo que otorga la longitud del simbolo
int Simbolo::Longitud() const {
  return int(simbolo_.length());
}


//------------------Sobrecarga-Operadores------------------//

// sobrecarga del operador de inserción en flujo para mostrar el simbolo
std::ostream& operator<<(std::ostream& out, const Simbolo& kSimboloMostrar) {
  if (kSimboloMostrar.Longitud() == 0) {   // si tiene tamaño 0 muestra que es un simbolo vacío
    out << "";
  } else {
    out << kSimboloMostrar.GetSimbolo();
  }
  return out;
}

// sobrecarga del operador de igualdad
bool operator==(const Simbolo& kSimbolo1, const Simbolo& kSimbolo2) {
  return kSimbolo1.GetSimbolo() == kSimbolo2.GetSimbolo();
}

// sobrecarga del operador de no igualdad
bool operator!=(const Simbolo& kSimbolo1, const Simbolo& kSimbolo2) {
  return !(kSimbolo1.GetSimbolo() == kSimbolo2.GetSimbolo());
}