// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnologíıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 9: Maquina de Turing
// Autor: Eduardo González Gutiérrez
// Correo: alu0101461588@ull.edu.es
// Fecha: 15/11/2023
// Archivo MaquinaTuring.cc: Implementación de la clase MaquinaTuring

#include "MaquinaTuring.h"

/**
 * @brief Construct a new TuringMachine_t::TuringMachine_t object. 
 * Leer el fichero tanto de la máquina de turing como el de la cinta.
 * Detectar si hay algún error.
 * 
 * @param nombrefichero1 
 * @param nombrefichero2 
 * @param error 
 */
MaquinaTuring::MaquinaTuring(char nombrefichero1 [],char nombrefichero2 [], bool& error) {
  std::string aux;

  // Leemos el fichero de la cadena de entrada y la guardamos en la cinta
  std::ifstream f_cinta(nombrefichero2);
  getline(f_cinta, Cinta_);

  // Leemos el fichero de la máquina de turing
  std::ifstream turing(nombrefichero1);

  // Leemos el número de estados
  turing >> numEstados_;
  getline(turing, aux); // Comprobamos que solo haya un valor en la línea

  if (!aux.empty()) {
    error = true;
    std::cout << "Error en la primera línea, hay más de un valor para indicar el número de estados" << std::endl;
    return;
  }

  // Leemos el estado de arranque
  turing >> EstadoArranque_;
  getline(turing, aux); // Comprobamos que solo haya un valor en la línea.

  if (!aux.empty()) {
    error = true;
    std::cout << "Error. Hay más de un estado de arranque" << std::endl;
    return;
  } 

  // Leemos el estado de aceptación
  turing >> EstadoAceptacion_;
  getline(turing, aux); // Comprobamos que solo haya un valor en la línea.

  if (!aux.empty()) {
    error = true;
    std::cout << "Error en la tercera línea. Hay más de un estado de aceptación" << std::endl;
    return;
  } 

  // Leemos el número de tuplas
  turing >> numTuplas_;
  getline(turing, aux); // Comprobamos que solo haya un valor en la línea.

  if (!aux.empty()) {
    error = true;
    std::cout << "Error en la cuarta línea. Hay más de un valor para indicar el número de Tuplas" << std::endl;
    return;
  }  
  
  Tuplas_.resize(numTuplas_); // Redimensionamos el vector de tuplas para que tenga el tamaño del número de tuplas.

  // Leemos las tuplas
  for (int i = 0; i < numTuplas_; i++) {
    // Identificador primer estado
    int identificador;
    turing >> identificador; 

    // Simbolo de entrada que se lee de la cinta
    Simbolo simbolo_entrada;
    char simbolo_leido;
    turing >> simbolo_leido;
    simbolo_entrada.setSimbolo(simbolo_leido);
        
    // Simbolo que se escribe en la cinta
    Simbolo simbolo_escribe;
    char leido;
    turing >> leido;
    simbolo_escribe.setSimbolo(leido);

    // Movimiento de la cabeza lectora (R, L o S)
    char movimiento;
    turing >> movimiento;
        
    // Identificador del siguiente estado
    int siguiente_estado;
    turing >> siguiente_estado;
        
    getline(turing, aux);

    // Comporbamos que no haya más vaores en la línea
    if (!aux.empty()) {
      error = true;
      std::cout << "Error en la definición de las tuplas. Hay más valores de los que debería" << std::endl;
      return;
    }  

    // Construimos la tupla
    Tuplas_.resize(numTuplas_);
    Tupla tupla_aux (identificador, simbolo_entrada, simbolo_escribe, movimiento, siguiente_estado);
    Tuplas_[i] = tupla_aux;
  }

  // Comprobamos que no haya más valores en el fichero
  getline(turing, aux);

  if (!aux.empty()) {
    error = true;
    std::cout << "Error en la definición del fichero de entrada. Hay más lineas de las que debería" << std::endl;
    return;
  } 
}

/**
 * @brief Mostrar la maquina de turing. 
 * Mostramos los valores enteros, y luego recorremos el vector de tuplas.
 * 
 */
void MaquinaTuring::MostrarMaquinaTuring() {
  std::cout << numEstados_ << std::endl;
  std::cout << EstadoArranque_ << std::endl;
  std::cout << EstadoAceptacion_ << std::endl;
  std::cout << numTuplas_ << std::endl;

  for (int j = 0; j < numTuplas_; j++){
    std::cout << Tuplas_[j].get_identificador() << " " << Tuplas_[j].get_entrada().getSimbolo() << " " << Tuplas_[j].get_escribe().getSimbolo() << " " << Tuplas_[j].get_movimiento() << " " << Tuplas_[j].get_sig_estado() << std::endl;
  } 

  std::cout << std::endl;
}

