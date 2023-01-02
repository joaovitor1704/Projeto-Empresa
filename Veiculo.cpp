#include "Veiculo.hpp"
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#define Vm 18



Veiculo::Veiculo(int _capacidade, Turno *_t,std::pair<float,float>*end_empresa,std::string _placa){
this->capacidade=_capacidade;
this->turno=_t;
this->end_empresa=end_empresa;
this->placa=_placa;
}

void Veiculo::Arruma_formato(Data *_d,int d, float m, int seg){
        if(_d->getSeg()+seg >=60 &&_d->getMin()+m < 60){
        _d->setHora(_d->getHora()+d);
        _d->setMin(_d->getMin()+m+1);
        _d->setSeg(_d->getSeg()+seg-60);
        
        }
        else if (_d->getSeg()+seg < 60 &&_d->getMin()+m < 60){
          _d->setHora(_d->getHora()+d);
        _d->setMin(_d->getMin()+m);
        _d->setSeg(_d->getSeg()+seg);  
          
        }
        else if(_d->getSeg()+seg < 60 &&_d->getMin()+m > 60){
           _d->setHora(_d->getHora()+d+1);
           _d->setMin(_d->getMin()+m-60);
           _d->setSeg(_d->getSeg()+seg); 
          
        }
        else{
            _d->setHora(_d->getHora()+d+1);
           _d->setMin(_d->getMin()+m-60+1);
           _d->setSeg(_d->getSeg()+seg-60); 
            
        }
}


float Veiculo::calculaDistancia_e (float x1, float y1){
return 110.57 * sqrt( pow(this->end_empresa->first-x1,2) + pow(this->end_empresa->second-y1, 2) );
}

float Veiculo::calculaDistancia (float x1, float y1, float x2, float y2){
return 110.57 * sqrt( pow(x2-x1,2) + pow(y2-y1, 2) );
}

void Veiculo::Corrige_horario(Funcionario _f){
  Data h =Data();
  h.setHora(this->getTurno().gethorario_entrada()-1);
  h.setMin(50);
  h.setSeg(0);
  Data _d=quadro_horarios.at(_f.getNome());
float outp=calculaDistancia_e(_f.getEndereco().first,_f.getEndereco().second);
     float t=outp/Vm;
      int d=t;
        float m=(t-d)*60;
        int seg=(m-static_cast<int>(m))*60;
        Data data=_d;
        Arruma_formato(&data,d,m,seg);
        if(data > h){
         data=data-h;
         for(auto itf=quadro_horarios.begin();itf!=quadro_horarios.end();itf++){
          itf->second=itf->second - data;
          //std::cout<<data.getHora()<<" :"<<data.getMin()<<" :" <<data.getSeg()<<"\n";
         }
        }
}

void Veiculo::Insere_quadro(Funcionario _f, Data _d){
  if(quadro_horarios.find(_f.getNome())!=quadro_horarios.end()){
    std::map<std::string,Data>::iterator it= quadro_horarios.find(_f.getNome());
    it->second=_d;
  }
  else{
     quadro_horarios.insert(make_pair(_f.getNome(),_d));
  }
}

void Veiculo::sethorario(){
  float outp=0;
  float t=0;
  Data* _d= new Data();
  _d->setHora(this->getTurno().gethorario_entrada()-1);
  _d->setMin(50);
  _d->setSeg(0);
  for(auto it=rota.begin();it!=rota.end();it++){
    std::pair<float,float>aux=it->getEndereco();
    if(it==rota.begin()){
       Data _data=Data();
      outp=calculaDistancia_e(aux.first,aux.second);
      t=outp/Vm;
      int d=t;
        float m=(t-d)*60;
        int seg=(m-static_cast<int>(m))*60;
          _data.setHora(d);
        _data.setMin(m);
        _data.setSeg(seg); 
          *_d=*_d-_data;
       Insere_quadro((*it),*_d);
        
      }
    else{
      outp=calculaDistancia((it-1)->getEndereco().first,(it-1)->getEndereco().second,aux.first,aux.second);
      t=outp/Vm;
      int d=t;
        float m=(t-d)*60;
        int seg=(m-static_cast<int>(m))*60;
        Arruma_formato(_d,d,m,seg);
         Insere_quadro((*it),*_d);
         if(it==rota.end()-1){
           Corrige_horario(*it);
         }  
    }
    }
}



