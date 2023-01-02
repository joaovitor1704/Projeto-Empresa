#include "Usuario.hpp"
#include <iostream>

Usuario *Usuario::instptrUsuario = 0;

Usuario *Usuario::instUsuario(std::string nome, Permissao permissao) {
  if (instptrUsuario == 0)
    instptrUsuario = new Usuario(nome, permissao);
  return instptrUsuario;
}

Usuario *Usuario::instUsuario() {
  if (instptrUsuario == 0)
    instptrUsuario = new Usuario;
  return instptrUsuario;
}

void Usuario::reset() {
  delete instptrUsuario;
  instptrUsuario = nullptr;
}

Usuario::Usuario(std::string _nome, Permissao _permissao) { this->nome = _nome; this->permissao = _permissao; }

Permissao Usuario::getPermissao() { return this->permissao; }

std::string Usuario::getNome() { return this->nome; }