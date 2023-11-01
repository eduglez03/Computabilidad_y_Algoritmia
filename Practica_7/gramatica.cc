// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnologíıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 7: Forma Normal de Chomsky
// Autor: Eduardo González Gutiérrez
// Correo: alu0101461588@ull.edu.es
// Fecha: 02/11/2023
// Archivo gramatica.cc: Implementacion metodos clase Gramatica

#include "gramatica.h"

/**
 * @brief Construct a new Gramatica:: Gramatica object
 * 
 * @param gramatica 
 */
Gramatica::Gramatica(const Gramatica& gramatica) {
  noTerminales_ = gramatica.getNoTerminales();
  terminales_ = gramatica.getTerminales();
  inicial_= gramatica.getInicial();
  producciones_ = gramatica.getProducciones();
}

/**
 * @brief Construct a new Gramatica:: Gramatica object
 * 
 * @param fichero_entrada 
 */
Gramatica::Gramatica(const std::string& fichero_entrada) {
  std::ifstream fichero{fichero_entrada, std::ios_base::in};
  std::string linea;
  /// Simbolos terminales: 
  getline(fichero, linea);
  int num_terminales = stoi(linea);
  Alfabeto terminales;
  for (int i = 0; i < num_terminales; i++) {
    getline(fichero, linea);
    terminales.add(linea);
  }
  terminales_ = terminales;
  /// Simbolos no terminales:
  getline(fichero, linea);
  int num_no_terminales = stoi(linea);
  Alfabeto no_terminales;
  for (int i = 0; i < num_no_terminales; i++) {
    getline(fichero, linea);
    no_terminales.add(linea);
  }
  noTerminales_ = no_terminales;
  /// Simbolo de arranque:
  getline(fichero, linea);
  Simbolo inicial = linea;
  inicial_ = inicial;
  /// Producciones:
  getline(fichero, linea);
  int num_producciones = stoi(linea);
  set_pair producciones;
  std::string elem;
  for (int i = 0; i < num_producciones; i++) {
    getline(fichero, linea);
    std::stringstream nueva_linea(linea);
    pair produccion;
    /// Primera parte
    getline(nueva_linea, elem, ' ');
    produccion.first = elem;
    /// Ignoramos el "-->"
    //getline(nueva_linea, elem, ' ');
    /// Segunda parte
    getline(nueva_linea, elem, ' ');
    std::vector<Simbolo> simbolos;
    for (const auto& simbolo : elem) {
      simbolos.push_back(simbolo);
    }
    produccion.second = simbolos;
    producciones.insert(produccion);
  }
  producciones_ = producciones;
}

/** 
 *  @brief Esta función comprueba que:
 *            1. La gramática no tenga símbolos inútiles
 *            2. La gramática no tenga producciones inútiles
 *            3. La gramática no tenga producciones unitarias
 *            4. La gramática no tenga producciones vacías
 *                NOTA: Salvo que la tenga el incial
 *  @return Void, pero termina el programa si no se cumplen las condiciones 
 */
