#ifndef Fornecedor_H
#define Fornecedor_H

#include "OrcamentoCompra.hpp"
#include <map>

class Fornecedor{
    private:
        //std::vector<std::pair<OrcamentoCompra*, float>> respFornecedor;
        std::map<OrcamentoCompra*, float> respFornecedor;

    public:
        void adicionaOrcamento(OrcamentoCompra *orcamento);
        void calculaOrcamento(OrcamentoCompra *orcamento, float valor);
        float respostaOrcamento(OrcamentoCompra *orcamento);

};

#endif