#ifndef RL_H
#define RL_H

#include "LogAcessoNegado.hpp"
#include "LogLeitura.hpp"
#include "LogEscrita.hpp"

class RegistroLog {
    RegistroLog() {};
    static RegistroLog *ptrRegLog;
  public:
    std::vector<LogAcessoNegado> vecLogAcNeg;
    std::vector<LogLeitura> vecLogLeitura;
    std::vector<LogEscrita> vecLogEscrita;
    static RegistroLog *instRegLog();
    void printLogs();
};

#endif