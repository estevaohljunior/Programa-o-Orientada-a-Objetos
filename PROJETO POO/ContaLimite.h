#ifndef CONTA_LIMITE_H
#define CONTA_LIMITE_H

#include "Conta.h"

#include <iostream>
using std::cout, std::endl;

class ContaLimite : public Conta
{
public:
  ContaLimite(int conta, Pessoa correntista, double saldo = 0.0, double limite = 200.0) : Conta(conta, correntista, saldo),limite(limite) {}
  
  virtual ~ContaLimite(){}


  virtual void operator >>(float valor)
  {
    try{
      if (valor > saldo + limite){
        throw alem_do_limite_error();
      }

      Date_hour dh;
      string descricao;
      cout << "Insira a descricao da trasação: ";
      cin >> descricao;
      OPERACAO operacao = {dh.date(), dh.hour(), valor, descricao};
      op.push_back(operacao);
      saldo -= valor;
    }
    catch (alem_do_limite_error &e){
      cerr << e.what() << endl;
      cout << endl;
    }
    
  }

  //sobrescrevendo método virtual puro extrato
  virtual void extrato()
  {
    cout << "CONTA: " << conta << endl;
    cout << "CLIENTE: " << correntista.getNome() << endl;
    cout << "LIMITE: " << limite << endl;
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
  double limite;
};

#endif