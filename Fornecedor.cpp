#include "Fornecedor.hpp"

void Fornecedor::adicionaOrcamento(OrcamentoCompra *orcamento) {
    respFornecedor.emplace(orcamento, -1);
}

void Fornecedor::calculaOrcamento(OrcamentoCompra *orcamento, float valor) {
    respFornecedor.at(orcamento) = valor;
}

float Fornecedor::respostaOrcamento(OrcamentoCompra *orcamento) {
    return respFornecedor.at(orcamento);
}