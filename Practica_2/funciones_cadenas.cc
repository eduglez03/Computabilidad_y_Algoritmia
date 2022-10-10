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

#include "funciones_cadenas.h"

// Método para sacar la cadena y el alfabeto de cada linea cogiendo como referencia estas dos para trabajar sobre ellas
void ObtieneAlfabetoLenguaje(const std::string& kLineaEntrada, Alfabeto& alfabeto, Lenguaje& lenguaje) {
  std::string palabra_meter;  // palabra que se irá formando para introducrila en el vector de elementos de la linea
  std::vector<std::string> vector_elementos;  // vector de elementos en el que se iran introduciendo las distintas palabras a medida que se vayan concoiendo
  const std::string kEspacio{" "};  // variable utilizada para compara con el caracter espacio

  // metemos todos los elementos de la linea dada en un vector
  for (int bucle1{0}; bucle1 < kLineaEntrada.length(); ++bucle1) {    
    if (kLineaEntrada[bucle1] == kEspacio) {  // si ya tenemos una palabra separada por espacio la metemos en el vector
      vector_elementos.push_back(palabra_meter);
      palabra_meter = "";   // reiniciamos la string para volverla a usar

    } else {
        palabra_meter = palabra_meter + kLineaEntrada[bucle1];
    }
  }
  vector_elementos.push_back(palabra_meter);   // metemos la ultima palabra de la línea
  
  int bucle2{1}; // empezamos en dos mas alante porque hay una llave y un espacio
  Simbolo simbolo_anadir;
  alfabeto.ClearAlfabeto();  // limpiamos el alfabeto
  for (; bucle2 < vector_elementos.size(); ++bucle2) {   // conseguimos el alfabeto
    if (vector_elementos[bucle2] != "}") {
      simbolo_anadir.SetSimbolo(vector_elementos[bucle2]);
      alfabeto.AnadirAlfabeto(simbolo_anadir);
    } else {
      break;
    }
  }

  bucle2 = bucle2 + 2; // saltamos es espacio siguiente y la llave abierta siguiente del lenguaje
  Cadena cadena_anadir;
  for (; bucle2 < vector_elementos.size(); ++bucle2) {   // conseguimos el lenguaje
    if (vector_elementos[bucle2] != "}") {
      simbolo_anadir.SetSimbolo(vector_elementos[bucle2]);
      cadena_anadir.SetCadena(simbolo_anadir);
      lenguaje.AnadirLenguaje(cadena_anadir);
    } else {
      break;
    }
  }
  
}

// Método que contatena dos lenguajes y lo muestra por pantalla
void Concatenacion(std::ofstream& kFicheroSalida, const Lenguaje& kLenguaje1, const Lenguaje& kLenguaje2) {
  kFicheroSalida << "Concatenacion: ";
  kFicheroSalida << kLenguaje1.Concatenacion(kLenguaje2) << std::endl;
}

// Método que une dos lenguajes y lo muestra por pantalla
void Union(std::ofstream& kFicheroSalida, const Lenguaje& kLenguaje1, const Lenguaje& kLenguaje2){
  kFicheroSalida << "Union: ";
  kFicheroSalida << kLenguaje1.Union(kLenguaje2) << std::endl;
}

// Método que intersecciona dos lenguajes y lo muestra por pantalla
void Interseccion(std::ofstream& kFicheroSalida, const Lenguaje& kLenguaje1, const Lenguaje& kLenguaje2) {
  kFicheroSalida << "Interseccion: ";
  kFicheroSalida << kLenguaje1.Interseccion(kLenguaje2) << std::endl;
}

// Método que hace la diferencia de dos lenguajes y lo muestra por pantalla
void Diferencia(std::ofstream& kFicheroSalida, const Lenguaje& kLenguaje1, const Lenguaje& kLenguaje2) {
  kFicheroSalida << "Diferencia: ";
  kFicheroSalida << kLenguaje1.Diferencia(kLenguaje2) << std::endl;
}

// Método que hace la inversa y lo muestra por pantalla
void Inversa(std::ofstream& kFicheroSalida, const Lenguaje& kLenguaje) {
  kFicheroSalida << "Inversa: ";
  kFicheroSalida << kLenguaje.Inversa() << std::endl;
}

// Método que hace la potencia y lo muestra por pantalla
void Potencia(std::ofstream& kFicheroSalida, const Lenguaje& kLenguaje) {
  int potencia;
  std::cout << "Introduzca una potencia: ";
  std::cin >> potencia;
  if (potencia >= 0) {   // comprobamos que la potencia sea correcta
    kFicheroSalida << "Potencia: ";
    kFicheroSalida << kLenguaje.Potencia(potencia) << std::endl;
  } else {
    kFicheroSalida << "La potencia elegida no es valida" << std::endl;
  }
}