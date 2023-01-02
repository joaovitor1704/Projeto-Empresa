#pragma once
#include "Data.h"
#include "Cliente.hpp"
#include "Produto.hpp"
#include <map>

class Pedido;
class Empresa;

class Orcamento{
    
    public:
Orcamento(Cliente* _cliente, Data _data);
void insereProduto(Produto* _produto, int qtd);
void removeProduto(Produto* _produto);
float calculatotal();
void print();

    private:
std::map<Produto*,int>carrinho;
Data data;
Cliente* cliente;
float valor_total;
friend Pedido;
friend Empresa;
};
