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

#include "lenguaje.h"


// constructor de la clase apartir de una cadena
Lenguaje::Lenguaje(const Cadena& kCadenaAnadir) {
  lenguaje_.insert(kCadenaAnadir);
}  

// constructor de la clase con un vector
Lenguaje::Lenguaje(const std::vector<Cadena>& kVectorCadenaAnadir) {
  for (int bucle{0}; bucle < kVectorCadenaAnadir.size(); ++bucle) {
    lenguaje_.insert(kVectorCadenaAnadir[bucle]);
  }
}  

// constructor por defecto de la clase que no hace nada
Lenguaje::Lenguaje() {
  lenguaje_.clear();
}

// getter que devuelve un vector de cadenas
std::vector<Cadena> Lenguaje::GetLenguaje() const {
  std::vector<Cadena> vector_entregar;
  for (Cadena bucle : lenguaje_) {   // para rellenar el vector con las posibles posiciones a elegir
    vector_entregar.push_back(bucle);
  }
  return vector_entregar;
}  

// setter que modifica la clase
void Lenguaje::SetLenguaje(const Lenguaje& kLenguajeCambiar) {
  lenguaje_.clear();   // limpiamos el lenguaje
  for (auto bucle : kLenguajeCambiar.GetLenguaje()) {  // recorremos el nuevo lenguaje para ir metiendolo en el antiguo
    lenguaje_.insert(bucle);
  }
}  

// te da una cadena en una determinada posicion del lenguaje
Cadena Lenguaje::AtLenguaje(const int kPosicion) const {
    if (kPosicion < LongitudLenguaje() && kPosicion >= 0 ) {   // comprobamos si estamos accediendo a un elemento existente del vector
    int posicion_actual{0};  // variable para contar cuantas veces estamos iterando el bucle y compararla para ver cuando paramos
    Cadena cadena_entregar;
    for (Cadena bucle : lenguaje_) {   // para rellenar el vector con las posibles posiciones a elegir
      if (posicion_actual == kPosicion) {   // si ya llegaste a la posicion que querias te da la cadena y se saltan las demás iteraciones
        cadena_entregar.SetCadena(bucle);
        break;
      }
      ++posicion_actual;
    }
    return cadena_entregar;

  } else {  // si no está dentro del tamaño indicado devolvemos la cadena vacía
    Simbolo simbolo_vacio{""};
    Cadena cadena_vacia{simbolo_vacio};
    return cadena_vacia;
  }
}

// devuelve la cantidad de cadenas del lenguaje
int Lenguaje::LongitudLenguaje() const {
  return lenguaje_.size();
}

// Método para añadir una cadena en el lenguaje
void Lenguaje::AnadirLenguaje(const Cadena& kCadenaAnadir) {
  lenguaje_.insert(kCadenaAnadir);
}

// comprueba si una determinada cadena está en el lenguaje
bool Lenguaje::ExisteCadenaLenguaje(const Cadena& kCadenaComprobar) const {
  bool existencia_cadena{false};
  for (auto bucle : lenguaje_) {  // recorremos el conjunto en busca de la cadena
    if (kCadenaComprobar.GetCadenaStr() == bucle.GetCadenaStr()) {  // si son iguales ponemos la variable existencia_cadena en true y salimos del bucle
      existencia_cadena = true;
    }
  }
  return existencia_cadena;
}

// elimina una cadena dada del lenguaje
void Lenguaje::EliminaCadena(const Cadena& kCadenaEliminar) {
  if (ExisteCadenaLenguaje(kCadenaEliminar) == true) {   // si existe la cadena en lenguaje podemos eliminarla
    lenguaje_.erase(lenguaje_.find(kCadenaEliminar));
  }
} 

// comprueba que el lenguaje se puede formar con el alfabeto
bool Lenguaje::LenguajePertenceAlfabeto(const Alfabeto& kAlfabeto) {
  bool pertenencia_alfabeto{true};   // suponemos que si pertenece y, en caso contrario, lo negamos
  for(auto bucle : lenguaje_) {
    if (kAlfabeto.CadenaPertenceAlfabeto(bucle) == false) {  // desde que una cadena no pertenezca al alfabeto es lenguaje no pertenece
      pertenencia_alfabeto = false;
    }
  }
  return pertenencia_alfabeto;
}


//------------------Sobrecarga-Operadores------------------//
// sobrecarga del operador de inserción en flujo para mostrar el alfabeto
std::ostream& operator<<(std::ostream& out, const Lenguaje& kLenguajeMostrar) {
  out << "{ ";
  for (auto bucle : kLenguajeMostrar.GetLenguaje()) {
    out << bucle << " ";
  }
  out << "}";
  return out;
}

// metodo que dice si la primera cadena esta antes( alfabeticamente hablando) que la segunda cadena
bool CalculaEnOrdenAlfabeticoCadenas(const Cadena& cadena_comparar1, const Cadena& cadena_comparar2) {
  int tamano_cadena_minima;  
  if (cadena_comparar1.Longitud() <= cadena_comparar2.Longitud()) {   // comprobamos que cadena es la que tiene menor tamano
    tamano_cadena_minima = cadena_comparar1.Longitud();
  } else {
    tamano_cadena_minima = cadena_comparar2.Longitud();
  } 

  for (int bucle{0}; bucle < tamano_cadena_minima; ++bucle) {
    if (int(cadena_comparar1.GetCadenaStr()[bucle]) < int(cadena_comparar2.GetCadenaStr()[bucle])) {   // si la letra del primero es menor(alfabeticamente) que la del segundo
      return true;
    }
    if (int(cadena_comparar2.GetCadenaStr()[bucle]) < int(cadena_comparar1.GetCadenaStr()[bucle])) {   // si la letra del segundo es menor(alfabeticamente) que la del primero
      return false;
    } 
  }

  if (cadena_comparar1.Longitud() == tamano_cadena_minima) { // si la primera cadena fue la menor y paso el bucle siendo todos sus caracteres iguales, significa que la menor(alfabeticamente)
    return true;   
  } else {  // si la segunda cadena fue la menor y paso el bucle siendo todos sus caracteres iguales, significa que la menor(alfabeticamente)
    return false;
  }

}

