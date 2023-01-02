#ifndef CATEGORIA_H
#define CATEGORIA_H
#include <vector>
#include"Produto.hpp"
#include <string>



class Categoria {
  private:
    std::string nome;
    std::vector<Produto*> produtos_categoria;
  public:
    std::string getnome() const;
    void setNome(const std::string _nome);
    void insereProduto(Produto* p);
    void removeProduto(Produto* p);
    Categoria(std::string nome);
};
#endif