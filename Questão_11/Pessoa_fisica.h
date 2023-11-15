#ifndef PESSOAF_H
#define PESSOAF_H 
//classe abstrata
#include <iostream>
#include <string>
#include "Agenda.h"
using std::string;
using std::cout, std::endl;
class Pessoa_Fisica: public Agenda
{
public:
  Pessoa_Fisica(string cpf,string nome, string endereco,string data_nasc, string email,string estado_civ) :Agenda(nome,endereco,email),cpf(cpf),data_nasc(data_nasc),estado_civ(estado_civ){}
  void setCpf(string cpf){this->cpf=cpf;}
  void setData_nasc(string data_nasc){this->data_nasc=data_nasc;}
  void setEstado_Civ(string estado_civ){this->estado_civ=estado_civ;}
  string getCpf()const {return cpf;}
  string getData_Nasc()const{return data_nasc;}
  string getEstado_civ()const{return estado_civ;}
  virtual void imprimir(){
    cout<<"Cpf: "<<getCpf()<<endl;
    cout<<"Nome: "<<Agenda::getNome()<<endl;
    cout<<"Endereco: "<<Agenda::getEndereco()<<endl;
    cout<<"Data do Nascimento: "<<getData_Nasc()<<endl;
    cout<<"Email: "<<Agenda::getEmail()<<endl;
    cout<<"Estado Civil: "<<getEstado_civ()<<endl;
    cout<<endl;
  };
  virtual void pesquisar(string cp){
    if (Agenda::getNome()==cp || getCpf()==cp){
    cout<<"Resultado da Pesquisa:  "<<endl;
    cout<<"Cpf: "<<getCpf()<<endl;
    cout<<"Nome: "<<Agenda::getNome()<<endl;
    cout<<"Endereco: "<<Agenda::getEndereco()<<endl;
    cout<<"Data do Nascimento: "<<getData_Nasc()<<endl;
    cout<<"Email: "<<Agenda::getEmail()<<endl;
    cout<<"Estado Civil: "<<getEstado_civ()<<endl;
    cout<<endl;
    }
  };
private:
 string cpf;
 string data_nasc;
 string estado_civ;
};
#endif

