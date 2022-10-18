// Universidad de La Laguna. Escuela Superior de Ingeniería y Tecnología
// 2º de Grado en Ingeniería Informática.  
// Asignatura: Computabilidad y Algoritmia

// Práctica 3: Calculadora lenguajes formales
// Autor: Eduardo González Gutiérrez
// Correo: alu0101461588@ull.edu.es
// Fecha: 17/10/2022

// Historial de revisiones
// 28/09/2022 - Creación, primera versión del código

#include <iostream>
#include <vector>
#include <string>

#include "alfabeto.h"
#include "lenguaje.h"
#include "funciones_cadenas.h"


// Método que sirve para mostrar al usuario la forma de interactuar con el programa
void Usage(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Modo de uso: ./maincadenas.cc fichero_lenguaje_operaciones.txt" << std::endl;
    std::cout << "Pruebe a añadir '--help' para más información." << std::endl;
    exit(EXIT_SUCCESS);
  }
  std::string parametro{argv[1]};
  if (parametro == "--help") {
    std::cout << "Este programa te permite introducir los lenguajes en las primeras lineas y tras eso" << std::endl;
    std::cout << "las operaciones entre ellos en notacion polaca inversa. Las operaciones posibles son:" << std::endl;
    std::cout << "+(Concatenacion)  |(Union)  ^(Interseccion)  -(Diferencia)  !(Inversa)  *(Potencia)" << std::endl << std::endl; ;
  }

  if (argc != 2) {
    std::cout << "Modo de uso: ./maincadenas.cc fichero_lenguaje_operaciones.txt" << std::endl;
    std::cout << "Pruebe a añadir '--help' para más información." << std::endl;
    exit(EXIT_SUCCESS);
  }
}


int main(int argc, char* argv[]) {
  Usage(argc, argv);
  std::string fichero_entrada{argv[1]};  // fichero de entrada
  std::ifstream fichero_leer{fichero_entrada};  // fichero para leer los datos
  std::string linea_actual;

  std::vector<Lenguaje> vector_lenguaje;  // VECTOR para almacenar los diversos lenguajes del fichero
  std::vector<Alfabeto> vector_alfabeto;  // VECTOR para almacenar los diversos alfabetos del fichero

  Simbolo simbolo_vacio{"&"};  // lenguaje para rellenar el vector
  Alfabeto alfabeto_meter{simbolo_vacio};  // alfabeto para rellenar el vector
  Lenguaje lenguaje_meter;  // lenguaje para rellenar el vector
  int contador_while{0};  // contador para saber cuantas veces llevamos en el while 

  while (getline(fichero_leer, linea_actual)) {
    if (linea_actual.length() > 1) {   // comporbamos que no sea una linea vacia
      if (EncuentraSimbolo(linea_actual, '=') == true) {   // si es un lenguaje lo metemos(suponiendo que todos los lenguajes están en orden)
        lenguaje_meter.SetLenguaje(SacaLenguajeString(linea_actual));   // creamos el lenguaje a partir de la linea_actual
        vector_lenguaje.push_back(lenguaje_meter);
        
        alfabeto_meter.SetAlfabeto(lenguaje_meter.CreaAlfabetoDeLenguaje());   // creamos el alfabeto a partir del lenguaje
        vector_alfabeto.push_back(alfabeto_meter);

        std::cout << "Alfabeto: " << alfabeto_meter << "   " << "Lenguaje: " << lenguaje_meter << std::endl;  // mostramos la información de cada

      } else {   // si es una operacion la hacemos
        const Lenguaje kLenguajeFinal{RPNLenguajes(vector_lenguaje, linea_actual)};
        std::cout << std::endl << "Alfabeto del Lenguaje: " << kLenguajeFinal.CreaAlfabetoDeLenguaje()  << "   Lenguaje resultado: " << kLenguajeFinal << std::endl;
      }
    }
  }
  return 0;
} 