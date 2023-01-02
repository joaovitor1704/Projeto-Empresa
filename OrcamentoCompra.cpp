#include "OrcamentoCompra.hpp"

OrcamentoCompra::OrcamentoCompra(unsigned qtd){
  this->qtdMaterial= qtd;
  this->qtdRespostas= 0;
  this->finalizado= false;
}

void OrcamentoCompra::aumentaQtdRespostas(){
  this->qtdRespostas += 1;
}

unsigned OrcamentoCompra::getQtdRespostas(){
  return qtdRespostas;
}
 
unsigned OrcamentoCompra::getQtdMaterial(){
  return qtdMaterial;
}

bool OrcamentoCompra::foiFinalizado(){
  return finalizado;
}