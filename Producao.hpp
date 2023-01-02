#ifndef PRODUCAO_H
#define PRODUCAO_H
#include "Produto.hpp"
#include "Data.h"

class Producao {
  private:
  
    Data data;
    int qtd;
    Produto *produto;

  public:
    Producao(Data _data, int quantidade, Produto *prod);

};

#endif