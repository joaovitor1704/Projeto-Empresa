#include "Estoque.hpp"
#include "Usuario.hpp"
#include "Log.hpp"


Estoque *Estoque::instptrEstoque = 0;


Estoque *Estoque::instEstoque() {
  if(instptrEstoque == 0)
    instptrEstoque = new Estoque;
  return instptrEstoque;
}

void Estoque::adicionaProduto(Produto *p) { produtos_estoque.push_back(p);
    RegistroLog::instRegLog()->vecLogEscrita.push_back(LogEscrita(Usuario::instUsuario(), "Estoque",
                                                                      Data::dateNow(), "Adiciona produto " + p->getNome()));
}

void Estoque::adicionaOrdem(OrdemDeProd *op, Produto _p) { ordemdeprod.emplace(op,_p); }

void Estoque::removeProduto(Produto *p) {
  std::vector<Produto *>::iterator it;
  for (it = produtos_estoque.begin(); it != produtos_estoque.end(); it++) {
    if ((*it)->getNome() == (p->getNome())) {
      produtos_estoque.erase(it);
      break;
    }
  }
}


bool Estoque::verificaEstoquemin(Produto *_produto, unsigned _ano, unsigned _mes, unsigned _dia) {
  RegistroLog::instRegLog()->vecLogLeitura.push_back(LogLeitura(Usuario::instUsuario(), "Estoque", __FUNCTION__));
  if (_produto->verificaEstoquemin() == 1) {
    return true;
  } else {
    
    int aux=_produto->getEstoquemin()-_produto->ChecaQtd();
    emiteOrdem( _ano, _mes, _dia,aux,_produto);
    return false;
  }
}

OrdemDeProd Estoque::emiteOrdem(unsigned _ano, unsigned _mes, unsigned _dia, int _qtd,Produto *_produto) {
    RegistroLog::instRegLog()->vecLogEscrita.push_back(LogEscrita(Usuario::instUsuario(), "Estoque",
                                                            
  Data::dateNow(), "Emite uma ordem de producao do produto " + _produto->getNome()));
  
  OrdemDeProd *op = new OrdemDeProd(_ano, _mes, _dia,_qtd,_produto);
  adicionaOrdem(op, *_produto);
  return *op;
  
}



void Estoque::print(){
 std::vector<Produto *>::iterator it;
 std::cout<<"Produtos em Estoque:";
 std::cout<<"\n";
  for (it = produtos_estoque.begin(); it != produtos_estoque.end(); it++) {
  (*it)->print();
  std::cout<<"\n";
}
 std::cout<<"\n";
}

void Estoque::print_op()const{
  std::cout<<"Ordens de Produção registradas:";
 std::cout<<"\n";
 
  for(auto it=ordemdeprod.begin();it!=ordemdeprod.end();it++){
  std::cout<<"Nome:"<<it->second.getNome();
  std::cout<<"\n";
  std::cout<<"Código:"<<it->second.getCodigo();
  std::cout<<"\n";
  std::cout<<*it->first;
  std::cout<<"\n"; 
}
 std::cout<<"\n";
}