// sobrecarga del operador < para la clase set
bool operator<(const Cadena& cadena_comparar1, const Cadena& cadena_comparar2) {
    if(cadena_comparar1.Longitud() < cadena_comparar2.Longitud()) {
    return true;
  } else if((cadena_comparar1.Longitud() == cadena_comparar2.Longitud()) && cadena_comparar1.GetCadenaStr() != cadena_comparar2.GetCadenaStr()) {  // si es distinta cadena pero misma longitud es verdadero
    return CalculaEnOrdenAlfabeticoCadenas(cadena_comparar1, cadena_comparar2);
  }
  return false;   // si es la misma cadena(el último caso que queda) retorna falso
} 


// metodo que devuelve el lenguaje concatenado con otro por parámetros
Lenguaje Lenguaje::Concatenacion(const Lenguaje& kLenguajeOperar) const {
  Lenguaje lenguaje_concatenacion;
  Cadena cadena_anadir;
  for (auto bucle1 : lenguaje_) {  // recorremos el primer conjunto buscando las primeras partes de la cadena
    for (auto bucle2 : kLenguajeOperar.GetLenguaje()) {    // recorremos el segundo conjunto formando las nuevas cadenas
      cadena_anadir.ResetCadena();   // reseteamos la cadena para evitar que se sobreescriba
      cadena_anadir.ConcatenarDelante(bucle1.GetCadenaSim());
      cadena_anadir.ConcatenarDelante(bucle2.GetCadenaSim());
      lenguaje_concatenacion.AnadirLenguaje(cadena_anadir);
    }
  }
  return lenguaje_concatenacion;
} 


// metodo que devuelve la union del lenguaje con otro por parámetros
Lenguaje Lenguaje::Union(const Lenguaje& kLenguajeOperar) const {
  Lenguaje lenguaje_union;
  for (auto bucle1 : lenguaje_) {   // metemos todos lo elementos del primer lenguaje
    lenguaje_union.AnadirLenguaje(bucle1);
  }
  for (auto bucle2 : kLenguajeOperar.GetLenguaje()) {   // metemos todos los elementos del segundo lenguaje(como es un conjunto no se van a repetir)
    lenguaje_union.AnadirLenguaje(bucle2);
  }
  return lenguaje_union;
}


// metodo que devuelve la interseccion del lenguaje con otro por parámetros
Lenguaje Lenguaje::Interseccion(const Lenguaje& kLenguajeOperar) const {
  Lenguaje lenguaje_interseccion;
  for (auto bucle : lenguaje_) {   // recorremos solo un conjunto porque la interseccion esta en los dos y comprobamos si en el otro está también
    if (kLenguajeOperar.ExisteCadenaLenguaje(bucle) == true) {   
      lenguaje_interseccion.AnadirLenguaje(bucle);
    }
  }
  return lenguaje_interseccion;
}


// metodo que devuelve la diferencia del lenguaje con otro por parámetros
Lenguaje Lenguaje::Diferencia(const Lenguaje& kLenguajeOperar) const {
  Lenguaje lenguaje_diferencia;
  for (auto bucle : lenguaje_) {
    if (kLenguajeOperar.ExisteCadenaLenguaje(bucle) == false) {    // si está en los dos conjunto no se añade porque se restan
      lenguaje_diferencia.AnadirLenguaje(bucle);
    }
  }
  return lenguaje_diferencia;
}


// metodo que devuelve la inversa del lenguaje
Lenguaje Lenguaje::Inversa() const {
  Lenguaje lenguaje_inversa;
  for (auto bucle : lenguaje_) {
    lenguaje_inversa.AnadirLenguaje(bucle.Inversa());   // metemos la inversa de cada cadena del lenguaje
  }
  return lenguaje_inversa;
}


// metodo que devuelve la potencia del lenguaje segun un indice dado
Lenguaje Lenguaje::Potencia(const int kPotencia) const {
  Lenguaje lenguaje_potencia;  // lenguaje donde se añadiran las potencias
  if (kPotencia > 0) {   // si es una potencia en la cual se puede hacer la operacion
    lenguaje_potencia.SetLenguaje(GetLenguaje());
    Lenguaje lenguaje_concatenar{GetLenguaje()};   // lenguaje para ir concatenando las potencias
    for (int bucle{0}; bucle < kPotencia - 1; ++bucle) {   // vamos concatenando y haciendo la potencia hasta un numero dado (el -1 es porque partimos siempre de la primera potencia)
      lenguaje_potencia.SetLenguaje(lenguaje_potencia.Concatenacion(lenguaje_concatenar));   // voy concatenando y lo meto en el lenguaje_potencia
    }
  } else {   // si la potencia es 0 el lenguaje tiene una cadena vacía
    Simbolo simbolo_vacio{""};
    Cadena cadena_vacia{simbolo_vacio};
    lenguaje_potencia.AnadirLenguaje(cadena_vacia);
  }
  return lenguaje_potencia;
}   




// ----------------------------- MODIFICACIÓN DE CLASE ---------------------------------

