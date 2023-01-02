#include "Empresa.hpp"
#include <regex>

Empresa *Empresa::instptrEmpresa = 0;

Empresa *Empresa::instEmpresa() {
  if(instptrEmpresa == 0)
    instptrEmpresa = new Empresa;
  return instptrEmpresa;
}

Funcionario* Empresa::adicionaFuncionario(TipoPessoa tipo, std::string cadastro, std::string nome,
                          std::string email, std::pair<float, float> endereco, unsigned anoNasc, unsigned mesNasc, unsigned diaNasc,
                            Departamento* departamento, Cargo *cargo, unsigned anoCria, unsigned mesCria, unsigned diaCria, float salario,Turno *t) {
  try {
    if(Usuario::instUsuario()->getPermissao() == permissaoTeste)
      if(validaCadastro(func, tipo, cadastro)) {
      Funcionario* funcionario = new Funcionario(tipo, cadastro, nome, email, endereco, Data(anoNasc, mesNasc, diaNasc),
                                                  cargo, Data(anoCria, mesCria, diaCria), salario,t);
      departamento->adicionarFuncionario(funcionario);
      RegistroLog::instRegLog()->vecLogEscrita.push_back(LogEscrita(Usuario::instUsuario(), "Empresa",
                                                                      Data::dateNow(), "adiciona funcionario " + funcionario->getNome()));
      return funcionario;
    } else {
      std::cout << "CPF invalido" << std::endl;
      return nullptr;
    }
    else
      throw ExcecaoAcessoNegado(Usuario::instUsuario(), typeid(*this).name(), __FUNCTION__);
  }
  catch(ExcecaoAcessoNegado& e) {
    std::cerr << e.what() << '\n';
  }
  return nullptr;
}

Cliente* Empresa::adicionarCliente(std::string telefone, std::string nome, std::string cadastro,
                                    std::string email, enum TipoPessoa tipo) {
  try {
    if(Usuario::instUsuario()->getPermissao() == permissaoTeste)
      if(validaCadastro(func, tipo, cadastro)) {
        Cliente* cliente = new Cliente(telefone, nome, cadastro, email, tipo);
        this->clientes.push_back(cliente);
        RegistroLog::instRegLog()->vecLogEscrita.push_back(LogEscrita(Usuario::instUsuario(), "Empresa",
                                                                        Data::dateNow(), "adiciona cliente " + cliente->getNome()));        
        return cliente;
      } else {
      std::cout << "CPF invalido" << std::endl;
      return nullptr;
      }
    else
      throw ExcecaoAcessoNegado(Usuario::instUsuario(), typeid(*this).name(), __FUNCTION__);
  }
  catch(ExcecaoAcessoNegado& e) {
    std::cerr << e.what() << '\n';
  }
  return nullptr;
}

bool Empresa::validaCadastro(TipoCadastro tipoC, TipoPessoa tipoP, std::string cadastro) {
  std::regex regularExpr(tipoP == pFisica ? "[0-9]{11}" : "[0-9]{14}");
  if(!std::regex_match(cadastro, regularExpr)) return false;
  if(tipoC == func) {
    std::vector<Departamento*>::iterator itrD;
    std::vector<Funcionario*>::iterator itrF;
    std::vector<Funcionario*> funcionarios;
    for(itrD = this->departamentos.begin(); itrD != this->departamentos.end(); ++ itrD)
      for(funcionarios = (*itrD)->getFuncionarios(),
            itrF = funcionarios.begin(); itrF != funcionarios.end(); ++ itrF)
        if((*itrF)->getCadastro() == cadastro)
          return false;
  } else {
    std::vector<Cliente*>::iterator itr;
    for(itr = this->clientes.begin(); itr != this->clientes.end(); ++ itr)
      if((*itr)->getCadastro() == cadastro)
        return false;
  }
  return true;
}

