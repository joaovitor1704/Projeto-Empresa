#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

#include <string>
#include <vector>
#include "Funcionario.hpp"
#include "Usuario.hpp"

class Departamento {
private:
  std::string nome;
  std::vector<Funcionario*> pessoal;

public:
  Departamento(std::string Nome);
  void adicionarFuncionario(Funcionario *f);
  bool retirarFuncionario(const Funcionario *f);
  std::vector<Funcionario*> getFuncionarios();
  std::string getNome() const;
  void setNome(const std::string _nome);
};

#endif