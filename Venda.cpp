#include "Venda.hpp"

Venda::Venda(Cliente *_cliente, Produto *_produto, int _qtd, Data _data) {
  this->cliente = _cliente;
  this->produto = _produto;
  this->qtd = _qtd;
  this->data = _data;
  efetuaVenda(_data);
}

bool Venda::verificaEstoque(int _qtd) {
  if (this->produto->ChecaQtd() >= _qtd) {
    return true;
  } else {
    return false;
  }
}

void Venda::efetuaVenda(Data data) {
  if (verificaEstoque(this->qtd)) {
      this->produto->alteraQtd(this->qtd);
      Estoque::instEstoque()->verificaEstoquemin(this->produto, data.getAno(), data.getMes(), data.getDia());
  }
}