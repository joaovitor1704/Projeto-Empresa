#include "LogLeitura.hpp"

std::string LogLeitura::getInformacao() {
  return this->informacao;
}

void LogLeitura::print() {
  std::cout << "LogLeitura" << "; usuario: " << usuario->getNome() << "; data: " << data.getData()
              << "; entidade: " << entidade << "; informacao: " << informacao << std::endl;
}