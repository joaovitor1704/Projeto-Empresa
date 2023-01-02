#ifndef CARTAOCREDITO_H
#define CARTAOCREDITO_H
#include "Pagamento.hpp"
#include <iostream>

class Cartaocredito: public Pagamento{
  private:
   void metodoAbstrato() {}
   unsigned numParcelas;
   float valorTotal;
   float valorParcela;

  public:
   Cartaocredito(unsigned _numParcelas, float _valorTotal);
   void efetuarPagamento(); 
   Data getDataPagamento();
   float getValorTotal();
   float getValorParcela();
   unsigned getNumParcelas();
   void print();
   Cartaocredito();
    
 };

#endif