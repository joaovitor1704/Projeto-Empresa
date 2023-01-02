#include "Turno.hpp"
#include <string>


Turno::Turno(std::string _t){
if(_t=="M"){
    sethorario_entrada(8);
    sethorario_saida(16);
}
else if (_t=="T"){
    sethorario_entrada(14);
    sethorario_saida(22);
}
else if(_t=="N"){
    sethorario_entrada(22);
    sethorario_saida(6);
}
}

void Turno::setTurno(std::string _turno){
    this->turno=_turno;
}

void Turno::sethorario_entrada(int _d){
Data _data = Data();
_data.setHora(_d);
this->horario_entrada=_data;
}

void Turno::sethorario_saida(int _d){
Data _data = Data();
_data.setHora(_d);
this->horario_saida=_data;
}

std::string Turno::getTurno(){return this->turno;}

int Turno::gethorario_entrada(){return this->horario_entrada.getHora();}

int Turno::gethorario_saida(){return this->horario_saida.getHora();}