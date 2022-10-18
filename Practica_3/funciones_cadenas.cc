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
#include <fstream>

#include "funciones_cadenas.h"


//-------------OPERAR-LENGUAJES-------------//
// comprueba si es un operador para poder realizar la operacion en la pila
bool EsOperador(const char& kElementoComprobar) {
  if (kElementoComprobar == '+' || kElementoComprobar == '-' || kElementoComprobar == '^' || kElementoComprobar == '|' || kElementoComprobar == '!' ||kElementoComprobar == '*') {
    return true;
  } else {
    return false;
  }
}

// Método que saca la siguiente operacion a hacer del fichero para trabajar con la pila 
std::string SacaOperarcionesRPN(const std::string& kLineaLeer, int& posicion_leer) {   // posicion leer está como referencia para poder ir cambiando el valor desde empezar a leer para la siguiente llamada del método.
  std::string elemento_devolver;  // variable que contiene la string del numero del lenguaje la pila u operación que vamos a devolver
  std::string numero_obtenido;  // varibale que almacena un numero dado en caso de que no sea un lenguaje o un operador(esta varibale sirve principalmente para el operador *)

  for (int bucle1{posicion_leer}; bucle1 < kLineaLeer.length(); ++bucle1) {    // buscamos por toda la linea hasta encontrar el primer operador o lenguaje que veamos
    elemento_devolver = kLineaLeer[bucle1];
    if (EsOperador(kLineaLeer[bucle1]) == true) {  // si es un operador devolvemos el operador(excepto * porque lleva un numero)
      if (elemento_devolver != "*") {
        ++posicion_leer;
        return elemento_devolver;
      } else {  // siendo el operador * necesitamos el * y un número que tiene que estar justo antes
        ++posicion_leer;
        return elemento_devolver + numero_obtenido;   // en dos posicion contando el espacio se tiene que encontrar la potencia
      }

    } else if (elemento_devolver == 'L') {  // si es un lenguaje vemos que numero del lenguaje es (suponemos que no va a haber más de 9 lenguajes por lo que cogemos el siguiente carácter tras la L)
      int decimales_lenguaje{0}; // variabel que acumula la cantidad de decimales del lenguaje
      elemento_devolver.clear();  // limpiamos el elemento a devolver
      for (int bucle_lenguaje{posicion_leer + 1}; bucle_lenguaje < kLineaLeer.length(); ++bucle_lenguaje) {   // empezamos a meter decimales hasta que haya un espacio
        if (kLineaLeer[bucle_lenguaje] != ' ' && kLineaLeer[bucle_lenguaje] != '\n') {
          elemento_devolver = elemento_devolver + kLineaLeer[bucle_lenguaje];
          ++decimales_lenguaje;
        } else {
          posicion_leer = posicion_leer + decimales_lenguaje + 2;  // como es un lenguaje sumamos las posiciones para llegar al siguiente dato en la siguiente llamada a la función y le sumamos dos contando el espacio
          return elemento_devolver;
        }
      }
      

    } else {  // si no es un lenguaje ni un operador almacenamos el número que es probable que pertenezca a un posible operador *
      if (elemento_devolver != ' ') {
        numero_obtenido = numero_obtenido + elemento_devolver;
      }

    }
    ++posicion_leer;
  }

  return "Fallo en la sintaxis de las operaciones";   // si no encuentra ningún operador o lenguaje devuelve un fallo
}

