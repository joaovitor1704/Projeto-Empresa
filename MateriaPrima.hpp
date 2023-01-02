#ifndef MP_H
#define MP_H

#include <string>
#include <map>
#include <list>
#include <vector>
#include <algorithm>
#include <limits>
#include "OrcamentoCompra.hpp"
#include "Fornecedor.hpp"
#include "RegistroLog.hpp"

class MateriaPrima {
    std::string nome;
		std::string unidadeDeMedida;
    std::map<OrcamentoCompra*, std::map<Fornecedor*, bool>> orcamentos;
    std::vector<Fornecedor*> fornecedores;
    unsigned estoqueMin;
    unsigned estoqueAtual;
  public:
    MateriaPrima(std::string nome, std::string _unidadeDeMedida, unsigned _estoqueMin);
    bool inserirFornecedor(Fornecedor*);
    OrcamentoCompra* emiteOrcamentoCompra(unsigned);
    bool deletaOrcamento(OrcamentoCompra*);
    std::map<OrcamentoCompra*, std::map<Fornecedor*, bool>> getOrcamentos();
    Fornecedor* finalizaCompra(OrcamentoCompra*);
    void alteraQtd(int);
    unsigned getQtd();
    std::string getUnidadeDeMedida();
    unsigned getEstoqueMin();
};

#endif