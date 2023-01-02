#pragma once
#include "Data.h"
#include "Funcionario.hpp"
#include "Turno.hpp"
#include <string>
#include <map>
#include <vector>
#include <string>

class Veiculo {

private:
std::map<std::string,Data> quadro_horarios;
int capacidade;
Turno *turno;
std::vector<Funcionario> rota;
std::pair<float,float> *end_empresa;
std::string placa;
public:
Veiculo(int _capacidade, Turno *_t,std::pair<float,float>*end_empresa,std::string placa);
void adicionafuncionario(Funcionario funcionario);
void removefuncionario(Funcionario funcionario);
float calculaDistancia (float x1, float y1, float x2, float y2);
void print_rota();
void sethorario();
void setCapacidade(int _c);
void setTurno(std::string _t);
int getCapacidade();
Turno getTurno();
float calculaDistancia_e (float x1, float y1);
void print_qh();
void Insere_quadro(Funcionario _f, Data _d);
void Corrige_horario(Funcionario _f);
void Arruma_formato(Data *_d,int d,float m,int seg);
std::string getPlaca();



};
