#include "Categoria.hpp"


Categoria::Categoria(std::string nome){
    this->nome=nome;
}

void Categoria::insereProduto(Produto* p){
produtos_categoria.push_back(p);
}

std::string Categoria::getnome() const{ return this->nome;}

void Categoria::setNome(const std::string _nome){this->nome=_nome;}

void Categoria::removeProduto(Produto* p){
     std::vector<Produto*>:: iterator it;
    for(it=produtos_categoria.begin();it!=produtos_categoria.end();it++){
        if((*it)->getNome() == (p->getNome())){
          produtos_categoria.erase(it);
          break;
        }
    }
}