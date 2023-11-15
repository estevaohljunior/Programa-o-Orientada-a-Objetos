#ifndef PESSOAJ_H
#define PESSOAJ_H 
//classe abstrata
#include <iostream>
#include <string>
#include "Agenda.h"
using std::string;
using std::cout, std::endl;
class Pessoa_Juridica: public Agenda
{
public:
  Pessoa_Juridica(string cnpj,string nome, string endereco,string insc_estadual, string email,string razao_social) :Agenda(nome,endereco,email),cnpj(cnpj),insc_estadual(insc_estadual),razao_social(razao_social){}
  void setCnpj(string cnpj){this->cnpj=cnpj;}
  void setInsc_Estadual(string insc_estadual){this->insc_estadual=insc_estadual;}
  void setRazao_Social(string razao_social){this->razao_social=razao_social;}
  string getCnpj()const {return cnpj;}
  string getInsc_Estadual()const{return insc_estadual;}
  string getRazao_Social()const{return razao_social;}
  virtual void imprimir(){
    cout<<"CNPJ: "<<getCnpj()<<endl;
    cout<<"Nome: "<<Agenda::getNome()<<endl;
    cout<<"Endereco: "<<Agenda::getEndereco()<<endl;
    cout<<"Inscrição Estadual: "<<getInsc_Estadual()<<endl;
    cout<<"Email: "<<Agenda::getEmail()<<endl;
    cout<<"Razao social: "<<getRazao_Social()<<endl;
    cout<<endl;
  };
  virtual void pesquisar(string cp){
    if (Agenda::getNome()==cp || getCnpj()==cp){
      cout<<"Resultado da Pesquisa:  "<<endl;
    cout<<"CNPJ: "<<getCnpj()<<endl;
    cout<<"Nome: "<<Agenda::getNome()<<endl;
    cout<<"Endereco: "<<Agenda::getEndereco()<<endl;
    cout<<"Inscrição Estadual: "<<getInsc_Estadual()<<endl;
    cout<<"Email: "<<Agenda::getEmail()<<endl;
    cout<<"Razao social: "<<getRazao_Social()<<endl;
    cout<<endl;
    };
  };
private:
 string cnpj;
 string insc_estadual;
 string razao_social;
};
#endif