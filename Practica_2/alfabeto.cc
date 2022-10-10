// Universidad de La Laguna. Escuela Superior de Ingeniería y Tecnología
// 2º de Grado en Ingeniería Informática.  
// Asignatura: Computabilidad y Algoritmia

// Práctica 2: Lenguajes
// Autor: Eduardo González Gutiérrez
// Correo: alu0101461588@ull.edu.es
// Fecha: 11/10/2022
// Archivo clase_alfabeto.cc: Implementación de la clase alfabeto

// Historial de revisiones
// 28/09/2022 - Creación, primera versión del código

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "alfabeto.h"


// constructor de la clase Alfabeto para añadir los simbolos
Alfabeto::Alfabeto(const Simbolo& kSimboloAnadir) {
  alfabeto_.insert(kSimboloAnadir);

}

// constructor de la clase con un vector de simbolos
Alfabeto::Alfabeto(const std::vector<Simbolo>& kVectorSimboloAnadir) {
  for(int bucle{0}; bucle < kVectorSimboloAnadir.size(); ++bucle) {
    alfabeto_.insert(kVectorSimboloAnadir[bucle]);
  }
} 

// constructor de la clase apartir de una cadena
Alfabeto::Alfabeto(const Cadena& kCadenaAlfabetoAnadir) {
  Simbolo simbolo_meter;
  std::string elemento_meter;
  for(int bucle{0}; bucle < kCadenaAlfabetoAnadir.Longitud(); ++bucle) {
    elemento_meter = kCadenaAlfabetoAnadir.GetCadenaStr()[bucle];  //transformamos el char en una string
    simbolo_meter.SetSimbolo(elemento_meter); // creamos un nuevo simbolo
    alfabeto_.insert(simbolo_meter); // metemos en el alfabeto el simbolo apartir de la cadena
  }
}

//getter de la clase Alfabeto
std::vector<Simbolo> Alfabeto::GetAlfabeto() const {
  std::vector<Simbolo> vector_entregar;
  for (Simbolo bucle : alfabeto_) {   // para rellenar el vector con las posibles posiciones a elegir
    vector_entregar.push_back(bucle);
  }
  return vector_entregar;
} 

//setter de la clase Alfabeto
void Alfabeto::SetAlfabeto(const Alfabeto& kAlfabetoCambiar) {
  alfabeto_.clear();
  for (int bucle{0}; bucle < kAlfabetoCambiar.LongitudAlfabeto(); ++bucle) {
    alfabeto_.insert(kAlfabetoCambiar.AtAlfabeto(bucle));
  }
}

// devuelve un determinado simbolo de una posicion del alfabeto
Simbolo Alfabeto::AtAlfabeto(const int kPosicion) const {
  if (kPosicion < LongitudAlfabeto() && kPosicion >= 0 ) {   // comprobamos si estamos accediendo a un elemento existente del vector
    std::vector<Simbolo> vector_alfabeto{GetAlfabeto()};
    return vector_alfabeto[kPosicion];
  } else {
    Simbolo simbolo_vacio{""};
    return simbolo_vacio;
  }
} 


// Método que añade un simbolo en el alfabeto
void Alfabeto::AnadirAlfabeto(const Simbolo& kSimboloAnadir) {
  alfabeto_.insert(kSimboloAnadir);
}

// Muestra la longitud del alfabeto en función del numero de simbolos que contiene
int Alfabeto::LongitudAlfabeto() const {
  return alfabeto_.size();
}  

