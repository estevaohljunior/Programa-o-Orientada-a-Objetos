#ifndef CONTAL_H
#define CONTAL_H 
#include "Conta.h"
#include <string>
#include <iostream>
#include <time.h>
using std::string;
using std::cout, std::endl;
class Limite: public Conta 
{
public:
int cont=0;
  string data[50],desc[50];
  double sald[50];
  Limite(int numConta,string nomeCorrentista, double saldo,float limite):Conta(numConta,nomeCorrentista,saldo),limite(limite){}
  //método virtual puro

  void setLimite(float limite){this->limite=limite;}
  int getLimite()const {return limite;}
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
    if (x-valor<0||getLimite()-valor<0){
      cout<<"Saldo Insuficiente.";
    }
    else{
      if (x-valor<0){
        Conta::setSaldo(x-valor);
        setLimite(getLimite()-valor);
        data[cont]=__DATE__;
        desc[cont]="Saque";
        sald[cont]=Conta::getSaldo();
        cont++;
      } 
      else{
    Conta::setSaldo(x-valor);
    data[cont]=__DATE__;
    desc[cont]="Saque";
    sald[cont]=Conta::getSaldo();
    cont++;
    }}
  }
  virtual void extrato(){
    cout<<"Numero da conta: "<<getNumConta()<<endl;
    cout<<"Nome do Correntista: "<<getNomeConrrentista()<<endl;
    cout<<"Limite da conta: R$"<<getLimite()<<endl;
    for (int i=0;i<cont;i++){
      cout<<"Data: "<<data[i]<<" ";
      cout<<"Descrição: "<<desc[i]<<" ";
      cout<<"Saldo: R$"<<sald[i]<<endl;
    }
    cout<<"Saldo da conta: R$"<<getSaldo()<<endl;
    cout<<endl;
  }
private:
  float limite;
};

#endif