void Gramatica::Comprobar() {
  bool producciones_inutiles = false;
  bool simbolos_inutiles = false;
  bool producciones_unitarias = false;
  bool producciones_vacias = false;

  // Comprobamos las producciones vacías
  for (const auto& produccion : getProducciones()) {
    for (const auto& simbolo : produccion.second) {
      if ((simbolo == '&') and (produccion.first != getInicial())) {
        producciones_vacias = true;
        std::cout << "Se ha encontrado una produccion vacia en " << produccion.first << std::endl;
      }
    }
  }

  // Comprobamos las producciones unitarias
  for (const auto& produccion : getProducciones()) {
    if ((produccion.second.size() == 1) and (noTerminales_.Encontrar(produccion.second[0]))) {
      producciones_unitarias = true;
      std::cout << "Se ha encontrado una produccion unitaria en " << produccion.first << std::endl;
    }
  }

  // Comprobamos los símbolos inútiles
  for (const auto& terminal : getTerminales().getAlfabeto()) {
    bool usado = false;
    for (const auto& produccion : getProducciones()) {
      for (const auto& simbolo : produccion.second) {
        if (simbolo == terminal) usado = true;
      }
    }
    if (!usado) {
      simbolos_inutiles = true;
      std::cout << "No se ha usado el simbolo " << terminal << std::endl;
    }
  } 

  // Comprobamos las producciones inútiles
  for (const auto& terminal : getNoTerminales().getAlfabeto()) {
    bool usado = false;
    for (const auto& produccion : getProducciones()) {
      if (produccion.first == terminal) usado = true;
    }
    if (!usado) {
      producciones_inutiles = true;
      std::cout << "El simbolo " << terminal << " no tiene producciones" << std::endl;
    }
  } 
  if (producciones_inutiles or simbolos_inutiles or producciones_unitarias or producciones_vacias) {
    std::cout << "Arregle el fichero de entrada" << std::endl;
    exit(EXIT_SUCCESS);
  }
}

/** 
 *  @brief Devuelve la primera letra no usada
 *  @return char
 */
char ObtenerLetra() {
  for (int i = 0; i < int(kAlfabeto.size()); ++i) {
    if (!Usado[i]) {
      Usado[i] = true;
      return kAlfabeto[i];
    }
  }
  std::cout << "ADVERTENCIA: Ha usado mas de 26 letras" << std::endl;
  std::cout << "Los resultados podrian no ser los deseados" << std::endl;
  std::cout << "Simplifique su gramatica" << std::endl;
  return '?';
}

/** 
 *  @brief Nos prepara los ya usados del alfabeto
 *  @return void
 */
void PrepararkAlfabeto(const Alfabeto& alfabeto) {
  for (const auto& elem : alfabeto.getAlfabeto()) {
    for (int i = 0; i < int(kAlfabeto.size()); i++) {
      if (kAlfabeto[i] == elem) Usado[i] = true;
    }
  }
}

/** 
 *  @brief Constructor de copia
 *         NOTA: kAlfabeto contiene las letras del abecedario
 *         NOTA: Usada contiene las letras que ya hemos usado
 *  @return Gramática en forma normal de Chomsky
 */
