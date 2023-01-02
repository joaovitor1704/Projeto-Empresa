#ifndef PRODUTO_H
#define PRODUTO_H
#include <string>
#include <list>
#include <map>
#include <iostream>
#include "Data.h"
#include "MateriaPrima.hpp"

class Produto {
  private:
std::string nome;
float valorvenda;
int codigo;
int lotemin;
int estoquemin;
std::list<int> lotes;
std::map<Data,float> hist_valor;
std::map<MateriaPrima*,unsigned>materiasprimas;

public:
Produto(std::string nome,float valorvenda, int codigo, int lotemin, int estoquemin,std::map<MateriaPrima*,unsigned> materiasprima);
  int ChecaQtd();
  void alteraQtd(int qtd);
  bool verificaEstoquemin();
  std::string getNome() const;
  void setNome(const std::string _nome);
  int getCodigo() const;
  void setCodigo(const int codigo);
  int getLotemin() const;
  void setLotemin(const int lotemin);
  int getEstoquemin() const;
  void setEstoquemin(const int estoquemin);
  float getValorvenda() const;
  void setValorvenda(const float valorvenda, unsigned ano, unsigned mes, unsigned dia);
  void insereLotes(int qtd);
  void print();
  void print_hist();
  void verificaMp();
  
};
#endif
