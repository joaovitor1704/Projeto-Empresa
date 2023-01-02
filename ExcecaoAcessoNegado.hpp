#ifndef ExcAcNeg_H
#define ExcAcNeg_H

#include <exception>
#include <string>
#include "Data.h"
#include "LogAcessoNegado.hpp"
#include "RegistroLog.hpp"

class ExcecaoAcessoNegado : public std::exception {
  private:
    std::string mensagem = "Acesso negado por permissao incompativel";
  public:
    ExcecaoAcessoNegado(Usuario *usuario, std::string entidade, std::string funcionalidade);
    virtual const char* what() const noexcept override { return this->mensagem.c_str(); }
};

#endif