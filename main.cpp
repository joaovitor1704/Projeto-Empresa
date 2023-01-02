#include <iostream>
#include "Empresa.hpp"
#include "Funcionario.hpp"
#include "Produto.hpp"
#include "Estoque.hpp"
#include "Usuario.hpp"
#include "ExcecaoAcessoNegado.hpp"
#include "RegistroLog.hpp"
#include "Orcamento.hpp"
#include "Pedido.hpp"
#include "Turno.hpp"
#include "MateriaPrima.hpp"
//#include "TesteAlemDoDoc.hpp"

int main() {
  // o que tiver que testar além do que os testes do documento cobra, testar dentro da funcao
  // cada um implementa a propria "TesteAlemDoDoc.hpp" com esta funcao e os testes que quiser dentro
  // assim nao vai misturar com os testes do doc
  //testeAlemDoDocumento();
  Usuario::instUsuario()->reset();
  Empresa *empresa = Empresa::instEmpresa();
  Usuario *user = Usuario::instUsuario("usuario1", permissaoTeste);
  Usuario *user1 = Usuario::instUsuario();
  std::cout << "se " << user << " == " << user1 << " o singleton funciona." << std::endl;
  Departamento dep("dep");
  empresa->adicionarDepartamento(&dep);
  Cargo cargo("cargo");
  Turno _t=Turno("M");
  Funcionario *func0 = empresa->adicionaFuncionario(pFisica, "12345678910", "nome0", "email0", {-19.91,-43.89}, 2000, 10, 10, &dep, &cargo, 2000, 10, 11, 10000,&_t);
  Funcionario *func1 = empresa->adicionaFuncionario(pFisica, "98765432101", "nome1", "email1", {-19.915, -43.94}, 2000, 10, 10, &dep, &cargo, 2000, 10, 11, 10000,&_t);
  Funcionario *func2 = empresa->adicionaFuncionario(pFisica, "32165498799", "nome2", "email2", {-19.916, -43.911}, 2000, 10, 10, &dep, &cargo, 2000, 10, 11, 10000,&_t);
  Cliente *cliente0 = empresa->adicionarCliente("123456789", "cliente0", "12345678901", "emailcliente0", pFisica);
  Cliente *cliente1 = empresa->adicionarCliente("123456789", "cliente1", "01987654321123", "emailcliente1", pJuridica);
  MateriaPrima madeira("madeira", "g", 1000), plastico("plastico", "g", 1000), aluminio("aluminio", "g", 1000), parafuso("parafuso", "unidade", 20);
  Produto mesa("mesa", 10, 0, 1, 20, std::map<MateriaPrima*, unsigned>{{&madeira, 450}, {&plastico, 150}, {&aluminio, 100}, {&parafuso, 8}});
	Estoque *estoque = Estoque::instEstoque();
	estoque->adicionaProduto(&mesa);
	estoque->emiteOrdem(2022, 11, 17, mesa.getEstoquemin(), &mesa);
  empresa->deletaFuncionario(func0);
  empresa->criaOrcamento(cliente1, 2022, 11, 17);
  (*empresa->getOrcamentos().begin())->insereProduto(&mesa, 10);
  mesa.setValorvenda(10.5, 2022, 11, 22);
  empresa->efetuaPedido(*empresa->getOrcamentos().begin(), 2022, 11, 17,cartao,3);
  std::pair<float,float>ende={-19.96, -44.05};
  empresa->setEndereco(ende);
  empresa->adicionaVeiculo(3,&_t,"hht321");
    empresa->getVeiculo("hht321")->adicionafuncionario(*func0);
  empresa->getVeiculo("hht321")->adicionafuncionario(*func2);
    empresa->getVeiculo("hht321")->adicionafuncionario(*func1);
  empresa->getVeiculo("hht321")->print_qh();

  //cadastrar veiculo etc...
  RegistroLog::instRegLog()->printLogs(); // cada um coloca os logs nos métodos das classes que implementou
    
}