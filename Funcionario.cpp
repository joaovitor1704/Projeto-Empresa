#include "Funcionario.hpp"

unsigned int Funcionario::qtd = 0;

Funcionario::Funcionario(TipoPessoa _tipo, std::string _cadastro, std::string _nome, std::string _email,
                          std::pair<float, float> _endereco, Data _nascimento, Cargo *cargo, Data dataCriacao, float salario,Turno *t) {
  this->tipo = _tipo;
  this->cadastro = _cadastro;
  this->nome = _nome;
  this->email = _email;
  this->endereco = _endereco;
  this->matricula = (++ Funcionario::qtd);
  this->nascimento = _nascimento;
  this->contratar(dataCriacao, cargo, salario);
  this->status = ativo;
  this->turno=t;
}

void Funcionario::aplicaDissidio(Data data, float novoSalario) {
  this->histAlt.insert({data, Alteracao(novoSalario)});
  this->salario = novoSalario;
}

void Funcionario::promover(unsigned ano, unsigned mes, unsigned dia, Cargo *novoCargo, float novoSalario) {
  try {
    if(Usuario::instUsuario()->getPermissao() == permissaoTeste) {
      this->histAlt.insert({Data(ano, mes, dia), Alteracao(novoCargo, novoSalario)});
      this->cargo = novoCargo;
      this->salario = novoSalario;
    }
    else
      throw ExcecaoAcessoNegado(Usuario::instUsuario(), typeid(*this).name(), __FUNCTION__);
  }
  catch(ExcecaoAcessoNegado& e) {
    std::cerr << e.what() << '\n';
  }
}

void Funcionario::promover(Data data, Cargo *novoCargo, float novoSalario) {
  try {
    if(Usuario::instUsuario()->getPermissao() == permissaoTeste) {
      this->histAlt.insert({data, Alteracao(novoCargo, novoSalario)});
      this->cargo = novoCargo;
      this->salario = novoSalario;
    }
    else
      throw ExcecaoAcessoNegado(Usuario::instUsuario(), typeid(*this).name(), __FUNCTION__);
  }
  catch(ExcecaoAcessoNegado& e) {
    std::cerr << e.what() << '\n';
  }
}

void Funcionario::contratar(unsigned ano, unsigned mes, unsigned dia, Cargo *novoCargo, float novoSalario) {
  try {
    if(Usuario::instUsuario()->getPermissao() == permissaoTeste) {
    this->histAlt.insert({Data(ano, mes, dia), Alteracao(ativo, novoCargo, novoSalario)});
    this->cargo = novoCargo;
    this->salario = novoSalario;
    }
    else
      throw ExcecaoAcessoNegado(Usuario::instUsuario(), typeid(*this).name(), __FUNCTION__);
  }
  catch(ExcecaoAcessoNegado& e) {
    std::cerr << e.what() << '\n';
  }
}

void Funcionario::contratar(Data data, Cargo *novoCargo, float novoSalario) {
  try {
    if(Usuario::instUsuario()->getPermissao() == permissaoTeste) {
    this->histAlt.insert({data, Alteracao(ativo, novoCargo, novoSalario)});
    this->cargo = novoCargo;
    this->salario = novoSalario;
    }
    else
      throw ExcecaoAcessoNegado(Usuario::instUsuario(), typeid(*this).name(), __FUNCTION__);
  }
  catch(ExcecaoAcessoNegado& e) {
    std::cerr << e.what() << '\n';
  }
}

void Funcionario::demitir(unsigned ano, unsigned mes, unsigned dia) {
  try {
    if(Usuario::instUsuario()->getPermissao() == permissaoTeste) {
    this->histAlt.insert({Data(ano, mes, dia), Alteracao(desligado)});
    this->status = desligado;
    }
    else
      throw ExcecaoAcessoNegado(Usuario::instUsuario(), typeid(*this).name(), __FUNCTION__);
  }
  catch(ExcecaoAcessoNegado& e) {
    std::cerr << e.what() << '\n';
  }
}

void Funcionario::demitir(Data data) {
  try {
    if(Usuario::instUsuario()->getPermissao() == permissaoTeste) {
      this->histAlt.insert({data, Alteracao(desligado)});
      this->status = desligado;
    }
    else
      throw ExcecaoAcessoNegado(Usuario::instUsuario(), typeid(*this).name(), __FUNCTION__);
  }
  catch(ExcecaoAcessoNegado& e) {
    std::cerr << e.what() << '\n';
  }
}

std::map<Data, Alteracao> Funcionario::getHistAlt() {
  if(this != nullptr)
    return this->histAlt;
  else {
    std::map<Data, Alteracao> mapErro;
    mapErro.insert({Data(0, 0, 0), Alteracao()});
    return mapErro;
  }
}

std::pair<float, float> Funcionario::getEndereco() const {
  if(this != nullptr)
    return this -> endereco;
  else
    return {0, 0};
}

void Funcionario::setEndereco(const std::pair<float, float> _endereco) {
  try {
    if(Usuario::instUsuario()->getPermissao() == permissaoTeste)
      this->endereco = _endereco;
    else
      throw ExcecaoAcessoNegado(Usuario::instUsuario(), typeid(*this).name(), __FUNCTION__);
  }
  catch(ExcecaoAcessoNegado& e) {
    std::cerr << e.what() << '\n';
  }
}

int Funcionario::getMatricula() const {
  if(this != nullptr)
    return this -> matricula;
  else
    return 0;
}

Data Funcionario::getNascimento() const {
  if(this != nullptr)
    return this -> nascimento;
  else
    return Data(0, 0, 0);
}

void Funcionario::setNascimento(const Data _nascimento) {
  try {
    if(Usuario::instUsuario()->getPermissao() == permissaoTeste)
      this->nascimento = _nascimento;
    else
      throw ExcecaoAcessoNegado(Usuario::instUsuario(), typeid(*this).name(), __FUNCTION__);
  }
  catch(ExcecaoAcessoNegado& e) {
    std::cerr << e.what() << '\n';
  }
}

Cargo *Funcionario::getCargo() const {
  if(this != nullptr)
    return this -> cargo;
  else
    return nullptr;
}

float Funcionario::getSalario() const {
  if(this != nullptr)
    return this -> salario;
  else
    return 0;
}

Status Funcionario::getStatus() const {
  if(this != nullptr)
    return this -> status;
  else
    return statusInvalido;
}
Turno Funcionario::getTurno(){
return *this->turno;
}