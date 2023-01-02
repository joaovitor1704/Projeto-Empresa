#ifndef CLIENTE_H
#define  CLIENTE_H

#include <iostream>
#include "Pessoa.hpp"
#include "Usuario.hpp"

class  Cliente : public Pessoa {
private:
    std::string telefone;
    virtual void metodoAbstrato() {}

public:
  Cliente(std::string telefone, std::string nome, std::string cadastro,
          std::string email, enum TipoPessoa tipo);
  void setTelefone(const std::string _telefone);
  std::string getTelefone();
  virtual ~Cliente() {};
};

#endif