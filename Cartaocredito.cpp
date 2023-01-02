#include "Cartaocredito.hpp"

Cartaocredito::Cartaocredito(unsigned _numParcelas, float _valorTotal){
 this->numParcelas= _numParcelas;
 this->valorTotal= _valorTotal;
 this->valorParcela= _valorTotal / _numParcelas;
 this->efetuado= false;
} 

Cartaocredito::Cartaocredito(){};

void Cartaocredito::efetuarPagamento(){
  this->efetuado=true;
  this->dataPagamento=dataPagamento.dateNow();
}
   
Data Cartaocredito::getDataPagamento(){
 return dataPagamento;    
}

float Cartaocredito::getValorTotal(){
  return valorTotal;
}

float Cartaocredito::getValorParcela(){
 return valorParcela;
}

unsigned Cartaocredito::getNumParcelas(){
  return numParcelas;
}

void Cartaocredito::print(){
 std::cout<<endl<<"Valor total: R$"<<this->getValorTotal();
 std:: cout<<endl<<"Parcelas: "<<this->getNumParcelas(); 
 std::cout<<endl<<"Valor da parcela: R$"<<this->getValorParcela();
 if(this->efetuado==true){
   std::cout<<endl<<"Pagamento ja efetuado!"<<endl;
   std::cout<<"Data do pagamento: ";
   this->dataPagamento.printData();
 }else{
   std::cout<<endl<<"Pagamento ainda nao efetuado."<<endl;
 }
 
}