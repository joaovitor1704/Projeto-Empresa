#include "Boleto.hpp"

Boleto::Boleto(vencimentoBoleto _vencimento, float _valor ,unsigned int ano, unsigned int mes, unsigned int dia){
  this->efetuado= false;
  this->vencimento= _vencimento;
  this->valor= _valor;
  this->dataAbertura= Data(ano, mes, dia);
}


bool Boleto::boletoVencido(){
  
  Data x= dataAbertura.dateNow();
  if(vencimento==noventaDias){
     if( x.diffData(dataAbertura) > 90 ){
     return true;
   }else{
     return false;
   }
  }else if(vencimento==sessentaDias){
    if( x.diffData(dataAbertura) > 60 ){
     return true;
   }else{
     return false;
   }
  }else if(vencimento==trintaDias){
    if(x.diffData(dataAbertura) > 30 ){
     return true;
   }else{
     return false;
   }
  }else{
    return false;
  }
  
}

void Boleto::pagarBoleto(){
  if(this->boletoVencido()==false){
    this->efetuado=true;
    this->dataPagamento=dataAbertura.dateNow();
    std::cout<<endl<<"Pagamento efetuado com sucesso!"<<endl;
  }else{
    std::cout<<endl<<"Este boleto esta vencido, nao eh possivel efetuar o pagamento!";  
  }
}

Data Boleto::getDataAbertura(){
 return dataAbertura;   
}

Data Boleto::getDataPagamento(){
 return dataPagamento;
}

vencimentoBoleto Boleto::getVencimento(){
  return vencimento; 
}  

float Boleto::getValor(){
  return valor;
}

void Boleto::print(){
  std::cout<<endl<<"Valor do boleto: R$"<<this->getValor();
  std::cout<<endl<<"Data de abertura do boleto: ";
  this->dataAbertura.printData();
  
  if(this->getVencimento()==noventaDias){
    std::cout<<"Vencimento: 90 dias";
  }else if(this->getVencimento()==sessentaDias){
    std::cout<<"Vencimento: 60 dias";
  }else if(this->getVencimento()==trintaDias){
    std::cout<<"Vencimento: 30 dias";
  }

  if(this->pagamentoEfetuado()==true){
    std::cout<<endl<<"Boleto pago.";
    std::cout<<endl<<"Data de pagamento: ";
    this->dataPagamento.printData();
    std::cout<<endl;
  }else{
    std::cout<<endl<<"Boleto nao pago.";
    if(this->boletoVencido()==false){
     std::cout<<endl<<"Boleto nao vencido."<<endl;
    }else{
    std::cout<<endl<<"Boleto vencido."<<endl;
    }
  }
  
}
