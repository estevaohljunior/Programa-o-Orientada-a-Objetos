#ifndef CONTA_COMUM_H
#define CONTA_COMUM_H

#include "Conta.h"

#include <iostream>
using std::cout, std::endl;

class ContaComum : public Conta
{
public:
  ContaComum(int conta, Pessoa correntista, double saldo = 0.0) : Conta(conta, correntista, saldo) {}
  
  virtual ~ContaComum(){}


  virtual void extrato()
  {
    cout << "CONTA: " << conta << endl;
    cout << "CLIENTE: " << correntista.getNome() << endl;
    cout << "Transações: " << endl;
    for(auto el : op){
      cout << el.data <<" "<< el.hora << endl;
      cout << el.descricao << endl << el.valor << endl << endl;
    }
    cout << "------------------------------" << endl;
    cout << "Saldo: R$ " << saldo << endl;
    cout << endl;
  }
};

#endif