Gramatica Gramatica::ConvertirToCNF() {
  Alfabeto CNF_no_terminales = getNoTerminales();
  PrepararkAlfabeto(CNF_no_terminales);
  Alfabeto CNF_terminales = getTerminales();
  Simbolo CNF_inicial = getInicial();
  set_pair CNF_producciones;

  /// PRIMERA: Cambiar los terminales
  char letra = ObtenerLetra();
  Alfabeto CNF_no_terminales_F1;
  /// Añadimos las nuevas producciones
  for (const auto& simbolo : getTerminales().getAlfabeto()) {
    std::string no_terminal;
    no_terminal = no_terminal + letra + simbolo.getChar();
    CNF_no_terminales_F1.add(no_terminal);
  }

  /// Cambiamos las viejas
  for (const auto& produccion : getProducciones()) {
    if (produccion.second.size() > 1) {
      pair nueva_produccion;
      nueva_produccion.first = produccion.first;
      std::vector<Simbolo> nuevos_simbolos;
      for (const auto& simbolo : produccion.second) {
        if (CNF_terminales.Encontrar(simbolo)) {
          std::string no_terminal;
          no_terminal = no_terminal + letra + simbolo.getChar(); 
          nuevos_simbolos.push_back(no_terminal);
        } else {
          nuevos_simbolos.push_back(simbolo);
        }
      }
      nueva_produccion.second = nuevos_simbolos;
      CNF_producciones.insert(nueva_produccion);
    } else {
      CNF_producciones.insert(produccion);
    }
  }

  /// SEGUNDA: Cambiar los no terminales
  set_pair producciones;
  Alfabeto no_terminales_F2;
  for (const auto& produccion : CNF_producciones) {
    int size = produccion.second.size();
    if (size > 2) {
      letra = ObtenerLetra(); 
      /// Creamos los nuevos no terminales 
      std::vector<Simbolo> simbolos_D;
      simbolos_D.push_back(produccion.first);
      for (int i = 0; i < size - 2; i++) {
        std::string no_terminal;
        no_terminal = no_terminal + letra + std::to_string(i);
        no_terminales_F2.add(no_terminal);
        simbolos_D.push_back(no_terminal);
      }

      /// Almacenamos de forma temporal
      std::vector<Simbolo> simbolos_B;
      for (const auto& simbolo : produccion.second) {
        simbolos_B.push_back(simbolo);
      }

      /// Creamos la nuevas producciones
      int size_D = simbolos_D.size() - 1;
      int counter_B = 0;
      for (int i = size_D; i > 0; --i) {
        pair nueva_produccion;
        nueva_produccion.first = simbolos_D[i - 1];
        std::vector<Simbolo> nuevos_simbolos;
        nuevos_simbolos.push_back(simbolos_B[counter_B]);
        nuevos_simbolos.push_back(simbolos_D[i]);
        nueva_produccion.second = nuevos_simbolos;
        producciones.insert(nueva_produccion);
        ++counter_B;
      }

      pair nueva_produccion;
      nueva_produccion.first = simbolos_D[size_D];
      std::vector<Simbolo> nuevos_simbolos;
      nuevos_simbolos.push_back(simbolos_B[counter_B]);
      nuevos_simbolos.push_back(simbolos_B[size_D + 1]);
      nueva_produccion.second = nuevos_simbolos;
      producciones.insert(nueva_produccion);
     } else {
      producciones.insert(produccion);
    }
  }

  /// Arreglamos los no terminales
  for (const auto& simbolo : CNF_no_terminales_F1.getAlfabeto()) {
    CNF_no_terminales.add(simbolo);
    pair nueva_produccion;
    nueva_produccion.first = simbolo;
    std::vector<Simbolo> nuevos_simbolos;
    nuevos_simbolos.push_back(simbolo.getSimbolo()[1]);
    nueva_produccion.second = nuevos_simbolos;
    producciones.insert(nueva_produccion);
  }
  for (const auto& simbolo : no_terminales_F2.getAlfabeto()) {
    CNF_no_terminales.add(simbolo);
  }

  /// Creamos la gramática
  Gramatica CNF_gramatica;
  CNF_gramatica.setTerminales(CNF_terminales); 
  CNF_gramatica.setNoTerminales(CNF_no_terminales);
  CNF_gramatica.setInicial(CNF_inicial);
  CNF_gramatica.setProducciones(producciones);
  return CNF_gramatica;
}

/** 
 *  @brief Escribe en un fichero la gramática de la siguiente forma:
 *               1. Número de símbolos del alfabeto.
 *                    1.1. Símbolo del alfabeto en cada línea.
 *               2. Número de símbolos no terminales.
 *                    2.1. Símbolo no terminales en cada línea.
 *               3. Símbolo de arranque.
 *               4. Número de producciones de la gramática.
 *                    4.1. Producción en cada línea.
 */              
void Gramatica::write(const std::string& kFichero_Entrada) {
  std::ofstream fichero{kFichero_Entrada};

  /// Símbolos del alfabeto
  fichero << terminales_.getAlfabeto().size() << std::endl;
  for (const auto& elem : terminales_.getAlfabeto()) {
    fichero << elem << std::endl;
  }

  /// Símbolos no terminales
  fichero << noTerminales_.getAlfabeto().size() << std::endl;
  for (const auto& elem : noTerminales_.getAlfabeto()) {
    fichero << elem << std::endl;
  }

  /// Símbolo de arranque
  fichero << inicial_ << std::endl;

  /// Producciones
  fichero << producciones_.size() << std::endl;
  for (const auto& elem : getProducciones()) {
    fichero << elem.first << " --> ";
    for (const auto& elem : elem.second) {
      fichero << elem;
    }
    fichero << std::endl;
  }
}