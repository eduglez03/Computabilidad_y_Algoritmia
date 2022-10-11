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


#include "cadena.h"
#include <string>
#include <vector>

// Constructor parametrizado de la clase Cadena con un parámetro que es un Simbolo
Cadena::Cadena(const Simbolo& kSimboloConvertir) {
  cadena_.SetSimbolo(kSimboloConvertir.GetSimbolo());
}

// Constructor parametrizado de la clase Cadena con un parámetro que es una Cadena
Cadena::Cadena(const Cadena& kCadenaConvertir) {
  cadena_.SetSimbolo(kCadenaConvertir.GetCadenaStr());
}


// Constructor por defecto de la clase Cadena
Cadena::Cadena() {
  cadena_.SetSimbolo("");
}

// metodo para concatenar un simbolo a la cadena y cambiando esta
void Cadena::ConcatenarDelante(const Simbolo& kSimboloConcatenar) {
  std::string nueva_cadena{cadena_.GetSimbolo() + kSimboloConcatenar.GetSimbolo()};
  cadena_.SetSimbolo(nueva_cadena);

}

// metodo para concatenar un simbolo a la cadena y cambiando esta
void Cadena::ConcatenarDetras(const Simbolo& kSimboloConcatenar) {
  std::string nueva_cadena{kSimboloConcatenar.GetSimbolo() + cadena_.GetSimbolo()};
  cadena_.SetSimbolo(nueva_cadena);

}

// Setter de la clase cadena para cambiar la cadena
void Cadena::SetCadena(const Cadena& kNuevaCadena) {
  cadena_.SetSimbolo(kNuevaCadena.GetCadenaStr());
}

// Getter de la clase cadena para obtener la string de la cadena
Simbolo Cadena::GetCadenaSim() const {
  return cadena_;
}

// Getter de la clase cadena para obtener la string de la cadena
std::string Cadena::GetCadenaStr() const {
  return cadena_.GetSimbolo();
}

// resetea la cadena para que no contenga ningún simbolo
void Cadena::ResetCadena() {
  cadena_.SetSimbolo("");
}

// sirve para conseguir un simbolo de la cadena especifico en string
Simbolo Cadena::AtCadena(const int kPosicion) const {
  if (kPosicion < Longitud()) {   // si estamos accediendo a una posicion mayor de la que tiene la cadena pornemos la vacía
    Simbolo simbolo_entregar{cadena_.GetSimbolo()[kPosicion]};
    return simbolo_entregar;
  }
  Simbolo simbolo_vacio{"&"};
  return simbolo_vacio;
}  

// Método que da la longitud(en char) de la cadena
int Cadena::Longitud() const {
  return int(cadena_.Longitud());
}

// sobrecarga del operador + para ampliar la cadena concatenando una string
Cadena Cadena::operator+(const Simbolo& kSimboloAnadir) {
  Cadena cadena_nueva{cadena_.GetSimbolo() + kSimboloAnadir.GetSimbolo()};
  return cadena_nueva;
}

// sobrecarga del operador de inserción en flujo para mostrar la cadena
std::ostream& operator<<(std::ostream& out, const Cadena& kCadenaMostrar) {
  if (kCadenaMostrar.Longitud() == 0) {   // si tiene tamaño 0 muestra que es una cadena vacía
    out << "&";
  } else {
    out << kCadenaMostrar.GetCadenaStr();
  }
  return out;
}

 // sobrecarga del operador de inserción en flujo para mostrar un vector de cadenas
std::ostream& operator<<(std::ostream& out, const std::vector<Cadena>& kVectorMostrar) {
  for (int bucle{0}; bucle < kVectorMostrar.size(); ++bucle) {
    out << kVectorMostrar[bucle] << " ";
  }
  return out;
} 

// Método que crea una cadena inversa
Cadena Cadena::Inversa() const {
  Cadena cadena_inversa;
  for (int bucle{int(cadena_.GetSimbolo().length()) - 1}; bucle >= 0; --bucle) {
    Simbolo simbolo_anadir{AtCadena(bucle)};
    cadena_inversa = cadena_inversa + simbolo_anadir;
  }

  return cadena_inversa;
}


// Método que incluye en un vector todos los prefijos de la cadena
std::vector<Cadena> Cadena::Prefijos() const {
  std::vector<Cadena> vector_cadenas;
  Cadena prefijo_anadir;

  if (Longitud() == 0) {   // si es la cadena vacia el prefijo es vacío
  Simbolo simbolo_vacio{"&"};
  Cadena cadena_vacia{simbolo_vacio};
  vector_cadenas.push_back(cadena_vacia);
  }else {
    Cadena cadena_vacia{'&'};
    vector_cadenas.push_back(cadena_vacia);  // incluyo la cadena vacía
    for (int bucle{0}; bucle < Longitud(); ++bucle) {
      Simbolo simbolo_concatenar = AtCadena(bucle);
      prefijo_anadir.ConcatenarDelante(simbolo_concatenar);
      vector_cadenas.push_back(prefijo_anadir);
    }
  }

  return vector_cadenas;
}


// Método que incluye en un vector todos los sufijos de la cadena
std::vector<Cadena> Cadena::Sufijos() const {
  std::vector<Cadena> vector_cadenas;
  Cadena cadena_invertir{Inversa()};
  Cadena sufijo_anadir;

  if (Longitud() == 0) {   // si es la cadena vacia el sufijo es vacío
    Simbolo simbolo_vacio{"&"};
    Cadena cadena_vacia{simbolo_vacio};
    vector_cadenas.push_back(cadena_vacia);

  } else {
    Cadena cadena_vacia{'&'};
    vector_cadenas.push_back(cadena_vacia);  // incluyo la cadena vacía
    for (int bucle{0}; bucle < Longitud(); ++bucle) {
      Simbolo simbolo_concatenar = cadena_invertir.AtCadena(bucle);
      sufijo_anadir.ConcatenarDetras(simbolo_concatenar);
      vector_cadenas.push_back(sufijo_anadir);
    }
  }
  return vector_cadenas;
}


// Sirve para comprobar si la cadena está en ese vector de cadenas
bool ComprobarExistenciaVector(const std::vector<Cadena>& kVectorComprobar, const Cadena& kCadenaComprobar) {
  for (int bucle{0}; bucle < kVectorComprobar.size() ; ++bucle) {
    if (kCadenaComprobar.GetCadenaStr() == kVectorComprobar[bucle].GetCadenaStr()) {
      return true;
    }
  }
  return false;
} 


// Método que incluye en un vector todas las subcadenas de la cadena
std::vector<Cadena> Cadena::Subcadenas() const {
  std::vector<Cadena> vector_subcadenas;
  Cadena subcadena_anadir;
  Cadena cadena_vacia{'&'};
  vector_subcadenas.push_back(cadena_vacia);  // incluyo la cadena vacía

  for (int bucle1{0}; bucle1 < Longitud(); ++bucle1) {
    for (int bucle2{bucle1}; bucle2 < Longitud(); ++bucle2) {
      subcadena_anadir.ConcatenarDelante(AtCadena(bucle2));
      if (ComprobarExistenciaVector(vector_subcadenas, subcadena_anadir) == false) {      // compruebo si ya he cogido esa cadena antes
        vector_subcadenas.push_back(subcadena_anadir);
      }
    }
    subcadena_anadir.ResetCadena();
  }
  return vector_subcadenas;
}

