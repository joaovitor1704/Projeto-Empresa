#ifndef ORCAMENTOCOMPRA_H
#define ORCAMENTOCOMPRA_H

class OrcamentoCompra{

private:
 unsigned qtdMaterial;
 unsigned qtdRespostas;
 bool finalizado;

public:
 OrcamentoCompra(unsigned qtd);
 void aumentaQtdRespostas();
 unsigned getQtdRespostas();
 unsigned getQtdMaterial();
 bool foiFinalizado();

};

#endif