// Método que comprueba si una cadena pertenece al alfabeto
bool Alfabeto::CadenaPertenceAlfabeto(const Cadena& kCadenaComprobar) const {
  bool comprobacion_final{false};   // variable que comprueba si la cadena pertenece al alfabeto
  Simbolo simbolo_comprobar1; // variable que tomara el valor del simbolo  del alfabeto que estamos comprobando si esta en la cadena
  int longitud_simbolo;  // variable que tomará la longitud del simbolo_comprobar para saber el tamaño de comparación
  Simbolo simbolo_comprobar2; // variable que tomara el valor del simbolo de la cadena que estamos comprobando si esta en el alfabeto
  int posicion_comprobar{0}; // varibale que toma la posicion de la cadena en la cual empieza simbolo_comprobar2

  if ((kCadenaComprobar.GetCadenaStr() == "&") || (kCadenaComprobar.GetCadenaStr() == "")) {   // si es una cadena vacia siempre pertenece al alfabeto
    return true;
  }

  for (int bucle1{0}; bucle1 < LongitudAlfabeto() && comprobacion_final == false;) {
    simbolo_comprobar1.SetSimbolo(AtAlfabeto(bucle1).GetSimbolo());   
    longitud_simbolo = simbolo_comprobar1.Longitud();
    simbolo_comprobar2.SetSimbolo("");    // vaciamos el simbolo para volver a reellenarlo con el siguiente

    for (int bucle2{0}; bucle2 < longitud_simbolo && posicion_comprobar < kCadenaComprobar.Longitud(); ++bucle2) {  // rellenamos un simbolo para comprobar partiendo de la cadena
      simbolo_comprobar2.Concatenar(kCadenaComprobar.GetCadenaStr()[posicion_comprobar]);
      if (posicion_comprobar < kCadenaComprobar.Longitud()) {
        ++posicion_comprobar;
      }

    }

    if (simbolo_comprobar1 != simbolo_comprobar2) {   // si esa parte de la cadena ya está en el alfabeto avanzamos hasta la siguiente parte a comprobar
      posicion_comprobar = posicion_comprobar - simbolo_comprobar2.Longitud();
      ++bucle1;  // sumamos uno a bucle para seguir buscando un simbolo
    } else {
      bucle1 = 0;   // si son iguales volvemos a comprobar desde la cadena del principio 
    }
    
    if (posicion_comprobar >= kCadenaComprobar.Longitud()) {   // si posicion_comprobar es mas grande que la cadena significa que podemos formar toda la cadena con el alfabeto
      comprobacion_final = true;
    }
  }
  
  return comprobacion_final;

}


//------------------Ejercicio-Practica------------------//
// Método que te dice cuantos simbolos de ese alfabeto tienes en esa cadena
int Alfabeto::CantidadSimbolosCadena(const Cadena& kCadenaComprobar) const {
  int cantidad_simbolos{0};  // variable para contar cuantos simbolos tiene la cadena
  bool comprobacion_final{false};   // variable que comprueba si la cadena pertenece al alfabeto
  Simbolo simbolo_comprobar1; // variable que tomara el valor del simbolo  del alfabeto que estamos comprobando si esta en la cadena
  int longitud_simbolo;  // variable que tomará la longitud del simbolo_comprobar para saber el tamaño de comparación
  Simbolo simbolo_comprobar2; // variable que tomara el valor del simbolo de la cadena que estamos comprobando si esta en el alfabeto
  int posicion_comprobar{0}; // varibale que toma la posicion de la cadena en la cual empieza simbolo_comprobar2

  if (kCadenaComprobar.GetCadenaStr() == "&") {   // si es una cadena vacia su longitud es 0
    return 0;
  }

  for (int bucle1{0}; bucle1 < LongitudAlfabeto();) {
    simbolo_comprobar1.SetSimbolo(AtAlfabeto(bucle1).GetSimbolo());   
    longitud_simbolo = simbolo_comprobar1.Longitud();
    simbolo_comprobar2.SetSimbolo("");    // vaciamos el simbolo para volver a reellenarlo con el siguiente

    for (int bucle2{0}; bucle2 < longitud_simbolo && posicion_comprobar < kCadenaComprobar.Longitud(); ++bucle2) {  // rellenamos un simbolo para comprobar partiendo de la cadena
      simbolo_comprobar2.Concatenar(kCadenaComprobar.GetCadenaStr()[posicion_comprobar]);
      if (posicion_comprobar < kCadenaComprobar.Longitud()) {
        ++posicion_comprobar;
      }

    }

    if (simbolo_comprobar1 != simbolo_comprobar2) {   // si esa parte de la cadena ya está en el alfabeto avanzamos hasta la siguiente parte a comprobar
      posicion_comprobar = posicion_comprobar - simbolo_comprobar2.Longitud();
      ++bucle1;  // sumamos uno a bucle para seguir buscando un simbolo
    } else {
      bucle1 = 0;   // si son iguales volvemos a comprobar desde la cadena del principio 
      ++cantidad_simbolos;  // sumamos la cantida de simblos porque encotramos uno que está en la cadena
    }
    
  }

  return cantidad_simbolos;

}   