// metodo que realiza la notacion polaca inversa y devuelve el lenguaje resultante
Lenguaje RPNLenguajes(const std::vector<Lenguaje>& kVectorLenguaje,  const std::string& kLineaLeer) {
  int posicion_actual{0};
  std::string elemento_comprobar;  // elemento para comprar si es un lenguaje o un operador
  std::stack<Lenguaje> pila_principal;   // pila donde guardaremos los lenguajes
  Lenguaje lenguaje_operar;   // lenguaje util para operar en la pila

  do {
    elemento_comprobar = SacaOperarcionesRPN(kLineaLeer, posicion_actual);  // emtemos el lemento en la string para operar más facilmente
    if (EsOperador(elemento_comprobar[0]) == false) {   // si es un lenguaje
      pila_principal.push(kVectorLenguaje[stoi(elemento_comprobar) - 1]);  // metemos el lenguaje en el vector(ponemos un -1 porque estamos trabajando con vectores que empiezan en 0)

    } else {    // si es un operador
      if (EsOperador(elemento_comprobar[0]) == true) {    // nos aseguramos de que sea un operando
          if (elemento_comprobar == "+" && pila_principal.size() >= 2) {   //---------------CONCATENACION-------------//
            lenguaje_operar.SetLenguaje(pila_principal.top()); // ponemos el primer lenguaje a operar
            pila_principal.pop();
            lenguaje_operar.SetLenguaje(pila_principal.top() + lenguaje_operar);  // operamos los dos lenguajes
            pila_principal.pop();
            pila_principal.push(lenguaje_operar);   // metemos en la pila el nuevo lenguaje habiendo quitado los otros dos

          } else if (elemento_comprobar == "-" && pila_principal.size() >= 2) {    //------------DIFERENCIA-------------//
            lenguaje_operar.SetLenguaje(pila_principal.top()); // ponemos el primer lenguaje a operar
            pila_principal.pop();
            lenguaje_operar.SetLenguaje(pila_principal.top() - lenguaje_operar);  // operamos los dos lenguajes 
            pila_principal.pop();
            pila_principal.push(lenguaje_operar);   // metemos en la pila el nuevo lenguaje habiendo quitado los otros dos

          } else if (elemento_comprobar == "^" && pila_principal.size() >= 2) {   //----------INTERSECCION----------//
            lenguaje_operar.SetLenguaje(pila_principal.top()); // ponemos el primer lenguaje a operar
            pila_principal.pop();
            lenguaje_operar.SetLenguaje(pila_principal.top() ^ lenguaje_operar);  // operamos los dos lenguajes
            pila_principal.pop();
            pila_principal.push(lenguaje_operar);   // metemos en la pila el nuevo lenguaje habiendo quitado los otros dos

          } else if (elemento_comprobar == "|" && pila_principal.size() >= 2) {  //--------------UNION---------------//
            lenguaje_operar.SetLenguaje(pila_principal.top()); // ponemos el primer lenguaje a operar
            pila_principal.pop();
            lenguaje_operar.SetLenguaje(pila_principal.top() | lenguaje_operar);  // operamos los dos lenguajes
            pila_principal.pop();
            pila_principal.push(lenguaje_operar);   // metemos en la pila el nuevo lenguaje habiendo quitado los otros dos

          } else if (elemento_comprobar[0] == '*' && pila_principal.size() >= 1) {   //-----------POTENCIA-----------//
            lenguaje_operar.SetLenguaje(pila_principal.top()); // ponemos el primer lenguaje a operar
            pila_principal.pop();
            std::string pasar_potencia;  // cremaos una string para poder pasarlo a entero
            for (int bucle_potencia{1}; bucle_potencia < elemento_comprobar.length(); ++bucle_potencia) {   // metemos todas las cifras en la string emepezando desde la segunda posicion
              pasar_potencia = pasar_potencia + elemento_comprobar[bucle_potencia];
            }
            int potencia{stoi(pasar_potencia)};
            pila_principal.push(lenguaje_operar * potencia);   // metemos en la pila el nuevo lenguaje con la potencia hecha

          } else if(elemento_comprobar == "!" && pila_principal.size() >= 1) {   //-------------INVERSA--------------//
            lenguaje_operar.SetLenguaje(pila_principal.top());
            pila_principal.pop();
            pila_principal.push(!lenguaje_operar);  // hacemos la inversa y lo metemos en la pila

          } else {  // si da un error terminamos el programa de longitud
          std::cout << "ERROR: Operandos insuficientes en la expresion" << std::endl;
          exit(EXIT_SUCCESS);
        }                                    
      }
    }
  } while(posicion_actual < kLineaLeer.length()); // mientras siga habiendo fichero que leer seguimos operando

  Lenguaje lenguaje_final;
  if (pila_principal.size() == 1) {  // comprobamos si solo hay un elemento en la pila
    lenguaje_final.SetLenguaje(pila_principal.top());
  } else {
    std::cout << "ERROR: ERROR: Expresion incorrecta." << std::endl;
    exit(EXIT_SUCCESS);
  }
  return lenguaje_final;
}  


//--------------SACAR-LENGUAJES-----------------//
// metodo que te saca el lenguaje de una string dada en un formato válido
Lenguaje SacaLenguajeString(const std::string kStringSacarLenguaje) {
  std::vector<std::string> vector_elementos;
  std::string elemento_meter;
  for (int bucle1{0}; bucle1 < kStringSacarLenguaje.length(); ++bucle1) {   // sacamos todos los elementos separados por espacios y eliminamos las comas
    if (kStringSacarLenguaje[bucle1] == ' ' || kStringSacarLenguaje[bucle1] == '}') {   // si es un espacio o un fin de llave metemos la palabra en el vector
      vector_elementos.push_back(elemento_meter);
      elemento_meter = "";  // reiniciamos la string
    } else {
      if (kStringSacarLenguaje[bucle1] != ',' && kStringSacarLenguaje[bucle1] != '{') {  // si no es una coma o una llave lo metemos en la string
        elemento_meter = elemento_meter + kStringSacarLenguaje[bucle1];
      }
    }
  }
  Lenguaje lenguaje_entregar; 
  Simbolo simbolo_entregar;  // simbolo para crear la cadena
  Cadena cadena_entregar;   // cadena para ir añadiendo al lenguaje
  bool lenguaje_encontrado{false};  // se pone en true cuando se encuentra la llave abierta del lenguaje para empear a meterlo
  for (int bucle2{0}; bucle2 < vector_elementos.size(); ++bucle2) {
    if (lenguaje_encontrado == true) {
      if (vector_elementos[bucle2] != "") {
        simbolo_entregar.SetSimbolo(vector_elementos[bucle2]);
        cadena_entregar.SetCadena(simbolo_entregar);
        lenguaje_entregar.AnadirLenguaje(cadena_entregar);
      }
    }
    if (vector_elementos[bucle2] == "=") {  // comprobamos que a partir del igual empieza el lenguaje(debido a que el bucle anterior nos quito las llaves y comas)
      lenguaje_encontrado = true;
    }
  }
  return lenguaje_entregar;
}

// metodo que dice si un carácter se encuentra en la string
bool EncuentraSimbolo(const std::string& kPalabraComprobar, const char& kCaracterComprobar) {
  for (int bucle{0}; bucle < kPalabraComprobar.size(); ++bucle) {
    if (kPalabraComprobar[bucle] == kCaracterComprobar) {  // si se encuentra el carácter se dice que si esta y no se sigue mirando
      return true;
    }
  }
  return false;
}