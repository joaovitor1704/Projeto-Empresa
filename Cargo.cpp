#include "Cargo.hpp"
#include "ExcecaoAcessoNegado.hpp"

Cargo::Cargo(std::string _nome) {
  if(_nome != "cargoNA")
    RegistroLog::instRegLog()->vecLogEscrita.push_back(LogEscrita(Usuario::instUsuario(), "Cargo", Data::dateNow(), "cria cargo " + _nome));        
  this->nome = _nome;
}

void Cargo::setNome(const std::string _nome) {
  try {
    if(Usuario::instUsuario()->getPermissao() == permissaoTeste)
      this->nome = _nome;
    else
      throw ExcecaoAcessoNegado(Usuario::instUsuario(), typeid(*this).name(), __FUNCTION__);
  }
  catch(ExcecaoAcessoNegado& e) {
    std::cerr << e.what() << '\n';
  }
}

std::string Cargo::getNome() const {
  if(this != nullptr)
    return this->nome;
  else
    return "Cargo invalido (nome)";
}