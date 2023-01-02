#ifndef ORDEMDEPROD_H
#define ORDEMDEPROD_H
#include "Data.h"
#include "Producao.hpp"


class OrdemDeProd{

private:
 Data data;
 int qtd;

public:
 OrdemDeProd(unsigned _ano, unsigned _mes, unsigned _dia, int _qtd, Produto *_prod);
 Producao produz(Produto *prod);
 friend std::ostream& operator<< (std::ostream& stream, const OrdemDeProd& it);


};



#endif
