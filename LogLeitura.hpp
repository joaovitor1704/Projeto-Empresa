#ifndef LogLeitura_H
#define LogLeitura_H

#include "Data.h"
#include "Log.hpp"
#include <list>

class LogLeitura: public Log {

private:
  std::string informacao;
  virtual void metodoAbstrato() {};

public:
  LogLeitura(Usuario *_usuario, std::string _entidade, std::string _informacao)
              : Log(_usuario, _entidade), informacao(_informacao) {};
  std::string getInformacao();
  void print() override;
};

#endif

