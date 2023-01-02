#pragma once
#include "Data.h"
#include <string>


class Turno {

private:
std::string turno;
Data horario_entrada;
Data horario_saida;
public:
Turno(std::string _t);
void setTurno(std::string _turno);
void sethorario_entrada(int _d);
void sethorario_saida(int _d);
std::string getTurno();
int gethorario_entrada();
int gethorario_saida();
};
