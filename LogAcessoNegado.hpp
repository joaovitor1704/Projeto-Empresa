#ifndef LogAcNeg_H
#define LogAcNeg_H

#include "Log.hpp"
#include <list>

class LogAcessoNegado : public Log {
  private:
    std::string funcionalidade;
    virtual void metodoAbstrato() {};
  public:
    LogAcessoNegado(Usuario *_usuario, std::string _entidade, std::string _funcionalidade)
                     : Log(_usuario, _entidade), funcionalidade(_funcionalidade) {};
    std::string getFuncionalidade();
    void print() override;
};

#endif