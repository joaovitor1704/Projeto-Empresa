#ifndef PAGAMENTO_H
#define PAGAMENTO_H
#include "Data.h"

class Pagamento{

protected:
 bool efetuado;
 Data dataPagamento;
 virtual void metodoAbstrato() = 0;

public:
 bool pagamentoEfetuado(); //porque o pedido so eh efetivado quando o pagamento eh efetuado
};

#endif