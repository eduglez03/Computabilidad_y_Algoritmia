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

#include "alfabeto.h"
#include "lenguaje.h"
#include "funciones_cadenas.h"
#include "cadena.h"
#include "simbolo.h"

// Método que sirve para mostrar al usuario la forma de interactuar con el programa
void Usage(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Modo de uso: ./maincadenas.cc fichero_lenguaje1.txt fichero_lenguaje2.txt fichero_salida.txt opcode" << std::endl;
    std::cout << "Pruebe a añadir '--help' para más información." << std::endl;
    exit(EXIT_SUCCESS);
  }
  std::string parametro{argv[1]};
  if (parametro == "--help") {
    std::cout << "Este programa te permite introducir desde dos ficheros con lenguajes y luego eliges" << std::endl;
    std::cout << "un número entre el 1-5 para que en el fichero de salida aparezca la operacion seleccionada entre los lenguajes" << std::endl;
    std::cout << "1(Concatenacion)  2(Union)  3(Interseccion)  4(Diferencia)  5(Inversa)  6(Potencia)" << std::endl << std::endl; ;
  }

  if (argc != 5) {
    std::cout << "Modo de uso: ./maincadenas.cc fichero_lenguaje1.txt fichero_lenguaje2.txt fichero_salida.txt opcode" << std::endl;
    std::cout << "Pruebe a añadir '--help' para más información." << std::endl;
    exit(EXIT_SUCCESS);
  }
}


int main(int argc, char* argv[]) {
  Usage(argc, argv);
  std::string parametro{argv[4]};  // opcion escogida por el usuario
  std::string fichero_entrada1{argv[1]};  // fichero de entrada
  std::string fichero_entrada2{argv[2]};  // fichero de entrada
  std::string fichero_salida{argv[3]};  // fichero de salida

  if (parametro.length() == 1) { // comprobamos is el opcode es un solo caracter
    int opcion_usuario{std::stoi(parametro)};
    std::ifstream fichero_leer1{fichero_entrada1};  // fichero para leer los datos
    std::ifstream fichero_leer2{fichero_entrada2};  // fichero para leer los datos
    std::ofstream fichero_escribir{fichero_salida};   // fichero para escribir los datos
    std::string linea_actual1;
    std::string linea_actual2;


    while (getline(fichero_leer1, linea_actual1) && getline(fichero_leer2, linea_actual2)) {
      Simbolo simbolo_vacio{"&"};
      Alfabeto alfabeto_1{simbolo_vacio};  // alfabeto para rellenar
      Alfabeto alfabeto_2{simbolo_vacio};  // alfabeto para rellenar
      Lenguaje lenguaje_1;  // lenguaje para rellenar
      Lenguaje lenguaje_2;  // lenguaje para rellenar
      
      ObtieneAlfabetoLenguaje(linea_actual1, alfabeto_1, lenguaje_1);  // metodo para sacar los lenguajes y los alfabetos
      ObtieneAlfabetoLenguaje(linea_actual2, alfabeto_2, lenguaje_2);  // metodo para sacar los lenguajes y los alfabetos
      fichero_escribir << "Alfabeto 1: " << alfabeto_1 << " | " << "Lenguaje 1: " << lenguaje_1 << std::endl;
      fichero_escribir << "Alfabeto 2: " << alfabeto_2 << " | " << "Lenguaje 2: " << lenguaje_2 << std::endl;
      
      if (lenguaje_1.LenguajePertenceAlfabeto(alfabeto_1) == false || lenguaje_2.LenguajePertenceAlfabeto(alfabeto_2) == false) {  // comprobamos si los lenguajes pertenecen a sus alfabetos
        fichero_escribir << "(hay un lenguaje que no se puede formar a partir del alfabeto)";

      } else{
        switch(opcion_usuario) {    // comprobamos que opcion a elegido el usuario
          case 1: Concatenacion(fichero_escribir, lenguaje_1, lenguaje_2 );
          break;
          case 2: Union(fichero_escribir, lenguaje_1, lenguaje_2 );
          break;
          case 3: Interseccion(fichero_escribir, lenguaje_1, lenguaje_2);
          break;
          case 4: Diferencia(fichero_escribir, lenguaje_1, lenguaje_2);
          break;
          case 5: Inversa(fichero_escribir, lenguaje_1);  
          break;
          case 6: Potencia(fichero_escribir, lenguaje_1);  
          break;
          default: std::cout << "El opcode introducido no es válido, introduzca uno entre el 1 y el 6" << std::endl;
          break;
        }
        
      }
      fichero_escribir << std::endl;
    }
  } else {
    std::cout << "El opcode introducido no es válido, introduzca uno entre el 1 y el 6 " << std::endl;
  }
  return 0;
}