#ifndef CONTA_H
#define CONTA_H 
//classe abstrata
#include <string>
using std::string;
class Conta 
{
public:
  Conta(int numConta,string nomeCorrentista, double saldo) : numConta(numConta),nomeCorrentista(nomeCorrentista),saldo(saldo) {}
  void setSaldo(double saldo){this->saldo=saldo;}
  void setNomeCorrentista(string nomeCorrentista){this->nomeCorrentista=nomeCorrentista;}
  void setNumConta(int numConta){this->numConta=numConta;}
  double getSaldo()const {return saldo;}
  int getNumConta()const{return numConta;}
  string getNomeConrrentista()const{return nomeCorrentista;}
  //método virtual puro
  virtual void deposito(double valor){};
  virtual void retirada(double valor){};
  virtual void extrato(){};
private:
  int numConta;
  string nomeCorrentista;
  double saldo;
};

#endif