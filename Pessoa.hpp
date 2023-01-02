#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include "Usuario.hpp"
#include "ExcecaoAcessoNegado.hpp"

enum TipoPessoa { pFisica, pJuridica, tpInvalido };

class Pessoa {
  protected:
    TipoPessoa tipo;
    std::string cadastro, nome, email;
    virtual void metodoAbstrato() = 0;

  public:
    TipoPessoa getTipo() const;
    std::string getCadastro() const;
    std::string getNome() const;
    std::string getEmail() const;
    void setNome(const std::string _nome);
    void setEmail(const std::string _email);
};

#endif