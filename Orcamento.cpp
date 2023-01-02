#include "Orcamento.hpp"
 
 void Orcamento::insereProduto(Produto* _produto, int qtd){carrinho.emplace(_produto,qtd);
 this->valor_total=calculatotal();
 }

 void Orcamento::removeProduto(Produto* _produto){
  for (auto it = carrinho.begin(); it != carrinho.end(); it++) {
    if (it->first->getNome() == (_produto->getNome())) {
      carrinho.erase(it);
      break;
    }
  }
  this->valor_total=calculatotal();
 }

 float Orcamento::calculatotal(){
    float outp=0;
    for (auto it = carrinho.begin(); it != carrinho.end(); it++) {
    outp += (it->first->getValorvenda())*(it->second);
    }
    return outp;
 }

 Orcamento::Orcamento(Cliente* _cliente, Data _data){
    this->data = _data;
    this->cliente=_cliente;
    this->valor_total=0;

 }

void Orcamento::print(){
  std::cout<<"Orçamento: "<<"\n"<<"data: ";
  std::cout<<this->data.getData()<<"\n";
  std::cout<<"Cliente: "<<this->cliente->getNome()<<"\n";
  std::cout<<"Produtos: "<<"\n";
  for (auto it = carrinho.begin(); it != carrinho.end(); it++) {
  std::cout<<it->first->getNome()<<"   x"<<it->second<<"\n";
  }
  std::cout<<"Valor a ser pago: "<<"   :"<<this->valor_total<<"\n";
}
