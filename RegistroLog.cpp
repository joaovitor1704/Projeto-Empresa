#include "RegistroLog.hpp"

RegistroLog *RegistroLog::ptrRegLog = 0;

RegistroLog *RegistroLog::instRegLog() {
  if(ptrRegLog == 0)
    ptrRegLog = new RegistroLog;
  return ptrRegLog;
}

void RegistroLog::printLogs() {
  std::vector<LogAcessoNegado>::iterator itrAcNeg = vecLogAcNeg.begin();
  std::vector<LogLeitura>::iterator itrLeitura = vecLogLeitura.begin();
  std::vector<LogEscrita>::iterator itrEscrita = vecLogEscrita.begin();
  while(itrAcNeg != vecLogAcNeg.end())
    (itrAcNeg ++)->print();
  while(itrLeitura != vecLogLeitura.end())
    (itrLeitura ++)->print();
  while(itrEscrita != vecLogEscrita.end())
    (itrEscrita ++)->print();
}