#include "Alteracao.hpp"

Cargo Alteracao::cargoNA("cargoNA");

Alteracao::Alteracao(float _novoSalario) {
  this->tipo = dissidio;
  this->novoSalario = _novoSalario;
  this->novoCargo = &cargoNA;
}

Alteracao::Alteracao(Cargo *_novoCargo, float _novoSalario) {
  this->tipo = promocao;
  this->novoCargo = _novoCargo;
  this->novoSalario = _novoSalario;
}

Alteracao::Alteracao(Status _novoStatus, Cargo *_novoCargo, float _novoSalario) {
  this->tipo = admissao;
  this->novoStatus = _novoStatus;
  this->novoCargo = _novoCargo;
  this->novoSalario = _novoSalario;
}

Alteracao::Alteracao(Status _novoStatus) {
  this->tipo = demissao;
  this->novoStatus = _novoStatus;
  this->novoCargo = &cargoNA;
}

Alteracao::Alteracao() {
  this->tipo = tipoAltNA;
}

TipoAlteracao Alteracao::getTipo() const {
  return tipo;
}

float Alteracao::getNovoSalario() const {
  return novoSalario;
}

Cargo *Alteracao::getNovoCargo() const {
  if(this->tipo == tipoAltNA) return nullptr;
  else return novoCargo;
}