void Veiculo::adicionafuncionario(Funcionario _f){
  try {
    if(Usuario::instUsuario()->getPermissao() == permissaoTeste ){
 std::vector<Funcionario>::iterator itf;
  itf=rota.begin();
  std::pair<float,float>auxf=_f.getEndereco();
  if(this->getTurno().gethorario_entrada()==_f.getTurno().gethorario_entrada() && this->capacidade > static_cast<int>(this->rota.size())){
  if(rota.empty()==1){
    rota.push_back(_f);
    RegistroLog::instRegLog()->vecLogEscrita.push_back(LogEscrita(Usuario::instUsuario(), "Veículo",
                                                                      Data::dateNow(), "adiciona Funcionário " + _f.getNome()));
    }
    else{
    std::pair<float,float>auxi=itf->getEndereco();
  if(calculaDistancia_e(auxf.first,auxf.second) >= calculaDistancia_e(auxi.first,auxi.second)){
    rota.insert(itf,_f);
    RegistroLog::instRegLog()->vecLogEscrita.push_back(LogEscrita(Usuario::instUsuario(), "Veículo",
                                                                      Data::dateNow(), "adiciona Funcionário " + _f.getNome()));
    }
    
    else if(rota.size()>1){
      for( auto it=rota.begin();it!=rota.end();it++){
        std::pair<float,float>auxi=it->getEndereco();
      std::pair<float,float>auxa=(it+1)->getEndereco();
        if (calculaDistancia(auxf.first,auxf.second,auxi.first,auxi.second) <= calculaDistancia(auxa.first,auxa.second,auxi.first,auxi.second)){
        rota.insert(it+1,_f);
        RegistroLog::instRegLog()->vecLogEscrita.push_back(LogEscrita(Usuario::instUsuario(), "Veículo",
                                                                   Data::dateNow(), "adiciona Funcionário " + _f.getNome()));
          break;
        }
        }
    }
    
      
  else{
   rota.push_back(_f);
   RegistroLog::instRegLog()->vecLogEscrita.push_back(LogEscrita(Usuario::instUsuario(), "Veículo",
                                                                      Data::dateNow(), "adiciona Funcionário " + _f.getNome()));
}
    }
    sethorario();
}
else{
std::cout<<"inserção inváilda"<<"\n";
}
    }
else
      throw ExcecaoAcessoNegado(Usuario::instUsuario(), typeid(*this).name(), __FUNCTION__);
  
 
//}
}
 catch(ExcecaoAcessoNegado& e) {
    std::cerr << e.what() << '\n';
  }
}


void Veiculo::removefuncionario(Funcionario funcionario){
for(auto it=rota.begin();it!=rota.end();it++){
if (it->getNome()==funcionario.getNome())
rota.erase(it);
}
}

void Veiculo::print_rota(){
   std::cout<<"Rota:"<<"\n";
    for( auto it=rota.begin();it!=rota.end();it++){
        std::cout<<it->getNome()<<"\n";
}
}

Turno Veiculo::getTurno(){
return *this->turno;
}
void Veiculo::print_qh(){
  std::vector<std::pair<std::string,Data> > arr;
  for(auto itf=quadro_horarios.begin();itf!=quadro_horarios.end();itf++){
    arr.push_back(make_pair(itf->first,itf->second));
  }
  
  std::sort(arr.begin(), arr.end(),
              [] (const auto &x, const auto &y) {return x.second < y.second;});
    std::cout<<"Quadro de Horários:"<<"\n";
  for(auto it=arr.begin();it!=arr.end();it++){
    std::cout<<it->first<<" ";
    std::cout<<it->second.getHora()<<":"<<it->second.getMin()<<":"<<it->second.getSeg()<<"\n";
    
  }
 
}

std::string Veiculo::getPlaca(){
  return this->placa;
}