/**
 * @brief Creo una cinta nueva de tipo string con un símbolo vacío al principio y al final.
 * 
 * Busco el estado de arranque entre las declaraciones de las tuplas.
 * Si no he encontrado el estado de arranque entre las tuplas, devuelvo false.
 * Si lo he encontrado, busco la transicion del estado actual que contenga el símbolo de la cinta 
 * que estoy señalando con j. Al principio este valor es 1 y no 0 porque en 0 está el símbolo vacío.
 * La función que me busca la transicion, si me devuelve el numero de tuplas significa que el símbolo 
 * de la cinta no está definido en las transiciones del estado actual. 
 * 
 * A continuación, si no me ha devuelto el número de tuplas, escribo en la cinta el símbolo a escribir 
 * definido en la transición del estado actual y luego compruebo que movimiento realizo. 
 * Si es R, le sumo 1 a j, y si es L, le resto. Sin embargo, si es S, compruebo que el estado siguiente 
 * sea el de aceptación, y devuelvo true. Si no es así, devuelvo false. 
 * 
 * Luego, comparo el estado siguiente de mi estado actual, con todas las tuplas, y obtengo el siguiente
 * estado (la i, que es la posicion en el vector de tuplas) y establezco el estado actual.
 * 
 * Por último, muestro el recorrido.
 * 
 * @return true 
 * @return false 
 */
bool MaquinaTuring::SimularMT() { 
  bool id = false;
  std::string vacio = "$"; // Simbolo blanco
  std::string temporal = vacio + vacio + Cinta_ + vacio + vacio; // Inicio la cinta con simbolos blancos a derecha e izquierda

  int i = 0;
  for (int i = 0; i < numTuplas_; i++) {
    // Busco el estado de arranque entre las declaraciones de las tuplas
    if (EstadoArranque_ == Tuplas_[i].get_identificador()) {
      id = true;
      MostrarRecorrido(temporal, i + 2, EstadoArranque_); // +2 para colocarlo en el inicio de la cinta (sin contar los símbolos vacíos)
      i = numTuplas_;
      i++;
    }
  }

  int estado_actual = EstadoArranque_;
  unsigned j = 2; // 1 porque el primer y segundo valor es el símbolo vacío
  if (id == false) {
    return false;
  }
  else {
    while(i < numTuplas_) {
      i = BuscarTransicion(temporal[j], estado_actual);
      if (i == numTuplas_) {
        return false;
      }
      else {
        temporal[j] = Tuplas_[i].get_escribe().getSimbolo();
        if(Tuplas_[i].get_movimiento() == 'R'){
          j++;
        }
        else if(Tuplas_[i].get_movimiento() == 'L'){
          j--;
        }
        else{
          if(Tuplas_[i].get_sig_estado() == EstadoAceptacion_){
            MostrarRecorrido(temporal, j, Tuplas_[i].get_sig_estado());
            return true;
          }
          else{
            return false;
          }
        }
        for (int k = 0; k < numTuplas_; k++){
          if (Tuplas_[k].get_identificador() == Tuplas_[i].get_sig_estado()) {
            estado_actual = Tuplas_[i].get_sig_estado();
            i = k;
            k = numTuplas_; // parar de recorrer el for
            MostrarRecorrido(temporal, j, estado_actual);
          }
        }
      } 
    }
  }
  return false;
}


/**
 * @brief Metodo que muestra el recorrido que va realizando la Maquina de Turing.
 * 
 * @param temporal 
 * @param j 
 * @param estado_actual 
 */
void MaquinaTuring::MostrarRecorrido(std::string& cinta_temporal, unsigned j, int estadoActual){
  for (unsigned i = 0; i < j; i++) {
    std::cout << cinta_temporal[i];
  }

  std::cout << " q" << estadoActual << " ";
  
  for (unsigned i = j; i < cinta_temporal.size(); i++) {
    std::cout << cinta_temporal[i];
  }
  std::cout << std::endl;
}

/**
 * @brief Metodo que busca una tupla determinada.
 * Paso como parámetros el símbolo de la entrada y el estado_actual definido en id.
 * Recorro todas las tuplas, y cuando el identificador sea igual al id, compruebo si la
 * entrada de esta tupla coincide con la entrada que estoy buscando. Si es así, devuelvo
 * la posición de la tupla en el vector de tuplas. Si no es así sigo recorriendo las entradas
 * de la tupla con el identificador igual a id.
 * 
 * Si al terminar de recorrer las tuplas no encuentro la entrada que estoy buscando,
 * devuelvo el numero de tuplas, que sería una posición que no existe en mi vector.
 * 
 * @param ent 
 * @param id 
 * @return int 
 */
int MaquinaTuring::BuscarTransicion(char entrada, int id){
  for (int i = 0; i < numTuplas_; i++) {
    if (Tuplas_[i].get_identificador() == id) {
      if (Tuplas_[i].get_entrada() == entrada) {
        return i;
      }
    }
  }
  return numTuplas_; // si no encuentro la transicion devuelvo el número de tuplas, dicho valor no será ninguna posición del vector de tuplas
}

