#include "Pessoa.hpp"

#include <string>

TipoPessoa Pessoa::getTipo() const {
  if(this != nullptr)
    return this -> tipo;
  else
    return tpInvalido;
}

std::string Pessoa::getCadastro() const {
  if(this != nullptr)
    return this -> cadastro;
  else
    return "Pessoa invalida (cadastro)";
}

std::string Pessoa::getNome() const {
  if(this != nullptr)
    return this -> nome;
  else
    return "Pessoa invalida (nome)";
}

std::string Pessoa::getEmail() const {
  if(this != nullptr)
    return this -> email;
  else
    return "Pessoa invalida (email)";
}

void Pessoa::setNome(const std::string _nome) {
  try {
    if(Usuario::instUsuario()->getPermissao() == permissaoTeste)
      this -> nome = _nome;
    else
      throw ExcecaoAcessoNegado(Usuario::instUsuario(), typeid(*this).name(), __FUNCTION__);
  }
  catch(ExcecaoAcessoNegado& e) {
    std::cerr << e.what() << '\n';
  }
}

void Pessoa::setEmail(const std::string _email) {
  try {
    if(Usuario::instUsuario()->getPermissao() == permissaoTeste)
      this -> email = _email;

    else
      throw ExcecaoAcessoNegado(Usuario::instUsuario(), typeid(*this).name(), __FUNCTION__);
  }
  catch(ExcecaoAcessoNegado& e) {
    std::cerr << e.what() << '\n';
  }
}