#ifndef PEDIDO_H
#define PEDIDO_H

#include "Orcamento.hpp"
#include "Venda.hpp"
#include  "Boleto.hpp"
#include  "Cartaocredito.hpp"

enum Tipopay { boleto, cartao };

class Pedido {
    public:
        Pedido(Orcamento *orcamento, Data data, Tipopay t, int any);
        void vende();
        void calculaNovoTotal();
        std::list<Venda*> getVendas();
        void print_pay();
        Tipopay tipo;
    

    private:
        Orcamento *orcamento;
        Data data;
        std::list<Venda*> listaVendas;
        Boleto *_b;
        Cartaocredito *_c;

};

#endif
