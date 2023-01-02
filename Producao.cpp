#include "Producao.hpp"

Producao::Producao(Data _data, int quantidade, Produto *prod){
 data= _data;
 qtd= quantidade;
 produto= prod;
 produto->insereLotes(qtd);
}
