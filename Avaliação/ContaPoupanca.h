#ifndef CONTA_POUPANCA_H
#define CONTA_POUPANCA_H

#include "Conta.h"

#include <iostream>
using std::cout, std::endl;

class ContaPoupanca : public Conta
{
public:
  ContaPoupanca(int conta, Pessoa correntista, string aniversario, double saldo = 0.0) : Conta(conta, correntista, saldo),aniversario(aniversario) {}
  
  virtual ~ContaPoupanca(){}


  virtual void extrato()
  {
    cout << "CONTA: " << conta << endl;
    cout << "CLIENTE: " << correntista.getNome() << endl;
    cout << "ANIVERSARIO: " << aniversario << endl;
    cout << "Transações: " << endl;
    for(auto el : op){
      cout << el.data <<" "<< el.hora << endl;
      cout << el.descricao << endl << el.valor << endl << endl;
    }
    cout << "------------------------------" << endl;
    cout << "Saldo: R$ " << saldo << endl;
    cout << endl;
  }

private:
  string aniversario;
};

#endif