// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Inforḿatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pŕactica 2: S ́ımbolos, alfabetos y cadenas
// Autor: Eduardo González Gutiérrez
// Correo: alu01014615888@ull.es
// Fecha: 03/10/2022
// Archivo cya-P02-Strings.cc: programa cliente.
//         Contiene la función main del proyecto que usa las clases X e Y
//         que realizan el trabajo de leer el fichero de entrada
//         identificando patrones en el texto que dan lugar
//         al fichero de salida.
// Referencias:
//          Enlaces de inteŕes
//
// Historial de revisiones
//          04/10/2021 - Creacíon (primera versíon) del ćodigo

#pragma once 
#include <iostream>
#include <vector>

class Simbolo {
 public:
   Simbolo(std::string simbolo){simbolo_ = simbolo;}
 private:
   std::string simbolo_;
};