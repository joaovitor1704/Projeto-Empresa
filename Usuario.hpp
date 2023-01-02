#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>

enum Permissao { vendedor, funcionarioSimples, RH, logista, administracao, permissaoTeste };

class Usuario {
private:
  Permissao permissao;
  std::string nome;
  Usuario(std::string nome, Permissao permissao);
  static Usuario *instptrUsuario;
public:
  Usuario() {};
  static Usuario *instUsuario(std::string nome, Permissao permissao);
  static Usuario *instUsuario();
  static void reset();
  Permissao getPermissao();
  std::string getNome();
};

#endif