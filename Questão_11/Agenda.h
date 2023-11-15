#ifndef AGENDA_H
#define AGENDA_H 
//classe abstrata
#include <string>
#include <iostream>
using std::string;
class Agenda 
{
public:
  Agenda(string nome, string endereco, string email) :nome(nome),endereco(endereco),email(email){}
  void setNome(string nome){this->nome=nome;}
  void setEndereco(string endereco){this->endereco=endereco;}
  void setEmail(string email){this->email=email;}
  string getNome()const{return nome;}
  string getEndereco()const{return endereco;}
  string getEmail()const{return email;}
  //método virtual puro
  virtual void imprimir(){};
  virtual void pesquisar(string cp){};
private:
  string nome;
  string endereco;
  string email;
};

#endif