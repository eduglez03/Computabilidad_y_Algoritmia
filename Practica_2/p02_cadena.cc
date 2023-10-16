// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnologíıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con Cadenas
// Autor: Eduardo González Gutiérrez
// Correo: alu0101461588@ull.edu.es
// Fecha: 27/09/2023
// Archivo cya-P02_cadena.cc: Implementacion metodos clase Cadena
// Contiene la implementacion de los metodos declarados en la clase Cadena
// Referencias:
// Enlaces de interés

// Historial de revisiones
// 12/09/2023 - Creación (primera versión) del código

#include "p02_cadena.h"

/**
 * @brief Metodo que accede a un elemento concreto de una cadena
 * 
 * @param posicion 
 * @return char 
 */
char Cadena::at(const int posicion) {
  return strings_.at(posicion);
} 

/**
 * @brief Metodo que calcula la longitud de una cadena
 * 
 * @return int 
 */
int Cadena::get_length() {
  if(strings_ == "&") { // Comprobamos que la cadena no sea la cadena vacia. En caso de serlo, su longitud sera 0
    return 0;
  }
  else {
    return strings_.size();
  }
}

/**
 * @brief Metood que calcula la inversa de una cadena
 * 
 * @return std::string 
 */
std::string Cadena::inversa() {
  std::string cadena_inversa;

  if(this->at(0) == '&'){ // Si la cadena es la cadena vacia, su inversa sera la propia cadena vacia
    cadena_inversa = "&";
  }
  else { // Si no es la cadena vacia, recorremos la cadena pasada por parametro a la inversa y almacenamos sus valores en la cadena resultado
    for(int i = this->get_length() - 1; i >= 0; i--) {
      cadena_inversa.push_back(this->at(i));
    }
  }

  return cadena_inversa;
}

/**
 * @brief Sobrecarga del operador < para comparar Cadena en función de su longitud
 * 
 * @param cadena2 
 * @return true 
 * @return false 
 */
bool Cadena::operator<(const Cadena& cadena2) const {
  return strings_.length() < cadena2.strings_.length();
}

/**
 * @brief Sobrecarga del operador de impresión (ostream) para imprimir Cadena
 * 
 * @param os 
 * @param cadena 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Cadena& cadena) {
  os << cadena.strings_;
  return os;
} 

/**
 * @brief Metodo que calcula los prefijos de una cadena
 * 
 * @return std::vector<Cadena> 
 */
std::vector<Cadena> Cadena::prefijos() {
  std::vector<Cadena> cadena_prefijos;
  std::string cadena_vacia = "&";
  cadena_prefijos.push_back(cadena_vacia); // Añadimos la cadena vacia al vector de cadenas resultantes

  for (int i = 0; i < this->get_length(); i++) {
    std::string prefijo;
    for (int j = 0; j <= i; j++) {
      prefijo += this->at(j);
    }
    cadena_prefijos.push_back(prefijo);
  }
  return cadena_prefijos;
}

/**
 * @brief Metodo que calcula los sufijos de una cadena
 * 
 * @return std::vector<Cadena> 
 */
std::vector<Cadena> Cadena::sufijos() {
  std::vector<Cadena> cadena_sufijos;
  std::string cadena_vacia = "&";

  for (int i = 0; i <= this->get_length(); i++) {
    std::string sufijo;
    for (int j = i; j < this->get_length(); j++) {
      sufijo += this->at(j);
    }
    cadena_sufijos.push_back(sufijo);
  }
  
  cadena_sufijos.push_back(cadena_vacia); // Añadimos la cadena vacia al vector de cadenas resultantes
  
  return cadena_sufijos;
}

void Cadena::subcadenas(int limite) {
  if (this->get_length() < limite) {
    std::cout << '&';
  } else {
    for (int i = 0; i < (this->get_length() - 1);) {
      std::cout << this->strings_.substr(i, limite) << ", ";
      i++;
    }
  }
}
