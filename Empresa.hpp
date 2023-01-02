#ifndef EMPRESA_H
#define EMPRESA_H

#include <list>
#include <vector>
#include "Funcionario.hpp"
#include "Cliente.hpp"
#include "Departamento.hpp"
#include "Venda.hpp"
#include "Usuario.hpp"
#include "Cargo.hpp"
#include "Pedido.hpp"
#include "Veiculo.hpp"
#include "LogEscrita.hpp"
#include "LogLeitura.hpp"
#include "Turno.hpp"


enum TipoDissidio { percentual, absoluto };
enum TipoCadastro { func, cliente};

class Empresa {
  private:
    std::vector<Departamento*> departamentos;
    std::vector<Cliente*> clientes;
		std::vector<Orcamento*> orcamentos;
		std::vector<Pedido*> pedidos;
    bool validaCadastro(TipoCadastro tipoC, TipoPessoa tipo, std::string cadastro);
    std::vector<Veiculo*> frota;
    std::pair<float, float> endereco;
    Empresa() {};
    static Empresa *instptrEmpresa;
    
  public:
    static Empresa *instEmpresa();
    Funcionario* adicionaFuncionario(TipoPessoa tipo, std::string cadastro, std::string nome,
                              std::string email, std::pair<float, float> endereco, unsigned anoNasc, unsigned mesNasc, unsigned diaNasc,
                                Departamento* departamento, Cargo *cargo, unsigned anoCria, unsigned mesCria, unsigned diaCria, float salario,Turno *t);
    Cliente* adicionarCliente(std::string telefone, std::string nome, std::string cadastro,
          std::string email, enum TipoPessoa tipo);
    void adicionarDepartamento(Departamento* departamento);
    bool retirarDepartamento(Departamento* departamento);
    void aplicarDissidio(TipoDissidio tipo, float valor, unsigned ano, unsigned mes, unsigned dia);
    Departamento* getDeptFuncionario(Funcionario* funcionario);
		bool criaOrcamento(Cliente* cliente, unsigned ano, unsigned mes, unsigned dia);
		std::vector<Orcamento*> getOrcamentos();
		bool efetuaPedido(Orcamento* orcamento, unsigned ano, unsigned mes, unsigned dia,Tipopay t, int any);
    void deletaFuncionario(Funcionario* funcionario);
    void deletaCliente(Cliente* cliente);
    Cargo* criaCargo(std::string nome);
    Veiculo* adicionaVeiculo(int _capacidade, Turno *_t,std::string _placa);
    void setEndereco(std::pair<float, float>);
    std::pair<float, float> getEndereco();
    Veiculo* getVeiculo(std::string placa);
};

#endif