// elimina todos los simbolos del alfabeto (un alfabeto no puede ser vacío pero es necesario para un método)
void Alfabeto::ClearAlfabeto() {
  alfabeto_.clear();
}

// sobrecarga del operador de inserción en flujo para mostrar el alfabeto
std::ostream& operator<<(std::ostream& out, const Alfabeto& kAlfabetoMostrar) {
  if (kAlfabetoMostrar.LongitudAlfabeto() == 0) {   // si tiene tamaño 0 muestra un error
    out << "Error: Alfabeto no puede estar vacio";

  } else {
    for (int bucle{0}; bucle < kAlfabetoMostrar.LongitudAlfabeto(); ++bucle) {
      out << kAlfabetoMostrar.AtAlfabeto(bucle) << " ";
    }

  }
  return out;
}  

// metodo que dice si la primera cadena esta antes que la segunda
bool CalculaEnOrdenAlfabeticoSimbolos(const Simbolo& simbolo_comparar1, const Simbolo& simbolo_comparar2) {
  int tamano_cadena_minima;  
  if (simbolo_comparar1.Longitud() <= simbolo_comparar2.Longitud()) {   // comprobamos que cadena es la que tiene menor tamaño
    tamano_cadena_minima = simbolo_comparar1.Longitud();
  } else {
    tamano_cadena_minima = simbolo_comparar2.Longitud();
  } 

  for (int bucle{0}; bucle < tamano_cadena_minima; ++bucle) {
    if (int(simbolo_comparar1.GetSimbolo()[bucle]) < int(simbolo_comparar2.GetSimbolo()[bucle])) {   // si la letra del primero es menor(alfabeticamente) que la del segundo
      return true;
    }
    if (int(simbolo_comparar2.GetSimbolo()[bucle]) < int(simbolo_comparar1.GetSimbolo()[bucle])) {   // si la letra del segundo es menor(alfabeticamente) que la del primero
      return false;
    } 
  }

  if (simbolo_comparar1.Longitud() == tamano_cadena_minima) { // si lel primer simbolo fue el menor y paso el bucle siendo todos sus caracteres iguales, significa que es el menor(alfabeticamente)
    return true;   
  } else {  // si lel primer simbolo fue el menor y paso el bucle siendo todos sus caracteres iguales, significa que es el menor(alfabeticamente)
    return false;
  }

}

// sobrecarga del operador < para la clase set
bool operator<(const Simbolo& simbolo_comparar1, const Simbolo& simbolo_comparar2) {
  if(simbolo_comparar1.Longitud() < simbolo_comparar2.Longitud()) {
    return true;
  } else if((simbolo_comparar1.Longitud() == simbolo_comparar2.Longitud()) && (simbolo_comparar1.GetSimbolo() != simbolo_comparar2.GetSimbolo())) {  // si es distinta cadena pero misma longitud es verdadero
    return CalculaEnOrdenAlfabeticoSimbolos(simbolo_comparar1, simbolo_comparar2);
  }
  return false;   // si es la misma cadena retorna falso
}
