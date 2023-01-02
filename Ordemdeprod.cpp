#include "Ordemdeprod.hpp"
#include <iostream>

OrdemDeProd::OrdemDeProd(unsigned _ano, unsigned _mes, unsigned _dia, int _qtd, Produto *_prod){
  this->data= Data(_ano, _mes, _dia) ;
  this->qtd=_qtd;
  produz(_prod);
}

Producao OrdemDeProd::produz( Produto *prod) {
  Producao p=Producao(this->data, this->qtd,prod);
  return p;
}


std::ostream& operator << (std::ostream& stream, const OrdemDeProd& it){
return stream << it.data.getData() <<": "<< it.qtd;
}
