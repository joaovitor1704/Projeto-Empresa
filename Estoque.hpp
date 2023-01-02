#ifndef ESTOQUE_H
#define ESTOQUE_H
#include <map>
#include <vector>
#include"Data.h"
#include"Ordemdeprod.hpp"
#include"Produto.hpp"
#include <iostream>


class Estoque {
  private:
    std::map<OrdemDeProd*,Produto> ordemdeprod;
    std::vector<Produto*> produtos_estoque;
     Estoque(){};
    static Estoque *instptrEstoque;

  public:
     void adicionaProduto(Produto* p);
    void removeProduto(Produto *p);
     void adicionaOrdem(OrdemDeProd *op, Produto _p);
    OrdemDeProd emiteOrdem(unsigned _ano, unsigned _mes, unsigned _dia, int _qtd, Produto *_produto);
    bool verificaEstoquemin(Produto *_produto, unsigned _ano, unsigned _mes, unsigned _dia);
    static Estoque *instEstoque();
    void print();
    void print_op()const;

};
#endif