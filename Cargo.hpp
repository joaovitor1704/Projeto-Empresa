#ifndef CARGO_H
#define CARGO_H

#include <string>
#include "Usuario.hpp"

class Cargo {
  private:
    std::string nome;
   
  public:
    Cargo(std::string _nome = "cargoNA");
    std::string getNome() const;
    void setNome(const std::string _nome);

};
#endif