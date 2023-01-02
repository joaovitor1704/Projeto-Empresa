#include "MateriaPrima.hpp"

MateriaPrima::MateriaPrima(std::string _nome, std::string _unidadeDeMedida, unsigned _estoqueMin)
                            : nome(_nome), unidadeDeMedida(_unidadeDeMedida), estoqueMin(_estoqueMin) {
  RegistroLog::instRegLog()->vecLogEscrita.push_back(LogEscrita(Usuario::instUsuario(), "Materia Prima", Data::dateNow(), "cria Materia Prima " + _nome));
}

bool MateriaPrima::inserirFornecedor(Fornecedor* fornecedor) {
  if(std::find(this->fornecedores.begin(), this->fornecedores.end(), fornecedor) == this->fornecedores.end())
    return false;
  else
    this->fornecedores.push_back(fornecedor);
  return true;
}

OrcamentoCompra* MateriaPrima::emiteOrcamentoCompra(unsigned qtd) {
  std::vector<Fornecedor*>::iterator itrF;
  OrcamentoCompra* orcamento = new OrcamentoCompra(qtd);
  std::map<Fornecedor*, bool> fornecedoresOrcamento;
  for(itrF = this->fornecedores.begin(); itrF != this->fornecedores.end(); ++ itrF) {
    (*itrF)->adicionaOrcamento(orcamento);
    fornecedoresOrcamento.insert({*itrF, false});
  }
  this->orcamentos.insert({orcamento, fornecedoresOrcamento});
  return orcamento;
}

bool MateriaPrima::deletaOrcamento(OrcamentoCompra* orcamento) {
  if(static_cast<bool>(this->orcamentos.erase(orcamento))) delete orcamento;
  else return false;
  return true;
}

std::map<OrcamentoCompra*, std::map<Fornecedor*, bool>> MateriaPrima::getOrcamentos() {
  return this->orcamentos;
}

Fornecedor* MateriaPrima::finalizaCompra(OrcamentoCompra* orcamento) {
  if((orcamento->getQtdRespostas() < 1) or orcamento->foiFinalizado()) return nullptr;
  std::map<Fornecedor*, bool> respostasOrcamento = this->orcamentos.at(orcamento);
  std::map<Fornecedor*, bool>::iterator itr;
  Fornecedor* fornecedor;
  float min = std::numeric_limits<float>::max();
  for(itr = respostasOrcamento.begin(); itr != respostasOrcamento.end(); ++ itr)
    if(float resposta = (itr->first)->respostaOrcamento(orcamento); resposta > 0 and resposta < min) {
      fornecedor = itr->first;
      min = resposta;
    }
  respostasOrcamento.at(fornecedor) = true;
  this->alteraQtd(orcamento->getQtdMaterial());
  return fornecedor;
}

void MateriaPrima::alteraQtd(int qtd) {
  this->estoqueAtual += qtd;
}

unsigned MateriaPrima::getQtd() {
  return this->estoqueAtual;
}

std::string MateriaPrima::getUnidadeDeMedida() {
  return this->unidadeDeMedida;
}

unsigned MateriaPrima::getEstoqueMin(){
  return this->estoqueMin;
}