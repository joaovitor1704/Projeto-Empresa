#include "Pedido.hpp"


Pedido::Pedido(Orcamento *orcamento, Data data,Tipopay t, int any) {
    this->orcamento = orcamento;
    this->data = data;
    calculaNovoTotal();
    vende();
    this->tipo=t;
    if(t==cartao){
        this->_c= new Cartaocredito(any,this->orcamento->valor_total);
    }
    else{
        switch (any)
        {
            case 1:
            this->_b=new Boleto(trintaDias,this->orcamento->valor_total,data.getAno(),data.getMes(),data.getDia());
            break;

            case 2:
            this->_b= new Boleto(sessentaDias,this->orcamento->valor_total,data.getAno(),data.getMes(),data.getDia());
            break;

            case 3:
            this->_b= new Boleto(noventaDias,this->orcamento->valor_total,data.getAno(),data.getMes(),data.getDia());
            break;
    
        }
    }
}

void Pedido::calculaNovoTotal() {
    orcamento->valor_total = orcamento->calculatotal();
}

void Pedido::vende() {
    for (auto it = orcamento->carrinho.begin(); it != orcamento->carrinho.end(); it++) {
        Venda* venda = new Venda(orcamento->cliente, it->first, it->second, this->data);
        listaVendas.push_back(venda);
    }
}

std::list<Venda*> Pedido::getVendas() {
    return listaVendas;
}

void Pedido::print_pay(){
    std::cout<<"Pedido:"<<"\n";
    this->orcamento->print();
    if(this->tipo==cartao){
    this->_c->print();
    }
    else{
    this->_b->print();
    }

}


