  #ifndef PAIRT_H_
  #define PAIRT_H_

  #include <iostream>

  class alfabeto {
    public:

      alfabeto(string cadena);
      ~alfabeto(void) {}

      void set_Cadena(string cadena) {  //getter
        Cadena = cadena;
      }
      string get_Cadena() {  //setter
        return Cadena;
      }
    
      // E/S
      std::istream& read(std::istream& is = std::cin);
      std::ostream& write(std::ostream& on = std::cout) const;
  
    private:

      std::string cadena_;

   };


  // Constructor
  alfabeto::alfabeto(cadena_(cadena)) {};


  // Destructor
  alfabeto::~alfabeto() {}

  // Lectura
  std::istream& alfabeto::read(std::istream& is) {
    return is >> cadena_;
  }

  //Escritura
  std::ostream& alfabeto::write(std::ostream& os) const {
    return os << cadena_;
  }

  // Sobrecarga operador inserción
  std::ostream& operator<<(std::ostream& os, const alfabeto& p) {
  p.write(os);
  return os;
}

#endif  // PAIRT_H_