void Empresa::adicionarDepartamento(Departamento* departamento) {
  try {
    if(Usuario::instUsuario()->getPermissao() == permissaoTeste) {
      this->departamentos.push_back(departamento);
      RegistroLog::instRegLog()->vecLogEscrita.push_back(LogEscrita(Usuario::instUsuario(), "Empresa",
                                                          Data::dateNow(), "adiciona departamento " + departamento->getNome()));
    }
    else
      throw ExcecaoAcessoNegado(Usuario::instUsuario(), typeid(*this).name(), __FUNCTION__);
  }
  catch(ExcecaoAcessoNegado& e) {
    std::cerr << e.what() << '\n';
  }
}

bool Empresa::retirarDepartamento(Departamento* departamento) {
  try {
    if(Usuario::instUsuario()->getPermissao() == permissaoTeste) {
      std::vector<Departamento*>::iterator itr;
      for(itr = this->departamentos.begin(); itr != this->departamentos.end(); ++ itr)
        if(*itr == departamento) {
          this->departamentos.erase(itr);
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

void Empresa::aplicarDissidio(TipoDissidio tipo, float valor, unsigned ano, unsigned mes, unsigned dia) {
  try {
    if(Usuario::instUsuario()->getPermissao() == permissaoTeste) {
      Data data(ano, mes, dia);
      std::vector<Departamento*>::iterator itrD;
      std::vector<Funcionario*>::iterator itrF;
      std::vector<Funcionario*> funcionarios;
      for(itrD = this->departamentos.begin(); itrD != this->departamentos.end(); ++ itrD)
        for(funcionarios = (*itrD)->getFuncionarios(),
              itrF = funcionarios.begin(); itrF != funcionarios.end(); ++ itrF)
          if(tipo == percentual)
            (*itrF)->aplicaDissidio(data, (*itrF)->getSalario() + (*itrF)->getSalario() * valor / 100);
          else
            (*itrF)->aplicaDissidio(data, (*itrF)->getSalario() +  valor);
    }
    else
      throw ExcecaoAcessoNegado(Usuario::instUsuario(), typeid(*this).name(), __FUNCTION__);
  }
  catch(ExcecaoAcessoNegado& e) {
    std::cerr << e.what() << '\n';
  }
}

Departamento* Empresa::getDeptFuncionario(Funcionario* funcionario) {
  std::vector<Departamento*>::iterator itrD;
  std::vector<Funcionario*>::iterator itrF;
  for(itrD = this->departamentos.begin(); itrD != this->departamentos.end(); ++ itrD) {
    std::vector<Funcionario*> funcionarios = (*itrD)->getFuncionarios();
    for(funcionarios = (*itrD)->getFuncionarios(),
					itrF = funcionarios.begin(); itrF != funcionarios.end(); ++ itrF)
      if((*itrF) == funcionario)
        return (*itrD);
  }
  return nullptr;
}

bool Empresa::criaOrcamento(Cliente* cliente, unsigned ano, unsigned mes, unsigned dia) {
  try {
    if(Usuario::instUsuario()->getPermissao() == permissaoTeste) {
      this->orcamentos.push_back(new Orcamento(cliente, Data(ano, mes, dia)));
			RegistroLog::instRegLog()->vecLogEscrita.push_back(LogEscrita(Usuario::instUsuario(), "Empresa",
                                                          Data::dateNow(), "cria orcamento para o cliente " + cliente->getNome()));
      return true;
    }
    else
      throw ExcecaoAcessoNegado(Usuario::instUsuario(), typeid(*this).name(), __FUNCTION__);
  }
  catch(ExcecaoAcessoNegado& e) {
    std::cerr << e.what() << '\n';
  }
  return false;
}

std::vector<Orcamento*> Empresa::getOrcamentos() {
	RegistroLog::instRegLog()->vecLogLeitura.push_back(LogLeitura(Usuario::instUsuario(), "Empresa", __FUNCTION__));
	return this->orcamentos;
}

bool Empresa::efetuaPedido(Orcamento* orcamento, unsigned ano, unsigned mes, unsigned dia, Tipopay t, int any) {
  try {
    if(Usuario::instUsuario()->getPermissao() != permissaoTeste || any > 6 || any < 1 ||(t==boleto && any>3)) {
      throw ExcecaoAcessoNegado(Usuario::instUsuario(), typeid(*this).name(), __FUNCTION__);
    }
    else
      {
      for(std::map<Produto*, int>::iterator itr = orcamento->carrinho.begin(); itr != orcamento->carrinho.end(); ++ itr)
        if((itr->first)->ChecaQtd() < (itr->second)) return false;
      this->pedidos.push_back(new Pedido(orcamento, Data(ano, mes, dia), t,  any));
			RegistroLog::instRegLog()->vecLogEscrita.push_back(LogEscrita(Usuario::instUsuario(), "Empresa",
                                                          Data::dateNow(), "efetua pedido do orcamento para o cliente " + orcamento->cliente->getNome()));
      return true;
  }
  }
  catch(ExcecaoAcessoNegado& e) {
    std::cerr << e.what() << '\n';
  }
  return false;
}

void Empresa::deletaFuncionario(Funcionario* funcionario) {
  try {
    if(Usuario::instUsuario()->getPermissao() == administracao) {
      this->getDeptFuncionario(funcionario)->retirarFuncionario(funcionario);
      delete funcionario;
    }
    else
      throw ExcecaoAcessoNegado(Usuario::instUsuario(), "Empresa", __FUNCTION__);
  }
  catch(ExcecaoAcessoNegado& e) {
    std::cerr << e.what() << '\n';
  }
}

void Empresa::deletaCliente(Cliente* cliente) {
  try {
    if(Usuario::instUsuario()->getPermissao() == permissaoTeste) {
      std::vector<Cliente*>::iterator itr;
      for(itr = this->clientes.begin(); itr != this->clientes.end(); ++ itr)
        if(*itr == cliente) {
          this->clientes.erase(itr);
          delete cliente;
        }
    }
    else
      throw ExcecaoAcessoNegado(Usuario::instUsuario(), typeid(*this).name(), __FUNCTION__);
  }
  catch(ExcecaoAcessoNegado& e) {
    std::cerr << e.what() << '\n';
  }
}

Cargo* Empresa::criaCargo(std::string nome) {
  try {
    if(Usuario::instUsuario()->getPermissao() == permissaoTeste)
      return new Cargo(nome);
    else
      throw ExcecaoAcessoNegado(Usuario::instUsuario(), typeid(*this).name(), __FUNCTION__);
  }
  catch(ExcecaoAcessoNegado& e) {
    std::cerr << e.what() << '\n';
  }
  return nullptr;
}

Veiculo* Empresa::adicionaVeiculo(int _capacidade, Turno *_t,std::string _placa) {
  try {
    if(Usuario::instUsuario()->getPermissao() == permissaoTeste) {
  Veiculo *_v=new Veiculo(_capacidade,_t,&this->endereco,_placa);
  this->frota.push_back(_v);
  RegistroLog::instRegLog()->vecLogEscrita.push_back(LogEscrita(Usuario::instUsuario(), "Empresa",
                                                          Data::dateNow(), "Adiciona veículo " + _v->getPlaca()));
  return _v;
}
 else
      throw ExcecaoAcessoNegado(Usuario::instUsuario(), typeid(*this).name(), __FUNCTION__);
  }
  catch(ExcecaoAcessoNegado& e) {
    std::cerr << e.what() << '\n';
  }
  return nullptr;
  }


std::pair<float, float> Empresa::getEndereco() {
  return this->endereco;
}

void Empresa::setEndereco(std::pair<float, float> _endereco) {
  RegistroLog::instRegLog()->vecLogEscrita.push_back(LogEscrita(Usuario::instUsuario(), "Empresa",
                                                          Data::dateNow(), "altera endereco para <" + std::to_string(_endereco.first) + ", " + std::to_string(_endereco.second) + ">"));
  this->endereco = _endereco;
}

Veiculo* Empresa::getVeiculo(std::string placa){
  RegistroLog::instRegLog()->vecLogLeitura.push_back(LogLeitura(Usuario::instUsuario(), "Empresa", __FUNCTION__));
  std::vector<Veiculo*>::iterator itr;
      for(itr = this->frota.begin(); itr != this->frota.end(); ++ itr){
        if(placa == (*itr)->getPlaca()){
          return (*itr);
        }
      }
      return nullptr;
}