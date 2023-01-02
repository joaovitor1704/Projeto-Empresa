#include "Departamento.hpp"

Departamento::Departamento(std::string _nome) {
  RegistroLog::instRegLog()->vecLogEscrita.push_back(LogEscrita(Usuario::instUsuario(), "Departamento", Data::dateNow(), "cria departamento " + _nome));        
  this->nome = _nome;
}

void Departamento::adicionarFuncionario(Funcionario *f) {
  try {
    if(Usuario::instUsuario()->getPermissao() == permissaoTeste)
      this->pessoal.push_back(f);
    else
      throw ExcecaoAcessoNegado(Usuario::instUsuario(), typeid(*this).name(), __FUNCTION__);
  }
  catch(ExcecaoAcessoNegado& e) {
    std::cerr << e.what() << '\n';
  }
}

bool Departamento::retirarFuncionario(const Funcionario *f) {
  try {
    if(Usuario::instUsuario()->getPermissao() == permissaoTeste) {
      std::vector<Funcionario*>::iterator itr;
      for(itr = this->pessoal.begin(); itr != this->pessoal.end(); ++ itr)
        if(*itr == f) {
          this->pessoal.erase(itr);
          return true;
        }
    }
    else
      throw ExcecaoAcessoNegado(Usuario::instUsuario(), typeid(*this).name(), __FUNCTION__);
  }
  catch(ExcecaoAcessoNegado& e) {
    std::cerr << e.what() << '\n';
  }
  return false;
}

std::vector<Funcionario*> Departamento::getFuncionarios() {
  return this -> pessoal;
}

std::string Departamento::getNome() const {
	if(this != nullptr)
  	return this->nome;
	else
		return "Departamento invalido (nome)";
}

void Departamento::setNome(std::string _nome) {
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