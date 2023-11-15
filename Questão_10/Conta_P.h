#ifndef CONTAP_H
#define CONTAP_H 
#include "Conta.h"
#include <string>
#include <iostream>
#include <time.h>
using std::string;
using std::cout, std::endl;
class Poupanca: public Conta 
{
public:
int cont=0;
  string data[50],desc[50];
  double sald[50];
  Poupanca(int numConta,string nomeCorrentista, double saldo,int dia_anv):Conta(numConta,nomeCorrentista,saldo),dia_anv(dia_anv){}
  //método virtual puro

  void setDia_anv(int dia_anv){this->dia_anv=dia_anv;}
  int getDia_anv()const {return dia_anv;}
  virtual void deposito(double valor){
    double x=Conta::getSaldo()+valor;
    Conta::setSaldo(x);
    data[cont]=__DATE__;
    desc[cont]="Deposito";
    sald[cont]=Conta::getSaldo();
    cont++;
  }
  virtual void retirada(double valor){
    double x=Conta::getSaldo();
    if (x-valor<0){
      cout<<"Saldo Insuficiente.";
    }
    else{ 
    Conta::setSaldo(x-valor);
    data[cont]=__DATE__;
    desc[cont]="Saque";
    sald[cont]=Conta::getSaldo();
    cont++;
    }
  }
  virtual void extrato(){
    cout<<"Numero da Conta: "<<getNumConta()<<endl;
    cout<<"Nome do Correntista: "<<getNomeConrrentista()<<endl;
    cout<<"Dia de Aniversario: "<<getDia_anv()<<endl;
    for (int i=0;i<cont;i++){
      cout<<"Data: "<<data[i]<<" ";
      cout<<"Descrição: "<<desc[i]<<" ";
      cout<<"Saldo: R$"<<sald[i]<<endl;
    }
    cout<<"Saldo da conta: R$"<<getSaldo()<<endl;
    cout<<endl;
  }
private:
  int dia_anv;
};

#endif