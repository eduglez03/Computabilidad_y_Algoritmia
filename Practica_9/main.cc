// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnologíıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 9: Maquina de Turing
// Autor: Eduardo González Gutiérrez
// Correo: alu0101461588@ull.edu.es
// Fecha: 15/11/2023
// Archivo main.cc: Programa cliente

#include <iostream>
#include <string>

#include "main_tools.h"
#include "MaquinaTuring.h"

int main(int argc, char *argv[]){
  unsigned opcion; // Opcion para mostrar la maquina de turing por pantalla
  bool aceptacion; // Aceptacion de la cadena
  bool error = false; // Error en la lectura de la maquina de turing

  // Si el numero de parametros es igual a 1 se muestra error
  if (argc == 1) {
    Error(argv[0]);
  }

  // Comprobamos que el número de argumentos sea el correcto 
  Usage(argc, argv);

  // Creamos un objeto de la clase MaquinaTuring
  MaquinaTuring maquinaturing(argv[1], argv[2], error);
  
  // Si no se ha producido ningún error en la lectura de la maquina de turing
  if (error == false) {
    std::cout << " >> ¿Mostrar la máquina de turing por pantalla?" << std::endl;
    std::cout << "Sí (Pulsa 1)" << std::endl;
    std::cout << "No (Pulsa 0)" << std::endl << "Opción: ";
    std::cin >> opcion;
    std::cout << std::endl;
    
    // Si la opcion es 1 se muestra la maquina de turing por pantalla
    if (opcion == 1) {
      maquinaturing.MostrarMaquinaTuring();
    }
    
    // Se simula la maquina de turing
    aceptacion = maquinaturing.SimularMT();
    std::cout << std::endl;
    
    // Se muestra si la cadena es aceptada o no
    if (aceptacion) {
      std::cout << "Cadena ACEPTADA" << std::endl;
    }
    else {
      std::cout << "Cadena NO ACEPTADA" << std::endl;
    }
  }
}
