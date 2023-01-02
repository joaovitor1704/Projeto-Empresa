#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>
#include <map>
#include "Pessoa.hpp"
#include "Data.h"
#include "Cargo.hpp"
#include "Alteracao.hpp"
#include "Usuario.hpp"
#include "ExcecaoAcessoNegado.hpp"
#include "Turno.hpp"

class Funcionario : public Pessoa {
  private:
    std::pair<float, float> endereco;
    unsigned int matricula;
    Data nascimento;
    Cargo *cargo;
    float salario;
    Status status;
    std::map<Data, Alteracao> histAlt;
    virtual void metodoAbstrato() {}
    static unsigned int qtd;
    Turno *turno;

public:
  Funcionario(TipoPessoa _tipo, std::string _cadastro, std::string _nome, std::string _email,
                std::pair<float, float> _endereco, Data _nascimento, Cargo *cargo, Data dataCriacao, float salario,Turno *t);
  void aplicaDissidio(Data data, float _novoSalario);
  void promover(unsigned ano, unsigned mes, unsigned dia, Cargo *_novoCargo, float _novoSalario);
  void promover(Data data, Cargo *_novoCargo, float _novoSalario);
  void contratar(unsigned ano, unsigned mes, unsigned dia, Cargo *_novoCargo, float _novoSalario);
  void contratar(Data data, Cargo *_novoCargo, float _novoSalario);
  void demitir(unsigned ano, unsigned mes, unsigned dia);
  void demitir(Data data);
  std::map<Data, Alteracao> getHistAlt();
  std::pair<float, float> getEndereco() const;
  void setEndereco(const std::pair<float, float> _endereco);
  int getMatricula() const;
  Data getNascimento() const;
  void setNascimento(const Data _nascimento);
  Cargo *getCargo() const;
  float getSalario() const;
  Status getStatus() const;
  virtual ~Funcionario() {};
  Turno getTurno();
};

#endif